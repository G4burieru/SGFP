#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;

Empresa::Empresa()
{

}

Empresa::~Empresa()
{

}

void Empresa::editarFuncionario()
{
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
            indice= i;
            break;
        }
    }

    std::cout << "Escolha o que alterar: \n[1] Codigo\n[2] Data de Ingresso"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";
    std::cin >> opcao;

    switch(opcao){
        case 1: //alterar codigo 
            std::cout << "Insira o novo codigo: ";
            std::cin >> novoInt;
            funcionarios[indice]->setCodigo(novoInt);
            break;

        case 2: //alterar dataIngresso
            std::cout << "Insira a nova data (DD MM AAAA): ";
            std::cin >> novoDia >> novoMes >> novoAno;
            novaData.setDia(novoDia);
            novaData.setMes(novoMes);
            novaData.setAno(novoAno);
            funcionarios[indice]->setData(novaData);
            break;

        case 3: //alterar nome
            std::cout << "Insira o novo nome: ";
            getline(cin, novoString);
            funcionarios[indice]->setNome(novoString);
            break;
        
        case 4: //alterar endereco
            std::cout <<"Insira o novo endereco: "; // COLOCAR CEP DPS
            getline(cin, novoString);
            funcionarios[indice]->setEndereco(novoString);
            break;

        case 5: //alterar telefone
            std::cout << "Insira o novo telefone: ";
            std::cin >> novoInt;
            funcionarios[indice]->setTelefone(novoInt);
            break;

        case 6: //alterar designacao
            std::cout << "Insira a nova designacao \n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n";
            std::cin >> novoInt;
            funcionarios[indice]->setDesignacao(novoInt);
            break;

        case 7: //alterar  salario
            std::cout << "Insira o novo salario: ";
            std::cin >> novoFloat;
            funcionarios[indice]->setSalario(novoFloat);
            break;
    }
}

void Empresa::excluirFuncionario()
{
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

void Empresa::exibirRegistro(int indice)
{

}
void Empresa::exibirListaFuncionarios()
{
    for(int i = 0; i < funcionarios.size(); i++){
        std::cout << "----------------------------------------------\n";
        exibirRegistro(i);
    }
    std::cout << "----------------------------------------------\n";

}

void Empresa::exibirListaFuncionariosTipo()
{
    int designacao;
    std::cout << "Insira a designacao dos funcionarios a serem exibidos \n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n";
    std::cin >> designacao;

    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getDesignacao() == designacao)
        {
            std::cout << "----------------------------------------------\n"; 
            exibirRegistro(i);
        }
    }

    std::cout << "----------------------------------------------\n";
}

void Empresa::buscarFuncionario()
{

}
void Empresa::calcularFolhaSalarial(){

}
void Empresa::folhaSalarialFuncionario() //imprime a folha salarial de um único funcionário.
{

}
void Empresa::folhaSalarialEmpresa() //imprime a folha salarial da empresa.
{

}
void Empresa::adicionarFuncionario(){
    int codigo;
    std::string nome;
    std::string endereco;
    int telefone;
    int dia, mes, ano;
    int tipo;
    float salario;
    
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

    Data data(dia, mes, ano);
    Funcionario *funcionario = new Funcionario(codigo, nome, endereco, telefone, data, tipo, salario);

    funcionarios.push_back(funcionario);
}

void Empresa::aumentaTodosSalarios(){
    for(int i = 0; i < funcionarios.size(); i++){
        funcionarios[i]->aumentoSalarial();
    }
    std::cout << "Salarios aumentados com sucesso!";
}