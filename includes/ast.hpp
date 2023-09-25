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

struct Location {
    std::size_t start;
    std::size_t end;
    std::string filename;
};
struct Error {
    std::string message;
    std::string full_text;
    Location location;
};
struct Int {
    int32_t value; 
    Location location;
};
struct Str {
    std::string value;
    Location location;
};
struct Call {
    AST* callee;
    std::vector<AST*> arguments;
    Location location;
};
struct Binary {
    AST* lhs;
    BinaryOp op;
    AST* rhs;
    Location location;
};
struct Function {
    AST* value;
    std::vector<AST*> parameters;
    Location location;
};
struct Let { 
    AST* value;
    std::string name;
    AST* next;
    Location location;
};
struct If {
    AST* condition;
    AST* then;
    AST* otherwise;
    Location location;
};
struct Print  {
    AST* value;
    Location location;
};
struct First  {
    AST* value;
    Location location;
};
struct Second {
    AST* value;
    Location location;
};
struct Bool   { 
    AST* value;
    Location location;
};
struct Tuple {
    AST* first;
    AST* second;
    Location location;
};
struct Var {
    AST* term;
    Location location;
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

struct AST {
    std::string name;
    Location location;
    Node* head; 
};

int convertToAST(nlohmann::json json, AST* out);