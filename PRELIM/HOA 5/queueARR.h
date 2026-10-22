#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr{
    private:
        //create a pointer array
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        //prototypes to use for queueArr:
        queueArr(size_t capacity);
        bool empty();
        bool full();

        size_t size();
        void Clear();

        T Front();
        T Back();

        void Enqueue(T newData);
        void Dequeue();

        //tasks
        // destructor
        ~queueArr();

        // copy constructor
        queueArr(const queueArr& other);

        //copy assignment operator
        queueArr& operator=(const queueArr& other);
};


//constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity){

    //capacity of the array
    q_capacity = capacity;

    //current size of the array
    q_size = 0;

    //initial front and back of the index
    q_front = 0;
    q_back = -1;

    //newly allocated array
    q_array = new T[q_capacity];
    std::cout << "Queue created with capacity: "
              << q_capacity << std::endl;
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }

    std::cout << "Copy constructor called." << std::endl;
}


//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    if (this != &other){

        delete [] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_capacity; i++){
            q_array[i] = other.q_array[i];
        }
    }

    std::cout << "Copy assignment operator called." << std::endl;

    return *this;
}

//delete
template <typename T>
queueArr<T>::~queueArr(){
    delete [] q_array;
    std::cout << "Queue destroyed." << std::endl;
}

//empty
template <typename T>
bool queueArr<T>::empty(){
    return q_size == 0;
}

//full
template <typename T>
bool queueArr<T>::full(){
    return q_size == q_capacity;
}

//clear
template <typename T>
void queueArr<T>::Clear(){
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

//return the element in the front of the queue
template <typename T>
T queueArr<T>::Front(){
    if (empty()){
        std::cout << "Queue is empty." << std::endl;
        return T{}; // return default value of T
    }
    //return the front element
    return q_array[q_front];
}

// back
template <typename T>
T queueArr<T>::Back(){
    //check and display if the queue is empty
    if (empty()){
        std::cout << "Queue is empty." << std::endl;
        return T{}; // return the default value of T
    }
    // if not then return the back element
    return q_array[q_back];
}

template <typename T>
size_t queueArr<T>::size(){
    return q_size;
}

template <typename T>
void queueArr<T>::Enqueue(T newData){
    if (full()){
        std::cout << "Queue is full." << std::endl;
        return;
    }

    //compute for the q_back to move it circularly
    q_back = (q_back + 1) % q_capacity;

    //assign the new value to the back of the queue array
    q_array[q_back] = newData;

    //increment the q_size
    q_size++;
}

//dequeue
template <typename T>
void queueArr<T>::Dequeue(){
    //check if the queue is empty
    if (empty()){
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    //compute for q_front to move it circularly
    q_front = (q_front + 1) % q_capacity;

    //decrement the size q_size
    q_size--;
}

#endif
