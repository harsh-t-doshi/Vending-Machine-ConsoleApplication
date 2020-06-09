#include "Products.h"

Products::Products(int num) {
    products = new Product * [num];
    MAX_SIZE = num;
};

void Products::print() {
    for (int i = 0; i < slots_used; i++) {
        cout << endl;
        cout << (i + 1) << " ";
        products[i]->print();
    }
    cout << endl;
}

void Products::buy(int selection) {
    products[selection - 1]->buy();
}

int Products::get_price(int selection) {
    return products[selection - 1]->get_price();
}

bool Products::item_available(int selection) {
    if (selection + 1 > slots_used) {
        return false;
    }
    return true;
}

void Products::insert(string item, int price) {
    if (slots_used >= MAX_SIZE) {
        cout << "Vending Machine is Full" << endl;
        return;
    }
    products[slots_used++] = new Product(item, price);
}

Products::~Products() {
    for (int i = 0; i < slots_used; i++) {
        delete products[i];
    }
}

Product::Product(string name, int p) {
    *price = p;
    *(this->name) = name;
    *remaining_stock = MAX_STOCK;
}

void Product::buy() {
    if (*remaining_stock == 0) {
        cout << "The item is out of stock" << endl;
        return;
    }
    *remaining_stock = *remaining_stock - 1;
    cout << "item is bought" << endl;
}

int Product::get_price() {
    cout << "item: " << *name << endl;
    return *price;
}

void Product::print() {
    //printf(name);
    cout << *name << " At " << " $0." << *price << " Available : " << *remaining_stock;
}

Product::~Product() {
    delete price;
    delete name;
    delete remaining_stock;
}