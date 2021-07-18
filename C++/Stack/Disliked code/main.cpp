#include <iostream>
#include <string>
#include <windows.h>
#include "stack.cpp"

void message(int input, HANDLE& hConsole);

int main()
{
    using namespace std;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    Stack s;
    int option, position, value;
    const string prompt{
    "\nEnter an option number to perform an operation. Enter 0 to exit.\n"
        "Opt.   Name:\n"
        "1.     push()\n"
        "2.     pop()\n"
        "3.     isEmpty()\n"
        "4.     isFull()\n"
        "5.     peek()\n"
        "6.     count()\n"
        "7.     change()\n"
        "8.     display()\n"
        "9.     Clear Screen\n"
    };

    do{
        cout << prompt << endl;    
        cin >> option;

        switch(option){
            case 0:
                break;
            case 1:
                message(option, hConsole);

                cout << "Enter an item in the stack: ";
                cin >> value;

                s.push(value);
                break;
            case 2:
                message(option, hConsole);
                cout << "Popped value : " << s.pop() << endl;
                break;
            case 3:
                message(option, hConsole);
                if(s.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 4:
                message(option, hConsole);
                if(s.isFull())                
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full" << endl;
                break;
            case 5:
                message(option, hConsole);

                cout << "Enter a position of the item you want to peek: " << endl;
                cin >> position;

                cout << "Value at position: " << position << " is " << s.peek(position) << endl <<  endl;
                break;
            case 6:
                message(option, hConsole);
                cout << "Count: " << s.count() << endl;
                break;
            case 7:
                message(option, hConsole);

                cout << "Enter the position of the item you want to change: " << endl;
                cin >> position;
                
                //cout << endl;

                cout << "Enter value of item you want to change : " << endl;    
                cin >> value;

                s.change(value, position);
                break;
            case 8:
                message(option, hConsole);
                s.display();
                break;
            case 9:
                system("clear");
            default:
                cout << "Please reenter a proper number from above " << endl;

        }
   }while(option != 0);
    
    return 0;
}

void message(int input, HANDLE& hConsole)
{
    std::string funcs[]{"push", "pop", "isEmpty", "isFull", "peek", "count", "change", "display"};
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << funcs[input-1] << "() function is called." << std::endl; 
    SetConsoleTextAttribute(hConsole, 15);

}
