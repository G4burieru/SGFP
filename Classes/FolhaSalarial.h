#ifndef FOLHASALARIAL_H
#define FOLHASALARIAL_H

#pragma once

class FolhaSalarial
{
public:
    FolhaSalarial();
    ~FolhaSalarial();
    void geraDiasEHoras();
    void calculaSalario(float SalarioDiario);
    void calculaFolha(float SalarioDiario);
    void calculaPrevidencia();
    void calculaImportoRend();
    void caculaSalarioLiqudo();

    float getSalarioMesBruto();
    float getSalarioMesLiquido();
    float getDescontoPrevidencia();
    float getDescontoImpostoRend();

private:
    int diasTrabalhados;
    float horasExtras, salarioMesBruto, salarioMesLiquido, descontoPrevidencia, descontoImpostoRend;

};

#endif