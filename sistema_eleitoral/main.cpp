#include <iostream> // Entrada e saida de codigo e manipulaçao
#include <locale.h> // Tradutor conforme o sistema
#include <limits> // Define um limite para um tipo de dado
#include <string> // Uso de strings
#include <vector> // Uso de vetores
#include "candidatos_eleitores.h" // Inclui o arquivo com as classes e funcoes utilizadas
#include <algorithm> // Usado para ordenar e procurar
#include "centralizarTexto.h" // // Inclui o conteudo desse arquivo
#include <iomanip>
using namespace std;

//função para centralizar o texto
void centralizarTexto(string texto){ // Definindo a função que é vazia que recebe como argumento um texto do tipo string
    int larguraconsole = 40; // Define isso para a largura da janela do console
    int espaco = (larguraconsole - texto.size() - 4 ) / 2; // pega o tamanho do texto e subtrai da largura do console, subtraimos 4 para os asteriscos e depois divide por 2, defini o numero de espaços em branco antes do texto ser empresso
    cout << "* "; // imprime um asterisco seguido de um espaço
    for(int i = 0; i < espaco; i++) cout << " "; // imprimir espaços em branco, movimentando o texto para direita dando uma aparencia de centraliazado
    cout << texto; // o texto é impresso
    for(int i = 0; i < espaco; i ++) cout << " "; // funciona da mesma maneira so que a difereça e que esse loop é executado a apos a impressão do texto
    if(texto.size()% 2 != 0) cout << " "; // para ajustar se o tamanho do texto for impar
    cout << " *" << endl; // imprime um espaço seguido de um asterisco na tela de console em seguida pula a proxima linha
}

void mostrarEleitor(std::vector<Eleitor>& eleitores, int numero_eleitores){ // Função que recebe dois argumentos o vetor de eleitor e numero inteiro de numero_eleitor
        system("cls");
        cout << "****************************************" << endl;
        centralizarTexto("NUMERO DE ELEITORES: " + to_string(numero_eleitores)); // Fazendo uma conversão para string para armazenar o conjunto de eleitores
        cout << "****************************************" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        centralizarTexto("ELEITORES CADASTRADOS: ");
        for(int i = 0; i < numero_eleitores; i++){ // Tem esse laço de repetição que pecorre cada eleitor no vetor eleitores para cada eleitor ele imprime o nome, idade, id
            centralizarTexto("NOME: " + eleitores[i].nome);
            centralizarTexto("IDADE: " + to_string(eleitores[i].idade));
            centralizarTexto("ID: " + to_string(eleitores[i].id));
}
         cout << "****************************************" << endl;
}

void mostrarCandidatos(const vector<Candidato>& candidato){ // Função que recebe um vetor de candidatos onde tem algumas propiedades como nome, idade, id, numero_votação
     cout << "****************************************" << endl;
     centralizarTexto("NUMEROS DE CANDIDATOS: " + std::to_string(candidato.size())); // Ele imprime o numero de candidatos convertendo o inteiro para string
     cout << "****************************************" << endl;
     cout << endl;
     cout << "****************************************" << endl;
     centralizarTexto("CANDIDATOS CADASTRADOS:");
     for(const auto& candidato: candidato){ // Loop que pecorre cada candidato no vetor imprindo seu nome idade e etc
        centralizarTexto("NOME: " + candidato.nome);
        centralizarTexto("IDADE: " + to_string(candidato.idade));
        centralizarTexto("ID: " + to_string(candidato.id));
        centralizarTexto("NUMERO DA VOTACAO: " + to_string(candidato.numero_votacao));
     }
     cout << "****************************************" << endl;
} // Término da função

int main(){
    setlocale(LC_ALL, ""); // traz para a lingua do sistema operacional
    int numero; // Variavel do tipo local
    int qtd_eleitores = 0;
    vector<Eleitor> eleitores; //Vetor para armazenar os eleitores
    vector<Candidato> candidatos; //Vetor para armazenar os candidatos
    //Cabecalho do sistema eleitoral e creditos
    cout << "****************************************" << endl;
    centralizarTexto("SISTEMA ELEITORAL");
    centralizarTexto("SISTEMA DESENVOLVIDO POR: ");
    centralizarTexto("ESDRAS RODRIGUES MILITAO" );
    centralizarTexto("ANTONIO GUILHERME SOUSA LIMA");
    centralizarTexto("HERMESON ALESSANDRO MELO DE SOUSA");
    centralizarTexto("MATHEUS LEITE LIMA");
    centralizarTexto("PEDRO ARTHUR CARVALHO MACHADO");
    cout << "****************************************" << endl;
    cout << endl;
    cout << endl;

    // Menu de perguntas
    cout << "****************************************" << endl;
    centralizarTexto("MENU:");
    centralizarTexto("1 - PARA CONTINUAR!");
    centralizarTexto("2 - PARA SAIR!");
    cout << "****************************************" << endl;
    cout << endl;
    cout << "ESCOLHA A OPCAO DESEJADA: " << endl;

    while(!(cin >> numero) || (numero != 1 && numero != 2)){// armazenando um valor na variavel e atribuindo dois numero ao menu
    cin.clear(); // limpar o estado do erro
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Toda essa linha descarta a entrada incorreta
    system("cls");// limpar todo codigo escrito para n�o ficar poluido
    cout << "**********************************************" << endl;
    centralizarTexto("VOCE DIGITOU ALGO ERRADO, TENTE NOVAMENTE!");// cada vez que não o laço não é atendido volta para o inicio
    cout << "**********************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "****************************************" << endl;
    centralizarTexto("MENU: ");
    centralizarTexto("1 - PARA CONTINUAR! ");
    centralizarTexto("2 - PARA SAIR!");
    cout << "****************************************" << endl;
    cout << "ESCOLHA A OPCAO DESEJADA: " << endl;;
    }

    switch(numero){ // verifica os valores digitados pelo usuario
    case 1: { // caso seja verdade todo esse conjunto de codigos serão executados
        system("cls"); // limpa o sistema
        cout << "****************************************" << endl;
        centralizarTexto("VOCE ENTROU NO SISTEMA, BEM VINDO!");
        cout << "****************************************" << endl;
        cout << endl;
        cout << "************************************************************" << endl;
        centralizarTexto("QUANTOS USUARIOS IRAO PARTICIPAR DA ELEICAO? (MINIMO 2)");
        cout << "************************************************************" << endl;
        cin>>qtd_eleitores;// Definindo quantos usuarios irao participar da eleicao(min 2)
        cout << endl;
        while(cin.fail() || qtd_eleitores < 2){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "**********************************************" << endl;
            centralizarTexto("ERRO! DIGITE NUMEROS MAIORES OU IGUAL A 2!");
            cout << "**********************************************" << endl;
            cin >> qtd_eleitores;
            cout << endl;
        } // While responsavel por ver se o que o usuario digitar � maior ou igual a 2 e se � um numero
        cout << "****************************************" << endl;
        centralizarTexto("QUANTIDADE REGISTRADA COM SUCESSO!");
        cout << "****************************************" << endl;
        cout << endl;
        while(true){
            if (qtd_eleitores >=2){
            break;
            }
        }
        int numero_eleitores = qtd_eleitores; //Armazena a quantidade final de eleitores

        // Estrutura de repeticao que registra cada eleitor por meio da funcao "atribuirValoresEleitor"
        for (int i = 0; i < numero_eleitores; ++i) {
            cout << "\n=== ELEITOR " << i + 1 << " ===\n";
            Eleitor eleitor("", 0, 0); // Cria um eleitor com valores padroes
            atribuirValoresEleitor(eleitor, eleitores, candidatos); // Funcao para atribuir valores ao eleitor e perguntar se quer se candidatar
            eleitores.push_back(eleitor);//Adiciona o eleitor ao vetor de eleitores e/ou candidatos
            cout << "****************************************" << endl;
            centralizarTexto("ELEITOR CADASTRADO COM SUCESSO!");
            cout << "****************************************" << endl;
        }
        cout << endl;
        mostrarEleitor(eleitores, numero_eleitores); // Chamando a função MostrarEleitor
        cout << endl;
        mostrarCandidatos(candidatos); // Chamando a função mostrarCandidatos
        cout << endl;

        if(candidatos.size() < 1){ // Fazendo a verificação de quantos candidatos tem no sistema
            cout << "****************************************" << endl;
            centralizarTexto("NAO E POSSIVEL INICIAR A ELEICAO.");
            centralizarTexto("NAO HA CANDIDATOS SUFICIENTES.");
            cout << "****************************************" << endl;
            return 0; // Encerra o programa
        }

        int iniciarTelaEleicao; // Variavel para eleição
        cout << "****************************************" << endl;
        centralizarTexto("DESEJA INICIAR A ELEICAO?");
        centralizarTexto("1 - SIM");
        centralizarTexto("0 - NAO, QUERO SAIR DO SISTEMA");
        cout << "****************************************" << endl;
        cout << endl;
        cout << "ESCOLHA A OPCAO DESEJADA: " << endl;
        // Menu da eleição
        while(!(cin >> iniciarTelaEleicao)|| (iniciarTelaEleicao !=1 && iniciarTelaEleicao !=0)){ //Laço de repetição para caso o usuario digite algo diferente de 0 e 1
            cin.clear(); // Limpa a tela
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora e passa para a proxima linha
            system("cls"); // Limpo a execução para não ficar poluido de informações
            cout << "**********************************************" << endl;
            centralizarTexto("VOCE DIGITOU ALGO ERRADO, TENTE NOVAMENTE!");
            cout << "**********************************************" << endl;
            cout << endl;
            cout << endl;
            cout << "****************************************" << endl;
            centralizarTexto("DESEJA INICIAR A ELEICAO?");
            centralizarTexto("1 - SIM");
            centralizarTexto("0 - NAO, QUERO SAIR DO SISTEMA");
            cout << "****************************************" << endl;
            cout << endl;
            cout << "ESCOLHA A OPCAO DESEJADA: " << endl;
            // Exibo o sistema novamente para o usuario digitar até que ele digite algo conferente
        }
        if(iniciarTelaEleicao == 1){

        }else{
        system("cls"); // limpa o sistema
        cout << "**********************************************************************" << endl;
        centralizarTexto("SISTEMA ENCERRADO COM SUCESSO, CLIQUE EM QUALQUER TECLA PARA SAIR!");
        cout << "**********************************************************************" << endl;
        } // Else sera executado quando o usuario digitar 0
    }

        break; // encerra o laço imediatamente
    case 2: // caso seja verdade todo esse conjunto de codigos serao executados
        system("cls"); // limpa o sistema
        cout << "**********************************************************************" << endl;
        centralizarTexto("SISTEMA ENCERRADO COM SUCESSO, CLIQUE EM QUALQUER TECLA PARA SAIR!");
        cout << "**********************************************************************" << endl;
        break; // encerra o laço imediatamente
    default: // esse comando não vai servir de muita coisa por causa do while, mas serve como uma boa pratica de programação
        system("cls"); // limpa o sistema
    }
return 0; // funçãoo que retorna um inteiro
}

