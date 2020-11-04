#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string CambiarPalabra ( string guess, string palabra, vector<int> position)
{
    for ( int i = 0; i < position.size() - 1; i++)
    { 
        guess.at( position.at(i) ) = palabra.at( position.at(i) ); 
    }
    return guess;    
}

bool AdivinarPalabra ( string GuessPalabra, string palabra )
{
    bool result;
    int i;
    if ( GuessPalabra == palabra ) { result = true; }
    else { result = false; }
    return result;
}

vector<int> AdivinarLetra ( char letra, string palabra, int N_letras)
{
    cout << "\nIngrese una letra" << endl;
    cin >> letra;
    vector<int> position;
    int cuenta;
    for ( int i; i < palabra.length(); i++)
    {   
        if ( palabra.at(i) == letra ) 
        { 
            position.push_back(i);
            N_letras -= 1;
            cuenta+=1;
        }         
    }

    position.push_back( N_letras );
    if ( position.size() == 1 )
    {
        cout << "\nLa letra "<< letra << " no se encuentra en la palabra" << endl;
    }
    else
    {
        cout << "\n!Correcto! la letra " << letra << " se encuentra en la plabra " << cuenta << " veces" << endl;
    }
    
    return position;

}

string Read (int number, string FileName)
{
    string line;
    ifstream file ( FileName );

    if (!file) 
    {
        cout << "Unable to open file" << endl;
        exit(0);   // call system to stop
    }

    for (int i=0; i<number;i++)
    {
        getline(file,line);
    }

    if (!file.eof()) { /* cout<<"La palabra es:\n" << line << endl; */ }
    else             { cout<<"Esta palabra no está en el documento\n"; exit(0); }

    return line;
}

void man ( int Fallas )
 { 
    if ( Fallas == 0 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    } 

    else if ( Fallas == 1 )
    {
        cout << "     ________ "    << endl;
        cout << "    |        |"    << endl; 
        cout << "    |        |"    << endl;
        cout << "    |         "    << endl;
        cout << "    |         "    << endl;
        cout << "    |         "    << endl;
        cout << "    |       / "    << endl;
        cout << "    |"             << endl;
        cout << "    |"             << endl;
        cout << "____|_____    "    << endl;
    }

    if ( Fallas == 2 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |       / \\ "  << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    }  

    if ( Fallas == 3 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "    |        | "   << endl;
        cout << "    |       / \\ "  << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    } 

    if ( Fallas == 4 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |       / "  << endl;
        cout << "    |        | "   << endl;
        cout << "    |       / \\ "  << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    }     

    if ( Fallas == 5 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |       /| "  << endl;
        cout << "    |        | "   << endl;
        cout << "    |       / \\ "  << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    }  

    if ( Fallas == 6 )
    {
        cout << "     ________ " << endl;
        cout << "    |        |" << endl; 
        cout << "    |        |" << endl;
        cout << "    |"          << endl;
        cout << "    |       /|\\"  << endl;
        cout << "    |        | "   << endl;
        cout << "    |       / \\"  << endl;
        cout << "    |"          << endl;
        cout << "    |"          << endl;
        cout << "____|_____ "    << endl;
    }  

    else if ( Fallas == 7 )
    {
        cout << "     ________ "    << endl;
        cout << "    |        |"    << endl; 
        cout << "    |        |"    << endl;
        cout << "    |        O "   << endl;
        cout << "    |       /|\\"  << endl;
        cout << "    |        | "   << endl;
        cout << "    |       / \\"  << endl;
        cout << "    |"             << endl;
        cout << "    |"             << endl;
        cout << "____|_____ "       << endl;
     }    

 }


