#include "pch.h"
#include "StudentGroup.h"

bool StudentGroup::StudentSearch(const Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
		if (*it == student)
			return true;

	return false;
}

Student* StudentGroup::getStudent(const string& t_firstname, const string& t_lastname, const string& t_patronymic)
{
	for (auto& i : students)
		if ((i->getFirstName() == t_firstname) && (i->getLastName() == t_lastname) && (i->getPatronymic() == t_patronymic))
			return i;
	std::cout << "������� " << t_firstname << " " << t_lastname << " " << t_patronymic << "\n";
	return nullptr;
}

const size_t & StudentGroup::getStudentsCount()
{
	return students.size();
}

const string & StudentGroup::getNameGroup()
{
	return namegroup;
}

const int StudentGroup::getMinAge()
{
	return minAge;
}

const double StudentGroup::getMinAverageScore()
{
	return minAverageScore;
}

void StudentGroup::setMinAge(const int& t_minAge)
{
	minAge = t_minAge;
}

void StudentGroup::setMinAverageScore(const double& t_minAverageScore)
{
	minAverageScore = t_minAverageScore;
}

void StudentGroup::addStudent(Student* student)
{
	if (students.size() >= MaximumStudents)
	{
		std::cout << "���������� �������� �������� " << student->getLastName() <<  " � ������ ��� ��� ��� ��������� \n";
		return;
	}

	if (StudentSearch(student))
	{
		std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ��� ��������� � ������\n";
		return;
	}

	if (minAge != 0)
	{
		if (minAge > student->getAge())
		{
			return;
		}
	}

	if (minAverageScore != 0.0)
	{
		if (minAverageScore > student->getAverageScore())
		{
			return;
		}
	}

	student->increaseGroupJoins();
	students.push_back(student);
	std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
	std::cout << "�������� � ������ " << namegroup << "\n";
}

void StudentGroup::removeStudent(Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == student)
		{
			student->decreaseGroupJoins();
			students.erase(it);
			std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " ";
			std::cout << "������ �� ������ " << namegroup << "\n";
			return;
		}
	}
	std::cout << "������� " << student->getLastName() << " " << student->getFirstName() << " " << student->getPatronymic() << " �� �������� ������ ���� ������ \n";
}

void StudentGroup::LexSort()
{
	std::cout << " ������ " << namegroup << " ������������� �� ������� \n";
	std::sort(students.begin(), students.end(), [](Student* student1, Student* student2)
	{
		return student1->getLastName() < student2->getLastName();
	});
}

void StudentGroup::sortAverageScore()
{
	std::cout << " ������ " << namegroup << " ������������� �� �������� ����� ��������� \n";
	std::sort(students.begin(), students.end(), [](Student* student1, Student* student2)
	{
		return student1->getAverageScore() > student2->getAverageScore();
	});
}

void StudentGroup::Check()
{
	for (auto i : students)
	{
		if (i->getAge() < getMinAge())
		{
			std::cout << "������� " << i->getLastName() << " ��� �������� �� ������, ��-�� ���������� ��������\n";
			removeStudentCheck(i);
		}

		if (i->getAverageScore() < getMinAverageScore())
		{
			std::cout << "������� " << i->getLastName() << " ��� �������� �� ������, ��-�� ������� �������� ����� \n";
			removeStudentCheck(i);
		}
	}
}

void StudentGroup::removeStudentCheck(Student* student)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == student)
		{
			student->decreaseGroupJoins();
			students.erase(it);
			return;
		}
	}
	
}

void StudentGroup::outputGroup()
{
	std::cout << "\n������ ��������� ������ " << namegroup << ": \n";
	for (auto& i : students)
	{
		std::cout << i->getLastName() << " " << i->getFirstName() << " " << i->getPatronymic() << " ";
		std::cout << " - " << i->getAge() << " ���, " << " ������� ����: " << i->getAverageScore() << " \n";

	}
	std::cout << "\n";
}
