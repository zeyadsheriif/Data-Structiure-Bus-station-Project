#include "Buses.h"
#include "PriorityQueue.h"

Buses::Buses()
{

    BusesType = "";
    capacity = 0;
    maintenanceTime = 0;
    direction = "";
    passnum = 0;



}

Buses::Buses(const string& type, int bC, int checkup, string dir, int passnumb)
{
    BusesType = type;
    capacity = bC;
    maintenanceTime = checkup;
    direction = dir;
    passnum = passnumb;

}

void Buses::setBusesType(const string& type)
{
    BusesType = type;
}

string Buses::getBusesType()
{
    return BusesType;
}

void Buses::setdirection(const string& dir)
{
    direction = dir;
}

string Buses::getdirection()
{
    return direction;
}

void Buses::setCapacity(int bc)
{
    capacity = bc;
}

int Buses::getCapacity()
{
    return capacity;
}

int Buses::getJourneys() const
{
    return journeys;
}

void Buses::setJourneys(int journeys)
{
    journeys = journeys;
}



int Buses::getDifferenceStation(const Passenger* passenger)
{
    return abs(passenger->getEndStation() - passenger->getStartStation());
}

int Buses::getPassnum() const
{
    return passnum;
}

void Buses::setPassnum(int passengerNumber)
{
    passnum = passnum;
}

bool Buses::isForward()
{
    return direction == 0;
}


void Buses::setMaintenanceTime(int checkup)
{
    maintenanceTime = checkup;
}




int Buses::getSPecialPriority(string specialtype)
{
    if (specialtype == "Aged") {
        return 1;
    }
    else if (specialtype == "POD") {
        return 2;
    }
    else if (specialtype == "pregnant") {
        return 3;
    }
    else {
        return 0;
    }
}

int Buses::getMaintenanceTime()
{
    return maintenanceTime;
}




void Buses::droppass(Passenger* passenger)
{

    int priority = abs(passenger->getEndStation() - passenger->getStartStation());
    passengers.dequeuePQ();
    tripsnum--;

}

void Buses::addpass(Passenger* passenger)
{
    passengers.enqueuePQ(passenger);
    passnum++;
}

void Buses::newBusyTime(int tripTime)
{
    totalBusyTime += tripTime;
    totalTimeCapacity += tripTime * capacity;
}

double Buses::calculateBusUtilization() const
{
    if (totalBusyTime == 0) return 0;
    return static_cast<double>(totalTimeCapacity) / (totalBusyTime * capacity) * 100;
}


template class PriorityQueue<Buses*>;
