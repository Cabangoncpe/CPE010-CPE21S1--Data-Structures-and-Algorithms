#ifndef PRINTERsupp_H
#define PRINTERsupp_H

#include <iostream>
#include "Jobsupp.h"

class Printer {
private:
    // store jobs
    Job jobs[10];

    int front;
    int back;
    int size;

public:

    //constructor
    Printer() {
        front = 0;
        back = -1;
        size = 0;
    }

    //add new job
    void addJob(Job newJob) {

        //if full
        if (size == 10) {
            std::cout << "Printer queue is full." << std::endl;
            return;
        }

        //move back to next position
        back = (back + 1) % 10;

        // store new job at the back
        jobs[back] = newJob;

        // increase jobs
        size++;

        std::cout << "Job added to printer queue." << std::endl;
    }

    // process first job in line
    void processJob() {

        // if no jobs
        if (size == 0) {
            std::cout << "No jobs waiting." << std::endl;
            return;
        }

        // display jobs 
        std::cout << "Processing job:\n" << std::endl;
        jobs[front].display();

        // move front to the next job
        front = (front + 1) % 10;

        // decrease jobs
        size--;
    }
    // display pending jobs
    void displayJobs() {

        // if queue empty
        if (size == 0) {
            std::cout << "No pending jobs." << std::endl;
            return;
        }

        std::cout << "Pending jobs:\n" << std::endl;

        // go through jobs in queue
        for (int i = 0; i < size; i++) {

            // position of job
            int index = (front + i) % 10;

            //display job
            jobs[index].display();
        }
    }
};
#endif
