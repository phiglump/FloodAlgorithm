CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = graphSearch.c main.c
TARGET = flood

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
