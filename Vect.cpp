#include "Vect.h"
#include <iostream>
#include <math.h>
using namespace std;

//Constructor sin argumentos
Vect::Vect(){
    arr = new Fraccion[1];
    size = 1;
    sizeMem = 1;
}

//Constructor con tamaño especifico
Vect::Vect(int s){
    size = s;
    arr = new Fraccion[s];
    sizeMem = s;
}

//Constructor con arreglo especifico
Vect::Vect(int s, Fraccion * arrf){
    arr = arrf;
    size = s;
    sizeMem = s;
}

//Obtener tamaño del arreglo
int Vect::getSize(){
    return size;
}

//Obtener Fraccion por indice
Fraccion Vect::getFraccion(int i){
    return arr[i];
}

//Cambiar una fraccion por indice
void Vect::setFraccion(int i, Fraccion f){
    arr[i] = f;
}

//Suma de fracciones (no modifica el objeto actual)
Vect Vect::suma(Vect inaVect){
    // Si los tamaños de los arreglos coinciden
    if(size == inaVect.getSize()){
        Vect newVect(size);
        for (int i=0; i<size; i++){
            //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
            newVect.setFraccion(i, arr[i].suma(inaVect.getFraccion(i)));
        }
        return newVect;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}


//SOBRECARGA de suma
Vect Vect::operator + (const Vect inaVect){
    return suma(inaVect);
}

//Multiplicacion de fracciones (no modifica el objeto actual)
Vect Vect::multiplicacion(Vect inVect){
    // Si los tamaños de los arreglos coinciden
    if(size == inVect.getSize()){
        Vect newVect(size);
        for (int i=0; i<size; i++){
            newVect.setFraccion(i, arr[i].multiplicacion(inVect.getFraccion(i)));
        }
        return newVect;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

//RESTA de dos vectores
Vect Vect::resta(Vect inaVect){
    if(size == inaVect.getSize()){
        Vect newVect(size);
        for (int i=0; i<size; i++){
            //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
            newVect.setFraccion(i, arr[i].resta(inaVect.getFraccion(i)));
        }
        return newVect;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

//SOBRECARGA de resta
Vect Vect::operator - (const Vect inaVect){
    return resta(inaVect);
}

//PRODUCTO PUNTO entre dos vectores

Fraccion Vect::dot(Vect inaVect){
    //checamos si los vectores tienen las mismas dimensiones
    if(size == inaVect.getSize()){
        Fraccion producto;
        Vect newVect(size);
        for (int i=0; i<size; i++){
            newVect.setFraccion(i, arr[i].multiplicacion(inaVect.getFraccion(i)));
            producto = producto.suma(newVect.getFraccion(i));
        }
        return producto;
    } else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Fraccion();
    }
}

//SOBRECARGA de producto punto
Fraccion Vect::operator * (const Vect inaVect){
    return this-> dot(inaVect);
}

//PRODUCTO CRUZ entre dos vectores

Vect Vect::cross(Vect inaVect){
    //checamos si los vectores tienen las mismas dimensiones
    if(size == inaVect.getSize()){
        if(size==3){
            //producto punto para dos vectores de tres dimensiones
            Vect newVect(size);
            newVect.arr[0]= arr[1].multiplicacion(inaVect.getFraccion(2));
            newVect.arr[0]= newVect.arr[0].resta(arr[2].multiplicacion(inaVect.getFraccion(1)));
            newVect.arr[1]= arr[2].multiplicacion(inaVect.getFraccion(0));
            newVect.arr[1]= newVect.arr[1].resta(arr[0].multiplicacion(inaVect.getFraccion(2)));
            newVect.arr[2]= arr[0].multiplicacion(inaVect.getFraccion(1));
            newVect.arr[2]= newVect.arr[2].resta(arr[1].multiplicacion(inaVect.getFraccion(0)));
            return newVect;
        } else{
            cout << "Los vectores no tienen una dimension válida" << endl;
            return Vect();
        }
    } else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vect();
    }
}

//IMPRIMIR los elementos de un vector
void Vect::imprimir(bool showSize){
    if(showSize)
        cout << "size: " << size << ", sizeMem: " << sizeMem << " --- ";
    cout << "[";
    int i;
    for (i=0; i<size; i++){
        cout << arr[i].getNumerador() << "/" << arr[i].getDenominador();
        if( i < size-1)
            cout << ", ";
    }
    cout << "]" << endl;
}

//obtener la MAGNITUD
float Vect::magnitud() {
    float mag;
    float magF= 0;
    for(int i=0; i < size; i++){
        mag = (float)arr[i].getNumerador()/arr[i].getDenominador();
        mag = mag*mag;
        magF = magF + mag;
    }
    magF = sqrt(magF);
    return magF;
}

float Vect::angulo(Vect inaVect) {
    float ang;
    Fraccion prodPunto;
    if(size == inaVect.getSize()){
        //Producto punto A y B
        Fraccion producto;
        Vect newVect(size);
        for (int i=0; i<size; i++){
            newVect.setFraccion(i, arr[i].multiplicacion(inaVect.getFraccion(i)));
            producto = producto.suma(newVect.getFraccion(i));
        }

        float mag, magF;
        //MAGNITUD del vector local
        for(int i=0; i < size; i++){
            mag = (float)arr[i].getNumerador()/arr[i].getDenominador();
            mag = mag*mag;
            magF = magF + mag;
        }
        magF = sqrt(magF);

        float mag2, magF2;
        //MAGNITUD del vector de input
        for(int i=0; i < size; i++){
            mag2 = (float)inaVect.arr[i].getNumerador()/inaVect.arr[i].getDenominador();
            mag2 = mag2*mag2;
            magF2 = magF2 + mag2;
        }
        magF2 = sqrt(magF2);

        float productof;
        productof = (float) producto.getNumerador()/producto.getDenominador();

        ang= productof/(magF*magF2);
        ang= acos(ang);
        ang= ang*180/3.14159265;
        return ang;
    } else{
        cout << "Los vectores no tienen el mismo numero de elementos" << endl;
        return 0;
    }
}

//ESCALAMIENTO
Vect Vect::dot(int escalar){
    Vect newVect(size);
    for(int i=0; i<size; i++){
        newVect.arr[i]= arr[i];
        newVect.arr[i].setNumerador(escalar*arr[i].getNumerador());
        //newVect.arr[i].reduccion(); //reducir fracciones?????
    }
    return newVect;
}