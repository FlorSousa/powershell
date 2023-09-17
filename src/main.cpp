#include <iostream>
#include "json/json.hpp"
#include "headers/readJson.hpp"

using json = nlohmann::json;

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
