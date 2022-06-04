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
    string novoCEP, novoNumeroRua;
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
            std::cout <<"Insira o novo CEP e numero da rua: ";
            getline(cin, novoCEP);
            getline(cin, novoNumeroRua);
            funcionarios[indice]->setEndereco(novoCEP, novoNumeroRua);
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
    std::cout << endl;
    string tipo[4]{"Operador", "Gerente", "Diretor", "Presidente"};
    std::cout << "Nome: " << funcionarios[indice]->getNome() << endl;
    std::cout << "Codigo: " << funcionarios[indice]->getCodigo() << endl;
    std::cout << "Designação: " << tipo[funcionarios[indice]->getDesignacao()-1] << endl;
    std::cout << "Data de Entrada: " << funcionarios[indice]->getData().getDia() << "/" << 
    funcionarios[indice]->getData().getMes() << "/" << funcionarios[indice]->getData().getAno() << endl;
    std::cout << "Telefone: " << funcionarios[indice]->getTelefone() << endl;
    std::cout << "SalarioDiario: " << funcionarios[indice]->getSalarioDiario() << endl;
    std::cout << "Endereco: " << funcionarios[indice]->getEndereco().getRua() << ", " << funcionarios[indice]->getEndereco().getNumero() << endl;
    std::cout << endl;
    //Exibit o resto das coisas do endereço --------------------------------------------------------------------------------------
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
    std::string cep;
    std::string numero;
    std::string telefone;
    int dia, mes, ano;
    int tipo;
    float salario;
    
    cout << "Insira o código do funcionario" << endl;
    cin >> codigo;
    cin.ignore();
    
    cout << "Insira o nome do funcionario:" << endl;
    getline(cin, nome);

    cout << "Insira o CEP:" << endl;
    getline(cin, cep);

    cout << "Insira o número da rua:" << endl;
    getline(cin, numero);

    cout << "Insira o telefone:" << endl;
    getline(cin, telefone);

    cout << "Insira a data de entrada (DD MM AAAA):" << endl;
    cin >> dia >> mes >> ano;

    cout << "Insira a designacao do funcionario\n[1] Operador\n[2] Gerente\n[3] Diretor\n[4] Presidente\n" << endl;
    cin >> tipo;

    cout << "Insira o salario diário:" << endl;
    cin >> salario;

    Data data(dia, mes, ano);
    Endereco endereco(cep, numero);
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

void Empresa::buscarFuncionario(){

    bool achou = false; //vai informar se um funcionário foi encontrado
    int tipo, tipoEnd; //tipo vai informar qual elemento será usado para fazer a busca do funcionário e tipoEnd vai informar qual elemento será usado para fazer a busca do endereço
    std::string nome, endereco; //nome vai armazenar o nome digitado pelo usuario e Endereço vai armazenar o Endereço digitado pelo usuario. ambos seram usados para fazer uma busca de funcionário

    std::cout << "Qual informação você deseja usar para buscar um funcionário?\n[1] Nome\n[2] Data de ingresso\n[3] Endereço" << std::endl;
    std::cin >> tipo;
    
    //switch case que vai funcionar de acordo com o que o usuario escolheu
    switch(tipo)
    {
        case 1:
        //caso o elemento escolhido for 1 (nome), sera usado um for para percorrer todos os elementos do vector ate achar um funcionário que tenha o nome digitado em alguma parte de seu nome completo
            std::cin.ignore(); //ignora o '\n' lido pelo cin
            std::cout << "Digite um nome pelo qual você deseja procurar um funcionário" << std::endl;
            std::getline(std::cin, nome); // le o que o usuario deseja usar na busca
            //for que percorre todos os elementos do vector
            for(int i = 0; i < funcionarios.size(); i++){
                //se o nome digitado pelo usuario estiver presente no nome completo do funcionário do indice i, achou será true e o funcionário será exibido
                if(funcionarios[i]->getNome().find(nome) != std::string::npos){
                    achou = true;
                    //exibirRegistro do funcionario com o indicie atual (indicie i)
                    exibirRegistro(i);
                }
            }
            //caso nao tenha sido encontrado nenhum funcionário com aquele nome (achou continua como false), o programa informará o erro
            //------------------------------------------------exception-----------------------------------------------
            if(!achou){
                std::cout << "Não existe nenhum funcionário com esse nome na empresa." << std::endl;
            }
            break;
        case 2:
        //caso o elemento escolhido for 2 (data), sera usado um for para percorrer todos os elementos do vector ate achar um funcionário com aquele intervalo de data de ingresso
            int dia1, dia2, mes1, mes2, ano1, ano2; // variaveis para ler os dois intervalos de tempo que seram usados para buscar um funcionário
            std::cout << "Digite a primeira data do intervalo (menor data) no padrao (DD MM AAAA)" << std::endl;
            std::cin >> dia1 >> mes1 >> ano1;//le a primeira data
            std::cout << "Digite a segunda data do intervalo (maior data) no padrao (DD MM AAAA)" << std::endl;
            std::cin >> dia2 >> mes2 >> ano2;//le a segunda data
            //--------------------------------------------------------------------------------------------------------------------------------------------------------
            //----------------------------------exception se o usuario digitar a MAIOR data PRIMEIRO e a MENOR data DEPOIS--------------------------------------------
            //--------------------------------------------------------------------------------------------------------------------------------------------------------
            for(int i = 0; i < funcionarios.size(); i++){
                //verifica se as duas datas digitadas sao iguais, se sim, ele irá verificar apenas aquela data exata
                if(ano1 == ano2 && mes1 == mes2 && dia1 == dia2){
                    if(funcionarios[i]->getData().getAno() == ano1 && funcionarios[i]->getData().getMes() == mes1 && funcionarios[i]->getData().getDia() == dia1){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                        break;
                    }
                }
                //verifica se o funcionário tem seu ano dentro do intervalo de anos fornecidos
                else if(funcionarios[i]->getData().getAno() >= ano1 && funcionarios[i]->getData().getAno() <= ano2){  
                    //verifica se o ano do funcionário é o menor ano possivel e então verifica se o seu mês está dentro do intervalo válido
                    if(funcionarios[i]->getData().getAno() == ano1 && funcionarios[i]->getData().getMes() >= mes1 && funcionarios[i]->getData().getMes() <= 12){
                        //se o mes for maior que o menor possivel e menor que 12, entao o dia nao importa
                        if(funcionarios[i]->getData().getMes() > mes1){
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        //se o seu mês for o menor possível, verifica se o seu dia está dentro do intervalo válido
                        else if(funcionarios[i]->getData().getMes() == mes1 && funcionarios[i]->getData().getDia() >= dia1 && funcionarios[i]->getData().getDia() <= 30){
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                    }
                    //verifica se o ano do funcionário é o maior ano possivel e então verifica se o seu mês está dentro do intervalo válido
                    else if(funcionarios[i]->getData().getAno() == ano2 && funcionarios[i]->getData().getMes() <= mes2 && funcionarios[i]->getData().getMes() >= 1){
                        //se o mes for menor que o maior possivel e maior que 1, entao o dia nao importa
                        if(funcionarios[i]->getData().getMes() < mes2){
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                        //se o seu mês for o maior possível, verifica se o seu dia está dentro do intervalo válido
                        else if(funcionarios[i]->getData().getMes() == mes2 && funcionarios[i]->getData().getDia() <= dia2 && funcionarios[i]->getData().getDia() >= 1){
                            achou = true;
                            //exibirRegistro do funcionario com o indicie atual (indicie i)
                            exibirRegistro(i);
                        }
                    }
                    //se o ano do funcionário estiver dentro do intervalo, mas não for nem o menor e nem o maior possível, então certamente a data do funcionário está dentro do intervalo aceito
                    else if(funcionarios[i]->getData().getAno() > ano1 && funcionarios[i]->getData().getAno() < ano2){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }                                                                           
                }
            }
            //caso nao tenha sido encontrado nenhum funcionário naquele intervalo de tempo, o programa informara o erro
            //------------------------------------------------exception-----------------------------------------------
            if(!achou){
                std::cout << "\nNenhum funcionário foi contratado nesse intervalo de tempo.\n" << std::endl;
            }
            break;
        case 3:
        //caso o elemento escolhido for 3 (Endereço), será perguntado ao usuário se ele deseja fazer a busca por [1] Cidade, [2] Bairro, [3] Rua ou [4] CEP
            std::cout << "Qual elementos você deseja usar para fazer a busca?\n[1] Cidade\n[2] Bairro\n[3] Rua\n[4] CEP" << std::endl;
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
                for(int i = 0; i < funcionarios.size(); i++){
                    //se a cidade digitada pelo usuario for igual a cidade do funcionário do indice i, achou será true e o funcionário será exibido
                    if(funcionarios[i]->getEndereco().getCidade().find(cidade) != std::string::npos){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }
                }
                break;
            }
            case 2:
            {
                std::string bairro;
                std::cout << "Digite o bairro que você deseja fazer a busca" << std::endl;
                getline(std::cin, bairro);
                for(int i = 0; i < funcionarios.size(); i++){
                    //se o bairro digitada pelo usuario for igual ao bairro do funcionário do indice i, achou será true e o funcionário será exibido
                    if(funcionarios[i]->getEndereco().getBairro().find(bairro) != std::string::npos){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }
                }
                break;
            }
            case 3:
            {
                std::string rua;
                std::cout << "Digite a rua que você deseja fazer a busca" << std::endl;
                getline(std::cin, rua);
                for(int i = 0; i < funcionarios.size(); i++){
                    //se a rua digitada pelo usuario for igual a rua do funcionário do indice i, achou será true e o funcionário será exibido
                    if(funcionarios[i]->getEndereco().getRua().find(rua) != std::string::npos){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }
                }
                break;
            }
            case 4:
            {
                std::string CEP;
                std::cout << "Digite o CEP que você deseja fazer a busca" << std::endl;
                getline(std::cin, CEP);
                for(int i = 0; i < funcionarios.size(); i++){
                    //se o CEP digitada pelo usuario for igual ao CEP do funcionário do indice i, achou será true e o funcionário será exibido
                    if(funcionarios[i]->getEndereco().getCEP() == CEP){
                        achou = true;
                        //exibirRegistro do funcionario com o indicie atual (indicie i)
                        exibirRegistro(i);
                    }
                }
                break;
            }
            
            default:
                //caso o tipo digitado nao exista
                //------------------------------------------------exception-----------------------------------------------
                std::cout << "Voce digitou um tipo inválido!" << std::endl;
                break;
            }
            //caso nao tenha sido encontrado nenhum funcionário com aquele endereço, o programa informará o erro
            //------------------------------------------------exception----------------------------------------------
            if(!achou){
                std::cout << "Não existe nenhum funcionário com esse endereço na empresa." << std::endl;
            }
            break;
        
        default:
            //caso o tipo digitado nao exista
            //------------------------------------------------exception-----------------------------------------------
            std::cout << "Voce digitou um tipo inválido!" << std::endl;
            break;
    }
}