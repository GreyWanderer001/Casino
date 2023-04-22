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
	Casino* casino;

public:
	Arcade(std::string name, Casino* casino);
	void Display();
	void Play(Customer &customer, int bid);
	std::string GetName();



};

#endif