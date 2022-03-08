// Take excess by reference
#include "fees.h"
#include <stdio.h>
#include <stdbool.h>

bool check(float cDollarMile)
{
    float checker = 0.0;
    if (cDollarMile < checker)
    {
        printf("Invalid input. Negative numbers are not allowed.\n");
        return false;
    }
    else
    {
        return true;
    }
}

float conferenceFees()
{
    float seminarFees;
    do
    {
        printf("Please enter your conference fees: $");
        scanf("%f", &seminarFees);
    } while (!check(seminarFees));
    return seminarFees;
}

float parkingFees(int numOfDays)
{
    float parkFee;
    do
    {
        printf("Please enter your parking fees: $");
        scanf("%f", &parkFee);
    } while (!check(parkFee));
    return parkFee;
}

float taxiFees()
{
    float taxiCost;
    int numDays;
    do
    {
        printf("Please enter your taxi fares: $");
        scanf("%f", &taxiCost);   
    } while (!check(taxiCost));
    return taxiCost;
}
