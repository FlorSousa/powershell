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
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
