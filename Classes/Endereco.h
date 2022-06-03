#ifndef ENDERECO_H
#define ENDERECO_H

#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Endereco
{
public:
    Endereco();
    Endereco(std::string CEP);
    ~Endereco();
    void parseCEP();

    std::string getCidade();
    std::string getBairro();
    std::string getRua();
    std::string getCEP();
    std::string getEstado();

    void setCidade(std::string cidade);
    void setBairro(std::string bairro);
    void setRua(std::string rua);
    void setCEP(std::string CEP);
    void setEstado(std::string estado);

protected:
    std::string estado, cidade, bairro, rua, CEP;

};

#endif