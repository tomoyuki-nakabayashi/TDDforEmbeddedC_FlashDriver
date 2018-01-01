#include "FlashDriver.h"

int Flash_Write(ioAddress addr, ioData data)
{
  IO_Write(0x40, 0);
  return 0;
}