#ifndef SRC_IO_H_
#define SRC_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int ioAddress;
typedef int ioData;

void IO_Write(ioAddress addr, ioData data);

#ifdef __cplusplus
}
#endif

#endif //SRC_IO_H_