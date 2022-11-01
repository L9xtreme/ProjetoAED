#ifndef PROJETOAED_UC_H
#define PROJETOAED_UC_H
#include <string>
#include <vector>
#include "Class.h"

using namespace std;

class Uc {
    private:
        string code;
        vector<Class> classes;
    public:
        Uc(string code);

        string getCode();
        vector<Class> getClasses();

        void addClass(Class ucClass);
        void insertClass(Class ucClass, int pos);
};
#endif
