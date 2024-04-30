#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "candidatos_eleitores.h"

using namespace std;

int main() {

// Definindo quantos usuarios irao participar da eleicao
    int qtd_eleitores;
    cout<<"Quantos usuarios irao participar da eleicao?"<<endl;
    cin>>qtd_eleitores;
    while(qtd_eleitores < 2){
          cout<<"Impossivel realizar eleicao com menos de 2 pessoas."<<endl;
          cout<<"Quantos usuarios irao participar da eleicao?"<<endl;
          cin>>qtd_eleitores;
          if (qtd_eleitores >=2){
             break;
          }
    }
    const int numero_eleitores = qtd_eleitores;

    vector<Eleitor> eleitores;
// Estrutura de repeticao que executa a funcao "atribuirValoresEleitor" uma vez para cada eleitor
    for (int i = 0; i < numero_eleitores; ++i) {
        cout << "\n=== Eleitor " << i + 1 << " ===\n";
        Eleitor eleitor("", 0, 0);
        atribuirValoresEleitor(eleitor, eleitores);
        eleitores.push_back(eleitor);

    }

// Estrutura de repeticao que adciona o numero de votacao que o usuario escolher para cada candidato.

    vector<Candidato> candidatos;
    for (const auto& eleitor : eleitores) {
        cout << "\n=== Candidato ===\n";
        adicionarNumeroVotacao(candidatos, eleitor);
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

    return 0;
}




