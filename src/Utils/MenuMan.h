#ifndef PROJETOAED_MENUMAN_H
#define PROJETOAED_MENUMAN_H
#include <string>
#include <vector>

using namespace std;

class MenuMan {
    public:
        static int createMenu(string title, vector<string> options);
};


#endif //PROJETOAED_MENUMAN_H
