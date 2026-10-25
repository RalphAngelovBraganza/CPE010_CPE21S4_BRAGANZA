#include <iostream>
#include <cmath>
#include <limits>

double calculateDistance(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2;

    std::cout << "\n| ˚˖𓍢ִ໋❀ Distance Calculator ˚˖𓍢ִ໋❀ |\n";

    std::cout << "\nEnter the coordinates of the first point (x1 y1): \n";
    while (!(std::cin >> x1 >> y1)) {
        std::cout << "Invalid input!\n\nPlease enter valid coordinates: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nEnter the coordinates of the second point (x2 y2): \n";
    while (!(std::cin >> x2 >> y2)) {
        std::cout << "Invalid input!\n\nPlease enter valid coordinates: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double distance = calculateDistance(x1, y1, x2, y2);

    std::cout << "\nThe distance between the two points is: " << "\n" << distance << std::endl;

    return 0;
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}