#include <iostream>
#include "FileMan.h"
#include <fstream>
#include <vector>
#include <Models/Uc.h>
#include <Models/Schedule.h>

using namespace std;


int FileMan::ucPosInVector(vector<Uc> Ucs, const string& UcCode) {
    for (int i = 0; i < Ucs.size(); i++) {
        if (Ucs[i].getCode() == UcCode) return i;
    }

    return -1;
}

int FileMan::classPosInVector(vector<Class> classes, const string& classCode) {
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getCode() == classCode) return i;
    }

    return -1;
}

vector<string> FileMan::split(const string& str, char del) {
    vector<string> splitted;
    string temp;
    for (char i : str) {
        if (i != del) {
            temp += i;
        } else {
            splitted.push_back(temp);
            temp = "";
        }
    }

    splitted.push_back(temp);

    return splitted;
}

string FileMan::fileToString(const string& filePath) {
    ifstream inFile(filePath);
    string fileText;
    string temp;

    if (!inFile) {
        return "File not found";
    }
    int i = 0;
    while (getline(inFile, temp)) {
        if (i++ == 0) continue;
        fileText += temp + "\n";
    }

    inFile.close();

    return fileText;
}

vector<Uc> FileMan::readUcsClassesFromFile(const string& filePath) {
    vector<Uc> ucs;
    string UcsClasses = fileToString(filePath);

    vector<string> lines = split(UcsClasses, '\n');
    for (const string& line: lines) {
        if (line.empty()) continue;

        vector<string> values = split(line, ',');
        /*
         * values[0] // Uc Code
         * values[1] // Class Code
         */

        int ucPos = ucPosInVector(ucs, values[0]);
        if(ucPos == -1) { // Uc doesn't exist in vector
            Uc uc(values[0]);
            ucs.push_back(uc);
            ucPos = ucs.size() - 1l;
        }

        // Add Class to Uc that is in `ucPos` in vector
        Class class1(values[1]);
        ucs[ucPos].addClass(class1);

    }
    return ucs;
}

void FileMan::readStudentClassesFromFile(vector<Uc>& ucs, const string& filePath) {
    string studentClasses = fileToString(filePath);

    vector<string> lines = split(studentClasses, '\n');
    int i = 0;
    for (const string& line: lines) {
        if (line.empty()) continue;

        vector<string> values = split(line, ',');
        /*
         * values[0] // Student Code
         * values[1] // Student Name
         * values[2] // Uc Code
         * values[3] // Class Code
         */

        Student student(values[0], values[1]);

        int ucPos = ucPosInVector(ucs, values[2]);

        if (ucPos == -1) continue;

        int classPos = classPosInVector(ucs[ucPos].getClasses(), values[3]);

        if (classPos == -1) continue;

        Class classToChange = ucs[ucPos].getClasses()[classPos];
        classToChange.addStudent(student);
        ucs[ucPos].insertClass(classToChange, classPos);

        cout << "Adicionado " << ++i << " alunos de " << lines.size() << endl;
    }
}

void FileMan::readScheduleFromFile(vector<Uc>& ucs, const string& filePath){
    string schedulesText = fileToString(filePath);

    vector<string> lines = split(schedulesText, '\n');
    int i = 0;
    for(const string& line: lines){
        if(line.empty()) continue;

        vector<string> values = split(line, ',');

        /*
         * values[0] = Class Code
         * values[1] = Uc Code
         * values[2] = Weekday
         * values[3] = Start Hour
         * values[4] = Duration
         * values[5] = Type
         */

        Schedule classSchedule2(Schedule::weekdayFromString(values[2]), stod(values[3]), stod(values[4]), Schedule::typeFromString(values[5]));

        int ucPos = ucPosInVector(ucs, values[1]);

        if (ucPos == -1) continue;

        int classPos = classPosInVector(ucs[ucPos].getClasses(), values[0]);

        if (classPos == -1) continue;

        Class classToChange = ucs[ucPos].getClasses()[classPos];
        classToChange.addSchedule(classSchedule2);
        ucs[ucPos].insertClass(classToChange, classPos);

        cout << "Adicionado " << ++i << " aulas de " << lines.size() << endl;
    }
}
