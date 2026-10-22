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
    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] = {"Mike", "Callum", "Ethan", "Sophie", "Ashley"};
    int ageList[j] = {19, 20, 21, 23, 25,};

return 0;
}
