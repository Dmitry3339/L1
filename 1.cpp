// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "studentgroup.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Student* abramovich = new Student("Вадим", "Абрамович", "Иванович", 18, 4.3);
	Student* zuyev = new Student("Никита", "Зуев", "Сергеевич", 22, 3.9);
	Student* romanov = new Student("Василий", "Романов", "Алексеевич", 17, 3.3);
	Student* dudnik = new Student("Борис", "Дудник", "Петрович", 16, 4);
	Student* sutulin = new Student("Афанасий", "Сутулин", "Александрович", 19, 4.5);
	Student* shatalov = new Student("Генадий", "Шаталов", "Николаевич", 17, 3.6);
	Student* korolyov = new Student("Гавриил", "Королев", "Михайлович", 25, 5);
	Student* astakhov = new Student("Глеб", "Астахов", "Георгиевич", 18, 3.7);

	StudentGroup* math = new StudentGroup(" Математика ", 17, 3.8);
	StudentGroup* inform = new StudentGroup(" Информатика ", 17, 3.5);
	

	math->addStudent(zuyev);
	math->addStudent(dudnik);
	math->addStudent(abramovich);
	math->addStudent(sutulin);
	math->addStudent(astakhov);

	inform->addStudent(korolyov);
	inform->addStudent(romanov);
	inform->addStudent(shatalov);
	inform->addStudent(abramovich);
	inform->addStudent(astakhov);

	abramovich->InformStudent();

	math->outputGroup();
	inform->outputGroup();

	math->LexSort();
	math->outputGroup();

	inform->sortAverageScore();
	inform->outputGroup();

	inform->removeStudent(abramovich);
	inform->outputGroup();

	math->setMinAverageScore(4.0);
	math->Check();

	math->outputGroup();

	delete abramovich, zuyev, romanov, dudnik, sutulin, shatalov, korolyov, astakhov;
	delete math, inform;

	cin.get();
}