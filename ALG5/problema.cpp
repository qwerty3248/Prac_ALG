#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

// Implementación del algoritmo de Floyd-Warshall adaptado con recuperación de camino
void floyd(const vector<vector<int>>& T, const vector<int>& E, vector<vector<int>>& D, vector<vector<int>>& P) {
    int n = T.size();
    
    // Inicialización de la matriz de distancias y predecesores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                D[i][j] = 0;
                P[i][j] = -1; // No hay predecesor
            } else if (T[i][j] != 0) {
                D[i][j] = T[i][j];
                P[i][j] = i; // El predecesor de j es i
            } else {
                D[i][j] = INF;
                P[i][j] = -1; // No hay predecesor
            }
        }
    }

    // Actualización de la matriz de distancias y predecesores
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] + E[k] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j] + E[k];
                    P[i][j] = P[k][j]; // Actualiza el predecesor
                }
            }
        }	
    }
}

// Función para recuperar el camino más corto
vector<int> camino(int i, int j, const vector<vector<int>>& P) {
    vector<int> path;
    if (P[i][j] == -1) {
        return path; // No hay camino
    }
    path.push_back(j);
    while (i != j) {
        j = P[i][j];
        path.push_back(j);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Matriz de tiempos T y vector de tiempos de escala E
    vector<vector<int>> T = {
        {0, 1, 3, 4},
        {1, 0, 2, 3},
        {3, 2, 0, 4},
        {4, 1, 4, 0} //cambie el 1 por el 3 de esta fila para tenerlo como ejemplo
    };
    vector<int> E = {1, 1, 1, 1};

    int n = T.size();
    vector<vector<int>> D(n, vector<int>(n, INF));
    vector<vector<int>> P(n, vector<int>(n, -1));

    floyd(T, E, D, P);

    // Imprimir la matriz de distancias mínimas
    cout << "Matriz de costos mínimos:" << endl;
    for (const auto& fila : D) {
        for (const auto& valor : fila) {
            if (valor == INF) {
                cout << "INF ";
            } else {
                cout << valor << " ";
            }
        }
        cout << endl;
    }

    // Recuperar y imprimir el camino más corto de ejemplo
    int start = 3, end = 0;
    vector<int> path = camino(start, end, P);
    cout << "Camino más corto de " << start + 1 << " a " << end + 1 << ": ";
    for (int city : path) {
        cout << city + 1 << " ";
    }
    cout << endl;

    return 0;
}

