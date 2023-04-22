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
	if (customer.GetBalance() < bid) {
		std::cout << "Insufficient funds" << std::endl;
	}
	else {
		customer.ChangeBalance(-bid);
		this->casino->ChangeBalance(bid);
	

	}
}

std::string Arcade::GetName() {
	return this->GameName;
}