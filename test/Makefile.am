check_LTLIBRARIES = libgtest.la libgmock.la
libgtest_la_SOURCES = $(top_srcdir)/googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread
libgmock_la_SOURCES = $(top_srcdir)/googletest/googlemock/src/gmock-all.cc
libgmock_la_CPPFLAGS = -I$(top_srcdir)/googletest/googlemock/include -I$(top_srcdir)/googletest/googlemock $(libgtest_la_CPPFLAGS)
libgmock_la_LDFLAGS = $(libgtest_la_LDFLAGS)

check_PROGRAMS = gtest
gtest_LDADD = libgtest.la libgmock.la
gtest_LDFLAGS = -pthread
gtest_CPPFLAGS = \
  -I$(top_srcdir)/googletest/googletest \
  -I$(top_srcdir)/googletest/googletest/include \
  -I$(top_srcdir)/googletest/googlemock \
  -I$(top_srcdir)/googletest/googlemock/include \
  -pthread \
  -I$(top_srcdir)/src \
  -std=c++11

test_sources = \
  TestMain.cpp \
  FlashTest.cpp \
  mock/FakeMicroTime.c
target_sources = \
  $(top_srcdir)/src/FlashDriver.c
gtest_SOURCES = $(test_sources) $(target_sources)