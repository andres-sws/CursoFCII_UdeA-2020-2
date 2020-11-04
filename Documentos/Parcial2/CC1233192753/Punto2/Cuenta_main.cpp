#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "CuentaBase.h"
#include "CuentaAhorro.h"
#include "CuentaCheque.h"

int main()
{
    char answer;

    string Nombre;
    string Apellido;
    string numerocuenta;
    double Saldobase;

    cout << "\nEste programa crea cuentas tipo Ahorro o Cheque.\n"
        << "\n¿Desea arbir una cuenta? (s/n)" << endl;
    cin >> answer;

    if ( answer == 'n') { exit(0); }

    bool abrirCuenta = true;

    while ( abrirCuenta )
    {
        if ( answer == 's' )
        {
            srand( time( NULL ) );
        
            cout << "Ingrese su(s) nombre(s): " << endl;
            cin.ignore();
            getline(cin, Nombre);

            cout << "Ingrese su(s) apellido(s): " << endl;
            getline(cin, Apellido);

            bool SBase = true;

            while (SBase)
            {
                cout << "Ingrese su Saldo Inicial: " << endl;
                cin >> Saldobase;

                if ( Saldobase <= 0 )
                {
                    cout << "El monto ingresado no es válido" << endl;
                }
                else { SBase = false; }
            }
            
            int a; int b; int c;
            string a_s; string b_s; string c_s; string barra; 

            a = 100 + rand() % (900);
            b = 100000 + rand() % (900000) ;
            c = 10 + rand() % (90);

            a_s = to_string(a);
            b_s = to_string(b);
            c_s = to_string(c);
            barra = "-";

            numerocuenta = a_s + barra + b_s + barra + c_s;

            char Tipo;

            bool TipoCuenta = true;

           

            while (TipoCuenta)
            {   
                cout << "¿Desea abrir Cuenta de Ahorros o una Cuenta de Cheques? "
                << "\n 1. Ahorros"
                << "\n 2. Cheques" << endl;
                cin >> Tipo;

                if ( Tipo == '1' ) //CuentaAhorros
                {
                    double tasain = .06;

                    cout << "Ud escogió una Cuenta de Ahorros "
                        << "\nLa tasa de interes es " << tasain*100 << " % "
                        << "\n Creando cuenta... " << endl;

                    CuentaAhorros cuenta ( Nombre, Apellido, numerocuenta, Saldobase, tasain);

                    cout << "Su cuenta ha sido creada exitosamente "
                        << " \n¿Desea ver su cuenta? (s/n) " << endl;
                    cin >> answer;

                    if ( answer == 's' ) { cuenta.imprimir(); /* TipoCuenta = false; abrirCuenta = false; */ } 
                    else { /* TipoCuenta = false; abrirCuenta = false; */ }

                    bool Transaccion = true;

                    char TipoT;
                        cout << "\n¿Desea realizar una transacción con su cuenta? (s/n)" << endl;
                        cin >> answer;

                    if ( answer == 's')
                    {
                        while ( Transaccion )
                        {
                            cout << "Escoga la transacción que desea realizar "
                                << "\n 1. Abonar"
                                << "\n 2. Cargar" << endl;
                            cin >> TipoT;

                            if ( TipoT == '1' ) // Abonar
                            {
                                double abono;
                                cout << "Ingrese la cantidad que desea abonar " << endl;
                                cin >> abono;
                                cout << "La cantidad a abonar es " << abono << " $"
                                    << "\n Realizando el transacción..." << endl;
                                cuenta.Abonar( abono );
                                cout << "Transacción finalizada "
                                    << " \n¿Desea ver su cuenta? (s/n) " << endl;
                                cin >> answer;

                                if ( answer == 's' ) { cuenta.imprimir(); } 
                                else { }
                                
                                cout << "\n¿Desea realizar otra transacción? (s/n)" << endl;
                                cin >> answer;

                                if ( answer == 'n' )
                                {
                                    cout << "\n¿Desea crear otra cuenta? (s/n)" << endl;
                                    cin >> answer;

                                    if ( answer == 's') { Transaccion = false; TipoCuenta = false; }
                                    else {  Transaccion = false; TipoCuenta = false; abrirCuenta = false; }

                                } 
                                else { } continue;
                            }

                            else if ( TipoT == '2' ) //Cargar
                            {
                                double cargo;
                                cout << "Ingrese la cantidad que desea cargar " << endl;
                                cin >> cargo;
                                cout << "La cantidad a cargar es " << cargo << " $"
                                    << "\n Realizando el transacción..." << endl;
                                cuenta.Cargar( cargo );
                                cout << "Transacción finalizada "
                                    << " \n¿Desea ver su cuenta? (s/n) " << endl;
                                cin >> answer;

                                if ( answer == 's' ) { cuenta.imprimir(); } 
                                else { }
                                
                                cout << "\n¿Desea realizar otra transacción? (s/n)" << endl;
                                cin >> answer;

                                if ( answer == 'n' )
                                {
                                    cout << "\n¿Desea crear otra cuenta? (s/n)" << endl;
                                    cin >> answer;

                                    if ( answer == 's') { Transaccion = false; TipoCuenta = false; }
                                    else {  Transaccion = false; TipoCuenta = false; abrirCuenta = false; }

                                } 
                                else { } continue;


                            }

                            else 
                            {
                                cout << "Opción no econtrada"
                                    << "\nVuelva a intentarlo" << endl;
                                continue; 
                            }

                        }
                    }

                    else
                    {
                        cout << " ¿Desea crear otra cuenta? (s/n)"  << endl;
                        cin >> answer;

                        if ( answer == 's') {Transaccion = false; TipoCuenta = false;}
                        else { exit(0); }
                    }
                                        
                    
                }

                else if ( Tipo == '2' )
                {
                    double cuota = 1200;

                    cout << "Ud escogió una Cuenta de Cheques "
                        << "\nLa cuota por transacción es " << cuota << " $"
                        << "\n Creando cuenta... " << endl;

                    CuentaCheques cuenta ( Nombre, Apellido, numerocuenta, Saldobase, cuota);

                    cout << "Su cuenta ha sido creada exitosamente "
                        << " \n¿Desea ver su cuenta? (s/n) " << endl;
                    cin >> answer;

                    if ( answer == 's' ) { cuenta.imprimir(); /* TipoCuenta = false; abrirCuenta = false; */ } 
                    else { /* TipoCuenta = false; abrirCuenta = false; */ }

                    bool Transaccion = true;

                    char TipoT;
                    cout << "\n¿Desea realizar una transacción con su cuenta? (s/n)" << endl;
                    cin >> answer;

                    if ( answer == 's')
                    {
                        while ( Transaccion )
                        {
                            cout << "Escoga la transacción que desea realizar "
                                << "\n 1. Abonar"
                                << "\n 2. Cargar" << endl;
                                cin >> TipoT;

                            if ( TipoT == '1' ) //Abonar_Cheque
                            {
                                double abono;
                                cout << "Ingrese la cantidad que desea abonar " << endl;
                                cin >> abono;
                                cout << "La cantidad a abonar es " << abono << " $"
                                << "\n Realizando el transacción..." << endl;
                                cuenta.Abonar( abono );
                                cout << "Transacción finalizada "
                                << " \n¿Desea ver su cuenta? (s/n) " << endl;
                                cin >> answer;

                                if ( answer == 's' ) { cuenta.imprimir(); } 
                                else { }
                                
                                cout << "\n¿Desea realizar otra transacción? (s/n)" << endl;
                                cin >> answer;

                                if ( answer == 'n' )
                                {
                                    cout << "\n¿Desea crear otra cuenta? (s/n)" << endl;
                                    cin >> answer;

                                    if ( answer == 's') { Transaccion = false; TipoCuenta = false; }
                                    else {  Transaccion = false; TipoCuenta = false; abrirCuenta = false; }

                                } 
                                else { } continue;

                            }

                            else if ( TipoT == '2' ) //CargarCheque
                            {
                                double cargo;
                                cout << "Ingrese la cantidad que desea cargar " << endl;
                                cin >> cargo;
                                cout << "La cantidad a cargar es " << cargo << " $"
                                    << "\n Realizando el transacción..." << endl;
                                cuenta.Cargar( cargo );
                                cout << "Transacción finalizada "
                                    << " \n¿Desea ver su cuenta? (s/n) " << endl;
                                cin >> answer;

                                if ( answer == 's' ) { cuenta.imprimir(); } 
                                else { }
                                
                                cout << "\n¿Desea realizar otra transacción? (s/n)" << endl;
                                cin >> answer;

                                if ( answer == 'n' )
                                {
                                    cout << "\n¿Desea crear otra cuenta? (s/n)" << endl;
                                    cin >> answer;

                                    if ( answer == 's') { Transaccion = false; TipoCuenta = false; }
                                    else {  Transaccion = false; TipoCuenta = false; abrirCuenta = false; }

                                } 
                                else { } continue;
                            }

                            else 
                            {
                                cout << "Opción no econtrada"
                                    << "\nVuelva a intentarlo" << endl;
                                continue; 
                            }   

                        }
                                                    
                    }
                    else
                    {
                        cout << "\n¿Desea crear otra cuenta? (s/n)"  << endl; 
                        cin >> answer;

                        if ( answer == 's') {Transaccion = false; TipoCuenta = false;}
                        else { exit(0); }
                    }
                }
                else { cout << "Opción no encontrada" << endl; } continue;  //dejar
            }   
        }

        else { exit(0); }
    }
    /* cout << "you made it! :3" << endl; */

    return 0;
}