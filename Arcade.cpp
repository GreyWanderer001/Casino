#include <iostream>
#include "Arcade.h"
#include "Customer.h"

Arcade::Arcade(std::string name) {

	this->GameName = name;
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

	}
}

std::string Arcade::GetName() {
	return this->GameName;
}