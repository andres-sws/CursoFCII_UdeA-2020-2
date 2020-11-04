#include <iostream>

using namespace std;

#include "Fecha.h"

int main()
{
    Fecha fecha1;
    fecha1.setValues();

    cout << "La fecha que ingresó es ";
    fecha1.imprimir();
  
    cout<<"El día siguiente es ";
    fecha1.diaSig();
    fecha1.imprimir();

    return 0;
}

