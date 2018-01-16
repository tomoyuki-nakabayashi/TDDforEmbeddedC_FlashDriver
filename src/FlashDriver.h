#ifndef SRC_FLASH_DRIVER_H
#define SRC_FLASH_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "IO.h"

enum {
  FLASH_SUCCESS = 0,
  FLASH_VPP_ERROR = -1,
  FLASH_PROGRAM_ERROR = -2,
  FLASH_PROTECTED_BLOCK_ERROR = -3,
  FLASH_UNKNOWN_PROGRAM_ERROR = -4,
  FLASH_READ_BACK_ERROR = -5
};

void Flash_Create();
void Flash_Destroy();
int Flash_Write(ioAddress addr, ioData data);

#ifdef __cplusplus
}
#endif

#endif //SRC_FLASH_DRIVER_H