#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "Passenger.h"
#include "PriorityQueue.h"


class Buses
{
private:
    string BusesType;
    int capacity;
    int maintenanceTime;
    int tripsnum;
    PriorityQueue<Passenger*> passengers;
    string direction;
    int passnum;
    int journeys;
    int totalBusyTime;
    int totalTimeCapacity;



public:

    Buses();
    Buses(const string& type, int bC, int checkup, string dir, int passnumb);

    void setBusesType(const string& type);


    string getBusesType();
    void setdirection(const string& dir);

    string getdirection();
    void setCapacity(int bc);

    int getCapacity();
    int getJourneys() const;
    void setJourneys(int journeys);

    int getDifferenceStation(const Passenger* passenger);
    int getPassnum() const;
    void setPassnum(int passengerNumber);


    bool isForward();


    void setMaintenanceTime(int checkup);

    int getSPecialPriority(string specialtype);
    int getMaintenanceTime();
    void droppass(Passenger* passenger);
    void addpass(Passenger* passenger);
    void newBusyTime(int tripTime);
    double calculateBusUtilization() const;
};
