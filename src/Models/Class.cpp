#include "Class.h"
using namespace std;

Class::Class(string code){
    this -> code = code;
}

string Class::getCode() {
    return this->code;
}

list<Student> Class::getStudents() {
    return this->students;
}

void Class::addStudent(Student student) {
    this -> students.push_back(student);
}