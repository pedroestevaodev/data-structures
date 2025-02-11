// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 4/B

// Inclusão do arquivo de cabeçalho 'Binary Tree Create'
#include "binaryTreeCreate.h"
// Inclusão das bibliotecas necessárias
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
using namespace std;

// Definição do construtor padrão da classe BinaryTreeCreate
BinaryTreeCreate::BinaryTreeCreate() {
    // Inicialização da raiz com o valor nulo
    root = nullptr;
}

// Definição do destrutor padrão da classe BinaryTreeCreate
BinaryTreeCreate::~BinaryTreeCreate() {
    // Chamada do método Clear() para limpar a árvore
    Clear();
}

// Definição do método Clear() que limpa a árvore
void BinaryTreeCreate::Clear() {
    // Verifico se a raiz não é nula
    if (root != nullptr) {
        // Caso não seja, deleto a raiz e deixo nula
        delete root;
        root = nullptr;
    }
}

// Definição do método Create() que recebe o nome do arquivo
void BinaryTreeCreate::Create(const string& filename) {
    // Configuração para permitir a formatação UTF-8 na exibição das mensagens 
    setlocale( LC_ALL, "" );
    
    // Declaração da variável file do tipo ifstream para abrir o arquivo
    ifstream file(filename);

    // Verifico se o arquivo foi aberto com sucesso
    if(file.is_open()) {
        // Caso tenha sido, declaro as variáveis parent, childL e childR
        string parent, childL, childR;

        // Crio um loop que percorre todas as linhas do arquivo
        // atribuindo a primeira coluna à variável parent,
        // a segunda coluna à variável childL e
        // a terceira coluna à variável childR
        while (file >> parent >> childL >> childR) {
            // Chamo o método Insert() para iniciar a adição na árvore
            // passando as variáveis parent, childL e childR
            Insert(parent, childL, childR);
        }

        cout << "=======================================" << endl;
        wcout << L"============ ÁRVORE GERADA ============" << endl;
        cout << "=======================================" << endl;
        // Chamo o método Print() para iniciar a impressão da árvore
        Print();
        // Chamo os métodos Nodes() e Leaves para iniciar a contagem
        // do número de nós e folhas
        cout << Nodes() << " " << Leaves() << endl;
        cout << endl;

        // Fecho o arquivo
        file.close();
    } else {
        // Caso não tenha sido possível abrir o arquivo, exibo uma mensagem de erro
        // e retorno para a tarefa anterior
        cout << endl;
        wcerr << L"Não foi possível abrir o arquivo." << endl;
        cout << endl;
        return;
    }
}

// Definição do método Insert() que recebe os valores parent, childL e childR
void BinaryTreeCreate::Insert(const string& parent, const string& childL, const string& childR) {
    // Chamo o método SearchInsert() para iniciar a busca e inserção dos nós
    // passando as variáveis root, parent, childL e childR
    SearchInsert(root, parent, childL, childR);
}

// Definição do método SearchInsert() que recebe os valores t, parent, childL e childR
void BinaryTreeCreate::SearchInsert(TreePointer &t, const string& parent, const string& childL, const string& childR) {
    // Verifico se a raiz é nula
    if (root == nullptr) {
        // Caso seja, crio um novo nó e atribuo o valor de parent
        root = new TreeNode;
        root->Entry = parent;
        // Deixo os nós filhos nulos
        root->LeftNode = root->RightNode = nullptr;
    }

    // Verifico se o nó atual é nulo
    if (t == nullptr) {
        // Caso seja, retorno
        return;
    }

    // Verifico se as variáveis parent, childL e childR são iguais a "X"
    if (parent == "X" && childL == "X" && childR == "X") {
        // Caso sejam, retorno
        return;
    }

    // Verifico se o valor do nó atual é igual ao valor de parent
    if (t->Entry == parent) {
        // Caso seja, verifico se o valor de childL é diferente de "X"
        if (childL != "X") {
            // Caso seja, crio um novo nó para o filho da esquerda
            t->LeftNode = new TreeNode;
            // Atribuo o valor de childL ao nó
            t->LeftNode->Entry = childL;
            // Deixo os nós filhos nulos
            t->LeftNode->LeftNode = t->LeftNode->RightNode = nullptr;
        }
        // Verifico se o valor de childR é diferente de "X"
        if (childR != "X") {
            // Caso seja, crio um novo nó para o filho da direita
            t->RightNode = new TreeNode;
            // Atribuo o valor de childR ao nó
            t->RightNode->Entry = childR;
            // Deixo os nós filhos nulos
            t->RightNode->LeftNode = t->RightNode->RightNode = nullptr;
        }
    } else {
        // Caso não seja, chamo o método SearchInsert() 
        // para continuar a busca a esquerda e a direita
        SearchInsert(t->LeftNode, parent, childL, childR);
        SearchInsert(t->RightNode, parent, childL, childR);
    }
}

// Definição do método Print() que chama o método PrintTree()
void BinaryTreeCreate::Print() {
    // Chamo o método PrintTree() com a raiz como parâmetro
    PrintTree(root);
}

// Definição do método PrintTree() que recebe o nó da árvore
void BinaryTreeCreate::PrintTree(TreePointer node) {
    // Verifico se o nó é nulo
    if (node == nullptr) {
        // Caso seja, retorno
        return;
    }

    // Inicio algumas verificações para ver se existem 
    // filhos a esquerda e a direita e caso existam,
    // exibo o valor do nó e a quantidade de filhos.
    // E caso não existam, mostro que a quantidade 
    // de filhos é 0 e é um nó folha
    if (node->LeftNode == nullptr && node->RightNode == nullptr) {
        cout << node->Entry << " 0 F" << endl;
    } else if (node->LeftNode != nullptr && node->RightNode != nullptr) {
        cout << node->Entry << " 2 ED" << endl;
    } else if (node->LeftNode != nullptr) {
        cout << node->Entry << " 1 E" << endl;
    } else {
        cout << node->Entry << " 1 D" << endl;
    }

    // Chamo o método PrintTree() para continuar a impressão
    // passando os nós filhos a esquerda e a direita
    PrintTree(node->LeftNode);
    PrintTree(node->RightNode);
}

// Definição do método Nodes() que chama o método NodesNumber()
int BinaryTreeCreate::Nodes() {
    // Retorno o valor retornado pelo método NodesNumber()
    return NodesNumber(root);
}

// Definição do método NodesNumber() que recebe o nó da árvore
int BinaryTreeCreate::NodesNumber(TreePointer &t) {
    // Verifico se o nó é nulo
    if (t == nullptr) {
        // Caso seja, retorno 0
        return 0;
    }

    // Inicio a contagem dos nós da arvore, percorrendo tanto
    // à esquerda quanto à direita
    return 1 + NodesNumber(t->LeftNode) + NodesNumber(t->RightNode);
}

// Definição do método Leaves() que chama o método LeavesNumber()
int BinaryTreeCreate::Leaves() {
    // Retorno o valor retornado pelo método LeavesNumber()
    return LeavesNumber(root);
}

// Definição do método LeavesNumber() que recebe o nó da árvore
int BinaryTreeCreate::LeavesNumber(TreePointer &t) {
    // Verifico se o nó é nulo
    if (t == nullptr) {
        // Caso seja, retorno 0
        return 0;
    }

    // Verifico se o nó atual possui filhos
    if (t->LeftNode == nullptr && t->RightNode == nullptr) {
        // Caso não possua, retorno 1
        return 1;
    }

    // Inicio a contagem das folhas da arvore, percorrendo tanto
    // à esquerda quanto à direita
    return LeavesNumber(t->LeftNode) + LeavesNumber(t->RightNode);
}