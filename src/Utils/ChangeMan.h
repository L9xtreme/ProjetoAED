#ifndef PROJETOAED_CHANGEMAN_H
#define PROJETOAED_CHANGEMAN_H
#include <queue>
#include <string>
#include <vector>
#include <Models/Uc.h>
#include <Models/Change.h>

using namespace std;

class ChangeMan {
    private:
        queue<Change> changes;
        static const int CLASSCAP = 25;

        void addStudentToClass(vector<Uc> ucs, Student student, const string& classCode);
        void addStudentToUC(vector<Uc> ucs, Student student, const string& ucCode, const string& classCode);
        void removeStudentFromClass(vector<Uc> ucs, unsigned long studentCode, const string& classCode);
        void removeStudentFromUc(vector<Uc> ucs, unsigned long studentCode, const string& ucCode);

    public:
        ChangeMan();
        bool tryAddStudentToClass(const vector<Uc>& ucs, Student student, const string& classCode);
        bool tryAddStudentToUc(const vector<Uc>& ucs, Student student, const string& ucCode);
        bool tryRemoveStudentFromClass(const vector<Uc>& ucs, unsigned long studentCode, const string& classCode);
        bool tryRemoveStudentFromUc(const vector<Uc>& ucs, unsigned long studentCode, const string& ucCode);
        void processQueue(vector<Uc> ucs);
};


#endif //PROJETOAED_CHANGEMAN_H
