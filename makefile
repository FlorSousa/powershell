CC = g++
CFLAGS = -Wall -Ilibs

TARGET = powershell

all: $(TARGET)

debug: obj/main.o obj/readJson.o
	$(CC) obj/main.o obj/readJson.o -o $(TARGET) -g $(CFLAGS)

$(TARGET): obj/main.o obj/writer.o obj/readJson.o obj/stack.o
	$(CC) obj/main.o obj/writer.o obj/readJson.o obj/stack.o -o $(TARGET) $(CFLAGS)
  
obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o src/main.cpp
	
obj/readJson.o: src/readJson.cpp
	$(CC) $(CFLAGS) -c -o obj/readJson.o src/readJson.cpp

obj/writer.o: src/writer.cpp
	$(CC) $(CFLAGS) -c -o obj/writer.o src/writer.cpp

obj/stack.o: src/classes/stack.cpp
	$(CC) $(CFLAGS) -c -o obj/stack.o src/classes/stack.cpp

clean:
	rm -f $(TARGET) obj/*.o

.PHONY: all clean debug