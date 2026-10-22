#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:

//Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = newName;
        studentAge = newAge;
    
        std::cout << "Constructor was called" << std::endl;
}

//Destructor
    ~Student(){
        std::cout <<"Destructor was called" <<std::endl;
}

//Copy Constructor
    Student (const Student &copyStudent){
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
}

//Display Attributes
    void printDetails(){
        std::cout << this->studentName << " " << this->studentAge << std::endl;
}

//Copy Assignment Operator 


};

int main() {
    Student student1 ("Mike", 19);
    Student student2 (student1);
    Student student3;
    student3 = student2;

return 0;
}
