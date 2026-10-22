#include <iostream>
#include <queue>

void display(std::queue<char> r); 

int main(){

    std::queue<char> q; 
    
    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //display
    display(q);
    //empty()
    if(q.empty()){
        std::cout<<"Queue ie empty"<<"\n";
    }
        else {
            std::cout<<"Queue is not empty"<<"\n";
        }

    //size()
    std::cout<<"Queue size: "<<q.size()<<"\n";
    //front()
    std::cout<<"Front of the queue: "<<q.front()<<"\n";
    //back
    std::cout<<"Back of the queue: "<<q.back()<<"\n";
    //pop
    q.pop(); std::cout<<"Popping out the front element"<<"\n";
    //display the new front
    std::cout<<"Front of the queue: "<<q.front()<<"\n";
    //display
    display(q);
    //push another element
    q.push('1'); std::cout<<"Pushing 1 at the rear"<<"\n";
    //display the new back 
    std::cout<<"Back of the queue: "<<q.back()<<"\n";
    //display
    display(q);
    
}

void display(std::queue<char> r){
    //create a copy of the queue
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();

    }
    std::cout<<"\n";
}


