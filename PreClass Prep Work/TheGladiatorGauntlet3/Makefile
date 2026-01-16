CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

VERSION = 0.1

TARGET = TGG3_$(VERSION)

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build Complete: $(TARGET)"

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del -f *.o TGG3_*