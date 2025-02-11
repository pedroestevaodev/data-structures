// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Declaração da diretiva '#pragma once' para evitar
// a inclusão múltipla de um mesmo arquivo de cabeçalho
#pragma once

// Inclusão do arquivo de cabeçalho 'Pilha de Cartas'
#include "pilha_de_cartas.h"

// Declaração da classe FreeCellGame
class FreeCellGame {
    public:
        // Declaração do construtor padrão
        FreeCellGame();
        // Por não haver alocação de recursos, não foi necessário implementar um destrutor

        // Declaração do método Jogar() que inicializa o jogo
        void Jogar();

    private:
        // Declaração de um array de oito posições para as pilhas de jogo
        PilhaDeCartas pilhasDeJogo[8];
        // Declaração de um array de quatro posições para as pilhas de saída
        PilhaDeCartas pilhasDeSaida[4];
        // Declaração de um array de quatro posições para as freecells
        PilhaDeCartas freeCells[4];

        // Declaração do método EmbaralharCartas()
        void EmbaralharCartas();
        // Declaração do método ImprimirCartas()
        void ImprimirCartas();
        // Declaração do método MascararNumero() que retorna o número mascarado
        const char* MascararNumero(int numero);
        // Declaração do método MoverCarta que retorna um bool
        bool MoverCarta(int origem, int destino, int opcao);
        // Declaração do método VerificarVitoria() que retorna um bool
        bool VerificarVitoria() const;
        // Declaração do método VerificarMovimentoValido() que retorna um bool
        bool VerificarMovimentoValido(PilhaDeCartas *pilhaOrigem, PilhaDeCartas *pilhaDestino) const;
        // Declaração do método VerificarMovimentoValidoSaida() que retorna um bool
        bool VerificarMovimentoValidoSaida(PilhaDeCartas *pilhaOrigem, PilhaDeCartas *pilhaDestino) const;
        // Declaração do método ZerarPilhas()
        void zerarPilhas();
};