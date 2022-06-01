#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;

Empresa::Empresa()
{
    for(int i = 0; i < 12; i++)
    {
        folhaSalarialCalculada[i] = 0;
    }

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
    
    indice = buscarFuncionario(codigo);

    std::cout << "Escolha o que alterar: \n[1] Codigo\n[2] Data de Ingresso"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";
    std::cin >> opcao;
    cin.ignore();

    switch(opcao)
    {
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
            getline(cin, novoString);
            funcionarios[indice]->setTelefone(novoString);
            break;

        case 6: //alterar designacao
            std::cout << "Insira a nova designacao \n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n";
            std::cin >> novoInt;
            funcionarios[indice]->setDesignacao(novoInt);
            break;

        case 7: //alterar  salario
            std::cout << "Insira o novo diário salario: ";
            std::cin >> novoFloat;
            funcionarios[indice]->setSalarioDiario(novoFloat);
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
            std::cout << "Funcionario removido com sucesso!\n";
        }
    }
}

void Empresa::exibirRegistro(int indice){
    string tipo[4]{"Operador", "Gerente", "Diretor", "Presidente"};
    std::cout << "Nome: " << funcionarios[indice]->getNome() << endl;
    std::cout << "Codigo: " << funcionarios[indice]->getCodigo() << endl;
    std::cout << "Designação: " << tipo[funcionarios[indice]->getDesignacao()-1] << endl;
    std::cout << "Data de Entrada: " << funcionarios[indice]->getData().getDia() << "/" << 
    funcionarios[indice]->getData().getMes() << "/" << funcionarios[indice]->getData().getAno() << endl;
    std::cout << "Telefone: " << funcionarios[indice]->getTelefone() << endl;
    std::cout << "SalarioDiario: " << funcionarios[indice]->getSalarioDiario() << endl;
    std::cout << "Endereco: " << funcionarios[indice]->getEndereco() << endl;
}

void Empresa::exibirListaFuncionarios()
{
    for(int i = 0; i < funcionarios.size(); i++){
        std::cout << "----------------------------------------------\n";
        exibirRegistro(i);
    }
    std::cout << "----------------------------------------------\n";

}

int Empresa::buscarFuncionario(int codigo)
{
    int indice;
    bool encontrado;
    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getCodigo() == codigo)
        {
            indice= i;
            encontrado = true;
            return indice;
        }
    }

    if(encontrado==false)
    {    
        std::cout << "Funcionario de codigo: "<< codigo << " nao encontrado.";
    }
}
void Empresa::calcularFolhaSalarial()
{
    int mes;

    std::cout << "Digite o numero do mes que voce deseja calcular a folha salarial:\n";
    cin >> mes;

    if(folhaSalarialCalculada[mes] == 1){
        std::cout << "A folha salarial desse mes já foi calculada.";
        // colocar excepiton ------------------------------------------------------------------------
    }else{
        std::cout << "Calculando folha salarial...";

    }

    for(int i = 0; i < funcionarios.size(); i++){
        funcionarios[i]->getFolhaDoMes(mes).geraDiasEHoras();
        funcionarios[i]->getFolhaDoMes(mes).calculaFolha(funcionarios[i]->getSalarioDiario());
    }

    std::cout << "Folha salarial calculada com sucesso!";
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
    std::string telefone;
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
    getline(cin, telefone);

    cout << "Insira a data de entrada (DD MM AAAA):" << endl;
    cin >> dia >> mes >> ano;

    cout << "Insira a designacao do funcionario\n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n" << endl;
    cin >> tipo;

    cout << "Insira o salario diário:" << endl;
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