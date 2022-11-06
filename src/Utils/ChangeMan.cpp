#include "ChangeMan.h"
#include "Models/Change.h"
#include "Utils/ListMan.h"
#include "Models/Schedule.h"

ChangeMan::ChangeMan() {}



// Tries
bool ChangeMan::tryAddStudentToClass(const vector<Uc> &ucs, Student student, const string& classCode) {
    for(Uc uc : ucs){
        for(Class ucClass : uc.getClasses()){
            if(ucClass.getCode() == classCode and ucClass.getStudents().size() < CLASSCAP) {
                vector<Schedule> studentSchedule = ListMan::getStudentSchedule(ucs, student.getCode());

                bool isCompatible;

                for (Schedule schedule: studentSchedule) {
                    for (Schedule schedule1: ucClass.getSchedule()) {
                        if (!ListMan::areSchedulesCompatible(schedule, schedule1))
                            isCompatible = false; break;
                    }

                    if (!isCompatible) break;

                }

                if (!isCompatible) break;


                this->changes.push(Change(AddToClass, student,classCode));
                return true;
            }
        }
    }
    return false;
}

bool ChangeMan::tryAddStudentToUc(const vector<Uc> &ucs, Student student, const string& ucCode) {
    for(Uc uc : ucs){
        if(uc.getCode()==ucCode){
            for(Class ucClass : uc.getClasses()){
                if(ucClass.getStudents().size() < CLASSCAP){
                    vector<Schedule> studentSchedule = ListMan::getStudentSchedule(ucs, student.getCode());
                    bool isCompatible;

                    for (Schedule schedule: studentSchedule) {
                        for (Schedule schedule1: ucClass.getSchedule()) {
                            if (!ListMan::areSchedulesCompatible(schedule, schedule1))
                                isCompatible = false; break;
                        }

                        if (!isCompatible) break;

                    }

                    if (!isCompatible) break;

                    this->changes.push(Change(AddToUC, student,ucCode, ucClass.getCode()));
                    return true;
                }
            }
        }
    }
    return false;
}

bool ChangeMan::tryRemoveStudentFromClass(const vector<Uc>& ucs, unsigned long studentCode, const string& classCode) {
    for(Uc uc : ucs){
        for(Class ucClass : uc.getClasses()){
            if(ucClass.getCode() == classCode){
                for(Student student : ucClass.getStudents()){
                    if(student.getCode()==studentCode){
                        this->changes.push(Change(RemoveFromClass,ListMan::getStudentFromCode(ucs, studentCode),classCode));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ChangeMan::tryRemoveStudentFromUc(const vector<Uc>& ucs, unsigned long studentCode, const string& ucCode) {
    for(Uc uc : ucs){
        if(uc.getCode()==ucCode){
            for(Class ucClass : uc.getClasses()){
                for(Student student : ucClass.getStudents()){
                    if(student.getCode()==studentCode){
                        this->changes.push(Change(RemoveFromUC,ListMan::getStudentFromCode(ucs, studentCode),ucCode));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


// Alters

void ChangeMan::addStudentToClass(vector<Uc> ucs, Student student, const string &classCode) {
    for (Uc uc : ucs){
        vector<Class> classes = uc.getClasses();
        for (Class ucClass : classes){
            if (ucClass.getCode() == classCode){
                ucClass.addStudent(student);
                uc.setClasses(classes);
                break;
            }
        }
    }
}

void ChangeMan::addStudentToUC(vector<Uc> ucs, Student student, const string &ucCode, const string& classCode) {
    for (Uc uc: ucs) {
        if(uc.getCode() == ucCode) {
            vector<Class> classes = uc.getClasses();
            for (Class ucClass: classes) {
                if(ucClass.getCode()==classCode){
                    ucClass.addStudent(student);
                    uc.setClasses(classes);
                    return;
                }
            }
        }
    }
}

void ChangeMan::removeStudentFromClass(vector<Uc> ucs, unsigned long studentCode, const string& classCode) {
    for (Uc uc: ucs) {
        vector<Class> classes = uc.getClasses();
        for (Class ucClass: classes) {
            if (ucClass.getCode() == classCode) {
                for (Student student: ucClass.getStudents()) {
                    if (student.getCode() == studentCode) {
                        ucClass.removeStudent(student);

                        break;
                    }
                }
                break;
            }
        }
        uc.setClasses(classes);
    }
}

void ChangeMan::removeStudentFromUc(vector<Uc> ucs, unsigned long studentCode, const string& ucCode) {
    for (Uc uc: ucs) {
        if(uc.getCode() == ucCode) {
            vector<Class> classes = uc.getClasses();
            for (Class ucClass: classes) {
                for (Student student: ucClass.getStudents()) {
                    if (student.getCode() == studentCode) {
                        ucClass.removeStudent(student);

                        break;
                    }
                }
            }
            uc.setClasses(classes);
            break;
        }
    }
}

void ChangeMan::processQueue(vector<Uc> ucs) {
    while (!this->changes.empty()) {
        Change change = this->changes.front();

        switch (change.getType()) {
            case RemoveFromClass:
                removeStudentFromClass(ucs, change.getStudent().getCode(), change.getTarget());
                break;
            case RemoveFromUC:
                removeStudentFromUc(ucs, change.getStudent().getCode(), change.getTarget());
                break;
            case AddToClass:
                addStudentToClass(ucs, change.getStudent(), change.getTarget());
                break;
            case AddToUC:
                addStudentToUC(ucs, change.getStudent(), change.getTarget(), change.getTarget2());
                break;
        }

        this->changes.pop();
    }
}