#ifndef GESTORHOR_H
#define GESTORHOR_H
using namespace std;
#include <set>
#include <vector>
#include <queue>
#include "Estudantes.h"
#include "HorarioUC.h"
#include "Pedido.h"
class GestorHor{
    set<Estudantes> estudantes;
    vector<HorarioUC> horario;
    queue<Pedido> pedidos;
};
#endif