#include <iostream>
#include <Utils/FileMan.h>

using namespace std;


int main(int argc, char* argv[]) {
    vector<Uc> Ucs = FileMan::readUcsClassesFromFile("classes_per_uc.csv");
    cout << "Agradavel" << endl;

}