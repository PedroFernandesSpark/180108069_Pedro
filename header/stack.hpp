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

public:
    stackArray(int size = 10);

    void Push(int item);
    stackItemClass Pop();
    stackItemClass Top();
    bool SetSize(int newSize);
    int Size();
    bool IsFull();
    bool IsEmpty();
    void DestroyStack();
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
    else throw std::runtime_error("Overflow");
}

stackItemClass stackArray::Pop() {
    cout << "popping" << Top().StackItem << endl;
    topo--;
    return pilha[topo];
}

stackItemClass stackArray::Top() {
    if (!IsEmpty()) {
        return pilha[topo];
    }
    else {
        throw std::runtime_error("Empty Stack");
    }
}

bool stackArray::SetSize(int newSize) {
    pilha = (stackItemClass*) realloc(pilha, newSize*sizeof(stackItemClass));
    capacity = newSize;
    return 1;
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
void stackArray::DestroyStack(){
    topo = -1;
    return;
}
