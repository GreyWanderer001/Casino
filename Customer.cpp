#include <iostream>
#include "Customer.h"



Customer::Customer(int balance, std::string name, std::string surname) {
	this->balance = balance;
	this->name = name;
	this->password = password;


}

void Customer::Display() {
	std::cout << this->balance << " " << this->name << std::endl;
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


