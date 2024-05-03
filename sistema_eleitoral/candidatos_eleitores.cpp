#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>
#include "candidatos_eleitores.h"

using namespace std;

//Receber os valores atributos do eleitor pelo usuario

void atribuirValoresEleitor(Eleitor& eleitor, const vector<Eleitor>& eleitores) {
    cout<<"Digite o nome do eleitor"<<endl;
    cin>>eleitor.nome;
    cout<<"Digite a idade do eleitor"<<endl;
    cin>>eleitor.idade;
    
    while (eleitor.idade < 18) {
        cout<<"Eleitor menor de 18 anos."<<endl;
        cout<<"Digite a idade do eleitor"<<endl;
        cin>>eleitor.idade;
    }
    
    cout<<"Digite o id do eleitor (00000 - 99999)"<<endl;
    cin>>eleitor.id;
    while(true){
        if (eleitor.id > 99999){
            cout<<"Erro em incluir eleitor! Digite o ID na faixa entre 00000 e 99999."<<endl;
            cout<<"Digite o id do eleitor (00000 - 99999)"<<endl;
            cin>>eleitor.id;
        }else if(find_if(eleitores.begin(), eleitores.end(), [&](const Eleitor& e){ return e.id == eleitor.id; }) != eleitores.end()) {
          cout<<"Erro em incluir eleitor! Esse ID ja esta sendo usado por outro eleitor."<<endl;
          cout<<"Digite o id do eleitor (00000 - 99999)"<<endl;
          cin>>eleitor.id;
        }else{
            break;
        }
    }
} 

// Função para adicionar o número de votação do candidato

void adicionarNumeroVotacao(vector<Candidato>& candidatos, const Eleitor& eleitor) {
    unsigned int numero_votacao;
    cout << "Digite o numero de votacao do candidato " <<eleitor.nome<< "(5 digitos): "<< endl;
    cin >> numero_votacao;
//Nao permitir numeros de votacao menores de 5 digitos.    
    while (numero_votacao < 10000 || numero_votacao > 99999) {
        cout << "Numero de votacao invalido!" << endl;
        cout << "Digite o numero de votacao do candidato " <<eleitor.nome<< "(5 digitos): "<< endl;
        cin >> numero_votacao;
    }
//Garantir que candidatos nao tenham o mesmo numero de votacao    
    while (find_if(candidatos.begin(), candidatos.end(), [&](const Candidato& c) { return c.numero_votacao == numero_votacao; }) != candidatos.end()) {
        cout << "Erro em incluir candidato! Esse numero de votacao ja esta sendo usado por outro candidato." << endl;
        cout << "Digite o numero de votacao do candidato " <<eleitor.nome<< "(5 digitos): "<< endl;
        cin >> numero_votacao;
    }
//Adcionar as informacoes    
    candidatos.emplace_back(eleitor, numero_votacao);
}






