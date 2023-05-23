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
	double price;
	double rent;
	std::string type;

public:
	Arcade(std::string name, Casino* casino, double price, double rent, std::string type);
	void Display();
	void Play(Customer& customer, int bid);
	std::string GetName();
	std::string GetCasinoName();
	std::string GetType();
	double GetRent();
	double GetPrice();

	void SetName(std::string newVar);
	void SetRent(double newVar);
	void SetPrice(double newVar);
	void SetType(std::string newVar);

};

#endif