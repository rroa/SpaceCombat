CC=clang++
CFLAGS=-c -Wall
LDFLAGS=-lGL -lGLU -lglut
SOURCES=quads.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=SpaceCombat

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
