#include <iostream>
#include "queuell.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;
    
    enqueue(&front, &back, 'M');
    std::cout<<front->data<< " "<<back->data<<"\n";
    enqueue(&front, &back, 'I');
    std::cout<<front->data<< " "<<back->data<<"\n";
    enqueue(&front, &back, 'K');
    std::cout<<front->data<< " "<<back->data<<"\n";
    enqueue(&front, &back, 'E');
    std::cout<<front->data<< " "<<back->data<<"\n";
    dequeue(&front, &back);
    std::cout<<front->data<< " "<<back->data<<"\n";

    std:: cout << "Queue list \n";
    display(front);
    std::cout << "Front value: " << FrontVariable(front) << std::endl;

    return 0;


}
