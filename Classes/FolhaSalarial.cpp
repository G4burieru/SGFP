#include "FolhaSalarial.h"

//Contrutor que inicia todos os atributos com 0 para marcar que não foram calculados.
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

//Calcula o salario bruto do mês.
void FolhaSalarial::calculaSalario(float salarioDiario)
{
    //O valor da hora é o salario diário dividido por 8.
    float valorHora = salarioDiario/8;

    //O salário bruto é o salário diário pelos dias trabalhados somado ao valor da hora vezes dois,
    //por ser hora extra, multiplicado pela quantidade de horas extras.
    salarioMesBruto = salarioDiario*diasTrabalhados + horasExtras*valorHora*2;  
}

//Calcula o desconto da previdência.
void FolhaSalarial::calculaPrevidencia()
{
    //No caso do salário bruto ser menor ou igual a 1212 reais, o desconto será de 7,5%
    if(salarioMesBruto <= 1212)
    {
        descontoPrevidencia = salarioMesBruto*0.075;
    }else if(salarioMesBruto <= 2427.35)
    // caso for menor ou igual a 2427.35, e maior que 1212, o desconto será de 7,5% de 1212, somado
    //a 9% do salário bruto menos 1212.
    {
        descontoPrevidencia = 1212*0.075 + (salarioMesBruto-1212)*0.09;  
    }else if(salarioMesBruto <= 3641.03)
    // caso for menor ou igual a 3641.03, e maior que 2427.35, o desconto será de 7,5% de 1212, somado
    //a 9% 1215.34 somado a 12% do salário bruto menos 2427.35.
    {
        descontoPrevidencia = 1212*0.075 + 1215.34*0.09 + (salarioMesBruto-2427.35)*0.12;  
    }else if(salarioMesBruto <= 7087.22)
    // caso for menor ou igual a 7087.22, e maior que 3641.03, o desconto será de 7,5% de 1212, somado
    //a 9% 1215.34, somado a 12% de 1213.67 somado a 14% do salário bruto menos 3641.03.
    {
        descontoPrevidencia = 1212*0.075 + 1215.34*0.09 + 1213.67*0.12 + (salarioMesBruto-3641.03)*0.14;  
    }else{
        //no caso ainda do salário ser maior que 7087,22 reais, o desconto será fixo de 828,39 reais.
        descontoPrevidencia = 828.39;
    } 
}

//Calcula o desconto do imposto de renda.
void FolhaSalarial::calculaImportoRend()
{
    //salarioP é o valor do salario bruto menos o desconto da previdência.
    float salarioP = salarioMesBruto - descontoPrevidencia;

    //caso salarioP for menor ou igual a 1903.98, não haverá imposto de renda a ser retirado.
    if(salarioP <= 1903.98)
    {
        descontoImpostoRend = 0;
    }else if(salarioP <= 2826.65)
    {
        //caso o salario for menor ou igual 2826.65 e maior que 1903.98, o desconto será de
        //7,5% do salarioP menos 1903.98.
        descontoImpostoRend = (salarioP-1903.98)*0.075;  
    }else if(salarioP <= 3751.05)
    {
        //caso o salario for menor ou igual 3751.05 e maior que 2826.65, o desconto será de
        //7,5% de 922.66 somado a 15% do salarioP menos 2826.65.
        descontoImpostoRend = 922.66*0.075 + (salarioP-2826.65)*0.15;  
    }else if(salarioP <= 4664.68)
    {
        //caso o salario for menor ou igual 4664.68 e maior que 3751.05, o desconto será de
        //7,5% de 922.66, somado a 15% de 924.39, somado  a 22,5% do salarioP menos 
        // 3751.05.
        descontoImpostoRend = 922.66*0.075 + 924.39*0.15 + (salarioP-3751.05)*0.225;  
    }else{
        //No caso do salário ser maior que 4664.68 o desconto será de 7,5% de 922.66, somado a 
        //15% de 924.39, somado  a 22,5% de 913.62, somado a 27,5% dp salarioP menos 4664.68.
        descontoImpostoRend = 922.66*0.075 + 924.39*0.15 + 913.62*0.225 + (salarioP-4664.68)*0.275;
    }
}

//Calcula o salário liquido
void FolhaSalarial::caculaSalarioLiqudo()
{
    //O salário liquido é igual ao salário bruto retirando a soma dos descontos.
    salarioMesLiquido = salarioMesBruto - (descontoImpostoRend + descontoPrevidencia);
}

//Retorna o salário bruto.
float FolhaSalarial::getSalarioMesBruto()
{
    return salarioMesBruto;
}

//Retorna o salario liquido.
float FolhaSalarial::getSalarioMesLiquido()
{
    return salarioMesLiquido;
}

//Retorna o desconto da previdencia.
float FolhaSalarial::getDescontoPrevidencia()
{
    return descontoPrevidencia;
}

//Retorna retorna o desconto do imposto de renda.
float FolhaSalarial::getDescontoImpostoRend()
{
    return descontoImpostoRend;
}

//Retorna as horas extras feitas.
float FolhaSalarial::getHorasExtras()
{
    return horasExtras;
}

//Retorna retorna os dias trabalhados
int FolhaSalarial::getDiasTrabalhados()
{
    return diasTrabalhados;
}

//Atribui os dias trabalhados
void FolhaSalarial::setDiasTrabalhados(int dias)
{
    diasTrabalhados = dias;
}

//Atribui as horas extras feitas.
void FolhaSalarial::setHorasExtras(float horas)
{
    horasExtras = horas;
}

//Atribui o salario bruto.
void FolhaSalarial::setSalarioMesBruto(float salarioB)
{
    salarioMesBruto = salarioB;
}

//Atribui o salario liquido.
void FolhaSalarial::setSalarioMesLiquido(float salarioL)
{
    salarioMesLiquido = salarioL;
}

//Atribui o desconto da previdência.
void FolhaSalarial::setDescontoPrevidencia(float descontoP)
{
    descontoPrevidencia = descontoP;
}

//Atribui o desconto do imposto de renda.
void FolhaSalarial::setDescontoImpostoRend(float descontoI)
{
    descontoImpostoRend = descontoI;
}