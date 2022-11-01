#include <iostream>
#include <Utils/FileMan.h>
#include <Utils/MenuMan.h>

using namespace std;

vector<Uc> ucs;

string askForFile() {
    cout << "Indique o caminho do ficheiro que pretende carregar:";
    string path;
    cin.ignore();
    getline(cin, path);
    return path;
}

void loadUcs() {
    ucs = FileMan::readUcsClassesFromFile(askForFile());
}

void loadStudents(){
    FileMan::readStudentClassesFromFile(ucs, askForFile());
}

void loadSchedules(){
    FileMan::readScheduleFromFile(ucs, askForFile());
}



void displayMainMenu() {
    while (true) {
        int choice = MenuMan::createMenu("Selecione o que pretende fazer", vector<string>{"Carregar lista de cadeiras", "Carregar lista de estudantes", "Carregar lista de aulas", "Sair"});
        bool exit = false;
        switch (choice) {
            case 1:
                loadUcs();
                break;
            case 2:
                loadStudents();
                break;
            case 3:
                loadSchedules();
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Por favor, selecione uma opção válida!" << endl;
        }

        if (exit) break;
    }
}

int main(int argc, char* argv[]) {
    displayMainMenu();
    return 0;
}