#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <iostream>

class Gerente : public Funcionario
{
public:
    Gerente(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario, std::string areaSupervisao);
    ~Gerente();

    void aumentoSalarial();

    std::string getAreaSupervisao();

    void setAreaSupervisao(std::string areaSupervisao);


     std::string getAreaFormacao();
     void setAreaFormacao(std::string areaFormacao);
     std::string getFormacaoMaxima();
     void setFormacaoMaxima(std::string formacaoMaxima);

private:
    std::string areaSupervisao;

};

#endif