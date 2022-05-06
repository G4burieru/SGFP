#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.h"
#include <iostream>

class Funcionario
{
public:
    Funcionario();
    ~Funcionario();
    virtual void aumentoSalarial();
    virtual void calcularSalarioMensal();

protected:
    int codigo;
    std::string nome;
    std::string endereco;
    int telefone;
    Data data;
    std::string designacao;
    float salario;


};

#endif