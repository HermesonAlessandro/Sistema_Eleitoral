#include <iostream> // Entrada e saida de codigo e manipulação
#include <locale.h> // Tradutor conforme o sistema
#include <limits> // Defini um limite para um tipo de dado
using namespace std;

int main(){
    setlocale(LC_ALL, ""); // traz para a lingua do sistema operacional
    int numero; // Variavel do tipo local
    cout << "Sistema Eleitoral!" << endl << endl; // Da linha 9 até a linha 15 estão os desenvolvedores do projeto!
    cout << "Sistema desenvolvido por: "<< endl;
    cout << "Esdras" << endl;
    cout << "Guilherme" << endl;
    cout << "Hermeson" << endl;
    cout << "Matheus" << endl;
    cout << "Pedro Arthur" << endl << endl;

    cout << "Menu: "<< endl;
    cout << "1 - para continuar! " << endl;
    cout << "2 - para sair!" << endl;
    cout << "escolha a opção desejada: " << endl; // Menu de perguntas

    while(!(cin >> numero) || (numero != 1 && numero != 2)){// armazenando um valor na variavel e atribuindo dois numero ao menu
    cin.clear(); // limpar o estado do erro
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Toda essa linha descarta a entrada incorreta
    system("cls"); // limpar todo codigo escrito para não ficar poluido
    cout << "VOCÊ DIGITOU ALGO ERRADO, TENTE NOVAMENTE!" << endl << endl; // cada vez que não o laço não é atendido volta para o inicio
    cout << "Menu: "<< endl;
    cout << "1 - para continuar! " << endl;
    cout << "2 - para sair!" << endl;
    cout << "escolha a opção desejada: " << endl;
    }

    switch(numero){ // verifica os valores digitados pelo usuario
    case 1: // caso seja verdade todo esse conjunto de codigos serão executados
        system("cls"); // limpa o sistema
        cout << "Você entrou no sistema!" << endl;
        break; // encerra o laço imediatamente
    case 2: // caso seja verdade todo esse conjunto de codigos serão executados
        system("cls"); // limpa o sistema
        cout << "Sistema encerrado com sucesso, clique em qualquer tecla para sair!" << endl;
        break; // encerra o laço imediatamente
    default: // esse comando não vai servir de muita coisa por causa do while, mas serve como uma boa pratica de programação
        system("cls"); // limpa o sistema
    }
return 0; // função que retorna um inteiro
}
