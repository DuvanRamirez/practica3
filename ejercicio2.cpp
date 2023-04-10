/*
#include <iostream>
#include <fstream>


using namespace std;



int main()
{
    int n;

    cout<<"Ingrese un numero que sera la semilla de codificacion: ";
    cin>>n;

    int letra_binario[8];
    char letra = 0;
    int cero=0;
    int uno=0;
    char binario_codificado[n*8];
    int posicion=(n*8)-1;//posiciones de binario_codificado
    char palabra[n];
    int posicion2=n-1;//posicion de la palabra
    char numero;

       // Abrir el archivo para lectura
       ifstream archivo1("C:/Users/duvan/Documents/proyectos c++/practica3/codificacion.txt");
       // Abre el archivo de escritura
       ofstream archivo2("C:/Users/duvan/Documents/proyectos c++/practica3/decodificacion.txt");
       // Verifica si el archivo se abrio correctamente
       if (!archivo1.is_open()) {
           cout << "Error al abrir el archivo de lectura." << endl;
           return 1;
       }

       // Lee numero por numero
       int i=0;
       while (archivo1 >> numero) {
             binario_codificado[i]=numero;
             i++;
       }

       // Cierra el archivo
       archivo1.close();

    //divide el numero codificado en numero de binarios que hay
    for (int i=n-1; i>=0; i--) {
        //agrega el numero binario de 8 bits a letra_binario[]
        for (int j=7; j>=0; j--) {
            letra_binario[j]=binario_codificado[posicion]-'0';//pasa el char a int y lo pasa a letra_binario[]
            posicion--;
        }
//primer metodo
        if (cero==uno || i==n-1){
            cero=0;
            uno=0;
            //contador de 1 y 0 //cambia 1 a 0 y viceversa
            for (int k=7; k>=0; k--) {
                if(letra_binario[k]==0){uno++;letra_binario[k]=1;}
                else if(letra_binario[k]==1){cero++;letra_binario[k]=0;}
            }
        }

        else if (cero>uno){
            cero=0;
            uno=0;
            //cambia 1 a 0 y viceversa
            for (int k=1; k<=7; k+=2){
                if(letra_binario[k]==0)letra_binario[k]=1;
                else if(letra_binario[k]==1)letra_binario[k]=0;
            }
            //contador de 1 y 0
            for (int k=7; k>=0; k--) {
                if(letra_binario[k]==0)cero++;
                else if(letra_binario[k]==1)uno++;
            }
        }

        else if (cero<uno){
            cero=0;
            uno=0;
            //cambia 1 a 0 y viceversa
            for (int k=2; k<=5; k+=3) {
               if(letra_binario[k]==0)letra_binario[k]=1;
               else if(letra_binario[k]==1)letra_binario[k]=0;
            }
            //contador de 1 y 0
            for (int k=7; k>=0; k--) {
                if(letra_binario[k]==0)cero++;
                else if(letra_binario[k]==1)uno++;
            }
        }
        //cambia binario por letra
        for (int k = 7; k >= 0; --k) {
            if (letra_binario[k] == 1) {
                letra |= 1 << (7 - k);
            }
        }
        //agrega las letras a un arreglo
        palabra[posicion2]=letra;
        posicion2--;
        letra=0;//reinicia la letra
    }

    //imprime la palabra
    for (int i=0; i<=n-1; i++) {

        // Verifica si el archivo se abrio correctamente
        if (!archivo2.is_open()) {
           cerr << "Error al abrir el archivo de escritura." << endl;
           return 1;
        }
        archivo2.seekp(i, ios::beg);
        // Escribe en el archivo
        archivo2 << palabra[i];

        cout<<palabra[i];
    }
    // Cierra el archivo
    archivo2.close();
    cout<<endl;
    return 0;
}
*/
