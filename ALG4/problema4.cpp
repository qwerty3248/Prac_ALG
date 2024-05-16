#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define TAM 10
#define MUNDO_BELKAN 2

//Funcion que mira si una funcion es valida en el laberinto
bool esValida(int fila, int columna , const int laberinto[TAM][TAM]){
	return (fila >= 0 && fila < TAM && columna >= 0 &&
	        columna < TAM && laberinto[fila][columna] == 0);
}
//La pos_actual es la pos_inicial al principio o de donde quieras emepzar
bool EncontrarSalidaLaberinto(pair<int,int> pos_actual,pair<int,int> &salida,
int laberinto[TAM][TAM], vector<pair<int,int>> &camino){
	
	if (pos_actual == salida){
		camino.push_back(pos_actual);
		return true;
	}//Si es la solucion salimos 
	
	
	//Marcamos la pos actual como visitada
	
	int fila = pos_actual.first;
	int columna = pos_actual.second;
	laberinto[fila][columna] = 2;//El 2 porque me gusta como si pongo el 9
	//Las direcciones que son arriba abajo izquierda y derecha
	int filas [] = {-1,1,0,0};
	int columnas[] = {0,0,-1,1};
	
	for (int i = 0; i < 4; i++){
		int nueva_fil = fila + filas[i];
		int nueva_col = columna + columnas[i];
		
		if (esValida(nueva_fil,nueva_col, laberinto)){
			//Si es valida la agregamos al camino
			camino.push_back(pos_actual);
			
			//La pos actual ahora es la nueva, es decir la siguiente
			if (EncontrarSalidaLaberinto({nueva_fil,nueva_col},
			    salida, laberinto, camino)){
				return true;
			
			
			}
			
			//Si no encuentro salida desde esa pos, no tengo otra
			//mas que retroceder
			
			camino.pop_back();
		
		
		}
	
	}
	
	
	//Si el camino no lleva a ningun lugar ponemos 0 nuevamente en el maze
	laberinto[fila][columna] = 0;
	return false;

}

void imprimirLaberinto(int laberinto[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", laberinto[i][j]);
        }
        printf("\n");
    }
}

void generarLaberinto(int laberinto[TAM][TAM]) {
    // Inicializar todo el laberinto como muros (1)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            laberinto[i][j] = 1;
        }
    }

    // Establecer entrada en la esquina superior izquierda
    laberinto[0][0] = 0;

    // Crear dos caminos hacia la salida (esquina inferior derecha)
    for (int i = 1; i < TAM; i++) {
        laberinto[i][1] = 0;
    }
    for (int i = 1; i < TAM - 1; i++) {
        laberinto[TAM - 2][i] = 0;
    }
}



int main (void){
    
  cout << "La pos de inicio es (0,0) y la pos final es la (TAM-1,TAM-1)\n";
  cout << "El tamano siempre sera un laberinto de 10*10\n";
  cout << "Para estas pruebas\n";
  
  //Se da por hecho de que la posicion inicial  y la posicion final estara
  //dentro de la matriz además de que la matriz tendra un tamaño valido
  
  int laberinto[TAM][TAM];
  generarLaberinto(laberinto);
  laberinto[0][TAM-9] = 0;
  //comientzo en 3,1 acabo en 3,8
  for (int i = 1; i <= TAM-2; i++ ){
  	laberinto[3][i] = 0;
  }
  //de la fila 3 a la 8
  for (int i = 3; i <= TAM-3; i++){
  	laberinto[i][TAM-2] = 0;
  }
  laberinto[TAM-2][TAM-1]= 0;
  laberinto[TAM-1][TAM-1]= 0;
  laberinto[9][1]=1;
  cout << endl;
  cout << "Este es el laberinto\n";
  imprimirLaberinto(laberinto);
  cout << endl;
  
  pair<int,int> salida = {TAM-1,TAM-1};
  pair <int,int> entrada = {0,0};
  vector<pair<int,int>> camino;
  
  
  //Este sera el laberinto con el cual se va a probar el 
  //algortimo
  
  if (EncontrarSalidaLaberinto(entrada,salida,laberinto,camino)){
  	cout << "El camino a seguir es: ";
  	for (int i = 0; i < camino.size(); i++){
  		cout << "("<<camino[i].first<<", "<<camino[i].second<<")";
  		if (i < camino.size()-1){
  			cout << ", ";
  		}
  	}
  	cout << endl;
  	cout << "Ahora vamos a ver si el camino concuerda con el laberinto\n";
  	for (int i = 0; i < camino.size(); i++){
  		laberinto[camino[i].first][camino[i].second] = 2;
  	}
  	cout << endl;
	cout << "Este es el laberinto\n";
	imprimirLaberinto(laberinto);
	cout << endl;
  
  }else{
  	cout << "No se encontro el camino\n";
  }
  
  
  
  
  return 0;
  

}

