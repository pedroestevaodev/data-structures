// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Declaração da diretiva '#pragma once' para evitar 
// a inclusão múltipla de um mesmo arquivo de cabeçalho
#pragma once

// Declaração da classe Carta
class Carta {
    public:
        // Declaração do construtor padrão
        Carta();
        // Declaração do construtor personalizado que recebe
        // um numero do tipo int e um naipe do tipo char
        Carta(int numero, char naipe);
        // Por não haver alocação de recursos, não foi necessário implementar um destrutor

        // Declaração dos métodos pegaNumero() e pegaNaipe()
        // que retornam o número e o naipe da carta, respectivamente
        int pegaNumero() const;
        char pegaNaipe() const;

    private:
        // Declaração da variável número do tipo int
        int numero;
        // Declaração da variável naipe do tipo char
        char naipe;
};