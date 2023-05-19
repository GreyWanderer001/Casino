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

int me = -1; // client position in vector customers
int choice = 0;
int choice2 = 0;
int choice3 = 0;
int bid;
bool doublebreak = false; // to exit from two loops at once


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
			cin.clear();//clears state of cin
			cin.ignore(INT_MAX, '\n'); // this clears console

			if (choice == 1) {
				cout << "Enter username: ";
				cin >> username;
				cout << "Enter password: ";

				bool valid = false;
				while (!valid) {
					password = "";

					while (true) {
						char ch = _getch();
						if (ch == '\r') { // Check for Enter key
							cout << endl; // Output a newline to move to the next line
							break;
						}
						else if (ch == '\b') { // Check for Backspace key
							if (!password.empty()) {
								password.pop_back();
								cout << "\b \b"; // Output backspace, space, and backspace to erase the last character
							}
						}
						else {
							password += ch;
							cout << "*";
						}
					}

					if (password.length() >= 8) { // Check if the string is at least 8 characters long
						for (char c : password) {
							if (std::isupper(c)) { // Check if the character is an uppercase letter
								valid = true;
								break;
							}
						}
					}

					if (valid) {
						break;
					}
					else {
						cout << "\nPassword must be at least 8 characters long and contain an uppercase letter.\n";
						cout << "Enter password: ";
					}
				}
				for (int i = 0; (i < 100 && password[i] != '\0'); i++)
					password[i] = password[i] + 2; //the key for encryption is 3 that is added to ASCII value

				registerUser(username, password);
				cout << endl;
			}

			else if (choice == 2) {
				cout << "Enter username: ";
				cin >> username;
				cout << "Enter password: ";
				password = "";
				while (true) {
					char ch = _getch();
					if (ch == '\r') {
						break;
					}
					else if (ch == '\b') {
						if (!password.empty()) {
							password.pop_back();
							cout << "\b \b";
						}
					}
					else {
						password += ch;
						cout << "*";
					}
				}


				for (int i = 0; (i < 100 && password[i] != '\0'); i++)
					password[i] = password[i] + 2; //the key for encryption is 3 that is added to ASCII value
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
					std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
				std::cout << "-> ";
				std::cin >> choice3;
				cin.clear();//clears state of cin
				cin.ignore(INT_MAX, '\n'); // this clears console
				choice3 -= 1;

				while (choice3 >= casinos.size() || choice3 < 0) {
					std::cout << "Choose correct casino number: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
					std::cout << "-> ";
					std::cin >> choice3;
					cin.clear();//clears state of cin
					cin.ignore(INT_MAX, '\n'); // this clears console
					choice3 -= 1;
				}

				while (true) {

					cout << "\n";
					std::cout << "Choose arcade (write \"-1\" to exit): " << std::endl;
					casinos.at(choice3).DisplayArcades();
					std::cout << "-> ";
					std::cin >> choice2;
					cin.clear();//clears state of cin
					cin.ignore(INT_MAX, '\n'); // this clears console
					choice2 -= 1;

					if (choice2 == -2) {
						break;
					}

					while (choice2 > casinos.at(choice3).GetArcadesSize() - 1 || choice2 < 0) {
						std::cout << "Choose correct  (write \"-1\" to exit): " << std::endl;
						casinos.at(choice3).DisplayArcades();
						std::cout << "-> ";
						std::cin >> choice2;
						cin.clear();//clears state of cin
						cin.ignore(INT_MAX, '\n'); // this clears console
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

					izvade(); // display user info

					while (true) {
						cout << "\n";
						std::cout <<"Enter your bid (write \"-1\" to exit): ";
						std::cin >> bid;
						cin.clear();//clears state of cin
						cin.ignore(INT_MAX, '\n'); // this clears console

						if (bid == -1) {
							doublebreak = true;
							break;
						}

						while (bid > customers.at(me).GetBalance() || bid <= 0) {
							cout << "\n";
							std::cout << "Enter your bid correctly (write \"-1\" to exit): ";
							std::cin >> bid;
							cin.clear();//clears state of cin
							cin.ignore(INT_MAX, '\n'); // this clears console
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
			else if (choice == 4) {
				if (customers.at(me).GetName() == "admin") {
					std::cout << "Enter Casino name: ";
					std::string name;
					std::cin >> name;

					std::cout << "Enter Casino balance: ";
					int balance;
					std::cin >> balance;
					cin.clear();//clears state of cin
					cin.ignore(INT_MAX, '\n'); // this clears console

					while (balance <= 0) {
						std::cout << "Enter correct balance (>0): ";
						std::cin >> balance;

						cin.clear();//clears state of cin
						cin.ignore(INT_MAX, '\n'); // this clears console
					}

					Casino create(balance, name);
					casinos.push_back(create); // push in new created casino to casino vector
				}
				
			}

			else if (choice == 5) {
				if (customers.at(me).GetName() == "admin") {
					int Casinonum;

					std::cout << "In which Casino would you like to put arcade?: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
					std::cout << "-> ";
					std::cin >> Casinonum;
					cin.clear();//clears state of cin
					cin.ignore(INT_MAX, '\n'); // this clears console
					Casinonum -= 1;

					while (Casinonum >= casinos.size() || Casinonum < 0) {
						std::cout << "Choose correct casino number: " << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> Casinonum;
						cin.clear();//clears state of cin
						cin.ignore(INT_MAX, '\n'); // this clears console
						Casinonum -= 1;
					}

					std::cout << "Enter Arcade name: ";
					std::string Arcadename;
					std::cin >> Arcadename;

					casinos.at(Casinonum).CreateArcade(Arcadename);
				}
				
			}
			else if (choice == 0) {
				break;
			}
			else {
				std::cout << "Choose correct option: ";


			}

		}
		break;

	}

	writeToArcade(); // writting to file
	writeToCasino();
	writeToCustomers();
	return 0;
}


void izvade() {
	system("CLS");
	std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
	if (me > -1) {
		std::cout << "User: " << customers.at(me).GetName() << " | Balance: " << customers.at(me).GetBalance() << "$\n";
	}
	else {
		std::cout << "User: - | Balance: - \n";
	}
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

void ReadCustomers() {
	std::ifstream file("users.txt");

	std::string line;
	while (std::getline(file, line)) {
		std::string delimiter = ":";
		std::string username = line.substr(0, line.find(delimiter)); // reading username from start to delimiter -> ":"
		line.erase(0, line.find(delimiter) + delimiter.length()); // delete info from start to delimiter
		std::string password = line.substr(0, line.find(delimiter)); // reading password to second delimiter
		line.erase(0, line.find(delimiter) + delimiter.length());
		int balance = std::stoi(line); // reading remaining symbols (balance)
		Customer info(balance, username, password);
		customers.push_back(info);
	}

	file.close();
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

void writeToCasino() {
	std::ofstream file("casino.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("casino.txt");

	for (int i = 0; i < casinos.size(); i++) {
		file1 << casinos.at(i).GetName() << ":" << casinos.at(i).GetBalance() << std::endl;
	}

	file1.close();
}

void writeToCustomers() {
	std::ofstream file("users.txt", std::ios::trunc); // "std::ios::trunc" - file clear
	std::ofstream file1("users.txt");

	for (int i = 0; i < customers.size(); i++) {
		file1 << customers.at(i).GetName() << ":" << customers.at(i).GetPass() << ":" << customers.at(i).GetBalance() << std::endl;
	}

	file1.close();
}