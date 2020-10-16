// copyright [2020] <Pedro Fernandes>
#ifndef SOURCE_STACK_HPP_
#define SOURCE_STACK_HPP_
#include "catch.hpp"
#endif  // SOURCE_STACK_HPP_

// Classe que contem cada elemtendo da pilha
// o tipo da variavel StackItem pode ser mudada para mudar o tipo
// do item da pilha
class stackItemClass {
 public:
    int StackItem;
};


// Classe que define o funcionamento da pilha
class stackArray {
 private:
    stackItemClass * pilha;
    int stackItem;
    int topo;
    int capacity;
    stackItemClass ErrorCase;

 public:
    void CreateStack(int size);
    void Push(int item);
    stackItemClass Pop();
    stackItemClass Top();
    bool SetSize(int newSize);
    int Size();
    bool IsFull();
    bool IsEmpty();
    bool DestroyStack(stackArray stack);
};

// Metodo que cria e define o tamanho da pilha
void stackArray::CreateStack(int size) {
    pilha = reinterpret_cast <stackItemClass*>
    (malloc(size*sizeof(stackItemClass)));
    topo = -1;
    capacity = size;
}

// Metodo que insere um novo item na pilha
void stackArray::Push(int item) {
    if (!IsFull()) {
    topo++;
    pilha[topo].StackItem = item;
    } else {
        return; }
}

// Metodo que retira o item que esta no topo da pilha
stackItemClass stackArray::Pop() {
    ErrorCase.StackItem = -2;
    stackItemClass intermed;
    if (!IsEmpty()) {
        intermed = pilha[topo];
        topo = topo -1;
        return intermed;
    } else {
        return ErrorCase;
    }
}


// Metodo que verifica e retorna qual o item que esta no topo da pilha
stackItemClass stackArray::Top() {
    ErrorCase.StackItem = -2;
    if (!IsEmpty()) {
        return pilha[topo];
    } else {
        return ErrorCase;
    }
}

// Metodo que muda o tamanho da pilha
bool stackArray::SetSize(int newSize) {
    pilha = reinterpret_cast <stackItemClass*>
     (realloc(pilha, newSize*sizeof(stackItemClass)));
    capacity = newSize;
    return true;
}


// Metodo que retorna o tamanho atual da pilha
int stackArray::Size() {
    return capacity;
}

// Metodo que verifica se a pilha esta vazia
bool stackArray::IsEmpty() {
    if (topo <= -1)
        return 1;
    else
        return 0;
}

// Metodo que verifica se a pilha esta cheia
bool stackArray::IsFull() {
    if (capacity == topo - 1)
        return 1;
    else
        return 0;
}

// Metodo que destroi a pilha
bool stackArray::DestroyStack(stackArray stack) {
    delete stack.pilha;
    stack.topo = -1;
    return true;
}
