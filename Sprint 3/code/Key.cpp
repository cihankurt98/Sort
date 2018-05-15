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
	if (key == word.substr(0, 2))
	{
		Value* value = new Value(word);;
		value->setPrev(valueTail);
		valueTail = value;
		return;
	}
	else if (prevKey != NULL)
	{
		prevKey->addValue(word);
	}
	else
	{
		Value *value = new Value(word);
		Key *newKey = new Key();
		newKey->setText(word.substr(0, 2));
		newKey->prevKey = NULL;
		newKey->valueTail = value;
		prevKey = newKey;
	}
}

Value* Key::getValuePtr()
{
	return valueTail;
}

void Key::setValuePtr(Value* value)
{
	valueTail = value;
}

Key* Key::getPrev()
{
	return prevKey;
}

