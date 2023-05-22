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
	std::string adress;
	int floors;
	double sqm;


public:
	Casino(int balance, std::string name, std::string adress, int floors, double sqm);
	void Display();
	void CreateArcade(std::string name);
	Arcade GetArcade(int index);
	Arcade GetArcadeByName(std::string name);
	void ChangeBalance(int newbalance);
	int GetBalance();
	void DisplayArcades();
	int GetArcadesSize();
	std::string GetName();
	std::string GetAdress();
	int GetFloors();
	double GetSqm();

	void SetName(std::string newVar);
	void SetAdress(std::string newVar);
	void SetFloors(int newVar);
	void SetSqm(double newVar);
	void SetBalance(int newVar);




};
#endif
