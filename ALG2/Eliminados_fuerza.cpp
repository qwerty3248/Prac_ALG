//CPP de eliminar repetidos de un vector por fuerza bruta
#include <iostream>
#include <vector>
using namespace std;

void Eliminar_repes(vector<int> &vec);

int main (void){
	vector<int> vec1 = {2,2,2,2,2,2,2,2};
	vector<int> vec2 = {1,1,12,44,44,3,2,23};
	vector<int> vec3 = {4,5,6,6,6,7,1,1};
	vector<int> vec4 = {3,3,2,3,3,3,3,3};
	vector<int> vec5 = {5,13,3,3,12,12,5,4};
	vector<int> vec6 = {3,3,1,9,1,7,7,1};
	
	for (size_t i = 0; i < vec1.size(); i++){
		cout << vec1[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec1);
	
	for (size_t i = 0; i < vec1.size(); i++){
		cout << vec1[i] << " ";
	
	}
	cout << endl;

	for (size_t i = 0; i < vec2.size(); i++){
		cout << vec2[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec2);
	
	for (size_t i = 0; i < vec2.size(); i++){
		cout << vec2[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec3.size(); i++){
		cout << vec3[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec3);
	
	for (size_t i = 0; i < vec3.size(); i++){
		cout << vec3[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec4.size(); i++){
		cout << vec4[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec4);
	
	for (size_t i = 0; i < vec4.size(); i++){
		cout << vec4[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec5.size(); i++){
		cout << vec5[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec5);
	
	for (size_t i = 0; i < vec5.size(); i++){
		cout << vec5[i] << " ";
	
	}
	cout << endl;

	for (size_t i = 0; i < vec6.size(); i++){
		cout << vec6[i] <<" ";
	}
	cout << endl;
	
	Eliminar_repes(vec6);
	
	for (size_t i = 0; i < vec6.size(); i++){
		cout << vec6[i] << " ";
	
	}
	cout << endl;
	return 0;
}

void Eliminar_repes(vector<int> &vec){
	int tam = vec.size();//tamanio del vector 
	vector<int> aux;//vector auxiliar
	bool esta;
	
	for (int i = 0; i < tam; i++){
		esta = false;
		for (size_t j = 0; j < aux.size(); j++){
			if (vec[i] == aux[j]){
				esta = true;
			
			}
		
		}
		if (!esta){
			aux.push_back(vec[i]);				
		}
	
	}
	vec = aux;

}
