#ifndef DIRETOR_H
#define DIRETOR_H

#include "Funcionario.h"
#include <iostream>

class Diretor : public Funcionario
{
public:
    Diretor();
    ~Diretor();

private:
    std::string areaSupervisao;
    std::string areaFormacao;

};

#endif