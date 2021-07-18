#include <iostream>
#include "stack.cpp"

int main()
{
    Stack s;
    



    s.push(5);
    s.printStack();

    for(int i = 0; i < 6; ++i){
        s.pop(); 
    }

    s.printStack();
    s.printFullStack();

    s.push(6);

    return 0;
}
