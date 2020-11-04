#ifndef CUENTA_A
#define CUENTA_A

#include <string> 
using namespace std;

#include "CuentaBase.h"

class CuentaAhorros : public Cuenta
{
    public:
    CuentaAhorros( const string &, const string &, const string &, double = 0.0, double = 0.0);

    void setTasaDeInteres( double );
    double getTasaDeInteres();

    double calcularInteres();

    void imprimir();

    private:

    double TasaInteres;
};

#endif