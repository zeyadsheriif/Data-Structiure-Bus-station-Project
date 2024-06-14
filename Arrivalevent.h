#pragma once
#include"event.h"

class Arrivalevent : public Events
{
private:
	int endstation;
	int ptype;
public:
	int setend(int end);
	void getend();
	void setptype();
};

