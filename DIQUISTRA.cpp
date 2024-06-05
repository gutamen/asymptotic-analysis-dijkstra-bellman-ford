int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index; // atribuicao 1 

    for (int v = 0; v < V; v++) // 2V + 2
        if (sptSet[v] == false && dist[v] <= min) //(1 vetor + 1 comparacao + 1 operacao '&&' + 1 vetor + 1 comparacao)* V = 5V
            min = dist[v], min_index = v;

    return min_index; // 1
}

//Custo da funcao = 1 + 2V + 2 + 5V + 1 = 7V + 4

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl; // custo 1
    for (int i = 0; i < V; i++) //2V + 2
        cout << i << " \t\t\t\t" << dist[i] << endl; //custo 2 (acesso e cout)2V
	// 4V + 3
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	// The output array.  dist[i] will hold the shortest distance from src to i
    int dist[V]; // custo 1

	// sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    bool sptSet[V]; // custo 1

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++) // 2V + 2
        dist[i] = INT_MAX, sptSet[i] = false; // (1 index + 1 atribuicao + 1 index + 1 atribuicao)*V = 4V

    // Distance of source vertex from itself is always 0
    dist[src] = 0; // 1 index + 1 atribuicao = 2

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) { // 3(V-1) + 2 = 3V - 1
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet); // (1 atribuicao + chamada funcao(7V + 4))*(V-1) = (7V + 5)(V - 1) = 7V^2 - 7V + 5V - 5 = 7V^2 - 2V - 5

        // Mark the picked vertex as processed
        sptSet[u] = true; //(1 index + 1 atribuicao)*(V - 1) = 2V - 2

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++) // (2V + 2)(V - 1) = 2V^2 - 2V + 2V -2 = 2V^2 - 2

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) // (3 operacoes '&&' + 4 comparacoes + 8 index + 1 operacao '!')(V^2 - V) = 16V^2 - 16V
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist); // 4V + 3
}