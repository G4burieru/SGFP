#ifndef EMPRESA_H
#define EMPRESA_H

#include "Funcionario.h"
#include <iostream>
#include <list>

class Empresa
{
public:
    Empresa();
    ~Empresa();

private:
    std::list<Funcionario> funcionarios;

};

#endif