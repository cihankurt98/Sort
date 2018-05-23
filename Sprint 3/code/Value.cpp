#include "Value.h"

Value::~Value()
{
	delete prev;
	//prev = NULL;
}
