#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FlashDriver.h"

namespace flash_driver_test{
using ::testing::Return;
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

TEST_F(FlashDriverTest, WriteSucceeds_ReadyImmediately)
{
  EXPECT_CALL(*mockIO, IO_Write(0, 0x40)).Times(1);
  EXPECT_CALL(*mockIO, IO_Write(0x1000, 0xBEEF)).Times(1);
  EXPECT_CALL(*mockIO, IO_Read(0)).WillOnce(Return(1<<7));
  EXPECT_CALL(*mockIO, IO_Read(0x1000)).WillOnce(Return(0xBEEF));
  int result = Flash_Write(0x1000, 0xBEEF);
  EXPECT_EQ(0, result);
}
}