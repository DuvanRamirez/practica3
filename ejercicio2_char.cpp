/*
#include <iostream>
#include <fstream>


using namespace std;



int main()
{   short n;
    short metodo=0;
    char numero;
    int cero=0;
    int uno=0;
    char letra;

    cout<<"Numero de bits para la codificacion: ";
    cin>>n;
    while(metodo!=1 || metodo!=2){
        cout<<"Metodo de codificacion 1 o 2: ";
        cin>>metodo;
        if(metodo==1 || metodo==2)break;
    }

    // Abrir el archivo para lectura
    ifstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/codificacion.txt");
    // Verifica si el archivo se abrio correctamente
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de lectura." << endl;
        return 1;
    }
    //cuenta los caracteres que hay en el archivo
    archivo.seekg(0, ios::end);//pasa el puntero al final del archivo
    int numero_caracteres = archivo.tellg();//cuenta
    archivo.seekg(0, ios::beg);//vuelve el puntero al inicio del archivo

    int caracteres_codificados[numero_caracteres];//para almacenar el numero codificado
    int caracteres_binario[numero_caracteres];//para almacenar el numero codificado
    char caracteres[(numero_caracteres)/8];//para almacenar los caracteres decodificados

    // Lee numero por numero
    int i=0;
    while (archivo >> numero) {
          caracteres_codificados[i]=numero-'0';
          i++;
    }

    // Cierra el archivo
    archivo.close();

    //agrego caracteres_codificados[] a caracteres_binario[] para hacer cambios
    for(int k=0; k<numero_caracteres; k++) {
        caracteres_binario[k]=caracteres_codificados[k];
    }

    //limites para los bits
    int limiteA=0;
    int limiteB=n-1;

    switch(metodo){
        case 1:
        //primer metodo
            for(int i=0; i<(numero_caracteres); i++) {
                if (cero==uno){
                    cero=0;
                    uno=0;
                    //contador de 1 y 0 //cambia 1 a 0 y viceversa
                    for (int k=limiteA; k<=limiteB ; k++) {
                        if(caracteres_codificados[k]==0){uno++;caracteres_binario[k]=1;}
                        else if(caracteres_codificados[k]==1){cero++;caracteres_binario[k]=0;}
                    }
                }
                else if (cero>uno){
                    cero=0;
                    uno=0;
                    //cambia 1 a 0 y viceversa
                    for (int k=limiteA+1; k<=limiteB; k+=2){
                        if(caracteres_codificados[k]==0)caracteres_binario[k]=1;
                        else if(caracteres_codificados[k]==1)caracteres_binario[k]=0;
                    }
                    //contador de 1 y 0
                    for (int k=limiteA; k<=limiteB ; k++) {
                        if(caracteres_codificados[k]==0)cero++;
                        else if(caracteres_codificados[k]==1)uno++;
                    }
                }

                else if (cero<uno){
                    cero=0;
                    uno=0;
                    //cambia 1 a 0 y viceversa
                    for (int k=limiteA+2; k<=limiteB; k+=3) {
                        if(caracteres_codificados[k]==0)caracteres_binario[k]=1;
                        else if(caracteres_codificados[k]==1)caracteres_binario[k]=0;
                    }
                    //contador de 1 y 0
                    for (int k=limiteA; k<=limiteB ; k++) {
                        if(caracteres_codificados[k]==0)cero++;
                        else if(caracteres_codificados[k]==1)uno++;
                    }
                }

                limiteA=limiteB+1;
                limiteB+=n;
            }
            break;
        case 2:
        //segundo metodo
            while(limiteA<numero_caracteres) {
                for (int k=limiteA; k<=limiteB ; k++) {
                    if(k>limiteA)caracteres_binario[k-1]=caracteres_codificados[k];
                    if(k==limiteA)caracteres_binario[k+(n-1)]=caracteres_codificados[k];
                }
                limiteA=limiteB+1;
                limiteB+=n;
            }
            break;
    }

    //limites para recorrer caracteres_binario[]
    int limiteC=0;
    int limiteD=7;

    for (int i = 0; i < (numero_caracteres/8); i++){
        //cambia binario por letra
        for (int k = limiteD; k >= limiteC; --k) {
            if (caracteres_binario[k] == 1) {
                letra |= 1 << (limiteD - k);
            }
        }
        //agrega las letras a un arreglo
        caracteres[i]=letra;
        letra=0;//reinicia la letra
        limiteC=limiteD+1;
        limiteD+=8;
    }
    cout<<endl;
    // Abre el archivo de escritura
    ofstream archivo2("C:/Users/duvan/Documents/proyectos c++/practica3/decodificacion.txt");
    // Verifica si el archivo se abrio correctamente
    if (!archivo2.is_open()) {
       cerr << "Error al abrir el archivo de escritura." << endl;
       return 1;
    }
    //imprime la palabra y la copia en decodificacion.txt
    for (int i=0; i<(numero_caracteres/8); i++) {
        cout<<caracteres[i];
        archivo2.seekp(i, ios::beg);
        // Escribe en el archivo
        archivo2 << caracteres[i];


    }
    // Cierra el archivo
    archivo2.close();

    cout<<endl;
    cout<<endl;
    return 0;
}
*/
