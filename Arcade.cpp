#include <iostream>
#include<cstdlib>
#include "Customer.h"
#include "Casino.h"

Arcade::Arcade(std::string name, Casino* casino) {

	this->GameName = name;
	this->casino = casino;
}

void Arcade::Display() { // display arcade
	std::cout <<   this->GameName   << std::endl;
}

void Arcade::Play(Customer &customer, int bid) { // Customer plays casino
	if (bid > this->casino->GetBalance()) { // if casino don`t have enough money
		std::cout << "\nCasino dont have this amount of money!\n" << std::endl;
	}
	else {
		if (customer.GetBalance() < bid) { // if customer don`t have enough money
			std::cout << "\nInsufficient funds\n" << std::endl;
		}
		else {
			srand(time(NULL)); // random seed
			int random = rand() % 2 + 1;
			if (random == 1) { // customer lose
				customer.ChangeBalance(-bid);
				this->casino->ChangeBalance(bid);
				system("CLS"); // clear console
				std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
				std::cout << "User: " << customer.GetName() << " | Balance: " << customer.GetBalance() << "\n";
				std::cout << "\n";
				std::cout << "You lose";
			}
			else { // customer win
				customer.ChangeBalance(bid);
				this->casino->ChangeBalance(-bid);
				system("CLS"); // clear console
				std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
				std::cout << "User: " << customer.GetName() << " | Balance: " << customer.GetBalance() << "\n";
				std::cout << "\n";
				std::cout << "You won";
			}
			


		}
	}
	
}

std::string Arcade::GetName() { // get arcade name
	return this->GameName;
}

std::string Arcade::GetCasinoName() { // get casino name
	return this->casino->GetName();
}