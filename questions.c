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
	strcpy(questions[0].question, "A 'char' is classified as this data type.");
	strcpy(questions[0].answer, "Integer");
	questions[0].value = 200;
	questions[0].answered = false;

	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "This Finnish-American software engineer developed the Linux Kernel, an open-source Unix-like operating system kernel.");
	strcpy(questions[1].answer, "Linus Torvalds");
	questions[1].value = 400;
	questions[1].answered = false;

	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "This famous simple program is often used to illustrate basic syntax of a programming language for a wokring program.");
	strcpy(questions[2].answer, "Hello, World!");
	questions[2].value = 600;
	questions[2].answered = false;

	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "This programming language was introduced by IBM in 1957 to help with translating mathematical formulas into machine code.");
	strcpy(questions[3].answer, "FORTRAN");
	questions[3].value = 800;
	questions[3].answered = false;




	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "This type of algorithm is used to place elemnts of a list in a certain order.");
	strcpy(questions[4].answer, "Sorting");
	questions[4].value = 200;
	questions[4].answered = false;

	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "This is the slowest type of time complexity possible.");
	strcpy(questions[5].answer, "Exponential");
	questions[5].value = 400;
	questions[5].answered = false;

	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "This search algorithm searches a tree or graph by starting at the root and exploring along each branch before backtracking.");
	strcpy(questions[6].answer, "Depth-First Search");
	questions[6].value = 600;
	questions[6].answered = false;

	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "This type of algorithm invokes itself repeatedly until a certain condition is matched.");
	strcpy(questions[7].answer, "Recursive");
	questions[7].value = 800;
	questions[7].answered = false;




	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "This widely used programming language is designed to managing sata held in a relational database system.");
	strcpy(questions[8].answer, "SQL");
	questions[8].value = 200;
	questions[8].answered = false;

	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "This is an association between two entities.");
	strcpy(questions[9].answer, "Relation");
	questions[9].value = 400;
	questions[9].answered = false;

	strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "This is a special relational database column designated to uniquely identify all table records.");
	strcpy(questions[10].answer, "Primary Key");
	questions[10].value = 600;
	questions[10].answered = false;

	strcpy(questions[11].category, "databases");
	strcpy(questions[11].question, "The 3-tier architecture consists of the presentation tier, application tier, and this tier.");
	strcpy(questions[11].answer, "Database");
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
