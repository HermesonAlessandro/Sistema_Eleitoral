#include <string> // Usado para a criação de classes do tipo string
#include <vector> // Usado para fornecer utilidades de vetores dinâmicos

using namespace std; // Padrão da linguagem c++

// Criar classe eleitor
class Eleitor{
public:
    Eleitor() : idade(0), id(0) {}
    Eleitor(const string& iNome, const unsigned int iIdade, const unsigned int iID) : nome(iNome), idade(iIdade), id(iID) {}
    string nome;
    unsigned int idade;
    unsigned int id;
}; // Classe que contem os seguintes atributos nome, idade, id;


class Candidato : public Eleitor{ // Criar  classe Candidato (Herdando nome, idade e ID do eleitor e adicionando mais um atributo que é o numero de votação
    public:
    Candidato(const Eleitor& eleitor, unsigned int iNumeroVotacao) : Eleitor(eleitor), numero_votacao(iNumeroVotacao),votos(0) {}
    // Metodo para adicionar votos
    void adcionarVoto() {
         votos++;
    }
    // Metodo para obter a contagem de votos
    unsigned int getVotos() const {
        return votos;
    }

    unsigned int numero_votacao; // Definição de uma variavel inteira sem sinal

    private: // Argumentos do tipo privado
    unsigned int votos; // Atributo para armazenar a quantidade de votos, definindo uma variavel inteira sem sinal
};

void atribuirValoresEleitor(Eleitor& eleitor, const vector<Eleitor>& eleitores, vector<Candidato>&candidatos); // Atribuidor de valores para o eleitor




