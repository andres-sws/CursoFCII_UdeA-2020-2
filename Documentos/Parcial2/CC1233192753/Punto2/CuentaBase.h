#ifndef CUENTAB_H
#define CUENTAB_H

#include <string> 

using namespace std;

class Cuenta
{
    public:
    Cuenta( const string &, const string &, const string &, double = 0.0 );

  //~EmpleadoPorComision();

    void setPrimerNombre( const string & ); 
    string getPrimerNombre() const;

    void setApellidoPaterno( const string & ); 
    string getApellidoPaterno() const;
  
    void setNumeroDeCuenta( const string & ); 
    string getNumeroDeCuenta() const;
  
    void setSaldoBase( double ); 
    double getSaldoBase() /* const */;
  
    bool Abonar( double );

    bool Cargar( double ); 

    void setSaldo( double );
    double getSaldo();

    void imprimir() /* const */;

    private:
    string primerNombre;
    string apellidoPaterno;
    string numeroCuenta;
    double saldoBase; 
    double Saldo;

};

#endif