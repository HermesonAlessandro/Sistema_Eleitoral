#include <algorithm> // Manipulação de sequencias de elementos
#include <iostream>
#include <string> // Fornece a classe de string variadas
#include <vector> // Contêiner que crescer e aumenta conforme o numero de informação
#include "candidatos_eleitores.h"
#include "centralizarTexto.h" // Inclui o conteudo desse arquivo
#include <limits> // Define um limite para um tipo de dado
#include <functional> // Biblioteca que oferece varias funçoes, classes, e objetos com referencia a programaçao funcional
using namespace std;

//Receber os valores atributos do eleitor pelo usuario
bool compararID(const Eleitor& e, const unsigned int& id) { // Funçao que recebe dois paramentros constantes eleitor e id
    return e.id == id; // Aqui vai ter uma comparaçao entre os dois objetos se forem igual retorne true e se não false
} // fechamento da funçãoo

bool validarNome(const string& nome) { // Criação de uma função que receba uma variavel constante nome como paramentos onde vamos verificar se o nome é valido conforme as regras
    if (!isalpha(nome[0])) {  // Verifica se o primeiro caractere é uma letra
        return false; //Se o primeiro caractere não for uma letra ela dar como falsa ai ela termina imediatamente
    }
    for (char c : nome) { // Laço de repetição que pecorre cada letra da string
        if (!isalpha(c) && c != ' ') { // Ele verifica se é uma letra ou espaço se der falsa ele retorna falso
            return false; // Se c não for nem letra e nem numero ele retorna falso
        }
    }
    return true; // Significa que não retornou falso e que são caracteres e são espaços em branco ou seja ele retorna true
}

void atribuirValoresEleitor(Eleitor& eleitor, const vector<Eleitor>& eleitores, vector<Candidato>& candidatos) {// Função de candidatos e eleitores
    do {
        cout << "DIGITE O NOME DO ELEITOR: " << endl;
        cin.ignore();
        getline(cin, eleitor.nome); // Lê a linha inteira da entrada padrão e armazena na variavel nome
        cout << endl;

        if (validarNome(eleitor.nome)) { // Validador de nome se retornar true ele vai retornar verdade e logo vai parar o laço com break
            break;
        } else {
            cout << "******************************************************" << endl;
            centralizarTexto("ERRO! O NOME DEVE CONTER APENAS LETRAS E ESPACOS!");
            cout << "******************************************************" << endl;
            cout << endl;
        }
    } while (true); // Vai executar enquanto aquilo for verdade

    string idade_str; // Criação de uma variavel do tipo string
    cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
    cin>> idade_str; // lendo a variavel
    cout << endl;
    while(!all_of(idade_str.begin(), idade_str.end(), ::isdigit)){ // laço testando cada argumento em que o usuario digitar
        cout << "****************************************" << endl;
        centralizarTexto("ERRO! A IDADE DEVE SER UM NUMERO!");
        cout << "****************************************" << endl;
        cout << endl;
        cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
        cin >> idade_str;
        cout << endl;
    }
        eleitor.idade = stoi(idade_str); // Esse aqui converte de string para inteiro

    while (eleitor.idade < 18) {
        cout << "****************************************" << endl;
        centralizarTexto("ELEITOR MENOR DE 18 ANOS.");
        cout << "****************************************" << endl;
        cout << endl;
        cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
        cin>>eleitor.idade;
        cout << endl;
    } // Esse while se encarrega de verificar se o eleitor é menor de 18 anos

    string id_str; // Variavel do tipo inteiro
    cout<<"DIGITE O ID DO ELEITOR (00001 - 99999)"<<endl;
    cin>>id_str; // Lendo a minha variavel
    cout << endl;
    while(!all_of(id_str.begin(), id_str.end(), ::isdigit) || id_str.size() != 5 || stoi(id_str) == 0 || find_if(eleitores.begin(), eleitores.end(), bind(compararID, placeholders::_1, stoi(id_str))) != eleitores.end()){ // Laço de repetiçã que executa até dar certo
    cout << "******************************************************************************************************************************************" << endl;
    centralizarTexto("ERRO DE ID OU SEU ID E DE NO MINIMO 5 NUMEROS OU SEU ID TEM QUE ESTA NA FAIXA DE 00001 - 99999 OU OUTRA PESSOA JA ESTA USANDO O SEU ID");
    cout << "******************************************************************************************************************************************" << endl;
    cout << endl;
    cout<<"DIGITE O ID DO ELEITOR (00001 - 99999)"<<endl;
    cin>>id_str; // Vai ficar lendo o que o usuario digitar
    cout << endl;
}
    eleitor.id = stoi(id_str); // Depois ele converte para inteiro

    //pergunta se o eleitor deseja se candidatar

    string resposta_str; // Declara uma variavel do tipo string
    do { // Vai ficar executando até que seja interropido com laço break
    cout << "************************************************************************" << endl;
    centralizarTexto("DESEJA SE CANDIDATAR PARA A ELEICAO? DIGITE 1 PARA SIM E 0 PARA NAO.");
    cout << "************************************************************************" << endl;
    cin >> resposta_str; // Lendo a variavel
    cout << endl;

    if(resposta_str.size() == 1 && (resposta_str[0] == '0' || resposta_str[0] == '1')) {
        break;
        // Na linha acima Se o que usuario digitar foe exatamente 1 o programa vai executar conjunto de comandos que sera parado com break e depois manda o usuario digitar novamente
    } else {
        cout << "******************************************" << endl;
        centralizarTexto("ERRO! DIGITE 1 PARA SIM E 0 PARA NAO.");
        cout << "******************************************" << endl;
        cout << endl;
    } // Caso não esteja correta
} while(true); // Vai sempre executar enquanto não estiver correto

    int resposta = stoi(resposta_str); // Depois que valida é convertido para string o valor

    if (resposta==1){
        string numero_votacao_str; // Declarando uma variavel numero_votacao_str do tipo string
    do{
    cout << "DIGITE O NUMERO DE VOTACAO DO CANDIDATO " <<eleitor.nome<< "(5 DIGITOS): "<< endl; // pede um dado
    cin >> numero_votacao_str; // Ler esse dado e depois armazena na variavel numero_votacao_str
    cout << endl;
    if(!all_of(numero_votacao_str.begin(), numero_votacao_str.end(), ::isdigit) || numero_votacao_str.size() != 5 || stoi(numero_votacao_str) == 0 || stoi(numero_votacao_str) == eleitor.id || find_if(eleitores.begin(), eleitores.end(), bind(compararID, placeholders::_1, stoi(numero_votacao_str))) != eleitores.end()){ // Caso o usuario não digite numeros e não digite um tamanho de 5 espaços vai ser executado um conjunto de comandos
        cout << "********************************************************************************************************" << endl;
        centralizarTexto("ERRO! O NUMERO DE VOTACAO INVALIDO OU DEVE SER UM NUMERO DE 5 DIGITOS OU NUMERO JA ESTA SENDO USADO!");
        cout << "********************************************************************************************************" << endl;
        cout << endl;
    }else{
        unsigned int numero_votacao = stoi(numero_votacao_str); // Converte a string para um inteiro
        bool numeroExiste = false; // Declara uma variavel booleana que inicializa com false e pecorre a lista de candidatos e se tiver algum igual define como true ai interrope esse laço
        for(const Candidato& c : candidatos){ //Vetor que pecorre o numero de candidatos
            if(c.numero_votacao == numero_votacao){ // Faz a verificação para saber se não é igual
                cout << "**********************************************************************************************" << endl;
                centralizarTexto("ERRO EM INCLUIR CANDIDATO! ESSE NUMERO DE VOTACAO JA ESTA SENDO USADO POR OUTRO CANDIDATO.");
                cout << "**********************************************************************************************" << endl;
                cout << endl;
                numeroExiste = true;
                break; // Responsavel por interroper o loop caso seja valido a entrada
            }
        }
        if(!numeroExiste){// Se o numero de votação não tiver sido usado por nenhum outro candidado o programa exibe esse comandos mostrando a mensagem que foi armazendado com sucesso
            cout << "**********************************************" << endl;
            centralizarTexto("NUMERO DE VOTACAO ARMAZENADO COM SUCESSO!"); // Sera executado caso os id estejam corretos conforme a formata��o e se n�o estiverem iguais
            cout << "**********************************************" << endl;
            Candidato candidato (eleitor, numero_votacao); // Adicionar as informacçes
            candidatos.push_back(candidato); // Candidato com novo elemento e consequente da pra adicionar um novo candidato
            break; // Para o laço
        }
    }
}while(true); // Se encarrega de repetir o laço

}
}


