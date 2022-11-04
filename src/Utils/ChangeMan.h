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

        void removeStudentFromClass(vector<Uc> ucs, unsigned long studentCode, string classCode);
        void removeStudentFromUc(vector<Uc> ucs, unsigned long studentCode, string ucCode);

    public:
        ChangeMan();
        bool tryRemoveStudentFromClass(vector<Uc> ucs, unsigned long studentCode, string classCode);
        bool tryRemoveStudentFromUc(vector<Uc> ucs, unsigned long studentCode, string ucCode);
};


#endif //PROJETOAED_CHANGEMAN_H
