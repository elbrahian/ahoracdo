#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;


void crearUsuario(string nombreArchivo,string nombreUsuario,int puntaje){
    fstream Archivo;

    Archivo.open(nombreArchivo,ios::app);

    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivo;
    }else{
        Archivo<<"Username: "<<nombreUsuario<<endl;
        Archivo<<"Puntaje: "<<puntaje<<endl;
        Archivo<<"_________________________________________"<<endl;
    }
    Archivo.close();
}
void mostrarUsuario(string nombreArchivo){
    fstream Archivo;
    Archivo.open(nombreArchivo,ios::in);
    string text;

    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivo;
    }else{

        while (!Archivo.eof()){
            getline(Archivo,text);
            cout<<text<<endl;
        }
    }
    Archivo.close();
}
