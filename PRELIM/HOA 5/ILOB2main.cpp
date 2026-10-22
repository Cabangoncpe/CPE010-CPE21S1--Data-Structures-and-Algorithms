#include <iostream>
#include "queueArr.h"

int main(){

    //create an objecy
    queueArr<int> q(6);
    q.Enqueue(1);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;
    
    q.Enqueue(2);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Enqueue(3);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Enqueue(4);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;
    
    q.Enqueue(5);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;
    
    q.Enqueue(6);
    std::cout << "q_front: " << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;
    

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    q.Dequeue();
    std::cout << q.Front() << ", q_back: " << q.Back() << ", q_size: " << q.size() << std::endl;

    //copy constructor
    queueArr<int> q2(q);

    std::cout << "Copy constructor test\n" << std::endl;
    std::cout << "q2_front: " << q2.Front()
              << ", q2_back: " << q2.Back()
              << ", q2_size: " << q2.size() << std::endl;

    // copy assignment operator
    queueArr<int> q3(3);

    q3 = q;

    std::cout << "Copy assignment" << std::endl;
    std::cout << "q3_front: " << q3.Front()
              << ", q3_back: " << q3.Back()
              << ", q3_size: " << q3.size() << std::endl;

    return 0;
}