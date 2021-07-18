#include <iostream>

class Stack{
private:
    int arr[5];
    int top; 
public:
    int getLength() const { return top; } 
    void setTop(int v) { top = v; }

    //Constructor
    Stack() : top(-1), arr{0} {}


    void push(int v) {
        if(getLength() >= 4)
            std::cerr << "Error: stack is full. Cannot push the stack.\n\n";
        else{
            setTop(getLength()+1);
            std::cout << "Pushing index " << getLength() << ": " << v << std::endl;
            arr[getLength()] = v;
            printStack();
        }
    }


    void pop(){
        if(getLength() == -1)
            std::cerr << "There is nothing to pop.\n" << std::endl;
        else{
            arr[getLength()] = 0;
            setTop(getLength()-1);
            std::cout << "Stack " << getLength()+1 << " popped!" << std::endl;
            printStack();
        }
    }

    void printFullStack(){
        size_t i = 0;
        std::cout << "[";
        for(auto& element : arr)
        {
            if(i < sizeof(arr)/sizeof(arr[0])-1){
                std::cout << element << ", ";  ++i;
            }
            else {
                std::cout << element << ']' << std::endl; 
            }
        }

    }

    void printStack(){
        std::cout << "Stack:\n [";
        for(int i = 0; i < getLength(); ++i){
            std::cout << arr[i] << ", "; 
        }
        std::cout << arr[getLength()] << "]\n" << std::endl;
    }
};




