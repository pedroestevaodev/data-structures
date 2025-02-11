// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Inclusão do arquivo de cabeçalho 'Carta'
#include "carta.h"

// Implementação do construtor padrão da classe Carta
// que inicializa as variáveis número e naipe com
// valores definidos para não começarem nulos ou vazios
Carta::Carta() : numero(-1), naipe('X') {}

// Implementação do construtor personalizado da classe Carta
// que inicializa as variáveis número e naipe com os valores
// recebidos como parâmetro 
Carta::Carta(int numero, char naipe) : numero(numero), naipe(naipe) {}

// Implementação do método pegaNumero() que retorna o número da carta
int Carta::pegaNumero() const {
    return numero;
}

// Implementação do método pegaNaipe() que retorna o naipe da carta
char Carta::pegaNaipe() const {
    return naipe;
}