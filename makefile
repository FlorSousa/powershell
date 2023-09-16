CC = g++
CFLAGS = -Wall -Ilibs

TARGET = powershell

all: $(TARGET)

debug: obj/main.o obj/readJson.o
	$(CC) obj/main.o obj/readJson.o -o $(TARGET) -g $(CFLAGS)

$(TARGET): obj/main.o obj/readJson.o
	$(CC) obj/main.o obj/readJson.o -o $(TARGET) $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o src/main.cpp
	
obj/readJson.o: src/readJson.cpp
	$(CC) $(CFLAGS) -c -o obj/readJson.o src/readJson.cpp

clean:
	rm -f $(TARGET) obj/*.o

.PHONY: all clean debug