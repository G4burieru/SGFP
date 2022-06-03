#include "Empresa.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include <iostream>
#include <string>
#include <ctime>

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
    long novoLong;
    string novoString;
    float novoFloat;
    Data novaData(0, 0, 0);

    std::cout << "Insira o codigo do funcionario a se alterar: ";
    std::cin >> codigo;
    
    indice = getFuncionarioPorCodigo(codigo);

    std::cout << "Escolha o que alterar: \n[1] Codigo\n[2] Data de Ingresso"
    "\n[3] Nome\n[4] Endereco\n[5] Telefone\n[6] Designacao\n[7] Salario\n";
    std::cin >> opcao;
    cin.ignore();

    switch(opcao)
    {
        case 1: //alterar codigo 
            std::cout << "Insira o novo codigo: ";
            std::cin >> novoLong;
            funcionarios[indice]->setCodigo(novoLong);
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
        std::cout << "Funcionario de codigo: "<< codigo << " nao encontrado.\n";
    }else
    {
        if(designacao==4||designacao==3)
        {
            //throw "acesso negado"; ----------------------------------------------------------------------
            cout << "Acesso negado"; // Provisorio ----------------------------------------------------------
        }else
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

int Empresa::getFuncionarioPorCodigo(long codigo)
{
    int indice;

    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getCodigo() == codigo)
        {
            indice= i;
            return indice;
        }
    }

    //Colocar exception nos metodos que usam caso recebam "0"--------------------------------------------
    return 0;
}

int Empresa::getFuncionarioPorNome(std::string nome)
{
    int indice;

    for(int i= 0; i < funcionarios.size(); i++)
    {
        
        if(funcionarios[i]->getNome() == nome)
        {
            indice= i;
            return indice;
        }
    }
    
    //Colocar exception nos metodos que usam caso recebam "0"--------------------------------------------
    return 0;
}

void Empresa::calcularFolhaSalarial()
{
    int mes;

    std::cout << "Digite o numero do mes que voce deseja calcular a folha salarial:\n";
    cin >> mes;

    if(folhaSalarialCalculada[mes-1] == 1){
        std::cout << "A folha salarial desse mes já foi calculada.";
        // colocar excepiton ------------------------------------------------------------------------
    }else{
        std::cout << "Calculando folha salarial...";

        for(int i = 0; i < funcionarios.size(); i++){
            setDiasEHorasAleatorios(mes, i);
            funcionarios[i]->calculaFolhaMes(funcionarios[i]->getSalarioDiario(), mes);
        }

        std::cout << "Folha salarial calculada com sucesso!";

        folhaSalarialCalculada[mes-1] = 1;
    }
    
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

void Empresa::ImprimeFolhaSalarialFuncionario() //imprime a folha salarial de um único funcionário.
{
    int opcao, indice, mes;

    std::cout << "Deseja imprimir por nome completo ou por codigo?\n[1] Codigo \n[2] Nome Completo\n";
    cin >> opcao;
    cin.ignore();

    if(opcao == 1){
        long codigo;

        std::cout << "Digite o codigo do funcionario:\n";
        cin >> codigo;

        indice = getFuncionarioPorCodigo(codigo);
    }

    if(opcao == 2){
        std::string nome;

        std::cout << "Digite o nome completo do funcionario:\n";
        getline(cin, nome);

        indice = getFuncionarioPorNome(nome);
    }else{
        //colocar exception --------------------------------------------------------------------------------
    }

    std::cout << "Voce deseja imprimir a folha de qual mes?\n";
    cin >> mes;

    if(folhaSalarialCalculada[mes-1])
    {
        funcionarios[indice]->imprimirFolhaMes(mes);
    }else
    {
        std::cout << "Folha desse mes nao calculada";
        //colocar exception--------------------------------------------------------------------------------
    }


}
void Empresa::ImprimeFolhaSalarialEmpresa() //imprime a folha salarial da empresa.
{
    int opcao;

    std::cout << "Deseja imprimir uma folha mensal ou a folha anual?\n[1] Mensal \n[2] Anual\n";
    std::cin >> opcao;

    if(opcao == 1){
        int mes;

        cout << "Digite o mes que vocce deseja exibir a folha salarial:\n";
        cin >> mes;
        
        std::cout << "Folha mes " << mes << endl;

        for(int i = 0; i < funcionarios.size(); i++)
        {
            std::cout << "----------------------------------------------\n"; 
            funcionarios[i]->imprimirFolhaMes(mes);
        }

        std::cout << "----------------------------------------------\n";

    }

    if(opcao == 2){

        std::cout << "Folha Anual" << endl;

        for(int i = 0; i < funcionarios.size(); i++)
        {
            std::cout << "----------------------------------------------\n"; 
            funcionarios[i]->imprimirFolhaAnual();
        }

        std::cout << "----------------------------------------------\n";       
        
    }else{
        //colocar exception --------------------------------------------------------------------------------
    }

}
void Empresa::adicionarFuncionario(){
    long codigo;
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
    getline(cin, endereco); //TRANSFORMAR EM CEP DPS -------------------------------------------------

    cout << "Insira o telefone:" << endl;
    getline(cin, telefone);

    cout << "Insira a data de entrada (DD MM AAAA):" << endl;
    cin >> dia >> mes >> ano;

    cout << "Insira a designacao do funcionario\n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n" << endl;
    cin >> tipo;

    cout << "Insira o salario diário:" << endl;
    cin >> salario;

    Data data(dia, mes, ano);
    Funcionario *funcionario;

    switch (tipo)
    {
    case 1:
         funcionario = new Operador(codigo, nome, endereco, telefone, data, salario);
        break;
    
    case 2:
         funcionario = new Gerente(codigo, nome, endereco, telefone, data, salario);
        break;
    
    case 3:
         funcionario = new Diretor(codigo, nome, endereco, telefone, data, salario);
        break;
    
    case 4:
         funcionario = new Presidente(codigo, nome, endereco, telefone, data, salario);
        break;
    
    default:
        //incerir exeption ------------------------------------------------------------------------
        break;
    }

    funcionarios.push_back(funcionario);
}

void Empresa::aumentaTodosSalarios(){
    for(int i = 0; i < funcionarios.size(); i++){
        funcionarios[i]->aumentoSalarial();
    }
    std::cout << "Salarios aumentados com sucesso!\n";
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

    maxHoras = funcionarios[indice]->getFolhaDoMes(mes).getDiasTrabalhados() * 4;
    
    funcionarios[indice]->setHorasExtrasMes((getIntAleatorio(maxHoras)), mes);

}