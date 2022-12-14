#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n; cin >> n;
	long long suma = 0;
	map<int,int> m;
	vector<int> v;

	// agregan elementos al vector
	for (int i = 0; i < n; i++){
		int value; cin >> value;
		v.push_back(value);
	}
	
	/*
	Para cada numero, se busca otro numero, tal que su suma es una potencia de 2.
	Como las potencias llegan a 2^31, restamos para cada potencia el valor del elemento
	y buscamos en el mapa si existe. Si existe agregamos todos los elementos que estaban en el mapa
	ya que como son iguales todos los pares son validos. Si no existe se agrega aquel valor al mapa.
	*/
	for(int i = 0; i < n; i++){
		int power2 = 1;
		for (int j = 0; j < 31; j++){
			int aux = power2 - v[i];
			if(m.count(aux)) suma += m[aux];
			power2 = power2 << 1;
		}
		if(!m.count(v[i])) m[v[i]] = 0;
		m[v[i]]++;
	}

	cout << suma << endl;

	return 0;
}