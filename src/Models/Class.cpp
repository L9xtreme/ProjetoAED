#include "Class.h"

using namespace std;

/**
 * Initializer
 * Time-complexity -> O(1)
 * @param code
 */

Class::Class(string code){
    this -> code = code;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return code
 */

string Class::getCode() {
    return this->code;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return students
 */

list<Student> Class::getStudents() {
    return this->students;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return schedule
 */

vector<Schedule> Class::getSchedule() {
    return this->schedule;
}

void Class::addStudent(Student student) {
    this -> students.push_back(student);
}

void Class::addSchedule(Schedule schedule1) {
    this -> schedule.push_back(schedule1);
}

void Class::removeStudent(unsigned long studentCode) {
    auto it = this->students.begin();
    while (it != students.end()) {
        if (it->getCode() == studentCode) {
            students.erase(it);
            break;
        }
    }
}

void Class::removeStudent(Student student) {
    return removeStudent(student.getCode());
}

void Class::setStudents(list<Student> students) {
    this->students = students;
}