
CC = g++
CFLAGS = -g -Wall -Wextra -Wpedantic



$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
SOURCES = Crowd.cpp  test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = execute

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)