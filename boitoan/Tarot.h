#ifndef TAROT_H
#define TAROT_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // Để dùng cho ngoại lệ
#include <conio.h>
#include <cstdlib>
using namespace std;

class TarotCard {
private:
    string ten;
    string daiDien;
    string yNgia;
    string tinhHuong;

public:
    // Constructor
    TarotCard(string ten = "", string daiDien = "", string yNgia = "", string tinhHuong = "");

    // Getters
    string getTen() const;
    string getDaiDien() const;
    string getYNgia() const;
    string getTinhHuong() const;

    // Display method
    void display() const;
};

class TarotDeck {
private:
    vector<TarotCard> deck;

public:
    // Constructor
    TarotDeck();

    // Shuffle the deck
    void shuffleDeck();

    // Draw a card
    TarotCard drawCard();


    // Display the deck
    void displayDeck() const;

    // Get remaining cards
    int getRemainingCards() const;

};
void boiTarot();


//void OpenWebsite() {
//    // URL of the website
//    string url = "";
//    // Open the URL in the default web browser
//    string command = "start " + url;
//    system(command.c_str());
//}
#endif // TAROT_H
