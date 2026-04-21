/*
Name: NAKANWAGI MARIAM
Registration Number: 25/U/BIE/01403/PE
*/

#include <stdio.h>

int main(void) {
    /* Declare variables here */

 char grades_sem1[8], grades_sem2[8];
 int  points_sem1[8], points_sem2[8];
float gpa_sem1, gpa_sem2, cgpa;


    /* Read 16 scores */

char *sem1_codes[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};

char *sem2_codes[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};
int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

 
int scores_sem1[8], scores_sem2[8];
int total_credits_sem1 =0, total_credits_sem2 = 0;
int weighted_points_sem1 = 0, weighted_points_sem2 = 0;
 
    /* Validate input */
 
 printf("--- Semester I ---\n");
for (int i = 0; i < 8; i++ ){
 printf("Enter score for %s ", sem1_codes[i]);

  if (scanf("%d", &scores_sem1[i]) != 1 || scores_sem1[i] < 0 || scores_sem1[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
        getGradeAndPoint(scores_sem1[i], &grades_sem1[i], &points_sem1[i]);
        total_credits_sem1 += sem1_credits[i];
        weighted_points_sem1 += points_sem1[i] * sem1_credits[i];
    }

    
    printf("\n--- Semester II ---\n");
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s: ", sem2_codes[i]);
        if (scanf("%d", &scores_sem2[i]) != 1 || scores_sem2[i] < 0 || scores_sem2[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
        getGradeAndPoint(scores_sem2[i], &grades_sem2[i], &points_sem2[i]);
        total_credits_sem2 += sem2_credits[i];
        weighted_points_sem2 += points_sem2[i] * sem2_credits[i];
    }


  /* Determine grades and grade points */


    if (score >= 80 && score <= 100) {
        *grade = 'A';
        *point = 5;
    } 
else if (score >= 70) {
        *grade = 'B';
        *point = 4;
    } 
else if (score >= 60) {
        *grade = 'C';
        *point = 3;
    }
 else if (score >= 50) {
        *grade = 'D';
        *point = 2;
    }
 else {
        *grade = 'F';
        *point = 0;
    }
}
    /* Compute Semester I GPA */


gpa_sem1 = (float)weighted_points_sem1 / total_credits_sem1;
    
    /* Compute Semester II GPA */

gpa_sem2 = (float)weighted_points_sem2 / total_credits_sem2;

    /* Compute CGPA */

(Total Credits Sem1 + Sem2)
    cgpa = (float)(weighted_points_sem1 +  weighted_points_sem2) /  (total_credits_sem1 + total_credits_sem2);

    /* Determine classification */


const char* getClassification(float cgpa) {
    if (cgpa >= 4.40f) return "First Class";
    if (cgpa >= 3.60f) return "Second Class Upper";
    if (cgpa >= 2.80f) return "Second Class Lower";
    if (cgpa >= 2.00f) return "Pass";
    return "Fail";
}

    /* Display full academic report */

printf("\n========== ACADEMIC REPORT ==========\n\n");

    
    printf("YEAR ONE SEMESTER I\n");
    printf("%-12s %-8s %-6s %-7s %-8s %-12s\n", 
           "Course", "Score", "Grade", "Point", "Credits", "Weighted");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        int weighted = points_sem1[i] * sem1_credits[i];
        printf("%-12s %-8d %-6c %-7d %-8d %-12d\n",
               sem1_codes[i], scores_sem1[i], grades_sem1[i], 
               points_sem1[i], sem1_credits[i], weighted);
    }
    printf("------------------------------------------------------------\n");
    printf("SEMESTER I TOTALS: %-3d Credits, %-4d Weighted Points\n\n", 
           total_credits_sem1, weighted_points_sem1);

    
    printf("YEAR ONE SEMESTER II\n");
    printf("%-12s %-8s %-6s %-7s %-8s %-12s\n", 
           "Course", "Score", "Grade", "Point", "Credits", "Weighted");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        int weighted = points_sem2[i] * sem2_credits[i];
        printf("%-12s %-8d %-6c %-7d %-8d %-12d\n",
               sem2_codes[i], scores_sem2[i], grades_sem2[i], 
               points_sem2[i], sem2_credits[i], weighted);
    }
    printf("------------------------------------------------------------\n");
    printf("SEMESTER II TOTALS: %-3d Credits, %-4d Weighted Points\n\n",
           total_credits_sem2, weighted_points_sem2);

    // Overall Totals
    int total_credits_all = total_credits_sem1 + total_credits_sem2;
    int total_weighted_all = weighted_points_sem1 + weighted_points_sem2;
    printf("OVERALL YEAR ONE TOTALS: %-3d Credits, %-4d Weighted Points\n\n",
           total_credits_all, total_weighted_all);

    // Required Summary Output (Must match exactly for autograding)
    printf("Semester I GPA: %.2f\n", gpa_sem1);
    printf("Semester II GPA: %.2f\n", gpa_sem2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", getClassification(cgpa));

    return 0;
}

    
 