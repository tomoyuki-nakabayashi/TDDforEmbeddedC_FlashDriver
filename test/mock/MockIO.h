#ifndef TEST_MOCK_MOCK_IO_H_
#define TEST_MOCK_MOCK_IO_H_
#include "gmock/gmock.h"
#include "IO.h"

class MockIO {
public:
  MOCK_METHOD1(IO_Read, ioData(ioAddress));
  MOCK_METHOD2(IO_Write, void(ioAddress, ioData));
};

extern MockIO *mockIO;

extern "C" {
  void IO_Write(ioAddress addr, ioData data)
  {
    return mockIO->IO_Write(addr, data);
  }

  ioData IO_Read(ioAddress addr)
  {
    return mockIO->IO_Read(addr);
  }
}

#endif //  TEST_MOCK_MOCK_IO_H_