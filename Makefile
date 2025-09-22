TARGET = terminal_quest
CXX = g++
CXXFLAGS = -std=c++17 -I./headers -Wall -Wextra

LIBS = -lsqlite3

SRCS = $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo "Executavel criado."
	rm -f $(OBJS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
