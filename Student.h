#pragma once
#include <iostream>
#include <string>
#include <array>

using namespace std;

class Student
{
private:
	string firstname;
	string lastname;
	string patronymic;
	double averagescore;
	unsigned int age = 0;
	unsigned int groupJoins = 0;

public:
	Student() = delete;
	Student(const string& t_firstname, const string& t_lastname, const string& t_patronymic, const unsigned int& t_age, const double& t_averagescore) :
		firstname(t_firstname), lastname(t_lastname), patronymic(t_patronymic), age(t_age), averagescore(t_averagescore) {}

	const string& getFirstName();
	const string& getLastName();
	const string& getPatronymic();
	const int getAge();
	const double& getAverageScore();

	void setFirstName(const string& t_firstName);
	void setLastName(const string& t_secondName);
	void setPatronymic(const string& t_middleName);
	void setAge(const unsigned int& t_age);
	void setAverageScore(const double& t_averagescore);

	void increaseGroupJoins();
	void decreaseGroupJoins();

	void InformStudent();
};

