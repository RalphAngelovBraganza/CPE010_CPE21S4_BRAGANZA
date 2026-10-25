#include <iostream>
#include <queue>
#include <string>

const int MaxSize = 5; // Maximum size of the queue

void display(std::queue<std::string> q)
{
    int i = 1;

    while (!q.empty())
    {
        std::cout << i << ": " << q.front() << "\n"; // Display the front element of the queue
        q.pop(); // Immediately removes the front element from the queue
        i++; // Then increments the counter for the next element in the array
    }

    std::cout << std::endl;
}

int main()
{
    //Array of students
    std::string studentName[MaxSize] = {
        "Ralph Braganza",
        "John Clarence",
        "Rojan Ambas",
        "James Verano",
        "Daniel Antivo"
    };

    std::queue<std::string> students;

    // Pass each name from the array into the queue
    for (int i = 0; i < MaxSize; i++)
    {
        students.push(studentName[i]);
    }
    
    // Display the students in the queue
    std::cout << "Students in the queue: \n";
    display(students);

    return 0;
}
