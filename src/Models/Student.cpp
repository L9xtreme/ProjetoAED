#include "Student.h"
using namespace std;

Student::Student(string code, string name) {
    this -> code = code;
    this -> name = name;
}

string Student::getName() {
    return this -> name;
}

string Student::getCode() {
    return this -> code;
}

string Student::toString() {
    return "Code: " + this -> code + "; Name: " + this -> name;
}