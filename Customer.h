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
	Customer(int balance, std::string name, std::string password);
	void Display();
	void ChangeBalance(int newbalance);
	int GetBalance();
	std::string GetName();
	std::string GetPass();

	

};