void Queue::Clear() {
    // Implementar Clear(), usando apenas Serve() e Empty()
    int x;

    while(!Empty()) {
        Serve(x);
    };
};

void Queue::Clear() {
    // Implementrar Clear() trabalhando diretamente com ponteiros
    QueueNode *p;
    while (head != NULL)
    {
        // Guarda o próximo elemento da fila para ser deletado.
        // Ou seja, p é a cabeça do nó que será removido na iteração seguinte.
        // q guardará o valor apontador "next" do nó anterior àquele que está sendo excluído.
        // Atualiza os valores dos ponteiros antes de remover o primeiro elemento da lista.
        // Se não houvesse essas instruções, poderia haver um problema se for feita uma chamada ao método Remove
        // Se não houvesse esse passo, ao tentarmos remover o segundo elemento,
        // ele iria percorrer toda a lista até encontrar um nó vazio, pois o último elemento
        // teria seu campo next definido como NULL.
        // Esse comportamento pode parecer indesejável, mas funciona porque o método Remove()
        // sempre atualizará as referências aos elementos anteriores no caso de remoção bem sucedida.
        // Isso significa que se você tiver uma variável auxiliar chamada prev, ela irá armazenar o endereço
        // do elemento anterior ao elemento que foi removido, enquanto que a variável curr irá armazenar
        // o endereço do elemento que foi removido. Com isso, quando removemos o elemento 2, prev apontaria
        // para o elemento 1 e curr apontaria para o elemento 3. Quando removemos o elemento 4, prev apont

        p = head;
        head = head->NextNode;
        delete p;
    }

    tail = NULL;
}

