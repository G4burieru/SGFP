#include <iostream>
#include "Funcionario.h"
#include "Empresa.h"
#include "Data.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"
#include <Windows.h>

using namespace std;

void telaErro(int x)
{

    system("CLS");
    if (x==1)
    {
        std::cout << "Erro "<< x <<" Not Found!" << endl;
    }
    else if(x==3)
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
    else if(x==9)
    {
        cout<< "Opção Invalida! ERROR " << x << "\n" << endl;
    }
    system("PAUSE");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
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
            if( x==9)
            {
                cout<< "Opção Invalida! ERROR " << x << "\n" << endl;
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
            //ALTEREI
            emp.salvarArquivo();
            return 0;

        default:
            //------------------------------------exception opcao invalida------------------------------------------
            cout << "Opção inválida!\n\n----------------------------------------------\n" << endl;
        }
    }
    
}