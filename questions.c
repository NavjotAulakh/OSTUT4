/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2018, Navjot Aualakh
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
	strcpy(questions[0].question, "q1");
	strcpy(questions[0].answer, "a1");
	questions[0].value = 200;
	questions[0].answered = false;

	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "q2");
	strcpy(questions[1].answer, "a2");
	questions[1].value = 400;
	questions[1].answered = false;

	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "q3");
	strcpy(questions[2].answer, "a3");
	questions[2].value = 600;
	questions[2].answered = false;

	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "q4");
	strcpy(questions[3].answer, "a4");
	questions[3].value = 800;
	questions[3].answered = false;




	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "q5");
	strcpy(questions[4].answer, "a5");
	questions[4].value = 200;
	questions[4].answered = false;

	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "q6");
	strcpy(questions[5].answer, "a6");
	questions[5].value = 400;
	questions[5].answered = false;

	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "q7");
	strcpy(questions[6].answer, "a7");
	questions[6].value = 600;
	questions[6].answered = false;

	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "q8");
	strcpy(questions[7].answer, "a8");
	questions[7].value = 800;
	questions[7].answered = false;




	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "q9");
	strcpy(questions[8].answer, "a9");
	questions[8].value = 200;
	questions[8].answered = false;

	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "q10");
	strcpy(questions[9].answer, "a10");
	questions[9].value = 400;
	questions[9].answered = false;

	strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "q11");
	strcpy(questions[10].answer, "a11");
	questions[10].value = 600;
	questions[10].answered = false;

	strcpy(questions[11].category, "databases");
	strcpy(questions[11].question, "q12");
	strcpy(questions[11].answer, "a12");
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

	printf("   %s | %s | %s \n", categories[0], categories[1], categories[2]);
	printf("  __________________________________________________\n");

	printf("      %s    |   %s     |       %s   \n", v[0], v[1], v[2]);
	printf("  __________________________________________________\n");
	
	printf("      %s    |   %s     |       %s   \n", v[3], v[4], v[5]);
	printf("  __________________________________________________\n");
	
	printf("      %s    |   %s     |       %s   \n", v[6], v[7], v[8]);
	printf("  __________________________________________________\n");

	printf("      %s    |   %s     |       %s   \n", v[9], v[10], v[11]);
	printf("  __________________________________________________\n");
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
