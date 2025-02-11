// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Inclusão do arquivo de cabeçalho 'Binary Tree Create'
#include "binaryTreeCreate.h"
// Inclusão das bibliotecas necessárias
#include <iostream>
#include <string>
#include <locale>
using namespace std;

// Implementação da função principal Main()
int main() {
    // Configuração para permitir a formatação UTF-8 na exibição das mensagens
    setlocale( LC_ALL, "" );

    // Declaração de um objeto tree do tipo BinaryTreeCreate
    BinaryTreeCreate tree;
    // Declaração da variável option para armazenar a opção do usuário
    int option;

    // Laço de repetição para exibir o menu
    do {
        cout << "=======================================" << endl;
        wcout << L"= CRIAÇÃO E LEITURA DE ÁRVORE BINÁRIA =" << endl;
        cout << "=======================================" << endl;
        cout << endl;

        wcout << L"Escolha um arquivo para criar a árvore e exibir:" << endl;
        cout << "1 - exemplo1.tree" << endl;
        cout << "2 - exemplo2.tree" << endl;
        cout << "3 - Informar nome do arquivo" << endl;
        cout << "4 - Sair" << endl;
        cout << "=======================================" << endl;
        cout << endl;

        // Solicito que o usuário digite uma opção
        wcout << L"Digite uma opção: " << endl;
        cout << "- ";
        cin >> option;
        cout << endl;

        // Enquanto a resposta for diferente de int 
        // apresento uma mensagem de erro e peço para
        // tentar novamente
        while (cin.fail()) {
            cin.clear();

            wcout << L"Opção inválida. Tente novamente!" << endl;
            cout << "- ";
            cin >> option;
            cout << endl;
        }

        // Verifico qual opção foi escolhida
        switch (option) {
            // Se a opção for 1
            case 1:
                // Limpo a árvore
                tree.Clear();
                // Crio a árvore com o arquivo exemplo1.tree
                tree.Create("exemplo1.tree");
                // Encerro o switch
                break;
            
            // Se a opção for 2
            case 2:
                // Limpo a árvore
                tree.Clear();
                // Crio a árvore com o arquivo exemplo2.tree
                tree.Create("exemplo2.tree");
                // Encerro o switch
                break;

            // Se a opção for 3
            case 3:
                {
                    // Limpo a árvore
                    tree.Clear();
                    // Declaração da variável arquivo do tipo string
                    string arquivo;

                    // Solicito ao usuário o nome do arquivo que deseja abrir
                    cout << "[Garanta que o arquivo esteja na raiz do projeto]" << endl;
                    cout << "Por favor, informe o nome do arquivo que deseja usar como base:" << endl;
                    cout << "- ";
                    cin >> arquivo;

                    // Crio a árvore com o arquivo informado
                    tree.Create(arquivo);
                }
                break;

            // Se a opção for 4
            case 4:
                // Exibo uma mensagem de despedida
                wcout << L"'Não existe trabalho ruim. Ruim é ter de trabalhar.'" << endl;
                wcout << L"(Um tal filósofo que deve quatorze meses de aluguel)" << endl;
                cout << endl;
                break;
            
            // Se a opção for diferente de 1, 2, 3 ou 4, imprimo uma mensagem de erro
            // e peço para tentar novamente
            default:
                wcout << L"Opção inválida. Tente novamente!" << endl;
                cout << endl;
                break;
        }

    } while (option != 4); // Emquanto for diferente de 4, o laço de repetição continua

    // Return 0 para indicar ao sistema operacional que
    // o programa terminou normalmente
    return 0;
}