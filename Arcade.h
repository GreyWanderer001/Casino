#include "Customer.h"
#include <string>
#pragma once

class Arcade
{
private:
	std::string GameName = "";

public:
	Arcade(std::string name);
	void Display();
	void Play(Customer &customer, int bid);
	std::string GetName();



};