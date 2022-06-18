#include "FolhaSalarial.h"

FolhaSalarial::FolhaSalarial()
{
    diasTrabalhados = 0;
    horasExtras = 0;
    salarioMesBruto = 0;
    salarioMesLiquido = 0;
    descontoPrevidencia = 0;
    descontoImpostoRend = 0;
}   

FolhaSalarial::~FolhaSalarial()
{

}

void FolhaSalarial::calculaSalario(float salarioDiario)
{
    float valorHora = salarioDiario/8;

    salarioMesBruto = salarioDiario*diasTrabalhados + horasExtras*valorHora*2;  
}

void FolhaSalarial::calculaPrevidencia()
{
    if(salarioMesBruto <= 1212)
    {
        descontoPrevidencia = salarioMesBruto*0.075;
    }else if(salarioMesBruto <= 2427.35)
    {
        descontoPrevidencia = 1212*0.075 + (salarioMesBruto-1212)*0.09;  
    }else if(salarioMesBruto <= 3641.03)
    {
        descontoPrevidencia = 1212*0.075 + 1215.34*0.09 + (salarioMesBruto-2427.35)*0.12;  
    }else if(salarioMesBruto <= 7087.22)
    {
        descontoPrevidencia = 1212*0.075 + 1215.34*0.09 + 1213.67*0.12 + (salarioMesBruto-3641.03)*0.14;  
    }else{
        descontoPrevidencia = 828.39;
    } 
}

void FolhaSalarial::calculaImportoRend()
{
    float salarioP = salarioMesBruto - descontoPrevidencia;

    if(salarioP <= 1903.98)
    {
        descontoImpostoRend = 0;
    }else if(salarioP <= 2826.65)
    {
        descontoImpostoRend = (salarioP-1903.98)*0.075;  
    }else if(salarioP <= 3751.05)
    {
        descontoImpostoRend = 922.66*0.075 + (salarioP-2826.65)*0.15;  
    }else if(salarioP <= 4664.68)
    {
        descontoImpostoRend = 922.66*0.075 + 924.39*0.15 + (salarioP-3751.05)*0.225;  
    }else{
        descontoImpostoRend = 922.66*0.075 + 924.39*0.15 + 913.62*0.225 + (salarioP-4664.68)*0.275;
    }
}

void FolhaSalarial::caculaSalarioLiqudo()
{
    salarioMesLiquido = salarioMesBruto - (descontoImpostoRend + descontoPrevidencia);
}

float FolhaSalarial::getSalarioMesBruto()
{
    return salarioMesBruto;
}

float FolhaSalarial::getSalarioMesLiquido()
{
    return salarioMesLiquido;
}

float FolhaSalarial::getDescontoPrevidencia()
{
    return descontoPrevidencia;
}

float FolhaSalarial::getDescontoImpostoRend()
{
    return descontoImpostoRend;
}

float FolhaSalarial::getHorasExtras()
{
    return horasExtras;
}

int FolhaSalarial::getDiasTrabalhados()
{
    return diasTrabalhados;
}

void FolhaSalarial::setDiasTrabalhados(int dias){
    diasTrabalhados = dias;
}
void FolhaSalarial::setHorasExtras(float horas){
    horasExtras = horas;
}

void lerFolha(){

}
void salvarFolha(){

}