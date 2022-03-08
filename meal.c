#include "meal.h"
#include <string.h>

enum meals {BREAK_FAST, LUNCH, DINNER};

float meal_eaten(int totalDays, float *excess, int carriedMeal[3]){
    int mealEaten[3];
    int allowedMeal[3] = {totalDays, totalDays, totalDays};
    int mealCost[] = {9,12,16};
    char *mealName[] = {"breakfast", "lunch", "dinner"};
    enum meals meal;

    float allowedCost = 0;
    float actualCost = 0;
    float excessMeal = 0;

    for(meal = BREAK_FAST; meal <= DINNER; meal++){
        printf("Enter the total %s: ",mealName[meal]);
        scanf("%d", &mealEaten[meal]);
        if(mealEaten[meal] < 0){
            printf("Number of meals cannot be negative!\n");
            meal--;
        }

    }


    for(meal = BREAK_FAST; meal <= DINNER; meal++){
        //Factor depart and arrival meals to the allowed meals
        allowedMeal[meal] += carriedMeal[meal];
        actualCost += mealEaten[meal] * mealCost[meal];
        allowedCost += allowedMeal[meal] * mealCost[meal];
        
    }

    //printf("Actual: %.2f\tAllowed:%.2f\n", actualCost, allowedCost); //Testing only
    //If excess < 0 => Saved for the bussiness
    *excess = actualCost - allowedCost;
    
    return actualCost;

}

float depart_arrival_time(int totalDays, float *excess){
    int depart_hour, depart_min,arrival_hour, arrival_min;
    char time[2];
    int carriedMeal[3] = {0,0,0};
    float totalCost = 0;

    enum meals meal;

    //INPUT VALIDATION: Use FOR instead of WHILE to avoid having to flush the input buffer
    for (int cond = 0; cond < 1; cond++){
        printf("Enter the time of departure (example: 5:02 am): ");
        scanf("%d:%d %s",&depart_hour,&depart_min,time);
        if ((strcmp(time,"am") == 0) || (strcmp(time,"pm") == 0)){
            if ( depart_hour >= 1 && depart_hour <= 12) {
                if ( depart_min >= 0 && depart_min <= 59) {  
                    break;
                }
            }
        }
        
        printf("Invalid time!\n");
        cond--;
        
    }


    if(depart_hour < 7  && (strcmp(time,"am") == 0)){
        meal = BREAK_FAST;
        carriedMeal[meal]++;
    }
    else if( (depart_hour >= 7 && depart_hour < 12) && (strcmp(time,"am") == 0) ){     
        meal = LUNCH;
        carriedMeal[meal]++;    

    }
    else if ((depart_hour < 6  || depart_hour == 12 ) && (strcmp(time,"pm") == 0)  ){
       meal = DINNER;
        carriedMeal[meal]++;
    }

    //Arrival meals and input validation

    for (int cond = 0; cond < 1; cond++){
        printf("Enter the time of arrival (example: 11:20 pm) : ");
        scanf("%d:%d %s",&arrival_hour,&arrival_min,time);
         if ((strcmp(time,"am") == 0) || (strcmp(time,"pm") == 0)){
            if ( arrival_hour >= 1 && arrival_hour <= 12) {
                if ( arrival_min >= 0 && arrival_min <= 59) {  
                    break;
                }
            }
        }
        
        printf("Invalid time!\n");
        cond--;
    }

     if((arrival_hour >= 8 && (strcmp(time,"am") == 0)) || (arrival_hour == 12 && (strcmp(time,"pm") == 0)) ){
        meal = BREAK_FAST;
        carriedMeal[meal]++;
    }
    else if( arrival_hour >= 1 && arrival_hour < 7  && (strcmp(time,"pm") == 0)){    
        meal = LUNCH;
        carriedMeal[meal]++;  
    }
    else if (arrival_hour >= 7  && (strcmp(time,"pm") == 0)){
        meal = DINNER;
        carriedMeal[meal]++;
    }

    /*testign carrying meals
    for(int i = 0; i < 3; i++){
        printf("%d",carriedMeal[i]);
    }
    printf("\n");
    */
    

    

    totalCost = (float) meal_eaten(totalDays, excess, carriedMeal);
    
    return totalCost; 
}


