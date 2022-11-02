#ifndef PROJETOAED_LISTMAN_H
#define PROJETOAED_LISTMAN_H
#include <vector>
#include "Models/Schedule.h"
#include "Models/Uc.h"

class ListMan {
public:
    static vector<Schedule> getStudentSchedule(const vector<Uc>& ucs, unsigned long studentCode);
};


#endif //PROJETOAED_LISTMAN_H
