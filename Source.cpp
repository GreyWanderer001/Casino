#include <iostream>
#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

#include <fstream>

using namespace std;

int main()
{




	Customer a(100, "aaa", "bbb");
	cout << "Hello world" << endl;

	a.Display();

	Casino b(100, "fenix");

	b.Display();

	b.CreateArcade("Flappybox");





	b.GetArcade(0).Play(a, 10);
	b.GetArcadeByName("Flappybox").Play(a, 10);

	a.Display();
	
	return 0;
}