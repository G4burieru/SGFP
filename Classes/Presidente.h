#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <iostream>

class Presidente : public Funcionario
{
public:
    Presidente();
    ~Presidente();

    void aumentoSalarial();

    std::string getAreaformacao();
    std::string getFormacaomaxima();

    void setAreaformacao(std::string areaFormacao);
    void setFormacaomaxima(std::string formacaoMaxima);

private:
    std::string areaFormacao;
    std::string formacaoMaxima;

};

#endif