class Money {
public:
	Money();
	Money(int* a, int how_many);
	int check(int value, int loop_max);
	~Money();
	int* max = new int;
private:
	
	int* accepted_values = new int[10];
};
