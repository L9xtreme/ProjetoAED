#include "MenuMan.h"
#include <iostream>

using namespace std;

int MenuMan::createMenu(std::string title, vector<string> options) {
    cout << title << endl << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ": " << options[i] << endl;
    }

    cout << endl << ">> ";
    int n;
    cin >> n;

    return n;
}