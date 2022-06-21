#include <iostream>
#include <Windows.h>
#include "Empresa.h"
#include "Menu.h"

using namespace std;

void Menu::telaErro(int x)
{
    std::system("CLS");
    if (x==1)
    {
        cout << "Erro "<< x <<" Not Found!" << endl;
    }
    else if(x==2)
    {
        cout << "Acesso Negado! ERROR " << x << "\n" << endl;
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
    else if(x==10)
    {
        cout << "Folha do Mês não Calculada! ERROR " << x << "\n" << endl;
    }
    else if(x==11)
    {
        cout << "Folha do Mês Já Calculada! ERROR " << x << "\n" << endl;
    }
    else if(x==12)
    {
        cout << "CEP Inválido! ERROR " << x << "\n" << endl;
    }
    system("PAUSE");
}


int Menu::abrirmenu()
{
    SetConsoleOutputCP(CP_UTF8);
    Empresa emp;
    int fazer;

    emp.lerFuncionario();
    emp.lerFolha();
    system("CLS");

    std::cout << "Bem vindo ao programa!\n";
    Sleep(2000);

    while(1)
    {
        system("CLS");
        cout << "O que deseja fazer agora?\n\n"
        "[01] Adicionar funcionário\n[02] Excluir funcionário\n[03] Editar funcionário\n[04] Exibir lista de funcionários\n"
        "[05] Exibir lista de um tipo específico de funcionário\n[06] Calcular folha salarial\n[07] Exibir folha da empresa\n"
        "[08] Exibir folha de um funcionário específico\n[09] Aumentar todos os salários\n"
        "[10] Buscar funcionário\n[11] Sair\n";

        cin >> fazer;

        switch(fazer)
        {
        case 1:
            system("CLS");
            try
            {  
                emp.adicionarFuncionario();
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;

        case 2:
            system("CLS");
            try
            {
            emp.excluirFuncionario();
            }
            catch (int x)
            {
                telaErro(x);
            }
            break;
        
        case 3:
            system("CLS");
            try
            {
                emp.editarFuncionario();
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;

        case 4:
            system("CLS");
            emp.exibirListaFuncionarios();
            system("PAUSE");
            break;

        case 5:
            system("CLS");
            emp.exibirListaFuncionariosTipo();
            system("PAUSE");
            break;

        case 6:
            system("CLS");
            try
            {
                emp.calcularFolhaSalarial();
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;

        case 7:
            system("CLS");
            try
            {
            emp.ImprimeFolhaSalarialEmpresa();
            system("PAUSE");
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;
        
        case 8:
            system("CLS");
            try
            {
                emp.ImprimeFolhaSalarialFuncionario();
                system("PAUSE");
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;

        case 9:
            system("CLS");
            emp.aumentaTodosSalarios();
            Sleep(1500);
            break;

        case 10:
            system("CLS");
            try
            {
                emp.buscarFuncionario();
                system("PAUSE");
            }
            catch(int x)
            {
                telaErro(x);
            }
            break;

        case 11:
            return 0;

        default:
            system("CLS");
            cout << "Opção inválida!" << endl;
            Sleep(1500);
        }
    }
    
}