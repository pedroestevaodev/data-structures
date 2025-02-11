// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Declaração da diretiva '#pragma once' para evitar
// a inclusão múltipla de um mesmo arquivo de cabeçalho
#pragma once

// Inclusão do arquivo de cabeçalho 'Carta'
#include "carta.h"

// Declaração da classe PilhaDeCartas
class PilhaDeCartas {
    public:
        // Declaração do construtor padrão
        PilhaDeCartas();
        // Declaração do destrutor
        ~PilhaDeCartas();
        // Declaração do método Full() que retorna um bool
        bool Full();
        // Declaração do método Empty() que retorna um bool
        bool Empty() const;
        // Declaração do método Push() que recebe uma carta
        void Push(const Carta& carta);
        // Declaração do método Pop() que retorna uma carta
        Carta Pop();
        // Declaração do método Top() que retorna uma carta
        Carta Top() const;
        // Declaração do método Size() que retorna um int
        int Size() const;
        // Declaração do método Clear() que limpa a pilha
        void Clear();

    private:
        // Declaração da estrutura Node que contém uma carta 
        // e um ponteiro para o próximo nó na pilha
        struct Node {
            // Declaração da variável carta do tipo Carta
            Carta carta;
            // Declaração da variável proximo do tipo Node
            Node* proximo;
            // Declaração do construtor personalizado que recebe
            // uma carta e inicializa a variável carta com o valor
            // recebido e a variável proximo com o valor nulo
            Node(const Carta& c) : carta(c), proximo(nullptr) {}
        };
        // Declaração do ponteiro 'topo' que aponta para o nó no topo da pilha
        Node* topo;
};