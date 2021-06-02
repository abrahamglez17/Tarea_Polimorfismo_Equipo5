//
// Created by Paul García on 31/05/21.
//

#ifndef FRACCION_H
#define FRACCION_H
class Fraccion{

private:
    int numerador;
    int denominador;

public:
    //constructores
    Fraccion();
    Fraccion(int, int);

    //setters y getters
    int getNumerador();
    int getDenominador();
    void setNumerador(int);
    void setDenominador(int);

    //metodos
    void reduccion(int &,int &);
    Fraccion suma(Fraccion);
    Fraccion resta(Fraccion);
    Fraccion multiplicacion(Fraccion);
    void imprimir();



};

#endif //TAREAPOLIMORFISMO_FRACCION_H
