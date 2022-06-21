#ifndef DIRETOR_H
#define DIRETOR_H

#include "Funcionario.h"
#include <iostream>

class Diretor : public Funcionario
{
public:
    Diretor(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario,std::string areaSupervisao, std::string areaFormacao);
    ~Diretor();

    void aumentoSalarial();
    
    std::string getAreaSupervisao();
    std::string getAreaFormacao();

    void setAreaSupervisao(std::string areaSupervisao);
    void setAreaFormacao(std::string areaFormacao);


    std::string getFormacaoMaxima();
    void setFormacaoMaxima(std::string formacaoMaxima);

private:
    std::string areaSupervisao;
    std::string areaFormacao;

};

#endif