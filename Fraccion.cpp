#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(){
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int num, int den){
    if(den == 0)
        den = 1;
    // ambos negativos o unicamente denominador negativo, entonces cambio signo en ambos
    // La expresion completa sería den < 0 && num < 0 || num > 0 && den < 0
    // Sin embargo, tienen en comun que si el denominador es negativo, cambio el signo en ambos
    if(den < 0 ){
        num = -num;
        den = -den;
    }
    reduccion(num,den);
    numerador = num;
    denominador = den;
}

void Fraccion::reduccion(int &num, int &den){
    // Variables auxiliares
    int limit = 0;
    int signo1 = 1;
    int signo2 = 1;
    // Guarda el signo en las variables signoX y deja num y den sin signo.
    // Esto se hace para que las operaciones modulo y limite esten correctas logicamente
    if(num < 0){
        signo1 = -1;
        num = num*signo1;
    }
    if(den < 0){
        signo2 = -1;
        den = den*signo2;
    }
    // La variable limite es la menor entre el denominador y el numerador
    // Sirve como criterio de parada al identificar un posible maximo comun divisor.
    if(num >= den)
        limit = den;
    else
        limit = num;
    int it = 2;
    while(it<=limit){
        if(num % it == 0 && den % it == 0){
            num = num/it;
            den = den/it;
        }else{
            it++;
        }
    }
    // Devolvemos los signos del numerador y denominador (en caso de que exista cambio)
    num = num*signo1;
    den = den*signo2;
}

//metodo de SUMA
Fraccion Fraccion::suma(Fraccion farg){
    int num = numerador * farg.getDenominador() +  denominador * farg.getNumerador();
    int den = denominador * farg.getDenominador();
    Fraccion fresultado(num,den);
    return fresultado;
}

//metodo de RESTA
Fraccion Fraccion::resta(Fraccion Resta){
    int num = numerador * Resta.getDenominador() -  denominador * Resta.getNumerador();
    int den = denominador * Resta.getDenominador();
    Fraccion fresultado(num,den);
    return fresultado;
}

//metodo de MULTIPLICACION
Fraccion Fraccion::multiplicacion(Fraccion farg){
    int num = numerador * farg.getNumerador();
    int den = denominador * farg.getDenominador();
    Fraccion fresultado(num,den);
    return fresultado;
}

void Fraccion::imprimir(){
    cout << numerador << "/" << denominador << endl;
}

int Fraccion::getNumerador(){return numerador;}
int Fraccion::getDenominador(){return denominador;}
void Fraccion::setNumerador(int num){
    this->numerador = num;
}
void Fraccion::setDenominador(int den){denominador = den;}
