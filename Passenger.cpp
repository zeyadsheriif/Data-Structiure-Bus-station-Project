#pragma once
#include "Passenger.h"
using namespace std;

void Passenger::setStartStation(int station) {
    StartStation = station;
}


void Passenger::setEndStation(int station) {
    EndStation = station;
}


void Passenger::setArrivalTime(int time) {
    ArrivalTime = time;
}

void Passenger::setOnTime(int time) {
    OnTime = time;
}

void Passenger::setOffTime(int time) {
    OffTime = time;
}

void Passenger::setPassengerID(int id) {
    PassengerID = id;
}

void Passenger::setPassengerType(string type) {
    PassengerType = type;
}

void Passenger::setSPType(string type) {
    SPType = type;
}



string Passenger::getSPType() {
    return SPType;
}

string Passenger::getPassengerType() {
    return PassengerType;
}

int Passenger::getPassengerID() {
    return PassengerID;
}

int Passenger::getOffTime() {
    return OffTime;
}

int Passenger::getOnTime() {
    return OnTime;
}

int Passenger::getArrivalTime() {
    return ArrivalTime;
}

int Passenger::getEndStation() {
    return EndStation;
}


int Passenger::getStartStation() {
    return StartStation;
}
