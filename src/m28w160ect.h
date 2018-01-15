#ifndef SRC_M28W160ECT_H_
#define SRC_M28W160ECT_H_

typedef enum {
  CommandRegister = 0x0,
  StatusRegister = 0x0
} Flash_Registers;

typedef enum {
  ProgramCommand = 0x40,
  Reset = 0xff
} Flash_Command;

enum {
  VppErrorBit = 1<<3,
  ReadyBit = 1<<7
};
#endif  // SRC_M28W160ECT_H_