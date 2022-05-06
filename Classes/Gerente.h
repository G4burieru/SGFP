#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <iostream>

class Gerente
{
public:
    Gerente();
    ~Gerente();

private:
    std::string areaSupervisao;

};

#endif