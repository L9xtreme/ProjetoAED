#ifndef TRABALHOAED_FILEMAN_H
#define TRABALHOAED_FILEMAN_H
#include <string>
#include <vector>
#include <Models/Uc.h>

using namespace std;

class FileMan {
    private:
        static string fileToString(const string& filePath);
        static vector<string> split(const string& str, char del);
        static int UcPosInVector(vector<Uc> Ucs, const string& UcCode);

    public:
        static vector<Uc> readUcsClassesFromFile(const string& filePath);
};
#endif //TRABALHOAED_FILEMAN_H
