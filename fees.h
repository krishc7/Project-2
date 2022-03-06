#ifndef ConfParkTaxiHotelFeesHeader_H

#define ConfParkTaxiHotelFeesHeader_H

float numOfdays;
float parkingFee,taxiFee; 

float conferenceFees(float seminarFees);
void parkingFees(float *parkFee, float numOfDays);
void taxiFees(const char vehicleType[], float *taxiFee, float numOfDays);

#endif