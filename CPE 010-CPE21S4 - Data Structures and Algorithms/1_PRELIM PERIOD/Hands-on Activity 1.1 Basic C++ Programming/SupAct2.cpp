#include <iostream>
#include <limits>

float KelToFah(float kelvin);
float FahToKel(float fahrenheit);

int main() {

    int choice;
    float temperature;
    int exitProgram = 0;

    while(exitProgram == 0) {
        std::cout << "\n| ˚˖𓍢ִ໋❀ Temperature Converter ˚˖𓍢ִ໋❀ |\n" << std::endl;
        std::cout << "Choose an option:\n";
        std::cout << "1. Convert Kelvin to Fahrenheit\n";
        std::cout << "2. Convert Fahrenheit to Kelvin\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nEnter temperature in Kelvin: ";
                while (!(std::cin >> temperature)) {
                    std::cout << "Invalid input! \n\nPlease enter a valid number: ";
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
                std::cout << temperature << " K = " << KelToFah(temperature) << " °F" << std::endl;
                break;
            case 2:
                std::cout << "\nEnter temperature in Fahrenheit: ";
                while (!(std::cin >> temperature)) {
                    std::cout << "Invalid input! \n\nPlease enter a valid number: ";
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                }
                std::cout << temperature << " °F = " << FahToKel(temperature) << " K" << std::endl;
                break;
            case 3:
                exitProgram = 1;
                std::cout << "\nExiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice! \n\nPlease try again." << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }

}
    return 0;
}

float KelToFah(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

float FahToKel(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}