#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "candidatos_eleitores.h"
#include "centralizarTexto.h" // Inclui o conteudo desse arquivo
#include <limits> // Define um limite para um tipo de dado
#include <functional> // Biblioteca que oferece varias funçoes, classes, e objetos com referencia a programação funcional
using namespace std;

//Receber os valores atributos do eleitor pelo usuario

bool compararID(const Eleitor& e, const unsigned int& id) { // Função que recebe dois paramentros constantes eleitor e id
    return e.id == id; // Aqui vai ter uma comparação entre os dois objetos se forem igual retorne true e se não false
} // fechamento da função


void atribuirValoresEleitor(Eleitor& eleitor, const vector<Eleitor>& eleitores) {
    cout<<"DIGITE O NOME DO ELEITOR: "<<endl;
    cin>>eleitor.nome;
    cout << endl;
    while(!all_of(eleitor.nome.begin(), eleitor.nome.end(), ::isalpha)){ // Estes são os iteratores para o inicio e fim de uma string
        cout << "********************************************" << endl;
        centralizarTexto("ERRO! O NOME DEVE CONTER APENAS LETRAS!");
        cout << "********************************************" << endl;
        cout << endl;
        cout<<"DIGITE O NOME DO ELEITOR: "<<endl;
        cin >> eleitor.nome;
        cout << endl;
    } // Esse while faz a verificação do que o usuario digitar caso não seja uma letra ela manda fazer o procedimento novamente

    cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
    cin>>eleitor.idade;
    cout << endl;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "****************************************" << endl;
        centralizarTexto("ERRO! A IDADE DEVE SER UM NUMERO!");
        cout << "****************************************" << endl;
        cout << endl;
        cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
        cin >> eleitor.idade;
        cout << endl;
    } // Esse while faz a verificação do que o cara digitar caso não seja satisfatorio ele limpa e ignora e manda o usuario digitar novamente
    while (eleitor.idade < 18) {
        cout << "****************************************" << endl;
        centralizarTexto("ELEITOR MENOR DE 18 ANOS.");
        cout << "****************************************" << endl;
        cout << endl;
        cout<<"DIGITE A IDADE DO ELEITOR"<<endl;
        cin>>eleitor.idade;
        cout << endl;
    } // Esse while se encarrega de verificar se o eleitor é menor de 18 anos

    cout<<"DIGITE O ID DO ELEITOR (00000 - 99999)"<<endl;
    cin>>eleitor.id;
    cout << endl;
    while(cin.fail() || eleitor.id < 10000 || eleitor.id > 99999 || find_if(eleitores.begin(), eleitores.end(), bind(compararID, placeholders::_1, eleitor.id)) != eleitores.end()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.fail() || eleitor.id < 10000 || eleitor.id > 99999) {
    cout << "************************************************" << endl;
        centralizarTexto("ERRO! O ID DEVE SER UM NUMERO DE 5 DIGITOS!");
    cout << "************************************************" << endl;
    } else {
        cout << "********************************************************" << endl;
        centralizarTexto("ERRO! ESSE ID JÁ ESTÁ SENDO USADO POR OUTRO ELEITOR.");
        cout << "********************************************************" << endl;
    }
    cout << endl;
    cout<<"DIGITE O ID DO ELEITOR (00000 - 99999)"<<endl;
    cin>>eleitor.id;
    cout << endl;
} // Esse while se encarrega de testar se os dois id são iguais, caso sejam retorna para o inicio madando o usuario digitar o id novamente
    while(true){
        if (eleitor.id > 99999){
            cout<<"ERRO EM INCLUIR ELEITOR! DIGITE O ID NA FAIXA ENTRE 00000 E 99999."<<endl;
            cout<<"DIGITE  O ID DO ELEITOR (00000 - 99999)"<<endl;
            cin>>eleitor.id;
        }else{
            break;
        }
    } // Esse id é executado quando o usuario digitar algo diferente de numeros ou seja na formatação
}

// Função para adicionar o número de votação do candidato
void adicionarNumeroVotacao(vector<Candidato>& candidatos, const Eleitor& eleitor) {
    unsigned int numero_votacao; // Variavel do tipo unsigned int que sera usada para armazenar o numero de votação inserido pelo usuario
    bool numeroExiste; // Teste lógico
    do{
        cout << "DIGITE O NUMERO DE VOTAÇÃO DO CANDIDATO " <<eleitor.nome<< "(5 DIGITOS): "<< endl; // pede um dado
        cin >> numero_votacao; // Ler esse dado e depois armazena na variavel numero_votacao
        cout << endl;
        if(cin.fail() || numero_votacao < 10000 || numero_votacao > 99999){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "**************************************************************" << endl;
            centralizarTexto("ERRO! O NUMERO DE VOTAÇÃO DEVE SER UM NUMERO DE 5 DIGITOS!");
            cout << "**************************************************************" << endl;
            cout << endl;
            numeroExiste;
            // Verifica se a entrada é valida, faz o teste e se der falso ele define a variavel numeroExiste = true
        }else{
            numeroExiste = false;
            for(const Candidato& c : candidatos){
             if(c.numero_votacao == numero_votacao){
                cout << "**********************************************************************************************" << endl;
                centralizarTexto("ERRO EM INCLUIR CANDIDATO! ESSE NUMERO DE VOTAÇÃO JÁ ESTÁ SENDO USADO POR OUTRO CANDIDATO.");
                cout << "**********************************************************************************************" << endl;
             cout << endl;
             numeroExiste = true;
             break; // Responsavel por interroper o loop caso seja valido a entrada
             }
            }
            // Utiliza a função find_if para verificar se o numero de votação não esta sendo usado por outro candidato, caso esteja haverá um erro define a variavel numeroExiste = true
        }
    }while(numeroExiste); // O loop continuará enquando a variavel numeroExiste for true

    cout << "**********************************************" << endl;
    centralizarTexto("NUMERO DE VOTAÇÃO ARMAZENADO COM SUCESSO!"); // Sera executado caso os id estejam corretos conforme a formatação e se não estiverem iguais
    cout << "**********************************************" << endl;

    candidatos.emplace_back(eleitor, numero_votacao); // Adicionar as informacões
}
