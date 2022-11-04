#ifndef PROJETOAED_CHANGE_H
#define PROJETOAED_CHANGE_H

#include <string>
using namespace std;

enum Type {RemoveFromClass, RemoveFromUC};

class Change {
    private:
        Type changeType;
        unsigned long studentCode;
        string target;

    public:
        Change(Type changeType, unsigned long targetStudentCode, string target);
        Type getType();
        unsigned long getStudentCode();
        string getTarget();
};


#endif //PROJETOAED_CHANGE_H
