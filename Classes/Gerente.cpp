#include "Gerente.h"

Gerente::Gerente()
{

}

Gerente::~Gerente()
{

}

std::string Gerente::getAreasupervisao(){
    return this->areaSupervisao;
}

void Gerente::setAreasupervisao(std::string areaSupervisao){
   this->areaSupervisao = areaSupervisao;
}

void Gerente::aumentoSalarial(){
    this->salario+=salario*0.1;
}