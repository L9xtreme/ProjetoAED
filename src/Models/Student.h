#ifndef PROJETOAED_STUDENT_H
#define PROJETOAED_STUDENT_H
#include <string>

using namespace std;

class Student {
    private:
        string code;
        string name;

    public:
        Student(string code, string name);

        string getName();
        string getCode();

        string toString();
};
#endif