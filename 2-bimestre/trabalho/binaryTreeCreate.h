// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Declaração da diretiva '#pragma once' para evitar
// a inclusão múltipla de um mesmo arquivo de cabeçalho
#pragma once
// Inclusão das bibliotecas necessárias
#include <string>
#include <fstream>
using namespace std;

// Declaração da classe BinaryTreeCreate
class BinaryTreeCreate
{
    public:
        // Declaração do construtor padrão
        BinaryTreeCreate();
        // Declaração do destrutor padrão
        ~BinaryTreeCreate();
        // Declaração do método Clear() que limpa a árvore
        void Clear();
        // Declaração do método Create() que percorre o arquivo
        void Create(const string& filename);
        // Declaração do método Insert() que chama o método de busca e inserção
        void Insert(const string& parent, const string& childL, const string& childR);
        // Declaração do método Print() que chama o método de impressão da árvore
        void Print();
        // Declaração dos métodos Nodes() e Leaves() que chamam os métodos de contagem
        int Nodes();
        int Leaves();

    private:
        // Declaração da estrutura TreeNode que representa os nós da árvore
        struct TreeNode {
            // Declaração da variável Entry para armazenar o conteúdo do nó
            string Entry;
            // Declaração dos ponteiros LeftNode e RightNode para os nós filhos
            TreeNode *LeftNode, *RightNode;
        };
        // Declaração do ponteiro TreePointer para os nós da árvore
        typedef TreeNode *TreePointer;

        // Declaração da raiz da árvore do tipo TreePointer
        TreePointer root;

        // Declaração do método SearchInsert() que busca e insere os nós
        void SearchInsert(TreePointer &t, const string& parent, const string& childL, const string& childR);
        // Declaração do método PrintTree() que imprime a árvore
        void PrintTree(TreePointer node);
        // Declaração dos métodos NodesNumber() e LeavesNumber() que contam os nós e folhas
        int NodesNumber(TreePointer &t);
        int LeavesNumber(TreePointer &t);
};