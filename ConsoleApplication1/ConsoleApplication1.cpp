#include <iostream>
//#include <string>
//#include "Products.h"
//#include "Money.h"
#include "VendingMachine.h"
using namespace std;


int main()
{
    cout << "Welcome to Vending Machines!\n\n";

    VendingMachine* vendingMachine = new VendingMachine();    
    int choice;
    int money, denomination;
    while (true) {
        cout << "The following items are available " << endl;
        vendingMachine->print_items();
        cout << "\nEnter your Product :";
        cin >> choice;
        cout << endl;
        cout << "\nDo you have coins(1) or notes(2) :";
        cin >> money;
        cout << "\nEnter your denomination :";
        cin >> denomination;
        vendingMachine->get_money(money, denomination);
        vendingMachine->compare_availability(choice);
        cout << "\nDo you want to reset ? Y or N" << endl;
        char ss;
        cin >> ss;
        if (ss == 'Y') {
            vendingMachine->reset();
        }
        
    }
    

    //vendingMachine->print();
}