#include <iostream>
#include <Utils/FileMan.h>
#include <Utils/MenuMan.h>
#include <Utils/ListMan.h>

using namespace std;

vector<Uc> ucs;

// Util Functions
string askForFile() {
    cout << "Indique o caminho do ficheiro que pretende carregar:";
    string path;
    cin.ignore();
    getline(cin, path);
    return path;
}

// Load Functions
void loadUcs() {
    ucs = FileMan::readUcsClassesFromFile(askForFile());
}

void loadStudents(){
    FileMan::readStudentClassesFromFile(ucs, askForFile());
}

void loadSchedules(){
    FileMan::readScheduleFromFile(ucs, askForFile());
}

// List Functions
void displayStudentSchedule() {
    // Ask for student code
    cout << "Digite o codigo do estudante: ";
    cin.ignore();
    int studentCode;
    cin >> studentCode;

    vector<Schedule> studentSchedule = ListMan::getStudentSchedule(ucs, studentCode);
    cout << "Horario do estudante" << to_string(studentCode) << ":" << endl;
    for (Schedule schedule: studentSchedule) {
        int horas = int(schedule.getStartHour());
        double minutos = (schedule.getStartHour() - int(schedule.getStartHour())) * 60;
        int horas2 = int(schedule.getDuration());
        double minutos2 = (schedule.getDuration() - int(schedule.getDuration())) * 60;
        cout << "Aula de " << schedule.getUcCode() << " do tipo " << Schedule::typeToString(schedule.getType()) << " a " << Schedule::weekDayToString(schedule.getWeekday()) << " as " << horas << " horas e " << int(minutos) << " minutos com duracao de " << horas2 << " horas e " << minutos2 << " minutos." << endl;
    }
}


// Menus
void displayLoadMenu() {
        int choice = MenuMan::createMenu("Selecione o que pretende fazer", vector<string>{"Carregar lista de turmas", "Carregar lista de estudantes", "Carregar lista de aulas"});
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
            default:
                cout << "Por favor, selecione uma opção válida!" << endl;
                displayLoadMenu();
                break;
    }
}

void displayListMenu() {
    int choice = MenuMan::createMenu("Listagens", vector<string>{"Ocupação de turmas/ano/UC", "Horário de determinado estudante", "Estudantes em determinada turma/UC/ano", "Estudantes com mais de n UCs", "Voltar atrás"});
    switch(choice){
        case 1:
            //TODO função de ocupações
            break;
        case 2:
            displayStudentSchedule();
            break;
        case 3:
            //TODO função estudantes em determinada turma/UC/ano
            break;
        case 4:
            //TODO Estudantes com mais de n UCs
            break;
        case 5:
            break;
        default:
            cout << "Escolha uma opção válida" << endl;
            displayListMenu();
            break;
    }
}

void displayMainMenu() {
    while (true) {
        int choice = MenuMan::createMenu("Selecione o que pretende fazer", vector<string>{"Carregar Dados", "Alterar Dados", "Ver Dados", "Sair"});
        bool exit = false;
        switch (choice) {
            case 1:
                displayLoadMenu();
                break;
            case 2:
                // TODO create function to change data
                break;
            case 3:
                displayListMenu();
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