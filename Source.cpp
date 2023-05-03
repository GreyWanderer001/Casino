#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

using namespace std;

void izvade();
void ReadArcade();
void ReadCasino();
void writeToArcade();
void ReadCustomers();
void writeToCasino();
void writeToCustomers();
int checkUser(string username, string password);
void registerUser(string username, string password);

std::vector<Casino> casinos;
std::vector<Customer> customers;

int me = -1;
int choice = 0;
int choice2 = 0;
int choice3 = 0;
int bid;
bool doublebreak = false;

int main()
{

	izvade();

	ReadCasino();
	ReadCustomers();
	ReadArcade();

	string username, password;


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

			else if (choice == 4) {
				std::cout << "Enter Casino name: ";
				std::string name;
				std::cin >> name;

				std::cout << "Enter Casino balance: ";
				int balance;
				std::cin >> balance;

				while (balance <= 0) {
					std::cout << "Enter correct balance (>0): ";
					std::cin >> balance;
				}

				Casino create(balance, name);
				casinos.push_back(create);
			}

			else if (choice == 5) {
				
				int Casinonum;

				std::cout << "In which Casino would you like to put arcade?: " << std::endl;
				for (int i = 0; i < casinos.size(); i++)
					std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
				std::cout << "-> ";
				std::cin >> Casinonum;
				Casinonum -= 1;

				while (Casinonum >= casinos.size() || Casinonum < 0) {
					std::cout << "Choose correct casino number: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
					std::cout << "-> ";
					std::cin >> Casinonum;
					Casinonum -= 1;
				}

				std::cout << "Enter Arcade name: ";
				std::string Arcadename;
				std::cin >> Arcadename;

				casinos.at(Casinonum).CreateArcade(Arcadename);
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
					std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
				std::cout << "-> ";
				std::cin >> choice3;
				choice3 -= 1;

				while (choice3 >= casinos.size() || choice3 < 0) {
					std::cout << "Choose correct casino number: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
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

					if (choice2 == -2) {
						break;
					}

					while (choice2 > casinos.at(choice3).GetArcadesSize() - 1 || choice2 < 0) {
						std::cout << "Choose correct  (write \"-1\" to exit): " << std::endl;
						casinos.at(choice3).DisplayArcades();
						std::cout << "-> ";
						std::cin >> choice2;
						choice2 -= 1;
						if (choice2 == -2) {
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

	writeToArcade();
	writeToCasino();
	writeToCustomers();
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

void writeToCustomers() {
	std::ofstream file("users.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("users.txt");

	for (int i = 0; i < customers.size(); i++) {
		file1 << customers.at(i).GetName() << ":" << customers.at(i).GetPass() << ":" << customers.at(i).GetBalance() << std::endl;
	}

	file1.close();
}

void ReadCustomers() {
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

void ReadCasino()
{
	std::ifstream file("casino.txt");

	std::string line;

	while (std::getline(file, line)) {
		size_t delimiter_pos = line.find(':');
		std::string name = line.substr(0, delimiter_pos);
		double balance = std::stod(line.substr(delimiter_pos + 1));
		Casino info(balance, name);
		casinos.push_back(info);
	}

	file.close();

}

void writeToCasino() {
	std::ofstream file("casino.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("casino.txt");

	for (int i = 0; i < casinos.size(); i++) {
		file1 << casinos.at(i).GetName() << ":" << casinos.at(i).GetBalance() << std::endl;
	}

	file1.close();
}

void ReadArcade()
{
	std::ifstream file("arcade.txt");

	std::string line;

	while (std::getline(file, line)) {
		std::string delimiter = ":";
		std::string name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		std::string casinoname = line.substr(0, line.find(delimiter));
		for (int i = 0; i < casinos.size(); i++) {
			if (casinoname == casinos.at(i).GetName()) {
				casinos.at(i).CreateArcade(name);
			}
		}

	}

	file.close();
}

void writeToArcade()
{
	std::ofstream file("arcade.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("arcade.txt");

	for (int i = 0; i < casinos.size(); i++) {
		for (int y = 0; y < casinos.at(i).GetArcadesSize(); y++) {
			file1 << casinos.at(i).GetArcade(y).GetName() << ":" << casinos.at(i).GetArcade(y).GetCasinoName() << std::endl;
		}
	}

	file1.close();
}
