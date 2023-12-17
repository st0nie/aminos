VPATH = src
CXXFLAGS = -g

SRCS = main.cpp neural.cpp io.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = aminos

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
