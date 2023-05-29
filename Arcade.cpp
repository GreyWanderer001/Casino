#include <iostream>
#include<cstdlib>
#include "Customer.h"
#include "Casino.h"

Arcade::Arcade(std::string name, Casino* casino, double price, double rent, std::string type) {
    this->GameName = name;
    this->casino = casino;
    this->price = price;
    this->rent = rent;
    this->type = type;
}

void Arcade::Display() {
    std::cout << this->GameName << " " << this->price << " " << this->rent << " " << this->type << " Parent casino: " << this->casino->GetName() << std::endl;
}

int Arcade::Play(Customer& customer, int bid) {
    if (bid > this->casino->GetBalance()) {
        std::cout << "\nCasino dont have this amount of money!\n" << std::endl;
    }
    else {
        if (customer.GetBalance() < bid) {
            std::cout << "\nInsufficient funds\n" << std::endl;
        }
        else {
            srand(time(NULL));
            int random = rand() % 2 + 1;
            if (random == 1) {
                customer.ChangeBalance(-bid);
                this->casino->ChangeBalance(bid);
                system("CLS");
                std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
                std::cout << "User: " << customer.GetUsername() << " | Balance: " << customer.GetBalance() << "$\n";
                std::cout << "\n";
                std::cout << "You lose";
                return -bid;
            }
            else {
                customer.ChangeBalance(bid);
                this->casino->ChangeBalance(-bid);
                system("CLS");
                std::cout << "$$$-----| Welcome to Casino R&D |-----$$$\n";
                std::cout << "User: " << customer.GetUsername() << " | Balance: " << customer.GetBalance() << "$\n";
                std::cout << "\n";
                std::cout << "You won";
                return bid;
            }



        }
    }

}

std::string Arcade::GetName() {
    return this->GameName;
}

std::string Arcade::GetCasinoName() {
    return this->casino->GetName();
}

double Arcade::GetPrice() {
    return this->price;
}

double Arcade::GetRent() {
    return this->rent;
}

std::string Arcade::GetType() {
    return this->type;
}

void Arcade::SetName(std::string newVar) {
    this->GameName = newVar;

}
void Arcade::SetRent(double newVar) {
    this->price = newVar;

}
void Arcade::SetPrice(double newVar) {
    this->rent = newVar;

}
void Arcade::SetType(std::string newVar) {
    this->type = newVar;

}