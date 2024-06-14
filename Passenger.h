#pragma once
#include <iostream>
#include <string>
#include "DS.h"
#include <fstream>
#include <sstream>
using namespace std;

class Passenger {
private:
    int ArrivalTime;
    int OnTime;//the acutual time the passenger got in to the bus 
    int OffTime;
    int StartStation;
    int EndStation;
    int PassengerID;
    string PassengerType;
    string SPType;

public:

    void setStartStation(int station);


    void setEndStation(int station);


    void setArrivalTime(int time);

    void setOnTime(int time);

    void setOffTime(int time);

    void setPassengerID(int id);

    void setPassengerType(string type);

    void setSPType(string type);



    string getSPType();

    string getPassengerType();

    int getPassengerID();

    int getOffTime();

    int getOnTime();

    int getArrivalTime();

    int getEndStation();


    int getStartStation();


};
