/* 
 * Laboratorio 2, Programación 3
 * Josué Fernández, 12011228
 * 
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//Prototipos
int menu();

void aritmetica(int);

double taylor(double);
double potencia(double,int);
double factorial(int);

void triangulo(int[],int,int);

int main(int argc, char** argv) {
    
//    int x;
//    cout <<"Ingrese x: ";
//    cin >> x;
//    cout << "El factorial de " << x << " es " << factorial(x);
    
    int opcion=0;
    int numero=0, limite=0;
    double valorX=0.0;
    
    while (opcion != 4) {
        switch (opcion = menu()) {
            case 1: // Teorema fundamental de la aritmética
            {
                cout << "Teorema Fundamental de la Aritmetica." << endl
                        << "Este consiste en expresar un número mayor a 1 como un producto de potencias primas." 
                        << endl << endl << "Ingrese un numero mayor a 1: ";
                cin >> numero;
                
                //Validar
                while(numero<=1){
                    cout << "    Debe ingresar un numero mayor a 1. Ingrese x: ";
                    cin >> numero;
                }
                
                cout << endl << "    La factorizacion del numero es: " << endl;
                
                aritmetica(numero);
                
                break;
            }
            case 2: // Función exponencial
            {
                cout << "Funcion exponencial." << endl
                        << "La funcion exponencial está definida como e^x ." << endl << endl
                        << "Ingrese el valor de x: ";
                cin >> valorX;
                
                cout << endl << "    El resultado del calculo es: " << taylor(valorX) << endl;
                
                break;
            }
            case 3: // Triángulo de Pascal
            {
                
                cout << "Triangulo de Pascal." << endl
                        << "Ingrese el limite de las filas a imprimir: ";
                cin >> limite;
                
                //Validar
                while(limite<=0){
                    cout << "    Debe ingresar un numero mayor a 0. Ingrese x: ";
                    cin >> limite;
                }
                
                cout << endl;
                
                int fila[] = {1};
                triangulo(fila,1,limite);
                
                break;
            }
            case 4:
            {
                cout << "    Nos vemos!" << endl;
                break;
            }
        } //Fin de switch
    } //Fin de while
    return 0;
}

/* 
 * Muestra el menú con las opciones a elegir.
 */
int menu() {
    int opcion = 0;

    do {
        cout << endl << "-----MENU-----" << endl
                << "1. Teorema Fundamental de la Aritmetica" << endl
                << "2. Serie de Taylor de la Funcion Exponencial" << endl
                << "3. Triangulo de Pascal" << endl
                << "4. Salir" << endl
                << "Ingrese la opcion que desee: ";
        cin >> opcion;
        if (opcion < 1 || opcion > 4) {
            cout << endl << "    Ha ingresado una opcion no valida. Ingrese de nuevo." << endl;
        }
    } while (opcion < 1 || opcion > 4);

    cout << endl;

    return opcion;
}

/*
 * Método que imprime en pantalla la factorización de un número mayor a 1.
 */
void aritmetica(int numero){
    int actual=numero;
    int size = 25;
    int primos[size] = {
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
    };
    int veces[size] = { };
    
    int i=0;
    for(; i<size; i++){ // Iteramos entre todos los primos
        while(actual%primos[i] == 0){//Evaluamos si el primo actual es un es un factor
            ++veces[i]; // Incrementamos las veces que ha sido usado el factor primo
            actual /= primos[i]; // Lo dividimos por su factor para seguir evaluando
        }
        if(actual==1)
            break;
    }
    
    cout << "\n    " << numero << " = ";
    
    for(int j=0;j<i; j++){
        if(veces[j])
            cout << primos[j] << "^" << veces[j] << " * ";
    }
    if(i<25 && veces[i])
            cout << primos[i] << "^" << veces[i];
    else if(actual!=1)
        cout << actual << endl << "    La factorizacion contiene primos mayores al vigesimoquinto primo.";
    cout << endl;
}

/*
 * Función que calcula el resultado de la función exponencial para un valor 
 * dado.
 */
double taylor(double valorX){
    double resultado=0.0;
    
    /*
     * 20 es el valor máximo con que pude hacer que el factorial funcionara sin  
     * resultar en una incoherencia.
     */
    for(int n=0; n<=40; n++){
        double numerador = potencia(valorX, n);
        double denominador = factorial(n);
        resultado += ( numerador / denominador );
    } 
    
    return resultado;
}

/*
 * Función recursiva que calcula un número a la potencia de un exponente y
 * retorna el resultado.
 */
double potencia(double numero,int exponente){
    if(exponente==0)
        return 1.0;
    return ((double)numero)*potencia(numero,exponente-1);
}

/*
 * Función recursiva que retorna el factorial de un entero no negativo.
 */
double factorial(int numero){
    if(numero==0)
        return 1;
    return (unsigned long long int)numero*factorial(numero-1);
}

/*
 * Método recursivo que imprime el triángulo de Pascal hasta la fila provista.
 * 
 * triangulo( {1} , 1 , 10 );
 * 
 */
void triangulo(int fila[], int size, int total){
    
    for(int i=0; i<size-1;i++)
        cout << fila[i] << ",";
    cout << fila[size-1] << endl;
    
    int nuevaFila[size+1] = {};
    
    nuevaFila[0] = 1;
    for(int i=1; i<size; i++){
        nuevaFila[i] = fila[i-1] + fila[i];
    }
    nuevaFila[size] = 1;
    
    
    if (size<total)
        triangulo(nuevaFila,size+1,total);   
}

