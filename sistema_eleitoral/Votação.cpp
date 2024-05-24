#include <iostream>
#include <locale.h> // Tradutor conforme o sistema
#include <limits> // Define um limite para um tipo de dado
#include <string> // Uso de strings
#include <vector> // Uso de vetores
#include "candidatos_eleitores.h" // Inclui o arquivo com as classes e funcoes utilizadas
#include <algorithm> // Usado para ordenar e procurar
#include "centralizarTexto.h"

using namespace std;
void votação();
void votar(vector<Eleitor>& eleitores, vector<Candidato>& candidatos) {
    //função votar, acessando o vetor Eleitores e vetor candidatos

    unsigned int idEleitor;
    //atribuir o valor int ao id do eleitor

    unsigned int numeroVotacao;
    //atribuir o valor int ao numero de votação

    cout << "Digite o ID do eleitor: ";
    //pedir o id do eleitor

    cin >> idEleitor;
    //armazenar o id dentro do id eleitor

    // Verificar se o eleitor existe
    if (!verificarEleitor(eleitores, idEleitor)) {
        cout << "Eleitor não encontrado!" << endl;
        //caso eleitor não ser encontrado irá exibir essa mensagem
        return;
    }

    Eleitor* eleitor = obterEleitor(eleitores, idEleitor);
    if (eleitor == nullptr) {
        cout << "Erro ao obter o eleitor!" << endl;
        //caso tiver error ao obter o eleitor.
        return;
    }

    cout << "Digite o número de votação do candidato: ";
    //ira pedir o numero de votação ao eleitor
    cin >> numeroVotacao;

    // Verificar se o candidato existe
    if (!verificarCandidato(candidatos, numeroVotacao)) {
        cout << "Candidato não encontrado!" << endl;
        //se o candidato não for encontrado
        return;
    }

    Candidato* candidato = obterCandidato(candidatos, numeroVotacao);
    if (candidato == nullptr) {
        cout << "Erro ao obter o candidato!" << endl;
        //caso o numero do candidadato tiver erro.
        return;
    }

    // Incrementar o voto ao candidato
    candidato->adicionarVoto();
    cout << "Voto registrado com sucesso!" << endl;
    //voto confirmado após as etapas de verificação
}
