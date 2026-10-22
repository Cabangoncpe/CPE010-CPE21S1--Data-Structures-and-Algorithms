#ifndef JOBsupp_H
#define JOBsupp_H

#include <iostream>
#include <string>

class Job {
private:
    int id;
    std::string user;
    int pages;

public:

    // Default constructor
    Job() {
        id = 0;
        user = "";
        pages = 0;
    }

    // Constructor to create a job
    Job(int id, std::string user, int pages) {
        this->id = id;
        this->user = user;
        this->pages = pages;
    }

    // Display the information of the job
    void display() {
        std::cout << "Job ID: " << id
                  << ", User: " << user
                  << ", Pages: " << pages << std::endl;
    }
};

#endif
