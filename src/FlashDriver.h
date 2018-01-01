#ifndef SRC_FLASH_DRIVER_H
#define SRC_FLASH_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "IO.h"

int Flash_Write(ioAddress addr, ioData data);

#ifdef __cplusplus
}
#endif

#endif //SRC_FLASH_DRIVER_H