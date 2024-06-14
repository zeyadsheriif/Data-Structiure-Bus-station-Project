#include "company.h"

void Company::Simulatorfunction()
{
    ReadInputFile();
    //PrintingInfo();
    StartTheDay();

}

void Company::ReadInputFile()
{

    string line;
    string word;
    int number;
    Events* el;
    // Read data from the text document
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file: input.txt" << endl;
        return;
    }

    while (getline(inputFile, line)) {

        stringstream lineStream(line);
        Buses* bus;
        int k;
        int toggle = 0;
        //cout << line << endl;
        switch (i) {
        case 0: // # of stations  - time between stations

            getline(lineStream, word, ' ');
            stationNO = stoi(word, 0, 10);
            stationList = new Stations[stationNO];
            getline(lineStream, word, ' ');
            TBStations = stoi(word, 0, 10);
            break;

        case 1: // # of Wbuses - # of Mbuses

            getline(lineStream, word, ' ');
            Wbuses = stoi(word, 0, 10);
            getline(lineStream, word, ' ');
            Mbuses = stoi(word, 0, 10);
            for (k = 0; k < (Wbuses + Mbuses); k++) {
                bus = new Buses();
                if (toggle && (k <= Wbuses * 2)) {
                    bus->setBusesType("W");
                    toggle = 0;
                }
                else if (k < Mbuses * 2) {
                    toggle = 1;
                    bus->setBusesType("M");
                }
                else {
                    bus->setBusesType("W");
                }
                garageQueue.enqueue(*bus);
            }


            break;
        case 2: // # of Wbuses cap  - # of Mbus cap

            getline(lineStream, word, ' ');
            WbusesC = stoi(word, 0, 10);
            getline(lineStream, word, ' ');
            MbusesC = stoi(word, 0, 10);
            break;

        case 3: //# of trips before checkup - WBus time - MBus time

            getline(lineStream, word, ' ');
            TBC = stoi(word, 0, 10);
            getline(lineStream, word, ' ');
            WCduration = stoi(word, 0, 10);
            getline(lineStream, word, ' ');
            MCduration = stoi(word, 0, 10);
            break;

        case 4: // maxW - getOff on time 

            getline(lineStream, word, ' ');
            maxW = stoi(word, 0, 10);
            getline(lineStream, word, ' ');
            getOF = stoi(word, 0, 10);
            break;
        case 5: // number of events

            getline(lineStream, word, ' ');
            NOevent = stoi(word, 0, 10);
            break;
        default:

            el = new Events();
            getline(lineStream, word, ' ');//EventType
            el->setEventType(word);
            if (word.compare("L") == 0) {
                el->setPassengerType("NA");//not aplicable 
                el->setSPType("NA");//not aplicable 
                el->setEndStation(0);
                getline(lineStream, word, ' ');//ArrivalTime
                el->setArrivalTime(TimeFromString(word, 0));
                getline(lineStream, word, ' ');//PassengerID
                el->setPassengerID(stoi(word, 0, 10));
                getline(lineStream, word, ' ');//StartStaion
                el->setStartStaion(stoi(word, 0, 10));
            }
            else if (word.compare("A") == 0) {
                getline(lineStream, word, ' ');//PassengerType
                el->setPassengerType(word);
                getline(lineStream, word, ' ');//ArrivalTime
                el->setArrivalTime(TimeFromString(word, 0));
                getline(lineStream, word, ' ');//PassengerID
                el->setPassengerID(stoi(word, 0, 10));
                getline(lineStream, word, ' ');//StartStaion
                el->setStartStaion(stoi(word, 0, 10));
                getline(lineStream, word, ' ');//EndStation
                el->setEndStation(stoi(word, 0, 10));
                if (el->getPassengerType().compare("SP") == 0) {
                    getline(lineStream, word, ' ');
                    el->setSPType(word);
                }
                else {
                    el->setSPType("NA");
                }

            }
            Eventlist.enqueue(*el);
            break;

        }
        i++;
    }


    inputFile.close();
}

void Company::StartTheDay()
{
    int Min;
    int hr;
    int Time_betwwen_stations;
    Events tmpEl;
    Stations* st;
    Passenger* pas;
    Buses bus;
    int time = 0;
    int timeDequeueGarage = 900;
    Time = 0;
    Eventlist.dequeue(tmpEl);
    while (Time < 86400)
    {

        //time = tmpEl.getTime();
        Time++;
        if (Time > 14400/*04:00*/ && Time < 79200/*22:00*/) {
            //handeling garage
            if ((Time % timeDequeueGarage/*00:15*/) == 0 && !garageQueue.isEmpty()) {
                cout << "dequeue a bus @ " << TimeCalc(Time, 1) << endl;
                garageQueue.dequeue(bus);
                if (garageQueue.isEmpty()) {
                    timeDequeueGarage = 1;
                }
            }

            // handling events;
            if (Time == tmpEl.getArrivalTime()) {
                cout << "A passenger arrived @ " << TimeCalc(Time, 1)
                    << " PassengerID " << tmpEl.getPassengerID()
                    << " StartSattion " << tmpEl.getStartStaion()
                    << endl;
                pas = new Passenger();
                pas->setStartStation(tmpEl.getStartStaion());
                pas->setEndStation(tmpEl.getEndStation());
                pas->setPassengerID(tmpEl.getPassengerID());
                pas->setArrivalTime(tmpEl.getArrivalTime());
                pas->setPassengerType(tmpEl.getPassengerType());
                pas->setSPType(tmpEl.getSPType());
                //stationList[tmpEl.getStartStaion()].setFwaitingWP(*pas);
                //stationList[tmpEl.getStartStaion()];
            }
            if (Time == TimeFromString("8:02", 0))
            {
                cout << "enqueue a bus @ " << TimeCalc(Time, 1) << endl;
                garageQueue.enqueue(bus);
                cout << "enqueu bus" << endl;
            }
            //if ((Time - event.arival_to_station_time) % Time_betwwen_stations == 0) {
                 //deque_bus from station
                 // enqueue in teh next one
             //}
        }

        //if (Time % 60 == 0) {
           // cout << "a minute passed " << endl;
        //}
    }

}


string Company::TimeCalc(int time, bool withSec)
{
    int tmpSec;
    int tmpMin;
    int tmpHr;
    tmpSec = time % 60;
    tmpMin = ((time % 3600) - tmpSec) / 60;
    tmpHr = ((time - tmpSec) - (tmpMin * 60)) / 3600;
    if (withSec)
        return to_string(tmpHr) + ":" + to_string(tmpMin) + ":" + to_string(tmpSec);
    else
        return to_string(tmpHr) + ":" + to_string(tmpMin);

}

void Company::PrintingInfo() {
    Events tmpEl;
    Buses bus;
    int i = 0;
    while (i < (Wbuses + Mbuses)) {
        Eventlist.dequeue(tmpEl);
        //"--------------"
        //cout << "type"<<tmpEl.getEventType()<<endl;
        //cout << "time"<<tmpEl.getTime()<<endl;
        i++;
        garageQueue.dequeue(bus);
        //cout << "bus type " << bus.getBusesType() << ", i = " << i <<  endl;

    }

    cout << "time: " << TimeFromString("4:0", 0) << endl;
    cout << "time: " << TimeFromString("04:0", 0) << endl;
    cout << "time: " << TimeFromString("22:0", 0) << endl;
    cout << "time: " << TimeFromString("5:50", 0) << endl;
    cout << "time: " << TimeFromString("5:70", 0) << endl;

}

int Company::TimeFromString(string stringTime, bool withSec) {
    stringstream lineStream(stringTime);
    string timeword;
    getline(lineStream, timeword, ':');
    int PAThour;
    int PATmin;
    int PATsec;
    PAThour = stoi(timeword, 0, 10) * 60 * 60;
    getline(lineStream, timeword, ':');
    PATmin = stoi(timeword, 0, 10) * 60;
    if (withSec) {
        getline(lineStream, timeword, ':');
        PATsec = stoi(timeword, 0, 10);
        return PAThour + PATmin + PATsec;
    }
    return PAThour + PATmin;
}

void Company::MoveBusesFromCheckupToMoving()
{
    if (!checkupQueues.empty())
    {
        LinkedQueue<Buses>* checkupQueuePtr = checkupQueues.front();

        Buses checkupBus;
        if (!checkupQueuePtr->isEmpty())
        {
            checkupQueuePtr->dequeue(checkupBus);
            movingBusesQueue.enqueue(checkupBus);
            cout << "Bus completed checkup and moved to the moving buses queue." << endl;
        }
        else
        {
            cout << "No buses in the checkup queue to move." << endl;
        }

        checkupQueues.dequeue();
        delete checkupQueuePtr; 
    }
    else
    {
        cout << "No checkup queues available." << endl;
    }
}


void Company::busWaitingToMoving(Buses* bus, variables& eventvariables, Stations currentStation) {


    if ((currentStation.getFmovingP().isEmpty() || currentStation.getBmovingP().isEmpty() &&
        bus->getBusesType() == "MB" && bus->getCapacity() == eventvariables.capacityMBus{

        if (bus->isForward()) {
            FmovingP.enqueue(bus);
        }
        else {
            BmovingP.enqueue(bus);
        }
        }


    else if ((currentStation.getBwaitingWP().isEmpty() || currentStation.getFwaitingWP().isEmpty()) &&
        bus->getBusType() == "WB" && bus->getCapacity() == eventvariables.capacityMBus) {

        if (bus->isForward()) {
            FwaitingWP.enqueue(bus);
        }
        else {
            BwaitingWP.enqueue(bus);
        }
    }
}
