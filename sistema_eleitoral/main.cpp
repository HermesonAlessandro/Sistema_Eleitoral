#include <iostream> // Entrada e saida de codigo e manipulaçao
#include <locale.h> // Tradutor conforme o sistema
#include <limits> // Define um limite para um tipo de dado
#include <string> // Uso de strings
#include <vector> // Uso de vetores
#include "candidatos_eleitores.h" // Inclui o arquivo com as classes e funcoes utilizadas
#include <algorithm> // Usado para ordenar e procurar
#include "centralizarTexto.h" // // Inclui o conteudo desse arquivo
#include <iomanip> // Biblioteca reponsavel por formatar saida na tela de impressao
using namespace std; // Padrão do c++

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

void mostrarID(const Eleitor& Eleitor){ // Criando uma função mostrarID que recebe um referencia constante do obejeto Eleitor da classe std::stringstream e std::stringstream manipulando string como se fosse fluxo de entrada e saida de dados
    stringstream id_stream; // Permite a manipulação de string na entrada e saida de dados
    id_stream << setfill('0') << setw(5) << Eleitor.id; // Faz o preenchimento com zero com a largura de 5 ou seja o que não tiver digito sera zero
    centralizarTexto("ID: " + id_stream.str()); // Chama função centralizarTexto com string "ID" concatenada com a string formatada com id id_stream.str() que retorna no fluxo id_stream
}

void mostrarEleitor(std::vector<Eleitor>& eleitores, int numero_eleitores){ // Função que recebe dois argumentos o vetor de eleitor e numero inteiro de numero_eleitor
        system("cls"); // Limpa a tela de excução para não ficar muito poluida
        cout << "****************************************" << endl;
        centralizarTexto("NUMERO DE ELEITORES: " + to_string(numero_eleitores)); // Fazendo uma conversão para string para armazenar o conjunto de eleitores
        cout << "****************************************" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        centralizarTexto("ELEITORES CADASTRADOS: ");
        for(int i = 0; i < numero_eleitores; i++){ // Tem esse laço de repetição que pecorre cada eleitor no vetor eleitores para cada eleitor ele imprime o nome, idade, id
            centralizarTexto("NOME: " + eleitores[i].nome); // Concatenando o nome do eleitor
            centralizarTexto("IDADE: " + to_string(eleitores[i].idade)); // Concatenando o a idade do eleitor
            mostrarID(eleitores[i]); // Mostrando o id usando a função criada logo acima
}
         cout << "****************************************" << endl;
}

void mostrarCandidatos(const vector<Candidato>& candidato){ // Função que recebe um vetor de candidatos onde tem algumas propriedades como nome, idade, id, numero_votação
     cout << "****************************************" << endl;
     centralizarTexto("NUMEROS DE CANDIDATOS: " + std::to_string(candidato.size())); // Ele imprime o numero de candidatos convertendo o inteiro para string
     cout << "****************************************" << endl;
     cout << endl;
     cout << "****************************************" << endl;
     centralizarTexto("CANDIDATOS CADASTRADOS:");
     for(const auto& candidato: candidato){ // Loop que pecorre cada candidato no vetor imprindo seu nome idade e etc
        centralizarTexto("NOME: " + candidato.nome); // Concatenando o nome do candidato
        centralizarTexto("IDADE: " + to_string(candidato.idade)); // Concatenando a idade do candidato
        mostrarID(candidato); // Mostrando o id do candidato conforme a função criada logo acima
        stringstream numero_votacao_stream; // Tratamento de entrada e saida de dados
        numero_votacao_stream << setfill('0') << setw(5) << candidato.numero_votacao; // Aqui quando for menor 5 ele vai  completar o resto tudo com zero
        centralizarTexto("NUMERO DA VOTACAO: " + numero_votacao_stream.str()); // Aqui ele vai pegar o valor inteiro convertido para string e mostrar na tela
     }
     cout << "****************************************" << endl;
} // Término da função

void mostrarResultados(const vector<Candidato>& candidatos, int votosEmBranco){ // Funçao serve para mostrar o resultado pecorrendo um vetor pecorrendo um vetor de candidatos e criando uma variavel para armazenar votos em brancos
    system("cls"); // Limpando a tela para não ficar poluido
    cout << "****************************************" << endl;
    centralizarTexto("RESULTADOS DA ELEICAO");
    cout << "****************************************" << endl;
    cout << endl;
    for(const auto& candidato: candidatos){ //Criado um laço de repetição que pecorrera cada candidato
        cout << "****************************************" << endl;
        centralizarTexto("CANDIDATO: " + candidato.nome); // Imprimindo o nome do candidato
        centralizarTexto("VOTOS: " + to_string(candidato.getVotos())); // Imprimindo os votos de cada candidato convertendo o mesmo para inteiro
        cout << "****************************************" << endl;
        cout << endl;
    }

    cout << "****************************************" << endl;
    centralizarTexto("VOTOS EM BRANCO: " + to_string(votosEmBranco)); // Aqui ele imprime a quantidade de votos em branco fazendo a mesma coisa convertendo numero para string
    cout << "****************************************" << endl;
    cout << endl;
}

bool compararIdade(const Candidato& c1, const Candidato& c2) { // Função que leva dois parametros ambos sao referencias a objetos aos quais c1 e c2 se referem e nao podem ser modificada dentro da função retorna um bool que é valor booleano
    return c1.idade < c2.idade; // Ele retorna o resulatado da comparação de c1 e c2 . A função portanto verifica se a idade do candidato c1 é menor do que a idade do c2 retorna true se sim e false para não
}

pair<Candidato, string> determinarVencedor(const vector<Candidato>& candidatos){ // Funçao que recebe um vetor de candidatos como argumento um par de informações que candidato vencedor e metodo de desempate para determinar o vencedor
    Candidato vencedor = candidatos[0];
    string metodoDesempate = "MAIOR NUMERO DE VOTOS";
    // Essas duas linhas logo acima inicializa o vencedor como o primeiro candidato no vetor define o metodo de desempate inicialmente como "maior numero de votos"
    for(const auto& candidato: candidatos){ // Loop que pecorre os candidato no vetor candidatos
        if(candidato.getVotos() > vencedor.getVotos()){
            vencedor = candidato;
            metodoDesempate = "MAIOR NUMERO DE VOTOS";
            // Essas três linhas logo acima se um candidato tem mais votos do que um vencedor atual o candidato atual passa a ser o mais novo campeão utilizando o metodo de desempate como "maior numero de votos"
        }else if(candidato.getVotos() == vencedor.getVotos()){
            if(candidato.idade > vencedor.idade){
                vencedor = candidato;
                metodoDesempate = "MAIOR IDADE";

            }else if(candidato.idade == vencedor.idade && candidato.id > vencedor.id){
                vencedor = candidato;
                metodoDesempate = "MAIOR ID";
            }
            // Basicamente os else if verificam, se o candidato e o vencedor atual tem o mesmo numero de votos o criterio agora é a idade ou seja quem tiver a maior idade ganha se permanecer empatado o criterio de desempate é o id quem tiver o maior id ganha
        }
    }
    return make_pair(vencedor, metodoDesempate); // Funçao retorna um par de informações que são nome do eleitor vitorioso e criterio de desempate utilizado ou não dependendo do caso
}

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
    centralizarTexto("ANTONIO GUILHERME SOUSA LIMA" );
    centralizarTexto("ESDRAS RODRIGUES MILITAO");
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

    string entrada; // Criação de uma variavel para o usuario
    while(true){ // Laço de repetição que inicia automatico
    cin >> entrada; // Leitura da variavel
    if(entrada == "1" || entrada == "2"){
        numero = stoi(entrada);
        break; // Basicamente se o numero for 1 ou 2 ele vai converter para inteiro armazenando na variavel numero e depois encerra o break
    }else{
        cin.clear(); // Limpa buffer de entrada
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignora o que esta escrito incorretamente pelo o usuario
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
        cout << endl;
        cout << "ESCOLHA A OPCAO DESEJADA: " << endl;
        } // Imprime novamente a tela
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
        } // While responsavel por ver se o que o usuario digitar numero maior ou igual a 2 e se é um numero
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
            sort(candidatos.begin(), candidatos.end(), compararIdade); // Aqui ele faz a ordenação do vetor de candidatos por meio da idade
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
        }else if(candidatos.size() < 2){ // Fazendo a verificação dos candidatos cadastrados antes da eleição
            cout << "******************************************************************************" << endl;
            centralizarTexto("NAO E POSSIVEL INICIAR A ELEICAO, PRECISAMOS DE PELO MENOS DOIS CANDIDATOS");
            cout << "******************************************************************************" << endl;
            return 0; // Encerra o programa
        }
        int iniciarTelaEleicao; // Variavel para eleição
        string entrada; // variável que armazena a entrada do usuario
        cout << "****************************************" << endl;
        centralizarTexto("DESEJA INICIAR A ELEICAO?");
        centralizarTexto("1 - SIM");
        centralizarTexto("0 - NAO, QUERO SAIR DO SISTEMA");
        cout << "****************************************" << endl;
        cout << endl;
        cout << "ESCOLHA A OPCAO DESEJADA: " << endl;
        // Menu da eleição
        while(true){ //Laço de repetição ja sendo executado pois é verdade
            cin >> entrada;
            if(entrada == "1" || entrada == "0"){ // Caso o usuario digite uma dessas informações
                iniciarTelaEleicao = stoi(entrada); // Vira a entrada convrtida para inteiro
                break;
            }else{
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
    }   int votoEmBranco = 0; // Atribuindo uma variavel e informando que ela vai se inicializar por zero
        if(iniciarTelaEleicao == 1){ // Condicional que verifica quando a variavel for igual 1
            system("cls"); // LImpa a tela
            for(int i = 0; i < numero_eleitores; i++){ // Laço de repetição para cada eleitor armazenado na variavel i servindo com contador
                cout << "\n=== ELEITOR " << i + 1 << " ===\n";
                cout << endl;
                cout << "****************************************" << endl;
                centralizarTexto("ELEITOR: " + eleitores[i].nome); // Imprime o nome de cada eleitor que se cadastrar
                cout << "****************************************" << endl;
                cout << endl;

                mostrarCandidatos(candidatos); //As informações logo acima imprimem cada eleitor e tambem mostra a lista de candidatos


                cout << endl;
                cout << "**********************************************************************" << endl;
                centralizarTexto("DIGITE O NUMERO DE VOTACAO DO CANDIDATO OU 0 PARA VOTAR EM BRANCO");
                cout << "**********************************************************************" << endl;
                // Seguindo ele faz o pedido para o numero de votaçao

                string voto_str; //Variavel para a votação
                do{
                    cin >> voto_str; // Lendo a variavel
                    cout << endl;
                if(voto_str == "0" || (voto_str.size() == 5 && all_of(voto_str.begin(), voto_str.end(), ::isdigit))){ // Verifica a entrada do usuario é valida, no caso um voto de 0 e 5 digitos representando numero de votação
                    if(voto_str == "0"){
                        votoEmBranco++;
                        // Essa condição verifica se o usuario digitou 0 se for verdade a variavel votoEmBranco é imcrementada

                    }else{
                        bool numeroVotacaoExiste = false;
                        int voto = stoi(voto_str);
                        for(auto& candidado: candidatos){
                            if(candidado.numero_votacao == voto){
                                candidado.adcionarVoto();
                                numeroVotacaoExiste = true;
                                break;
                            }
                        }
                        // Esse senão significa que o eleitor voltou em algum candidato ou seja ele vai pecorrer o vetor de candidatos e vai ver se algum candidato tem aquele numero de votação para incrementar na contagem de votos desse candidato
                        if(!numeroVotacaoExiste){
                        cout << "********************************************************************************************" << endl;
                        centralizarTexto("ERRO! O NUMERO DE VOTACAO DIGITADO NAO CORRESPONDE A NENHUM CANDIDATO, DIGITE NOVAMENTE.");
                        cout << "********************************************************************************************" << endl;
                            continue;
                        }
                        // Essa condição é executada quando nenhum numero de votação é encontrada na vetor de candidatos, o codigo exibe o erro e continua com a interação com loop while
                    }
                    cout << "****************************************" << endl;
                    centralizarTexto("VOTO CADASTRADO COM SUCESSO!");
                    cout << "****************************************" << endl;
                    break;
                    // Se o voto for valido codigo exibe essa mensagem de sucesso e sai do loop while
                }else{
                    cout << "****************************************************************************" << endl;
                    centralizarTexto("ERRO! DIGITE O NUMERO DE VOTACAO DO CANDIDATO OU 0 PARA VOTAR EM BRANCO.");
                    cout << "****************************************************************************" << endl;
                    }
                }while(true);
                // Se a entrada  do usuario não for valida, o codigo exibe uma mensagem de erro e continua para a proxima interação com loop while
            }
            mostrarResultados(candidatos, votoEmBranco); // Exibe o resultado da eleição
            pair<Candidato, string> resultado = determinarVencedor(candidatos);
            cout << "****************************************" << endl;
            centralizarTexto("O VENCEDOR DA ELEICAO E: " + resultado.first.nome); // Imprimindo e pegando o primeiro valor no tratamentos de dados cujo o nome é resultado
            cout << "****************************************" << endl;
            cout << endl;
            cout << "O METODO DE DESEMPATE FOI: " << resultado.second << endl; // Imprimindo e pegando o primeiro valor como referencia que é no second e olhando na estrutura de dados cujo o nome é resultado
            // Finalmente é chamado a função determinarVencedor para determinar o vencedor da eleição e exibe o nome e o metodo de desempate utilizado
        }
        else{
        system("cls"); // limpa o sistema
        cout << "**********************************************************************" << endl;
        centralizarTexto("SISTEMA ENCERRADO COM SUCESSO, CLIQUE EM QUALQUER TECLA PARA SAIR!");
        cout << "**********************************************************************" << endl;
        } // Else sera executado quando o usuario digitar 0 ou numero de 5 digitos caso tenha algum candidato ele sai do loop se não fica no loop infinito até colocar a informação verdadeira
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
