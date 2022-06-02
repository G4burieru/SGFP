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
    void exibirRegistro(int indice);
    void exibirListaFuncionarios();
    void exibirListaFuncionariosTipo();
    int buscarFuncionario(long codigo);
    void calcularFolhaSalarial();
    void folhaSalarialFuncionario();
    void folhaSalarialEmpresa();
    void adicionarFuncionario();
    void aumentaTodosSalarios();


private:
    std::vector<Funcionario*> funcionarios;
    bool folhaSalarialCalculada[12];
};

#endif