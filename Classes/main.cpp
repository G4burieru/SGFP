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
        
        cout << "O que deseja fazer agora?\n[1] Adicionar Funcionario\n[2] excluir funcionario\n[3] editar funcionario\n[4] exibir lista de funcionarios\n[5] exibir lista de um tipo específica de funcionario \n[6] Calcular folha salarial \n[7] Exibir folha da empresa \n[8] exibir folha de um funcionario expecifico \n[9] Aumentar todos os salarios, eba \n[10] sair\n";

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
        default:
            return 0;
        }
    }
    
}