#include <stdio.h>
#include <stdlib.h>
#include "AraboImplementation.c"
#include "park_taxi_hotel_fees.ces.c"
#include "meal.c"

int main() {

    int days;
    float airfare, carRentals, drivingFee, conference, mealCostsCovered;
    float parking, taxi, mealCost, *excessCost, hotelFees;
    float totalExpenses, totalAllowed, amtSaved;

    days = totalNumDaysOnTrip();

    mealCost = depart_arrival_time(days, excessCost);

    airfare = amountRoundTripAirfare();

    carRentals = amountCarRentals();

    drivingFee = milesDriven(carRentals);

    conference = conferenceFees(); 

    parking = parkingFees(days);

    taxi = taxiFees();

    hotelFees = hotelExpenses();

    totalExpenses = (mealCost + airfare + carRentals + drivingFee + conference + parking + taxi + hotelFees);

    totalAllowed = ((days * 6) + (days * 90) + (days * 10) + (mealCost - *excessCost));

    printf("\nTotal expenses for this trip: $%.2f", totalExpenses);
    printf("\nTotal allowed expenses for this trip: $%.2f", totalAllowed);

    if((totalExpenses - totalAllowed) > 0.0) 
    {
        amtSaved = totalAllowed - totalExpenses;
        printf("\nTotal excess cost to be reimbursed by businessperson: $%.2f", amtSaved);
    }
    else 
    {
        amtSaved = totalExpenses - totalAllowed;
        printf("\nTotal amount saved by the businessperson: $%.2f", amtSaved);
    }

    return 0;
}