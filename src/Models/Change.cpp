#include "Change.h"

Change::Change(Type changeType, unsigned long targetStudentCode, string target) {
    this->changeType = changeType;
    this->studentCode = targetStudentCode;
    this->target = target;
}

unsigned long Change::getStudentCode() {
    return this->studentCode;
}

Type Change::getType() {
    return this->changeType;
}

string Change::getTarget() {
    return this->target;
}