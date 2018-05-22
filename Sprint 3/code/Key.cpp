#include "Key.h"

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



void Key::addValue(std::string word)
{
	std::string tempstr = word.substr(0, 2);
	if (key == tempstr)
	{
		Value *temp = valueTail;
		valueTail = new Value(word);
		valueTail->setPrev(temp);
		return;
	}
	else if (prevKey)
	{
		prevKey->addValue(word);
		return;
	}
	Key *newKey = new Key();
	newKey->setText(word.substr(0, 2));
	newKey->valueTail = new Value(word);
	prevKey = newKey;
}

Value* Key::getValuePtr()
{
	return valueTail;
}

Key* Key::getPrev()
{
	return prevKey;
}

