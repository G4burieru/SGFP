#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"
#include <iostream>

class Operador : public Funcionario
{
public:
    Operador();
    ~Operador();

    void aumentoSalarial();

private:

};

#endif