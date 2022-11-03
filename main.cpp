#include <iostream>
#include <Utils/FileMan.h>
#include <Utils/MenuMan.h>
#include <Utils/ListMan.h>
#include <map>
#include <cmath>

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
        if(i.second.size() > n) {
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

void displayTotalStudents(){
    vector<unsigned long> studentsTotal = ListMan::getStudentsTotal(ucs);
    cout << "" << endl;
    cout << "O numero total de estudantes na FEUP e: " << studentsTotal.size() << endl;
    cout << "" << endl;
}

void displayPercentageInUC(){
    cout << "Digite a Uc que quer a percentagem: ";
    cin.ignore();
    string Uc1;
    cin >> Uc1;

    vector<unsigned long> studentsTotal = ListMan::getStudentsTotal(ucs);
    vector<unsigned long> studentsInUc = ListMan::getUcStudents(ucs, Uc1);

    cout << "" << endl;
    cout << "A percentagem de alunos na Uc " << Uc1 << " e " << ceil((((double) studentsInUc.size() / (double) studentsTotal.size())*100)*100.0)/100.0 << "%" << endl;
    cout << "" << endl;
}

void displayPercentageInYear(){
    cout << "Digite o ano que quer a percentagem: ";
    cin.ignore();
    char Ano;
    cin >> Ano;

    vector<unsigned long> studentsTotal = ListMan::getStudentsTotal(ucs);
    vector<unsigned long> studentsInYear = ListMan::getYearStudents(ucs, Ano);

    cout << "" << endl;
    cout << "A percentagem de alunos no ano " << Ano << " e " << ceil((((double) studentsInYear.size() / (double) studentsTotal.size())*100)*100.0)/100.0 << "%" << endl;
    cout << "" << endl;
}

void displayPercentageInClass(){
    cout << "Digite a turma que quer a percentagem: ";
    cin.ignore();
    string classCode;
    cin >> classCode;

    vector<unsigned long> studentsinclass = ListMan::getClassStudents(ucs, classCode);
    vector<unsigned long> studentsTotal = ListMan::getStudentsTotal(ucs);

    cout << "" << endl;
    cout << "A percentagem de alunos na turma " << classCode << " e " << ceil((((double) studentsinclass.size() / (double) studentsTotal.size())*100)*100.0)/100.0 << "%" << endl;
    cout << "" << endl;
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

void displayOtherOptionsMenu() {
    int choice = MenuMan::createMenu("Percentagem de estudantes no/a: ", vector<string>{"Uc", "Turma", "Ano"});
    //the percentages on the year function don't add to 100% because there can be students in more than 1 year
    switch(choice){
        case 1:
            displayPercentageInUC();
            break;
        case 2:
            displayPercentageInClass();
            break;
        case 3:
            displayPercentageInYear();
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayOtherOptionsMenu();
            break;
    }
}

void displayOptionsMenu() {
    int choice = MenuMan::createMenu("Opcoes : ", vector<string>{"Numero de alunos na universidade", "Percentagens"});
    switch(choice){
        case 1:
            displayTotalStudents();
            break;
        case 2:
            displayOtherOptionsMenu();
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayOptionsMenu();
            break;
    }
}

void displayListMenu() {
    int choice = MenuMan::createMenu("Listagens", vector<string>{"Numero de alunos  na Universidade / Percentagens(UCs,turmas,anos)", "Horario de determinado estudante", "Estudantes em determinada turma/UC/ano", "Estudantes com mais de n UCs", "Cadeiras de determinado estudante", "Voltar atras"});
    switch(choice){
        case 1:
            displayOptionsMenu();
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
                cout << "Por favor, selecione uma opcao valida!" << endl;
        }
    }
}


int main(int argc, char* argv[]) {
    displayMainMenu();
    return 0;
}