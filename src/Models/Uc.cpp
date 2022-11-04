#include "Uc.h"

using namespace std;

/**
 * Initializer
 * Time-complexity -> O(1)
 * @param code
 */

Uc::Uc(string code) {
    this -> code = code;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return code
 */

string Uc::getCode() {
    return this->code;
}

/**
 * Getters
 * Time-complexity -> O(1)
 * @return classes
 */

vector<Class> Uc::getClasses() {
    return this->classes;
}

void Uc::addClass(Class ucClass) {
    this -> classes.push_back(ucClass);
}

void Uc::insertClass(Class ucClass, int pos) {
    this -> classes[pos] = ucClass;
}

void Uc::setClasses(vector<Class> classes) {
    this -> classes = classes;
}
