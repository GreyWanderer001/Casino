#include <iostream>
#include<cstdlib>
#include "Customer.h"
#include "Casino.h"

Arcade::Arcade(std::string name, Casino* casino) {

	this->GameName = name;
	this->casino = casino;
}

void Arcade::Display() {
	std::cout <<   this->GameName   << std::endl;
}

void Arcade::Play(Customer &customer, int bid) {
	if (bid > this->casino->GetBalance()) {
		std::cout << "Casino dont have this amount of money" << std::endl;
	}
	else {
		if (customer.GetBalance() < bid) {
			std::cout << "Insufficient funds" << std::endl;
		}
		else {
			srand(time(NULL));
			int random = rand() % 2 + 1;
			std::cout << random << std::endl;
			if (random == 1) {
				customer.ChangeBalance(-bid);
				this->casino->ChangeBalance(bid);
				std::cout << "You lose, your balance: " << customer.GetBalance() << std::endl;
			}
			else {
				customer.ChangeBalance(bid);
				this->casino->ChangeBalance(-bid);
				std::cout << "You won, your balance: " << customer.GetBalance() << std::endl;
			}
			


		}
	}
	
}

std::string Arcade::GetName() {
	return this->GameName;
}