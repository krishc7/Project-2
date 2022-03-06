#include "AraboH_header.h"

int totalNumDaysOnTrip ()
{
    do
    {
        printf("Please enter total number of days the person spent on their trip: ");
        scanf("%d", totalDays);

        if (totalDays < 1)
        {
            printf("Invalid input. Total number of days must be more than 0.")
        }
    } while (totalDays < 1);
    
    return totalDays;
}

float amountRoundTripAirfare()
{
    do
    {
        printf("Please enter the amount of round-trip airfar: $");
        scanf("%f", dollarAirfare);
    } while (!dollarMileValidation(dollarAirfare));

    return dollarAirfare;
}

float amountCarRentals()
{
    do
    {
        printf("Please enter the amount of car rentals: $");
        scanf("%f", dollarCarRental);
    } while (!dollarMileValidation(dollarCarRental));

    return dollarCarRental;
}

void milesDriven()
{
    int miles;

    do
    {
        if (dollarCarRental == 0)
        {
            printf("Please enter the amount of miles driven: ");
            scanf("%d", miles);
        }
    } while (!dollarMileValidation(miles));

    privateMileExpense = privateMileExpense * 0.27;
}

bool dollarMileValidation(float cDollarMile)
{
    if (cDollarMile < 0)
    {
        printf("Invalid input. Negative numbers are not allowed.");
        return false;
    }
}