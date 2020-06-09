#include "Money.h"
Money::Money() {

};

Money::Money(int* a, int how_many) {
    *max = how_many;
    for (int i = 0; i < how_many; i++) {
        *(accepted_values + i) = a[i];
    }
}

int Money::check(int value, int loop_max) {
    bool present = 0;
    for (int i = 0; i < loop_max; i++) {
        if (value == *(accepted_values + i)) {
            present = 1;
        }
    }
    if (!present) {
        value = 0;
    }
    return value;
};

Money::~Money() {
    delete max;
    delete accepted_values;
}