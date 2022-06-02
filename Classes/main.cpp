#include <iostream>
#include "Funcionario.h"
#include "Empresa.h"
#include "Data.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"

int main()
{
    Empresa emp;

    for(int i = 0; i < 4; i++)
    {
        emp.adicionarFuncionario();
    }
    
    emp.aumentaTodosSalarios();
    emp.exibirListaFuncionarios();
    
}