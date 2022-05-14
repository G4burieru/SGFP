#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <iostream>

class Gerente : public Funcionario
{
public:
    Gerente();
    ~Gerente();

    void aumentoSalarial();

    std::string getAreasupervisao();

    void setAreasupervisao(std::string areaSupervisao);

private:
    std::string areaSupervisao;

};

#endif