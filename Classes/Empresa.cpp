#include "Empresa.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Endereco.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

#define ANOATUAL 2022

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
    int indice, codigo, opcao, novoInt, novoDia, novoMes, novoAno, tipo;
    long novoLong;
    std::string novoString, novoString2;
    std::string novoCEP, novoNumeroCasa;
    float novoFloat;
    long long telefonlong;
    Data novaData(0, 0, 0);
    bool dataValida = false;
    Funcionario* funcionario;

    std::cout << "Insira o codigo do funcionario a se alterar: ";
    std::cin >> codigo;
    
    indice = getFuncionarioPorCodigo(codigo);

    std::cout << "Escolha o que alterar: \n[01] Codigo\n[02] Data de Ingresso"
    "\n[03] Nome\n[04] Endereco\n[05] Telefone\n[06] Designacao\n[07] Area de Supervisão, Formação ou Formação Máxima\n[08] Salario\n[00] Voltar\n";
    std::cin >> opcao;
    std::cin.ignore();

    switch(opcao)
    {
        case 1: //alterar codigo 
            std::cout << "Insira o novo codigo: ";
            std::cin >> novoLong;
            for (int i = 0; i < funcionarios.size(); i++)
            {
                if(novoLong==funcionarios[i]->getCodigo())
                {
                    throw 3;
                }
            }
            funcionarios[indice]->setCodigo(novoLong);
            break;

        case 2: //alterar dataIngresso
            std::cout << "Insira a nova data (DD MM AAAA): ";
            std::cin >> novoDia >> novoMes >> novoAno;
            dataValida = validaData(novoDia, novoMes, novoAno);
            novaData.setDia(novoDia);
            novaData.setMes(novoMes);
            novaData.setAno(novoAno);
            if(dataValida==true)
            {
                funcionarios[indice]->setData(novaData);
            }
            break;

        case 3: //alterar nome
            std::cout << "Insira o novo nome: ";
            getline(std::cin, novoString);
            funcionarios[indice]->setNome(novoString);
            break;
        
        case 4: //alterar endereco
            std::cout <<"Insira o novo CEP: ";
            getline(std::cin, novoCEP);
            std::cout <<"Insira o novo número da casa: ";
            getline(std::cin, novoNumeroCasa);
            funcionarios[indice]->setEndereco(novoCEP, novoNumeroCasa);
            break;

        case 5: //alterar telefone
            std::cout << "Insira o novo telefone: (somente numeros, com o ddd)";
            std::cin >> telefonlong;
            novoString = padronizaTelefone(telefonlong);
            for (int i = 0; i < funcionarios.size(); i++)
            {
                if(novoString ==funcionarios[i]->getTelefone())
                {
                    throw 4;
                }
            }
            funcionarios[indice]->setTelefone(novoString);
            break;

        case 6: //alterar designacao
            std::cout << "Insira a nova designação \n[01] Operador\n[02] Gerente\n[03] Diretor\n[04] Presidente\n";
            std::cin >> tipo;
            std::cin.ignore();

            switch (tipo)
            {
                case 1:
                    funcionario = new Operador(funcionarios[indice]->getCodigo(), funcionarios[indice]->getNome(), funcionarios[indice]->getEndereco(), funcionarios[indice]->getTelefone(), funcionarios[indice]->getData(), funcionarios[indice]->getSalarioDiario());
                    break;
                
                case 2:
                    std::cout << "Insira a Área de Supervisão: " << std::endl;
                    getline(std::cin, novoString);
                    funcionario = new Gerente(funcionarios[indice]->getCodigo(), funcionarios[indice]->getNome(), funcionarios[indice]->getEndereco(), funcionarios[indice]->getTelefone(), funcionarios[indice]->getData(), funcionarios[indice]->getSalarioDiario(), novoString);
                    break;
                
                case 3:
                    std::cout << "Insira a Área de Supervisão: " << std::endl;
                    getline(std::cin, novoString);
                    std::cout << "Insira a Área de Formação: " << std::endl;
                    getline(std::cin, novoString2);
                    funcionario = new Diretor(funcionarios[indice]->getCodigo(), funcionarios[indice]->getNome(), funcionarios[indice]->getEndereco(), funcionarios[indice]->getTelefone(), funcionarios[indice]->getData(), funcionarios[indice]->getSalarioDiario(), novoString, novoString2);
                    break;
                
                case 4:
                    std::cout << "Insira a Área de Formação: " << std::endl;
                    getline(std::cin, novoString);
                    std::cout << "Insira a Formação Máxima: " << std::endl;
                    getline(std::cin, novoString2);
                    funcionario = new Presidente(funcionarios[indice]->getCodigo(), funcionarios[indice]->getNome(), funcionarios[indice]->getEndereco(), funcionarios[indice]->getTelefone(), funcionarios[indice]->getData(), funcionarios[indice]->getSalarioDiario(), novoString, novoString2);
                    break;

                default:
                    throw 9; // opcao invalida
            }

            funcionarios.push_back(funcionario);
            funcionarios.erase(funcionarios.begin()+indice);
            salvarFuncionario();
            break;

        case 7: //alterar area de supervisao, formacao ou formacao maxima
            if(funcionarios[indice]->getDesignacao() == 2){
                std::cout << "Insira a nova Área de Supervisão: " << std::endl;
                getline(std::cin, novoString);
                funcionarios[indice]->setAreaSupervisao(novoString);
            }
            else if(funcionarios[indice]->getDesignacao() == 3){
                    std::cout << "Insira a nova Área de Supervisão: " << std::endl;
                    getline(std::cin, novoString);
                    funcionarios[indice]->setAreaSupervisao(novoString);
                    std::cout << "Insira a nova Área de Formação: " << std::endl;
                    getline(std::cin, novoString2);
                    funcionarios[indice]->setAreaFormacao(novoString2);
            }
            else if(funcionarios[indice]->getDesignacao() == 4){
                    std::cout << "Insira a nova Área de Formação: " << std::endl;
                    getline(std::cin, novoString);
                    funcionarios[indice]->setAreaFormacao(novoString);
                    std::cout << "Insira a nova Área de Formação Máxima: " << std::endl;
                    getline(std::cin, novoString2);
                    funcionarios[indice]->setFormacaoMaxima(novoString2);
            }
            break;

        case 8: //alterar  salario
            std::cout << "Insira o novo diário salario: ";
            std::cin >> novoFloat;
            funcionarios[indice]->setSalarioDiario(novoFloat);
            break;

        case 0:
            break;
        
        default: //opção invalida
            throw 9;
    }
    salvarFuncionario();
}

void Empresa::excluirFuncionario()
{
    int codigo, indice, designacao;
    bool encontrado = false, confirmacao = false;

    std::cout << "Insira o codigo do funcionário a ser excluido: ";
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
        throw 1;
    }

    else
    {
        if(designacao==4||designacao==3)
        {
            throw 2;//acesso negado
        }
        else
        {
            std::cout << "Voce tem certeza que quer apagar o funcionário " << funcionarios[indice]->getNome() 
            << "?\n[01] Sim, excluir\n[00] Nao, manter\n";

            std::cin >> confirmacao;
            if(confirmacao==true)
            {
                funcionarios.erase(funcionarios.begin()+indice);
                std::cout << "Funcionario removido com sucesso!\n";
            }
        }
    }
    salvarFuncionario();

}

void Empresa::exibirRegistro(int indice)
{
    std::cout << std::endl;
    std::string tipo[4]{"Operador", "Gerente", "Diretor", "Presidente"};
    std::cout << "Nome: " << funcionarios[indice]->getNome() << std::endl;
    std::cout << "Codigo: " << funcionarios[indice]->getCodigo() << std::endl;
    std::cout << "Designação: " << tipo[funcionarios[indice]->getDesignacao()-1] << std::endl;


    std::cout << "Data de Entrada: ";
    if(funcionarios[indice]->getData().getDia()<10)
    {
        std::cout << "0" << funcionarios[indice]->getData().getDia();
    }
    else 
    {
        std::cout << funcionarios[indice]->getData().getDia();
    }
    std::cout << "/";
    if(funcionarios[indice]->getData().getMes()<10)
    {
        std::cout << "0" << funcionarios[indice]->getData().getMes();
    }
    else 
    {
        std::cout << funcionarios[indice]->getData().getMes();
    }
    std::cout << "/" << funcionarios[indice]->getData().getAno() << std::endl;


    if(funcionarios[indice]->getDesignacao() == 2 || funcionarios[indice]->getDesignacao() == 3){
        std::cout << "Área de supervisão: " << funcionarios[indice]->getAreaSupervisao() << std::endl;
    }

    if(funcionarios[indice]->getDesignacao() == 3 || funcionarios[indice]->getDesignacao() == 4){
        std::cout << "Área de formação: " << funcionarios[indice]->getAreaFormacao() << std::endl;
    }

    if(funcionarios[indice]->getDesignacao() == 4){
        std::cout << "Formação máxima: " << funcionarios[indice]->getFormacaoMaxima() << std::endl;
    }

    std::cout << "Telefone: " << funcionarios[indice]->getTelefone() << std::endl;
    std::cout << std::fixed;
    std::cout << "Salário Diario: " << std::setprecision(2) << funcionarios[indice]->getSalarioDiario() << std::endl;
    std::cout << "Logradouro: " << funcionarios[indice]->getEndereco().getRua() << ", " << funcionarios[indice]->getEndereco().getNumero() << std::endl;
    std::cout << "Bairro: " << funcionarios[indice]->getEndereco().getBairro() << std::endl;
    std::cout << "Cidade: " << funcionarios[indice]->getEndereco().getCidade() << std::endl;
    std::cout << "Estado: " << funcionarios[indice]->getEndereco().getEstado() << std::endl;
    std::cout << std::endl;
   
}

void Empresa::exibirListaFuncionarios()
{
    for(int i = 0; i < funcionarios.size(); i++){
        std::cout << "----------------------------------------------\n";
        exibirRegistro(i);
    }
    std::cout << "----------------------------------------------\n";

}

int Empresa::getFuncionarioPorCodigo(long codigo)
{
    int indice = -1;

    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getCodigo() == codigo)
        {
            indice= i;
            break;
        }
    }

    if(indice==-1)
    {
        throw 1;//throw erro not found
    } 
    return indice;
}

int Empresa::getFuncionarioPorNome(std::string nome)
{
    int indice = -1;

    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getNome() == nome)
        {
            indice= i;
            return indice;
        }
    }
    
    if(indice==-1)
    {
        throw 1; //erro not found
    }
    return -1; // retorno invalido
}

void Empresa::calcularFolhaSalarial()
{
    int mes;

    std::cout << "Digite o numero do mes que voce deseja calcular a folha salarial:\n";
    std::cin >> mes;

    if(mes<1 || mes>12)
    {
        throw 6;
    }

    if(folhaSalarialCalculada[mes-1] == 1){
        throw 11;
    }else{
        std::cout << "Calculando folha salarial...";
        Sleep(1000);

        for(int i = 0; i < funcionarios.size(); i++){
            //se o funcionario foi cadastrado com um ano igual ao atual porem em um mes superior ao da folha que esta sendo calculada ou se o ano de cadastro for maior ao atual, esse funcionario sera pulado
            if(funcionarios[i]->getData().getAno() == ANOATUAL && funcionarios[i]->getData().getMes() > mes){
                continue;
            }
            setDiasEHorasAleatorios(mes, i);
            funcionarios[i]->calculaFolhaMes(funcionarios[i]->getSalarioDiario(), mes);
        }

        std::cout << "Folha salarial calculada com sucesso!";
        Sleep(1000);

        folhaSalarialCalculada[mes-1] = 1;
    }
    salvarFolha(mes-1);
    
}

void Empresa::exibirListaFuncionariosTipo()
{
    int designacao;
    std::cout << "Insira a designacao dos funcionários a serem exibidos \n[01] Operador\n[02] Gerente\n[03] Diretor\n[04] Presidente\n";
    std::cin >> designacao;
    if(designacao<1 || designacao>4)
    {
        std::cout << "Designação Invalida!";
    }

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

void Empresa::ImprimeFolhaSalarialFuncionario() //imprime a folha salarial de um único funcionário.
{
    int opcao, indice, mes;

    std::cout << "Deseja imprimir por nome completo ou por codigo?\n[01] Codigo \n[02] Nome Completo\n";
    std::cin >> opcao;
    std::cin.ignore();
    if(opcao>2 || opcao<1)
    {
        throw 9;
    }

    if(opcao == 1)
    {
        long codigo;

        std::cout << "Digite o codigo do funcionário:\n";
        std::cin >> codigo;

        indice = getFuncionarioPorCodigo(codigo);
    }

    if(opcao == 2)
    {
        std::string nome;

        std::cout << "Digite o nome completo do funcionário:\n";
        getline(std::cin, nome);

        try
        {
        indice = getFuncionarioPorNome(nome);
        }
        catch(int x)
        {
            if(x==1)
            {
                std::cout << "Erro "<< x <<" Not Found!\n" << std::endl;
            }
        }
    }


    std::cout << "Voce deseja imprimir a folha de qual mes?\n";
    std::cin >> mes;

    if(folhaSalarialCalculada[mes-1])
    {
        funcionarios[indice]->imprimirFolhaMes(mes);
    }else
    {
        std::cout << "Folha desse mes nao calculada\n";
    }


}
void Empresa::ImprimeFolhaSalarialEmpresa() //imprime a folha salarial da empresa.
{
    int opcao;

    std::cout << "Deseja imprimir uma folha mensal ou a folha anual?\n[01] Mensal \n[02] Anual\n";
    std::cin >> opcao;

    if(opcao == 1)
    {
        int mes;

        std::cout << "Digite o mês que você deseja exibir a folha salarial:\n";
        std::cin >> mes;

        if(folhaSalarialCalculada[mes-1] == false)
        {
            throw 10; //folha não calculada
        }
        
        std::cout << "Folha mês " << mes << std::endl;

        for(int i = 0; i < funcionarios.size(); i++)
        {
            std::cout << "----------------------------------------------\n"; 
            funcionarios[i]->imprimirFolhaMes(mes);
        }

        std::cout << "----------------------------------------------\n";

    }

    else if(opcao == 2)
    {

        std::cout << "Folha Anual" << std::endl;

        for(int i = 0; i < funcionarios.size(); i++)
        {
            std::cout << "----------------------------------------------\n"; 
            funcionarios[i]->imprimirFolhaAnual();
        }

        std::cout << "----------------------------------------------\n";       
        
    }
    else{
        std::cout << "Opção Invalida!" << std::endl;
    }


}

std::string Empresa::padronizaTelefone(long long telefonlong) // padroniza o telefone
{
    std::string telefone;
    telefone = std::to_string(telefonlong);
    telefone.insert(0, "(");
    telefone.insert(3, ")");
    telefone.insert(9, "-");
    return telefone;
}

bool Empresa::validaData(int dia, int mes, int ano)
{
    int diasmes[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(ano<2000 || ano>ANOATUAL)
    {
        throw 6;
        return false;
    }
    if(mes<1 || mes>12)
    {
        throw 6;
        return false;
    }
    if(dia>diasmes[mes-1] || dia<1)
    {
        throw 6;
        return false;
    }
    else
    {
        return true;
    }
}

void Empresa::adicionarFuncionario()
{
    long codigo;
    std::string nome;
    std::string cep;
    std::string numero;
    std::string telefone;
    long long telefonlong;
    int dia, mes, ano;
    int tipo;
    float salario;
    bool datavalida, cepvalido;
    
    std::cout << "Insira o código do funcionário:" << std::endl;
    std::cin >> codigo;
    std::cin.ignore();
    
    for (int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getCodigo()==codigo)
        {
            throw 3;
        }
    }
    
    std::cout << "Insira o nome do funcionário:" << std::endl;
    std::getline(std::cin, nome);

    std::cout << "Insira o CEP:" << std::endl;
    std::getline(std::cin, cep);

    std::cout << "Insira o número da casa:" << std::endl;
    std::getline(std::cin, numero);

    Endereco endereco(cep, numero);
    cepvalido = endereco.validaCEP();
    if(cepvalido==false)
    {
        throw 12; // erro cep invalido 
    }

    std::cout << "Insira o telefone: (somente numeros, com ddd)" << std::endl;
    std::cin >> telefonlong; // pega o telefone como long long para evitar escrita errada
    std::cin.ignore();
    if(telefonlong<10000000000 || telefonlong>99999999999) // verifica se o telefone tem 11 digitos
    {
        throw 5; // erro para telefone invalido
    }
    telefone = padronizaTelefone(telefonlong); // coloca o (XX) e o - no telefone

    for (int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getTelefone()==telefone)
        {
            throw 4; // erro para telefone ja cadastrado
        }
    }

    std::cout << "Insira a data de entrada (DD MM AAAA):" << std::endl;
    std::cin >> dia >> mes >> ano;

    datavalida = validaData(dia, mes, ano);
        if(datavalida==false)
        {
            throw 6; // erro data invalida
        }

    std::cout << "Insira a designacao do funcionário\n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n" << std::endl;
    std::cin >> tipo;
    if(tipo>4 || tipo<1)
    {
        throw 7; // erro designacao invalida
    }

    std::cout << "Insira o salario diário:" << std::endl;
    std::cin >> salario;
    std::cin.ignore();
    if(salario<10)
    {
        throw 8; // erro salario invalido
    }

    Data data(dia, mes, ano);
    Funcionario *funcionario;
    

    std::string areaSupervisao, areaFormacao, formacaoMaxima;

    switch (tipo)
    {
    case 1:
        funcionario = new Operador(codigo, nome, endereco, telefone, data, salario);
        break;
    
    case 2:
        std::cout << "Insira a Área de Supervisão: " << std::endl;
        getline(std::cin, areaSupervisao);
        funcionario = new Gerente(codigo, nome, endereco, telefone, data, salario, areaSupervisao);
        break;
    
    case 3:
        std::cout << "Insira a Área de Supervisão: " << std::endl;
        getline(std::cin, areaSupervisao);
        std::cout << "Insira a Área de Formação: " << std::endl;
        getline(std::cin, areaFormacao);
        funcionario = new Diretor(codigo, nome, endereco, telefone, data, salario, areaSupervisao, areaFormacao);
        break;
    
    case 4:
        std::cout << "Insira a Área de Formação: " << std::endl;
        getline(std::cin, areaFormacao);
        std::cout << "Insira a Formação Máxima: " << std::endl;
        getline(std::cin, formacaoMaxima);
         funcionario = new Presidente(codigo, nome, endereco, telefone, data, salario, areaFormacao, formacaoMaxima);
        break;
    }

    funcionarios.push_back(funcionario);
    salvarFuncionario();

}

void Empresa::aumentaTodosSalarios(){
    for(int i = 0; i < funcionarios.size(); i++){
        funcionarios[i]->aumentoSalarial();
    }
    std::cout << "Salários aumentados com sucesso!\n";
}

int Empresa::getIntAleatorio(int maximo){
    static short vezes = 0;
    srand(time(NULL) + vezes);

    vezes++;

    return (rand() % (maximo+1));
}

void Empresa::setDiasEHorasAleatorios(int mes, int indice)
{
    int maxDias, maxHoras;

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        maxDias = 31 - 8;
    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        maxDias = 30 - 8;
    }else{
        maxDias = 28 - 8;
    }

    funcionarios[indice]->setDiasTrabalhadosMes(getIntAleatorio(maxDias), mes);

     //se o funcionario foi cadastrado no mes que esta pedindo a folha salarial, a quantidade de dias trabalhado n poderá exceder o maximo de dias - o dia de entrada
    if(funcionarios[indice]->getData().getAno() == ANOATUAL && funcionarios[indice]->getData().getMes() == mes){
        while(1){
           if(funcionarios[indice]->getFolhaDoMes(mes).getDiasTrabalhados() <= (maxDias - funcionarios[indice]->getData().getDia())){
            break;
           }else{
            funcionarios[indice]->setDiasTrabalhadosMes(getIntAleatorio(maxDias), mes);
           }
        }
    }

    maxHoras = funcionarios[indice]->getFolhaDoMes(mes).getDiasTrabalhados() * 4;
    
    funcionarios[indice]->setHorasExtrasMes((getIntAleatorio(maxHoras)), mes);
}

void Empresa::buscarFuncionario()
{
    bool achou = false; //vai informar se um funcionário foi encontrado
    int tipo, tipoEnd; //tipo vai informar qual elemento será usado para fazer a busca do funcionário e tipoEnd vai informar qual elemento será usado para fazer a busca do endereço
    std::string nome, endereco; //nome vai armazenar o nome digitado pelo usuario e Endereço vai armazenar o Endereço digitado pelo usuario. ambos seram usados para fazer uma busca de funcionário
    std::string CEP;

    std::cout << "Qual informação você deseja usar para buscar um funcionário?\n[01] Nome\n[02] Data de ingresso\n[03] Endereço" << std::endl;
    std::cin >> tipo;
    
    //switch case que vai funcionar de acordo com o que o usuario escolheu
    switch(tipo)
    {
        case 1:
        {
        //caso o elemento escolhido for 1 (nome), sera usado um for para percorrer todos os elementos do vector ate achar um funcionário que tenha o nome digitado em alguma parte de seu nome completo
            std::cin.ignore(); //ignora o '\n' lido pelo cin
            std::cout << "Digite um nome pelo qual você deseja procurar um funcionário" << std::endl;
            std::getline(std::cin, nome); // le o que o usuario deseja usar na busca
            //for que percorre todos os elementos do vector
            for(int i = 0; i < funcionarios.size(); i++)
            {
                //se o nome digitado pelo usuario estiver presente no nome completo do funcionário do indice i, achou será true e o funcionário será exibido
                if(funcionarios[i]->getNome().find(nome) != std::string::npos)
                {
                    std::cout << "----------------------------------------------";
                    achou = true;
                    //exibirRegistro do funcionario com o indicie atual (indicie i)
                    exibirRegistro(i);
                }
                std::cout << "----------------------------------------------";
            }
            //caso nao tenha sido encontrado nenhum funcionário com aquele nome (achou continua como false), o programa informará o erro
            if(!achou)
            {
                throw 1;
            }
            break;
        }
        case 2:
        {
        //caso o elemento escolhido for 2 (data), sera usado um for para percorrer todos os elementos do vector ate achar um funcionário com aquele intervalo de data de ingresso
            int dia1, dia2, mes1, mes2, ano1, ano2; // variaveis para ler os dois intervalos de tempo que seram usados para buscar um funcionário
            std::cout << "Digite a primeira data do intervalo (menor data) no padrao (DD MM AAAA)" << std::endl;
            std::cin >> dia1 >> mes1 >> ano1;//le a primeira data
            std::cout << "Digite a segunda data do intervalo (maior data) no padrao (DD MM AAAA)" << std::endl;
            std::cin >> dia2 >> mes2 >> ano2;//le a segunda data
            
            if(ano1>ano2 || (ano1==ano2 && mes1>mes2) || (ano1>=ano2 && mes1==mes2 && dia1>dia2))
            {
                throw 6; // data invalida
            }
            system("CLS");
            for(int i = 0; i < funcionarios.size(); i++)
            {
                //verifica se as duas datas digitadas sao iguais, se sim, ele irá verificar apenas aquela data exata
                if(ano1 == ano2 && mes1 == mes2 && dia1 == dia2)
                {
                    if(funcionarios[i]->getData().getAno() == ano1 && funcionarios[i]->getData().getMes() == mes1 && funcionarios[i]->getData().getDia() == dia1)
                    {
                        std::cout << "----------------------------------------------";
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                        break;
                    }
                    std::cout << "----------------------------------------------";
                }
                //verifica se o funcionário tem seu ano dentro do intervalo de anos fornecidos
                else if(funcionarios[i]->getData().getAno() >= ano1 && funcionarios[i]->getData().getAno() <= ano2)
                {  
                    //verifica se o ano do funcionário é o menor ano possivel e então verifica se o seu mês está dentro do intervalo válido
                    if(funcionarios[i]->getData().getAno() == ano1 && funcionarios[i]->getData().getMes() >= mes1 && funcionarios[i]->getData().getMes() <= 12)
                    {
                        //se o mes for maior que o menor possivel e menor que 12, entao o dia nao importa
                        if(funcionarios[i]->getData().getMes() > mes1)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        //se o seu mês for o menor possível, verifica se o seu dia está dentro do intervalo válido
                        else if(funcionarios[i]->getData().getMes() == mes1 && funcionarios[i]->getData().getDia() >= dia1 && funcionarios[i]->getData().getDia() <= 30)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    //verifica se o ano do funcionário é o maior ano possivel e então verifica se o seu mês está dentro do intervalo válido
                    else if(funcionarios[i]->getData().getAno() == ano2 && funcionarios[i]->getData().getMes() <= mes2 && funcionarios[i]->getData().getMes() >= 1)
                    {
                        //se o mes for menor que o maior possivel e maior que 1, entao o dia nao importa
                        if(funcionarios[i]->getData().getMes() < mes2)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        //se o seu mês for o maior possível, verifica se o seu dia está dentro do intervalo válido
                        else if(funcionarios[i]->getData().getMes() == mes2 && funcionarios[i]->getData().getDia() <= dia2 && funcionarios[i]->getData().getDia() >= 1)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    //se o ano do funcionário estiver dentro do intervalo, mas não for nem o menor e nem o maior possível, então certamente a data do funcionário está dentro do intervalo aceito
                    else if(funcionarios[i]->getData().getAno() > ano1 && funcionarios[i]->getData().getAno() < ano2)
                    {
                        std::cout << "----------------------------------------------";
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }
                    std::cout << "----------------------------------------------";                                                                           
                }
            }
            //caso nao tenha sido encontrado nenhum funcionário naquele intervalo de tempo, o programa informara o erro
            if(!achou)
            {
                throw 1;
            }
            break;
        }
        case 3:
        {
        //caso o elemento escolhido for 3 (Endereço), será perguntado ao usuário se ele deseja fazer a busca por [1] Cidade, [2] Bairro, [3] Rua ou [4] CEP
            std::cout << "Qual elementos você deseja usar para fazer a busca?\n[01] Cidade\n[02] Bairro\n[03] Rua\n[04] CEP" << std::endl;
            std::cin >> tipoEnd;
            std::cin.ignore();
            switch (tipoEnd)
            {
                case 1:
                {
                    std::string cidade;
                    std::cout << "Digite a cidade que você deseja fazer a busca" << std::endl;
                    getline(std::cin, cidade);
                    //for que percorre todos os elementos do vector
                    system("CLS");
                    for(int i = 0; i < funcionarios.size(); i++)
                    {
                        //se a cidade digitada pelo usuario for igual a cidade do funcionário do indice i, achou será true e o funcionário será exibido
                        if(funcionarios[i]->getEndereco().getCidade().find(cidade) != std::string::npos)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    break;
                }
                case 2:
                {
                    std::string bairro;
                    std::cout << "Digite o bairro que você deseja fazer a busca" << std::endl;
                    getline(std::cin, bairro);
                    system("CLS");
                    for(int i = 0; i < funcionarios.size(); i++)
                    {
                        //se o bairro digitada pelo usuario for igual ao bairro do funcionário do indice i, achou será true e o funcionário será exibido
                        if(funcionarios[i]->getEndereco().getBairro().find(bairro) != std::string::npos)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    break;
                }
                case 3:
                {
                    std::string rua;
                    std::cout << "Digite a rua que você deseja fazer a busca" << std::endl;
                    getline(std::cin, rua);
                    system("CLS");
                    for(int i = 0; i < funcionarios.size(); i++)
                    {
                        //se a rua digitada pelo usuario for igual a rua do funcionário do indice i, achou será true e o funcionário será exibido
                        if(funcionarios[i]->getEndereco().getRua().find(rua) != std::string::npos)
                        {   
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    break;
                }
                case 4:
                {

                    std::cout << "Digite o CEP que você deseja fazer a busca" << std::endl;
                    getline(std::cin, CEP);

                    if(CEP.size() == 9)
                    {
                        CEP.replace(5,1,"");
                    }

                    system("CLS");
                    for(int i = 0; i < funcionarios.size(); i++)
                    {
                        //se o CEP digitada pelo usuario for igual ao CEP do funcionário do indice i, achou será true e o funcionário será exibido
                        if(funcionarios[i]->getEndereco().getCEP() == CEP)
                        {
                            std::cout << "----------------------------------------------";
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        std::cout << "----------------------------------------------";
                    }
                    break;
                }
                default:
                {
                    throw 9;
                    break; 
                }         
                //caso nao tenha sido encontrado nenhum funcionário com aquele endereço, o programa informará o erro
                if(!achou)
                {
                    throw 1;
                }
                break;
            }
            break;
        }
        default:
        {
            throw 9;
            break;
        }
        
    }
}
void Empresa::salvarFuncionario(){
    std::fstream fs;
    fs.open("Funcionarios/ListaFuncionarios.txt", std::fstream::out);
    if(!fs.is_open()){
        std::cout << "Erro ao abrir arquivo para escrita\n";
        return;
    }
    for(int i = 0; i < funcionarios.size(); i++){
        fs << "-----" << std::endl;
        fs << funcionarios[i]->getCodigo() << std::endl;
        fs << funcionarios[i]->getNome() << std::endl;
        fs << funcionarios[i]->getEndereco().getCEP() << std::endl;
        fs << funcionarios[i]->getEndereco().getNumero() << std::endl;
        fs << funcionarios[i]->getTelefone() << std::endl;
        fs << funcionarios[i]->getData().getDia() << std::endl;
        fs << funcionarios[i]->getData().getMes() << std::endl;
        fs << funcionarios[i]->getData().getAno() << std::endl;
        fs << funcionarios[i]->getDesignacao() << std::endl;
        fs << funcionarios[i]->getSalarioDiario() << std::endl;
        if(funcionarios[i]->getDesignacao()==2)
        {
            fs << funcionarios[i]->getAreaSupervisao() << std::endl;
        }
        else if(funcionarios[i]->getDesignacao()==3)
        {
            fs << funcionarios[i]->getAreaSupervisao()<<std:: endl;
            fs << funcionarios[i]->getAreaFormacao()<< std::endl;
        }
        else if(funcionarios[i]->getDesignacao()==4)
        {
            fs << funcionarios[i]->getAreaFormacao()<< std::endl;
            fs << funcionarios[i]->getFormacaoMaxima()<< std::endl;
        }
    }
    fs.close();
}
void Empresa::lerFuncionario(){
    int i = 0;
    int quantTem = 0; // quantos funcionarios tem na lista
    int quantLeu = 0; // quantos funcionarios ja leu da lista
    std::fstream fs;
    //essa primeira parte vai ler o arquivo por completo e contar quantos funcionarios tem nele
    {
        fs.open("Funcionarios/ListaFuncionarios.txt", std::fstream::in);
        if(!fs.is_open()){
            std::cout << "Erro ao abrir arquivo para leitura\n";
        }
        while(1){
            if(fs.eof()){
                break;
            }
            std::string linha;
            getline(fs, linha);
            if(linha == "-----"){
                quantTem++;
            }
        }
        fs.close();
    }
    //essa segunda parte vai ler o arquivo ja sabendo quantos funcionarios tem e parar exatamente onde deve
    {
        fs.open("Funcionarios/ListaFuncionarios.txt", std::fstream::in);
        if(!fs.is_open()){
            std::cout << "Erro ao abrir arquivo para leitura\n";
        }
        system("CLS");
        while(1){
            if(quantLeu == quantTem){
                break;
            }
            std::cout << "Lendo lista de funcionários, " << i+1 << " funcionário(s) registrado(s)\n";
            i++;
            std::string linha;
            long codigo;
            std::string nome;
            std::string cep;
            std::string numero;
            std::string telefone;
            std::string areaSupervisao;
            int dia, mes, ano;
            int tipo;
            float salario;
            
            getline(fs, linha);
            quantLeu++;

            fs >> codigo;
            fs.ignore();
            getline(fs, nome);
            getline(fs, cep);
            getline(fs, numero);
            getline(fs, telefone);
            fs >> dia >> mes >> ano;
            fs >> tipo;
            fs >> salario;
            fs.ignore();

            Data data(dia, mes, ano);
            Endereco endereco(cep, numero);
            Funcionario *funcionario;
            std::string areaFormacao, formacaoMaxima;

            switch (tipo)
            {
            case 1:
                funcionario = new Operador(codigo, nome, endereco, telefone, data, salario);
                break;
            
            case 2:
                getline(fs, areaSupervisao);
                funcionario = new Gerente(codigo, nome, endereco, telefone, data, salario, areaSupervisao);
                break;
            
            case 3:
                getline(fs, areaSupervisao);
                getline(fs, areaFormacao);
                funcionario = new Diretor(codigo, nome, endereco, telefone, data, salario, areaSupervisao, areaFormacao);
                break;
            
            case 4:
                getline(fs, areaFormacao);
                getline(fs, formacaoMaxima);
                funcionario = new Presidente(codigo, nome, endereco, telefone, data, salario, areaFormacao, formacaoMaxima);
                break;
            }

            funcionarios.push_back(funcionario);
        }
        fs.close();
    }
}

void Empresa::salvarFolha(int j)
{
    std::fstream fs;
    
    switch(j){
        case 0:
        {
 
            fs.open("FolhasSalariais/jan.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 1:
        {
            fs.open("FolhasSalariais/fev.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 2:
        {
            fs.open("FolhasSalariais/mar.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 3:
        {
            fs.open("FolhasSalariais/abr.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 4:
        {
            fs.open("FolhasSalariais/mai.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 5:
        {
            fs.open("FolhasSalariais/jun.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 6:
        {
            fs.open("FolhasSalariais/jul.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 7:
        {
            fs.open("FolhasSalariais/ago.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 8:
        {
            fs.open("FolhasSalariais/set.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 9:
        {
            fs.open("FolhasSalariais/out.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 10:
        {
            fs.open("FolhasSalariais/nov.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
        case 11:
        {
            fs.open("FolhasSalariais/dez.txt", std::fstream::out);
            if(!fs.is_open())
            {
                std::cout << "Erro ao abrir arquivo para escrita\n";
                break;
            }
            break;
        }
    }
    for(int i = 0; i < funcionarios.size(); i++)
    {

        fs << "-----" << std::endl;
        fs << funcionarios[i]->getNome() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getSalarioMesBruto() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getDescontoPrevidencia() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getDescontoImpostoRend() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getDescontoPrevidencia() + funcionarios[i]->folhaDoMes[j].getDescontoImpostoRend() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getSalarioMesLiquido() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getDiasTrabalhados() << std::endl;
        fs << funcionarios[i]->folhaDoMes[j].getHorasExtras() << std::endl;
    }
    fs.close();
}

void Empresa::lerFolha(){
    std::string mes[12] = {"FolhasSalariais/jan.txt", "FolhasSalariais/fev.txt", "FolhasSalariais/mar.txt", "FolhasSalariais/abr.txt", 
                      "FolhasSalariais/mai.txt", "FolhasSalariais/jun.txt", "FolhasSalariais/jul.txt", "FolhasSalariais/ago.txt", 
                      "FolhasSalariais/set.txt", "FolhasSalariais/out.txt", "FolhasSalariais/nov.txt", "FolhasSalariais/dez.txt"};
    int quantTem = funcionarios.size(); // quantos funcionarios tem na lista
    int quantLeu = 0; // quantos funcionarios ja leu da lista
    std::fstream fs;
    std::string linha;
    std::string nome;
    float salarioMesBruto;
    float descontoPrevidencia;
    float descontoImpostoRend;
    float descontoTotal;
    float salarioLiquido;
    int diasTrabalhados;
    float horasExtras;

    for(int j = 0; j < 12; j++)
    {
        quantLeu = 0;
        //essa segunda parte vai ler o arquivo ja sabendo quantos funcionarios tem e parar exatamente onde deve
        {
            fs.open(mes[j], std::fstream::in);
            if(!fs.is_open()){
                continue;
            }   
            while(1){
                if(quantLeu == quantTem){
                    break;
                }
                
                fs.ignore();
                getline(fs, linha);
                getline(fs, nome);
                fs >> salarioMesBruto;
                fs >> descontoPrevidencia;
                fs >> descontoImpostoRend;
                fs >> descontoTotal;
                fs >> salarioLiquido;
                fs >> diasTrabalhados;
                fs >> horasExtras;

                funcionarios[quantLeu]->setDiasTrabalhadosMes(diasTrabalhados, j+1);
                funcionarios[quantLeu]->setHorasExtrasMes(horasExtras, j+1);
                funcionarios[quantLeu]->setSalarioMesBrutoMes(salarioMesBruto, j+1);
                funcionarios[quantLeu]->setSalarioMesLiquidoMes(salarioLiquido, j+1);
                funcionarios[quantLeu]->setDescontoPrevidenciaMes(descontoPrevidencia, j+1);
                funcionarios[quantLeu]->setdescontoImpostoRendMes(descontoImpostoRend, j+1);
                quantLeu++;
                
            }
            folhaSalarialCalculada[j] = true;
            fs.close();
        }
    }

}