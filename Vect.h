#include "Fraccion.h"
#ifndef VECT_H
#define VECT_H
class Vect{
private:
    Fraccion * arr;
    int size;
    int sizeMem;

public:
    //constructores
    Vect();
    Vect(int);
    Vect(int, Fraccion *);

    //setters y getters
    int getSize();
    Fraccion getFraccion(int);
    void setFraccion(int, Fraccion);

    //operaciones
    Vect suma(Vect inaVect);
    Vect multiplicacion(Vect inaVect);
    Vect resta(Vect inaVect);
    Fraccion dot(Vect inaVect);
    Vect cross(Vect inaVect);
    Vect dot(int escalar);
    float magnitud();
    float angulo(Vect inaVect);

    //sobrecargas de operadores
    Vect operator + (const Vect);
    Vect operator - (const Vect);
    Fraccion operator * (const Vect inaVect);

    void imprimir(bool);
};

#endif //VECT_H