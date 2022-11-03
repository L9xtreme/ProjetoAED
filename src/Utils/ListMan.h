#ifndef PROJETOAED_LISTMAN_H
#define PROJETOAED_LISTMAN_H
#include <vector>
#include <map>
#include <string>
#include "Models/Schedule.h"
#include "Models/Uc.h"

using namespace std;

class ListMan {
public:
    static vector<Schedule> getStudentSchedule(const vector<Uc>& ucs, unsigned long studentCode);
    static map<unsigned long, vector<string>> getStudentsUcs(const vector<Uc>& ucs);
    static vector<unsigned long> getClassStudents(const vector<Uc>& ucs, const string& classCode);
    static vector<unsigned long> getUcStudents(const vector<Uc>& ucs, const string& Uc1);
    static vector<unsigned long> getYearStudents(const vector<Uc>& ucs, const char& Ano);
    static vector<unsigned long> getStudentsTotal(const vector<Uc>& ucs);
};


#endif //PROJETOAED_LISTMAN_H
