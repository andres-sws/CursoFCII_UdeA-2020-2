#include <iostream>

#include "CuentaBase.h"

using namespace std;

Cuenta::Cuenta( const string &nombre,const string &apellido, const string &nc, double saldob )
    :primerNombre( nombre ), apellidoPaterno( apellido ), numeroCuenta( nc )
{
    setSaldoBase( saldob ); // valida y almacena las ventas brutas
   
}

void Cuenta::setPrimerNombre( const string &nombre )
{
    primerNombre = nombre; 
}

string Cuenta::getPrimerNombre() const
{
    return primerNombre;
}

void Cuenta::setApellidoPaterno( const string &apellido )
{
  apellidoPaterno = apellido; 
}

string Cuenta::getApellidoPaterno() const
{
  return apellidoPaterno;
}

void Cuenta::setNumeroDeCuenta( const string &nc )
{
  numeroCuenta = nc; 
}

string Cuenta::getNumeroDeCuenta() const
{
  return numeroCuenta;
}

void Cuenta::setSaldoBase( double saldob )
{
  saldoBase = ( saldob < 0.0 ) ? 0.0 : saldob;
  setSaldo( saldob );
}

double Cuenta::getSaldoBase() /* const */
{
  return saldoBase;
}

void Cuenta::setSaldo(double saldo)
{
    Saldo = saldo;
}

double Cuenta::getSaldo()
{
    return Saldo;
}

bool Cuenta::Abonar( double abono)
{
    double a;
    a = (abono<0)? 0.0 :abono;
    
    double s;
    s = getSaldo() + a;
    setSaldo(s);
  
    if (a==0)
    {
      cout<<" Error en la transacción, el monto a abonar debe ser mayor a 0 $" << endl;
      cout<<" Su saldo es ahora "<<getSaldo()<<" $"<<endl;
      return false;
    }
    else 
    {
      cout<<" Su saldo es ahora "<<getSaldo()<<" $"<<endl;
      return true;
    }
}

bool Cuenta::Cargar( double cargo)
{
    double c;
    c = (cargo<0)? 0.0 :cargo;

    double s;
    s = getSaldo();

    if (s<cargo)
    {
        setSaldo(s);
        cout<<" Error en la transacción, el monto a cargar excedió el saldo de la cuenta"<<endl; 
        cout<<" Su saldo es ahora "<< getSaldo()<<" $"<<endl;
        return false;
    }

    else if ( cargo <= 0)
    {
      cout<<" Error en la transacción, el monto a cargar debe ser mayor a 0 $" << endl;
      cout<<" Su saldo es ahora "<<getSaldo()<<" $"<<endl;
      return false;
    }

    else 
    {   s=s-c; 
        setSaldo(s);
        cout<<" Su saldo es ahora "<< getSaldo()<<" $"<<endl;
        return true;
    }
  
}

void Cuenta::imprimir() 
{
  cout << "\nDatos de la cuenta: \n"
        << "\nNombre(s): " << getPrimerNombre()
        << "\nApellido(s): " << getApellidoPaterno()
        << "\nNúmero de cuenta: " << getNumeroDeCuenta()
        << "\nSaldo Inical: " << getSaldoBase()<< " $"
        << "\nSaldo Actual: " << getSaldo()<< " $"<<endl;
        

}



