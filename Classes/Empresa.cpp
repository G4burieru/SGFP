#include "Empresa.h"

Empresa::Empresa()
{

}

Empresa::~Empresa()
{

}

void Empresa::editarFuncionario(){

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

    cout << "Insira a designacao do funcionario(Operador[1], Gerente[2], Diretor[3], Presidente[4]" << endl;
    cin >> tipo;

    cout << "Insira o salario:" << endl;
    cin >> salario;

    Data data(dia, mes, ano);
    Funcionario funcionario(codigo, nome, endereco, telefone, data, tipo, salario);

    funcionarios.push_back(funcionario);
}