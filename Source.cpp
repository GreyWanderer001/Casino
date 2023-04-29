#include <iostream>
#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

#include <fstream>

using namespace std;

int Register(std::string name, std::string password);
int Login(std::string name, std::string password);
void ReadCustomers();
void ReadCasino();
void ReadArcade();

std::vector<Customer> customers;
std::vector<Casino> casinos;

int me = -1;
int choice = 0;
int choice2 = 0;
int choice3 = 0;
int bid;
bool doublebreak = false;
std::string name = "";
std::string password = "";




int main()
{
	Casino b(100, "fenix");
	casinos.push_back(b);
	casinos.at(0).CreateArcade("Flappybox");
	


	while (me < 0) {
		std::cout << "1 - login, 2 - register, other to exit" << std::endl;
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "enter name" << std::endl;
			std::cin >> name;
			std::cout << "enter password" << std::endl;
			std::cin >> password;
			//me = Login(name, password);
		}
		else if (choice == 2) {
			std::cout << "enter name" << std::endl;
			std::cin >> name;
			std::cout << "enter password" << std::endl;
			std::cin >> password;
			me = Register(name, password);
		}
		else {
			break;
		}
		while (me > -1) {
			
			std::cout << "1 - go to the casino, other - exit" << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "choose casino to go to " << std::endl;
				for (int i = 0; i < casinos.size(); i++)
					std::cout << i << " - " << casinos.at(i).GetName() << std::endl;
				
				std::cin >> choice3;

				while (choice3 > casinos.size() || choice3 < 0) {
					std::cout << "choose casino to go to " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i << " - " << casinos.at(i).GetName() << std::endl;

					std::cin >> choice3;
				}

				while (true) {
					


					std::cout << "choose arcade" << std::endl;
					casinos.at(choice3).DisplayArcades();
					std::cin >> choice2;

					if (choice2 == -1) {
						break;
					}

					while (choice2 > casinos.at(choice3).GetArcadesSize() - 1 || choice2 < 0) {
						std::cout << "choose correct arcade" << std::endl;
						casinos.at(choice3).DisplayArcades();
						std::cin >> choice2;
						//if (choice == -1) {
						//	doublebreak = true;
						//	break;
						//}
					}

					//if (doublebreak) {
					//	doublebreak = false;
					//	break;
					//}



					std::cout << "Your balance: " << customers.at(me).GetBalance() << " Enter your bid ";
					std::cin >> bid;

					if (bid == -1) {
						break;
					}

					while (bid > customers.at(me).GetBalance() || bid < 0) {
						std::cout << "Enter your bid correctly" << std::endl;
						std::cout << "Your balance: " << customers.at(me).GetBalance() << " Enter your bid ";
						std::cin >> bid;
						//if (bid == -1) {
						//	doublebreak = true;
						//	break;
						//}
					}

					//if (doublebreak) {
					//	doublebreak = false;
					//	break;
					//}



					casinos.at(choice3).GetArcade(choice2).Play(customers.at(me), bid);
				}



				
				
			}
			else {
				break;
			}

		}
	}

	




	






	
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

/*
int Login(std::string name, std::string password) {
	while (true) {
		for (int i = 0; i < customers.size(); i++) {
			if (customers.at(i).GetName() == name && customers.at(i).GetPass() == password) {
				return i;
			}
		}
		std::cout << "Incorrect name or password" << std::endl;
		std::cout << "Enter name, type nothing to exit" << std::endl;
		std::cin >> name;
		std::cout << "Enter password, type nothing to exit" << std::endl;
		std::cin >> password;
		if (name == "" || password == "") {
			return -1;
		}
	}


}
*/

void ReadCustomers() {
	//read from json and append all customers to vector "customers"
}

void ReadCasino()
{
}

void ReadArcade()
{
}
