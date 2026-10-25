#ifndef PRINTJOB_H
#define PRINTJOB_H
#include <iostream>
#include <string>

class Job {
    public:
    int id;
    std::string name;
    int pages;
        Job(){
            id = 0;
            name = "";
            pages = 0;
        }

        Job(int jobId, std::string userName, int pageNum){
            id = jobId;
            name = userName;
            pages = pageNum;
        }
    };

class Printer {
    private:
    static const int maxJobs = 5;

        Job jobs[maxJobs];
        int front = 0;
        int back = -1;
        int size = 0;

    public:
        bool isEmpty(){
            return size == 0;
        }

        bool Full(){
            return size == maxJobs;
        }

        void addJob(Job job){
            if (Full()){
                std::cout << "======= |      QUEUE IS FULL      | =======\n";
                std::cout << "Cannot add another print job.\n";
                return;
            }
            back = (back + 1) % maxJobs;
            jobs[back] = job;
            size++;
            std::cout << "======= | PRINT JOB ADDED SUCCESSFULLY | =======\n";
        }

        void removeJob(){
            if (isEmpty()){
                std::cout << "======= |     QUEUE IS EMPTY     | =======\n";
                std::cout << "There are no jobs to remove.\n";
                return;
            }
            std::cout << "======= |    PRINT JOB REMOVED    | =======\n";
            std::cout << "Job " << jobs[front].id << " from "
                    << jobs[front].name << " has been removed.\n";
            front = (front + 1) % maxJobs;
            size--;

            if (isEmpty()){
                front = 0;
                back = -1;
            }
        }

        void printNext(){
            if (isEmpty()){
                std::cout << "======= |     QUEUE IS EMPTY     | =======\n";
                std::cout << "There are no jobs to print.\n";
                return;
            }

            std::cout << "============ |    PRINTING    | ============\n";
            std::cout << "Job ID: " << jobs[front].id << "\n";
            std::cout << "User:   " << jobs[front].name << "\n";
            std::cout << "Pages:  " << jobs[front].pages << "\n";
            std::cout << "======= |     PRINT JOB COMPLETED     | =======\n";

            front = (front + 1) % maxJobs;
            size--;

            if (isEmpty()){
                front = 0;
                back = -1;
            }
        }

        void printAll(){
            if (isEmpty()){
                std::cout << "======= |     QUEUE IS EMPTY     | =======\n";
                std::cout << "There are no jobs to print.\n";
                return;
            }
            std::cout << "\n======= |     PRINTING ALL JOBS     | =======\n";

            while (!isEmpty()){
                printNext();
            }
            std::cout << "======== |    ALL JOBS PRINTED    | ========\n";
        }

        void displayQueue(){
            if (isEmpty()){
                std::cout << "======= |     QUEUE IS EMPTY     | =======\n";
                std::cout << "There are no jobs in the queue.\n";
                return;
            }
            std::cout << "\n========== |     CURRENT QUEUE     | ==========\n";
            int current = front;

            for (int i = 0; i < size; i++){
                std::cout << "Job ID: " << jobs[current].id << "\n";
                std::cout << "User:   " << jobs[current].name << "\n";
                std::cout << "Pages:  " << jobs[current].pages << "\n";

                if (i < size - 1){
                    std::cout << "----------------------------------------------\n";
                }
                current = (current + 1) % maxJobs;
            }
            std::cout << "==============================================\n";
        }

    };

#endif

