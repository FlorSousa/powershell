#include <iostream>
#include <fstream>
#include "json/json.hpp"
#include "headers/readJson.hpp"

using json = nlohmann::json;

/*
Retorna a "expression" da AST.
*/
json read_json(char* fileName) {

    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("couldn't open file.");
    }
    
    json data;
    file >> data;
    file.close();

    return data["expression"];
}
