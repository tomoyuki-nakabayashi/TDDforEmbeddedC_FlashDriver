#ifndef SRC_FLASH_DRIVER_H
#define SRC_FLASH_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "IO.h"

enum {
  FLASH_SUCCESS = 0,
  FLASH_VPP_ERROR = -1
};

void Flash_Create();
void Flash_Destroy();
int Flash_Write(ioAddress addr, ioData data);
void Flash_Ctrl();

#ifdef __cplusplus
}
#endif

#endif //SRC_FLASH_DRIVER_H