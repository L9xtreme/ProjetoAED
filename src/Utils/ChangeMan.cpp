#include "ChangeMan.h"
#include "Models/Change.h"

ChangeMan::ChangeMan() {}

bool ChangeMan::tryRemoveStudentFromClass(vector<Uc> ucs, unsigned long studentCode, string classCode) {
    for(Uc uc : ucs){
        for(Class ucClass : uc.getClasses()){
            if(ucClass.getCode() == classCode){
                for(Student student : ucClass.getStudents()){
                    if(student.getCode()==studentCode){
                        this->changes.push(Change(RemoveFromClass,studentCode,classCode));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool ChangeMan::tryRemoveStudentFromUc(vector<Uc> ucs, unsigned long studentCode, string ucCode) {
    for(Uc uc : ucs){
        if(uc.getCode()==ucCode){
            for(Class ucClass : uc.getClasses()){
                for(Student student : ucClass.getStudents()){
                    if(student.getCode()==studentCode){
                        this->changes.push(Change(RemoveFromUC,studentCode,ucCode));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void ChangeMan::removeStudentFromClass(vector<Uc> ucs, unsigned long studentCode, string classCode) {
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

void ChangeMan::removeStudentFromUc(vector<Uc> ucs, unsigned long studentCode, string ucCode) {
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