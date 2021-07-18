#include <iostream>

class Queue{
private:
    //Representing the queue as an array
    int arr[5];
    int rear;
    int front;
    
public:
    Queue() : arr{0}, rear(-1), front(-1) {} //Constructor
   
    //Getters
    int getFront() { return front; }
    int getRear() { return rear; }

    void enqueue(int value){

        if(rear==-1) //append front if enqueue for the first time
            front = 0;

        if(isFull()){
            std::cout << "\nQueue is full. Cannot enqueue. " << std::endl; }
        else{    
        ++rear;
        arr[rear]=value;}
    }

    void dequeue()
    {
        if(isEmpty()){
            std::cout << "\nQueue is empty. Cannot dequeue. " << std::endl;
            return; }
        else{
         arr[front]=0;
         ++front; }
    }

    bool isEmpty(){
        if(front==-1 && rear==-1) 
            return true;
        if(front == 5 && rear == 4)
        {
            front = rear = -1;
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if(front == 5 && rear == 4)
        {
            front = rear = -1;
            return true;
        }
        else if(rear==sizeof(arr)/sizeof(arr[0])-1)
            return true;
        else
            return false;
    }

    void display()
    {
        std::cout << "\nQueue:\n ["; 
        size_t length = sizeof(arr) / sizeof(arr[0]);
        size_t i = 0;
        for(i = 0; i < length-1; ++i)
            std::cout << arr[i] << ',';
        std::cout << arr[i] << ']' << std::endl;

         
    }
};

int main()
{
    Queue q; 
    
    q.display();

    q.enqueue(1);

    q.display();

    for(int i = 1; i <= 6; ++i){
     q.enqueue(i);
     q.display();
    }

    for(int i = 0; i < 7; ++i){
    q.dequeue();
    q.display();}

    q.enqueue(5);

    q.enqueue(-234);

    q.display();


    return 0;
}
