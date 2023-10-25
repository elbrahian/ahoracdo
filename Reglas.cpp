#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <string.h>

using namespace std;




void mostrarReglas(string nombreArchivo){
    fstream Archivo;
    Archivo.open(nombreArchivo,ios::in);
    string text;

    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivo;
    }else{
        cout<<"_____________________________________________________________"<<endl;

        while (!Archivo.eof()){
            getline(Archivo,text);
            cout<<text<<endl;
        }
        cout<<"_____________________________________________________________"<<endl;
    }
    Archivo.close();
}

void crearRegla(string nombreArchivo){
    fstream Archivo;
    Archivo.open(nombreArchivo,ios::app);
    int opcion;
    string regla;


    if(!Archivo){
        cout<<"ERROR AL ABRIR EL ARCHIVO: "<<nombreArchivo;
    }else{

        do{
            fflush(stdin);
            cout<<"Ingrese una regla"<<endl;
            getline(cin,regla);
            Archivo<<"->"<<regla<<endl;

            cout<<"\t Ingrese 1 para continuar"<<endl;
            cout<<"\t Ingrese 0 para salir"<<endl;
            cin>>opcion;

        }while(opcion!=0);
    }
    Archivo.close();
}
