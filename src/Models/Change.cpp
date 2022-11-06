#include "Change.h"
#include "Utils/ListMan.h"

Change::Change(Type changeType, Student student, string target) {
    this->changeType = changeType;
    this->student = student;
    this->target = target;
}

Change::Change(Type changeType, Student student, string target, string target2) {
    this->changeType = changeType;
    this->student = student;
    this->target = target;
    this->target2 = target2;
}

Student Change::getStudent() {
    return this->student;
}

Type Change::getType() {
    return this->changeType;
}

string Change::getTarget() {
    return this->target;
}

string Change::getTarget2() {
    return this->target2;
}