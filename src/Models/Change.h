#ifndef PROJETOAED_CHANGE_H
#define PROJETOAED_CHANGE_H

#include <string>
#include <Models/Student.h>
#include <Models/Uc.h>
using namespace std;

enum Type {RemoveFromClass, RemoveFromUC, AddToClass, AddToUC};

class Change {
    private:
        Type changeType;
        Student student;
        string target;
        string target2;

    public:
        Change(Type changeType, Student student, string target);
        Change(Type changeType, Student student, string target, string target2);
        Type getType();
        Student getStudent();
        string getTarget();
        string getTarget2();
};


#endif //PROJETOAED_CHANGE_H
