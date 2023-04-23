#include <iostream>
#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

#include <fstream>

using namespace std;

int Register(std::string name, std::string password);
void ReadCustomers();

std::vector<Customer> customers;






int main()
{
	

	int me = Register("aaaaaa", "bbbbbb");




	Casino b(100, "fenix");


	b.Display();

	b.CreateArcade("Flappybox");

	b.GetArcade(0).Play(customers.at(me), 20);
	customers.at(me).Display();
	b.Display();






	//b.GetArcade(0).Play(a, 10);
	//b.GetArcadeByName("Flappybox").Play(a, 10);

	//a.Display();
	//b.Display();
	
	return 0;
}

int Register(std::string name, std::string password) {
	/*
	while (name.length() < 4) {
		std::cout << "username must be at least 4 chars" << std::endl;
		std::cin >> name;
		if (true) {
			//check for same usernames
			while (password.length() < 4) {
				std::cout << "password must be at least 4 chars" << std::endl;
				std::cin >> password;
			}

			

			Customer registred(100, name, password);
			customers.push_back(registred);

			for (int i = 0; i < customers.size(); i++)
				std::cout << i << std::endl;

			std::cout << "registred" << std::endl;


			return customers.size()-1;


		}
	}

	*/
	Customer registred(100, name, password);
	customers.push_back(registred);
	std::cout << "registred" << std::endl;
	return customers.size() - 1;
}

void ReadCustomers() {
	//read from json and append all customers to vector "customers"
}