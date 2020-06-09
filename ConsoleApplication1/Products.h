#include<iostream>
using namespace std;
class Product {
public:
	Product(string name, int p);
	void buy();
	int get_price();
	void print();
	~Product();
private:
	const int MAX_STOCK = 10;
	string* name = new string;
	int* price = new int;
	int* remaining_stock = new int;
};

class Products {
public:
	Products(int num);
	void print();
	void buy(int selection);
	int get_price(int selection);
	bool item_available(int selection);
	void insert(string item, int price);
	~Products();
private:
	int slots_used = 0;
    int MAX_SIZE = 0;
    Product** products;
};