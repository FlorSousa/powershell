#include "stack.hpp"

// Construtor padrão
Stack::Stack() {}

// Construtor com argumentos
Stack::Stack(std::queue<unsigned char> topStack, std::queue<unsigned char> bodyStack) {
    this->topStack = topStack;
    this->bodyStack = bodyStack;
}

std::queue<unsigned char> Stack::getFullStack() {
    std::queue<unsigned char> fullStack;
    std::queue<unsigned char> localTopStack = this->topStack;
    std::queue<unsigned char> localBodyStack = this->bodyStack;

    while (!localTopStack.empty()) {
        fullStack.push(localTopStack.front());
        localTopStack.pop();
    }

    while (!localBodyStack.empty()) {
        fullStack.push(localBodyStack.front());
        localBodyStack.pop();
    }

    return fullStack;
}

void Stack::pushToTop(unsigned char byte) {
    this->topStack.push(byte);
}

void Stack::pushToBody(unsigned char byte) {
    this->bodyStack.push(byte);
}

void Stack::pushToTop(std::queue<unsigned char> bytes){
    while (!bytes.empty()){
        this->topStack.push(bytes.front());
        bytes.pop();
    }
    
}

void Stack::pushToBody(std::queue<unsigned char> bytes){
    while (!bytes.empty()){
        this->bodyStack.push(bytes.front());
        bytes.pop();
    }
}

std::queue<unsigned char> Stack::getBodyStack() {
    return this->bodyStack;
}

std::queue<unsigned char> Stack::getTopStack() {
    return this->topStack;
}
