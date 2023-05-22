#include <vector>
#include <string>
#pragma once

class Customer
{
private:
	int balance = 0;
	std::string username = "";
	std::string password = "";

	std::string name = "";
	std::string surname = "";

	std::string email = "";
	std::string phone = "";

	int age = 0;

public:
	Customer(int balance, std::string username, std::string password, std::string name, std::string surname, int age, std::string email, std::string phone);
	void ChangeBalance(int newbalance);
	int GetBalance();
	std::string GetUsername();
	std::string GetPass();
	std::string GetName();
	std::string GetSurname();
	int GetAge();
	std::string GetEmail();
	std::string GetPhone();
};