/*
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void codificacion(int*,int*,int*);
void contador(int*,int*,int*);

int main()
{
    short n;
    char letra;
    int Nbinario;
    int cero=0;
    int uno=0;

    cout<<"Ingrese un numero que sera la semilla de codificacion: ";
    cin>>n;

    char palabra[n]={};
    int letra_binario[8]={};
    int palabra_codificada[8*n]={};
    int posicion=(8*n)-1;

    // Abrir el archivo para lectura
       ifstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/archivo.txt");

       // Verifica si el archivo se abrio correctamente
       if (!archivo.is_open()) {
           cout << "Error al abrir el archivo" << endl;
           return 1;
       }

       // Leer letra por letra
       int i=0;
       while (archivo >> letra) {
             palabra[i]=letra;
             i++;
       }

       // Cierra el archivo
       archivo.close();

    //toma letra por letra

    for(int i=(n-1); i>=0; i--) {
        letra=palabra[i];
        //convierte la letra a binario
        for (int j=7; j>=0; j--) {
            Nbinario=((letra>>j)&1);
            letra_binario[j]=Nbinario;
            }
 //primer metodo
        if (cero==uno || i==(n-1)){
            cero=0;
            uno=0;
            //contador de 1 y 0
            contador(letra_binario,&cero,&uno);
            //cambia 1 a 0 y viceversa
            for (int k=7; k>=0; k--) {
                if(letra_binario[k]==0)letra_binario[k]=1;
                else if(letra_binario[k]==1)letra_binario[k]=0;
            }
            //pasa la letra en binario a un arreglo
            codificacion(letra_binario, palabra_codificada,&posicion);
        }

        else if (cero>uno){
            cero=0;
            uno=0;
            //contador de 1 y 0
            contador(letra_binario,&cero,&uno);
            //cambia 1 a 0 y viceversa
            for (int k=6; k>=0; k-=2){
                if(letra_binario[k]==0)letra_binario[k]=1;
                else if(letra_binario[k]==1)letra_binario[k]=0;
            }
            //pasa la letra en binario a un arreglo
            codificacion(letra_binario, palabra_codificada,&posicion);
        }

        else if (cero<uno){
            cero=0;
            uno=0;
            //contador de 1 y 0
            contador(letra_binario,&cero,&uno);
            //cambia 1 a 0 y viceversa
            for (int k=5; k>=0; k-=3) {
                if(letra_binario[k]==0)letra_binario[k]=1;
                else if(letra_binario[k]==1)letra_binario[k]=0;
            }
            //pasa la letra en binario a un arreglo
            codificacion(letra_binario, palabra_codificada,&posicion);
         }
    }
    //imprime la palabra completa codificada
    for (int i=0;  i<8*n; i++) {
        cout<<palabra_codificada[i];
    }
    cout<<endl;
    return 0;
}


//pasa la letra en binario a un arreglo
void codificacion(int *letra_binario,int *palabra_codificada,int *posicion) {
    for (int k = 0; k <= 7; k++) {
        *(palabra_codificada+(*posicion))=*(letra_binario+k);
        (*posicion)--;
    }
}
//contador de 1 y 0
void contador(int *letra_binario,int *cero,int *uno){
    for (int k=7; k>=0; k--) {
        if(*(letra_binario+k)==0)(*cero)++;
        else if(*(letra_binario+k)==1)(*uno)++;
    }
}
*/
