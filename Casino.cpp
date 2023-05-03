#include <iostream>
#include "Casino.h"
#include <string>


Casino::Casino(int balance, std::string name) { // constructor
	this->balance = balance;
	this->name = name;
}

void Casino::Display() { // display all fields
	std::cout << this->balance << " " << this->name << " " <<  std::endl;
}

void Casino::DisplayArcades() { // display all arcades from vector
	for (int i = 0; i < arcades.size(); i++)
		std::cout << i+1 << ". " << arcades.at(i).GetName() << std::endl;
}

void Casino::CreateArcade(std::string name) { // create new arcade and add it to vector
	
	Arcade arcade(name, this);
	this->arcades.push_back(arcade);
}

int Casino::GetArcadesSize() { // get arcades vector size
	return arcades.size();
}

std::string Casino::GetName() { // get casino name
	return this->name;
}

Arcade Casino::GetArcade(int index) { // get arcade by index
	return this->arcades.at(index);
}

Arcade Casino::GetArcadeByName(std::string name) { // get arcade by name
	for (int i = 0; i < this->arcades.size(); i++)
		if (this->arcades.at(i).GetName() == name)
			return this->arcades.at(i);

}

void Casino::ChangeBalance(int newbalance) { // change casino`s balance
	if (newbalance < 0 && this->balance < std::abs(newbalance)) {
		this->balance = balance;
	}
	else {
		this->balance += newbalance;


	}
}

int Casino::GetBalance() { // get casino balance
	return this->balance;
}