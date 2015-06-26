CC=g++
CFLAGS=-c -g -O0 -Wall -std=c++11
LDFLAGS=-lGL -lglut -std=c++11
SOURCES=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=free_roam

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

run: all
	./free_roam

clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)
