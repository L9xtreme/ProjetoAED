#include "ListMan.h"

vector<Schedule> ListMan::getStudentSchedule(const vector<Uc>& ucs, const unsigned long studentCode) {
    vector<Schedule> res;
    for (Uc uc: ucs) {
        for (Class ucClass: uc.getClasses()) {
            for(Student student: ucClass.getStudents()){
                if (studentCode == student.getCode()) {
                    for (Schedule ucSchedule: ucClass.getSchedule())
                        res.push_back(ucSchedule);
                }
                break;
            }
        }
    }
    Schedule::sortSchedule(res);
    return res;
}