#include <iostream>
#include <windows.h>
#include <limits>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

//PRACTICA 1
void practica_1(){
    system("cls");
    
    int numero;

    cout << "Mostreo de divisores" << endl;
    cout << "____________________" << endl;

    FILTRO: cout << "Seleccione su numero: " << endl;
    cin >> numero;
    
    if(!cin.good()) {
        cout << "Dato no valido" << endl;
        system("pause");
        
        //limpiar banderas de error
        cin.clear();
        // Elimina los caracteres del buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        goto FILTRO;
    }
    system("cls");

    cout << "Estos son los divisores" << endl;
    for( int i = 1; i <= numero; i++)
    {
        if(numero % i == 0)
        {
            cout << i << endl;
        }
    }

    system("pause");

}


//PRACTICA 2
void practica_2(){
    system("cls");

    unsigned int ancho, largo;
    cout << "Creacion de triangulo" << endl;
    cout << "_____________________" << endl;
 
    FILTRO1: cout << "Ancho: " << endl;
    
    cin >> ancho;
    if(!cin.good()) {
        cout << "Dato no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        goto FILTRO1;
    }

    FILTRO2: cout << "Largo: " << endl;
    cin >> largo;
    if(!cin.good()) {
        cout << "Dato no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        goto FILTRO2;
    }

    for (int i = 0; i <= ancho; i++)
    {
        for (int j = 0; j <= largo; j++)
        {
            if(i == 0){
                (j == largo) ? cout << endl : cout << "*";
            }
            else if(i == ancho){
                cout << "*";
            }
            else{
                if(j == 0){
                    cout << "*";
                }
                else if (j == largo){
                    cout << "*"<< endl;
                }
                else{
                    cout << " ";
                }
            }
        }
    }
    cout << endl;
    system("pause");
}



//PRACTICA 3
void practica_3(){
    system("cls");
    cout << "Los 10 Numeros" << endl;
    cout << "______________" << endl;

    int numero1, numero2 = 0, i=1;
    int array[10];

    while(i <= 10){
        FILTRO: cout << "Seleccione el numero " << i << " :" << endl;
            
        cin >> numero1;
        if(!cin.good()) {
            cout << "Numero no valido" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto FILTRO;
        }
        numero2 += numero1;
        array[i-1] = numero1;
        cout << "Cantidad actual: " << numero2 << endl;
        cout << "================" << endl;

        i++;
    }


    int sumArray = 0;
    for(int j = 1; j <= 10; j++)
    {
        sumArray += array[j-1];
    }

    cout << "Cantidad total en dos variables: " << numero2 << endl;
    cout << "Cantidad total en el array: " << sumArray << endl;
    system("pause");
}


//PRACTICA 4
void practica_4(){
    system("cls");
    cout << "Arreglo y busqueda" << endl;
    cout << "__________________" << endl;

    int numero;
    int array[10];
    char letter;
    bool finished = false;

    for(int i = 1; i <= 10 ; i++)
    {
        FILTRO: cout << "Introduce el numero " << i << " :" << endl;
        cin >> numero;
         if(!cin.good() || numero == 0) {
            cout << "Numero no valido" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto FILTRO;
        }
        array[i-1] = numero;
    }

    do{
        FILTRO2: cout << "Ingrese el numero que desea buscar en el arreglo"<<endl;
        cin >> numero;
         if(!cin.good() || numero == 0) {
            cout << "Numero no valido" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto FILTRO2;
        }

        for(int j = 0; j < 10; j++)
        {
            if(array[j] == numero)
            {
                cout << "Se encontro el numero " << array[j] << " en la posicion " << j+1 << endl;
            }
        }
        cout << "Buscar otro numero? (S/N)" << endl;
        cin >> letter;
        (letter == 'N' || letter == 'n') ? finished = true : finished = false;
        
    }while(!finished);
}



//PRACTICA 5
int * burbuja(int arr[])
{
    int pivote, iterador = 0, movimientos = 0;
    bool ordenado = false;

    while(!ordenado)
    {
        for(int i = 0; i <= 9; i++)
        {
            if(i == 9)
            {
             cout << arr[i] << endl;

            }
            else{
                cout << arr[i] << " ,";
            }
            Sleep(100);
        }

        if(iterador < 9)
        {
            
            if(arr[iterador] > arr[iterador+1])
            {
                pivote = arr[iterador+1];
                arr[iterador+1] = arr[iterador];
                arr[iterador] = pivote;
                movimientos++;
            }
                iterador++;
        }
        else{
            if(movimientos != 0)
            {
           
                
                iterador = 0;
                movimientos = 0;
            }
            else{
                 ordenado = true;
            }
        }
        
    }

    return arr;
}

void practica_5(){
    system("cls");
    cout << "Arreglo y burbuja" << endl;
    cout << "_________________" << endl;

    int numero, trigger, iterador = 0;
    int array[10];
    
    for(int i = 1; i <= 10 ; i++)
    {
        FILTRO: cout << "Introduce el numero " << i << " :" << endl;
        cin >> numero;
         if(!cin.good() || numero == 0) {
            cout << "Numero no valido" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto FILTRO;
        }
        array[i-1] = numero;
    }

    do{

    cout << "+=========================+" << endl;
    cout << "| Presione 1 para ordenar |" << endl;
    cout << "+=========================+" << endl;
    cin >> trigger;
        if(!cin.good()){
            cout << "Numero no valido" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(trigger != 1);

    auto result = burbuja(array);
    cout << endl << "================= " << endl;
    while(iterador <= 9){
        cout << result[iterador] << " ,";
        Sleep(300);
        iterador++;
    }
    cout << endl;

    system("pause");
}


//PRACTICA 6
void practica_6(){
    float promedio;
    int opcion, addNumero, index = 0;
    int numeros[1000];
    numeros[0] = 0;
    do{
        cout << "1.- Agregar numeros" << endl;
        cout << "2.- Mostrar numeros" << endl;
        cout << "3.- Mostrar media y desviación tipica" << endl;
        cout << "4.- Salir"<<endl;
        cout << "Selecciona una opcion"<<endl;
        cin >> opcion;
        if(!cin.good()){
            cout << "Opcion no valida" << endl;
            system("pause");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion)
        {
           //ADD
            case 1:
            {
                system("cls");
                FILTRO: cout << "Nuevo numero:" << endl;
                cin >> addNumero;
                if(!cin.good()){
                    cout << "Opcion no valida" << endl;
                    system("pause");
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    goto FILTRO;
                }
                numeros[index] = addNumero;
                index++;
                system("cls");
                cout << "Numero agregado." << endl;
                system("pause");
            } break;
            
            //MOSTRAR
            case 2:{
                system("cls");
                for(int iterador = 0; iterador <= index-1; iterador++)
                {
                    if(iterador % 10 == 0 && iterador != 0){

                        cout << numeros[iterador] << endl;
                    }
                    else{
                        cout << numeros[iterador] << " | ";
                    }
                }
                system("pause");
            }break;

            case 3:{
                int sumatoria = 0, sumatoriaVarianza = 0;
                promedio = 0;
                for(int iterador = 0; iterador <= index-1; iterador++)
                {
                    sumatoria += numeros[iterador];
                }
                promedio = sumatoria / index-1;
                system("cls");
                cout << "Promedio: " << promedio << endl;
                
                for(int iterador = 0; iterador <= index-1; iterador++)
                {
                    int numtemporal = numeros[iterador];
                    int frecuencia = 0;
                    for (int iterador2 = 0; iterador2 <= index-1; iterador2++)
                    {
                        if(numeros[iterador2] == numtemporal) frecuencia++;
                    }
                    int pivote = pow((numtemporal - promedio), 2) * frecuencia;

                    sumatoriaVarianza += pivote;
                }

                sumatoriaVarianza = sumatoriaVarianza/index-1;

                int desviacionTipica = sqrt(sumatoriaVarianza);
                cout << "Desviacion standard: " << desviacionTipica << endl;                
                system("pause");

                
            }break;
            default:
                break;
        }
    }while(opcion != 4);
}

//PRACTICA 7
void piramide(int num)
{  
    int crescendo;
    ofstream triangulo ("triangulo.txt", std::ofstream::out);
    for(int iterador = num-1; iterador >= 0; iterador--)
    {
        crescendo = 0;
        while(crescendo <= iterador)
        {
            triangulo << "$";
            crescendo++;
        }
        
        triangulo << "\n";
    }
    triangulo.close();
    cout << "Se ha realizado el archivo con exito" << endl;
    system("pause");

}
void practica_7(){
    FILTRO: system("cls");
    cout << "Triangulo"  << endl;
    cout << "_____________" << endl;
    int numero;
    cout << "Ingresa el numero de inicio del triangulo: " << endl;
    cin >> numero;
    if(!cin.good()){
        cout << "Opcion incorrecta" << endl;
        system("pause");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO;
    }

    piramide(numero);

}

//PRACTICA 8
void practica_8(){
  FILTRO: system("cls");
    cout << "Piramide"  << endl;
    cout << "_____________" << endl;
    int numero, crescendo;
    cout << "Ingresa el numero de niveles: " << endl;
    cin >> numero;
    if(!cin.good()){
        cout << "Numero no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO;
    }

    ofstream piramide ("piramide.txt", ofstream::out);
    for(int ascendente = 0; ascendente <= numero-1; ascendente++)
    {
        crescendo = 0;
        while(crescendo <= ascendente)
        {
            piramide << "$";
            crescendo++;
        }
        
        piramide << "\n";
    }
    for(int descendente = numero-1; descendente >= 0; descendente--)
    {
        crescendo = 0;
        while(crescendo <= descendente)
        {
            piramide << "$";
            crescendo++;
        }
        
        piramide << "\n";
    }

    piramide.close();
    cout << "Se ha realizado el archivo con exito" << endl;
    system("pause");
}

int * numgran(int arr[])
{
    int maximo;
    for(int index = 0; index <= 9; index++)
    {
        if(index != 9)
        {
            (arr[index] > arr[index+1]) ? maximo = arr[index] : maximo = arr[index+1];
        }
    }
    cout << "El numero mas grande de los ficheros cargados es: "<< maximo << endl;
    system("pause");

    return 0;
}
void practica_9(){
    system("cls");
    cout << "Leer archivo"  << endl;
    cout << "_____________" << endl;
    ifstream numerosEnTexto;
    numerosEnTexto.open("misnum.txt");
    char output[100];
    int array[10], index = 0;
    if (numerosEnTexto.is_open()) {
        while (!numerosEnTexto.eof()) {

            numerosEnTexto >> output;
            array[index] = atoi(output);
            cout << output << endl;
            Sleep(100);
            index++;

        }
    }
    numerosEnTexto.close();
    numgran(array);
}

//PRACTICA 10
void practica_10(){
    system("cls");
    cout << "Billetes"  << endl;
    cout << "_____________" << endl;
    int billetes[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    // int precio = (rand() % 10000) + 1;
    //int pago;
    // FILTRO: cout << "Ingrese su cantidad: " << endl;
    // cin >> pago;
    // if(!cin.good()){
    //     cout << "Numero no valido" << endl;
    //     system("pause");

    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     goto FILTRO;
    // }


    //COMENTAR ESTO Y DESCOMENTAR EL CONTENIDO DE ARRIBA
    //PARA VOLVER AL SISTEMA DINAMICO
    int precio = 44;
    int pago = 100;



    int cambio = pago - precio;
    int cambioStandard = cambio;
    int contadorBilletes = 0; //numeros de array
    int cantidadContada = 0;    //diferencia en el proceso
    int billetesPago[contadorBilletes]; //arreglo con los billetes
    if(cambio > 0)
    {
        while(cantidadContada <= cambioStandard )
        {
           for(int index = 0; index <= 8; index++)
           {
               if(billetes[index] <= cambio)
               {
                   //se asigna el billete en el array
                   billetesPago[contadorBilletes] = billetes[index];
                   contadorBilletes++;
                   cantidadContada += billetesPago[contadorBilletes];

                   cambio -= billetes[index];
               }
           } 
        }


    }
    else{
        cout << "No hay cambio" << endl;
    }
    cout << "Precio: " << precio << endl;
    cout << "Pagado: " << pago << endl;
    cout << "Su cambio es de: " << cambioStandard << "  :  ";

    for(int index = 0; index < contadorBilletes; index++)
    {
        cout << billetesPago[index] << " , ";
        Sleep(200);
    }
    cout << endl;
    system("pause");
}


//PRACTICA 11
int SumCif( int numero )
{
    int sumatoria = 0;
    while(numero)
        {
            sumatoria += numero % 10;
            numero /= 10;
        }

    return sumatoria;
}

int NumCif ( int numero )
{
    int cifras;
     while(numero)
    {
        cifras++;
        numero /= 10;
    }

    return cifras;
}

void practica_11(){
    FILTRO:system("cls");
    cout << "Segmentacion de numero"  << endl;
    cout << "_______________________" << endl;
    int numero, cifras, sumatoria = 0;
    cout << "Ingrese un numero de entre 3-5 caracteres de preferencia" << endl;
    cin >> numero;
    if(!cin.good()){
        cout << "Numero no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO;
    }
    
    cifras = NumCif(numero);
    sumatoria = SumCif(numero);

    cout << "Numero: " << numero << endl;
    cout << "Cifras: " << cifras << endl;
    cout << "Sumatoria: " << sumatoria << endl;

    system("pause");
}

//PRACTICA 12
int MCD(int numero1, int numero2)
{
    int mcd;
    int menor = min(numero1, numero2);
    int mayor = max(numero1, numero2);
    do{
        mcd = menor;
        menor = mayor % menor;
        mayor = mcd;
    }while(menor != 0);

    return mcd;
}

int MCM(int numero1, int numero2)
{
    int mcm = 0;
    int menor = min(numero1, numero2);
    int mayor = max(numero1, numero2);
    
    mcm = (mayor/MCD(mayor, menor))*menor;
    
    return mcm;
}

void practica_12(){
    system("cls");
    int numero, numero2;
    int mcm, mcd;
    FILTRO: cout << "Ingrese el primer numero: " << endl;
    cin >> numero;
    if(!cin.good()){
        cout << "Numero no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO;
    }
    FILTRO2: cout << "Ingrese el segundo numero: " << endl;
    cin >> numero2;
    if(!cin.good()){
        cout << "Numero no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO2;
    }

    mcm = MCM(numero, numero2);
    mcd = MCD(numero, numero2);

    ofstream resultado("resultado.txt", ofstream::out);

    resultado << "El maximo comun multiplo de " << numero << " Y " << numero2 << " es " << mcm << endl;
    resultado << "El maximo comun divisor de " << numero << " Y " << numero2 << " es " << mcd << endl;
    
    resultado.close();
    cout << "Los resultados estan en resultado.txt" << endl;
    system("pause");
}

//PRACTICA 13
void practica_13(){
    system("cls");
    int numero;
    int n1 = 0, n2 = 1, n3;
    FILTRO: cout << "Ingrese la cantidad de numero a ver de Fibonacci: " << endl;
    cin >> numero;
    if(!cin.good()){
        cout << "Numero no valido" << endl;
        system("pause");

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto FILTRO;
    }

    cout << "Con FOR: " << endl;

    for(int i = 0; i <= numero; i++)
    {
        cout << n1 << "   ";
        n3 = n1;
        n1 = n2;
        n2 = n3 + n2;

        Sleep(100);
    }

    cout << endl;
    cout << "Con WHILE: " << endl;
    int i = 0;
    n1 = 0;
    n2 = 1;
    while(i <= numero )
    {
        cout << n1 << "   ";
        n3 = n1;
        n1 = n2;
        n2 = n3 + n2;

        i++;
        Sleep(100);
    }

    cout << endl;
    
    system("pause");
}

int main(){

    HWND CurrentWin;
    CurrentWin = GetForegroundWindow();
    HANDLE consol;
    consol = GetStdHandle(STD_OUTPUT_HANDLE);

    int opcion;
    do{
        SetConsoleTextAttribute(consol,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
        system("cls");
        cout << "1.- Practica 1" << endl;
        cout << "2.- Practica 2" << endl;
        cout << "3.- Practica 3" << endl;
        cout << "4.- Practica 4" << endl;
        cout << "5.- Practica 5" << endl;
        cout << "6.- Practica 6" << endl;
        cout << "7.- Practica 7" << endl;
        cout << "8.- Practica 8" << endl;
        cout << "9.- Practica 9" << endl;
        cout << "10.- Practica 10" << endl;
        cout << "11.- Practica 11" << endl;
        cout << "12.- Practica 12" << endl;
        cout << "13.- Practica 13" << endl;
        cout << "Selecciona una opcion: " << endl;
        
        SetConsoleTextAttribute(consol,FOREGROUND_INTENSITY|FOREGROUND_GREEN);
        
        cin >> opcion;
        if(!cin.good()) {
            cout << "Opcion incorrecta" << endl;
            system("pause");

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }        
        else{

            switch (opcion)
            {
            case 1:
                practica_1();
                break;
            case 2:
                practica_2();
                break;
            case 3:
                practica_3();
                break;
            case 4:
                practica_4();
                break;

            case 5:
                practica_5();
                break;
            case 6:
                practica_6();
                break;
            case 7:
                practica_7();
                break;
            case 8:
                practica_8();
                break;
            case 9:
                practica_9();
                break;
            case 10:
                practica_10();
                break;
            case 11:
                practica_11();
                break;
            case 12:
                practica_12();
                break;
            case 13:
                practica_13();
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
            }
        }

    }while(opcion != 14);

    return 0;
}