#include <iostream>

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
			customer.ChangeBalance(-bid);
			this->casino->ChangeBalance(bid);


		}
	}
	
}

std::string Arcade::GetName() {
	return this->GameName;
}