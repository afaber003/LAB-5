#include "PrintJob.h"

// constructor
PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}


int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}