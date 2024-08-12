#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h>   // for time()
#include <stdbool.h> // for bool type and true/false values

#define SUITS 4
#define FACES 13
#define CARDS 52

// shuffle modifies wDeck
void shuffle(int wDeck[][FACES]);

// dealFull doesn't modify the arrays
void dealFull(const int wDeck[][FACES], const char* wFace[], const char* wSuit[]);

// New prototype
void dealFive(const int wDeck[][FACES], const char* wFace[], const char* wSuit[]);

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};

    // seed random-number generator
    srand(time(NULL));

    // shuffle the deck
    shuffle(deck);

    // initialize suit array
    const char* suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char* face[FACES] = {"Ace", "Deuce", "Three", "Four",
                               "Five", "Six", "Seven", "Eight",
                               "Nine", "Ten", "Jack", "Queen", "King"};

    puts("");

    // Uncomment the call to dealFull if you want to print the full deck
    // dealFull(deck, face, suit);

    // Call dealFive to deal and print five unique cards
    dealFive(deck, face, suit);

    puts("");
    return 0;
}

void shuffle(int wDeck[][FACES]) {
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row;
        size_t column;

        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void dealFull(const int wDeck[][FACES], const char* wFace[], const char* wSuit[]) {
    // deal each of the cards
    for (size_t card = 1; card <= CARDS; ++card) {
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row) {
            // loop through columns of current row
            for (size_t column = 0; column < FACES; ++column) {
                // if slot contains current card, display card
                if (wDeck[row][column] == card) {
                    // print card face and suit
                    printf("%5s of %-8s", wFace[column], wSuit[row]);
                    // print newline or tab
                    printf("%c", card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}

void dealFive(const int wDeck[][FACES], const char* wFace[], const char* wSuit[]) {
    int hand[5]; 
    bool used[CARDS + 1] = {false};    
    int cardIndex = 0;
    int card;

    while (cardIndex < 5) {
        do {
            card = rand() % CARDS + 1;
        } while (used[card]);

        used[card] = true;
        hand[cardIndex++] = card;
    }


    for (int i = 0; i < 5; ++i) {
        size_t row, column;
        for (row = 0; row < SUITS; ++row) {
            for (column = 0; column < FACES; ++column) {
                if (wDeck[row][column] == hand[i]) {
                    break;
                }
            }
            if (column < FACES) {
                break;
            }
        }
        printf("%5s of %-8s", wFace[column], wSuit[row]);
        printf("%c", i % 5 == 4 ? '\n' : '\t');
    }
}
