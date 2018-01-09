#include "FlashDriver.h"

int Flash_Write(ioAddress addr, ioData data)
{
  IO_Write(0, 0x40);
  IO_Write(addr, data);
  IO_Read(0);
  IO_Read(addr);
  return 0;
}