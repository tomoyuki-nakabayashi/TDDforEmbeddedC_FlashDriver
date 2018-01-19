#ifndef TEST_MOCK_FAKEMICROTIME_H_
#define TEST_MOCK_FAKEMICROTIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "MicroTime.h"

void FakeMicroTime_Init(uint32_t start, uint32_t incr);

#ifdef __cplusplus
}
#endif

#endif  // TEST_MOCK_FAKEMICROTIME_H_