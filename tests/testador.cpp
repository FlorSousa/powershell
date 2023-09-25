#include <iostream>
#include <fstream>
#include "ast.hpp"

int main() {
    std::ifstream file("../files/print.json");

    if (!file.is_open()) {
        throw std::runtime_error("couldn't open file.");
    }
    nlohmann::json data;
    file >> data;
    AST ast2{};
    convertToAST(data, &ast2);

    return 1;
}