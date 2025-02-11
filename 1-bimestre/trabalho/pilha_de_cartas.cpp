// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Inclusão do arquivo de cabeçalho 'Pilha de Cartas'
#include "pilha_de_cartas.h"
// Inclusão da biblioteca 'iostream'
#include <iostream>
using namespace std;

// Implementação do construtor padrão da classe PilhaDeCartas
// que inicializa a variável topo com o valor nulo
PilhaDeCartas::PilhaDeCartas() : topo(nullptr) {}

// Implementação do destrutor da classe PilhaDeCartas
// que chama o método Clear() para limpar a pilha
PilhaDeCartas::~PilhaDeCartas() {
    // Crio um loop que persiste enquanto a pilha não estiver vazia
    while (!Empty()) {
        // Chamo o método Pop() para remover o nó no topo da pilha
        Pop();
    }
}

// Implementação do método Full() que retorna um bool
bool PilhaDeCartas::Full() {
    // Retorno falso
    return false;
}

// Implementação do método Empty() que retorna um bool
bool PilhaDeCartas::Empty() const {
    // Retorno verdadeiro se o topo for nulo
    return topo == nullptr;
}

// Implementação do método Push() que recebe uma carta
void PilhaDeCartas::Push(const Carta& carta) {
    // Crio um novo nó e o inicializo com a carta recebida
    Node* novo = new Node(carta);

    // Verifico se a memória foi alocada corretamente
    if (novo == nullptr) {
        // Caso não tenha sido, imprimo uma mensagem de erro
        cout << ("Erro: Memoria insuficiente.") << endl;
    }

    // Faço o novo nó apontar para o nó no topo da pilha
    novo->proximo = topo;
    // Faço o topo apontar para o novo nó
    topo = novo;
}

// Implementação do método Pop() que retorna uma carta
Carta PilhaDeCartas::Pop() {
    // Verifico se existe uma carta no topo    
    if (!topo) {
        // Caso não exista, retorno uma carta inválida
        return Carta(-1, 'X');
    }

    // Crio uma variável cartaRemovida do tipo Carta
    // que recebe a carta que está no topo da pilha
    Carta cartaRemovida = topo->carta;
    // Crio uma variável temp do tipo Node e a inicializo com o topo
    Node* temp = topo;

    // Faço o topo apontar para o nó abaixo dele
    topo = topo->proximo;
    // Deleto o nó que estava no topo
    delete temp;
    // Retorno a carta que foi removida
    return cartaRemovida;
}

// Implementação do método Top() que retorna uma carta
Carta PilhaDeCartas::Top() const {
    // Verifico se existe uma carta no topo    
    if (!topo) {
        // Caso não exista, retorno uma carta inválida
        return Carta(-1, 'X');
    }

    // Retorno a carta que está no topo da pilha
    return topo->carta;
}

// Implementação do método Size() que retorna um int
int PilhaDeCartas::Size() const {
    // Crio uma variável tamanho do tipo int e a inicializo com 0
    int tamanho = 0;
    // Crio uma variável temp do tipo Node e a inicializo com o topo
    Node* temp = topo;

    // Crio um loop que persiste enquanto temp não for nulo
    while (temp != nullptr) {
        // Incremento a variável tamanho
        tamanho++;
        // Faço temp apontar para o nó abaixo dele
        temp = temp->proximo;
    }

    // Retorno o tamanho da pilha
    return tamanho;
}

// Implementação do método Clear() que limpa a pilha
void PilhaDeCartas::Clear() {
    // Crio um loop que persiste enquanto a pilha não estiver vazia
    while (!Empty()) {
        // Chamo o método Pop() para remover o nó no topo da pilha
        Pop();
    }
}