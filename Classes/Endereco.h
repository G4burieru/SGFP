#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Endereco
{
public:
    Endereco();
    Endereco(std::string CEP, std::string numero);
    ~Endereco();
    void parseCEP();

    std::string getEstado();
    std::string getCidade();
    std::string getBairro();
    std::string getRua();
    std::string getCEP();
    std::string getNumero();
    

    void setEstado(std::string estado);
    void setCidade(std::string cidade);
    void setBairro(std::string bairro);
    void setRua(std::string rua);
    void setCEP(std::string CEP);
    void setNumero(std::string numero);
    bool validaCEP();

protected:
    std::string estado, cidade, bairro, rua, CEP, numero;

};

#endif