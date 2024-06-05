void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V; // custo de acesso com ponteiro 1 + custo de atribuicao 1 = 2
    int E = graph->E; // custo de acesso com ponteiro 1 + custo de atribuicao 1 = 2
    int dist[V]; // custo de iniciar vetor 1

    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for (int i = 0; i < V; i++) // 2V + 2
        dist[i] = INT_MAX; // (custo da atribuicao 1 + custo do acesso ao vetor) * V = 2V
    dist[src] = 0; // custo de acesso no vetor 1 + custo de atribuicao 1 = 2

    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++) { // 3(V-1) + 2 (comparacao, operacao de subtracao e incremento de i acontecem V vezes)
        for (int j = 0; j < E; j++) { // (2E + 2) * (V-1) = 2E(V-1) + 2(V-1)
            int u = graph->edge[j].src; // (atribuicao 1 + declaracao de var 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E(V-1) = 5E(V-1)
            int v = graph->edge[j].dest; // (atribuicao 1 + declaracao de var 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E(V-1) = 5E(V-1)
            int weight = graph->edge[j].weight; // (atribuicao 1 + declaracao de var 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E(V-1) = 5E(V-1)
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				// (acesso vetor 1 + comparacao '!=' 1 + operador '&&' 1 + acesso vetor 1 + operacao soma 1 + comparacao '<' 1 + acesso vetor 1)*E(V-1)
				//7E(V-1)
                dist[v] = dist[u] + weight; // (acesso vetor 1 + atribuicao 1 + acesso vetor 1 + operacao soma 1)* (V-1)E = 4E(V-1)
        }
    }

    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (int i = 0; i < E; i++) { // 2E + 2
        int u = graph->edge[i].src; // (atribuicao 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E = 4E
        int v = graph->edge[i].dest; // (atribuicao 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E = 4E
        int weight = graph->edge[i].weight; // (atribuicao 1 + acesso ponteiro 1 + acesso vetor 1 + acesso estrutura 1)*E = 4E
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			// (acesso vetor 1 + comparacao '!=' 1 + operador '&&' 1 + acesso vetor 1 + operacao soma 1 + comparacao '<' 1 + acesso vetor 1)*E
			// 7E
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }

    printArr(dist, V); // custo 1

    return; // custo 1
}