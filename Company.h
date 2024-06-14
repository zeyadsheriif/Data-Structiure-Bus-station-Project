#pragma once
#include <iostream>
#include <string>
#include "DS.h"
#include "Buses.h"
#include "Passenger.h"
#include <fstream>
#include "Stations.h"
#include "event.h"
#include <sstream>
#include "PriorityQueue.h"
#include "QueueAdt.h"
class Stations;

using namespace std;

class Company {

private:

    LinkedQueue<Buses> fwdBusQueue; //moving list
    LinkedQueue<Buses> bckBusQueue; //moving list 
    LinkedQueue<Buses> wbQueue; //checkuplist
    LinkedQueue<Buses> mbQueue; //checkuplist
    LinkedQueue<Buses> garageQueue; //station0
    Stations* stationList;
    LinkedQueue<Events> Eventlist;
    LinkedQueue<Buses> movingBusesQueue;
    LinkedQueue<LinkedQueue<Buses>*> checkupQueues;
    LinkedQueue<Buses> Completed;





    int i = 0;
    int eventCounter = 0;
    int stationNO;
    int TBStations; //time between stations
    int Wbuses;
    int Mbuses;
    int WbusesC; //capacity of wheel buses
    int MbusesC; //capacity of mixed buses
    int TBC; //number of trips before checkup
    int WCduration; //wheel buses checkup duration
    int MCduration; //mixed buses checkup duration
    int maxW;
    int NOevent; //number of events in the file
    int getOF; //get on/off time
    int PAT; //passenger arrival time
    int PID; //passenger id
    int Sstation;// start station
    int Estation; // end station
    string SPtype; //type of sp passenger 
    int Time;// maximum value = 23:59:59 24*60*60 - 1 =85399 less 
    // less than the maximum value for int

    struct variables {
        int num_stations;
        int timebetweenstations;
        int num_WBuses;
        int num_MBuses;
        int checkupdurationWBus;
        int checkupdurationMBus;
        int max_waiting_time;
        int get_on_off_time;
        int capacityWBus;
        int capacityMBus;
        int trips_before_checkup;

    };

    int TimeFromString(string stringTime, bool withSec);
    void MoveBusesFromCheckupToMoving();
    void busWaitingToMoving(Buses* bus, variables& eventvariables, Stations currentStation);
    void busWaitingToMoving(Buses* bus, variables& CapacityWBus , variables& CapacityMBus , variables& eventvariables, Stations currentStation);
    string TimeCalc(int time, bool withSec);
    void PrintingInfo();
    

public:
    void Simulatorfunction();
    void ReadInputFile();
    void StartTheDay();

};
