#include "pch.h"
#include <iostream>
#include <time.h>
using namespace System;
using namespace std;

void Dibujar_horario(int a, int b, int ancho, int alto, int espera) {
    for (int i = a; i <= ancho; i++) {
        Console::SetCursorPosition(i, b); cout << (char)219;
        _sleep(espera);
    }
    for (int i = b; i <= alto; i++) {
        Console::SetCursorPosition(ancho, i); cout << (char)219;
        _sleep(espera);
    }
    for (int i = ancho; i >= a; i--) {
        Console::SetCursorPosition(i, alto); cout << (char)219;
        _sleep(espera);
    }
    for (int i = alto; i >= b; i--) {
        Console::SetCursorPosition(a, i); cout << (char)219;
        _sleep(espera);
    }
}
void dibujar_carta(int inicio_x, int inicio_y, int alto, int ancho) {
    for (int i = inicio_x; i <= (inicio_x + ancho); i++) {
        for (int j = inicio_y; j <= (inicio_y + alto); j++) {
            Console::SetCursorPosition(i, j);
            if (i == inicio_x || i == (inicio_x + ancho)
                || j == inicio_y || j == (inicio_y + alto)) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
    }
}
void comoJugar() {
    Console::SetCursorPosition(50, 12);
    cout << "Instrucciones: " << endl;
    Console::SetCursorPosition(2, 13);
    cout << " - Si el jugador quiere otra carta lo pide y va sumando los valores.Estos valores deben mostrarse" << endl;
    Console::SetCursorPosition(2, 14);
    cout << " - Si el valor acumulado sobrepasa ventiuno, automáticamente es turno del jugador 2";
    Console::SetCursorPosition(2, 15);
    cout << " - Presione una tecla para elegir la cantidad de rondas.";
    
}





int main()
{
    int rondasJ; int carta1; int carta2; int carta3; int carta4;
    srand(time(NULL));
    Console::CursorVisible = false;
    //Dibujar_horario(0, 0, 119, 29, 1);
    //comoJugar();
    //system("pause");
    //system("cls");
    do{
        Dibujar_horario(0, 0, 119, 29, 0);
        Console::SetCursorPosition(42, 12);
        cout << "Ingrese la cantidad de rondas que desean jugar: "; cin >> rondasJ;
        system("cls");
    } while (rondasJ >=10 && 5 <= rondasJ);
    system("cls");
    Dibujar_horario(0, 0, 119, 29, 0);
    for (int i = 0; i < rondasJ; i++)
    {
        Console::SetCursorPosition(4, 7);
        cout << "Jugador 1";
        //carta1
        dibujar_carta(5, 9, 6, 7);
        carta1 = rand() % 13 + 1;
        Console::SetCursorPosition(7, 12);
        cout << carta1;
        //carta2
        dibujar_carta(19, 9, 6, 7);
        carta2 = rand() % 13 + 1;
        Console::SetCursorPosition(21, 12);
        cout << carta2;


        Console::SetCursorPosition(52, 7);
        cout << "Jugador 2";
        //carta3
        dibujar_carta(50, 9, 6, 7);
        carta3 = rand() % 13 + 1;
        Console::SetCursorPosition(52, 12);
        cout << carta3;
        //carta4
        dibujar_carta(66, 9, 6, 7);
        carta4 = rand() % 13 + 1;
        Console::SetCursorPosition(68, 12);
        cout << carta4;
        system("pause");
    }
    


    return 0;
}
