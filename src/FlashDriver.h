#ifndef SRC_FLASH_DRIVER_H
#define SRC_FLASH_DRIVER_H

#define ioAddress int
#define ioData int

int Flash_Write(ioAddress addr, ioData data);

#endif //SRC_FLASH_DRIVER_H