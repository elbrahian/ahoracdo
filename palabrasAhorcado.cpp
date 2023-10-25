#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <string.h>

using namespace std;

struct CrearPalabra{
    string palabra;
    string definicion;
    string sinonimo;
    string antonimo;
};

void crearWord(string nombreArchivos,CrearPalabra &word){

    int opcion;
    fstream Archivo;

    Archivo.open(nombreArchivos,ios::app);

    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivos;
    }else{
    do{
        fflush(stdin);
        cout<<"Ingrese La palabra"<<endl;
        getline(cin,word.palabra);
        Archivo<<"PALABRA: "<<word.palabra<<endl;

        cout<<"Ingrese la definicion de la palabra"<<endl;
        getline(cin,word.definicion);
        Archivo<<"DEFINICION: "<<word.definicion<<endl;

        cout<<"Ingrese el sinonimo"<<endl;
        getline(cin,word.sinonimo);
        Archivo<<"SINONIMO: "<<word.sinonimo<<endl;

        cout<<"Ingrese el antonimo"<<endl;
        getline(cin,word.antonimo);
        Archivo<<"ANTONIMO: "<<word.antonimo<<endl;

        Archivo<<"_______________________________________"<<endl;

        cout<<"\tIngrese 0 para continuar"<<endl;
        cout<<"\tIngrese 1 para salir"<<endl;
        cin>>opcion;

    }while(opcion==0);

    }

    Archivo.close();
}

void mostrarWord(string nombreArchivos){
    fstream Archivo;
    Archivo.open(nombreArchivos,ios::in);
    string text;

    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivos;
    }else{

        while (!Archivo.eof()){
            getline(Archivo,text);
            cout<<text<<endl;
        }
    }
    Archivo.close();
}
