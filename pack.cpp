#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "work.h"
#include "powersupply.h"


#include "database.h"
#include "pack.h"


//значения кратны степеням двойки
const uint32_t CONST_DAC_U_START            = 8;
const uint32_t CONST_DAC_U_STOP             = 16;
const uint32_t CONST_DAC_I                  = 16;
const uint32_t CONST_NUMBER_OF_POINTS       = 2048;
const uint32_t CONST_DAC_U_ETALON_START     = 2;
const uint32_t CONST_DAC_U_ETALON_STOP      = 2;
const uint32_t CONST_DAC_I_ETALON           = 2;
const uint32_t CONST_FLASH_INTENCITY        = 64;
const uint32_t CONST_REFERENCE_U            = 2;
const uint32_t CONST_LUXMETER_LUX           = 8192;
const uint32_t CONST_TEMPERATURE_1          = 64;
const uint32_t CONST_TEMPERATURE_2          = 64;
const uint32_t CONST_TEMPERATURE_3          = 64;
const uint32_t CONST_TIME_TICK              = 8192;
const uint32_t CONST_U_OS                   = 16;
const uint32_t CONST_I_SC                   = 16;
const uint32_t CONST_FF                     = 64;
const uint32_t CONST_EFFICIENCY             = 64;


const double ADC_U_DIVIDER = 10;
const double ADC_I_DIVIDER = 24;

const double ADC_DIVIDER = 1;

const uint32_t MAX_CODE         = 4095;
const uint32_t MAX_FLASH        = 127;
const uint32_t MAX_TIME_TICK    = 1;


#ifndef DAC_ALIGN_12B_R
#define DAC_ALIGN_12B_R 0x00000000U
#endif

#ifndef DAC_ALIGN_12B_L
#define DAC_ALIGN_12B_L 0x00000004U
#endif

#ifndef DAC_ALIGN_8B_R
#define DAC_ALIGN_8B_R 0x00000008U
#endif
                    

//упаковка на два байта MSB first
//    0      1      2      3      4      5      6      7      8      9     10     11     12     13     14     15     16     17 */
static const uint32_t pack_power[] = {0x0000,0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000,0x8000};
static const uint32_t pack_mask[] =  {0x0000,0x0001,0x0003,0x0007,0x000f,0x001f,0x003f,0x007f,0x00ff,0x01ff,0x03ff,0x07ff,0x0fff,0x1fff,0x3fff,0x7fff,0xffff};

extern uint8_t RXbuffer[16];
extern uint8_t TXbuffer[16];



/*
typedef struct
{
    uint8_t         index;
    const uint32_t  *msb;
    uint32_t        bitlength;
    uint8_t         offset;
    const uint32_t  *maxCode;
    uint32_t        Alignment;
    const           double *dividerADC;

} DefineConfigPack;
*/

const DefineConfigPack ConfigPakage[] = 
{
    //index                 MSB                 bitlength   offset  maxCode         DAC_configuration       divider for ADC      
    {FLASH_INTENCITY,   &CONST_FLASH_INTENCITY,  7,          1,     &MAX_FLASH,      DAC_ALIGN_12B_R,        &ADC_DIVIDER},
    {DAC_U_START,       &CONST_DAC_U_START,      12,         2,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_U_DIVIDER},
    {DAC_U_STOP,        &CONST_DAC_U_STOP,       12,         3,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_U_DIVIDER},
    {DAC_I,             &CONST_DAC_I,            12,         4,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_I_DIVIDER},
    {NUMBER_OF_POINTS,  &CONST_NUMBER_OF_POINTS, 12,         5,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_DIVIDER},
    
    {ADC_U,             &CONST_DAC_U_STOP,       12,         1,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_U_DIVIDER},
    {ADC_I,             &CONST_DAC_I,            12,         2,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_I_DIVIDER},
    {LIM_I,             &CONST_DAC_I,            12,         4,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_I_DIVIDER},
    {REFERENCE_U,       &CONST_REFERENCE_U,      12,         5,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_DIVIDER},
    {TIME_TICK,         &CONST_TIME_TICK,        12,         6,     &MAX_TIME_TICK,  DAC_ALIGN_12B_R,        &ADC_DIVIDER},//last
    
    {LUXMETER1_LUX,     &CONST_LUXMETER_LUX,     12,         3,     &MAX_CODE,       DAC_ALIGN_12B_R,        &ADC_DIVIDER},
    
};


void PackConfig(void)
{
    for(uint32_t i = 0; i < sizeof(ConfigPakage)/sizeof(ConfigPakage[0]); i++)
    {
        const DefineConfigPack *ptrConfig;
        ptrConfig = &ConfigPakage[i];
        
        AS[ptrConfig->index].MSB =              *ptrConfig->msb;
        AS[ptrConfig->index].bitlength =        ptrConfig->bitlength;
        AS[ptrConfig->index].offset =           ptrConfig->offset;
        AS[ptrConfig->index].maxCode =          *ptrConfig->maxCode;
        AS[ptrConfig->index].Alignment =        ptrConfig->Alignment;
        AS[ptrConfig->index].dividerADC =       ptrConfig->dividerADC;
    }
}









uint32_t pack(AnalogTypeDef *as, void *pBuff)
{
    float value;
    
    uint16_t *buff = (uint16_t*)pBuff;
    
    //упаковка значения //
    //Берем значение из базы аналоговых сигналов //
    value = as->value;
    value = value*pack_power[as->bitlength]/(as->MSB);   //Преобразуем в двоичный код по MSB//
    as->output = (int16_t)value;                         //Переводим в целочисленный вид */
    as->output &= (pack_mask[as->bitlength]);            //Убираем до необходимой длины */
    
    
    buff[as->offset] &= ~(pack_mask[as->bitlength]);     //Обнуляем в буфере разряды сигнала */
    buff[as->offset] |= as->output;                      //Закладываем значение сигнала */
    
    //offset - буфер приводится к 16 разрядам,
    //и переход идет через 16 бит,
    //для 8 битного буфера на 16 байт,
    //то есть через два байта,
    //соответственно offset с 1 это третий байт
    //пример offset = 0 - 0,1 байт
    //пример offset = 1 - 2,3 байт
    //пример offset = 2 - 4,5 байт
    //пример offset = 3 - 6,7 байт
    //пример offset = 4 - 8,9 байт
    //пример offset = 5 - 10,11 байт
    //пример offset = 6 - 12,13 байт
    //пример offset = 7 - запрещено служебное слово
    //Передача идет Служебное+Код+7*(16бит)+Служебно+Служебное
    
    //15-й разряд - знак
    //code = 16384 соответствует 32
    //формула x = value*16384/32
    
    return 1;
}


uint32_t unpack (AnalogTypeDef *as, void *pBuff)
{
    float value;
    int32_t mask;
    
    uint16_t *buff = (uint16_t*)pBuff;
    
    // распаковка значения //
    mask = pack_mask[as->bitlength];
    //UNUSED(mask);//для микроконтроллера
    value = buff[as->offset];
    
    //if(value & (0x0001<<(as->bitlength-1)))
    //{
    //    value |= ~mask; // Для отрицательного числа восстанавливаем знак - дополнительный код //
    //} else {
    //    value &= mask;  // Для положительных чисел убираем лишние биты //
    //}
    
    /*as->valuemeasured = pack_power[as->bitlength];
    as->valuemeasured = (float)as->MSB/pack_power[as->bitlength];
    as->valuemeasured = (float)value*as->valuemeasured;*/
    
    
    
    as->valuemeasured = value*((float)as->MSB/pack_power[as->bitlength]);
    
    as->code = (uint32_t)(((as->valuemeasured)*(as->maxCode))/(2*as->MSB));
    
    return 1;
}






