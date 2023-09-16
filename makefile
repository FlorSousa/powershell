CC = g++
CFLAGS = -Wall -Ilibs

TARGET = powershell

all: $(TARGET)

debug: obj/main.o
	$(CC) obj/main.o -o $(TARGET) -g $(CFLAGS)

$(TARGET): obj/main.o
	$(CC) obj/main.o -o $(TARGET) $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o src/main.cpp

clean:
	rm -f $(TARGET) obj/*.o

.PHONY: all clean debug