#include <iostream>
#include "Header.h"

int main()
{
	srand(time(NULL));
	Game G;
	G.input();
	G.output();
	cout << "\nTong suc sat thuong: " << G.totalAttack();;

	return 0;
}