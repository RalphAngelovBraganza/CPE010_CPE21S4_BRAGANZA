#include <iostream>
#include <limits>
#include "printJob.h"

int main()
{
Printer printer;
int choice;

    do
    {
        // Menu display
        std::cout << "\n===== | SHARED PRINTER | =====\n";
        std::cout << "1. Add Print Job\n";
        std::cout << "2. Remove Print Job\n";
        std::cout << "3. Print Next Job\n";
        std::cout << "4. Print All Jobs\n";
        std::cout << "5. Display Queue\n";
        std::cout << "6. Exit\n";
        std::cout << "\n===============================\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Error checking for menu input
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1){
            int id;
            std::string name;
            int pages;

            std::cout << "Enter Job ID: ";
            std::cin >> id;

            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid Job ID.\n";
                continue;
            }

            std::cout << "Enter User Name: ";
            std::cin >> name;
            std::cout << "Enter Number of Pages: ";
            std::cin >> pages;

            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid number of pages.\n";
                continue;
            }

            printer.addJob(Job(id, name, pages));

        }else if (choice == 2){
            printer.removeJob(); // Remove the next job in the queue
        }else if (choice == 3){ 
            printer.printNext(); // Print the next job in the queue
        }else if (choice == 4){
            printer.printAll(); // Print all jobs in the queue
        }else if (choice == 5){
            printer.displayQueue(); // Display the current queue of jobs
        }else if (choice == 6){
            std::cout << "Exiting program...\n"; // Exit the program
        }else {
            std::cout << "Invalid choice. Please choose from 1 to 6.\n"; // Invalid choice
        }

    } while (choice != 6);

return 0;
}

