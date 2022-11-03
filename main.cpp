#include <iostream>
#include <Utils/FileMan.h>
#include <Utils/MenuMan.h>
#include <Utils/ListMan.h>
#include <map>

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

Student getStudentFromCode(unsigned long studentCode) {
    for (Uc uc: ucs) {
        for (Class ucClass: uc.getClasses()) {
            for (Student student: ucClass.getStudents()) {
                if (student.getCode() == studentCode) return student;
            }
        }
    }
    return {0, "A"};
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

void displayStudentNUcs(){
    cout << "Digite o numero de Ucs: ";
    cin.ignore();
    int n;
    cin >> n;
    map<unsigned long, vector<string>> studentsUcs = ListMan::getStudentsUcs(ucs);

    for (pair<unsigned long, vector<string>> i : studentsUcs) {
        if(i.second.size() >= n) {
            cout << "O estudante " << getStudentFromCode(i.first).getName() << " tem " << i.second.size() << " UCs!" << endl;
        }
    }
}

void displayStudentUcs() {
    cout << "Digite o numero do estudante: ";
    cin.ignore();
    unsigned long studentCode;
    cin >> studentCode;

    map<unsigned long, vector<string>> studentsUcs = ListMan::getStudentsUcs(ucs);

    cout << "O estudante " << getStudentFromCode(studentCode).getName() << " esta inscrito nas seguintes cadeiras:" << endl;
    for (const string& uc: studentsUcs[studentCode]) {
        cout << uc << endl;
    }
}

void diplayStudentsInClass(){
    cout << "Digite o numero da turma: ";
    cin.ignore();
    string classCode;
    cin >> classCode;

    vector<unsigned long> studentsinclass = ListMan::getClassStudents(ucs, classCode);

    for(int i : studentsinclass){
        cout << getStudentFromCode(i).getName() << " esta nesta turma!" << endl;
    }
}

void displayStudentsInUc(){
    cout << "Digite a Uc: ";
    cin.ignore();
    string Uc1;
    cin >> Uc1;

    vector<unsigned long> studentsInUc = ListMan::getUcStudents(ucs, Uc1);

    for(int i : studentsInUc){
        cout << getStudentFromCode(i).getName() << " esta nesta UC!" << endl;
    }
}

void displayStudentsInYear(){
    cout << "Digite o Ano: ";
    cin.ignore();
    char Ano;
    cin >> Ano;

    vector<unsigned long> studentsInYear = ListMan::getYearStudents(ucs, Ano);

    for(int i : studentsInYear){
        cout << getStudentFromCode(i).getName() << " esta neste Ano!" << endl;
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
                cout << "Por favor, selecione uma opcao valida!" << endl;
                displayLoadMenu();
                break;
    }
}

void displayStudentsMenu() {
    int choice = MenuMan::createMenu("Estudantes em: ", vector<string>{"Turma", "Uc", "Ano"});
    switch(choice){
        case 1:
            diplayStudentsInClass();
            break;
        case 2:
            displayStudentsInUc();
            break;
        case 3:
            displayStudentsInYear();
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayStudentsMenu();
            break;
    }
}

void displayListMenu() {
    int choice = MenuMan::createMenu("Listagens", vector<string>{"Ocupação de turmas/ano/UC", "Horario de determinado estudante", "Estudantes em determinada turma/UC/ano", "Estudantes com mais de n UCs", "Cadeiras de determinado estudante", "Voltar atrás"});
    switch(choice){
        case 1:
            //TODO função de ocupações
            break;
        case 2:
            displayStudentSchedule();
            break;
        case 3:
            displayStudentsMenu();
            break;
        case 4:
            displayStudentNUcs();
            break;
        case 5:
            displayStudentUcs();
            break;
        case 6:
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayListMenu();
            break;
    }
}

void displayMainMenu() {
    while (true) {
        int choice = MenuMan::createMenu("Selecione o que pretende fazer", vector<string>{"Carregar Dados", "Alterar Dados", "Ver Dados", "Sair"});
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
                return;
            default:
                cout << "Por favor, selecione uma opção valida!" << endl;
        }
    }
}


int main(int argc, char* argv[]) {
    displayMainMenu();
    return 0;
}