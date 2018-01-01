#ifndef TEST_MOCK_MOCK_IO_H_
#define TEST_MOCK_MOCK_IO_H_
#include "gmock/gmock.h"
#include "IO.h"

class MockIO {
public:
  MOCK_METHOD2(IO_Write, void(ioAddress, ioData));
};

extern MockIO *mockIO;

extern "C" {
  void IO_Write(ioAddress addr, ioData data)
  {
    return mockIO->IO_Write(addr, data);
  }
}

#endif //TEST_MOCK_MOCK_IO_H_