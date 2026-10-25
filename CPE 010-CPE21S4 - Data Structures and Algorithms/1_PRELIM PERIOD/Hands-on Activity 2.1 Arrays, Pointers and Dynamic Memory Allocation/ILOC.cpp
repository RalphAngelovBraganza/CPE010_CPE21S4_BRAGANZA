#include <iostream>
#include <string>

class Fruitz{
private:
    std::string Name;
    int Price;
    int Quantity;

public:
    // Constructor
    Fruitz(std::string name, int price, int quantity){
        Name = name;
        Price = price;
        Quantity = quantity;
    }

    // Copy Constructor
    Fruitz(const Fruitz& copy){
        Name = copy.Name;
        Price = copy.Price;
        Quantity = copy.Quantity;
    }

    // Destructor
    ~Fruitz(){
    }

    // Copy Assignment Operator
    Fruitz& operator=(const Fruitz& copy){
        if(this != &copy){
            Name = copy.Name;
            Price = copy.Price;
            Quantity = copy.Quantity;
        }
        return *this;
    }

    void displayAttributes() const{
        std::cout << Name << ":" << " PHP " << Price << " x" << Quantity << std::endl;
    }

    int getPrice() const{
        return Price;
    }

    int getQuantity() const{
        return Quantity;
    }
};

class Vegetablez{
private:
    std::string Name;
    int Price;
    int Quantity;

public:
    // Constructor
    Vegetablez(std::string name, int price, int quantity){
        Name = name;
        Price = price;
        Quantity = quantity;
    }

    // Copy Constructor
    Vegetablez(const Vegetablez& copy){
        Name = copy.Name;
        Price = copy.Price;
        Quantity = copy.Quantity;
    }

    // Destructor
    ~Vegetablez(){
    }

    // Copy Assignment Operator
    Vegetablez& operator=(const Vegetablez& copy){
        if(this != &copy){
            Name = copy.Name;
            Price = copy.Price;
            Quantity = copy.Quantity;
        }
        return *this;
    }

    void displayAttributes() const{
        std::cout << Name << ":" << " PHP " << Price << " x" << Quantity << std::endl;
    }

    int getPrice() const{
        return Price;
    }

    int getQuantity() const{
        return Quantity;
    }
};

// Total Sum Function
void totalSum(Fruitz *fruitz[], int fruitzSize,
              Vegetablez *vegetablez[], int vegetablezSize)
{
    int total = 0;

    for(int i = 0; i < fruitzSize; i++){
        if(fruitz[i] != nullptr){
            total += fruitz[i]->getPrice() * fruitz[i]->getQuantity();
        }
    }

    for(int i = 0; i < vegetablezSize; i++){
        if(vegetablez[i] != nullptr){
            total += vegetablez[i]->getPrice() * vegetablez[i]->getQuantity();
        }
    }

    std::cout << "\nTotal Sum: PHP " << total << std::endl;
}

int main(){

    const int F_SIZE = 2;
    const int V_SIZE = 2;

    Fruitz *fruitz[F_SIZE];
    Vegetablez *vegetablez[V_SIZE];

    fruitz[0] = new Fruitz("Apple", 10, 7);
    fruitz[1] = new Fruitz("Banana", 10, 8);

    vegetablez[0] = new Vegetablez("Broccoli", 60, 12);
    vegetablez[1] = new Vegetablez("Lettuce", 50, 10);

    std::cout << "Jenna's Grocery List" << std::endl;

    for(int i = 0; i < F_SIZE; i++){
        fruitz[i]->displayAttributes();
    }

    for(int i = 0; i < V_SIZE; i++){
        vegetablez[i]->displayAttributes();
    }

    totalSum(fruitz, F_SIZE, vegetablez, V_SIZE);

    // Delete Lettuce (Problem 4)
    delete vegetablez[1];
    vegetablez[1] = nullptr;

    // Deallocate remaining memory
    for(int i = 0; i < F_SIZE; i++){
        delete fruitz[i];
        fruitz[i] = nullptr;
    }

    delete vegetablez[0];
    vegetablez[0] = nullptr;

    return 0;
}

