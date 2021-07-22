#include <iostream>

class Queue{
private:
    int arr[5];
    int front;
    int rear;

public:
    Queue() : arr{0}, front(-1), rear(-1) {} //Constructor
   
    //Getters
    int getFront() { return front; }
    int getRear() { return rear; }

    void enqueue(int value)
    {
        if(isFull())
            return;
        else if(isEmpty())
            rear = front = 0;
        else
            rear++;
        
        std::cout << "Element at index " << rear << " is enqueued." << std::endl;

        arr[rear] = value;
    }

    int dequeue()
    {
        int x = 0;
        if(isEmpty()){
            std::cout << "Queue is empty. " << std::endl;
            return -1;
        }
        else if(front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            std::cout << "Element at index " << front << " is dequeued." << std::endl;
            arr[front] = 0;
            front++;
        }

        return x;
    }

    bool isEmpty(){

        bool condition(false);
        if(front == -1 && rear == -1){
            condition = true;}
        else condition = false;
        
        return condition;     
    }

    bool isFull(){
        if(rear == sizeof(arr)/sizeof(arr[0])-1){
            return true;}
        else
            return false;
    }

    void display()
    {
       std::cout << "Queue:\n ["; 
        size_t length = sizeof(arr) / sizeof(arr[0]);
        size_t i = 0;
        for(i = 0; i < length-1; ++i)
            std::cout << arr[i] << ',';
        std::cout << arr[i] << "]\n" << std::endl;

    }
};

int main()
{
    using namespace std;
    Queue q;
    
    int i;
    for(i = 0; i < 5; ++i){
        q.enqueue(i+1);
        q.display();
    }

    cout << '\n' << endl;

    for( ; i >= 0; --i){
        q.dequeue();
        q.display();
    }

    q.display();

    return 0;
}
