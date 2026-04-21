/*
Name: NAKANWAGI MARIAM
Registration Number: 25/U/BIE/01403/PE
*/

#include <stdio.h>

int main(void) {
    /* Declare variables here */

    // Semester I course codes and credit units
    char *sem1_codes[] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };
    int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};

    
    // Semester II course codes and credit units
    char *sem2_codes[] = {
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };
    int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

    // Arrays to store scores for both semesters
    int sem1_scores[8];
    int sem2_scores[8];

    // Arrays to store calculated grades and points
    char sem1_grades[8];
    int sem1_points[8];
    char sem2_grades[8];
    int sem2_points[8];

    // Variables for GPA and CGPA calculations
    int sem1_total_credits = 0;
    int sem1_weighted_points = 0;
    int sem2_total_credits = 0;
    int sem2_weighted_points = 0;
    float sem1_gpa, sem2_gpa, cgpa;

    // Variables for classification
    const char *classification;
    
    // Loop counters
    int i;

 

    /* Read 16 scores */

   // Read Semester I scores
    printf("=== SEMESTER I SCORES ===\n");
    for (i = 0; i < 8; i++) {
        printf("Enter score for %s: ", sem1_codes[i]);
        scanf("%d", &sem1_scores[i]);

    // Check if input is not an integer
        if (input_result != 1) {
            printf("Invalid score entered\n");
            return 1;
        }
    }
    
    
    // Read Semester II scores
    printf("\n=== SEMESTER II SCORES ===\n");
    for (i = 0; i < 8; i++) {
        printf("Enter score for %s: ", sem2_codes[i]);
        scanf("%d", &sem2_scores[i]);

       // Check if input is not an integer
        if (input_result != 1) {
            printf("Invalid score entered\n");
            return 1;
        }
    }


    /* Validate input */

  // Check Semester I scores
    for (i = 0; i < 8; i++) {
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }
    
    // Check Semester II scores
    for (i = 0; i < 8; i++) {
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }


 
  /* Determine grades and grade points */

 // Process Semester I grades and points
    for (i = 0; i < 8; i++) {
        int score = sem1_scores[i];
        int score_group;
        
        // Handle special case for score 100
        if (score == 100) {
            score_group = 10;
        } else {
            score_group = score / 10;
        }
        
        // Use switch to determine grade and point
        switch (score_group) {
            case 10:  // 100
            case 9:   // 90-99
            case 8:   // 80-89
                sem1_grades[i] = 'A';
                sem1_points[i] = 5;
                break;
            case 7:   // 70-79
                sem1_grades[i] = 'B';
                sem1_points[i] = 4;
                break;
            case 6:   // 60-69
                sem1_grades[i] = 'C';
                sem1_points[i] = 3;
                break;
            case 5:   // 50-59
                sem1_grades[i] = 'D';
                sem1_points[i] = 2;
                break;
            default:  // 0-49
                sem1_grades[i] = 'F';
                sem1_points[i] = 0;
                break;
        }
    }
    
    // Process Semester II grades and points
    for (i = 0; i < 8; i++) {
        int score = sem2_scores[i];
        int score_group;
        
        // Handle special case for score 100
        if (score == 100) {
            score_group = 10;
        } else {
            score_group = score / 10;
        }
        
        // Use switch to determine grade and point
        switch (score_group) {
            case 10:  // 100
            case 9:   // 90-99
            case 8:   // 80-89
                sem2_grades[i] = 'A';
                sem2_points[i] = 5;
                break;
            case 7:   // 70-79
                sem2_grades[i] = 'B';
                sem2_points[i] = 4;
                break;
            case 6:   // 60-69
                sem2_grades[i] = 'C';
                sem2_points[i] = 3;
                break;
            case 5:   // 50-59
                sem2_grades[i] = 'D';
                sem2_points[i] = 2;
                break;
            default:  // 0-49
                sem2_grades[i] = 'F';
                sem2_points[i] = 0;
                break;
        }
    }


    /* Compute Semester I GPA */


   for (i = 0; i < 8; i++) {
        sem1_total_credits += sem1_credits[i];
        sem1_weighted_points += sem1_points[i] * sem1_credits[i];
    }
    sem1_gpa = (float)sem1_weighted_points / sem1_total_credits;


    /* Compute Semester II GPA */

   for (i = 0; i < 8; i++) {
        sem2_total_credits += sem2_credits[i];
        sem2_weighted_points += sem2_points[i] * sem2_credits[i];
    }
    sem2_gpa = (float)sem2_weighted_points / sem2_total_credits;


    /* Compute CGPA */

int total_credits = sem1_total_credits + sem2_total_credits;
    int total_weighted_points = sem1_weighted_points + sem2_weighted_points;
    cgpa = (float)total_weighted_points / total_credits;


    /* Determine classification */

    // Convert CGPA to an integer code for switch statement
    int cgpa_code;
    if (cgpa >= 4.40f) {
        cgpa_code = 4;
    } else if (cgpa >= 3.60f) {
        cgpa_code = 3;
    } else if (cgpa >= 2.80f) {
        cgpa_code = 2;
    } else if (cgpa >= 2.00f) {
        cgpa_code = 1;
    } else {
        cgpa_code = 0;
    }
    
    // Use switch to assign classification
    switch (cgpa_code) {
        case 4:
            classification = "First Class";
            break;
        case 3:
            classification = "Second Class Upper";
            break;
        case 2:
            classification = "Second Class Lower";
            break;
        case 1:
            classification = "Pass";
            break;
        case 0:
            classification = "Fail";
            break;
        default:
            classification = "Fail";
            break;
    }



    /* Display full academic report */
printf("\n========================================\n");
    printf("         ACADEMIC REPORT\n");
    printf("========================================\n\n");
    
    // Display Semester I report
    printf("YEAR ONE - SEMESTER I\n");
    printf("------------------------------------------------------\n");
    printf("%-12s %-8s %-6s %-6s %-8s %-10s\n", 
           "Course", "Score", "Grade", "Point", "Credits", "Weighted");
    printf("------------------------------------------------------\n");
    
    for (i = 0; i < 8; i++) {
        int weighted = sem1_points[i] * sem1_credits[i];
        printf("%-12s %-8d %-6c %-6d %-8d %-10d\n",
               sem1_codes[i], sem1_scores[i], sem1_grades[i],
               sem1_points[i], sem1_credits[i], weighted);
    }
    printf("------------------------------------------------------\n");
    printf("TOTAL: %d Credits, %d Weighted Points\n\n", 
           sem1_total_credits, sem1_weighted_points);
    
    // Display Semester II report
    printf("YEAR ONE - SEMESTER II\n");
    printf("------------------------------------------------------\n");
    printf("%-12s %-8s %-6s %-6s %-8s %-10s\n", 
           "Course", "Score", "Grade", "Point", "Credits", "Weighted");
    printf("------------------------------------------------------\n");
    
    for (i = 0; i < 8; i++) {
        int weighted = sem2_points[i] * sem2_credits[i];
        printf("%-12s %-8d %-6c %-6d %-8d %-10d\n",
               sem2_codes[i], sem2_scores[i], sem2_grades[i],
               sem2_points[i], sem2_credits[i], weighted);
    }
    printf("------------------------------------------------------\n");
    printf("TOTAL: %d Credits, %d Weighted Points\n\n",
           sem2_total_credits, sem2_weighted_points);
    
    // Display overall summary
    printf("========================================\n");
    printf("         OVERALL SUMMARY\n");
    printf("========================================\n");
    printf("Total Credits Attempted: %d\n", total_credits);
    printf("Total Weighted Points: %d\n\n", total_weighted_points);
    
    // Required output format for autograding
    printf("Semester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    
    printf("\n========================================\n");

    return 0;
}


   

    
 