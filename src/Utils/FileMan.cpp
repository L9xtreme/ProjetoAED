#include <iostream>
#include "FileMan.h"
#include <fstream>
#include <vector>
#include <Models/Uc.h>

using namespace std;


int FileMan::UcPosInVector(vector<Uc> Ucs, const string& UcCode) {
    for (int i = 0; i < Ucs.size(); i++) {
        if (Ucs[i].getCode() == UcCode) return i;
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
    vector<Uc> Ucs;
    string UcsClasses = fileToString(filePath);

    vector<string> lines = split(UcsClasses, '\n');
    for (const string& line: lines) {
        if (line.empty()) continue;


        cout << "Ucs Size: " << Ucs.size() << endl;

        vector<string> values = split(line, ',');
        /*
         * values[0] // Uc Code
         * values[1] // Class Code
         */

        int ucPos = UcPosInVector(Ucs, values[0]);
        if(ucPos == -1) { // Uc doesn't exist in vector
            Uc uc(values[0]);
            Ucs.push_back(uc);
            ucPos = Ucs.size() - 1l;
        }

        // Add Class to Uc that is in `ucPos` in vector
        Class class1(values[1]);
        Ucs[ucPos].addClass(class1);
        cout << "Uc's Classes' Size: " << Ucs[ucPos].getClasses().size() << endl;

    }
    return Ucs;
}