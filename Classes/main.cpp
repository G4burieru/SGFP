#include <iostream>
#include "Funcionario.h"
#include "Empresa.h"
#include "Data.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"

using namespace std;

int main()
{
    Empresa emp;
    int fazer;

    cout << "Bem vindo ao programa, essa é uma versão teste ^-^\n";

    while(1)
    {
        
        cout << "O que deseja fazer agora?\n\n"
        "[01] Adicionar Funcionario\n[02] Excluir funcionario\n[03] Editar funcionario\n[04] Exibir lista de funcionarios\n"
        "[05] Exibir lista de um tipo específica de funcionario\n[06] Calcular folha salarial\n[07] Exibir folha da empresa\n"
        "[08] Exibir folha de um funcionario expecifico\n[09] Aumentar todos os salarios, eba\n"
        "[10] Buscar Funcionario\n[11] Sair\n";

        cin >> fazer;

        switch(fazer)
        {
        case 1:
            emp.adicionarFuncionario();
            break;

        case 2:
            emp.excluirFuncionario();
            break;
        
        case 3:
            emp.editarFuncionario();
            break;

        case 4:
            emp.exibirListaFuncionarios();
            break;

        case 5:
            emp.exibirListaFuncionariosTipo();
            break;

        case 6:
            emp.calcularFolhaSalarial();
            break;

        case 7:
            emp.ImprimeFolhaSalarialEmpresa();
            break;
        
        case 8:
            emp.ImprimeFolhaSalarialFuncionario();
            break;

        case 9:
            emp.aumentaTodosSalarios();
            break;

        case 10:
            emp.buscarFuncionario();
            break;

        case 11:
            //ALTEREI
            emp.salvarArquivo();
            return 0;

        default:
            //------------------------------------exception opcao invalida------------------------------------------
            cout << "Opção inválida!\n\n----------------------------------------------\n" << endl;
        }
    }
    
}