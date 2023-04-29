#pragma once
#include <string>
#include "Arcade.h"
#include <vector>
#ifndef Casino_H
#define Casino_H


class Arcade;

class Casino
{
private:
	int balance = 0;
	std::string name = "";
	std::vector<Arcade> arcades;


public:
	Casino(int balance, std::string name);
	void Display();
	void CreateArcade(std::string name);
	Arcade GetArcade(int index);
	Arcade GetArcadeByName(std::string name);
	void ChangeBalance(int newbalance);
	int GetBalance();
	void DisplayArcades();
	int GetArcadesSize();
	std::string GetName();



};
#endif
