#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.h"
#include <iostream>

class Funcionario : public Data
{
public:
    Funcionario(int codigo, std::string nome, std::string endereco, int telefone, Data data, int designacao, float salario);
    ~Funcionario();
    virtual void aumentoSalarial();
    virtual void calcularSalarioMensal();

    int getCodigo();
    std::string getNome();
    std::string getEndereco();
    int getTelefone();
    Data getData();
    int getDesignacao();
    float getSalario();

    void setCodigo(int codigo);
    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(int telefone);
    void setData(Data data);
    void setDesignacao(int designacao);
    void setSalario(float salario);

protected:
    int codigo;
    std::string nome;
    std::string endereco;
    int telefone;
    Data data;
    int designacao;
    float salario;


};

#endif