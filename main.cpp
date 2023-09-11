#include <iostream>
#include <cstring>
#include "StudentBook.h"
using namespace std;

struct Student
{
    char name[40];
    char surname[40];
    double salary;
    char number[40];
};

const int MAX_STUDENTS = 35;  // Максимальное количество студентов
Student students[MAX_STUDENTS]; // Массив студентов
int studentCount = 0;           // Текущее количество студентов

void showAllStudents()
{
    if (studentCount == 0) {
        cout << "There are no students in the book." << endl;
        return;
    }

    cout << "Students:" << endl;
    for (int i = 0; i < studentCount; i++) {
        const Student& student = students[i];
        cout << "Student #" << i << endl;
        cout << "Name: " << student.name << "\tSurname: " << student.surname << "\tSalary: " << student.salary << "\tNumber: " << student.number << endl;
        cout << "-----------------------" << endl;
    }
}

int main()
{
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Show all students" << endl;
        cout << "2. Add student" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Select a menu option: ";
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3: ";
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
        case 1:
            showAllStudents();
            break;
        case 2: {
            if (studentCount < MAX_STUDENTS) {
                Student& student = students[studentCount];
                cout << "Enter name -> ";
                cin >> student.name;
                cout << "Enter surname -> ";
                cin >> student.surname;
                cout << "Enter salary -> ";
                cin >> student.salary;
                cout << "Enter number -> ";
                cin >> student.number;
                studentCount++;
                cout << "Student successfully added." << endl;
            } else {
                cout << "The student book is filled." << endl;
            }
            break;
        }
        case 3:
            return 0;  // Выход из программы
        }
    }

    return 0;
}
