#ifndef DATA_BASE_H
#define DATA_BASE_H


#define NUMBER_POINTS 64 //number of points for data

#define STRUCT_END  0xffff


#define START_FRAME             0x3A
#define STOP_FRAME              0x0D
#define END_FRAME               0x0A
#define START_FRAME_NONE_VALID  0xA0
#define LENGTH_NONE_VALID       0xA1
#define USART_3_PC              0xB1
#define USART_1_RS485_PC        0xB2
#define USART_1_RS485_FLASH     0xB3

#define START_MEASUREMENT       0x01
#define START_LUXMETER          0x12
#define STOP_LUXMETER           0x13
#define LUXMETER_ANSWER_OK      0x14


#define STOP_MEASUREMENT        0x02
#define CHECK_FLASH             0x03
#define SAVE_RESULTS            0x04
#define MONITOR_ON              0x05
#define MONITOR_OFF             0x06
#define BRAKE                   0x07
#define CODE_NONE_VALID         0x08
#define CONFIGURE               0x09
#define TRANSFER_DATA           0x52


#define START_MEASUREMENT_OK    0x11
#define STOP_MEASUREMENT_OK     0x21
#define CHECK_FLASH_OK          0x31
#define SAVE_RESULTS_OK         0x41
#define MONITOR_ON_OK           0x51
#define MONITOR_OFF_OK          0x61
#define BRAKE_OK                0x71
#define CONFIGURE_OK            0x91
#define TRANSFER_DATA_OK        0x53
#define TRANSFER_DATA_COMPLETE  0x54



//0x3A - START_FRAME
//0x0D - STOP_FRAME
//0x0A - END_FRAME
//0xA0 - START_FRAME_NONE_VALID
//0xA1 - LENGTH_NONE_VALID
//0xB1 - USART_3_PC
//0xB2 - USART_1_RS485_PC
//0xB3 - USART_1_RS485_FLASH

//0x01 - START_MEASUREMENT
//0x02 - STOP_MEASUREMENT
//0x03 - CHECK_FLASH
//0x04 - SAVE_RESULTS
//0x05 - MONITOR_ON
//0x06 - MONITOR_OFF
//0x07 - BRAKE
//0x08 - CODE_NONE_VALID
//0x09 - CONFIGURE

//0x11 - START_MEASUREMENT_OK
//0x21 - STOP_MEASUREMENT_OK
//0x31 - CHECK_FLASH_OK
//0x41 - SAVE_RESULTS_OK
//0x51 - MONITOR_ON_OK
//0x61 - MONITOR_OFF_OK
//0x71 - BRAKE_OK
//0x91 - CONFIGURE_OK




typedef enum
{
    Default             = 0,

    DAC_U_START         = 1,
    DAC_U_STOP          = 2,
    ADC_U               = 3,
    ADC_I               = 4,
    NUMBER_OF_POINTS    = 5,

    DAC_I               = 6,
    LIM_I               = 7,

    DAC_U_ETALON_START  = 8,
    DAC_U_ETALON_STOP   = 9,
    ADC_U_ETALON        = 10,
    ADC_I_ETALON        = 11,

    DAC_I_ETALON        = 12,
    LIM_I_ETALON        = 13,

    FLASH_INTENCITY     = 14,

    REFERENCE_U         = 15,

    LUXMETER1_LUX       = 16,
    LUXMETER2_LUX       = 17,
    
    TEMPERATURE_1       = 18,
    TEMPERATURE_2       = 19,
    TEMPERATURE_3       = 20,
    TIME_TICK           = 21,

    U_OC                = 22,
    I_SC                = 23,
    FF                  = 24,
    EFFICIENCY          = 25,

    U_OC_ETALON         = 26,
    I_SC_ETALON         = 27,
    FF_ETALON           = 28,
    EFFICIENCY_ETALON   = 29,

    POWER_LIGHT         = 30,


    SIZE_SIGNAL

} BaseAnalog_TypeDef;

typedef struct
{
    const       double *divider;
    const       double *dividerADC;
    float       value;
    float       valuemeasured;
    uint32_t    code;
    uint32_t    MSB;
    uint32_t    bitlength;
    int32_t     output;
    uint8_t     offset;
    uint8_t     sign;
    uint32_t    maxCode;
    uint32_t    Alignment;

} AnalogTypeDef;


typedef struct
{
    uint16_t I_ADC[64];
    uint16_t LIM_ADC;
    uint16_t U_etalon;
    uint16_t I_etalon;
    uint16_t U_ADC[64];
    uint16_t U_ref2_5V[64];

    
    uint16_t LIM_etalon;        
    uint16_t U_detector;
    uint16_t ADC_Temperature[1];
    uint16_t Intencity [64];
    uint32_t LightDetector[2];
    uint16_t CodeADC[6];
    uint32_t TimerADC[2];//start [0] and stop[1]
        
} DefineComplex;


typedef struct
{
    float I_ADC[64];
    float U_ADC[64];  
    uint16_t LIM_ADC;

    float U_etalon[64];
    float I_etalon[64];
    uint16_t LIM_etalon;
    
    uint16_t U_ref2_5V;

    uint16_t U_detector;
    
    uint16_t ADC_Temperature[3];
    
    float Intencity [64];

} DefineResults;

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







//CAN
typedef struct {
    
    uint8_t server; // кому посылка
    uint8_t client; // от кого или кому отвечать
    uint8_t command; // команда
    uint8_t id_parameter; // номер потока
    uint8_t reply;    // признак отвечать или нет
    
    uint8_t startPointShedule; //указатель номера начала посылки
    uint8_t stopPointShedule; //указатель номера начала посылки
    
} t_sneduleCAN;



//CAN


extern AnalogTypeDef AS[SIZE_SIGNAL];

#if 0 //конфигурация для микроконтроллера

void UART_Init(UART_HandleTypeDef *huart, uint8_t *bufferRX, uint8_t *bufferTX);

void SemInit(void);
void SetTime(void);
void CheckTime(void);
void ConfigureCode (void);

void FlashSet(void);
void FlashReset(void);
HAL_StatusTypeDef FlashSPI2 (uint32_t codeForFlash, uint16_t Size);
void CheckFlash (uint32_t codeForFlash, uint16_t Size);
void TrigerFlashRS422 (void);

void MonitorWork(void);
void MonitorSend(void);

void GeneratorOn(void);

void SetDataADC(void);
HAL_StatusTypeDef ReadADC1(void);

uint8_t BrakeMeasurement (void);

HAL_StatusTypeDef ConfigureI2C (I2C_HandleTypeDef *hi2c, const uint16_t *I2C_devAddress, uint8_t *I2C_bufConfig);
HAL_StatusTypeDef ReadI2C (I2C_HandleTypeDef *hi2c, const uint16_t *I2C_devAddress, uint8_t *I2C_buffRead);

void OutData (void);

void UART_PARCER (void);
#endif

#endif // DATA_BASE_H
