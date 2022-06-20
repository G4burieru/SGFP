#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <iostream>

class Presidente : public Funcionario
{
public:
    Presidente(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiarios, std::string areaFormacao, std::string formacaoMaxima);
    ~Presidente();

    void aumentoSalarial();

    std::string getAreaFormacao();
    std::string getFormacaoMaxima();

    void setAreaFormacao(std::string areaFormacao);
    void setFormacaoMaxima(std::string formacaoMaxima);

         std::string getAreaSupervisao();
     void setAreaSupervisao(std::string areaSupervisao);


private:
    std::string areaFormacao;
    std::string formacaoMaxima;

};

#endif