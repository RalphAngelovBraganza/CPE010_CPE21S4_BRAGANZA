#include <iostream>
#include <limits>
using namespace std;

int main() {
    string item1, item2, item3;
    float price1, price2, price3;
    float total = 0;
    float payment;

    for (int i = 1; i <= 3; i++) {

        // Item Name - this block of code will go through each item one by one.
        if (i == 1) {
            cout << "Enter Item 1 Name: ";
            cin >> item1;
        }
        else if (i == 2) {
            cout << "Enter Item 2 Name: ";
            cin >> item2;
        }
        else {
            cout << "Enter Item 3 Name: ";
            cin >> item3;
        }

        // Item Price - this while loop will keep running until a valid number is inputted and then add up all the prices.
        while (true) {
            cout << "Enter Item " << i << " Price: ";
            float price;
            cin >> price;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (price < 0) {
                cout << "Price cannot be negative.\n";
                continue;
            }

            if (i == 1)
                price1 = price;
            else if (i == 2)
                price2 = price;
            else
                price3 = price;

            total += price;
            break;
        }
    }

    cout << "\nTotal Amount: " << total << endl;

    // Payment—this is where the payment is done; it will ask the user for the needed amount and it will keep asking until a valid input or amount is made.
    while (true) {
        cout << "Enter Payment: ";
        cin >> payment;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (payment < total) {
            cout << "Insufficient payment. Please enter enough payment.\n";
            continue;
        }

        break;
    }

    // Receipt—it will print a receipt for the user for items 1 to 3 and their individual prices. The receipt will also print out the total, the amount you paid, and the change.
    cout << "\n===================================";
    cout << "\n             RECEIPT";
    cout << "\n===================================";
    cout << "\nItem\t\tPrice";
    cout << "\n-----------------------------------";
    cout << "\n" << item1 << "\t\t" << price1;
    cout << "\n" << item2 << "\t\t" << price2;
    cout << "\n" << item3 << "\t\t" << price3;
    cout << "\n-----------------------------------";
    cout << "\nTotal:\t\t" << total;
    cout << "\nPayment:\t" << payment;
    cout << "\nChange:\t\t" << payment - total;
    cout << "\n===================================\n";

    return 0;
}