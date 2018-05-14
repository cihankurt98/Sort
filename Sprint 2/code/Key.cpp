#include "Key.h"

Key::Key()
{

}

Key::~Key()
{
	delete valueTail;
	valueTail = NULL;
	delete prevKey;
	prevKey = NULL;
}

std::string Key::getText() const
{
	return key;
}

void Key::addValue(std::string word)
{

}

Value* Key::getValuePtr()
{
	return valueTail;
}

void Key::setValuePtr(Value* value)
{
	value->setPrev(valueTail);
	valueTail = value;
}

