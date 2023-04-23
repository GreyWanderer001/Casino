#include <vector>
#include <string>
#pragma once

class Customer
{
private:
	int balance = 0;
	std::string name = "";
	std::string password = "";

public:
	Customer(int balance, std::string name, std::string surname);
	void Display();
	void ChangeBalance(int newbalance);
	int GetBalance();

	

};