#include <iostream>
#include "stack.cpp"
int main()
{
    Stack s;

    for(int i = 0; i < 7; ++i)
        s.push(i);
    
     
    for(int i = 0; i < 7; ++i){
        s.pop(); 
    }

    s.printStack();
    s.printFullStack();

    s.push(6);
    
    s.printFullStack();

    return 0;
}
