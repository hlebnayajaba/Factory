#pragma once
#include <iostream>
#include <string>
#include "Project.h"
using namespace std;
class Employee
{
protected:
	int id;
	string name;
	int age;
	int worktime;
	float payment;
public:
	void SetWorkTime();
	virtual void calc() = 0;
	virtual void printInfo() = 0;
};

class ProjectManager : public Employee
{
protected:
	Project projects[1];
public:
	void calc() override;
	int calcHeads();
};


class SeniorManager : public ProjectManager
{
	Project projects[];
public:
	void calc() override;
};

class Personal : public Employee
{
protected:
	float salary;
public:
	int calcBase();
};


class Engineer: public Personal
{
protected:
	Project project;
public:
	int calcBudgetPart();
	void calc() override;
};

class Programmer : public Engineer
{
public:
	void calc() override;
	int CalcProAdditions();
};

class Tester : public Engineer
{
public:
	void calc() override;
	int CalcProAdditions();
};

class TeamLeader : public Programmer
{
public:
	int calcHeads();
	void calc() override;
};

class Cleaner : public Personal
{
public:
	void calc() override;
};

class Driver : public Personal
{
public:
	void calc() override;
	int CalcBonus();
};
