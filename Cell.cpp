#include "Cell.h"

using namespace std;

Cell::Cell()
{
	id = "error-default";
	weight = 0;
	r = 0;
	c = 0;
}

Cell::Cell(string i, int w, int x, int y)
{
	id = i;
	weight = w;
	r = x;
	c = y;
}

string Cell::getId()
{
	return id;
}

void Cell::setId(string i)
{
	id = i;
}

int Cell::getWeight()
{
	return weight;
}

void Cell::setWeight(int w)
{
	weight = w;
}

int Cell::getR()
{
	return r;
}

void Cell::setR(int x)
{
	r = x;
}

int Cell::getC()
{
	return c;
}

void Cell::setC(int y)
{
	c = y;
}
