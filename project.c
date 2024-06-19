#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a single question
struct Question {
    char question[100];
    char options[4][50];
    char correct_answer;
};
struct Question Qu[100];
int count=0;
// Function to load questions from a file
void loadQuestions() {
    FILE *file = fopen("Question.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int i=0;
    while(!feof(file)){
        fgets(Qu[i].question,100,file);
        for(int j=0;j<4;j++){
            fgets(Qu[i].options[j],50,file);
        }
        Qu[i].correct_answer=fgetc(file);
        fgetc(file);
        fgetc(file);
        count++;
        i++;
    }

    fclose(file);
    return;
    // return num_questions;
}
int main() {
    loadQuestions();
    // // Assuming a maximum of 50 questions
    // int num_questions;

    // // Load questions from a file (replace 'quiz.txt' with your file name)
    // // num_questions = loadQuestions(questions, "quiz.txt");

    // if (num_questions == 0) {
    //     return 1;
    // }

    // // Get player's name
    char player_name[100];
    printf("Enter your name: ");
    gets(player_name);

    int score = 0;

    // Iterate through questions
    for (int i = 0; i < count; i++) {
        puts(Qu[i].question);
        for(int j=0;j<4;j++){
            puts(Qu[i].options[j]);
        }
        char temp;
        scanf(" %c",&temp);

        if (temp == Qu[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c\n",Qu[i].correct_answer);
        }
    }

    printf("\n%s's Final Score: %d/%d\n", player_name, score, count);
    // Save the player's score to score.txt
    FILE *score_file = fopen("score.txt", "a");
    if (score_file != NULL) {
        fprintf(score_file, "%s %d\n", player_name, score);
        fclose(score_file);
    }

    return 0;
}
