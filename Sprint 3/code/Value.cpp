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

void Value::setText(std::string value)
{
	word = value;
}

std::string Value::getText() const
{
	return word;
}

Value* Value::getPrev()
{
	return prev;
}

void Value::setPrev(Value* prev)
{
	this->prev = prev;
}

void Value::print() const
{
	return;
}