#include <iostream> // Entrada e saida de codigo e manipula��o
#include <locale.h> // Tradutor conforme o sistema
#include <limits> // Define um limite para um tipo de dado
#include <string> // Uso de strings
#include <vector> // Uso de vetores
#include "candidatos_eleitores.h" // Inclui o arquivo com as classes e funcoes utilizadas
#include <algorithm> // Usado para ordenar e procurar
using namespace std;

int main(){
    setlocale(LC_ALL, ""); // traz para a lingua do sistema operacional
    int numero; // Variavel do tipo local
    int qtd_eleitores = 0;
    vector<Eleitor> eleitores; //Vetor para armazenar os eleitores
    vector<Candidato> candidatos; //Vetor para armazenar os candidatos

    //Cabecalho do sistema eleitoral e creditos
    cout << "SISTEMA ELEITORAL!" << endl << endl;
    cout << "SISTEMA DESENVOLVIDO POR: "<< endl;
    cout << "ESDRAS" << endl;
    cout << "GUILHERME" << endl;
    cout << "HERMESON" << endl;
    cout << "MATHEUS" << endl;
    cout << "PEDRO ARTHUR" << endl << endl;

    // Menu de perguntas
    cout << "MENU: "<< endl;
    cout << "1 - para PARA CONTINUAR! " << endl;
    cout << "2 - PARA SAIR!" << endl;
    cout << "ESCOLHA A OP��O DESEJADA: " << endl;

    while(!(cin >> numero) || (numero != 1 && numero != 2)){// armazenando um valor na variavel e atribuindo dois numero ao menu
    cin.clear(); // limpar o estado do erro
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Toda essa linha descarta a entrada incorreta
    system("cls"); // limpar todo codigo escrito para n�o ficar poluido
    cout << "VOCE DIGITOU ALGO ERRADO, TENTE NOVAMENTE!" << endl << endl; // cada vez que n�o o la�o n�o � atendido volta para o inicio
    cout << "MENU: "<< endl;
    cout << "1 - PARA CONTINUAR! " << endl;
    cout << "2 - PARA SAIR!" << endl;
    cout << "ESCOLHA A OP�AO DESEJADA: " << endl;
    }

    switch(numero){ // verifica os valores digitados pelo usuario
    case 1: { // caso seja verdade todo esse conjunto de codigos ser�o executados
        system("cls"); // limpa o sistema
        cout << "VOC� ENTROU NO SISTEMA!" << endl << endl;
        cout<<"Quantos usuarios irao participar da eleicao?"<<endl;
        cin>>qtd_eleitores; // Definindo quantos usuarios irao participar da eleicao(min 2)
        while(qtd_eleitores < 2){
          cout<<"Impossivel realizar eleicao com menos de 2 pessoas."<<endl;
          cout<<"Quantos usuarios irao participar da eleicao?"<<endl;
          cin>>qtd_eleitores;
            if (qtd_eleitores >=2){
            break;
            }
        }
        int numero_eleitores = qtd_eleitores; //Armazena a quantidade final de eleitores

        // Estrutura de repeticao que registra cada eleitor por meio da funcao "atribuirValoresEleitor"
        for (int i = 0; i < numero_eleitores; ++i) {
            cout << "\n=== Eleitor " << i + 1 << " ===\n";
            Eleitor eleitor("", 0, 0); // Cria um eleitor com valores padroes
            atribuirValoresEleitor(eleitor, eleitores); // Funcao para atribuir valores ao eleitor
            eleitores.push_back(eleitor); //Adiciona o eleitor ao vetor de eleitores
        }

        // Estrutura de repeticao que registra o numero de votacao para cada candidato


        for (const auto& eleitor : eleitores) {
            cout << "\n=== Candidato ===\n";
            adicionarNumeroVotacao(candidatos, eleitor); // Funcao para adicionar numero de votacao
        }

        // Mostra todos os eleitores cadastrados e suas respectivas informacoes

        cout << "\nEleitores cadastrados:\n";
        for (int i = 0; i < numero_eleitores; ++i) {
            cout << "Nome: " << eleitores[i].nome <<endl<< "Idade: " << eleitores[i].idade <<endl<< "ID: " << eleitores[i].id << endl;
            cout <<""<<endl;
        }

        // Mostra todos os candidatos cadastrados e suas respectivas informacoes

        cout << "\nCandidatos cadastrados:\n";
        cout<<""<<endl;
        for (const auto& candidato : candidatos) {
            cout << "Nome: " << candidato.nome <<endl<< "Idade: " << candidato.idade <<endl<< "ID: " << candidato.id <<endl<< "Numero de votacao: " << candidato.numero_votacao << endl;
            cout<<""<<endl;
        }

        break;} // encerra o la�o imediatamente
    case 2: // caso seja verdade todo esse conjunto de codigos ser�o executados
        system("cls"); // limpa o sistema
        cout << "SISTEMA ENCERRADO COM SUCESSO, CLIQUE EM QUALQUER TECLA PARA SAIR!" << endl;
        break; // encerra o la�o imediatamente
    default: // esse comando n�o vai servir de muita coisa por causa do while, mas serve como uma boa pratica de programa��o
        system("cls"); // limpa o sistema
    }
return 0; // fun��o que retorna um inteiro
}
