#include <iostream>
#include <iostream>
#include <fstream>
#include<cstdlib>
#include<string.h>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


string leer_string(istream& is){
	string a =0;
	is >> a;
	return a;
};

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

int largo_cadena(string cadena)
{
	int largo=0;
	while (cadena[largo]!='\0') 
	{
		largo++;
	}
	return largo;
}


void get_nota_cred(string cadena, string *nota, string *credito)
{
	int largo=0;
	int tam_nota=0;
	int tam_cred=0;
	bool coma = 0;
	string nota2 = "";
	string cred2 = "";
	char* notas1; 
    char* creditos1;
    int j;	
	
	while (cadena[largo]!='\0') 
	{
		if(cadena[largo]==','){
			coma = 1;
			
		}	
		if(!coma)
		{	
			nota2[largo] = cadena[largo];	
			//cout<<"\n Entro "<<nota2[largo];
			tam_nota++;
		}
		if(coma)
		{	
			tam_cred++;
		}
		largo++;
		//cout<<"\n Así va: "<<nota2;
	}
	tam_cred = tam_cred-1;
	//cout<<"\n Tam nota : "<<tam_nota;
	//cout<<"\n Tam cred : "<<tam_cred;
	
	notas1 = new char[tam_nota];
	creditos1 = new char[tam_cred];
	
	//cout<<"\n cred : "<<creditos[1];
	
	for(int i=0; i<tam_nota; i++){ 
		notas1[i]=cadena[i];
		//cout<<"\n"<<notas[i];
	};
	
	nota2 = notas1;
	
	//cout<<"\n este es el resultado: "<<nota2;
	j=tam_nota+1;
	cred2 = cadena[j];
	//cout<<"\n este es el resultado: "<<cred2;
	
	
	*nota = nota2;
	*credito = cred2;
//	return 0;
}



int main(int argc, char** argv) {
	int x=0;
    double* notas; 
    double* creditos; 
    double suma=0,suma_creditos=0,papa=0,avance=0,sum_cred_no_perd=0,pa;
	ifstream archivo;//("notas3.txt"); 
	archivo.open("notas3.txt");
	
	bool flag = 1;
	int j = 0;
	//notas = new char[x];
	string dato;
	string note;
	string cred; 
	int p;
	while((!archivo.eof())&&flag){ // To get you all the lines.
	    getline(archivo,dato); // Saves the line in STRING.
	    if(dato!="")
	    {
	    	x++;
	    }else{flag=0;}

	}
	archivo.close(); 
	notas = new double[x];
	creditos = new double[x];
	archivo.open("notas3.txt");
	
	for(int i=0; i<x; i++){
		
	    getline(archivo,dato); // Saves the line in STRING.
	    //cout<<"\n Dato "<<dato; // Prints our STRING.	
	    if(dato!="")
	    {
			get_nota_cred(dato,&note,&cred);		
			notas[i]=atof(note.c_str()); //convert string to number
			creditos[i]=atof(cred.c_str());//convert string to number
			cout<<"\n Nota: "<<notas[i];
			cout<<" Creditos: "<<creditos[i];
	    }			
		
	};
	archivo.close();
	int x2=0;
	for(int i=0; i<x; i++){
		suma_creditos += creditos[i];
		suma += creditos[i]*notas[i];
		
		if(notas[i]>=3.0)
		{
			sum_cred_no_perd += creditos[i];
			pa += notas[i];
			x2++;
		};
				

	};	
	papa=suma/(suma_creditos); //PAPPA
	//sum_cred_no_perd = sum_cred_no_perd - 4; //le esestoy quitando matematicas basicas
	pa = pa/x2; //Promedio academico
	avance = (sum_cred_no_perd/172)*100; //Avance carrera
	cout<<endl;
	cout<<"\n P.A.P.A. : "<<papa;
	cout<<"\n P.A. : "<<pa;
	cout<<"\n Avance: "<<avance<<"%";
	cout<<"\n Materias vistas: "<<x2;
	//cout<<"\n Materias vistas: "<<x2-1;//le esestoy quitando matematicas basicas
	cout<<"\n Creditos: "<<sum_cred_no_perd;
	return 0;	
		

}	
