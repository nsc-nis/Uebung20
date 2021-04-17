#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//********************************************************************
//
// Programm        : Übung 20 - Bitoperatoren
//
//
// Ersteller       : Niklas Schachl
//
//
// Erstelldatum    : 15.4.2021
//
//
// Kurzbeschreibung: Programm zum Üben von Bitoperatoren in C
//
// ACHTUNG: Das kompilieren auf LInux funtkioniert mit CLion NICHT! Stattdessen im Terminal: gcc -o main main.c -lm
//          (aufgrund der Bibliothek libm.a, die gelinkt werden muss)
//
//********************************************************************

//Variablen deklarieren
unsigned int inputBits;
unsigned int x;
unsigned int y;

//Funktionen deklarieren
unsigned int getBits();
void putbits(unsigned int n);

//Hauptprogramm
int main()
{
    printf("* ---- Integer to Bit conversion ----\n");
    printf("* Please type in a integer-number:\n");
    printf("./");
    fflush(stdin);
    scanf("%d", &inputBits);
    putbits(inputBits);

    printf("* ---- Bit to Integer conversion ----\n");
    printf("* Result: %u\n", getBits());

    printf("* ---- Bit operations ----\n");

    //Eingabe des Benutzers
    printf("* Please type in two figures:\n");
    printf("./firstNumber/");
    fflush(stdin);
    scanf("%u", &x);
    printf("./secondNumber/");
    fflush(stdin);
    scanf("%u", &y);

    //Ausgabe Bitmuster variable x:
    printf("* Bit pattern of: %u = x: ",x);
    putbits(x);

    //Ausgabe Bitmuster variable y:
    printf("* Bit pattern of: %u = x: ",y);
    putbits(y);

    //Ausgabe Bitmuster x & y:
    printf("* Bit pattern of x & y: ");
    putbits(x & y);

    //Ausgabe Bitmuster x | y:
    printf("* Bit pattern of x | y: ");
    putbits(x | y);

    //Ausgabe Bitmuster x ^ y:
    printf("* Bit pattern of x ^ y: ");
    putbits(x ^ y);

    return 0;
}

//********************************************************************
//
// Funktion        : putbits
//
//
// Kurzbeschreibung: Gibt das Bitmuster einer Zahl vom Typ unsigned int (also Länge 2 Byte) ab der aktuellen Cursor-Position aus.
//
// Parameter       :
//    1   n  unsigned int  Integer-Zahl, welche in ein Bitmuster umgewandelt wird
//
//********************************************************************
void putbits(unsigned int n)
{
    for (int i = 15; i >= 0; --i)
    {
        if(n / pow(2, i) >= 1)
        {
            n = n - pow(2,i);   //Kompilieren im Terminal: gcc -o main main.c -lm

            printf("1");
        }
        else
            printf("0");

        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

//********************************************************************
//
// Funktion        : getBits
//
//
// Kurzbeschreibung: Liest vom Benutzer auf der Konsole eine 16 Bit lange Binärzahl ein und gibt diese vom Typ unsigned int zurück
//
//********************************************************************
unsigned int getBits()
{
    long long num;

    printf("* Please type in a binary-number:\n");
    printf("./");
    fflush(stdin);
    scanf("%lld", &num);

    int dec = 0, i = 0, rem;
    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        dec += rem * pow(2,i);
        ++i;
    }
    return dec;
}
