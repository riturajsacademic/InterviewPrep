CC = gcc
SOURCES = ..\Lib\files\tree.c main.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE = hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) -c $< -o $@

clean: 
	del hello.exe main.o ..\Lib\files\tree.o