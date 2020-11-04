#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#include "Fecha.h"

Fecha::Fecha( int d, int m, int y )
{
    dia = d;
    mes = m;
    anio = y;
}

void Fecha::setValues()
{

    bool reject;
    reject = true;

    cout<<"Este programa calcula el día siguiente a una fecha ingesada"<<endl;

    while(reject==true)
    {   
        string fecha_i;
        cout<<"Escriba una fecha en el formato dd/mm/aa incluyendo el simbolo \"/\" "<<endl;
        getline(cin,fecha_i);

        vector<int> vect; 
        stringstream ss(fecha_i); 
        int i;

	    while(ss >> i) 
        { 
		    vect.push_back(i); 
		    if(ss.peek() == '/') {ss.ignore();} 		
	    } 

        dia=vect[0]; mes=vect[1]; anio=vect[2];

        if (dia<=0 || mes<=0 || anio<=0){cout<<"La fecha ingresada es incorrecta"<<endl;}

        else if(mes==2)
        {
            if (bisiesto()== false && dia>28){cout<<"La fecha ingresada es incorrecta"<<endl;}
            else if (bisiesto()== true && dia>29){cout<<"La fecha ingresada es incorrecta"<<endl;}
            else {reject=false;}
        }

        else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        {
            if (dia>31){cout<<"La fecha ingresada es incorrecta"<<endl;}
            else {reject = false;}
        }

        else if (mes>12){cout<<"La fecha ingresada es incorrecta"<<endl;}

        else 
        {
            if(dia>30){cout<<"La fecha ingresada es incorrecta"<<endl;}
            else {reject = false;}
        }
        
    }

}

// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir()
{
    cout << dia << '/' << mes << '/' << anio<<endl;
}

bool Fecha::bisiesto()
{
    if (anio%4==0)
    {
        if (anio%100==0)
        {
            if (anio%400==0){return true;}
            else {return false;}
                
        }
        else {return true;}
    }
    else {return false;}
}

void Fecha::diaSig()
{
    if (dia<=27)
    {
        dia=dia+1;
    }
    else if (dia==28)
    {
        if (mes==2)
        {
            if (bisiesto() == true){dia=dia+1;}
            else {mes=mes+1;dia=1;}
        }
        else {dia=dia+1;}
    }
    else if (dia==29)
    {
        if (mes==2){mes=mes+1;dia=1;}
        else {dia=dia+1;}
    }

    else if (dia==30)
    {
        if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        {
            dia=dia+1;
        }
        else {mes=mes+1; dia=1;}
    }

    else if (dia==31)
    {
        if (mes==12){anio=anio+1; mes=1; dia=1;}
        else {mes=mes+1; dia=1;}
    }

    
    
}