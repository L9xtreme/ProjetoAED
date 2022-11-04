#include <iostream>
#include "Utils/FileMan.h"
#include "Utils/MenuMan.h"
#include "Utils/ListMan.h"
#include <map>
#include <cmath>

using namespace std;

vector<Uc> ucs;

// Util Functions

/**
 * Função para pedir o caminho dos ficheiros para as funções load ficarem mais resumidas
 * Time-complexity -> O(1)
 * @return path caminho do ficheiro
 */

string askForFile() {
    cout << "Indique o caminho do ficheiro que pretende carregar:";
    string path;
    cin.ignore();
    getline(cin, path);
    return path;
}

/**
 * Função para mostrar o nome de um estudante correspondente ao seu número
 * Time-complexity -> O(n^3)
 * @param studentCode código do estudante
 * @return student nome do estudante
 */

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

/**
 * Função para "carregar" as UC's
 * Time-complexity -> O(n + k) (k=tamanho do for loop da função readUcsClassesFromFile)
 */

void loadUcs() {
    ucs = FileMan::readUcsClassesFromFile(askForFile());
}

/**
 * Função para "carregar" os estudantes
 * Time-complexity -> O(n + k) (k=tamanho do for loop da função readStudentClassesFromFile)
 */

void loadStudents(){
    FileMan::readStudentClassesFromFile(ucs, askForFile());
}

/**
 * Função para "carregar" os horários
 * Time-complexity -> O(n + k) (k=tamanho do for loop da função readScheduleFromFile)
 */

void loadSchedules(){
    FileMan::readScheduleFromFile(ucs, askForFile());
}

// List Functions

/**
 * Função que a partir do numero do estudante dá print ao horário do mesmo estudante
 * Time-complexity -> O(n^4 + k) (k=tamanho do for loop)
 */

void displayStudentSchedule() {
    cout << "Digite o codigo do estudante: ";
    cin.ignore();
    int studentCode;
    cin >> studentCode;

    vector<Schedule> studentSchedule = ListMan::getStudentSchedule(ucs, studentCode);
    cout << "Horario do estudante " << getStudentFromCode(studentCode).getName() << "(" << to_string(studentCode) << ")" << ":" << endl;
    for (Schedule schedule: studentSchedule) {
        int horas = int(schedule.getStartHour());
        double minutos = (schedule.getStartHour() - int(schedule.getStartHour())) * 60;
        int horas2 = int(schedule.getDuration());
        double minutos2 = (schedule.getDuration() - int(schedule.getDuration())) * 60;
        cout << "Aula de " << schedule.getUcCode() << " do tipo " << Schedule::typeToString(schedule.getType()) << " a " << Schedule::weekDayToString(schedule.getWeekday()) << " as " << horas << " horas e " << int(minutos) << " minutos com duracao de " << horas2 << " horas e " << minutos2 << " minutos." << endl;
    }
}

/**
 * Função que a partir de um número n de UC's dá print aos estudantes com mais de n UC's
 * Time-complexity -> O(n^3 + k) (k=tamanho do for loop)
 */

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

/**
 * Função que a partir do código do estudante dá print ás UC's em que esse estudante está inscrito
 * Time-complexity -> O(n^3 + k) (k=tamanho do for loop)
 */

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

/**
 * Função que a partir do codigo da turma dá print aos estudantes que estão nessa turma
 * Time-complexity -> O(n^3 + k) (k=tamanho do for loop)
 */

void diplayStudentsInClass(){
    cout << "Digite o codigo da turma: ";
    cin.ignore();
    string classCode;
    cin >> classCode;

    vector<unsigned long> studentsinclass = ListMan::getClassStudents(ucs, classCode);

    for(int i : studentsinclass){
        cout << getStudentFromCode(i).getName() << " esta nesta turma!" << endl;
    }
}

/**
 * Função que a partir do codigo da UC dá print aos estudantes que estão nessa mesma UC
 * Time-complexity -> O(n^3 + k) (k=tamanho do for loop)
 */

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

/**
 * Função que a partir do ano dá print aos estudantes que estão nessa mesmo ano
 * Time-complexity -> O(n^3 + k) (k=tamanho do for loop)
 */

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

/**
 * Função que dá print ao número de estudantes do curso inteiro
 * Time-complexity -> O(n^3)
 */

void displayTotalStudents(){
    vector<unsigned long> studentsTotal = ListMan::getStudentsTotal(ucs);
    cout << "" << endl;
    cout << "O numero total de estudantes no curso e: " << studentsTotal.size() << endl;
    cout << "" << endl;
}

/**
 * Função que a partir de uma UC dá print á percentagem de alunos nessa UC
 * Time-complexity -> O(2*(n^3))
 */

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

/**
 * Função que a partir de um ano dá print á percentagem de alunos nesse ano
 * Time-complexity -> O(2*(n^3))
 */

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

/**
 * Função que a partir de uma turma dá print á percentagem de alunos nessa turma
 * Time-complexity -> O(2*(n^3))
 */

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

/**
 * Função que cria um menu para os "carregamentos" dos ficheiros
 * Time-complexity -> O()
 */

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

/**
 * Função que cria um menu para se proceder á escolha de que função queremos executar
 * Time-complexity -> O()
 */

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

/**
 * Função que cria um menu para escolher a percentagem do que queremos calcular
 * Time-complexity -> O()
 */

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

/**
 * Função que cria um "sub"-menu para escolher uma de duas opções : Numero de alunos no curso ou Percentagens
 * Time-complexity -> O()
 */

void displayOptionsMenu() {
    int choice = MenuMan::createMenu("Opcoes : ", vector<string>{"Numero de alunos no curso", "Percentagens"});
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

/**
 * Função que cria um menu com todas as listagens
 * Time-complexity -> O()
 */

void displayListMenu() {
    int choice = MenuMan::createMenu("Listagens", vector<string>{"Numero de alunos  no curso / Percentagens(UCs,turmas,anos)", "Horario de determinado estudante", "Estudantes em determinada turma/UC/ano", "Estudantes com mais de n UCs", "Cadeiras de determinado estudante", "Voltar atras"});
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

/**
 * Função que cria um menu para escolher que remoção o utilizador quer fazer (Turma ou UC)
 * Time-complexity -> O()
 */

void displayRemoveMenu() {
    int choice = MenuMan::createMenu("Remoção de : ", vector<string>{"Turma ", "Uc "});
    switch(choice){
        case 1:

            break;
        case 2:
            //TODO Remover estudante de uma UC.
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayRemoveMenu();
            break;
    }
}

/**
 * Função que cria um menu para o utilizador escolher que alteração quer fazer
 * Time-complexity -> O()
 */


void displayChangeMenu() {
    int choice = MenuMan::createMenu("Alterações: ", vector<string>{"Remover estudante de turma/UC ", "Adicionar estudante a uma turma/UC", "Alterar a turma/UC de um estudante", "Alterar um conjunto de turmas/UCs de um estudante "});
    switch(choice){
        case 1:
            displayRemoveMenu();
            break;
        case 2:
            //TODO Adicionar estudante a uma turma/UC.
            break;
        case 3:
            //TODO Alterar a turma/UC de um estudante.
            break;
        case 4:
            //TODO Alterar um conjunto de turmas/UCs de um estudante.
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            displayChangeMenu();
            break;
    }
}

/**
 * Função que cria o menu principal com várias opções
 * Time-complexity -> O()
 */

void displayMainMenu() {
    while (true) {
        int choice = MenuMan::createMenu("Selecione o que pretende fazer", vector<string>{"Carregar Dados", "Alterar Dados", "Ver Dados", "Sair"});
        switch (choice) {
            case 1:
                displayLoadMenu();
                break;
            case 2:
                displayChangeMenu();
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