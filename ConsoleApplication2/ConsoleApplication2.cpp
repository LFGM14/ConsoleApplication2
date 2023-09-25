#include "pch.h"

#include <iostream>

#include <time.h>

using namespace System;
using namespace std;

void Dibujar_horario(int a, int b, int ancho, int alto, int espera) {
    for (int i = a; i <= ancho; i++) {
        Console::SetCursorPosition(i, b);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = b; i <= alto; i++) {
        Console::SetCursorPosition(ancho, i);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = ancho; i >= a; i--) {
        Console::SetCursorPosition(i, alto);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = alto; i >= b; i--) {
        Console::SetCursorPosition(a, i);
        cout << (char)219;
        _sleep(espera);
    }
}

void dibujar_carta(int inicio_x, int inicio_y) {
    for (int i = inicio_x; i <= (inicio_x + 7); i++) {
        for (int j = inicio_y; j <= (inicio_y + 6); j++) {
            Console::SetCursorPosition(i, j);
            if (i == inicio_x || i == (inicio_x + 7) ||
                j == inicio_y || j == (inicio_y + 6)) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
    }
}

void howTo() {
    Console::SetCursorPosition(50, 12);
    cout << "Instrucciones: " << endl;
    Console::SetCursorPosition(2, 13);
    cout << " - Si el jugador quiere otra carta lo pide y va sumando los valores.Estos valores deben mostrarse" << endl;
    Console::SetCursorPosition(2, 14);
    cout << " - Si el valor acumulado sobrepasa ventiuno, automáticamente es turno del jugador 2";
    Console::SetCursorPosition(2, 15);
    cout << " - Presione una tecla para elegir la cantidad de rondas.";

}



int ChooseAceValue(int score) {
    Console::SetCursorPosition(55, 26);
    cout << "Que valor quieres para tu as? (1 or 11): " << endl <<
        "Advertencia: El valor que elijas ahora será utilizado por el resto de tu turno.";
    int ace_value;
    cin >> ace_value;

    while (ace_value != 1 && ace_value != 11) {
        cout << "Valor invalido. Intenta otra vez." << endl;
        cout << "Que valor quieres para tu as? (1 or 11): ";
        cin >> ace_value;
    }

    if (ace_value == 1 && score + 11 > 21) {
        cout << "Debes elegir el valor de 1 o perderás automaticamente." << endl;
        ace_value = 1;
    }

    return ace_value;
}

int playerSetup(
    const char* name,
    int posPlayerNameX,
    int posPlayerNameY,
    int posPlayerCard1X,
    int posPlayerCard2X,
    int posPlayerCardY,
    int posPlayerCard1NumberX,
    int posPlayerCard2NumberX,
    int posPlayerCardNumberY,
    int posPlayerScoreX,
    int posPlayerScoreY) {

    int firstCard, secondCard, score, buffer, answerExtra;
    Console::SetCursorPosition(posPlayerNameX, posPlayerNameY);
    cout << name;

    dibujar_carta(posPlayerCard1X, posPlayerCardY);
    firstCard = rand() % 13 + 1;
    Console::SetCursorPosition(posPlayerCard1NumberX, posPlayerCardNumberY);
    cout << firstCard;

    dibujar_carta(posPlayerCard2X, posPlayerCardY);
    secondCard = rand() % 13 + 1;
    Console::SetCursorPosition(posPlayerCard2NumberX, posPlayerCardNumberY);
    cout << secondCard;

    if (firstCard == 11 || firstCard == 12 || firstCard == 13) {
        firstCard = 10;
    }
    if (secondCard == 11 || secondCard == 12 || secondCard == 13) {
        secondCard = 10;
    }

    score = firstCard + secondCard;

    Console::SetCursorPosition(posPlayerScoreX, posPlayerScoreY);

    if (firstCard == 1) {
        int newValue = ChooseAceValue(firstCard);
        score = (score - 1) + newValue;
    }

    if (secondCard == 1) {
        int newValue = ChooseAceValue(secondCard);
        score = (score - 1) + newValue;
    }

    else
    {
        cout << "Total:" << score;
    }

    if (score == 21) {
        cout << "Felicidades " << name << endl;
        return 21;
    }
    else {
        while (score <= 21){
            cout << "¿Deseas una carta extra? (1 = Si, 0 = no) "; cin >> answerExtra;
            if (answerExtra == 1) { // la pide EVALUA
                Console::SetCursorPosition(50, 25);
                buffer = rand() % 13 + 1;
                cout << "Obteniste un " << buffer << endl;
                score += buffer;
                Console::SetCursorPosition(posPlayerScoreX, posPlayerScoreY);
                cout << "Total:" << score;
            }
            else if(answerExtra == 0) {
                return score;
            }
            else if (score >= 21) {
                Console::SetCursorPosition(50, 23);
                cout << "Perdiste " << name;
                return 0;
            }
            
        }
            return score;
        }
    }






void mainGame(int rounds) {
    int posPlayer1NameX = 4, posPlayer2NameX = 52, posPlayersNameY = 7;
    int posPlayer1Card1X = 5, posPlayer2Card1X = 50, posPlayer1Card2X = 19, posPlayer2Card2X = 66, posCardsY = 9;
    int posPlayer1Card1NumberX = 7, posPlayer2Card1NumberX = 52, posPlayer1Card2Numberx = 21, posPlayer2Card2Numberx = 68, posPlayerCardNumberY = 12;
    int posPlayer1ScoreX = 11, posPlayer2ScoreX = 55, posPlayerScoreY = 20;

    int player1Score = 0, player2Score = 0;

    
    Console::SetCursorPosition(42, 12);
    for (int i = 0; i < rounds; i++) {
        Dibujar_horario(0, 0, 119, 29, 0);
        player1Score = playerSetup("Jugador 1", posPlayer1NameX, posPlayersNameY, posPlayer1Card1X, posPlayer1Card2X, posCardsY, posPlayer1Card1NumberX, posPlayer1Card2Numberx, posPlayerCardNumberY, posPlayer1ScoreX, posPlayerScoreY);
        player2Score = playerSetup("Jugador 2", posPlayer2NameX, posPlayersNameY, posPlayer2Card1X, posPlayer2Card2X, posCardsY, posPlayer2Card1NumberX, posPlayer2Card2Numberx, posPlayerCardNumberY, posPlayer2ScoreX, posPlayerScoreY);

        if (player1Score == player2Score) {
            //empate
            player1Score += 1;
            player2Score += 1;
            Console::SetCursorPosition(52, 25);
            cout << "Empate";
        }
        if (player1Score > player2Score) {
            player1Score += 1;
            Console::SetCursorPosition(52, 25);
            cout << "Gano Jugador 1";
        }
        if (player2Score > player1Score) {
            player2Score += 1;
            Console::SetCursorPosition(52, 25);
            cout << "Gano Jugador 2";
        }

        system("pause");
        system("cls");
    }
}

void gameStart() {
    int rounds;
    Dibujar_horario(0, 0, 119, 29, 0);
    howTo();
    system("pause");
    system("cls");
    Dibujar_horario(0, 0, 119, 29, 0);
    Console::SetCursorPosition(42, 12);
    cout << "Ingrese la cantidad de rondas que desean jugar: ";
    cin >> rounds;
    system("cls");
    if (rounds <= 4 || rounds >= 11) {
        gameStart();
    }
    else {
        mainGame(rounds);
    }
}

int main() {
    srand(time(NULL));
    Console::CursorVisible = false;

    gameStart();

    return 0;
}