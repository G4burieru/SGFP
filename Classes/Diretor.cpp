#include "Diretor.h"

Diretor::Diretor()
{

}

Diretor::~Diretor()
{

}

std::string Diretor::getAreasupervisao(){
    return this->areaSupervisao;
}

std::string Diretor::getAreaformacao(){
    return this->areaFormacao;
}

void Diretor::setAreasupervisao(std::string areaSupervisao){
   this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaformacao(std::string areaFormacao){
   this->areaFormacao = areaFormacao;
}

void Diretor::aumentoSalarial(){
    this->salario+=salario*0.2;
}