#include <iostream>
#include <vector>
class Stack{
private:
    int top;
    int arr[5];
public:
    int getLength() const { return top; } 
    void setTop(int v) { top = v; }

    //Constructor 
    Stack() : top(-1), arr{0} {} 

    //Functions
    /*
     * Name: push
     * Purpose: pushes the value onto a stack
     * Parameter: integer v
     * Returns: void
     */
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


    /*
     * Name: pop 
     * Purpose: pops the value onto a stack
     * Parameter: none 
     * Returns: void
     */
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


    /*
     * Name: printFullStack 
     * Purpose: prints the stack in its full format (ex: {0,0,0,0,0})
     * Parameter: none 
     * Returns: void
     */
    void printFullStack(){
        size_t i = 0;
        std::cout << "Full Stack:\n[";
        for(auto& element : arr)
        {
            if(i < sizeof(arr)/sizeof(arr[0])-1){
                std::cout << element << ", ";  ++i;
            }
            else {
                std::cout << element << "]\n" << std::endl; 
            }
        }

    }


    /*
     * Name: printStack 
     * Purpose: prints the stack until it reaches the max (formatted)
     * Parameter: none 
     * Returns: void
     */
    void printStack(){
        int len = getLength();
        std::cout << "Stack:\n [";
        if(len <= -1)
        std::cout << len << "]\n" << std::endl;
        else
        {
            for(int i = 0; i < len; ++i){
                std::cout << arr[i] << ", "; 
            }
            std::cout << arr[len] << "]\n" << std::endl;
        }
    }

};




