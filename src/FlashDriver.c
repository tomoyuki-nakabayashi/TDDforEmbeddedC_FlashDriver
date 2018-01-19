#include <inttypes.h>
#include "FlashDriver.h"
#include "m28w160ect.h"
#include "MicroTime.h"

#define FLASH_WRITE_TIMEOUT_IN_MICROSECONDS 5000

void Flash_Create() {

}

void Flash_Destroy() {

}

static int writeError(int status) {
  IO_Write(CommandRegister, Reset);
  if (status & VppErrorBit) return FLASH_VPP_ERROR;
}

int Flash_Write(ioAddress addr, ioData data)
{
  uint32_t timestamp = MicroTime_Get();
  IO_Write(CommandRegister, ProgramCommand);
  IO_Write(addr, data);

  ioData status = IO_Read(StatusRegister);
  while ((status & ReadyBit) == 0) {
    if (MicroTime_Get() - timestamp >= FLASH_WRITE_TIMEOUT_IN_MICROSECONDS)
      return FLASH_TIMEOUT_ERROR;
    status = IO_Read(StatusRegister);
  }

  if (status != ReadyBit) return writeError(status);

  if (IO_Read(addr) != data) return FLASH_READ_BACK_ERROR;

  return FLASH_SUCCESS;
}