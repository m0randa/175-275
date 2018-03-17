//----------------------------------------------------------------------//

// Author:

// Net ID:

// Date:

//

//----------------------------------------------------------------------//



#include "GPSPosition.h"
#include <cmath>
using namespace std;

GPSPosition::GPSPosition(double latitude, double longitude, unsigned long timeSeconds){
    latitude = latitude/100;
    latitude = latitude+(latitude - (int)latitude)*(2.0/3);
    longitude = longitude /100;
    longitude = longitude+(longitude - (int)longitude)*(2.0/3);
    
        //Time given in 000000 format
        //where first two digits are hours, second two digits are minutes, and last two digits are seconds
    
    int sec2sec = timeSeconds%100;
    timeSeconds = timeSeconds/100;
    int min2sec = timeSeconds%100;
    timeSeconds = timeSeconds/100;
    min2sec = min2sec *60;
    int hr = timeSeconds*3600;
    timeSeconds = hr + min2sec +sec2sec;
    
    SetLatitude(latitude);
    SetLongitude(longitude);
    SetTime(timeSeconds);
    SetVel(0);
}
double GPSPosition::CalcDistanceKmTo(GPSPosition toPosition){
    const double EarthRadiusKm = 6371.0;
    const double PI = 3.14159265358979323846;
    double fromLatitudeRad;
    double fromLongitudeRad;
    double toLatitudeRad;
    double toLongitudeRad;
    double deltaLatitude;
    double deltaLongitude;
    double a;
    double c;
    
    // Convert to radians
    
    fromLatitudeRad = PI * this->GetLatitude() / 180.0;
    fromLongitudeRad = PI * this->GetLongitude() / 180.0;
    toLatitudeRad = PI * toPosition.GetLatitude() / 180.0;
    toLongitudeRad = PI * toPosition.GetLongitude() / 180.0;
    
    // Calculate delta for latitude and longitude
    deltaLatitude = toLatitudeRad - fromLatitudeRad;
    deltaLongitude = toLongitudeRad - fromLongitudeRad;
    
    // Calculate great-circle distance using haversine formula
    a = ( sin(deltaLatitude / 2) * sin(deltaLatitude / 2) ) + ( sin(deltaLongitude / 2) * sin(deltaLongitude / 2) * cos(fromLatitudeRad) * cos(toLatitudeRad) );
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EarthRadiusKm * c;
    
}

