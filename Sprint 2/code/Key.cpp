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
	Key* temp = this;
	while (temp != NULL)
	{
		if (temp->getText() == word.substr(0,1))
		{
			Value* value = new Value(word);;
			value->setPrev(temp->getValuePtr());
			temp->setValuePtr(value);
			return;
		}
		temp = temp->getPrev();
	}
	Key* key  = new Key();
	key->setText(word.substr(0,1));
	key->addValue(word);

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

Key* Key::getPrev()
{
	if (prevKey != NULL) return prevKey;
	return NULL;
}

