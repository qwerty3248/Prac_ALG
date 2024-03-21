//CPP de eliminar repetidos de un vector por fuerza bruta
#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>

using namespace std;

vector<int> Eliminar_repes(vector<int> &vec);
bool esta(const vector<int> vec, int num);

// Función para generar un vector aleatorio con elementos que pueden repetirse ocasionalmente
vector<int> generarVectorAleatorioConRepeticiones(int n, double probabilidad_repeticion) {
    vector<int> v(n);
    
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    
    for (int i = 0; i < n; ++i) {
        // Generar un número aleatorio entre 0 y n-1
        v[i] = rand() % n;
        
        // Introducir la probabilidad de repetición
        if ((double) rand() / RAND_MAX < probabilidad_repeticion) {
            // Repetir el número ocasionalmente
            v[i] = v[rand() % n]; // Seleccionar un número aleatorio previamente generado
        }
    }
    
    return v;
}

int main(int argc, char *argv[]) {

	//int *v;
	int n,argumento/*, i*/;
	double probabilidad = 0.7;
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
		vector<int> v = generarVectorAleatorioConRepeticiones(n,probabilidad);

		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		//for (i= 0; i<n; i++)
		//	v[i]= rand()%n;

		cerr << "Ejecutando Divide y venceras para tam. caso: " << n << endl;

		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		Eliminar_repes(v);
		//shell(v,n);
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;

		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";


		// Liberamos memoria del vector
		//delete [] v;
	}

	// Cerramos fichero de salida
	fsalida.close();

	return 0;
}
bool esta(const vector<int> vec, int num){
	bool esta = false;
	for (size_t i = 0 ; i < vec.size(); i++){
		if (vec[i] == num){
			esta = true;
			break;
		}
	}
	return esta;

}//O(n)
vector<int> Eliminar_repes(vector<int> &vec){
	if (vec.size() == 1){
		return vec;
	}//Caso base
	
	vector<int> primera_mitad (vec.begin(),vec.begin() + vec.size() / 2);
	vector<int> segunda_mitad (vec.begin() + vec.size() / 2, vec.end());
	
	
	vector<int> eliminados_primera = Eliminar_repes(primera_mitad);
	vector<int> eliminados_segunda = Eliminar_repes(segunda_mitad);
	
	//Metemos en resultados los que no esten solamente de cada mitad
	vector<int> resultado;
	
	for (int num : eliminados_primera){
		if (!esta(resultado, num)){
			resultado.push_back(num);
		}
	}
	for (int num : eliminados_segunda){
		if (!esta(resultado,num)){
			resultado.push_back(num);
		}
	}
	
	return resultado;

}//O(n*log(n))









