#include <iostream>
#include "Jobsupp.h"
#include "Printersupp.h"

int main() {

    // create objext
    Printer printer;

    // add jobs to printer line
    printer.addJob(Job(1, "Mike", 5));
    printer.addJob(Job(2, "Corro", 10));
    printer.addJob(Job(3, "Jave", 3));
    printer.addJob(Job(4, "Dane", 7));

    // display jobs
    printer.displayJobs();

    // process jobs
    std::cout << "Processing Jobs\n" << std::endl;

    printer.processJob();
    printer.processJob();
    printer.processJob();
    printer.processJob();

    // try to process another job when the queue is empty
    printer.processJob();

    return 0;
}