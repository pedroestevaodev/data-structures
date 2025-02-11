// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Inclusão do arquivo de cabeçalho 'Freecell Game'
#include "freecell_game.h"
// Inclusão da biblioteca 'iostream'
#include <iostream>
// Inclusão da biblioteca 'iomanip'
#include <iomanip>
// Inclusão da biblioteca 'cstdlib'
#include <cstdlib>
// Inclusão da biblioteca 'ctime'
#include <ctime>
using namespace std;

// Implementação do construtor padrão da classe FreeCellGame
FreeCellGame::FreeCellGame() {
    // Inicializo a semente do gerador de números 
    // aleatórios com o valor atual do tempo
    srand(time(nullptr));
}

// Implementação do método EmbaralharCartas()
void FreeCellGame::EmbaralharCartas() {
    // Declaração do array de 52 posições do tipo Carta que simula o baralho de cartas
    Carta baralho[52];
    // Declaração do array de 4 posições do tipo char que recebe os naipes
    char naipes[4] = {'E', 'C', 'O', 'P'};
    // Declaração do array de 13 posições do tipo int que recebe os números
    int numeros[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    // Declaração do contador index do tipo int que inicia em 0
    int index = 0;

    // Preencher o baralho com as cartas //
    // Percorro todos os naipes em um loop
    for (char naipe : naipes) {
        // Percorro todos os números em um loop
        for (int numero : numeros) {
            // Atribuo a carta ao baralho, com o numero e naipe atual
            baralho[index] = Carta(numero, naipe);
            // Incremento o contador index
            index++;
        }
    }

    // Embaralhar as cartas //
    // Percorro um loop para as 52 cartas
    for (int i = 0; i < 52; i++) {
        // Gero um número aleatório entre 0 e 51
        int randomIndex = rand() % 52;
        // Crio uma carta temporária que recebe a carta na posição i do baralho
        Carta temp = baralho[i];
        // Atribuo a carta na posição i do baralho a carta na posição randomIndex
        baralho[i] = baralho[randomIndex];
        // Atribuo a carta na posição randomIndex do baralho a carta temporária
        baralho[randomIndex] = temp;
    }

    // Distribuir as cartas nas pilhas de jogo //
    // Declaração do contador pilhaIndex do tipo int que inicia em 0
    int pilhaIndex = 0;
    // Declaração do contador pilhaBaralhoIndex do tipo int que inicia em 0
    int pilhaBaralhoIndex = 0;

    // Percorro um loop para as oito pilhas de jogo
    for (int i = 0; i < 8; i++) {
        // Percorro um loop para as sete primeiras pilhas de jogo 
        // e seis para as últimas
        for (int j = 0; j < (i < 4 ? 7 : 6); j++) {
            // Atribuo a carta na posição pilhaBaralhoIndex do baralho
            // para a pilha de jogo na posição pilhaIndex
            pilhasDeJogo[pilhaIndex].Push(baralho[pilhaBaralhoIndex]);
            // Incremento o contador pilhaBaralhoIndex
            pilhaBaralhoIndex++;
        }
        // Incremento o contador pilhaIndex
        pilhaIndex++; 
    }  
}

// Implementação do método Jogar()
void FreeCellGame::Jogar() {
    // Declaração da variável opcaoJogar do tipo int
    int opcaoJogar;

    // Laço de repetição para exibir o menu inicial
    do {
        cout << "==========================================" << endl;
        cout << "===            JOGO FREECELL           ===" << endl;
        cout << "==========================================" << endl;
        cout << "1 - Iniciar jogo" << endl;
        cout << "2 - Nao tenho paciencia, fui" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        // Solicito que o usuário digite uma opção
        cout << "Digite uma opcao: " << endl;
        cout << "- ";
        cin >> opcaoJogar;
        cout << endl;

        // Enquanto a resposta for diferente de int 
        // apresento uma mensagem de erro e peço para
        // tentar novamente
        while (cin.fail()) {
            cin.clear();

            cout << "Opcao invalida. Tente novamente!" << endl;
            cout << "- ";
            cin >> opcaoJogar;
            cout << endl;
        }

        // Verifico qual opção foi escolhida
        switch (opcaoJogar)
        {
            // Se a opção for 1, inicializo o jogo
            case 1:
                // Declaração da variável opcaoMover do tipo int
                int opcaoMover;
                // Declaração das variáveis origem e destino do tipo int
                int origem, destino;
                
                // Chamo o método para embaralhar as cartas
                EmbaralharCartas();
                
                // Laço de repetição para exibir o menu de jogo
                do {    
                    cout << "==========================================" << endl;
                    cout << "===            JOGO FREECELL           ===" << endl;
                    cout << "==========================================" << endl;
                    cout << endl;

                    // Chamo o método para exibir as cartas
                    ImprimirCartas();
                    
                    cout << "==========================================" << endl;
                    cout << "===           MOVER UMA CARTA          ===" << endl;
                    cout << "==========================================" << endl;
                    cout << "1 - De uma pilha de jogo para outra" << endl;
                    cout << "2 - De uma pilha de jogo para uma freecell" << endl;
                    cout << "3 - De uma pilha de jogo para uma pilha de saida" << endl;
                    cout << "4 - De uma freecell para uma pilha de jogo" << endl;
                    cout << "5 - De uma freecell para uma pilha de saida" << endl;
                    cout << "6 - Retornar ao menu" << endl;
                    cout << "==========================================" << endl;
                    cout << endl;

                    // Solicito que o usuário digite uma opção
                    cout << "Digite uma opcao: " << endl;
                    cout << "- ";
                    cin >> opcaoMover;
                    cout << endl;

                    // Enquanto a resposta for diferente de int 
                    // apresento uma mensagem de erro e peço para
                    // tentar novamente
                    while (cin.fail()) {
                        cin.clear();

                        cout << "Opcao invalida. Tente novamente!" << endl;
                        cout << "- ";
                        cin >> opcaoMover;
                        cout << endl;
                    }

                    // Verifico qual opção foi escolhida
                    switch (opcaoMover) {
                        // Se a opção for 1, informo que o movimento será
                        // de uma pilha de jogo para outra
                        case 1:
                            // Solicito os números de origem e destino das pilhas de jogo
                            cout << "[PILHA DE JOGO - PILHA DE JOGO]" << endl;
                            cout << "Informe a pilha de origem e a pilha de destino [Ex: 1 8]: ";
                            cin >> origem >> destino;
                            cout << endl;

                            // Enquanto a resposta for diferente de int 
                            // apresento uma mensagem de erro e peço para
                            // tentar novamente
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore();

                                cout << "Opcao invalida. Tente novamente!" << endl;
                                cout << "Informe a pilha de origem e a pilha de destino [Ex: 1 8]: ";
                                cout << "- ";
                                cin >> origem >> destino;
                                cout << endl;
                            }

                            // Verifico se é possível mover a carta
                            if (MoverCarta(origem, destino, opcaoMover)) {
                                // Se sim, informo que o movimento foi realizado
                                cout << "[MOVIMENTO REALIZADO]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            } else {
                                // Se não, informo que o movimento foi inválido
                                cout << "[MOVIMENTO INVALIDO - TENTE NOVAMENTE]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            }

                            break;

                        // Se a opção for 2, informo que o movimento será
                        // de uma pilha de jogo para uma freecell
                        case 2:
                            // Solicito os números de origem e destino das pilhas de jogo e freecell
                            cout << "[PILHA DE JOGO - FREECELL]" << endl;
                            cout << "Informe a pilha de origem e a freecell de destino [Ex: 1 4]: ";
                            cin >> origem >> destino;
                            cout << endl;
                            
                            // Enquanto a resposta for diferente de int 
                            // apresento uma mensagem de erro e peço para
                            // tentar novamente
                            while (cin.fail()) {
                                cin.clear();

                                cout << "Opcao invalida. Tente novamente!" << endl;
                                cout << "Informe a pilha de origem e a freecell de destino [Ex: 1 4]: ";
                                cout << "- ";
                                cin >> origem >> destino;
                                cout << endl;
                            }
                            
                            // Verifico se é possível mover a carta
                            if (MoverCarta(origem, destino, opcaoMover)) {
                                // Se sim, informo que o movimento foi realizado
                                cout << "[MOVIMENTO REALIZADO]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            } else {
                                // Se não, informo que o movimento foi inválido
                                cout << "[MOVIMENTO INVALIDO - TENTE NOVAMENTE]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            }

                            break;

                        // Se a opção for 3, informo que o movimento será
                        // de uma pilha de jogo para uma pilha de saída
                        case 3:
                            // Solicito os números de origem e destino das pilhas de jogo e saída
                            cout << "[PILHA DE JOGO - PILHA DE SAIDA]" << endl;
                            cout << "Informe a pilha de origem e a pilha de destino [Ex: 1 4]: ";
                            cin >> origem >> destino;
                            cout << endl;

                            // Enquanto a resposta for diferente de int 
                            // apresento uma mensagem de erro e peço para
                            // tentar novamente
                            while (cin.fail()) {
                                cin.clear();

                                cout << "Opcao invalida. Tente novamente!" << endl;
                                cout << "Informe a pilha de origem e a pilha de destino [Ex: 1 4]: ";
                                cout << "- ";
                                cin >> origem >> destino;
                                cout << endl;
                            }

                            // Verifico se é possível mover a carta
                            if (MoverCarta(origem, destino, opcaoMover)) {
                                // Se sim, informo que o movimento foi realizado
                                cout << "[MOVIMENTO REALIZADO]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            } else {
                                // Se não, informo que o movimento foi inválido
                                cout << "[MOVIMENTO INVALIDO - TENTE NOVAMENTE]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            }

                            break;

                        // Se a opção for 4, informo que o movimento será
                        // de uma freecell para uma pilha de jogo
                        case 4:
                            // Solicito os números de origem e destino da freecell e da pilha de jogo
                            cout << "[FREECELL - PILHA DE JOGO]" << endl;
                            cout << "Informe a freecell de origem e a pilha de destino [Ex: 4 1]: ";
                            cin >> origem >> destino;
                            cout << endl;

                            // Enquanto a resposta for diferente de int 
                            // apresento uma mensagem de erro e peço para
                            // tentar novamente
                            while (cin.fail()) {
                                cin.clear();

                                cout << "Opcao invalida. Tente novamente!" << endl;
                                cout << "Informe a freecell de origem e a pilha de destino [Ex: 4 1]: ";
                                cout << "- ";
                                cin >> origem >> destino;
                                cout << endl;
                            }

                            // Verifico se é possível mover a carta
                            if (MoverCarta(origem, destino, opcaoMover)) {
                                // Se sim, informo que o movimento foi realizado
                                cout << "[MOVIMENTO REALIZADO]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            } else {
                                // Se não, informo que o movimento foi inválido
                                cout << "[MOVIMENTO INVALIDO - TENTE NOVAMENTE]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            }

                            break;

                        // Se a opção for 5, informo que o movimento será
                        // de uma freecell para uma pilha de saída
                        case 5:
                            // Solicito os números de origem e destino da freecell e da pilha de saída
                            cout << "[FREECELL - PILHA DE SAIDA]" << endl;
                            cout << "Informe a freecell de origem e a pilha de destino [Ex: 4 1]: ";
                            cin >> origem >> destino;
                            cout << endl;

                            // Enquanto a resposta for diferente de int 
                            // apresento uma mensagem de erro e peço para
                            // tentar novamente
                            while (cin.fail()) {
                                cin.clear();

                                cout << "Opcao invalida. Tente novamente!" << endl;
                                cout << "Informe a freecell de origem e a pilha de destino [Ex: 4 1]: ";
                                cout << "- ";
                                cin >> origem >> destino;
                                cout << endl;
                            }

                            // Verifico se é possível mover a carta
                            if (MoverCarta(origem, destino, opcaoMover)) {
                                // Se sim, informo que o movimento foi realizado
                                cout << "[MOVIMENTO REALIZADO]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            } else {
                                // Se não, informo que o movimento foi inválido
                                cout << "[MOVIMENTO INVALIDO - TENTE NOVAMENTE]" << endl;
                                cout << "- Pilha de Origem: " << origem << endl;
                                cout << "- Pilha de Saida: " << destino << endl;
                                cout << endl;
                            }

                            break;

                        // Se a opção for 6, zero as pilhas e saio para o menu inicial
                        case 6:
                            // Chamo o método para zerar as pilhas
                            zerarPilhas();

                            break;

                        // Se a opção for diferente de 1, 2, 3, 4, 5 ou 6, imprimo uma mensagem de erro
                        // e peço para tentar novamente
                        default:
                            cout << "Opcao invalida. Tente novamente!" << endl;
                            cout << endl;
                            break;
                    }
                } while (!VerificarVitoria() && opcaoMover != 6); // Enquanto for diferente de 6 e não houver vitória, o laço de repetição continua
            
                // Verifico se houve vitória
                if (VerificarVitoria()) {
                    // Caso sim, apresento uma mensagem de parabenização
                    cout << "==========================================" << endl;
                    cout << "===    PARABENS! VOCE VENCEU O JOGO    ===" << endl;
                    cout << "==========================================" << endl;
                    cout << endl;

                    // Chamo o método para zerar as pilhas
                    zerarPilhas();
                }

                break;

            // Se a opção for 2, apresento uma mensagem e fecho o jogo
            case 2:
                cout << "==========================================" << endl;
                cout << endl;
                cout << "Que pena. Quem sabe na proxima..." << endl;
                cout << endl;
                break;

            // Se a opção for diferente de 1 ou 2, imprimo uma mensagem de erro
            // e peço para tentar novamente
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                cout << endl;
                break;
        }
    } while (opcaoJogar != 2); // Enquanto for diferente de 2, o laço de repetição continua
}

// Implementação do método MascararNumero() que retorna o número mascarado
const char* FreeCellGame::MascararNumero(int numero) {
    // Declaração da variável mascaraNumero do tipo const char*
    const char* mascaraNumero;

    // Verifico qual número foi recebido
    switch (numero) {
        // Caso seja 1, 11, 12 ou 13, atribuo o valor correspondente
        case 1:
            mascaraNumero = "A";
            break;
        case 11:
            mascaraNumero = "J";
            break;
        case 12:
            mascaraNumero = "Q";
            break;
        case 13:
            mascaraNumero = "K";
            break;
        
        // Caso seja diferente de 1, 11, 12 ou 13, atribuo o valor recebido
        default:
            string strValue = to_string(numero);
            mascaraNumero = strValue.c_str();
            break;
    }

    // Retorno o número mascarado
    return mascaraNumero;
}

// Implementação do método ImprimirCartas()
void FreeCellGame::ImprimirCartas() {
    // Início da exibição da seção de freecells
    cout << "[FREECELLS]" << endl;
    // Percorro um loop para as quatro freecells, exibindo o número de cada uma
    for (int i = 0; i < 4; i++) {
        cout << left << "[ " << setw(2) << setfill(' ') << internal << "0" << i+1 << setw(2) << " ] ";
    }
    cout << endl;

    // Percorro um loop para as quatro freecells, exibindo uma quebra 
    // entre o número da pilha e a carta exibida
    for (int i = 0; i < 4; i++) {
        cout << left << "  " << setw(2) << setfill(' ') << internal << "-" << setw(4) << "   ";
    }
    cout << endl;

    // Percorro um loop para as quatro freecells, exibindo as cartas
    for (int i = 0; i < 4; i++) {
        // Atribuo à variável freeCell a pilha de freecell na posição i
        PilhaDeCartas& freeCell = freeCells[i];

        // Verifico se a pilha freecell não está vazia
        if (!freeCell.Empty()) {
            // Caso não esteja, atribuo à variável carta a carta que está no topo da pilha
            Carta carta = freeCell.Top();
            // Exibo a carta
            cout << left << "[ " << setw(2) << setfill(' ') << internal << MascararNumero(carta.pegaNumero()) << carta.pegaNaipe() << setw(2) << " ] ";
        } else {
            // Caso esteja, exibo o campo vazio
            cout << left << "[" << setw(2) << setfill(' ') << internal << "  -  " << setw(2) << "] ";
        }
    }
    cout << endl;
    cout << endl;

    // Início da exibição da seção de pilhas de saída
    cout << "[PILHAS DE SAIDA]" << endl;
    // Percorro um loop para as quatro pilhas de saída, exibindo o número de cada uma
    for (int i = 0; i < 4; i++) {
        cout << left << "[ " << setw(2) << setfill(' ') << internal << "0" << i+1 << setw(2) << " ] ";
    }
    cout << endl;

    // Percorro um loop para as quatro pilhas de saída, exibindo uma quebra 
    // entre o número da pilha e a carta exibida
    for (int i = 0; i < 4; i++) {
        cout << left << "  " << setw(2) << setfill(' ') << internal << "-" << setw(4) << "   ";
    }
    cout << endl;

    // Percorro um loop para as quatro pilhas de saída, exibindo as cartas
    for (int i = 0; i < 4; i++) {
        // Atribuo à variável pilha a pilha de saída na posição i
        PilhaDeCartas& pilha = pilhasDeSaida[i];

        // Verifico se a pilha de saída não está vazia
        if (!pilha.Empty()) {
            // Caso não esteja, atribuo à variável carta a carta que está no topo da pilha
            Carta carta = pilha.Top();
            // Exibo a carta
            cout << left << "[ " << setw(2) << setfill(' ') << internal << MascararNumero(carta.pegaNumero()) << carta.pegaNaipe() << setw(2) << " ] ";
        } else {
            // Caso esteja, exibo o campo vazio
            cout << left << "[" << setw(2) << setfill(' ') << internal << "  -  " << setw(2) << "] ";
        }
    }
    cout << endl;
    cout << endl;

    // Início da exibição da seção de pilhas de jogo
    // Declaração da variável maximoCartasPilhas do tipo int que inicia com 0
    int maximoCartasPilhas = 0;

    // Percorro um loop por todas as pilhas de jogo
    for (PilhaDeCartas& pilha : pilhasDeJogo) {
        // Verifico se o tamanho da pilha atual é maior que o valor da variável maximoCartasPilhas
        if (pilha.Size() > maximoCartasPilhas) {
            // Caso seja, atribuo o tamanho da pilha atual à variável maximoCartasPilhas
            maximoCartasPilhas = pilha.Size();
        }
    }

    // Declaração da matriz bidirecional pilhasJogoTemp que recebe as oito pilhas de jogo
    // com o número de cartas definido pela variável maximoCartasPilhas
    Carta pilhasJogoTemp[8][maximoCartasPilhas];

    // Percorro um loop pelas oito pilhas de jogo
    for (int i = 0; i < 8; i++) {
        // Atribuo à variável pilha a pilha de jogo na posição i
        PilhaDeCartas& pilha = pilhasDeJogo[i];
        // Declaração do array pilhaTemp do tipo Carta que recebe o tamanho da pilha atual
        Carta pilhaTemp[pilha.Size()];
        // Declaração da variável pilhaTempIndex do tipo int que inicia com 0
        int pilhaTempIndex = 0;

        // Um loop que persiste enquanto a pilha não estiver vazia
        while (!pilha.Empty()) {
            // Atribuo à variável carta a carta que foi removida
            Carta carta = pilha.Pop();
            // Atribuo a carta à pilha temporária na posição pilhaTempIndex
            pilhaTemp[pilhaTempIndex] = carta;
            // Incremento o contador pilhaTempIndex
            pilhaTempIndex++;
        }
        
        // Declaração da variável modelIndex do tipo int que inicia com 0
        int modelIndex = 0;

        // Percorro um loop para devolver as cartas removidas para a pilha
        // na mesma ordem em que foram retiradas
        for (int j = pilhaTempIndex; j > 0; j--) {
            // Atribuo à pilha de jogo temporária na posição i e na posição modelIndex
            // a carta que está na pilha temporária na posição j-1
            pilhasJogoTemp[i][modelIndex] = pilhaTemp[j-1];
            // Devolvo a carta para a pilha de jogo
            pilha.Push(pilhaTemp[j-1]);
            // Incremento o contador modelIndex
            modelIndex++;
        }
    }

    cout << "[PILHAS DE JOGO]" << endl;
    // Percorro um loop para as oito pilhas de jogo, exibindo o número de cada uma
    for (int i = 0; i < 8; i++) {
        cout << left << "[ " << setw(2) << setfill(' ') << internal << "0" << i+1 << setw(2) << " ] ";
    }
    cout << endl;

    // Percorro um loop para as oito pilhas de jogo, exibindo uma quebra 
    // entre o número da pilha e a carta exibida
    for (int i = 0; i < 8; i++) {
        cout << left << "  " << setw(2) << setfill(' ') << internal << "-" << setw(4) << "   ";
    }
    cout << endl;

    // Percorro um loop no vetor bidirecional pilhasJogoTemp 
    // para exibir as cartas das pilhas de jogos
    // Começo percorrendo o número armazenado na variável maximoCartasPilhas
    for (int i = 0; i < maximoCartasPilhas; i++) {
        // Percorro um loop para as oito pilhas de jogo
        for (int j = 0; j < 8; j++) {
            // Atribuo à variável naipe o naipe da carta na posição j e i
            char naipe = pilhasJogoTemp[j][i].pegaNaipe();
            // Atribuo à variável numero o número da carta na posição j e i
            int numero = pilhasJogoTemp[j][i].pegaNumero();

            // Verifico se a carta na posição é nula/inválida
            if (numero == -1 && naipe == 'X') {
                // Caso seja, exibo o campo vazio
                cout << setw(8) << " ";
            } else {
                // Caso não seja, exibo a carta
                cout << left << "[ " << setw(2) << setfill(' ') << internal << MascararNumero(numero) << naipe << setw(2) << " ] ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Implementação do método MoverCarta() que retorna um bool
bool FreeCellGame::MoverCarta(int origem, int destino, int opcao) {
    // Declaração da variável de ponteiro pilhaOrigem 
    // para PilhaDeCartas que inicia não apontando para nada 
    PilhaDeCartas* pilhaOrigem = nullptr;
    // Declaração da variável de ponteiro pilhaDestino 
    // para PilhaDeCartas que inicia não apontando para nada 
    PilhaDeCartas* pilhaDestino = nullptr;
    // Declaração da variável cartaMovida do tipo Carta
    Carta cartaMovida;
    
    // Decremento os valores de origem e destino para que fiquem dentro dos limites válidos
    origem--;
    destino--;
    
    // Verifico qual opção foi recebida
    switch (opcao) {
        // Se a opção for 1:
        case 1:
            /* De uma pilha de jogo para outra pilha de jogo */

            // Verifico se as pilhas estão dentro dos limites válidos 
            if (origem < 0 || origem >= 8 || destino < 0 || destino >= 8) {
                // Se não estiverem, retorno false
                return false; 
            }
            
            // Atribuo à variável pilhaOrigem a pilha de jogo na posição origem
            pilhaOrigem = &pilhasDeJogo[origem];
            // Atribuo à variável pilhaDestino a pilha de jogo na posição destino
            pilhaDestino = &pilhasDeJogo[destino];

            // Verifico se a pilha de origem está vazia ou se o movimento é inválido
            if (pilhaOrigem->Empty() || !VerificarMovimentoValido(pilhaOrigem, pilhaDestino)) {
                // Se estiver, retorno false
                return false;
            }

            // Atribuo à variável cartaMovida a carta removida da pilha de origem
            cartaMovida = pilhaOrigem->Pop();
            // Insiro na pilha de destino a carta movida
            pilhaDestino->Push(cartaMovida);

            // Se o movimento foi bem-sucedido retorno true
            return true;

        // Se a opção for 2:
        case 2:
            /* De uma pilha de jogo para uma freecell */

            // Verifico se as pilhas estão dentro dos limites válidos
            if (origem < 0 || origem >= 8 || destino < 0 || destino >= 4) {
                // Se não estiverem, retorno false
                return false; 
            }
            
            // Atribuo à variável pilhaOrigem a pilha de jogo na posição origem
            pilhaOrigem = &pilhasDeJogo[origem];
            // Atribuo à variável pilhaDestino a pilha de freecell na posição destino
            pilhaDestino = &freeCells[destino];

            // Verifico se a pilha de origem está vazia ou se a pilha de destino não está vazia
            if (pilhaOrigem->Empty() || !pilhaDestino->Empty()) {
                // Se estiver, retorno false
                return false;
            }

            // Atribuo à variável cartaMovida a carta removida da pilha de origem
            cartaMovida = pilhaOrigem->Pop();
            // Insiro na pilha de destino a carta movida
            pilhaDestino->Push(cartaMovida);

            // Se o movimento foi bem-sucedido retorno true
            return true;

        // Se a opção for 3:
        case 3:
            /* De uma pilha de jogo para uma pilha de saída */

            // Verifico se as pilhas estão dentro dos limites válidos
            if (origem < 0 || origem >= 8 || destino < 0 || destino >= 4) {
                // Se não estiverem, retorno false
                return false; 
            }
            
            // Atribuo à variável pilhaOrigem a pilha de jogo na posição origem
            pilhaOrigem = &pilhasDeJogo[origem];
            // Atribuo à variável pilhaDestino a pilha de saída na posição destino
            pilhaDestino = &pilhasDeSaida[destino];

            // Verifico se a pilha de origem está vazia ou se o movimento é inválido
            if (pilhaOrigem->Empty() || !VerificarMovimentoValidoSaida(pilhaOrigem, pilhaDestino)) {
                // Se estiver, retorno false
                return false;
            }

            // Atribuo à variável cartaMovida a carta removida da pilha de origem
            cartaMovida = pilhaOrigem->Pop();
            // Insiro na pilha de destino a carta movida
            pilhaDestino->Push(cartaMovida);

            // Se o movimento foi bem-sucedido retorno true
            return true;

        // Se a opção for 4:
        case 4:
            /* De uma freecell para uma pilha de jogo */

            // Verifico se as pilhas estão dentro dos limites válidos
            if (origem < 0 || origem >= 4 || destino < 0 || destino >= 8) {
                // Se não estiverem, retorno false
                return false; 
            }
            
            // Atribuo à variável pilhaOrigem a pilha de freecell na posição origem
            pilhaOrigem = &freeCells[origem];
            // Atribuo à variável pilhaDestino a pilha de jogo na posição destino
            pilhaDestino = &pilhasDeJogo[destino];

            // Verifico se a pilha de origem está vazia ou se o movimento é inválido
            if (pilhaOrigem->Empty() || !VerificarMovimentoValido(pilhaOrigem, pilhaDestino)) {
                // Se estiver, retorno false
                return false;
            }

            // Atribuo à variável cartaMovida a carta removida da pilha de origem
            cartaMovida = pilhaOrigem->Pop();
            // Insiro na pilha de destino a carta movida
            pilhaDestino->Push(cartaMovida);

            // Se o movimento foi bem-sucedido retorno true
            return true;

        // Se a opção for 5:
        case 5:
            /* De uma freecell para uma pilha de saída */

            // Verifico se as pilhas estão dentro dos limites válidos
            if (origem < 0 || origem >= 4 || destino < 0 || destino >= 4) {
                // Se não estiverem, retorno false
                return false; 
            }
            
            // Atribuo à variável pilhaOrigem a pilha de freecell na posição origem
            pilhaOrigem = &freeCells[origem];
            // Atribuo à variável pilhaDestino a pilha de saída na posição destino
            pilhaDestino = &pilhasDeSaida[destino];

            // Verifico se a pilha de origem está vazia ou se o movimento é inválido
            if (pilhaOrigem->Empty() || !VerificarMovimentoValidoSaida(pilhaOrigem, pilhaDestino)) {
                // Se estiver, retorno false
                return false;
            }

            // Atribuo à variável cartaMovida a carta removida da pilha de origem
            cartaMovida = pilhaOrigem->Pop();
            // Insiro na pilha de destino a carta movida
            pilhaDestino->Push(cartaMovida);

            // Se o movimento foi bem-sucedido retorno true
            return true;
        
        // Se a opção for diferente de 1, 2, 3, 4 ou 5, retorno false
        default:
            return false;
    };
}

// Implementação do método VerificarVitoria() que retorna um bool
bool FreeCellGame::VerificarVitoria() const {
    // Declaração da variável pilhasCompletadas do tipo int que inicia com 0
    int pilhasCompletadas = 0;

    // Percorro um loop pelas pilhas de saída
    for (const PilhaDeCartas& pilha : pilhasDeSaida) {
        // Verifico se a pilha está completa
        if (pilha.Size() == 13) {
            // Se estiver, incremento o contador pilhasCompletadas
            pilhasCompletadas++;
        }
    }

    // Verifico se o contador pilhasCompletadas é iqual à quatro
    if (pilhasCompletadas == 4) {
        // Se for, retorno true
        return true;
    }

    // Se o contador for diferente de quatro retorno false
    return false;
}

// Implementação do método VerificarMovimentoValido() que retorna um bool
bool FreeCellGame::VerificarMovimentoValido(PilhaDeCartas *pilhaOrigem, PilhaDeCartas *pilhaDestino) const {
    // Verifico se a pilha de destino está vazia
    if (pilhaDestino->Empty()) {
        // Se estiver, retorno true
        return true;
    }
    
    // Atribuo à variável cartaOrigem a carta que está no topo da pilha de origem
    const Carta& cartaOrigem = pilhaOrigem->Top();
    // Atribuo à variável cartaDestino a carta que está no topo da pilha de destino
    const Carta& cartaDestino = pilhaDestino->Top();

    // Verifico as regras de movimento: alternância de cores e ordem decrescente
    bool valido = ((cartaOrigem.pegaNumero() == cartaDestino.pegaNumero() - 1) &&
                    ((cartaOrigem.pegaNaipe() == 'E' || cartaOrigem.pegaNaipe() == 'P') &&
                    (cartaDestino.pegaNaipe() == 'O' || cartaDestino.pegaNaipe() == 'C'))) ||
                    ((cartaOrigem.pegaNumero() == cartaDestino.pegaNumero() - 1) &&
                    ((cartaOrigem.pegaNaipe() == 'O' || cartaOrigem.pegaNaipe() == 'C') &&
                    (cartaDestino.pegaNaipe() == 'E' || cartaDestino.pegaNaipe() == 'P')));
    
    // Retorno a variável valido
    return valido;
}

// Implementação do método VerificarMovimentoValidoSaida() que retorna um bool
bool FreeCellGame::VerificarMovimentoValidoSaida(PilhaDeCartas *pilhaOrigem, PilhaDeCartas *pilhaDestino) const {
    // Atribuo à variável cartaOrigem a carta que está no topo da pilha de origem
    const Carta& cartaOrigem = pilhaOrigem->Top();

    // Verifico se o número da carta da pilha de origem é um A/ás
    // e se a pilha de destino está vazia
    if ((cartaOrigem.pegaNumero() == 1) && pilhaDestino->Empty()) {
        // Se for, retorno true
        return true;
    }

    // Verifico se o número da carta da pilha de origem é maior que 1(A - ás)
    // e se a pilha de destino está vazia
    if ((cartaOrigem.pegaNumero() > 1) && pilhaDestino->Empty()) {
        // Se for, retorno false
        return false;
    }

    // Atribuo à variável cartaDestino a carta que está no topo da pilha de destino
    const Carta& cartaDestino = pilhaDestino->Top();

    // Verifico as regras de movimento: alternância de cores e ordem crescente
    bool valido = ((cartaOrigem.pegaNumero() == cartaDestino.pegaNumero() + 1) &&
                    ((cartaOrigem.pegaNaipe() == 'E' && cartaDestino.pegaNaipe() == 'E') ||
                    (cartaOrigem.pegaNaipe() == 'P' && cartaDestino.pegaNaipe() == 'P') ||
                    (cartaOrigem.pegaNaipe() == 'O' && cartaDestino.pegaNaipe() == 'O') ||
                    (cartaOrigem.pegaNaipe() == 'C' && cartaDestino.pegaNaipe() == 'C')));
    
    // Retorno a variável valido
    return valido;
}

// Implementação do método zerarPilhas()
void FreeCellGame::zerarPilhas() {
    // Percorro as pilhas de jogo
    for (PilhaDeCartas& pilhaJogo : pilhasDeJogo) {
        // Enquanto a pilha não estiver vazia, removo as cartas
        pilhaJogo.Clear();
    }

    // Percorro as pilhas de saída
    for (PilhaDeCartas& pilhaSaida : pilhasDeSaida) {
        // Enquanto a pilha não estiver vazia, removo as cartas
        pilhaSaida.Clear();
    }

    // Percorro as freecells
    for (PilhaDeCartas& pilhaFreecell : freeCells) {
        // Enquanto a pilha não estiver vazia, removo as cartas
        pilhaFreecell.Clear();
    }
}