#include <iostream>
#include<cstdlib>
#include "Customer.h"
#include "Casino.h"

Arcade::Arcade(std::string name, Casino* casino) {

	this->GameName = name;
	this->casino = casino;
}

void Arcade::Display() {
	std::cout << this->GameName << std::endl;
}

void Arcade::Play(Customer &customer, int bid) {
	if (bid > this->casino->GetBalance()) {
		std::cout << "\nCasino dont have this amount of money!\n" << std::endl;
	}
	else {
		if (customer.GetBalance() < bid) {
			std::cout << "\nInsufficient funds\n" << std::endl;
		}
		else {
			srand(time(NULL));
			int random = rand() % 2 + 1;
			if (random == 1) {
				customer.ChangeBalance(-bid);
				this->casino->ChangeBalance(bid);
				system("CLS");
				std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
				std::cout << "User: " << customer.GetUsername() << " | Balance: " << customer.GetBalance() << "$\n";
				std::cout << "\n";
				std::cout << "You lose";
			}
			else {
				customer.ChangeBalance(bid);
				this->casino->ChangeBalance(-bid);
				system("CLS");
				std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
				std::cout << "User: " << customer.GetUsername() << " | Balance: " << customer.GetBalance() << "$\n";
				std::cout << "\n";
				std::cout << "You won";
			}
			


		}
	}
	
}

std::string Arcade::GetName() {
	return this->GameName;
}

std::string Arcade::GetCasinoName() {
	return this->casino->GetName();
}