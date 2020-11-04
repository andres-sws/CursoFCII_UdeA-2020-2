#include <iostream>
using namespace std;

#include"CuentaAhorro.h"

CuentaAhorros::CuentaAhorros( const string &nombre,const string &apellido, const string &nc, double saldob, double tasaIn )
    : Cuenta( nombre, apellido, nc, saldob )
{
    setTasaDeInteres( tasaIn );
}

void CuentaAhorros::setTasaDeInteres( double tasain)
{
    TasaInteres = tasain;
}

double CuentaAhorros::getTasaDeInteres()
{
    return TasaInteres; 
}

double CuentaAhorros::calcularInteres()
{
    return getSaldoBase()*getTasaDeInteres();
}

void CuentaAhorros::imprimir()
{
    cout << "\nTipo de Cuenta: AHORROS" << endl;
    Cuenta::imprimir();
    cout<< "Tasa de Interes: "<< getTasaDeInteres()
        << "\n Monto de interes obtenido por cuenta  [ caclcularInteres() ]: "<< calcularInteres() << endl;
}