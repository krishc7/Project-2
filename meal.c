#include "meal.h"
#include <string.h>

enum meals {BREAK_FAST, LUNCH, DINNER};

float meal_eaten(int totalDays, float *excess, int carriedMeal[3]){
    int mealEaten[3];
    int allowedMeal[3] = {totalDays, totalDays, totalDays};
    int mealCost[] = {9,12,16};
    enum meals meal;

    float allowedCost = 0;
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
        //Factor depart and arrival meals if the bussisness person had more meals than allowed
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

    //Departure meals
    printf("Enter the time of departure (5:02 am): ");
    scanf("%d:%d %s",&depart_hour,&depart_min,time);
    if(depart_hour < 7  && (strcmp(time,"am") == 0)){
        meal = BREAK_FAST;
        carriedMeal[meal]++;
    }
    else if( (depart_hour >= 7 || depart_hour < 12) && (strcmp(time,"am") == 0) ){     
        meal = LUNCH;
        carriedMeal[meal]++;    

    }
    else if ((depart_hour < 6  || depart_hour == 12 ) && (strcmp(time,"pm") == 0)  ){
       meal = DINNER;
        carriedMeal[meal]++;
    }

    //Arrival meals 
    printf("Enter the time of arrival (11:20 pm) : ");
    scanf("%d:%d %s",&arrival_hour,&arrival_min,time);
     if((arrival_hour >= 8 && (strcmp(time,"am") == 0)) || (arrival_hour == 12 && (strcmp(time,"pm") == 0)) ){
        meal = BREAK_FAST;
        carriedMeal[meal]++;
    }
    else if( arrival_hour >= 1  && (strcmp(time,"pm") == 0) ){    
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


