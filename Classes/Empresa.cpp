#include "Empresa.h"
<<<<<<< HEAD
=======
#include <iostream>
#include <string>
>>>>>>> gabs

using namespace std;

Empresa::Empresa()
{

}

Empresa::~Empresa()
{

}

void Empresa::editarFuncionario(){
<<<<<<< HEAD
    
    int codigo;
    int mudar;
    int indice;
    string novoString;
    double novoDouble;
    int novoInt;
    int dia, mes, ano;
    Data data(0, 0, 0);

    std::cout << "Digite o codigo do funcionario que voce deseja alterar: ";
    std::cin >> codigo;

    for(int i= 0; i < funcionarios.size(); i++){
        
        if(funcionarios[i]->getCodigo() == codigo){
=======
    int indice, codigo, opcao, novoInt, novoDia, novoMes, novoAno;
    string novoString;
    float novoFloat;
    Data novaData(0, 0, 0);

    std::cout << "Insira o codigo do funcionario a se alterar: ";
    std::cin >> codigo;
    
    for(int i= 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getCodigo() == codigo)
        {
>>>>>>> gabs
            indice= i;
            break;
        }
    }

<<<<<<< HEAD
    std::cout << "Escolha o atributo que você gostaria de alterar: \n[1] Código\n[2] Data"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";

    std::cin >> mudar;

    switch(mudar){
        case 1://alterar codigo 
=======
    std::cout << "Escolha o que alterar: \n[1] Codigo\n[2] Data de Ingresso"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";
    std::cin >> opcao;

    switch(opcao){
        case 1: //alterar codigo 
>>>>>>> gabs
            std::cout << "Insira o novo codigo: ";
            std::cin >> novoInt;
            funcionarios[indice]->setCodigo(novoInt);
            break;

<<<<<<< HEAD
        case 2://alterar dataIngresso
            std::cout << "Insira a nova data (DD MM AAAA): ";
            std::cin >> dia >> mes >> ano;
            data.setDia(dia);
            data.setMes(mes);
            data.setAno(ano);
            funcionarios[indice]->setData(data);
            break;

        case 3://alterar nome
=======
        case 2: //alterar dataIngresso
            std::cout << "Insira a nova data (DD MM AAAA): ";
            std::cin >> novoDia >> novoMes >> novoAno;
            novaData.setDia(novoDia);
            novaData.setMes(novoMes);
            novaData.setAno(novoAno);
            funcionarios[indice]->setData(novaData);
            break;

        case 3: //alterar nome
>>>>>>> gabs
            std::cout << "Insira o novo nome: ";
            getline(cin, novoString);
            funcionarios[indice]->setNome(novoString);
            break;
        
<<<<<<< HEAD
        case 4://alterar endereco
            std::cout << "Insira o novo endereco: ";
=======
        case 4: //alterar endereco
            std::cout <<"Insira o novo endereco: "; // COLOCAR CEP DPS
>>>>>>> gabs
            getline(cin, novoString);
            funcionarios[indice]->setEndereco(novoString);
            break;

<<<<<<< HEAD
        case 5://alterar telefone
=======
        case 5: //alterar telefone
>>>>>>> gabs
            std::cout << "Insira o novo telefone: ";
            std::cin >> novoInt;
            funcionarios[indice]->setTelefone(novoInt);
            break;

<<<<<<< HEAD
        case 6://alterar designacao
            std::cout << "Insira a nova designacao [1] Operador, [2] Gerente, [3] Diretor ,[4] Presidente";
=======
        case 6: //alterar designacao
            std::cout << "Insira a nova designacao \n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n";
>>>>>>> gabs
            std::cin >> novoInt;
            funcionarios[indice]->setDesignacao(novoInt);
            break;

<<<<<<< HEAD
        case 7://alterar  salario
            std::cout << "Insira o novo salario";
            std::cin >> novoDouble;
            funcionarios[indice]->setSalario(novoDouble);
            break;
    }
}
void Empresa::excluirFuncionario(){

}
=======
        case 7: //alterar  salario
            std::cout << "Insira o novo salario: ";
            std::cin >> novoFloat;
            funcionarios[indice]->setSalario(novoFloat);
            break;
    }
}

void Empresa::excluirFuncionario(){
    int codigo, indice, designacao;
    bool encontrado = false, confirmacao = false;

    std::cout << "Insira o codigo do funcionario a ser excluido: ";
    std::cin >> codigo;

    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getCodigo() == codigo)
        {
            indice= i;
            encontrado = true;
            designacao=funcionarios[i]->getDesignacao();
            break;
        }
    }

    if(encontrado==false)
    {    
        std::cout << "Funcionario de codigo: "<< codigo << " nao encontrado.";
    }

    if(designacao==4||designacao==3)
    {
        throw "acesso negado";
    }
    else
    {
         std::cout << "Voce tem certeza que quer apagar o funcionário " << funcionarios[indice]->getNome() 
         << "?\n [1] Sim, excluir\n[0] Nao, manter\n";

        std::cin >> confirmacao;
        if(confirmacao==true)
        {
            funcionarios.erase(funcionarios.begin()+indice);
            cout << "Funcionario removido com sucesso!\n";
        }
    }
}

>>>>>>> gabs
void Empresa::exibirRegistro(){

}
void Empresa::exibirListaFuncionarios(){

}
void Empresa::exibirListaFuncionariosTipo(){

}
void Empresa::buscarFuncionario(){

}
void Empresa::calcularFolhaSalarial(){

}
void Empresa::folhaSalarialFuncionario(){

}
void Empresa::folhaSalarialEmpresa(){

}
void Empresa::adicionarFuncionario(){
    int codigo;
    std::string nome;
    std::string endereco;
    int telefone;
    int dia, mes, ano;
    int tipo;
    float salario;
<<<<<<< HEAD

    std::cout << "Insira o código do funcionario" << endl;
    std::cin >> codigo;
    std::cin.ignore();
    
    std::cout << "Insira o nome do funcionario:" << endl;
    std::getline(cin, nome);

    std::cout << "Insira o endereco:" << endl;
    std::getline(cin, endereco); //TRANSFORMAR EM CEP DPS

    std::cout << "Insira o telefone:" << endl;
    std::cin >> telefone;

    std::cout << "Insira a data de entrada (DD MM AAAA):" << endl;
    std::cin >> dia >> mes >> ano;

    std::cout << "Insira a designacao do funcionario(Operador[1], Gerente[2], Diretor[3], Presidente[4]" << endl;
    std::cin >> tipo;

    std::cout << "Insira o salario:" << endl;
    std::cin >> salario;
=======
    
    cout << "Insira o código do funcionario" << endl;
    cin >> codigo;
    cin.ignore();
    
    cout << "Insira o nome do funcionario:" << endl;
    getline(cin, nome);

    cout << "Insira o endereco:" << endl;
    getline(cin, endereco); //TRANSFORMAR EM CEP DPS

    cout << "Insira o telefone:" << endl;
    cin >> telefone;

    cout << "Insira a data de entrada (DD MM AAAA):" << endl;
    cin >> dia >> mes >> ano;

    cout << "Insira a designacao do funcionario\n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n" << endl;
    cin >> tipo;

    cout << "Insira o salario:" << endl;
    cin >> salario;
>>>>>>> gabs

    Data data(dia, mes, ano);
    Funcionario funcionario(codigo, nome, endereco, telefone, data, tipo, salario);

    funcionarios.push_back(funcionario);
}