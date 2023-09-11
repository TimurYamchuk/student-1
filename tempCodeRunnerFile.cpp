#include <iostream>
#include <fstream>
#include "StudentBook.h"
#ifndef STUDENTBOOK_H
#define STUDENTBOOK_H
using namespace std;

struct Student {
    string name;
    string surname;
    string number;
    double salary;
};

const int MAX_STUDENTS = 100;
vector<Student> students;

void FromFile(const char* fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "Error when opening a file." << endl;
        return;
    }

    students.clear();
    Student student;

    while (file >> student.name >> student.surname >> student.number >> student.salary) {
        students.push_back(student);
    }

    file.close();
    cout << "Students successfully loaded from file." << endl;
}

void saveStudentsToFile(const char* fileName) {
    ofstream file(fileName);
    if (!file) {
        cout << "Error when opening a file." << endl;
        return;
    }

    for (const Student& student : students) {
        file << student.name << '\t' << student.surname << '\t' << student.number << '\t' << student.salary << '\n';
    }

    file.close();
    cout << "Students successfully saved to file." << endl;
}

void showAllStudents() {
    if (students.empty()) {
        cout << "There are no students in the book." << endl;
        return;
    }

    cout << "Students:" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        const Student& student = students[i];
        cout << "Student #" << i << endl;
        cout << "Last name: " << student.surname << endl;
        cout << "First name: " << student.name << endl;
        cout << "Number: " << student.number << endl;
        cout << "Salary: " << student.salary << endl;
        cout << "-----------------------" << endl;
    }
}

void searchBySurname(const string& lastName) {
    bool found = false;

    cout << "Result:\n";
    for (const Student& student : students) {
        if (student.surname == lastName) {
            cout << "Last name: " << student.surname << endl;
            cout << "First name: " << student.name << endl;
            cout << "Number: " << student.number << endl;
            cout << "Salary: " << student.salary << endl;
            cout << "-----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student with surname '" << lastName << "' was not found." << endl;
    }
}

void searchStudentsBySalaryRange(double minSalary, double maxSalary) {
    bool found = false;

    cout << "Result:\n";
    for (const Student& student : students) {
        if (student.salary >= minSalary && student.salary <= maxSalary) {
            cout << "Last name: " << student.surname << endl;
            cout << "First name: " << student.name << endl;
            cout << "Number: " << student.number << endl;
            cout << "Salary: " << student.salary << endl;
            cout << "-----------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Students with salary in the given range are not found." << endl;
    }
}

void sortStudentsByLastName() {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.surname < b.surname;
    });

    cout << "Students sorted by last name." << endl;
}

void addStudents() {
    if (students.size() >= MAX_STUDENTS) {
        cout << "The students book is filled." << endl;
        return;
    }

    Student student;

    cout << "Enter last name of student: ";
    cin >> student.surname;

    cout << "Enter student's first name: ";
    cin >> student.name;

    cout << "Enter student's number: ";
    cin >> student.number;

    cout << "Enter the student's salary: ";
    cin >> student.salary;

    students.push_back(student);
    cout << "Student successfully added." << endl;
}

void deleteStudents() {
    if (students.empty()) {
        cout << "There are no students to delete." << endl;
        return;
    }

    cout << "Enter the last name of the student to delete: ";
    string lastName;
    cin >> lastName;

    bool found = false;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].surname == lastName) {
            students.erase(students.begin() + i);
            found = true;
            cout << "The student with the surname '" << lastName << "' has been successfully deleted." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with surname '" << lastName << "' was not found." << endl;
    }
}

void exitProgram() {
    students.clear();
    cout << "Exiting the program." << endl;
}

int main() {
    const char* fileName = "students.txt";
    // Остальной код вашей программы
    // ...
    return 0;
    #endif
}

