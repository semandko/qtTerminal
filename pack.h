#ifndef PACK_H
#define PACK_H

#define PACK_UNPACK_H


void PackConfig(void);
uint32_t pack(AnalogTypeDef *as, void *pBuff);
uint32_t unpack (AnalogTypeDef *as, void *pBuff);


#endif // PACK_H
