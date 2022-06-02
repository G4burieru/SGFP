#ifndef EMPRESA_H
#define EMPRESA_H

using namespace std;

#include "Funcionario.h"
#include <iostream>
#include <vector>

class Empresa
{
public:
    Empresa();
    ~Empresa();
    void editarFuncionario();
    void excluirFuncionario();
    void exibirListaFuncionarios();
    void exibirListaFuncionariosTipo();
    void calcularFolhaSalarial();
    void folhaSalarialFuncionario();
    void folhaSalarialEmpresa();
    void adicionarFuncionario();
    void aumentaTodosSalarios();


private:
    std::vector<Funcionario*> funcionarios;
    bool folhaSalarialCalculada[12];
    int getFuncionario(long codigo);
    void exibirRegistro(int indice);
};

#endif