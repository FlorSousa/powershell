CC = g++
CFLAGS = -Wall -Ilibs

TARGET = powershell

all: $(TARGET)

debug: obj/main.o
	$(CC) obj/main.o -o $(TARGET) -g $(CFLAGS)

$(TARGET): obj/main.o obj/writer.o
	$(CC) obj/main.o obj/writer.o -o $(TARGET) $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o src/main.cpp

obj/writer.o: src/writer.cpp
	$(CC) $(CFLAGS) -c -o obj/writer.o src/writer.cpp

clean:
	rm -f $(TARGET) obj/*.o

.PHONY: all clean debug