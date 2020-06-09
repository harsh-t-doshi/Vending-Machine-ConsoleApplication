#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    *amount_deposited = 0;
    products = new Products(6);
    products->insert("Candy", 10);
    products->insert("Snack", 50);
    products->insert("Nuts", 90);
    products->insert("Coke", 25);
    products->insert("Pepsi", 35);
    products->insert("Gingerale", 45);
}

void VendingMachine::reset() {
    *amount_deposited = 0;
    delete products;
    products = new Products(6);
    products->insert("Candy", 10);
    products->insert("Snack", 50);
    products->insert("Nuts", 90);
    products->insert("Coke", 25);
    products->insert("Pepsi", 35);
    products->insert("Gingerale", 45);
}

VendingMachine::~VendingMachine() {
    delete products;
}

void VendingMachine::print_items() {
    products->print();
}

void VendingMachine::get_money(int choice, int value) {
    switch (choice) {
    case(1):
        *amount_deposited = coins->check(value, *coins->max);
        break;
    case(2):
        *amount_deposited = notes->check(value, *notes->max) * 100;
        break;
    default:
        *amount_deposited = 0;
    }
}

void VendingMachine::compare_availability(int selection) {
    try {
        if (!products->item_available(selection)) {
            cout << "The given item is not in the vending machine" << endl;
        }
        int price = products->get_price(selection);
        if (price > * amount_deposited) {
            cout << "Insufficient Money" << endl;
            //return_money('Y');
        }
        else {
            cout << "price : " << price << endl;
            *amount_deposited -= price;
            products->buy(selection);
        }
        return_money('Y');

        //if (*remain != 0 && *amount_deposited >= *price) {
        //    *remain -= 1;
        //    *amount_deposited -= *price;
        //    //return_money('Y');
        //}
        //else if (*amount_deposited < *price) {
        //    throw "Amount deposited is low";
        //}
        //else if (*remain == 0) {
        //    throw "Stock not available";
        //}
        //else {
        //    throw "Unknown error";
        //}
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}

void VendingMachine::return_money(char choice)
{
    if (*amount_deposited != 0)
    {
        if (choice == 'Y' || choice == 'y')
        {
            cout << "\n Your remaining change is : " << *amount_deposited / 100.0 << " $ \n";
            *amount_deposited = 0;
        }
    }
}
