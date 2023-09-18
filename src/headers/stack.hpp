// stack.hpp

#pragma once
#include <queue>

class Stack {
public:
    std::queue<unsigned char> topStack;
    std::queue<unsigned char> bodyStack;

    //get
    std::queue<unsigned char> getTopStack();
    std::queue<unsigned char> getFullStack();
    std::queue<unsigned char> getBodyStack();

    //push
    void pushToTop(unsigned char);
    void pushToBody(unsigned char);
    void pushToTop(std::queue<unsigned char> bytes);
    void pushToBody(std::queue<unsigned char> bytes);
    //construtores
    Stack();
    Stack(std::queue<unsigned char> topStack, std::queue<unsigned char> bodyStack);
};
