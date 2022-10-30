#ifndef TRABALHOAED_CLASS_H
#define TRABALHOAED_CLASS_H
#include <string>
#include <list>
#include "Student.h"

using namespace std;

class Class {
    private:
        string code;
        list<Student> students;
    public:
        Class(string code);

        string getCode();
        list<Student> getStudents();

        void addStudent(Student student);


};


#endif //TRABALHOAED_CLASS_H
