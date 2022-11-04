#include "Student.h"
using namespace std;

/**
 * Initializer
 * Time-complexity -> O(1)
 * @param code
 * @param name
 */

Student::Student(unsigned long code, string name) {
    this -> code = code;
    this -> name = name;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return name
 */

string Student::getName() {
    return this -> name;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return code
 */

unsigned long Student::getCode() {
    return this -> code;
}

string Student::toString() {
    return "Code: " + to_string(this -> code) + "; Name: " + this -> name;
}