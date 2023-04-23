#include <iostream>
#include "Casino.h"
#include <string>


Casino::Casino(int balance, std::string name) {
	this->balance = balance;
	this->name = name;
}

void Casino::Display() {
	std::cout << this->balance << " " << this->name << " " <<  std::endl;
}

void Casino::CreateArcade(std::string name) {
	
	Arcade arcade(name, this);
	this->arcades.push_back(arcade);
}


Arcade Casino::GetArcade(int index) {
	return this->arcades.at(index);
}

Arcade Casino::GetArcadeByName(std::string name) {
	for (int i = 0; i < this->arcades.size(); i++)
		if (this->arcades.at(i).GetName() == name)
			return this->arcades.at(i);

}

void Casino::ChangeBalance(int newbalance) {
	if (newbalance < 0 && this->balance < std::abs(newbalance)) {
		this->balance = balance;
	}
	else {
		this->balance += newbalance;


	}
}

int Casino::GetBalance() {
	return this->balance;
}