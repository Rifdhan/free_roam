CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=free_roam

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXE)
