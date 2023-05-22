#include "Customer.h"
#include <string>
#pragma once
#ifndef Arcade_H
#define Arcade_H

class Casino;

class Arcade
{
private:
	std::string GameName = "";
	Casino* casino; // vector of pointers to casinos
	int price;
	int rent;
	std::string type;

public:
	Arcade(std::string name, Casino* casino);
	void Display();
	void Play(Customer &customer, int bid);
	std::string GetName();
	std::string GetCasinoName();



};

#endif