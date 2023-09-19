#include <iostream>
#include <queue>
#include <fstream>
#include "writer.hpp"

int writeBytes(std::string filename, std::queue<unsigned char> fullStack){
    std::ofstream objectFile(filename, std::ios::binary);
    if (!objectFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo! - writer.cpp, 10 \n";
        return 1;
    }

    while (!fullStack.empty()) {
        char frontChar = fullStack.front();
        objectFile.write(&frontChar, sizeof(char));
        fullStack.pop();
    }

    if (!objectFile) {
        std::cerr << "Erro ao escrever o arquivo objeto! - writer.cpp, 21" << std::endl;
        return 1;
    }

    objectFile.close();
    std::cout << "Arquivo objeto foi criado";
    return 0;
}