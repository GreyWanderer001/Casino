#include <iostream>
#include "Customer.h"



Customer::Customer(int balance, std::string name, std::string password) { // constructor
	this->balance = balance;
	this->name = name;
	this->password = password;

}

void Customer::Display() { //display all fields
	std::cout << this->balance << " " << this->name << " " << this->password << std::endl;
}
void Customer::ChangeBalance(int newbalance) { // change customer`s balance
	if (newbalance < 0 && this->balance < std::abs(newbalance)) { // if newbalance is < 0
		this->balance = balance;
	}
	else {
		this->balance += newbalance;

	}
}

int Customer::GetBalance() { // get customer balance
	return this->balance;
}

std::string Customer::GetName() { // get customer name
	return this->name;
}

std::string Customer::GetPass() { // get customer password
	return this->password;
}