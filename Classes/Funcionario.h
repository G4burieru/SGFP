#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.h"
#include "FolhaSalarial.h"
#include "Endereco.h"
#include <iostream>

class Funcionario : public Data
{
public:
    Funcionario(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, int designacao, float salario);
    ~Funcionario();
    virtual void aumentoSalarial();

    long getCodigo();
    std::string getNome();
    Endereco getEndereco();
    std::string getTelefone();
    Data getData();
    int getDesignacao();
    float getSalarioDiario();
    FolhaSalarial getFolhaDoMes(int mes);

    void setCodigo(long codigo);
    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(std::string telefone);
    void setData(Data data);
    void setDesignacao(int designacao);
    void setSalarioDiario(float salario);
    void setDiasTrabalhadosMes(int dias, int mes);
    void setHorasExtrasMes(float horas, int mes);
    void calculaFolhaMes(float SalarioDiario, int mes);
    void imprimirFolhaMes(int mes);
    void imprimirFolhaAnual();
    float getSalarioAno();
    float getImpostoRendAno();
    float getPrevidenciaAno();

protected:
    long codigo;
    std::string nome;
    Endereco endereco;
    std::string telefone;
    Data data;
    int designacao;
    float salarioDiario;
    FolhaSalarial folhaDoMes[12]; 


};

#endif