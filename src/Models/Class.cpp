#include "Class.h"
#include <iostream>
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

vector<Schedule> Class::getSchedule() {
    return this->schedule;
}

void Class::addStudent(Student student) {
    this -> students.push_back(student);
    // cout << "Adicionado estudante: " << student.getCode() << " à turma " << this -> code << endl;
}

void Class::addSchedule(Schedule schedule1) {
    this -> schedule.push_back(schedule1);
}