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
  IO_Read(StatusRegister);
  IO_Read(addr);
  return FLASH_SUCCESS;
}