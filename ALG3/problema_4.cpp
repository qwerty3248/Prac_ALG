#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> 

using namespace std;

const int INFINITO = numeric_limits<int>::max(); // Usamos INFINITO en lugar de INF

// Función para encontrar el camino más corto desde el nodo de inicio al nodo de destino en un grafo ponderado
vector<int> dijkstra(const vector<vector<int>>& grafo, int inicio, int destino) {
    int n = grafo.size(); // Número de nodos en el grafo
    vector<int> distancia(n, INFINITO); // Distancia mínima desde el nodo de inicio a cada nodo
    vector<bool> visitado(n, false); // Bandera para marcar los nodos visitados
    vector<int> anterior(n, -1); // Almacenar el nodo anterior en el camino más corto
    
    distancia[inicio] = 0; // La distancia desde el nodo de inicio hasta sí mismo es 0
    
    // Iteramos sobre todos los nodos del grafo
    for (int i = 0; i < n; ++i) {
        int minDistancia = INFINITO;
        int u = -1;
        
        // Encontramos el nodo no visitado con la distancia mínima actual
        for (int j = 0; j < n; ++j) {
            if (!visitado[j] && distancia[j] < minDistancia) {
                minDistancia = distancia[j];
                u = j;
            }
        }
        
        // Si no se encuentra un nodo válido, o hemos llegado al nodo de destino, salimos del bucle
        if (u == -1 || u == destino) break;
        
        visitado[u] = true; // Marcamos el nodo como visitado
        
        // Actualizamos las distancias mínimas a los nodos vecinos no visitados
        for (int v = 0; v < n; ++v) {
            if (!visitado[v] && grafo[u][v] != INFINITO && distancia[u] + grafo[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + grafo[u][v];
                anterior[v] = u;
            }
        }
    }
    
    // Reconstruimos el camino más corto desde el nodo de destino hasta el nodo de inicio
    vector<int> camino;
    for (int v = destino; v != -1; v = anterior[v]) {
        camino.push_back(v);
    }
    reverse(camino.begin(), camino.end());
    
    return camino;
}

int main() {
    // Definimos el grafo como una matriz de distancias entre nodos
    vector<vector<int>> grafo = {
        {0, INFINITO, INFINITO, 1,12},
        {INFINITO, 0, 3, INFINITO,3},
        {INFINITO, 3, 0, INFINITO,4},
        {1, INFINITO, INFINITO, 0,2},
        {12,3,4,2,0}
    };

    vector<vector<int>> grafo2 = grafo;
    
    int inicio = 0; // Nodo de inicio
    int destino = 4; // Nodo de destino
    
    // Encontramos el camino más corto
    vector<int> caminoMasCorto = dijkstra(grafo2, inicio, destino);
    
    // Imprimimos el camino más corto encontrado
    cout << "Camino más corto desde el nodo " << inicio << " hasta el nodo " << destino << ": ";
    for (int nodo : caminoMasCorto) {
        cout << nodo << " ";
    }
    cout << endl;
    
    return 0;
}

