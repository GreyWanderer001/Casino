#include <iostream>
#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void readCustomers();
void ReadCasino();
void ReadArcade();
void writeToFile();
void izvade();

std::vector<Customer> customers;
std::vector<Casino> casinos;

int me = -1;
int choice = 0;
int choice2 = 0;
int choice3 = 0;
int bid;
bool doublebreak = false;

void registerUser(string username, string password) {
	bool parbaude = false;
	for (int i = 0; i < customers.size(); i++) {
		if (username == customers.at(i).GetName()) {
			parbaude = true;
			cout << "\n";
			std::cout << "\nUser already exsist!";
		}
	}
	if (parbaude) {

	}
	else {
		Customer registred(100, username, password);
		customers.push_back(registred);
		ofstream outfile("users.txt", ios::app);
		outfile << username << ":" << password << ":" << 100 << endl;
		outfile.close();
		cout << "\n";
		cout << "\nThank you for registration in our Casino!";
	}


}

int checkUser(string username, string password) {
	for (int i = 0; i < customers.size(); i++) {
		if (username == customers.at(i).GetName() && customers.at(i).GetPass() == password) {
			return i;

		}
	}
	return -1;
}


int main()
{

	izvade();

	readCustomers();

	string username, password;

	Casino b(100, "Fenix");
	casinos.push_back(b);
	casinos.at(0).CreateArcade("Flappybox");


	while (me < 0) {
		while (choice != 3) {
			cout << "\n1. Register\n2. Login\n3. Exit\n";
			cout << "-> ";
			cin >> choice;
			cout << "\n";

			if (choice == 1) {
				cout << "Enter username: ";
				cin >> username;
				cout << "Enter password: ";
				password = "";
				char ch;
				while ((ch = _getch()) != '\r') {
					password += ch;
					cout << "*";
				}
				registerUser(username, password);
				cout << endl;
			}
			else if (choice == 2) {
				cout << "Enter username: ";
				cin >> username;
				cout << "Enter password: ";
				password = "";
				char c;
				while ((c = _getch()) != '\r') {
					password += c;
					cout << "*";
				}
				me = checkUser(username, password);
				if (me > -1) {
					choice = 3;

				}
				else {
					std::cout << "\nIncorrect login or password!\n";
				}
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "Invalid choice.\n";
			}
		}

		izvade();

		while (me > -1) {

			std::cout << "\nGo to the casino - 1\nExit - 0" << std::endl;
			std::cout << "-> ";
			std::cin >> choice;
			cout << "\n";
			if (choice == 1) {
				std::cout << "Choose casino: " << std::endl;
				for (int i = 0; i < casinos.size(); i++)
					std::cout << i+1 << ". " << casinos.at(i).GetName() << std::endl;
				std::cout << "-> ";
				std::cin >> choice3;
				choice3 -= 1;

				while (choice3 > casinos.size() || choice3 < 0) {
					std::cout << "Choose casino: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i+1 << ". " << casinos.at(i).GetName() << std::endl;
					std::cout << "-> ";
					std::cin >> choice3;
					choice3 -= 1;
				}

				while (true) {

					cout << "\n";
					std::cout << "Choose arcade (write \"-1\" to exit): " << std::endl;
					casinos.at(choice3).DisplayArcades();
					std::cout << "-> ";
					std::cin >> choice2;
					choice2 -= 1;

					if (choice2 == -1) {
						break;
					}

					while (choice2 > casinos.at(choice3).GetArcadesSize() - 1 || choice2 < 0) {
						std::cout << "Choose correct  (write \"-1\" to exit): " << std::endl;
						casinos.at(choice3).DisplayArcades();
						std::cout << "-> ";
						std::cin >> choice2;
						choice2 -= 1;
						if (choice2 == -1) {
							doublebreak = true;
							break;
						}
					}

					if (doublebreak) {
						doublebreak = false;
						break;
					}

					izvade();

					while (true) {
						cout << "\n";
						std::cout <<"Enter your bid (write \"-1\" to exit): ";
						std::cin >> bid;

						if (bid == -1) {
							doublebreak = true;
							break;
						}

						while (bid > customers.at(me).GetBalance() || bid < 0) {
							cout << "\n";
							std::cout << "Enter your bid correctly (write \"-1\" to exit): ";
							std::cin >> bid;
							if (bid == -1) {
								doublebreak = true;
								break;
							}
						}

						if (doublebreak) {
							break;
						}


						izvade();
						casinos.at(choice3).GetArcade(choice2).Play(customers.at(me), bid);
					}

					if (doublebreak) {
						doublebreak = false;
						break;
					}


				}





			}
			else {
				break;
			}

		}
		break;

	}













	writeToFile();
	return 0;
}


void izvade() {
	system("CLS");
	std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
	if (me > -1) {
		std::cout << "User: " << customers.at(me).GetName() << " | Balance: " << customers.at(me).GetBalance() << "\n";
	}
	else {
		std::cout << "User: - | Balance: - \n";
	}
}

void writeToFile() {
	std::ofstream file("users.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("users.txt");

	for (int i = 0; i < customers.size(); i++) {
		file1 << customers.at(i).GetName() << ":" << customers.at(i).GetPass() << ":" << customers.at(i).GetBalance() << std::endl;
	}

	file1.close();
}

void readCustomers() {
	std::ifstream file("users.txt");

	std::string line;
	while (std::getline(file, line)) {
		std::string delimiter = ":";
		std::string username = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		std::string password = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		int balance = std::stoi(line);
		Customer info(balance, username, password);
		customers.push_back(info);
	}

	file.close();
}

void ReadCasino()
{
}

void ReadArcade()
{
}
