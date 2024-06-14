#pragma once
#include <iostream>
#include <string>
using namespace std;

class Events {
private:

    //A         SP              4:28        5           1           3           Pregnant
    //A         NP              4:7         1           3           1           NA
    //A         WP              5:3         12          3           2           NA
    //EventType PassengerType   ArrivalTime PassengerID StartStaion EndStation  SPType
    //L         NA              5:57        3           1           NA          NA
    string EventType;
    string PassengerType;
    int ArrivalTime;
    int PassengerID;
    int StartStaion;
    int EndStation;
    string SPType;
    /*
    priority table:
        np with max wait = 0
        aged = 1
        pod = 2
        pregnant = 3
        np = 4
    */
public:

    void setSPType(string spType) {
        SPType = spType;
    }

    void setEventType(string event) {
        EventType = event;
    }

    void setArrivalTime(int time) {
        ArrivalTime = time;
    }

    void setPassengerID(int id) {
        PassengerID = id;
    }

    void setStartStaion(int station) {
        StartStaion = station;
    }

    void setEndStation(int station) {
        EndStation = station;
    }

    void setPassengerType(string pt) {
        PassengerType = pt;
    }

    string getPassengerType() {
        return PassengerType;
    }


    int getEndStation() {
        return EndStation;
    }

    int getStartStaion() {
        return StartStaion;
    }

    int getPassengerID() {
        return PassengerID;
    }

    int getArrivalTime() {
        return ArrivalTime;
    }

    string getEventType() {
        return EventType;
    }

    string getSPType() {
        return SPType;
    }

};


