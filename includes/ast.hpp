#pragma once

#include <variant>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "json/json.hpp"

class AST;

enum BinaryOp { // operação binária
    Add, // Add
    Sub, // Subtract
    Mul, // Multiply
    Div, // Divide
    Rem, // Rem
    Eq,  // Equal
    Neq, // Not equal
    Lt,  // Less than
    Gt,  // Greater than
    Lte, // Less than or equal to
    Gte, // Greater than or equal to
    And, // And
    Or,  // Or
}; 

struct Error {
    std::string message;
    std::string full_text;
};
struct Int { uint32_t value; };
struct Str { std::string value; };
struct Call {
    AST* callee;
    std::vector<AST*> arguments;
};
struct Binary {
    AST* lhs;
    BinaryOp op;
    AST* rhs;
};
struct Function {
    AST* value;
    std::vector<AST*> parameters;
};
struct Let { 
    AST* value;
    std::string name;
    AST* next;
};
struct If {
    AST* condition;
    AST* then;
    AST* otherwise;
};
struct Print  { AST* value; };
struct First  { AST* value; };
struct Second { AST* value; };
struct Bool   { AST* value; };
struct Tuple {
    AST* first;
    AST* second;
};
struct Var { AST* term; };

struct Location {
    std::size_t start;
    std::size_t end;
    std::string filename;
};

using Node = std::variant<
                    Error,
                    Int,
                    Str,
                    Call,
                    Binary,
                    Function, 
                    Let,
                    If,
                    Print,
                    First,
                    Second,
                    Bool,
                    Tuple
                    >;
class AST {
public:
    Node node; 
    Location location;

    AST(Node node, Location location) : node(node), location(location) =  default;

    // TODO
    // AST(nlohmann::json json);
};
