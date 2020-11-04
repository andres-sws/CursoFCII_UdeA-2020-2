#include <vector>
#include "hangman.h"

using namespace std;

string palabra;
string guessPalabra;
string guess;
int N_letras;
char letra;
char answer;

int main()
{       
    
    srand( time( NULL ) );

    cout << "\n¿Desea jugar ahorcado? (s/n)" << endl; 
    cin >> answer;
     
    if ( answer == 's')
    {   
        bool Start = true;

        while ( Start )
        {
            int choose;
            choose = ( rand() % 10 ) + 1; /* cout<< "palabra # " << choose << endl; */
            /* cout << "\nAqui empieza el juego" << endl; */
            const int WORD_TO_FIND =  choose; 
            palabra = Read ( WORD_TO_FIND, "palabras.txt" );
            N_letras = palabra.length();
            guess = "-";
            for ( int i = 1; i < N_letras; i++ ){ guess.push_back( '-' ); }
            cout << "Su palabra tiene " << guess.length() << " letras\n" << endl;

            bool Playing = true;
            int Fallas = 0;

            while ( Playing )
            {
                man ( Fallas );
                cout << "\n" << guess << "\n" 
                    << "\n¿Desea adivinar una letra  o adivinar la palabra?"
                    << "\n 1. Letra "
                    << "\n 2. Palabra" << endl;
                cin >> answer;

                if ( answer == '1')
                {
                    vector<int> position;
                    position = AdivinarLetra( letra, palabra, N_letras );
                    if ( position.size() == 1 ) { Fallas += 1;}
                    guess = CambiarPalabra( guess, palabra, position );
                    N_letras = position.back();
                    /* cout << N_letras << endl; */ 
                    cout << "Le quedan por adivinar " << position.back() << " de " << palabra.length() << " letras.  Fallas: " << Fallas << endl;
                    cout << "\n" << endl;

                    if ( Fallas > 6 ) 
                    { 
                        man ( Fallas );
                        cout << " " << endl;
                        cout << palabra << endl;
                        cout << "\nSuperaste el número de fallas, has perdio :c \n" 
                            << "\n¿Desea jugar de nuevo? (s/n)" << endl;
                        cin >> answer;
                        if ( answer == 's') { Playing = false; } 
                        else { exit(0); }  
                    }

                    if ( N_letras == 0 )
                    {
                        cout << " " << endl;
                        cout << guess << endl;
                        cout << "\n!Felicitaciones! Ganaste :)\n"   
                            << "\n¿Desea jugar de nuevo? (s/n)" << endl;
                        cin >> answer;
                        if ( answer == 's') { Playing = false; } 
                        else { exit(0); }
                    }

                }
                else if ( answer == '2')
                {
                    bool result;
                    string GuessPalabra;
                    cout << "\nIngrese una palabra" << endl;
                    cin >> GuessPalabra;
                    result = AdivinarPalabra ( GuessPalabra, palabra );

                    if ( result == true )
                    {
                        cout << "\n" << endl;
                        man ( Fallas );
                        cout << " " << endl;
                        cout << palabra << endl;
                        cout << "\n!Felicitaciones! Ganaste :)\n"   
                            << "\n¿Desea jugar de nuevo? (s/n)" << endl;
                        cin >> answer;
                        if ( answer == 's') { Playing = false; } 
                        else { exit(0); }
                    }

                    else 
                    {
                        Fallas += 1;
                
                        cout << "\nLa palabra " << GuessPalabra << " no es la correcta." << " Fallas: " << Fallas << endl;
                        cout << " " << endl;                      
                    }

                    if ( Fallas > 6 ) 
                    { 
                        man ( Fallas );
                        cout << "\nSuperaste el número de fallas, haz perdio :c \n" 
                            << "\n¿Desea jugar de nuevo? (s/n)" << endl;
                        cin >> answer;
                        if ( answer == 's') { Playing = false; } 
                        else { exit(0); }  
                    }


                }

                else { cout << "\nOpción no encontrada\n" << endl;}
 
            }

        }
        
    }
    else { cout << "ok" << endl; exit(0); }

    cout << "END" << endl;

   
  
}
