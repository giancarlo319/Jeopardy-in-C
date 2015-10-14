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
    
    question questions[0].category = "geography"
	question questions[0].question = "This is the capital city of Hungary"
	question questions[0].answer = "Budapest"
	question questions[0].value = 200
	question questions[0].answered = false

	question questions[1].category = "geography"
	question questions[1].question = "Jordan is located in this continent"
	question questions[1].answer = "Asia"
	question questions[1].value = 400
	question questions[1].answered = false

	question questions[2].category = "geography"
	question questions[2].question = "This country is bordered by Russia and Sweden"
	question questions[2].answer = "Finland"
	question questions[2].value = 600
	question questions[2].answered = false

	question questions[3].category = "geography"
	question questions[3].question = "This country has the largest number of universities"
	question questions[3].answer = "India"
	question questions[3].value = 800
	question questions[3].answered = false




	question questions[4].category = "science"
	question questions[4].question = "In this part of the cell cycle, chromosomes in a cell nucleus are separated into two identical sets of chromosomes"
	question questions[4].answer = "Mitosis"
	question questions[4].value = 200
	question questions[4].answered = false

	question questions[5].category = "science"
	question questions[5].question = "Number of planets in our solar system"
	question questions[5].answer = "8"
	question questions[5].value = 400
	question questions[5].answered = false

	question questions[6].category = "science"
	question questions[6].question = "This is the chemical formula for hydrogen peroxide"
	question questions[6].answer = "H2O2"
	question questions[6].value = 600
	question questions[6].answered = false

	question questions[7].category = "science"
	question questions[7].question = "Type of energy that a body possesses by virtue of being in motion"
	question questions[7].answer = "Kinetic"
	question questions[7].value = 800
	question questions[7].answered = false




	question questions[8].category = "computer networks"
	question questions[8].question = "The Open System Interconnection model has this many layers"
	question questions[8].answer = "7"
	question questions[8].value = 200
	question questions[8].answered = false

	question questions[9].category = "computer networks"
	question questions[9].question = "This device forwards data packets between computer networks"
	question questions[9].answer = "Router"
	question questions[9].value = 400
	question questions[9].answered = false

	question questions[10].category = "computer networks"
	question questions[10].question = "Frames from one LAN can be transmitted to another LAN via this device"
	question questions[10].answer = "Bridge"
	question questions[10].value = 600
	question questions[10].answered = false

	question questions[11].category = "computer networks"
	question questions[11].question = "Number of hosts attached to each of the local area networks at your site"
	question questions[11].answer = "254"
	question questions[11].value = 800
	question questions[11].answered = false

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{

	char c1[] = categories[0];
	char c2[] = categories[1];
	char c3[] = categories[2];
	
	char c1q1[] = "200";
	char c2q1[] = "200";
	char c3q1[] = "200";
	
	char c1q2[] = "400";
	char c2q2[] = "400";
	char c3q2[] = "400";

	char c1q3[] = "600";
	char c2q3[] = "600";
	char c3q3[] = "600";
	
	char c1q4[] = "800";
	char c2q4[] = "800";
	char c3q4[] = "800";


	
	printf("   %s   |   %s   |   %s   \n", c1, c2, c3);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", c1q1, c2q1, c3q1);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", c1q2, c2q2, c3q2);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", c1q3, c2q3, c3q3);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", c1q4, c2q4, c3q4);
	printf("  -------------------------------------------------\n");


}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}

void question_answered(char *category, int value)
{
    //Flags a question as answered
}
