#ifndef PROJETOAED_STUDENT_H
#define PROJETOAED_STUDENT_H
#include <string>

using namespace std;

class Student {
    private:
        unsigned long code;
        string name;

    public:
        Student(unsigned long code, string name);

        string getName();
        unsigned long getCode();

        string toString();
};
#endif