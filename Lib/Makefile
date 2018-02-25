CC = gcc
SOURCES = ..\Tree\main_tree_basics.c files\tree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE = hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $< -o $@