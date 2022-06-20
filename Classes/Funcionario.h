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
    void setEndereco(std::string CEP, std::string numeroRua);
    void setTelefone(std::string telefone);
    void setData(Data data);
    void setDesignacao(int designacao);
    void setSalarioDiario(float salario);
    
    void calculaFolhaMes(float SalarioDiario, int mes);
    void imprimirFolhaMes(int mes);
    void imprimirFolhaAnual();
    float getSalarioAno();
    float getImpostoRendAno();
    float getPrevidenciaAno();
    int getDiasTrabalhadosMes();

    void setDiasTrabalhadosMes(int dias, int mes);
    void setHorasExtrasMes(float horas, int mes);
    void setSalarioMesBrutoMes(float salarioB, int mes);
    void setSalarioMesLiquidoMes(float salarioL, int mes);
    void setDescontoPrevidenciaMes(float descontoP, int mes);
    void setdescontoImpostoRendMes(float descontoI, int mes);
    
    virtual std::string getAreaSupervisao();
    virtual void setAreaSupervisao(std::string areaSupervisao);
    virtual std::string getAreaFormacao();
    virtual void setAreaFormacao(std::string areaFormacao);
    virtual std::string getFormacaoMaxima();
    virtual void setFormacaoMaxima(std::string formacaoMaxima);
    FolhaSalarial folhaDoMes[12]; 

protected:
    long codigo;
    std::string nome;
    std::string CEP, numeroRua;
    Endereco endereco;
    std::string telefone;
    Data data;
    int designacao;
    float salarioDiario;

};

#endif