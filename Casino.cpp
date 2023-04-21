#include <iostream>
#include "Casino.h"
#include <string>
#include "Arcade.h"

Casino::Casino(int balance, std::string name) {
	this->balance = balance;
	this->name = name;
}

void Casino::Display() {
	std::cout << this->balance << " " << this->name << " " <<  std::endl;
}

void Casino::CreateArcade(std::string name) {
	Arcade arcade(name);
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