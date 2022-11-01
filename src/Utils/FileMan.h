#ifndef PROJETOAED_FILEMAN_H
#define PROJETOAED_FILEMAN_H
#include <string>
#include <vector>
#include <Models/Uc.h>

using namespace std;

class FileMan {
    private:
        static string fileToString(const string& filePath);
        static vector<string> split(const string& str, char del);
        static int ucPosInVector(vector<Uc> Ucs, const string& UcCode);
        static int classPosInVector(vector<Class> classes, const string& classCode);

    public:
        static vector<Uc> readUcsClassesFromFile(const string& filePath);
        static void readStudentClassesFromFile(vector<Uc>& ucs, const string& filePath);
        static void readScheduleFromFile(vector<Uc>& ucs, const string& filePath);
};
#endif //PROJETOAED_FILEMAN_H
