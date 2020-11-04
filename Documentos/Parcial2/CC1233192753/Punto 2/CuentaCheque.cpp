#include <iostream>
using namespace std;

#include"CuentaCheque.h"

CuentaCheques::CuentaCheques( const string &nombre,const string &apellido, const string &nc, double saldob, double cuota )
    : Cuenta( nombre, apellido, nc, saldob )
{
    setMontoCuota( cuota );
}

void CuentaCheques::setMontoCuota( double mcuota )
{
    montoCuota = mcuota;
}

double CuentaCheques::getMontoCuota()
{
    return montoCuota;
}

void CuentaCheques::Abonar( double abono)
{
    bool a;
    double s;
    a = Cuenta::Abonar( abono );
    s = Cuenta::getSaldo();
    
    if ( a == true )
    {
        s = s - getMontoCuota();
        Cuenta::setSaldo( s );

        cout << "Cuota por transaccion: " << getMontoCuota() << " $" 
            << "\n Saldo Total: " << Cuenta::getSaldo() << " $" << endl;
    }

    else
    {
        cout << "Cuota por transaccion: " << 0.00 << " $" 
            << "\n Saldo Total: " << Cuenta::getSaldo() << " $" << endl;
    }
    
}

void CuentaCheques::Cargar( double cargo)
{
    bool c;
    double s;
    c = Cuenta::Cargar( cargo );
    s = Cuenta::getSaldo();
    
    if ( c == true )
    {
        s = s - getMontoCuota();
        Cuenta::setSaldo( s );

        cout << "Cuota por transaccion: " << getMontoCuota() << " $" 
            << "\n Saldo Total: " << Cuenta::getSaldo() << " $" << endl;
    }

    else
    {
        cout << "Cuota por transaccion: " << 0.00 << " $" 
            << "\n Saldo Total:  " << Cuenta::getSaldo() << " $" << endl;
    }
    
}

void CuentaCheques::imprimir()
{
    cout << "\nTipo de Cuenta: CHEQUES" << endl;
    Cuenta::imprimir();
    cout << " Cuota por transaccion: "<< getMontoCuota() << " $" << endl; 
        
}
