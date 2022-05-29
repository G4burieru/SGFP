#ifndef EMPRESA_H
#define EMPRESA_H

using namespace std;

#include "Funcionario.h"
#include <iostream>
<<<<<<< HEAD
#include <list>
=======
#include <vector>
>>>>>>> gabs

class Empresa
{
public:
    Empresa();
    ~Empresa();
    void editarFuncionario();
    void excluirFuncionario();
    void exibirRegistro();
    void exibirListaFuncionarios();
    void exibirListaFuncionariosTipo();
    void buscarFuncionario();
    void calcularFolhaSalarial();
    void folhaSalarialFuncionario();
    void folhaSalarialEmpresa();
    void adicionarFuncionario();

private:
<<<<<<< HEAD
    std::list<Funcionario> funcionarios;
=======
    std::vector<Funcionario*> funcionarios;
>>>>>>> gabs

};

#endif