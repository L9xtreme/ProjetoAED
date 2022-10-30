#include "Uc.h"
#include <string>

using namespace std;

Uc::Uc(string code) {
    this -> code = code;
}

string Uc::getCode() {
    return this->code;
}

vector<Class> Uc::getClasses() {
    return this->classes;
}

void Uc::addClass(Class ucClass) {
    this -> classes.push_back(ucClass);
}
