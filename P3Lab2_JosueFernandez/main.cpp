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
long double taylor(int);
double potencia(double,int);
unsigned long long int factorial(int);

int main(int argc, char** argv) {
    
//    int x;
//    cout <<"Ingrese x: ";
//    cin >> x;
//    cout << "El factorial de " << x << " es " << factorial(x);
    
    int opcion=0;
    int valorX=0;
    
    while (opcion != 4) {
        switch (opcion = menu()) {
            case 1: // Teorema fundamental de la aritmética
            {
                cout << "";
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

void aritmetica(int numero){
    
    
    
}

/*
 * Función que calcula el resultado de la función exponencial para un valor 
 * dado.
 */
long double taylor(int valorX){
    double resultado=0.0;
    
    for(int n=0; n<=20; n++){
        resultado += ( potencia((long double)valorX, n) / factorial(n) );
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
    return numero*potencia(numero,exponente-1);
    
}

/*
 * Función recursiva que retorna el factorial de un entero no negativo.
 */
unsigned long long int factorial(int numero){
    if(numero==0)
        return 1;
    return (unsigned long long int)numero*factorial(numero-1);
}