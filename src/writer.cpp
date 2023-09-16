#include <iostream>
#include <fstream>
#include <vector>
#include "writer.h"

int writeBytes(std::string filename, std::vector<unsigned char> topStack, std::vector<unsigned char> bodyStack){
    std::ofstream objectFile(filename, std::ios::binary);

    if (!objectFile.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo! - writer.cpp, 10 \n";
        return 1;
    }

    std::vector<unsigned char> binaryOut;
    binaryOut.insert(binaryOut.end(), topStack.begin(), topStack.end());
    binaryOut.insert(binaryOut.end(), bodyStack.begin(), bodyStack.end());
    
    objectFile.write(reinterpret_cast<const char*>(binaryOut.data()), binaryOut.size());

    if (!objectFile) {
        std::cerr << "Erro ao escrever dados binários no arquivo." << std::endl;
        return 1;
    }

    objectFile.close();
    
    std::cout << "Fim!";
    return 0;
}