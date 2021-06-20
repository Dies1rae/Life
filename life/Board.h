#pragma once
#include "Evolution.h"

class Board {
	Board();
	Board(Evolution& evol) : petri_(evol){}
	~Board(){}

private:
	//time neded in sec
	Evolution& petri_;
};

