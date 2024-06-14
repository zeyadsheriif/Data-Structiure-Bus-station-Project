#pragma once
#include <iostream>
#include <string>
#include "DS.h"
#include "Buses.h"
#include "Passenger.h"
#include "Company.h"
#include <sstream>
class Passenger;
using namespace std;

class Stations {
private:
    int passenger_count;
    int buses_count;
    int station_number;
    


    PriorityQueue<Passenger> FwaitingSP;
    PriorityQueue<Passenger> BwaitingSP;

    LinkedQueue<Passenger> FwaitingWP;
    LinkedQueue<Passenger> BwaitingWP;

    LinkedQueue<Passenger> FwaitingNP;
    LinkedQueue<Passenger> BwaitingNP;


    LinkedQueue<Buses> FWDBusList;
    LinkedQueue<Buses> BCKBusList;

    LinkedQueue<Passenger> FmovingP;
    LinkedQueue<Passenger> BmovingP;


public:



    void setPcount(int Pcount) {
        passenger_count = Pcount;
    }

    void setBcount(int Bcount) {
        buses_count = Bcount;
    }

    void setFwaitingWP(Passenger passenger) {
        FwaitingWP.enqueue(passenger);
    }

    void getFwaitingWP(Passenger passenger) {
        FwaitingWP.dequeue(passenger);
    }

    void setBwaitingWP(Passenger passenger) {
        FwaitingWP.enqueue(passenger);
    }

    void getBwaitingWP(Passenger passenger) {
        FwaitingWP.dequeue(passenger);
    }
    void setFmovingP(Passenger passenger) {
        FmovingP.enqueue(passenger);
    }


    void getFmovingP(Passenger passenger) {
        FmovingP.dequeue(passenger);
    }
    void setBmovingP(Passenger passenger) {
        BmovingP.enqueue(passenger);
    }


    void getBmovingP(Passenger passenger) {
        BmovingP.dequeue(passenger);
    }


    int getPcount() {
        return passenger_count;
    }
    int getBcount() {
        return buses_count;
    }
    int getSnum() {
        return station_number;
    }
};

