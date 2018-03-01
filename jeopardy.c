/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2018, Navjot Aulakh
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
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
//char *playerI = NULL;

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){
    char *tokenA = strtok(input, " ");
    tokenA = strtok(input, " ");

    for(int i = 0; tokenA != NULL; i++)
    {
        strcpy(tokens[i], tokenA);
        tokenA = strtok(NULL, " ");
    }  
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players){
    for(int i = 0; i < num_players; i++){
        printf("Name: %s\tScore:%d\n", players[i].name, players[i].score);
    }
}

int game_state;

int main(void)
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];

    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };

    // Prompt for players names
    printf("Welcome to Jeopardy! Please Enter your Names:\n");
    
    // initialize each of the players in the array
    for(int i = 0; i < 4; i++)
    {
        scanf("%s", players[i].name);
    	//strcpy(players[i].name, playerI);
        players[i].score=0;
    	printf("Player: %s Score:%d\n", players[i].name, players[i].score);
    }
    // Display the game introduction and initialize the questions
    initialize_game();
    
    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    while (game_state)
    {
        // EXAMPLE: This line gets a line of input from the user
        fgets(buffer, BUFFER_LEN, stdin);

        // Initialize token for tokenization of the answers
        char **token = NULL;

        // Call functions from the questions and players source files

        // Execute the game until all questions are answered
        int questions_left = sizeof(questions);
        bool correct;
        char *category;  
        int value = 0;
        char response[BUFFER_LEN] = { 0 };
        
        category = (char *) calloc(BUFFER_LEN, sizeof(char));
        
        while(questions_left > 0)
        {
            for(int i = 0; i < NUM_PLAYERS; i++)
            {
                printf("%s's Turn\nPlease choose from the following questions\n(hint: first enter category and hit enter, then enter the dollar amount and hit enter):\n\n", players[i].name);
                
                display_categories();
                
                printf("\n");
                scanf("%s", category);
                scanf("%d", &value);
                printf("You have chosen: %s %d.\n", category, value);
                
                if(already_answered(category,value))
                {
                    printf("Question has already been answered. Please choose another question\n");
                    i--;
                }
                else if(true)
                {
                    display_question(category, value);
                    scanf("%s", response);
                    
                    correct = valid_answer(category, value, response);
                    if(correct)
                    {
                        printf("Correct! You may now choose another question.\n\n");
                        players[i].score += value;
                        i--;
                    }
                    else{
                        printf("Unfortunately, that is incorrect, or you forgot to say \"What is/Who is\".\n\n");
                    }
                    questions_left--;
                    if(questions_left<=0)
                    {
                        game_state = 0;
                    }
                } 
                show_results(players,NUM_PLAYERS);               
            }
            free(category);
        }
        // Display the final results and exit
        show_results(players,NUM_PLAYERS);
    }
    return EXIT_SUCCESS;
}