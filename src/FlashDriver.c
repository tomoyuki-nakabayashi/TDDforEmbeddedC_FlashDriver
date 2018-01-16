#include "FlashDriver.h"
#include "m28w160ect.h"

void Flash_Create() {

}

void Flash_Destroy() {

}

int Flash_Write(ioAddress addr, ioData data)
{
  IO_Write(CommandRegister, ProgramCommand);
  IO_Write(addr, data);

  ioData status = 0;
  while ((status & ReadyBit) == 0) {
    status = IO_Read(StatusRegister);
  }

  if (status != ReadyBit) {
    IO_Write(CommandRegister, Reset);

    if (status & VppErrorBit) return FLASH_VPP_ERROR;
  }

  if (IO_Read(addr) != data) return FLASH_READ_BACK_ERROR;
  
  return FLASH_SUCCESS;
}