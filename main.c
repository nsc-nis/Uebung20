#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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
bool isRunning;
bool isError;
char inputChar;

//Funktionen deklarieren
unsigned int getBits();
void putbits(unsigned int n);

//Hauptprogramm
int main()
{
    do
    {
        isRunning = true;
        isError = true;
        printf("\n* ---- Integer to Bit conversion ----\n");
        printf("* Please type in a integer-number:\n");
        printf("./");
        fflush(stdin);
        scanf("%d", &inputBits);
        printf("* Result: ");
        putbits(inputBits);

        printf("\n* ---- Bit to Integer conversion ----\n");
        printf("* Result: %u\n", getBits());

        printf("\n* ---- Bit operations ----\n");

        //Eingabe des Benutzers
        printf("* Please choose an input method: \n");
        printf("* binary (bit-pattern) - b\n");
        printf("* decimal (integer-value) - d\n");
        printf("./operations/");
        fflush(stdin);
        fflush(stdin);
        scanf("%c", &inputChar);

        if(inputChar == 'b')
        {
            printf("* Please type in two figures:\n");
            x = getBits();
            y = getBits();
        }
        else if(inputChar == 'd')
        {
            printf("* Please type in two figures:\n");
            printf("./firstNumber/");
            fflush(stdin);
            scanf("%u", &x);

            printf("./secondNumber/");
            fflush(stdin);
            scanf("%u", &y);
        }
        else
        {
            printf("\n* ERROR! Wrong input!\n");
            x = 1;
            y = 1;
        }

        //Ausgabe Bitmuster variable x:
        printf("* Bit pattern of: %u = x: ", x);
        putbits(x);

        //Ausgabe Bitmuster variable y:
        printf("* Bit pattern of: %u = x: ", y);
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

        printf("\n* ---- Bit shifting ----\n");

        //Eingabe des Benutzers
        printf("* By how many positions should x be shifted?\n");
        printf("./shift/");
        fflush(stdin);
        scanf("%u", &inputBits);

        //Ausgabe Bitmuster x << n:
        printf("* Bit pattern of x << %u: ", inputBits);
        putbits(x << inputBits);

        //Ausgabe Bitmuster x >> n:
        printf("* Bit pattern of x >> %u: ", inputBits);
        putbits(x >> inputBits);

        //re-run
        while (isError)
        {
            printf("\n* Would you like to do more operations? (y/n)\n");
            printf("./exit/");
            fflush(stdin);
            scanf("%s", &inputChar);

            if (inputChar == 'y')
            {
                isError = false;
            }
            else if (inputChar == 'n')
            {
                isError = false;
                isRunning = false;
                printf("* Shutting down...\n");
            }
            else
                printf("\n* ERROR! Wrong input!\n");
        }
    }
    while (isRunning);

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
