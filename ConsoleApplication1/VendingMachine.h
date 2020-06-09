#include "Products.h"
#include "Money.h"

class VendingMachine {
public:
	VendingMachine();
	void reset();
	~VendingMachine();
	void print_items();
	void get_money(int choice, int value);
	void compare_availability(int selection);
	void return_money(char choice);
private:
	Products* products;
	int accepted_coins[4] = { 1,5,10,25 };
	int accepted_notes[2] = { 1,2 };

	Money* coins = new Money(accepted_coins, 4);
	Money* notes = new Money(accepted_notes, 2);

	int* amount_deposited = new int;
};
