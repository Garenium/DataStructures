#include <iostream>

class Stack{
    private: 
        int top;
        int arr[5];
    public:
        //Constructor
        Stack() : top(-1), arr{0} {}

        //Functions
        void push(int value){
            if(top == 4)
                std::cerr << "Stack overflow" << std::endl;
            else{ ++top; arr[top] = value; }
        }

        int pop() { 
	    auto poppedValue(-1);
            if(top == -1)
                std::cout << "Stack is empty ";
            else{
                poppedValue = arr[top];
                arr[top] = 0; 
                --top; 
            }
	    return poppedValue;
        }

        bool isEmpty() { 
            if(top == -1)
                return true;    
            else
                return false;
        }

        /* int peek() { */ 
        /*     if(top != -1) */
        /*         return arr[top]; */
        /*     else{ */
        /*         std::cout << "stack is empty or out of bounds." << std::endl; */
        /*         return -1; */
        /*     } */
        /* } */

        int peek(int position){
            if(0 <= position && position <= top) 
                return arr[position];
            else{
                std::cout << "stack is empty or out of bounds." << std::endl;
                return -1;
            }
        }

        int count() { 
            if(top == -1)
                return -1;
            else
            return top+1; 
        } //debug

        void change(int value, int index){
            if(0 >= index && index <= 4) 
                arr[index] = value;
            else
                std::cerr << "Invalid index " << std::endl;
        }

        void display(){
            std::cout << "\nStack: \n";
            for(int& element : arr)
                std::cout << element << std::endl;
            std::cout << "\n";
        }

        bool isFull()
        {
            if(top == 4)
                return true;
            else
                return false;
        }

 };
