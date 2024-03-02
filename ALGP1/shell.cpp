#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>
using namespace std;

void shellSort(int *arr, int n);

int main(int argc, char *argv[]) {

	int *v;
	int n, i, argumento;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	unsigned long int semilla;
	ofstream fsalida;

	if (argc <= 3) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}

	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}

	// Inicializamos generador de no. aleatorios
	semilla= atoi(argv[2]);
	srand(semilla);

	// Pasamos por cada tamaÒo de caso
	for (argumento= 3; argumento<argc; argumento++) {

		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);

		// Reservamos memoria para el vector
		v= new int[n];

		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (i= 0; i<n; i++)
			v[i]= rand()%n;

		cerr << "Ejecutando Shell Sort para tam. caso: " << n << endl;

		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		shellSort(v, n); // Ejecutamos el algoritmo para tamaÒo de caso tam
		//shell(v,n);
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;

		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";


		// Liberamos memoria del vector
		delete [] v;
	}

	// Cerramos fichero de salida
	fsalida.close();

	return 0;
}

void shellSort(int *arr, int n) {
    // Comenzamos con una brecha grande e ir reduciéndola
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realizamos inserción de elementos dentro de la brecha actual
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Mover los elementos de arr[0..i-gap], arr[1..i-gap+1], ... arr[i-gap] que son  
            //mayores que temp
            // hacia adelante para abrir espacio para temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Coloca temp (el elemento originalmente en arr[i]) en su posición correcta
            arr[j] = temp;
        }
    }
}

//Este shell no funciona
void shell (int *arr, int n){
	int  intervalo,i,valorAInsertar,posicionActual;
	for (intervalo = n/2; intervalo > 0; intervalo/=2){
		for (i=intervalo; i<n; i++){
			valorAInsertar = arr[i];
			posicionActual = i;
			
			
			while(posicionActual > 0 && 
			      arr[posicionActual-intervalo] > valorAInsertar){
			      
			      arr[posicionActual] = arr[posicionActual-intervalo];
			      posicionActual = posicionActual - intervalo;
			      
			      
			      }
			      
			if (posicionActual != i){
				arr[posicionActual] = valorAInsertar;
			
			}      
		
		}
	}


}

