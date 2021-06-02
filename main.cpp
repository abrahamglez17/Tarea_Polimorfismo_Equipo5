//#include "Fraccion.h"
#include "Vect.h"
#include <iostream>
using namespace std;

int main(){
    //FALTA PONER VECTORES DE 4 DIMENSIONES
    Fraccion f1 (30000,75000); // Fraccion 1: 2/5
    Fraccion f2 (55,12); //  Fraccion 2: 1/2
    Fraccion f3 (3,12); // Fraccion 3: -1/4 (negativo/positivo)
    Fraccion f4 (5,17); // Fraccion 4: -1/4 (positivo/negativo)
    Fraccion f5 (-8,-26); // Fraccion 5: 1/4 (negativo/negativo)
    Fraccion f6; // Fraccion 6: 0/1 (valor por defecto)

    cout << "Arreglo 1 (af1): ";
    Vect af1(3);
    af1.imprimir(false);
    cout << "Arreglo 2 (af2): ";
    Vect af2(4);
    af2.imprimir(false);
    Fraccion farray[4] = {f1,f2,f3, f4};
    Fraccion farray2[4] = {f1,f2,f1, f5};
    Fraccion farray3[3] = {f1,f2,f3};
    Fraccion farray4[3] = {f2,f4,f5};
    cout << "Arreglo 3 (af3): ";
    Vect af3(4,farray);
    af3.imprimir(false);
    cout << "Arreglo 4 (af4): ";
    Vect af4(4,farray2);
    af4.imprimir(false);
    cout << "Arreglo 5 (af5): ";
    Vect af5(3,farray3);
    af5.imprimir(false);
    cout << "Arreglo 6 (af6): ";
    Vect af6(3,farray4);
    af6.imprimir(false);

    cout << endl << "**************Suma y resta de arreglos:" << endl;
    //SUMA
    cout << endl << "af2 = af3 + af4:" << endl;
    af2 = af3.suma(af4);
    af2.imprimir(false);
    cout << endl << "SOBRECARGA af2 = af3 + af4:" << endl;
    af2 = af3 + af4;
    af2.imprimir(false);

    //RESTA
    cout << endl << "af2 = af3 - af4:" << endl;
    af2 = af3.resta(af4);
    af2.imprimir(false);
    cout << endl << "SOBRECARGA af2 = af3 - af4:" << endl;
    af2 = af3 - af4;
    af2.imprimir(false);

    //PRODUCTO PUNTO
    cout << endl << "**************Producto punto de arreglos: " << endl;
    cout << "dot = af3 * af4:" << endl;
    Fraccion dot;
    dot= af3.dot(af4);
    dot.imprimir();
    cout << endl << "SOBRECARGA dot = af3 * af4:" << endl;
    dot = af3 * af4;
    dot.imprimir();

    //PRODUCTO CRUZ
    cout << endl << "**************Producto cruz de arreglos: " << endl;
    cout << "af2 = af3 X af4:" << endl;;
    af2= af3.cross(af4);
    af2.imprimir(false);
    cout << endl << "**************Producto cruz de arreglos (3 dimensiones): " << endl;
    cout << "af1 = af5 X af6:" << endl;;
    af1= af5.cross(af6);
    af1.imprimir(false);

    //MAGNITUD
    cout << endl << "**************Magnitud de vectores: " << endl;
    float mag1;
    mag1 = af3.magnitud();
    cout << endl << "Magnitud (af3): " << mag1;
    float mag2;
    mag2 = af4.magnitud();
    cout << endl << "Magnitud (af4): " << mag2;

    //ANGULO entre vectores
    cout << endl << "**************Angulo entre dos vectores: " << endl;
    float ang1;
    ang1 = af1.angulo(af2);
    cout << endl << "Angulo af1 - af2: " << ang1;

    float ang2;
    ang2 = af5.angulo(af6);
    cout << endl << "Angulo af5 - af6: " << ang2;

    //ESCALAMIENTO
    cout << endl << "**************ESCALAMIENTO de: " << endl;
    int escalar= 5;
    af2= af3.dot(escalar);
    af2.imprimir(false);
}