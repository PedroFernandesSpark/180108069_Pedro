#include <iostream>
#include <cstdlib>
using namespace std;

class stackItemClass {
public:
    int StackItem;
};

class stackArray {
private:
    stackItemClass * pilha;
    int stackItem;
    int topo;
    int capacity;
    stackItemClass ErrorCase;

public:
    stackArray(int size = 10);

    void Push(int item);
    stackItemClass Pop();
    stackItemClass Top();
    bool SetSize(int newSize);
    int Size();
    bool IsFull();
    bool IsEmpty();
    bool DestroyStack(stackArray stack);
};

stackArray::stackArray(int size) {
    pilha = (stackItemClass*) malloc(size*sizeof(stackItemClass));
    topo = -1;
    capacity = size;
}

void stackArray::Push(int item) {
    if (!IsFull()){
    topo++;
    pilha[topo].StackItem = item;
    cout << "Inserting:   " << item << endl;
    }
    else cout << "Stack is full";
}

stackItemClass stackArray::Pop() {
    ErrorCase.StackItem = -2;
    stackItemClass intermed;
    if (!IsEmpty()){
        cout << "popping" << Top().StackItem << endl;
        intermed = pilha[topo];
        topo = topo -1;
        return intermed;
    }
    else
    {
        cout << "Stack is Empty";
        return ErrorCase;
    }
    
}

stackItemClass stackArray::Top() {
    ErrorCase.StackItem = -2;
    if (!IsEmpty()) {
        return pilha[topo];
    }
    else {
        cout << "Stack is empty";
        return ErrorCase;
    }
}

bool stackArray::SetSize(int newSize) {
    pilha = (stackItemClass*) realloc(pilha, newSize*sizeof(stackItemClass));
    capacity = newSize;
    return true;
}

int stackArray::Size() {
    return capacity;
}

bool stackArray::IsEmpty() {
    if (topo <= -1)
        return 1;
    else
        return 0;
}

bool stackArray::IsFull() {
    if (capacity == topo - 1)
        return 1;
    else
        return 0;
}
bool stackArray::DestroyStack(stackArray stack){
    delete stack.pilha;
    stack.topo = -1;
    return true;
}
