#include "ListMan.h"
#include <algorithm>

using namespace std;

/**
 * Função que a partir do vetor de UC's e do código do estudante adiciona a um vetor res os horários desse estudante numa UC em que ele esteja inscrito
 * Time-complexity -> O(n^4)
 * @param ucs vetor com todas as UC's
 * @param studentCode código do estudante
 * @return res vetor com os horários do estudante que estamos a procurar numa UC em que ele esteja inscrito
 */

vector<Schedule> ListMan::getStudentSchedule(const vector<Uc>& ucs, const unsigned long studentCode) {
    vector<Schedule> res;
    for (Uc uc: ucs) {
        for (Class ucClass: uc.getClasses()) {
            for(Student student: ucClass.getStudents()){
                if (studentCode == student.getCode()) {
                    for (const Schedule& ucSchedule: ucClass.getSchedule())
                        res.push_back(ucSchedule);
                    break;
                }
            }
        }
    }
    Schedule::sortSchedule(res);
    return res;
}

/**
 * Função que a partir do vetor de UC's adiciona a um mapa res as UC's (value) que um estudante (key) está inscrito
 * Time-complexity -> O(n^3)
 * @param ucs vetor com todas as UC's
 * @return res mapa com UC's (value) que um estudante (key) está inscrito
 */

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

/**
 * Função que a partir do vetor de UC's e do código da turma adiciona a um vetor res o código de todos os estudantes que estão nessa turma
 * Time-complexity -> O(n^3)
 * @param ucs vetor com todas as UC's
 * @param classCode código da turma
 * @return res vetor com o código de todos os estudantes que estão na turma em que estamos a procurar
 */

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

/**
 * Função que a partir do vetor de UC's e de uma UC em particular adiciona a um vetor res o código de todos os estudantes que estão nessa UC
 * Time-complexity -> O(n^3)
 * @param ucs vetor com todas as UC's
 * @param Uc1 UC que queremos os estudantes
 * @return res vetor com o código de todos os estudantes que estão na UC1
 */

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

/**
 * Função que a partir do vetor de UC's e de um ano adiciona a um vetor res o código de todos os estudantes que estão nesse ano
 * Time-complexity -> O(n^3)
 * @param ucs vetor com todas as UC's
 * @param Ano ano de que queremos os estudantes
 * @return res vetor com o código de todos os estudantes que estão no Ano
 */

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

/**
 * Função que a partir do vetor de UC's dá return a todos os estudantes que estão no curso
 * Time-complexity -> O(n^3)
 * @param ucs vetor com todas as UC's
 * @return res vetor com todos os estudantes que estão no curso
 */

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

