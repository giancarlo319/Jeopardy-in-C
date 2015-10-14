/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Elias Amal, Dominick Mancini, Scott McLean, Luisa Rojas-Garcia>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"

#define MAX_LEN 256
#define BUFFER_LEN 256
#define NUM_PLAYERS 4
// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char input[BUFFER_LEN], char tokens[5][BUFFER_LEN]);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player players[NUM_PLAYERS]);

extern void run_game(char token[5][BUFFER_LEN], player players[NUM_PLAYERS]);
#endif /* JEOPARDY_H_ */