#ifndef DIRETOR_H
#define DIRETOR_H

#include "Funcionario.h"
#include <iostream>

class Diretor : public Funcionario
{
public:
    Diretor(long codigo, std::string nome, std::string endereco, std::string telefone, Data data, float salarioDiario);
    ~Diretor();

    void aumentoSalarial();
    
    std::string getAreasupervisao();
    std::string getAreaformacao();

    void setAreasupervisao(std::string areaSupervisao);
    void setAreaformacao(std::string areaFormacao);

private:
    std::string areaSupervisao;
    std::string areaFormacao;

};

#endif