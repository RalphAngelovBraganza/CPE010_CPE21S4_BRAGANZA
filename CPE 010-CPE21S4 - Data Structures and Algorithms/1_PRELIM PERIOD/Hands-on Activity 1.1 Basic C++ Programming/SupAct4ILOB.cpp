#include <iostream>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double base, height, area;

public:
    Triangle(double A, double B, double C, double bs, double ht);
    void setAngles(double A, double B, double C);
    void setArea(double bs, double ht);
    double displayArea();
    double perimeteraTria(double side1, double side2, double side3);
    void typeTria();
    const bool validateTriangle();
};

int main() {
    // Driver code
    Triangle set1(60, 60, 60, 10, 5);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Area: " << set1.displayArea() << "\n";
        std::cout << "Perimeter: " << set1.perimeteraTria(10, 10, 10) << "\n";
        set1.typeTria();
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C, double bs, double ht) {
    angleA = A;
    angleB = B;
    angleC = C;
    base = bs;
    height = ht;
    totalAngle = A + B + C;
    area = 0.5 * base * height;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setArea(double bs, double ht) {
    base = bs;
    height = ht;
    area = 0.5 * base * height;
}

double Triangle::displayArea() {
    return area;
}

double Triangle::perimeteraTria(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

void Triangle::typeTria() {
    if (angleA == 90 || angleB == 90 || angleC == 90) {
        std::cout << "A Right Triangle" << std::endl;
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        std::cout << "An Obtuse Triangle" << std::endl;
    } else {
        std::cout << "An Acute Triangle" << std::endl;
    }
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}