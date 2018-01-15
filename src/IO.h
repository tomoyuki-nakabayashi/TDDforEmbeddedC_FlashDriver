#ifndef SRC_IO_H_
#define SRC_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int ioAddress;
typedef int ioData;

typedef struct {
  double a;
  unsigned char b;
  double c;
  unsigned int d;
} myStruct;

void IO_Write(ioAddress addr, ioData data);
ioData IO_Read(ioAddress addr);
void IO_Ctrl(myStruct *data);

#ifdef __cplusplus
}
#endif

#endif //SRC_IO_H_