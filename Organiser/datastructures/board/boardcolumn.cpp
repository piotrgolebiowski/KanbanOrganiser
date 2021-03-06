#include "boardcolumn.h"

BoardColumn::BoardColumn()
{

}

BoardColumn::BoardColumn(QString title)
{
	this->title = title;
}

bool BoardColumn::isEqual(const BoardColumn* other)
{
    if(this->title.compare(other->title) == 0
            && cards.size() == other->cards.size())
	{
		return true;
	}

	return false;
}

bool BoardColumn::IsNull()
{
	if(title.compare("") == 0 || title.isNull() || title.isEmpty())
	{
		return true;
	}

	return false;
}
