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

private:

};

#endif