#include "gtest/gtest.h"
#include "gmock/gmock.h"
extern "C" {
  #include "FlashDriver.h"
}

namespace flash_driver_test{
  #include "mock/MockIO.h"
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
    protected:
      MockIO *mockIO;
  };

  TEST_F(FlashDriverTest, FirstWrite)
  {
    EXPECT_CALL(MockIO, IO_Write(0, 0x40)).WillOnce();
    EXPECT_CALL(MockIO, IO_Write(0x1000, 0xBEEF)).WillOnce();
    auto result = Flash_Write(0x1000, 0xBEEF);
    EXPECT_EQ(0, result);
  }