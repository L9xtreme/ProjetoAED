#include "Student.h"
using namespace std;

Student::Student(unsigned long code, string name) {
    this -> code = code;
    this -> name = name;
}

string Student::getName() {
    return this -> name;
}

unsigned long Student::getCode() {
    return this -> code;
}

string Student::toString() {
    return "Code: " + to_string(this -> code) + "; Name: " + this -> name;
}