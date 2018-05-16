#include "Key.h"
#include <string>

Key::Key()
{
	prevKey = NULL;
	valueTail = NULL;
	key = "";
}


Key::~Key()
{
	delete valueTail;
	//valueTail = NULL;
	delete prevKey;
	//prevKey = NULL;
}

std::string Key::getText() const
{
	return key;
}

bool Key::setText(std::string key)
{
	if (key.length() >= 2)
	{
		this->key = key;
		return true;
	}
	return false;
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
		return;
	}
	Value *value = new Value(word);
	Key *newKey = new Key();
	newKey->setText(word.substr(0, 2));
	newKey->prevKey = NULL;
	newKey->valueTail = value;
	prevKey = newKey;
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

void Key::print() const
{
	return;
}

void Key::setPrev(Key* prev)
{
	prevKey = prev;
}