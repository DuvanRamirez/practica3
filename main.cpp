
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>


using namespace std;

int Menu1(int);
int Menu2(int);
int Menu3(int);
int Menu4(int);
int registro_usuario(string , string , string);

int main()
{


    int opcion1=3;
    //Menu 1
    opcion1= Menu1(opcion1);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Usuario administrador
    if(opcion1==1){
        int opcion2=2;
        //Menu 2
        opcion2= Menu2(opcion2);
        if(opcion2==1){
            string cedula;
            string clave;
            char usuarioadministrador[14];
            bool clavesi=false;
            //Menu 3
            while(clavesi==false){
                system("cls");//limpiar la terminal
                cout<<"Ingrese Cedula y clave"<<endl;
                cout<<"Cedula: ";
                cin>>cedula;
                cout<<"Clave : ";
                cin>>clave;
                cout<<"Entrar 1     Salir 0 "<<endl;
                int n;
                cin>>n;
                if(n==0)exit(0);
//codificacion de clave
//--------------------------------------------------------------------------------------------------------
                // Abrir el archivo para lectura
                ifstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/usuarioadministrador.txt");

                // Verifica si el archivo se abrio correctamente
                if (!archivo.is_open()) {
                   cout << "Error al abrir el archivo" << endl;
                   return 1;
                }
                //cuenta los caracteres que hay en el archivo
                archivo.seekg(0, ios::end);//pasa el puntero al final del archivo
                int numero_caracteres = archivo.tellg();
                archivo.seekg(0, ios::beg);//vuelve el puntero al inicio del archivo

                char caracteres[numero_caracteres];//para almacenar los caracteres del texto
                //int caracteres_binario[8*numero_caracteres];//para almacenar los bunarios de cada caracter
                //int caracteres_codificados[8*numero_caracteres];

                // Lee letra por letra y la almacena
                char letra;
                int i=0;
                while (archivo >> letra) {
                     caracteres[i]=letra;
                     i++;
                }

                // Cierra el archivo
                archivo.close();
//------------------------------------------------------------------------------------------------------------------
                //añade cedula a usuarioadministrador
                for (int i = 0; i<10; i++) {
                    usuarioadministrador[i]=cedula[i];
                }
                //añade clave a usuarioadministrador[i]
                for (int j = 0; j<4; j++) {
                    usuarioadministrador[j+10]=clave[j];
                }
                int contador=0;//cuenta las veces que es igual los caracteres de la clave
                for (int k = 0; k<14; k++) {
                    if (usuarioadministrador[k]==caracteres[k])contador++;
                }
                //si todos los caracteres son iguales entra el usuario, si no se repite
                if(contador==14)clavesi=true;
                else {cout<<"Clave o Usuario Incorrecto"<<endl;sleep(2);}

            }
            system("cls");
            cout<<"Bienvenido"<<endl;
            sleep(2);
            int opcion3=2;
            string cedulaU;
            string claveU;
            string saldoU;
            //Menu 4
            while(opcion3){
                opcion3=2;
                opcion3=Menu3(opcion3);
                if(opcion3==1){
                    system("cls");//limpiar la terminal
                    cout<<"Ingrese los datos porfavor"<<endl;
                    cout<<endl;
                    cout<<"Cedula del Usuario: ";
                    cin>>cedulaU;
                    cout<<"Clave del Usuario: ";
                    cin>>claveU;
                    cout<<"Saldo del Usuario: ";
                    cin>>saldoU;

                    //Registro de usuarios
                    registro_usuario(cedulaU,claveU,saldoU);
                    cout<<endl;
                    cout<<"Registro Completado"<<endl;
                    sleep(2);
                }
            }
        }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Usuario
    else if(opcion1==2){
        int opcion2=2;
        string saldoU;
        int numero_caracteres;
        //Menu 2
        opcion2= Menu2(opcion2);
        if(opcion2==1){
            string cedula;
            string clave;
            char usuario[14];
            bool clavesi=false;
            //Menu 3
            while(clavesi==false){
                system("cls");//limpiar la terminal
                cout<<"Ingrese Cedula y clave"<<endl;
                cout<<endl;
                cout<<"Cedula: ";
                cin>>cedula;
                cout<<"Clave : ";
                cin>>clave;
                cout<<"Entrar 1     Salir 0 "<<endl;
                int n;
                cin>>n;
                if(n==0)exit(0);
//codificacion de clave
//--------------------------------------------------------------------------------------------------------
                // Abrir el archivo para lectura
                ifstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/usuarios.txt");

                // Verifica si el archivo se abrio correctamente
                if (!archivo.is_open()) {
                   cout << "Error al abrir el archivo" << endl;
                   return 1;
                }
                //cuenta los caracteres que hay en el archivo
                archivo.seekg(0, ios::end);//pasa el puntero al final del archivo
                numero_caracteres = archivo.tellg();
                archivo.seekg(0, ios::beg);//vuelve el puntero al inicio del archivo
                char caracteres[numero_caracteres];//para almacenar los caracteres del texto
                //int caracteres_binario[8*numero_caracteres];//para almacenar los bunarios de cada caracter
                //int caracteres_codificados[8*numero_caracteres];

                // Lee letra por letra y la almacena
                char letra;
                int i=0;
                while (archivo >> letra) {
                     caracteres[i]=letra;
                     i++;
                }

                // Cierra el archivo
                archivo.close();
//------------------------------------------------------------------------------------------------------------------
                //añade el saldo a saldoU
                for (int i=0; i<(numero_caracteres-14); i++) {
                    saldoU[i]=caracteres[i+14];
                }
                //añade cedula a usuario
                for (int i = 0; i<10; i++) {
                    usuario[i]=cedula[i];
                }
                //añade clave a usuario
                for (int j = 0; j<4; j++) {
                    usuario[j+10]=clave[j];
                }
                int contador=0;//cuenta las veces que es igual los caracteres de la clave
                for (int k = 0; k<14; k++) {
                    if (usuario[k]==caracteres[k])contador++;
                }
                //si todos los caracteres son iguales entra el usuario, si no se repite
                if(contador==14)clavesi=true;
                else {cout<<"Clave o Usuario Incorrecto"<<endl;sleep(2);}

            }
            system("cls");
            cout<<"Bienvenido"<<endl;
            sleep(2);
            //pasa saldo que esta string a numero
            int saldo_en_numero=stoi(saldoU);
            //Menu4
            int opcion4=3;
            while(opcion4){
                opcion4=3;
                opcion4=Menu4(opcion4);
                system("cls");
                if(opcion4==1){
                    if(saldo_en_numero>=1000){
                        cout<<"Saldo dispponible: $"<<saldo_en_numero<<" COP."<<endl;
                        saldo_en_numero-=1000;
                        sleep(2);
                    }
                    else {cout<<"Saldo Insuficiente"<<endl;sleep(2);}
                }
                else if(opcion4==2){
                    string retiro;
                    cout<<"Cuanto desea retirar: ";
                    cin>>retiro;
                    system("cls");
                    int saldo_a_retirar=stoi(retiro);
                    if(saldo_en_numero>=saldo_a_retirar){
                        cout<<"Retirando Saldo..."<<endl;
                        saldo_en_numero-=(1000+saldo_a_retirar);
                        sleep(2);
                    }
                    else {cout<<"Saldo Insuficiente"<<endl;sleep(2);}
                }
                fstream archivo("C:/Users/duvan/Documents/proyectos c++/practica3/usuarios.txt", ios::in | ios::out);
                // Verifica si el archivo se abrio correctamente
                if (!archivo.is_open()) {
                   cout << "Error al abrir el archivo" << endl;
                   return 1;
                }
                //borrar cantidad de dinero y pone el nuevo saldo
                string saldo_modificado=to_string(saldo_en_numero);
                int tamaño_numero=saldo_modificado.length();
                int inicio = 14;
                int fin = numero_caracteres;
                archivo.seekg(inicio, ios::beg);
                archivo.seekp(inicio, ios::beg);

                for (int i=inicio; i<fin; i++) {
                    archivo.put(' ');
                }
                archivo.seekg(inicio, ios::beg);
                archivo.seekp(inicio, ios::beg);

                for (int i=inicio; i<tamaño_numero; i++) {
                    // Escribe en el archivo
                    archivo.seekp(i, ios::beg);
                    archivo << saldo_modificado[i];
                }

                archivo.close();

            }
        }
    }
    return 0;
}

int Menu1(int opcion1){
    while(opcion1>2){
        system("cls");//limpiar la terminal
        cout<<"Menu principal:"<<endl;
        cout<<endl;
        cout<<"1. Usuario Administrador"<<endl;
        cout<<"2. Usuario"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion1;
        if (opcion1==3)exit(0);
    }
    return opcion1;
}
int Menu2(int opcion2){
    while(opcion2>1){
        system("cls");//limpiar la terminal
        cout<<endl;
        cout<<"1. Ingresar"<<endl;
        cout<<"2. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion2;
        if(opcion2==2)exit(0);
    }
    return opcion2;
}
int Menu3(int opcion3){
    while(opcion3>1){
        system("cls");//limpiar la terminal
        cout<<endl;
        cout<<"1. Registro de Usuario"<<endl;
        cout<<"2. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion3;
        if(opcion3==2)exit(0);
    }
    return opcion3;
}
int Menu4(int opcion4){
    while(opcion4>2){
        system("cls");//limpiar la terminal
        cout<<"Cada retiro de dinero o consulta"<<endl;
        cout<<"de saldo tiene un costo de $1000 COP. "<<endl;
        cout<<endl;
        cout<<"1. Consultar Saldo"<<endl;
        cout<<"2. Retirar Dinero"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion4;
        if(opcion4==3)exit(0);
    }
    return opcion4;
}
int registro_usuario(string cedulaU, string claveU, string saldoU){

    // Abre el archivo de escritura
    ofstream archivo2("C:/Users/duvan/Documents/proyectos c++/practica3/usuarios.txt");

    // Verifica si el archivo se abrio correctamente
    if (!archivo2.is_open()) {
       cerr << "Error al abrir el archivo de escritura." << endl;
       return 1;
    }
    /*string linea;
    bool libre=false;
    while(libre==false){
        //cuenta los caracteres que hay en la linea
        getline(archivo2, linea);
        cout<<linea<<endl;
        int numero_caracteres = linea.length();
        cout<<numero_caracteres<<endl;
        if(numero_caracteres>0) {archivo2.write("\n", 1);cout<<"endl";}
        if (numero_caracteres==0)libre=true;
    }
    */
    //copia los datos en el archivo usuarios
    for(int i=0; i<10; i++) {
        // Escribe en el archivo
        archivo2.seekp(i);
        archivo2 << cedulaU[i];
    }
    for(int j=10; j<14; j++) {
        // Escribe en el archivo
        archivo2.seekp(j);
        archivo2 << claveU[j-10];
    }
    int tamañosaldo;
    tamañosaldo=saldoU.length();
    for(int k=14; k<tamañosaldo+14; k++) {
        // Escribe en el archivo
        archivo2.seekp(k);
        archivo2 << saldoU[k-14];
    }
    // Cierra el archivo
    archivo2.close();
}
