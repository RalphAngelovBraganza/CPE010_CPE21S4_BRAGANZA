#include <iostream>
#include <limits>
using namespace std;

int main() {
    float quiz_total = 0;
    float qInput;
    
    /* This block of code will ask the user for the 3 quiz scores. If the user fails to input a number from 0 to 100, it will tell the user to try again until they input the right values.*/
    for (int i = 1; i <= 3; i++) {
        while (true) {
            cout << "Enter Quiz Score " << i << " (0-100): ";
            cin >> qInput;
            
            if (cin.fail()) {
                cout << "Invalid input. Please enter an integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            if (qInput < 0 || qInput > 100) {
                cout << "Invalid score. Must be between 0 and 100.\n";
                continue;
            }
            
            break;
        }
        quiz_total += qInput;
    }
    
    // This line of code will display the average quiz score and total quiz score.
    float total_qa = quiz_total / 3.0;
    cout << "\nQuiz Average: " << total_qa << "\n";
    cout << "Total Quiz Score: " << quiz_total << "\n";
    
    return 0;
}