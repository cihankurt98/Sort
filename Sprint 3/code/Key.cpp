#include "Key.h"


Key::~Key()
{
	delete valueTail;
	//valueTail = NULL;
	delete prevKey;
	//prevKey = NULL;
}

void Key::addValue(const std::string& word)
{
	if (key == word.substr(0, 2))
	{
		Value *temp = valueTail;
		valueTail = new Value(word);
		valueTail->setPrev(temp);
		return;
	}
	if (prevKey)
	{
		prevKey->addValue(word);
		return;
	}
	prevKey = new Key();
	prevKey->setText(word.substr(0, 2));
	prevKey->valueTail = new Value(word);
}



