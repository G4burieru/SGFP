#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <iostream>

class Presidente
{
public:
    Presidente();
    ~Presidente();

private:
    std::string areaFormacao;
    std::string formacaoMaxima;

};

#endif