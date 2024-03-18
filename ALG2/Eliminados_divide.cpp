//CPP de eliminar repetidos de un vector por fuerza bruta
#include <iostream>
#include <vector>
using namespace std;

vector<int> Eliminar_repes(vector<int> &vec);
bool esta(const vector<int> vec, int num);

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
	
	vec1 = Eliminar_repes(vec1);
	
	for (size_t i = 0; i < vec1.size(); i++){
		cout << vec1[i] << " ";
	
	}
	cout << endl;

	for (size_t i = 0; i < vec2.size(); i++){
		cout << vec2[i] <<" ";
	}
	cout << endl;
	
	vec2 = Eliminar_repes(vec2);
	
	for (size_t i = 0; i < vec2.size(); i++){
		cout << vec2[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec3.size(); i++){
		cout << vec3[i] <<" ";
	}
	cout << endl;
	
	vec3 = Eliminar_repes(vec3);
	
	for (size_t i = 0; i < vec3.size(); i++){
		cout << vec3[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec4.size(); i++){
		cout << vec4[i] <<" ";
	}
	cout << endl;
	
	vec4 = Eliminar_repes(vec4);
	
	for (size_t i = 0; i < vec4.size(); i++){
		cout << vec4[i] << " ";
	
	}
	cout << endl;	

	for (size_t i = 0; i < vec5.size(); i++){
		cout << vec5[i] <<" ";
	}
	cout << endl;
	
	vec5 = Eliminar_repes(vec5);
	
	for (size_t i = 0; i < vec5.size(); i++){
		cout << vec5[i] << " ";
	
	}
	cout << endl;

	for (size_t i = 0; i < vec6.size(); i++){
		cout << vec6[i] <<" ";
	}
	cout << endl;
	
	vec6 = Eliminar_repes(vec6);
	
	for (size_t i = 0; i < vec6.size(); i++){
		cout << vec6[i] << " ";
	
	}
	cout << endl;
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









