mkfile_path = $(dir $(lastword $(MAKEFILE_LIST)))

GTEST_INCLUDES = -I$(mkfile_path)external/googletest/googletest/include
GTEST_LIBDIR = -L$(mkfile_path)external/googletest/build/lib

CC  = g++
CFLAGS    = -std=c++11

INCLUDES += $(GTEST_INCLUDES) -Isrc
SRCS    = src/*.cpp test/*.cpp
OBJS    = ./*.o
TARGET  = test_all

LIBDIR  += $(GTEST_LIBDIR)
LIBS    = -lgtest -lgtest_main

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean