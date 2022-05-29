#include "Empresa.h"

using namespace std;

Empresa::Empresa()
{

}

Empresa::~Empresa()
{

}

void Empresa::editarFuncionario(){
    
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
            indice= i;
            break;
        }
    }

    std::cout << "Escolha o atributo que você gostaria de alterar: \n[1] Código\n[2] Data"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";

    std::cin >> mudar;

    switch(mudar){
        case 1://alterar codigo 
            std::cout << "Insira o novo codigo: ";
            std::cin >> novoInt;
            funcionarios[indice]->setCodigo(novoInt);
            break;

        case 2://alterar dataIngresso
            std::cout << "Insira a nova data (DD MM AAAA): ";
            std::cin >> dia >> mes >> ano;
            data.setDia(dia);
            data.setMes(mes);
            data.setAno(ano);
            funcionarios[indice]->setData(data);
            break;

        case 3://alterar nome
            std::cout << "Insira o novo nome: ";
            getline(cin, novoString);
            funcionarios[indice]->setNome(novoString);
            break;
        
        case 4://alterar endereco
            std::cout << "Insira o novo endereco: ";
            getline(cin, novoString);
            funcionarios[indice]->setEndereco(novoString);
            break;

        case 5://alterar telefone
            std::cout << "Insira o novo telefone: ";
            std::cin >> novoInt;
            funcionarios[indice]->setTelefone(novoInt);
            break;

        case 6://alterar designacao
            std::cout << "Insira a nova designacao [1] Operador, [2] Gerente, [3] Diretor ,[4] Presidente";
            std::cin >> novoInt;
            funcionarios[indice]->setDesignacao(novoInt);
            break;

        case 7://alterar  salario
            std::cout << "Insira o novo salario";
            std::cin >> novoDouble;
            funcionarios[indice]->setSalario(novoDouble);
            break;
    }
}
void Empresa::excluirFuncionario(){

}
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

    Data data(dia, mes, ano);
    Funcionario funcionario(codigo, nome, endereco, telefone, data, tipo, salario);

    funcionarios.push_back(funcionario);
}