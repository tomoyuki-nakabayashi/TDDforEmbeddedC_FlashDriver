#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FlashDriver.h"
#include "m28w160ect.h"

namespace flash_driver_test{
using ::testing::Return;
#include "mock/MockIO.h"
MockIO *mockIO;

class FlashDriverTest : public ::testing::Test
{
  virtual void SetUp()
  {
    mockIO = new MockIO();
    Flash_Create();
  }

  virtual void TearDown()
  {
    Flash_Destroy();
    delete mockIO;
  }
  protected:
    const ioAddress address = 0x1000;
    const ioData data = 0xBEEF;
    const int result = -1;
};

TEST_F(FlashDriverTest, WriteSucceeds_ReadyImmediately)
{
  EXPECT_CALL(*mockIO, IO_Write(CommandRegister, ProgramCommand)).Times(1);
  EXPECT_CALL(*mockIO, IO_Write(address, data)).Times(1);
  EXPECT_CALL(*mockIO, IO_Read(StatusRegister)).WillOnce(Return(ReadyBit));
  EXPECT_CALL(*mockIO, IO_Read(address)).WillOnce(Return(data));
  int result = Flash_Write(address, data);
  EXPECT_EQ(FLASH_SUCCESS, result);
}

TEST_F(FlashDriverTest, SucceedsNotImmediatelyReady) {
  EXPECT_CALL(*mockIO, IO_Write(CommandRegister, ProgramCommand)).Times(1);
  EXPECT_CALL(*mockIO, IO_Write(address, data)).Times(1);
  EXPECT_CALL(*mockIO, IO_Read(StatusRegister))
    .Times(4)
    .WillOnce(Return(0))
    .WillOnce(Return(0))
    .WillOnce(Return(0))
    .WillOnce(Return(ReadyBit));
  EXPECT_CALL(*mockIO, IO_Read(address)).WillOnce(Return(data));

  auto result = Flash_Write(address, data);
  EXPECT_EQ(FLASH_SUCCESS, result);
}

TEST_F(FlashDriverTest, WriteFails_VppError) {
  EXPECT_CALL(*mockIO, IO_Write(CommandRegister, ProgramCommand)).Times(1);
  EXPECT_CALL(*mockIO, IO_Write(address, data)).Times(1);
  EXPECT_CALL(*mockIO, IO_Read(StatusRegister)).Times(1)
    .WillOnce(Return(ReadyBit | VppErrorBit));
  EXPECT_CALL(*mockIO, IO_Write(CommandRegister, Reset)).Times(1);
  
  auto result = Flash_Write(address, data);
  EXPECT_EQ(FLASH_VPP_ERROR, result);
}

using ::testing::Pointee;
MATCHER_P(EqMyStruct, x, "") { return arg->a == x.a; }

TEST_F(FlashDriverTest, PointeeTest) {
  myStruct test = {1.0, 2, 3.0, 4};
  EXPECT_CALL(*mockIO, IO_Ctrl(EqMyStruct(test))).Times(1);
  Flash_Ctrl();
}
}