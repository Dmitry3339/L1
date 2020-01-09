#include "pch.h"
#include "Student.h"


const string& Student::getFirstName()
{
	return firstname;
}

const string& Student::getLastName()
{
	return lastname;
}

const string& Student::getPatronymic()
{
	return patronymic;
}

const int Student::getAge()
{
	return age;
}

const double & Student::getAverageScore()
{
	return averagescore;
}

void Student::setFirstName(const string& t_firstname)
{
	firstname = t_firstname;
}

void Student::setLastName(const string& t_lastname)
{
	lastname = t_lastname;
}

void Student::setPatronymic(const string& t_patronymic)
{
	patronymic = t_patronymic;
}

void Student::setAge(const unsigned int& t_age)
{
	age = t_age;
}

void Student::setAverageScore(const double & t_averagescore)
{
	averagescore = t_averagescore;
}

void Student::increaseGroupJoins()
{
	groupJoins++;
}

void Student::decreaseGroupJoins()
{
	groupJoins--;
}

void Student::InformStudent()
{
	std::cout << "\n ���������� � ��������: " << lastname << " " << firstname << " " << patronymic << " " << std::endl;
	std::cout << "�������: " << age << " ���"  << std::endl;
	std::cout << "�������� � " << groupJoins << " �������. " << std::endl;
	std::cout.precision(5);
	std::cout << "������� ����: " << getAverageScore() << std::endl;
	std::cout << "\n";
}