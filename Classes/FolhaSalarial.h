#ifndef FOLHASALARIAL_H
#define FOLHASALARIAL_H

#pragma once

class FolhaSalarial
{
public:
    FolhaSalarial();
    ~FolhaSalarial();

    void calculaSalario(float SalarioDiario);
    void calculaPrevidencia();
    void calculaImportoRend();
    void caculaSalarioLiqudo();

    float getSalarioMesBruto();
    float getSalarioMesLiquido();
    float getDescontoPrevidencia();
    float getDescontoImpostoRend();

    void setDiasTrabalhados(int dias);
    void setHorasExtras(float horas);
    float getHorasExtras();
    int getDiasTrabalhados();

private:
    int diasTrabalhados;
    float horasExtras, salarioMesBruto, salarioMesLiquido, descontoPrevidencia, descontoImpostoRend;

};

#endif