#include "Endereco.h"

Endereco::Endereco()
{

}

Endereco::~Endereco()
{

}

void Endereco::parseCEP(){
    std::string url; //variavel do tipo string para salvar o url do site que ira fazer a busca do CEP
    std::string json, rua, bairro, cidade, estado; //cria-se variaveis do tipo string para salvar o arquivo json inteiro, a rua, o bairro, a cidade e o estado
    std::fstream fs; //uma variavel para o arquivo do cep
    int i = 0; //um indice para indicar qual a linha do arquivo que o programa está lendo

    url = "https://viacep.com.br/ws/" + CEP + "/json/"; //atribui a variavel url o url correspondente ao CEP digitado
    system(("wget -q -O cep.txt " + url).c_str()); //converte url para um vetor de char e faz o wget dela

    fs.open("CEP.txt", std::fstream::in); //cria um arquivo CEP.txt de leitura
    if(fs.is_open()){ //se o arquivo estiver aberto,
        while(!fs.eof()){ //será verificado se ele ainda não chegou no final
                getline(fs, json); //lerá uma linha por vez do arquivo json

                //rua
                if(i == 2){ //se o indice for 2 (rua), ele começa a leitura a partir do caractere 17 (onde começa o nome da rua) e remove os ultimos 2 caracetres (que correspondem a um '",')
                    rua = json.substr(17, json.size() - 2 - 17);
                    setRua(rua);
                }
                //bairro
                if(i == 4){ //se o indice for 4 (bairro), ele começa a leitura a partir do caractere 13 (onde começa o nome do bairro) e remove os ultimos 2 caracetres (que correspondem a um '",')
                    bairro = json.substr(13, json.size() - 2 - 13);
                    setBairro(bairro);
                }
                //cidade
                if(i == 5){ //se o indice for 5 (cidade), ele começa a leitura a partir do caractere 17 (onde começa o nome da cidade) e remove os ultimos 2 caracetres (que correspondem a um '",')
                    cidade = json.substr(17, json.size() - 2 - 17);
                    setCidade(cidade);
                }
                //estado
                if(i == 6){ //se o indice for 6 (estado), ele começa a leitura a partir do caractere 9 (onde começa o nome do estado) e remove os ultimos 2 caracetres (que correspondem a um '",')
                    estado = json.substr(9, json.size() - 2 - 9);
                    setEstado(estado);
                }
                i++; //incrementa o i para avancar uma linha na leitura do arquivo
        }
        fs.close(); //ao fim de tudo, fecha o arquivo
    }
}

Endereco::Endereco(std::string CEP, std::string numero){
    setCEP(CEP); //seta o CEP
    setNumero(numero); //seta o numero da rua

    parseCEP(); //faz a manipulação do arquivo json e o "parseamento" do CEP

}

std::string Endereco::getEstado(){
    return estado;
}
std::string Endereco::getCidade(){
    return cidade;
}
std::string Endereco::getBairro(){
    return bairro;
}
std::string Endereco::getRua(){
    return rua;
}
std::string Endereco::getCEP(){
    return CEP;
}
std::string Endereco::getNumero(){
    return numero;
}

void Endereco::setEstado(std::string estado){
    this->estado = estado;
}
void Endereco::setCidade(std::string cidade){
    this->cidade = cidade;
}
void Endereco::setBairro(std::string bairro){
    this->bairro = bairro;
}
void Endereco::setRua(std::string rua){
    this->rua = rua;
}
void Endereco::setCEP(std::string CEP){
    if(CEP.size() == 9){
        CEP.replace(5,1,"");
    }
    this->CEP = CEP;
}
void Endereco::setNumero(std::string numero){
    this->numero = numero;
}

bool Endereco::validaCEP(){
    if(estado == "" || cidade == "" || bairro == "" ){
        return false;
    }
    else return true;

}