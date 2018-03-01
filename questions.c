/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "This is the capital city of Hungary");
	strcpy(questions[0].answer, "Budapest");
	questions[0].value = 200;
	questions[0].answered = false;

	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "Jordan is located in this continent");
	strcpy(questions[1].answer, "Asia");
	questions[1].value = 400;
	questions[1].answered = false;

	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "This country is bordered by Russia and Sweden");
	strcpy(questions[2].answer, "Finland");
	questions[2].value = 600;
	questions[2].answered = false;

	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "This country has the largest number of universities");
	strcpy(questions[3].answer, "India");
	questions[3].value = 800;
	questions[3].answered = false;




	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "In this part of the cell cycle, chromosomes in a cell nucleus are separated into two identical sets of chromosomes");
	strcpy(questions[4].answer, "Mitosis");
	questions[4].value = 200;
	questions[4].answered = false;

	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "Number of planets in our solar system");
	strcpy(questions[5].answer, "8");
	questions[5].value = 400;
	questions[5].answered = false;

	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "This is the chemical formula for hydrogen peroxide");
	strcpy(questions[6].answer, "H2O2");
	questions[6].value = 600;
	questions[6].answered = false;

	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "Type of energy that a body possesses by virtue of being in motion");
	strcpy(questions[7].answer, "Kinetic");
	questions[7].value = 800;
	questions[7].answered = false;




	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "The Open System Interconnection model has this many layers");
	strcpy(questions[8].answer, "7");
	questions[8].value = 200;
	questions[8].answered = false;

	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "This device forwards data packets between databases");
	strcpy(questions[9].answer, "Router");
	questions[9].value = 400;
	questions[9].answered = false;

	strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "Frames from one LAN can be transmitted to another LAN via this device");
	strcpy(questions[10].answer, "Bridge");
	questions[10].value = 600;
	questions[10].answered = false;

	strcpy(questions[11].category, "databases");
	strcpy(questions[11].question, "Number of hosts attached to each of the local area networks at your site");
	strcpy(questions[11].answer, "254");
	questions[11].value = 800;
	questions[11].answered = false;

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    char v[12][20];

	for (int i = 0; i < NUM_QUESTIONS; i++) {
		
		if (questions[i].answered == false) {
			
			snprintf(v[i], 20, "%d", questions[i].value);
			
		} else {

			strcpy(v[i], "   ");

		}
			
	}

	
	printf("   %s   |   %s   |   %s   \n", categories[0], categories[1], categories[2]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", v[0], v[1], v[2]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", v[3], v[4], v[5]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", v[6], v[7], v[8]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", v[9], v[10], v[11]);
	printf("  -------------------------------------------------\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) 
	{
		if ((strcmp(category, questions[i].category) == 0) && value == questions[i].value) 
		{
			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    bool is_valid;

	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) 
        {
			if (strcmp(questions[i].answer, answer) == 0) 
            {
				is_valid = true;
			} else {
				is_valid = false;
			}
		}
	}
	return is_valid;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    bool answered = false;
    // lookup the question and see if it's already been marked as answered
	for(int i = 0; i < 12; i++)
    {
		if((strcmp(questions[i].category,category) == 0) && (questions[i].value == value))
        {
			if(questions[i].answered == false)
				answered = false;
			else
				answered = true;
		}
	}
    return answered;
}
