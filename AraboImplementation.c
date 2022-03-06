#include "AraboHeader.h"

int totalNumDaysOnTrip()
{
    int totalDays;

    do
    {
        printf("Please enter total number of days the person spent on their trip: ");
        scanf("%d", &totalDays);

        if (totalDays < 1)
        {
            printf("Invalid input. Total number of days must be more than 0.\n");
        }
    } while (totalDays < 1);

    return totalDays;
}

float amountRoundTripAirfare()
{
    float dollarAirfare;

    do
    {
        printf("Please enter the amount of round-trip airfar: $");
        scanf("%f", &dollarAirfare);
    } while (!dollarMileValidation(dollarAirfare));

    return dollarAirfare;
}

float amountCarRentals()
{
    float dollarCarRental;

    do
    {
        printf("Please enter the amount of car rentals: $");
        scanf("%f", &dollarCarRental);
    } while (!dollarMileValidation(dollarCarRental));

    return dollarCarRental;
}

float milesDriven(float cDollarCarRental)
{
    float miles;

    do
    {
        printf("Please enter the amount of miles driven: ");
        scanf("%d", &miles);
    } while (!dollarMileValidation(miles));

    if (cDollarCarRental == 0)
    {
        return miles * 0.27;
    }
    else
    {
        return 0;
    }
}

bool dollarMileValidation(float cDollarMile)
{
    if (cDollarMile < 0)
    {
        printf("Invalid input. Negative numbers are not allowed.\n");
        return false;
    }
    else
    {
        return true;
    }
}