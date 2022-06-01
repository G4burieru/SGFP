#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.h"
#include "FolhaSalarial.h"
#include <iostream>

class Funcionario : public Data
{
public:
    Funcionario(int codigo, std::string nome, std::string endereco, std::string telefone, Data data, int designacao, float salario);
    ~Funcionario();
    virtual void aumentoSalarial();

    int getCodigo();
    std::string getNome();
    std::string getEndereco();
    std::string getTelefone();
    Data getData();
    int getDesignacao();
    float getSalarioDiario();
    FolhaSalarial getFolhaDoMes(int mes);


    void setCodigo(int codigo);
    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(std::string telefone);
    void setData(Data data);
    void setDesignacao(int designacao);
    void setSalarioDiario(float salario);

protected:
    int codigo;
    std::string nome;
    std::string endereco;
    std::string telefone;
    Data data;
    int designacao;
    float salarioDiario;
    FolhaSalarial folhaDoMes[12]; 


};

#endif