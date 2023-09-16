#include <vector> 
#ifndef WRITER_H
#define WRITER_H
int writeBytes(std::string filename, std::vector<unsigned char> topStack, std::vector<unsigned char> bodyStack);
#endif