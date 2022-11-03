#include "ListMan.h"
#include <algorithm>

using namespace std;

vector<Schedule> ListMan::getStudentSchedule(const vector<Uc>& ucs, const unsigned long studentCode) {
    vector<Schedule> res;
    for (Uc uc: ucs) {
        for (Class ucClass: uc.getClasses()) {
            for(Student student: ucClass.getStudents()){
                if (studentCode == student.getCode()) {
                    for (const Schedule& ucSchedule: ucClass.getSchedule())
                        res.push_back(ucSchedule);
                }
                break;
            }
        }
    }
    Schedule::sortSchedule(res);
    return res;
}

map<unsigned long, vector<string>> ListMan::getStudentsUcs(const vector<Uc>& ucs) {
    map<unsigned long, vector<string>> res;
    for(Uc uc : ucs){
        for(Class ucClass : uc.getClasses()) {
            for(Student student : ucClass.getStudents()){
                if(res.find(student.getCode()) == res.end()) {
                    // Not found
                    res[student.getCode()] = vector<string>();
                }
                res[student.getCode()].push_back(uc.getCode());
            }
        }
    }

    return res;
}

vector<unsigned long> ListMan::getClassStudents(const vector<Uc>& ucs, const string& classCode){
    vector<unsigned long> res;
    for(Uc uc: ucs) {
        for(Class ucClass: uc.getClasses()){
            if (ucClass.getCode() == classCode)
            for(Student student : ucClass.getStudents()){
                if (count(res.begin(), res.end(), student.getCode()) <= 0) {
                    res.push_back(student.getCode());
                }
            }
        }
    }
    return res;
}

vector<unsigned long> ListMan::getUcStudents(const vector<Uc>& ucs, const string& Uc1){
    vector<unsigned long> res;
    for(Uc uc: ucs) {
        if(uc.getCode() == Uc1){
            for(Class ucClass : uc.getClasses()){
                for(Student student : ucClass.getStudents()){
                    if(count(res.begin(),res.end(),student.getCode()) <= 0){
                        res.push_back(student.getCode());
                    }
                }
            }
        }
    }
    return res;
}

vector<unsigned long> ListMan::getYearStudents(const vector<Uc>& ucs, const char& Ano){
    vector<unsigned long> res;
    for(Uc uc: ucs) {
        for(Class ucClass: uc.getClasses()){
            if (ucClass.getCode().at(0) == Ano) {
                for (Student student: ucClass.getStudents()) {
                    if (count(res.begin(), res.end(), student.getCode()) <= 0) {
                        res.push_back(student.getCode());
                    }
                }
            }
        }
    }
    return res;
}

vector<unsigned long> ListMan::getStudentsTotal(const vector<Uc> &ucs) {
    vector<unsigned long> res;
    for(Uc uc : ucs){
        for(Class ucClass : uc.getClasses()){
            for(Student student : ucClass.getStudents()){
                if(count(res.begin(), res.end(), student.getCode()) <= 0){
                    res.push_back(student.getCode());
                }
            }
        }
    }
    return res;
}

