#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"
#include <iostream>

class Operador : public Funcionario
{
public:
    Operador(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario);
    ~Operador();

    void aumentoSalarial();


    std::string getAreaSupervisao();
     void setAreaSupervisao(std::string areaSupervisao);
     std::string getAreaFormacao();
     void setAreaFormacao(std::string areaFormacao);
     std::string getFormacaoMaxima();
     void setFormacaoMaxima(std::string formacaoMaxima);

private:

};

#endif