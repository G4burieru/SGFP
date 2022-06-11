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
        
        cout << "O que deseja fazer agora?\n[1] Adicionar Funcionario\n[2] excluir funcionario\n[3] editar funcionario\n[4] exibir lista de funcionarios\n[5] exibir lista de um tipo específica de funcionario \n[6] Calcular folha salarial \n[7] Exibir folha da empresa \n[8] exibir folha de um funcionario expecifico \n[9] Aumentar todos os salarios, eba \n[10] Buscar Funcionario\n[11] Sair\n";

        cin >> fazer;

        switch(fazer)
        {
        case 1:
            try
            {
                emp.adicionarFuncionario();
            }
            catch(int x)
            {
                if(x==3)
                {
                    cout << "Codigo ja utilizado! ERROR " << x << "\n" << endl;
                }
                else if(x==4)
                {
                   cout << "Telefone ja utilizado! ERROR " << x << "\n" << endl; 
                }
                else if(x==5)
                {
                    cout << "Telefone invalido! ERROR " << x << "\n" << endl;
                }
                else if(x==6)
                {
                    cout << "Data invalida! ERROR " << x << "\n" << endl;
                }
                else if(x==7)
                {
                    cout << "Designação invalida! ERROR " << x << "\n" << endl;
                }
                else if(x==8)
                {
                    cout << "Salario invalido! ERROR " << x << "\n" << endl;
                }
            }
            break;

        case 2:
            try
            {
            emp.excluirFuncionario();
            }
            catch (int x)
            {
                cout << "Acesso Negado! ERROR " << x << endl;
            }
            break;
        
        case 3:
        try
        {
            emp.editarFuncionario();
        }
        catch(int x)
        {
            if (x==1)
            {
               std::cout << "Erro "<< x <<" Not Found!" << endl;
            }
        }
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
        try
        {
            emp.ImprimeFolhaSalarialFuncionario();
        }
        catch(int x)
        {
            if (x==1)
            {
               std::cout << "Erro "<< x <<" Not Found!" << endl;
            }
        }
            break;

        case 9:
            emp.aumentaTodosSalarios();
            break;

        case 10:
        try
        {
            emp.buscarFuncionario();
        }
        catch(int x)
        {
            if(x==1)
            {
                std::cout << "Erro "<< x <<" Not Found!" << endl;
            }
            else if(x==6)
            {
                cout << "Data invalida! ERROR " << x << "\n" << endl;
            }
        }
            break;

        case 11:
            return 0;

        default:
            cout << "Opção invalida!" << endl;
        }
    }
    
}