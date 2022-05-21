#ifndef DATA_H
#define DATA_H

#pragma once

class Data
{
public:
    Data();
    Data(int dia, int mes, int ano);
    ~Data();
    int getDia();
    int getMes();
    int getAno();

    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);

protected:
    int dia;
    int mes;
    int ano;

};

#endif