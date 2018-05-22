#include "Value.h"

Value::Value(std::string word)
{
	this->word = word;
	prev = NULL;
}

Value::~Value()
{
	delete prev;
	//prev = NULL;
}


Value* Value::getPrev()
{
	return prev;
}

std::string Value::getText() const
{
	return word;
}