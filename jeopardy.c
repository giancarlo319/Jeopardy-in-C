/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Elias Amal, Dominick Mancini, Scott McLean, Luisa Rojas-Garcia>
 * All rights reserved.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define


// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char input[BUFFER_LEN], char tokens[5][BUFFER_LEN]);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players);


int main(void)
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and prompt for players names
    // initialize each of the players in the array
    printf("Welcome to Jeopardy! Please Enter your Names:\n");
    for(int i=0; i<4; i++){
        scanf("%s", players[i].name);
    }
    printf("Thank you.\n");

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files

        char token[5][BUFFER_LEN] = {{0}};

        
        initialize_game();
        run_game(token, players);
        //free(token);
        return 0;

    }

    
}
void show_results(player *players){
    for(int i = 0; i <= 4; i++){
        printf("Name: %s\tScore:%d\n", players[i].name, players[i].score);
    }
}

void tokenize(char input[BUFFER_LEN], char tokens[5][BUFFER_LEN]){

    puts("Tokenizing...");

    char *token1;
    token1 = strtok(input, " ");
    printf("%s", token1);

    for(int i = 0; token1 != NULL; i++){
        strcpy(tokens[i], token1);
        token1 = strtok(NULL, " ");
        puts("loop");
    }       
}

void run_game(char token[5][BUFFER_LEN], player players[NUM_PLAYERS]){
    // Execute the game until all questions are answered
    int questions_remaining = NUM_QUESTIONS;
    bool correct;
    bool answered;
    char category[BUFFER_LEN] = { 0 };  
    int value;
    char response[BUFFER_LEN] = { 0 };
    
    //token = (char *) calloc(256, sizeof(char));


    while(questions_remaining > 0){
        for(int i = 0; i < NUM_PLAYERS; i++)
        {
            printf("%s's Turn\nPlease choose from the following questions\n(hint: first enter category and hit enter, then enter the dollar amount and hit enter):\n\n", players[i].name);
            
            display_categories();
            
            //printf("\n");
            scanf("%s %d", category, &value);
            //printf("CATEGORY: %s, VALUE: %d\n", category, value);
            answered = already_answered(category, value);
            if(answered == true)
            {
                printf("Question has already been answered. Please choose another");
                i--;
            }
            else
            {
                puts("displaying question, plase end your question with a space and \"=\"");
                display_question(category, value);
                
                scanf("%[^=]", response);
                printf("%s\n", response);
                
                puts("got response");
                tokenize(response, token);
                puts("Done Tokenizing");
                printf("%s<--Response\n", token[2]);
                                               //extracts answer from response
                correct = valid_answer(category,value,token[2]);
                if(correct){
                    printf("Correct! You may now choose another question.\n\n");
                    players[i].score += value;
                    i--;
                }
                else{
                    printf("Unfortunately, that is incorrect, or you forgot to say \"What is/Who is\".\n\n");
                }
                question_answered(category, value);
                questions_remaining--;
                if(questions_remaining<=0){
                    break;
                }
            }                
        }
        free(category);
    }
    
    // Display the final results and exit
    show_results(players);

}

//Alex Trebek <> Kebert Xela