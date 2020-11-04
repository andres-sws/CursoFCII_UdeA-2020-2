#ifndef CUENTA_C
#define CUENTA_C

#include <string> 
using namespace std;

#include "CuentaBase.h"

class CuentaCheques : public Cuenta
{
    public:
    CuentaCheques( const string &, const string &, const string &, double = 0.0, double = 0.0);

    void setMontoCuota( double );
    double getMontoCuota();

    void Abonar( double );

    void Cargar( double ); 

    void imprimir();

    private:

    double montoCuota;
};

#endif