#include "gmock/gmock.h"
extern "C" {
  #include "IO.h"
}

class MockIO {
public:
  MOCK_METHOD2(IO_Write, int(ioAddress, ioData));
};

extern MockIO *mockIO;

extern "C"{
  int IO_Write(ioAddress addr, ioData data)
  {
    return mockIO->IO_Write(addr, data);
  }
}
