// Take excess by reference

# include<string.h>
# include <stdio.h>

float conferenceFees(float seminarFees)
{
    return seminarFees;
}

void parkingFees(float *parkFee, float numOfDays)
{
    for (float i = 0; i < numOfDays; i++)
    {
        *parkFee = *parkFee - 6.0;
    }
//    return *parkFee;
}

void taxiFees(const char vehicleType[], float *taxiFee, float numOfDays)
{
    const char typeTaxi[] = "Taxi";
    int comparison = strcmp(vehicleType, typeTaxi);
//    printf("%d", comparison);
    if (comparison == 0)
    {
        printf("\nTaxi was used");
        for (float i = 0; i < numOfDays; i++)
        {
            *taxiFee = *taxiFee - 10.0;
        }
    }
    else
        printf("\nTaxi was not used");
}

void hotelFees(float *hotelFee, float numOfDays)
{
    for (float i = 0; i < numOfDays; i++)
    {
        *hotelFee = *hotelFee - 90.0;
    }
}

int main(int argc, char *argv[]) {

   float b =  45.00;
   printf("%f", conferenceFees(b));


 
   float c = 2.0;
   float d = 14.0;
   printf("\n");
   printf("after parking fees for %f days and %f cost", c, d);
   parkingFees(&d, c);
   printf("\n");
   printf("after parking fees for %f days and %f cost", c, d);

   const char taxiConfirmation[] = "Taxi";
   float days = 2.0;
   float taxiFare = 24.0;
   printf("\n");
   printf("%s: after taxi fees for %f days and %f cost", taxiConfirmation, days, taxiFare);
   taxiFees(taxiConfirmation, &taxiFare, days);
   printf("\n");
   printf("%s: after taxi fees for %f days and %f cost", taxiConfirmation, days, taxiFare);
   taxiFees(taxiConfirmation, &taxiFare, days);

   float hotelDays = 3.0;
   float hotelFare = 300.0;
   printf("\n");
   printf("after hotel fees for %f days and %f cost", hotelDays, hotelFare);
   hotelFees(&hotelFare, hotelDays);
   printf("\n");
   printf("after hotel fees for %f days and %f cost", hotelDays, hotelFare);



}
