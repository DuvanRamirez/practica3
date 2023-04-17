/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{   short n;
    short metodo=0;
    char letra;
    char Nbinario;
    int cero=0;
    int uno=0;
    int posicion=0;//para ayudar a almacenar los binarios en caracteres_binarios[]

    cout<<"Numero de bits para la codificacion: ";
    cin>>n;
    while(metodo!=1 || metodo!=2){
        cout<<"Metodo de codificacion 1 o 2: ";
        cin>>metodo;
        if(metodo==1 || metodo==2)break;
    }

    // Abrir el archivo para lectura
    ifstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/archivo.txt");

    // Verifica si el archivo se abrio correctamente
    if (!archivo.is_open()) {
       cout << "Error al abrir el archivo" << endl;
       return 1;
    }
    //cuenta los caracteres que hay en el archivo
    archivo.seekg(0, ios::end);//pasa el puntero al final del archivo
    int numero_caracteres = archivo.tellg();
    archivo.seekg(0, ios::beg);//vuelve el puntero al inicio del archivo

    string caracteres;
    caracteres.resize(numero_caracteres);//para almacenar los caracteres del texto
    string caracteres_binario;
    caracteres_binario.resize(8*numero_caracteres);//para almacenar los bunarios de cada caracter
    string caracteres_codificados;
    caracteres_codificados.resize(8*numero_caracteres);

    // Lee letra por letra y la almacena
    getline(archivo, caracteres);

    // Cierra el archivo
    archivo.close();

    //toma letra por letra
    for(int i=0; i<numero_caracteres; i++) {
        letra=caracteres[i];
        //convierte la letra a binario
        for (int j=7; j>=0; j--){
            Nbinario=((letra>>j)&1);
            caracteres_binario[posicion]=Nbinario+'0';
            posicion++;
            }
    }
    //agrego caracteres_binario[] a caracteres_codificados[] para hacer cambios
    for(int k=0; k<(numero_caracteres*8); k++) {
        caracteres_codificados[k]=caracteres_binario[k];
    }
    //limites para los bits
    int limiteA=0;
    int limiteB=n-1;

    switch(metodo){
        case 1:
        //primer metodo
        for(int i=0; i<(numero_caracteres*8); i++) {
            if (cero==uno){
                cero=0;
                uno=0;
                //contador de 1 y 0 //cambia 1 a 0 y viceversa
                for (int k=limiteA; k<=limiteB ; k++) {
                    if(caracteres_binario[k]-'0'==0){cero++;caracteres_codificados[k]='1';}
                    else if(caracteres_binario[k]-'0'==1){uno++;caracteres_codificados[k]='0';}
                }
            }
            else if (cero>uno){
                cero=0;
                uno=0;
                //contador de 1 y 0
                for (int k=limiteA; k<=limiteB ; k++) {
                    if(caracteres_binario[k]-'0'==0)cero++;
                    else if(caracteres_binario[k]-'0'==1)uno++;
                }
                //cambia 1 a 0 y viceversa
                for (int k=limiteA+1; k<=limiteB; k+=2){
                    if(caracteres_binario[k]-'0'==0)caracteres_codificados[k]='1';
                    else if(caracteres_binario[k]-'0'==1)caracteres_codificados[k]='0';
                }
            }

            else if (cero<uno){
                cero=0;
                uno=0;
                //contador de 1 y 0
                for (int k=limiteA; k<=limiteB ; k++) {
                    if(caracteres_binario[k]-'0'==0)cero++;
                    else if(caracteres_binario[k]-'0'==1)uno++;
                }
                //cambia 1 a 0 y viceversa
                for (int k=limiteA+2; k<=limiteB; k+=3) {
                    if(caracteres_binario[k]-'0'==0)caracteres_codificados[k]='1';
                    else if(caracteres_binario[k]-'0'==1)caracteres_codificados[k]='0';
                }

            }
            limiteA=limiteB+1;
            limiteB+=n;
            //cout<<caracteres_codificados[i];
        }
        break;
        case 2:
        //segundo metodo
            while(limiteA<numero_caracteres*8) {
                for (int k=limiteA; k<=limiteB ; k++) {
                    caracteres_codificados[k+1]=caracteres_binario[k];
                    if(k==limiteB)caracteres_codificados[limiteA]=caracteres_binario[k];
                }
                limiteA=limiteB+1;
                limiteB+=n;
            }
            break;
    }

    cout<<endl;

    // Abre el archivo de escritura
    ofstream archivo2("C:/Users/duvan/Documents/proyectos c++/practica3/codificacion.txt");
    // Verifica si el archivo se abrio correctamente
        if (!archivo2.is_open()) {
           cerr << "Error al abrir el archivo de escritura." << endl;
           return 1;
        }

        // Escribe en el archivo
        archivo2.seekp(0, ios::beg);
        archivo2 << caracteres_codificados;

        cout<<endl;
        cout<<caracteres_codificados<<endl;

    // Cierra el archivo
    archivo2.close();
    cout<<endl;
    cout<<endl;
    return 0;
}
*/
