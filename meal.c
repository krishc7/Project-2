#include "meal.h"
#include <string.h>

enum meals {BREAK_FAST, LUNCH, DINNER};

float meal_eaten(int totalDays, float *excess, int carriedMeal[3]){
    int mealEaten[3];
    int allowedMeal = totalDays;
    int mealCost[] = {9,12,16};
    enum meals meal;

    float totalCost = 0;
    float actualCost = 0;
    float excessMeal = 0;


    printf("Enter the total breakfast: ");
    meal = BREAK_FAST;
    scanf("%d", &mealEaten[meal]);
    printf("Enter the total lunch    : ");
    meal= LUNCH;
    scanf("%d", &mealEaten[meal]);
    printf("Enter the total dinner   : ");
    meal = DINNER;
    scanf("%d", &mealEaten[meal]);

    for(meal = BREAK_FAST; meal <= DINNER; meal++){
        actualCost += mealEaten[meal] * mealCost[meal];
        totalCost += allowedMeal * mealCost[meal];
        excessMeal += carriedMeal[meal] * mealCost[meal]; //Testing only
    }

    printf("Actual: %.2f\tTotal:%.2f\tExcess:%.2f\n", actualCost, totalCost, excessMeal); //Testing only
    *excess += actualCost + excessMeal - totalCost;

    return actualCost;

}

float depart_arrival_time(int totalDays, float *excess){
    int depart_hour, depart_min,arrival_hour, arrival_min;
    char time[2];
    int carriedMeal[3] = {0,0,0};
    float totalCost = 0;

    enum meals meal;

    //Departure meals
    printf("Enter the time of departure: ");
    scanf("%d:%d %s",&depart_hour,&depart_min,time);
    if(depart_hour >= 7  && (strcmp(time,"am") == 0)){
        meal = BREAK_FAST;
        carriedMeal[meal]--;
    }
    else if( (depart_hour < 6 || depart_hour == 12) && (strcmp(time,"pm") == 0) ){     
        meal = LUNCH;
        carriedMeal[meal]--;    

    }
    else if (depart_hour >=6  && (strcmp(time,"pm") == 0) && depart_hour != 12 ){
       meal = DINNER;
        carriedMeal[meal]--;
    }

    //Arrival meals 
    printf("\nEnter the time of arrival: ");
    scanf("%d:%d %s",&arrival_hour,&arrival_min,time);
     if(arrival_hour >= 8 && (strcmp(time,"am") == 0)){
        meal = BREAK_FAST;
        carriedMeal[meal]--;
     
    }
    else if( arrival_hour >= 1  && (strcmp(time,"pm") == 0) ){    
        meal = LUNCH;
        carriedMeal[meal]--;  
    }
    else if (arrival_hour >= 7  && (strcmp(time,"pm") == 0)){
       meal = DINNER;
        carriedMeal[meal]--;
    }

    /*Testign carrying meals
    for(int i = 0; i < 3; i++){
        printf("%d",carriedMeal[i]);
    }
    printf("\n");

    */

    totalCost = (float) meal_eaten(totalDays, excess, carriedMeal);
    
    return totalCost; 
}


