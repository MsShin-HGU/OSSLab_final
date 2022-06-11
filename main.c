#include <stdio.h>
#include <string.h>
#include<stdlib.h>

const int NUMBER_OF_GRADES = 9;
const char* GRADES[9] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
const int SCORES[9] = {95, 90, 85, 80, 75, 70, 65, 60, 0};

void showTable(void);
char* getGrade(int score);

void absol_eval();
void relat_eval();
void total_grade();

int main() {
  showTable();
  
  int sel;
  while(1){
    printf("------------------------------------------------\n");
    printf("Grade Calculator\n");
    printf("1. Absolute evaluation\n2. Relative evaluation\n3. The grades of the semester\n4. Termination\n");
    printf("------------------------------------------------\n");
    scanf("%d", &sel);

    if (sel == 1) {
      absol_eval();
      continue;
    }
    if (sel == 2) {
    
    }
    if (sel == 3) {
      total_grade();
    }
    if(sel == 4){
      printf("Terminated.");
      break;
    }
    
  }
  
  return 0;
  }
  

void absol_eval(){
  int score, data;
    char grade;

    printf("Calculate your grade!\n\n");
    printf("Enter your score : ");
    scanf("%d", &score);

    if (score > 100 || score < 0) {
        printf("Entered an incorrect score.\n");
        printf("Enter a score between 0 and 100.");
    }
    else {

        data = score / 10;

        switch(data){
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
        }
        printf("\nYour grade is %c. \n", grade);
    }
}

void total_grade(){
  int sub;
  char grade[100] = "";
  double total = 0;
  
  printf("Enter the number of subjects.");
  scanf("%d", &sub);
  for(int i=0; i<sub; i++){
    printf("Enter the number of %d subjects. ", i+1);
    scanf("%s", &grade);
    if(strcmp(grade, GRADES[0]) == 0){
      total = total + 4.5;
    }
    else if(strcmp(grade, GRADES[1]) == 0){
      total = total + 4.0;
    }
    else if(strcmp(grade, GRADES[2]) == 0){
      total = total + 3.5;
    }
    else if(strcmp(grade, GRADES[3]) == 0){
      total = total + 3.0;
    }
    else if(strcmp(grade, GRADES[4]) == 0){
      total = total + 2.5;
    }
    else if(strcmp(grade, GRADES[5]) == 0){
      total = total + 2.0;
    }
    else if(strcmp(grade, GRADES[6]) == 0){
      total = total + 1.5;
    }
    else if(strcmp(grade, GRADES[7]) == 0){
      total = total + 1.0;
    }
    else if(strcmp(grade, GRADES[8]) == 0){
      total = total + 0.0;
    }
    else {
      printf("Enter it incorrectly.\n");
      continue;
    }
  }

  double avg = total/sub;
  printf("Your grades in this semester is %.2f.\n", avg);
}

void showTable(void) {
    printf("[Grade Table]\n");
    printf("┌───────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│Score\t");
    for(int i = 0 ; i < NUMBER_OF_GRADES; i++) {
        printf("│%d\t", SCORES[i]);
    }
    printf("│\n├───────────────────────────────────────────────────────────────────────────────┤\n");
    printf("│Grade\t");
    for(int i = 0 ; i < NUMBER_OF_GRADES; i++) {
        printf("│%s\t", GRADES[i]);
    }
    printf("│\n");
    printf("└───────────────────────────────────────────────────────────────────────────────┘\n\n");
}

