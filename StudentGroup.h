#pragma once
#include <vector>
#include "Student.h"

class StudentGroup
{
private:
	vector<Student*> students;
	string namegroup;
	int minAge = 0;
	double minAverageScore = 0.0;
	const int MaximumStudents = 20;
	bool StudentSearch(const Student* student);
public:
	StudentGroup() = delete;
	StudentGroup(const string& t_namegroup,  const int& t_minAge, const double& t_minAverageScore) :
		namegroup(t_namegroup),  minAge(t_minAge), minAverageScore (t_minAverageScore){}

	Student* getStudent(const string& t_firstname, const string& t_lastname, const string& t_patronymic);
	const size_t& getStudentsCount();
	const string& getNameGroup();
	const int getMinAge();
	const double getMinAverageScore();

	void setMinAge(const int& t_minAge);
	void setMinAverageScore(const double& t_minAverageScore);

	void addStudent(Student* student);
	void removeStudent(Student* student);
	void LexSort();
	void sortAverageScore();
	void Check();
	void removeStudentCheck(Student* student);
	void outputGroup();
};

