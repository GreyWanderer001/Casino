#include <iostream>
#include "Customer.h"



Customer::Customer(int balance, std::string name, std::string password) {
	this->balance = balance;
	this->name = name;
	this->password = password;


}

void Customer::Display() {
	std::cout << this->balance << " " << this->name << " " << this->password << std::endl;
}
void Customer::ChangeBalance(int newbalance) {
	if (newbalance < 0 && this->balance < std::abs(newbalance)) {
		this->balance = balance;
	}
	else {
		this->balance += newbalance;

	}
}

int Customer::GetBalance() {
	return this->balance;
}

std::string Customer::GetName() {
	return this->name;
}

std::string Customer::GetPass() {
	return this->password;
}