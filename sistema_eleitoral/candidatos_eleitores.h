#include <string>
#include <vector>

using namespace std;

//Criar classe eleitor

class Eleitor{
public:
    Eleitor() : idade(0), id(0) {}
    Eleitor(const string& iNome, const unsigned int iIdade, const unsigned int iID) : nome(iNome), idade(iIdade), id(iID) {}
    string nome;
    unsigned int idade;
    unsigned int id;
};

//Criar  classe Candidato (Herdando nome, idade e ID do eleitor

class Candidato : public Eleitor{
    public:
    Candidato(const Eleitor& eleitor, unsigned int iNumeroVotacao) : Eleitor(eleitor), numero_votacao(iNumeroVotacao),votos(0) {}
    //Metodo para adicionar votos
    void adcionarVoto() {
         votos++;
    }
    //Metodo para obter a contagem de votos
    unsigned int getVotos() const {
        return votos;
    }

    unsigned int numero_votacao;

    private:
    unsigned int votos; //Atributo para armazenar a quantidade de votos
};

void atribuirValoresEleitor(Eleitor& eleitor, const vector<Eleitor>& eleitores, vector<Candidato>&candidatos);


