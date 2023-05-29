#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <regex>


#include "Customer.h"
#include "Casino.h"
#include "Arcade.h"

using namespace std;

void deleteUser(int index);
void changeUserData(int index);

void izvade();
void ReadArcade();
void ReadCasino();
void writeToArcade();
void ReadCustomers();
void writeToCasino();
void writeToCustomers();
void changeCasinoData(int index);
void ChangeArcadeData(int indexA, int indexC);
int checkUser(string username, string password);
void registerUser(string username, string password, string name, string surname, int age, string email, string phone);

bool inputwithoutsemi(std::string stri);

std::vector<Casino> casinos;
std::vector<Customer> customers;

int me = -1; // client position in vector customers
int choice = 0;
int choice2 = 0;
int choice3 = 0;
int bid;
bool doublebreak = false; // to exit from two loops at once


int wincount = 0;
int losecount = 0;
int losebetcount = 0;
int winbetcount = 0;
int userregistedcount = 0;
int casinocreatedcount = 0;
int arcadecreatedcount = 0;


bool isPhoneNumberValid(const std::string& phone) {
	// Regular expression to validate phone numbers
	std::regex phoneRegex("^\\+[1-9]\\d{1,14}$");

	// Check if the phone number matches the regex pattern
	return std::regex_match(phone, phoneRegex);
}

bool isEmailAddressValid(const std::string& email) {
	// Regular expression to validate email addresses
	std::regex emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

	// Check if the email address matches the regex pattern
	return std::regex_match(email, emailRegex);
}


bool compareUsersByBalance(Customer& u1, Customer& u2) {
	return u1.GetBalance() > u2.GetBalance();
}

bool compareUsersByName(Customer& u1, Customer& u2) {
	if (u1.GetName().length() == u2.GetName().length()) {
		return u1.GetName() < u2.GetName();
	}
	return u1.GetName().length() < u2.GetName().length();
}

bool compareUsersByAge(Customer& u1, Customer& u2) {
	return u1.GetAge() > u2.GetAge();
}


bool compareCasinosByName(Casino& u1, Casino& u2) {
	if (u1.GetName().length() == u2.GetName().length()) {
		return u1.GetName() < u2.GetName();
	}
	return u1.GetName().length() < u2.GetName().length();
}

bool compareCasinosByBalance(Casino& u1, Casino& u2) {
	return u1.GetBalance() > u2.GetBalance();
}

bool compareCasinosBySqm(Casino& u1, Casino& u2) {
	return u1.GetSqm() > u2.GetSqm();
}

bool compareCasinosByFloor(Casino& u1, Casino& u2) {
	return u1.GetFloors() > u2.GetFloors();
}

bool compareArcadesByRent(Arcade& u1, Arcade& u2) {
	return u1.GetRent() > u2.GetRent();
}

bool compareArcadesByPrice(Arcade& u1, Arcade& u2) {
	return u1.GetPrice() > u2.GetPrice();
}

bool compareArcadesByName(Arcade& u1, Arcade& u2) {
	if (u1.GetName().length() == u2.GetName().length()) {
		return u1.GetName() < u2.GetName();
	}
	return u1.GetName().length() < u2.GetName().length();
}

bool compareArcadesByType(Arcade& u1, Arcade& u2) {
	if (u1.GetType().length() == u2.GetType().length()) {
		return u1.GetType() < u2.GetType();
	}
	return u1.GetType().length() < u2.GetType().length();
}




int main()
{
	std::string adminUsername = "admin";
	std::string adminPassword = "cfokp";

	izvade();

	ReadCasino();
	ReadCustomers();
	ReadArcade();

	string username = "";
	string password = "";

	string name = "";
	string surname = "";
	string email = "";
	string phone = "";

	int age = 0;






	while (me < 0) {
		while (choice != 3) {
			std::cout << "\n1. Register\n2. Login\n3. Exit\n";

			std::cout << "-> ";
			std::cin >> choice;
			std::cout << "\n";
			std::cin.clear();//clears state of cin
			std::cin.ignore(INT_MAX, '\n'); // this clears console

			if (choice == 1) {

				while (inputwithoutsemi(name)) {
					std::cout << "Enter Your Name: ";
					std::cin >> name;

				}

				while (inputwithoutsemi(surname)) {
					std::cout << "Enter Your Surname: ";
					std::cin >> surname;

				}




				while (true) {

					if (age < 18) {
						std::cout << "How old are You?: ";
						std::cin >> age;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
					}
					else {
						break;
					}
				}


				while (true) {
					if (isEmailAddressValid(email) != true || inputwithoutsemi(email)) {


						std::cout << "Enter your E-mail address: ";
						std::cin >> (std::cin, email);



					}
					else {
						break;
					}
				}

				while (true) {
					if (isPhoneNumberValid(phone) != true || inputwithoutsemi(phone)) {
						std::cout << "Enter your phone number (example: +37129578473): ";
						std::cin >> (std::cin, phone);


					}
					else {
						break;
					}
				}


				while (username == "admin" || username.length() <= 3 || inputwithoutsemi(username)) {
					std::cout << "Enter username (not admin!!!): ";
					std::cin >> username;
				}

				std::cout << "Enter password: ";

				bool valid = false;
				while (!valid) {
					password = "";

					while (true) {
						char ch = _getch();
						if (ch == '\r') { // Check for Enter key
							std::cout << endl; // Output a newline to move to the next line
							break;
						}
						else if (ch == '\b') { // Check for Backspace key
							if (!password.empty()) {
								password.pop_back();
								std::cout << "\b \b"; // Output backspace, space, and backspace to erase the last character
							}
						}
						else {
							password += ch;
							std::cout << "*";
						}
					}

					if (password.length() >= 8) { // Check if the string is at least 8 characters long and do not contain :
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
						std::cout << "\nPassword must be at least 8 characters long and contain an uppercase letter.\n";
						std::cout << "Enter password: ";
					}
				}
				for (int i = 0; (i < 100 && password[i] != '\0'); i++) {
					if (password[i] == '8') {
						password[i] = password[i] + 3;
					}
					else {
						password[i] = password[i] + 2;

					}

				}

				registerUser(username, password, name, surname, age, email, phone);
				std::cout << endl;
			}

			else if (choice == 2) {
				username = "";
				while (inputwithoutsemi(username)) {
					std::cout << "Enter username: ";

					std::cin >> username;

				}

				std::cout << "Enter password: ";
				password = "";

				while (true) {
					char ch = _getch();
					if (ch == '\r') {
						break;
					}
					else if (ch == '\b') {
						if (!password.empty()) {
							password.pop_back();
							std::cout << "\b \b";
						}
					}
					else {
						password += ch;
						std::cout << "*";
					}
				}

				for (int i = 0; (i < 100 && password[i] != '\0'); i++) {
					if (password[i] == '8') {
						password[i] = password[i] + 3;
					}
					else {
						password[i] = password[i] + 2;
					}

				}
				me = checkUser(username, password);
				if (username == adminUsername && password == adminPassword) {
					me = -2; // Set a special value for the admin
					choice = 3;
				}

				if (me > -1 || me == -2) {
					choice = 3;

				}
				else {
					std::cout << "\nIncorrect login or password!\n";
				}




			}
			else if (choice == 3) {
				doublebreak = true;
				break;
			}


			else {
				std::cout << "Invalid choice.\n";
			}
		}

		izvade();

		while (me > -1 || me == -2) { // Allow admin to access the options


			if (me == -2) {
				std::cout << "\n1. Admin settings\n2. Logout" << std::endl;
			}
			else {
				std::cout << "\n1. Go to the casino\n2. Logout" << std::endl;

			}
			std::cout << "-> ";
			std::cin >> choice;

			std::cin.clear();//clears state of cin
			std::cin.ignore(INT_MAX, '\n'); // this clears console

			if (choice == 1 && me != -2) {

				std::cout << "Choose casino: " << std::endl;
				for (int i = 0; i < casinos.size(); i++)
					std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
				std::cout << "-> ";
				std::cin >> choice3;
				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console
				choice3 -= 1;

				while (choice3 >= casinos.size() || choice3 < 0) {
					std::cout << "Choose correct casino number: " << std::endl;
					for (int i = 0; i < casinos.size(); i++)
						std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
					std::cout << "-> ";
					std::cin >> choice3;
					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console
					choice3 -= 1;
				}

				while (true) {

					std::cout << "\n";
					std::cout << "Choose arcade (write \"-1\" to exit): " << std::endl;
					casinos.at(choice3).DisplayArcades();
					std::cout << "-> ";
					std::cin >> choice2;
					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console
					choice2 -= 1;

					if (choice2 == -2) {
						break;
					}

					while (choice2 > casinos.at(choice3).GetArcadesSize() - 1 || choice2 < 0) {
						std::cout << "Choose correct  (write \"-1\" to exit): " << std::endl;
						casinos.at(choice3).DisplayArcades();
						std::cout << "-> ";
						std::cin >> choice2;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
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
						std::cout << "\n";
						std::cout << "Enter your bid (write \"-1\" to exit): ";
						std::cin >> bid;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						if (bid == -1) {
							doublebreak = true;
							break;
						}

						while (bid > customers.at(me).GetBalance() || bid <= 0) {
							std::cout << "\n";
							std::cout << "Enter your bid correctly (write \"-1\" to exit): ";
							std::cin >> bid;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							if (bid == -1) {
								doublebreak = true;
								break;
							}
						}

						if (doublebreak) {
							break;
						}


						izvade();
						int money = casinos.at(choice3).GetArcade(choice2).Play(customers.at(me), bid);
						if (money > 0) {
							wincount++;
							winbetcount += money;
						}
						if (money < 0) {
							losecount++;
							losebetcount += money;
						}
						writeToArcade(); // writting to file
						writeToCasino();
						writeToCustomers();
					}

					if (doublebreak) {
						doublebreak = false;
						break;
					}


				}

			}

			else if (choice == 1 && me == -2) {
				// Admin options
				std::cout << "\nAdmin Options:\n";
				std::cout << "1. Casino options\n";
				std::cout << "2. Arcades options\n";
				std::cout << "3. Users options\n";
				std::cout << "4. Exit\n";
				std::cout << "-> ";
				std::cin >> choice;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "Invalid input. Please enter a number.\n";
					continue;
				}

				if (choice == 1) {
					std::cout << "\nCasino Options:";
					std::cout << "\n1. Create Casino \n2. Delete Casino\n3. Change Casino data\n4. Search Casino\n5. Sort Casino\n6. Exit\n";
					std::cout << "-> ";
					std::cin >> choice;
					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console

					if (choice == 1) {
						std::string name = "";


						while (name.length() < 1 || inputwithoutsemi(name)) {
							std::cout << "Enter Casino name: ";
							std::cin >> name;
						}

						std::cout << "Enter Casino balance: ";
						int balance;
						std::cin >> balance;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						while (balance <= 0) {
							std::cout << "Enter correct balance (>0): ";
							std::cin >> balance;

							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
						}

						std::cout << "Enter Casino adress: ";
						std::string adress;
						std::getline(std::cin, adress);

						while (adress.length() < 5 || inputwithoutsemi(adress)) {
							std::cout << "Enter Casino adress: ";
							std::getline(std::cin, adress);
						}

						std::cout << "Enter Casino floors: ";
						int floors;
						std::cin >> floors;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						while (floors < 1) {
							std::cout << "Enter correct floors (>0): ";
							std::cin >> floors;

							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
						}

						std::cout << "Enter Casino sqm: ";
						double sqm;
						std::cin >> sqm;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						while (sqm <= 0.0) {
							std::cout << "Enter correct sqm (>0): ";
							std::cin >> sqm;

							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
						}


						Casino create(balance, name, adress, floors, sqm);
						casinos.push_back(create); // push in new created casino to casino vector
						casinocreatedcount++;
					}

					else if (choice == 2) {
						std::cout << "Choose casino (write \"-1\" to exit): " << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> choice3;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						choice3 -= 1;

						if (choice3 != -2) {
							while (choice3 >= casinos.size() || choice3 < 0) {
								std::cout << "Choose correct casino number (write \"-1\" to exit): " << std::endl;
								for (int i = 0; i < casinos.size(); i++)
									std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
								std::cout << "-> ";
								std::cin >> choice3;
								std::cin.clear();//clears state of cin
								std::cin.ignore(INT_MAX, '\n'); // this clears console
								choice3 -= 1;
								if (choice3 != -2) {
									casinos.erase(casinos.begin() + choice3);
									std::cout << "\nCasino deleted successfully!" << std::endl;
								}
								else {
									break;

								}

							}



						}



					}

					else if (choice == 3) {
						int index;
						std::cout << "Which Casino would you like to edit?" << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						changeCasinoData(index - 1);


					}

					else if (choice == 4) {
						int index = 0;
						std::cout << "Which Casino would you like to view?" << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						while (index > casinos.size() || index < 0) {
							std::cout << "Choose correct casino number: " << std::endl;
							for (int i = 0; i < casinos.size(); i++)
								std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> index;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
						}
						casinos.at(index - 1).Display();
					}

					else if (choice == 5) {

						std::cout << "Chose sort option!\n";
						std::cout << "1. By name\n";
						std::cout << "2. By balance\n";
						std::cout << "3. By sqm\n";
						std::cout << "4. By floors\n";
						std::cout << "-> ";
						std::cin >> choice;

						if (choice == 1) {
							std::cout << "Sorted casinos by Name:\n";
							std::sort(casinos.begin(), casinos.end(), compareCasinosByName);
							for (auto& casino : casinos) {
								std::cout << casino.GetName() << ": " << casino.GetBalance() << "\n";
							}
						}

						else if (choice == 2) {
							std::cout << "Sorted casinos by Balance:\n";
							std::sort(casinos.begin(), casinos.end(), compareCasinosByBalance);
							for (auto& casino : casinos) {
								std::cout << casino.GetName() << ": " << casino.GetBalance() << "\n";
							}
						}

						else if (choice == 3) {
							std::cout << "Sorted casinos by Sqm:\n";
							std::sort(casinos.begin(), casinos.end(), compareCasinosBySqm);
							for (auto& casino : casinos) {
								std::cout << casino.GetName() << ": " << casino.GetSqm() << "\n";
							}
						}

						else if (choice == 4) {
							std::cout << "Sorted casinos by Floors:\n";
							std::sort(casinos.begin(), casinos.end(), compareCasinosByFloor);
							for (auto& casino : casinos) {
								std::cout << casino.GetName() << ": " << casino.GetFloors() << "\n";
							}
						}

						else {
							break;
						}
					}
					else {
						std::cout << "Choose correct option: ";
					}


				}

				else if (choice == 2) {
					std::cout << "1. Create Arcade\n2. Delete Arcade\n3. Change Arcade data\n4. Sort Arcade\n5. Find Arcade \n-> ";
					std::cin >> choice;
					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console

					if (choice == 1) {
						int Casinonum;

						std::cout << "In which Casino would you like to put arcade?: " << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> Casinonum;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						Casinonum -= 1;

						while (Casinonum >= casinos.size() || Casinonum < 0) {
							std::cout << "Choose correct casino number: , -1 to exit" << std::endl;
							for (int i = 0; i < casinos.size(); i++)
								std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> Casinonum;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							if (Casinonum == -1) {
								break;
							}
							Casinonum -= 1;
						}


						if (Casinonum != -1) {
							std::string Arcadename = "";
							while (inputwithoutsemi(Arcadename)) {
								std::cout << "Enter Arcade name: ";
								std::cin >> Arcadename;
							}

							double rent, price;
							std::cout << "Enter Arcade price: ";
							std::cin >> price;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							while (price < 1) {
								std::cout << "Enter correct price (>0): ";
								std::cin >> price;

								std::cin.clear();//clears state of cin
								std::cin.ignore(INT_MAX, '\n'); // this clears console
							}
							std::cout << "Enter Arcade rent: ";
							std::cin >> rent;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							while (rent < 1) {
								std::cout << "Enter correct rent (>0): ";
								std::cin >> rent;

								std::cin.clear();//clears state of cin
								std::cin.ignore(INT_MAX, '\n'); // this clears console
							}

							std::string type = "";
							while (inputwithoutsemi(type)) {
								std::cout << "Enter Arcade type: ";
								std::cin >> type;
							}


							casinos.at(Casinonum).CreateArcade(Arcadename, price, rent, type);
							casinocreatedcount++;
						}

						
					}

					else if (choice == 2) {
						int index;
						std::cout << "From which Casino would you like to delete arcade: " << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						index -= 1;

						while (index >= casinos.size() || index < 0) {
							std::cout << "Choose correct casino number: " << std::endl;
							for (int i = 0; i < casinos.size(); i++)
								std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> index;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							index -= 1;
						}
						int index2 = -10;

						while (index2 >= casinos.at(index).GetArcadesSize() || index2 < 0) {
							std::cout << "\n";
							std::cout << "Choose arcade to delete: " << std::endl;
							casinos.at(index).DisplayArcades();
							std::cout << "-> ";
							std::cin >> index2;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							index2 -= 1;


						}
						casinos.at(index).DeleteArcade(index2);

					}

					else if (choice == 3) {
						int index;
						std::cout << "From which Casino would you like to change arcade data: " << std::endl;
						for (int i = 0; i < casinos.size(); i++)
							std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						index -= 1;

						while (index >= casinos.size() || index < 0) {
							std::cout << "Choose correct casino number: , -1 to exit" << std::endl;
							for (int i = 0; i < casinos.size(); i++)
								std::cout << i + 1 << ". " << casinos.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> index;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							if (index == -1) {
								break;
							}
							index -= 1;
						}

						if (index != -1) {
							int index2 = -10;

							while (index2 >= casinos.at(index).GetArcadesSize() || index2 < 0) {
								std::cout << "\n";
								std::cout << "Choose arcade to change data: " << std::endl;
								casinos.at(index).DisplayArcades();
								std::cout << "-> ";
								std::cin >> index2;
								std::cin.clear();//clears state of cin
								std::cin.ignore(INT_MAX, '\n'); // this clears console
								index2 -= 1;



							}

							ChangeArcadeData(index2, index);
						}
						
					}

					else if (choice == 4) {
						std::vector<Arcade> globalvec;

						for (int i = 0; i < casinos.size(); i++) {
							for (int y = 0; y < casinos.at(i).GetArcades().size(); y++) {
								globalvec.push_back(casinos.at(i).GetArcades().at(y));
							}
						}




						
						std::cout << "Chose sort option!\n";
						std::cout << "1. By name\n";
						std::cout << "2. By price\n";
						std::cout << "3. By rent\n";
						std::cout << "4. By type\n";
						std::cout << "-> ";
						std::cin >> choice;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						

						if (choice == 1) {
							std::cout << "Sorted arcades by Name:\n";
							std::sort(globalvec.begin(), globalvec.end(), compareArcadesByName);
							for (auto& arcade : globalvec) {
								std::cout << arcade.GetName() << "\n";
							}
						}

						else if (choice == 2) {
							std::cout << "Sorted arcades by Price:\n";
							std::sort(globalvec.begin(), globalvec.end(), compareArcadesByPrice);
							for (auto& arcade : globalvec) {
								std::cout << arcade.GetName() << ": " << arcade.GetPrice() << "\n";
							}
						}

						else if (choice == 3) {
							std::cout << "Sorted arcades by Rent:\n";
							std::sort(globalvec.begin(), globalvec.end(), compareArcadesByRent);
							for (auto& arcade : globalvec) {
								std::cout << arcade.GetName() << ": " << arcade.GetRent() << "\n";
							}
						}

						else if (choice == 4) {
							std::cout << "Sorted arcades by Type:\n";
							std::sort(globalvec.begin(), globalvec.end(), compareArcadesByType);
							for (auto& arcade : globalvec) {
								std::cout << arcade.GetName() << ": " << arcade.GetType() << "\n";
							}
						}
						
					}
					else if (choice == 5) {
						std::vector<Arcade> globalvec;

						for (int i = 0; i < casinos.size(); i++) {
							for (int y = 0; y < casinos.at(i).GetArcades().size(); y++) {
								globalvec.push_back(casinos.at(i).GetArcades().at(y));
							}
						}


						int index = -10;

						std::cout << globalvec.size() << std::endl;

						while (index >= globalvec.size() || index <= 0) {
							std::cout << "Which Arcade would you like to view?, -1 to exit" << std::endl;
							for (int i = 0; i < globalvec.size(); i++)
								std::cout << i + 1 << ". " << globalvec.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> index;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
							if (index == -1) {
								break;
							}
							index--;
						}
						if (index != -1) {
							globalvec.at(index).Display();

						}

					}
				}

				else if (choice == 3) {
					std::cout << "\n1. Delete user\n";
					std::cout << "2. Change user data\n";
					std::cout << "3. Search users\n";
					std::cout << "4. Sort users\n";
					std::cout << "5. Exit\n";
					std::cout << "-> ";
					std::cin >> choice;
					std::cout << "\n";

					if (choice == 1) {
						int index;
						std::cout << "Which user would you like to delete?" << std::endl;
						for (int i = 0; i < customers.size(); i++)
							std::cout << i + 1 << ". " << customers.at(i).GetUsername() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						deleteUser(index - 1);

					}
					else if (choice == 2) {
						int index;
						std::cout << "Which user would you like to edit?" << std::endl;
						for (int i = 0; i < customers.size(); i++)
							std::cout << i + 1 << ". " << customers.at(i).GetUsername() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console
						changeUserData(index - 1);

					}
					else if (choice == 3) {
						int index = 0;
						std::cout << "Which User would you like to view?" << std::endl;
						for (int i = 0; i < customers.size(); i++)
							std::cout << i + 1 << ". " << customers.at(i).GetName() << std::endl;
						std::cout << "-> ";
						std::cin >> index;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						while (index > customers.size() || index < 0) {
							std::cout << "Choose correct User number: " << std::endl;
							for (int i = 0; i < customers.size(); i++)
								std::cout << i + 1 << ". " << customers.at(i).GetName() << std::endl;
							std::cout << "-> ";
							std::cin >> index;
							std::cin.clear();//clears state of cin
							std::cin.ignore(INT_MAX, '\n'); // this clears console
						}
						customers.at(index - 1).Display();

					}
					else if (choice == 4) {
						std::cout << "Chose sort option!\n";
						std::cout << "1. By name\n";
						std::cout << "2. By balance\n";
						std::cout << "3. By age\n";
						std::cout << "-> ";
						std::cin >> choice;
						std::cin.clear();//clears state of cin
						std::cin.ignore(INT_MAX, '\n'); // this clears console

						if (choice == 1) {
							std::cout << "Sorted users by Name:\n";
							std::sort(customers.begin(), customers.end(), compareUsersByName);
							for (auto& customer : customers) {
								std::cout << customer.GetName() << ": " << customer.GetBalance() << "\n";
							}
						}

						else if (choice == 2) {
							std::cout << "Sorted users by Balance:\n";
							std::sort(customers.begin(), customers.end(), compareUsersByBalance);
							for (auto& customer : customers) {
								std::cout << customer.GetUsername() << ": " << customer.GetBalance() << "\n";
							}
						}

						else if (choice == 3) {
							std::cout << "Sorted users by Age:\n";
							std::sort(customers.begin(), customers.end(), compareUsersByAge);
							for (auto& customer : customers) {
								std::cout << customer.GetUsername() << ": " << customer.GetAge() << "\n";
							}
						}
						else {
							break;
						}

					}
					else if (choice == 5) {
						break;
					}
					else {
						std::cout << "Choose correct option: ";
					}
				}
				else if (choice == 4) {
					break;
				}
				else {
					std::cout << "\nChoice correct option: ";
				}


			}

			else if (choice == 2) {
				me = -1;
				izvade();
				writeToArcade(); // writting to file
				writeToCasino();
				writeToCustomers();
			}
			else {
				std::cout << "\nChoose correct option: ";

			}

		}
		if (doublebreak) {
			doublebreak = false;
			break;
		}

	}

	writeToArcade(); // writting to file
	writeToCasino();
	writeToCustomers();

	std::cout << std::endl;

	std::cout << "win: " << wincount << " money amount: " << winbetcount << " lose: " << losecount << " lose amount: " << losebetcount << " users registed: " << userregistedcount << " casino created: " << casinocreatedcount << " arcade created: " << arcadecreatedcount;

	return 0;
}


void izvade() {
	system("CLS");
	std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
	if (me > -1) {
		std::cout << "User: " << customers.at(me).GetUsername() << " | Balance: " << customers.at(me).GetBalance() << "$\n";
	}
	else {
		std::cout << "User: - | Balance: - \n";
	}
}

void registerUser(string username, string password, string name, string surname, int age, string email, string phone) {
	bool parbaude = false;
	for (int i = 0; i < customers.size(); i++) {
		if (username == customers.at(i).GetUsername()) {
			parbaude = true;
			std::cout << "\n";
			std::cout << "\nUser already exsist!";
		}
	}
	if (parbaude) {
	}
	else {
		Customer registred(100, username, password, name, surname, age, email, phone);
		customers.push_back(registred);
		ofstream outfile("users.txt", ios::app);
		outfile << username << ":" << password << ":" << 100 << ":" << name << ":" << surname << ":" << age << ":" << email << ":" << phone << endl;
		outfile.close();
		std::cout << "\n";
		std::cout << "\nThank you for registration in our Casino!";
		userregistedcount++;
	}
}

int checkUser(string username, string password) {
	for (int i = 0; i < customers.size(); i++) {
		if (username == customers.at(i).GetUsername() && customers.at(i).GetPass() == password) {
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

		std::string username = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string password = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		string balance = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string surname = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string age = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string email = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string phone = line;


		Customer info(stoi(balance), username, password, name, surname, stoi(age), email, phone);
		customers.push_back(info);
	}

	file.close();
}

void ReadCasino()
{
	std::ifstream file("casino.txt");

	std::string line;

	while (std::getline(file, line)) {


		std::string delimiter = ":";

		std::string name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string balance = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		string adress = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string floors = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string sqm = line;


		Casino info(stoi(balance), name, adress, stoi(floors), stod(sqm));
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
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string price = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string rent = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());

		std::string type = line.substr(0, line.find(delimiter));

		for (int i = 0; i < casinos.size(); i++) {
			if (casinoname == casinos.at(i).GetName()) {
				casinos.at(i).CreateArcade(name, stod(price), stod(rent), type);
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
			file1 << casinos.at(i).GetArcade(y).GetName() << ":" << casinos.at(i).GetArcade(y).GetCasinoName() << ":" << casinos.at(i).GetArcade(y).GetPrice() << ":" << casinos.at(i).GetArcade(y).GetRent() << ":" << casinos.at(i).GetArcade(y).GetType() << std::endl;
		}
	}

	file1.close();
}

void writeToCasino() {
	std::ofstream file("casino.txt", std::ios::trunc);
	file.close();
	std::ofstream file1("casino.txt");

	for (int i = 0; i < casinos.size(); i++) {
		file1 << casinos.at(i).GetName() << ":" << casinos.at(i).GetBalance() << ":" << casinos.at(i).GetAdress() << ":" << casinos.at(i).GetFloors() << ":" << casinos.at(i).GetSqm() << std::endl;
	}

	file1.close();
}

void writeToCustomers() {
	std::ofstream file("users.txt", std::ios::trunc); // "std::ios::trunc" - file clear
	std::ofstream file1("users.txt");

	for (int i = 0; i < customers.size(); i++) {
		file1 << customers.at(i).GetUsername() << ":" << customers.at(i).GetPass() << ":" << customers.at(i).GetBalance() << ":" << customers.at(i).GetName() << ":" << customers.at(i).GetSurname() << ":" << customers.at(i).GetAge() << ":" << customers.at(i).GetEmail() << ":" << customers.at(i).GetPhone() << std::endl;
	}

	file1.close();
}

void deleteUser(int index)
{
	if (index >= 0 && index < customers.size()) {
		customers.erase(customers.begin() + index);
		writeToCustomers();
		std::cout << "\nUser deleted successfully.\n";
	}
	else {
		std::cout << "\nInvalid user index.\n";
	}
}

void changeUserData(int index)
{
	if (index >= 0 && index < customers.size()) {

		std::cout << "\nCurrent user data!\n";
		std::cout << "Name: " << customers.at(index).GetName() << "\n";
		std::cout << "Surname: " << customers.at(index).GetSurname() << "\n";
		std::cout << "Age: " << customers.at(index).GetAge() << "\n";
		std::cout << "Email: " << customers.at(index).GetEmail() << "\n";
		std::cout << "Phone: " << customers.at(index).GetPhone() << "\n";
		std::cout << "Username: " << customers.at(index).GetUsername() << "\n";
		std::cout << "Balance: " << customers.at(index).GetBalance() << "\n";

		std::cout << "\nEnter new data!\n";
		std::cout << "What would you like to edit?";
		std::cout << "\n1. Name\n2. Surname\n3. Age\n4. Email\n5. Phone number\n6. Username\n7. Balance";
		std::cout << "\n-> ";
		std::cin >> choice;

		string name;
		string surname;
		int age;
		string email;
		string phone;
		string username;
		int balance;

		while (true) {
			switch (choice) {
			case 1:
				while (inputwithoutsemi(name)) {
					std::cout << "New name: ";
					std::cin >> name;
				}

				customers.at(index).SetName(name);
				doublebreak = true;
				break;
			case 2:
				while (inputwithoutsemi(surname)) {
					std::cout << "New surname: ";
					std::cin >> surname;
				}

				customers.at(index).SetSurname(surname);
				doublebreak = true;
				break;
			case 3:
				std::cout << "New age: ";
				std::cin >> age;
				customers.at(index).SetAge(age);
				doublebreak = true;
				break;
			case 4:
				while (isPhoneNumberValid(email) != true && inputwithoutsemi(email)) {
					std::cout << "New email: ";
					std::cin >> email;
				}

				customers.at(index).SetEmail(email);
				doublebreak = true;
				break;
			case 5:
				while (isPhoneNumberValid(phone) != true && inputwithoutsemi(phone)) {
					std::cout << "New phone: ";
					std::cin >> phone;
				}

				customers.at(index).SetPhone(phone);
				doublebreak = true;
				break;
			case 6:
				while (inputwithoutsemi(username)) {
					std::cout << "New username: ";
					std::cin >> username;
				}

				customers.at(index).SetUsername(username);
				doublebreak = true;
				break;
			case 7:
				std::cout << "New balance: ";
				std::cin >> balance;
				customers.at(index).SetBalance(balance);
				doublebreak = true;
				break;
			default:
				std::cout << "Enter correct number!";
				break;
			}
			if (doublebreak) {
				doublebreak = false;
				break;
			}
		}

		std::cout << "\nCurrent user data!\n";
		std::cout << "Name: " << customers.at(index).GetName() << "\n";
		std::cout << "Surname: " << customers.at(index).GetSurname() << "\n";
		std::cout << "Age: " << customers.at(index).GetAge() << "\n";
		std::cout << "Email: " << customers.at(index).GetEmail() << "\n";
		std::cout << "Phone: " << customers.at(index).GetPhone() << "\n";
		std::cout << "Username: " << customers.at(index).GetUsername() << "\n";
		std::cout << "Balance: " << customers.at(index).GetBalance() << "\n";

		writeToCustomers();
		std::cout << "\nUser data changed successfully.\n";
	}
	else {
		std::cout << "\nInvalid user index.\n";
	}
}

void changeCasinoData(int index)
{
	if (index >= 0 && index < casinos.size()) {


		std::cout << "\nCurrent casino data!\n";
		std::cout << "Name: " << casinos.at(index).GetName() << "\n";
		std::cout << "Balance: " << casinos.at(index).GetBalance() << "\n";
		std::cout << "Adress: " << casinos.at(index).GetAdress() << "\n";
		std::cout << "Floors: " << casinos.at(index).GetFloors() << "\n";
		std::cout << "Area: " << casinos.at(index).GetSqm() << "m^2\n";


		std::cout << "\nEnter new data!\n";
		std::cout << "What would you like to edit?";
		std::cout << "\n1. Name\n2. Balance\n3. Adress\n4. Floors\n5. Area";
		std::cout << "\n-> ";
		std::cin >> choice;

		string name;
		string adress = "";
		int floors;
		double sqm;
		int balance;
		std::string line1;

		while (true) {
			switch (choice) {
			case 1:
				while (inputwithoutsemi(name)) {
					std::cout << "New name: ";
					std::cin >> name;
				}

				casinos.at(index).SetName(name);
				doublebreak = true;
				break;
			case 2:
				std::cout << "New balance: ";
				std::cin >> balance;
				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console

				while (balance <= 0) {
					std::cout << "Enter correct balance (>0): ";
					std::cin >> balance;

					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console
				}


				casinos.at(index).SetBalance(balance);

				doublebreak = true;
				break;
			case 3:

				std::getline(std::cin, line1);
				while (adress.length() < 5 || inputwithoutsemi(adress)) {
					std::cout << "New adress: ";
					std::getline(std::cin, adress);
				}
				casinos.at(index).SetAdress(adress);

				doublebreak = true;
				break;
			case 4:
				std::cout << "New count of floors: ";
				std::cin >> floors;
				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console
				while (floors < 1) {
					std::cout << "Enter correct floors (>0): ";
					std::cin >> floors;

					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console
				}
				casinos.at(index).SetFloors(floors);
				doublebreak = true;
				break;
			case 5:

				std::cout << "New area(m^2): ";
				std::cin >> sqm;
				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console

				while (sqm <= 0.0) {
					std::cout << "Enter correct area (>0): ";
					std::cin >> sqm;

					std::cin.clear();//clears state of cin
					std::cin.ignore(INT_MAX, '\n'); // this clears console
				}
				casinos.at(index).SetSqm(sqm);
				doublebreak = true;
				break;
			default:
				std::cout << "Enter correct number!";
				break;
			}
			if (doublebreak) {
				doublebreak = false;
				break;
			}
		}

		std::cout << "\nCurrent casino data!\n";
		std::cout << "Name: " << casinos.at(index).GetName() << "\n";
		std::cout << "Balance: " << casinos.at(index).GetBalance() << "\n";
		std::cout << "Adress: " << casinos.at(index).GetAdress() << "\n";
		std::cout << "Floors: " << casinos.at(index).GetFloors() << "\n";
		std::cout << "Sqm: " << casinos.at(index).GetSqm() << "m^2\n";

		writeToCasino();
		std::cout << std::endl;
		std::cout << "\nCasino data changed successfully.\n";
	}
	else {
		std::cout << "\nInvalid Casino index.\n";
	}
}

void ChangeArcadeData(int indexA, int indexC) {

	std::cout << "\nCurrent Arcade data!\n";
	std::cout << "Name: " << casinos.at(indexC).GetArcade(indexA).GetName() << "\n";
	std::cout << "Price: " << casinos.at(indexC).GetArcade(indexA).GetPrice() << "\n";
	std::cout << "Rent: " << casinos.at(indexC).GetArcade(indexA).GetRent() << "\n";
	std::cout << "Type: " << casinos.at(indexC).GetArcade(indexA).GetType() << "\n";


	std::cout << "\nEnter new data!\n";
	std::cout << "What would you like to edit?";
	std::cout << "\n1. Name\n2. Price\n3. Rent\n4. Type";
	std::cout << "\n-> ";
	std::cin >> choice;

	string name, type;
	double price, rent;

	while (true) {
		switch (choice) {
		case 1:
			while (inputwithoutsemi(name)) {
				std::cout << "New name: ";
				std::cin >> name;
			}

			casinos.at(indexC).SetArcadeName(indexA, name);
			doublebreak = true;
			break;
		case 2:
			std::cout << "New Price: ";
			std::cin >> price;
			std::cin.clear();//clears state of cin
			std::cin.ignore(INT_MAX, '\n'); // this clears console

			while (price <= 0) {
				std::cout << "Enter correct price (>0): ";
				std::cin >> price;

				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console
			}


			casinos.at(indexC).SetArcadePrice(indexA, price);

			doublebreak = true;
			break;
		case 3:
			std::cout << "New Rent: ";
			std::cin >> rent;
			std::cin.clear();//clears state of cin
			std::cin.ignore(INT_MAX, '\n'); // this clears console

			while (rent <= 0) {
				std::cout << "Enter correct Rent (>0): ";
				std::cin >> rent;

				std::cin.clear();//clears state of cin
				std::cin.ignore(INT_MAX, '\n'); // this clears console
			}


			casinos.at(indexC).SetArcadeRent(indexA, rent);

			doublebreak = true;
			break;
		case 4:
			while (inputwithoutsemi(type)) {
				std::cout << "New type: ";
				std::cin >> type;
			}

			casinos.at(indexC).SetArcadeType(indexA, type);
			doublebreak = true;
			break;
		default:
			std::cout << "Enter correct number!";
			break;
		}
		if (doublebreak) {
			doublebreak = false;
			break;
		}
	}

	std::cout << "\nCurrent Arcade data!\n";
	std::cout << "Name: " << casinos.at(indexC).GetArcade(indexA).GetName() << "\n";
	std::cout << "Price: " << casinos.at(indexC).GetArcade(indexA).GetPrice() << "\n";
	std::cout << "Rent: " << casinos.at(indexC).GetArcade(indexA).GetRent() << "\n";
	std::cout << "Type: " << casinos.at(indexC).GetArcade(indexA).GetType() << "\n";

	writeToArcade();
	std::cout << std::endl;
	std::cout << "\Arcade data changed successfully.\n";
}


bool inputwithoutsemi(std::string stri) {

	if (strstr(stri.c_str(), ":") || stri.empty()) {
		return true;
	}
	else {
		return false;
	}
}