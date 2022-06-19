#ifndef EMPRESA_H
#define EMPRESA_H

using namespace std;

#include "Funcionario.h"
#include <iostream>
#include <vector>
#include <string>

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
    void ImprimeFolhaSalarialFuncionario();
    void ImprimeFolhaSalarialEmpresa();
    void adicionarFuncionario();
    void aumentaTodosSalarios();
    void buscarFuncionario();
    std::string padronizaTelefone(long long telefonlong);
    bool validaData(int dia, int mes, int ano);
    void salvarFuncionario();
    void lerFuncionario();

    void salvarFolha(int j);
    void lerFolha();

protected:
    void setDiasEHorasAleatorios(int mes, int indice);
    int getIntAleatorio(int maximo);
    int getFuncionarioPorCodigo(long codigo);
    int getFuncionarioPorNome(std::string nome);
    void exibirRegistro(int indice);

private:
    std::vector<Funcionario*> funcionarios;
    bool folhaSalarialCalculada[12];
    
};

#endif