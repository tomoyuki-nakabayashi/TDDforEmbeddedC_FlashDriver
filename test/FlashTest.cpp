#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FlashDriver.h"

namespace flash_driver_test{
  #include "mock/MockIO.h"
  MockIO *mockIO;
  
  class FlashDriverTest : public ::testing::Test
  {
    virtual void SetUp()
    {
      mockIO = new MockIO();
    }

    virtual void TearDown()
    {
      delete mockIO;
    }
  };

  TEST_F(FlashDriverTest, FirstWrite)
  {
    EXPECT_CALL(*mockIO, IO_Write(0x40, 0)).Times(1);
    int result = Flash_Write(0x1000, 0xBEEF);
    EXPECT_EQ(0, result);
  }
}