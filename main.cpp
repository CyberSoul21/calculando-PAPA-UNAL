#include <iostream>
#include <iostream>
#include <fstream>
#include<cstdlib>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

double leer(istream& is){
	double a =0;
	is >> a;
	return a;
};

bool leer_b(istream& is){

	bool valor = false;
	is >> valor;
	return valor;

};

ostream& escribir_b(ostream& os,bool v)
{
	string bol = "";

	if(v){
		bol="true";
		os << bol;
	}else{
		bol="false";
		os << bol;
	};
	
	return os;
};

ostream& escribir(ostream& os,double n)
{
	//n=(n)*(-1);
	os << n;
	return os;	
}; 

int main(int argc, char** argv) {

    int x=0;
    double* notas; 
    double* creditos; 
    double suma=0,suma_creditos=0,papa=0,avance=0,sum_cred_no_perd=0;
	ifstream archivo("notas.txt"); 

	cout<<"Digite cantidad de materias: ";
	//cout<<'O'+'.'+'.';
	x = leer(cin);
	notas = new double[x];
	creditos = new double[x];
	for(int i=0; i<x; i++){ 
		notas[i]=leer(archivo);
		cout<<" "<<notas[i];
	};
	cout<<endl;
	for(int i=0; i<x; i++){
		creditos[i]=leer(archivo);
		suma_creditos += creditos[i];
		cout<<" "<<creditos[i];
	};
	cout<<endl;
	for(int i=0; i<x; i++){
		suma += creditos[i]*notas[i];
		if(notas[i]>=3.0)
		{
			sum_cred_no_perd += creditos[i];
		};
		
	};
	
	papa=suma/(suma_creditos);
	escribir(cout,papa);
	cout << endl;
	sum_cred_no_perd = sum_cred_no_perd;
	escribir(cout,sum_cred_no_perd);
	cout << endl;
	avance = (sum_cred_no_perd/172)*100;
	escribir(cout,avance);
	cout << endl;
	// escribir(salida,x);	
	archivo.close();

	return 0;
}
