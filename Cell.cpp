#include "Cell.h"

using namespace std;

Cell::Cell(string i, int w)
{
	id = i;
	weight = w;
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