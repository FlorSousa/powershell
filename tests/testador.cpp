#include <iostream>
#include "ast.hpp"

int main() {
    Binary binary{
        .lhs = nullptr,
        .op = ::Add,
        .rhs = nullptr
    };
    Location location{.start=0,.end=0,.filename="test"};
    AST ast(binary, location);
    return 0;
}