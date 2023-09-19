#include <iostream>
#include <fstream>
#include "json/json.hpp"

using json = nlohmann::json;

/*
Retorna a "expression" da AST.
*/
json read_json(const char* fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("couldn't open file.");
    }
    
    json data;
    file >> data;
    file.close();

    return data["expression"];
}

int main(int argc, char **argv) {
    char *fileName;
    fileName = argv[1];
    
    try {
        json root = read_json(fileName);
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\nVerifique o caminho até o json!\n";
        return 1;
    }

    return 0;
}
