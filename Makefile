CC=g++
CFLAGS=-c -g -O0 -Wall -std=c++11
LDFLAGS=
SOURCES=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=free_roam

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

run: all
	./free_roam

clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)
