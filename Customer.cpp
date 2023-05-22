#include <iostream>
#include "Customer.h"



Customer::Customer(int balance, std::string username, std::string password, std::string name, std::string surname, int age, std::string email, std::string phone) {
	this->balance = balance;
	this->username = username;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->email = email;
	this->phone = phone;
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

std::string Customer::GetUsername() {
	return this->username;
}

std::string Customer::GetPass() {
	return this->password;
}

std::string Customer::GetName() {
	return this->name;
}

std::string Customer::GetSurname() {
	return this->surname;
}

int Customer::GetAge() {
	return this->age;
}

std::string Customer::GetEmail() {
	return this->email;
}

std::string Customer::GetPhone() {
	return this->phone;
}