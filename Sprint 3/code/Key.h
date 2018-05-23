#ifndef KEY_H
#define KEY_H

#include "Value.h"

class Key
{
public:
    inline Key()
    {
        prevKey = NULL;
        valueTail = NULL;
        //key = "";
    }
    // post: Key is properly initialised, however the key value
    //       is illegal (empty)

    virtual ~Key();
    // post: recursively deletes all keys and values

    inline std::string getText() const
    {
        return key;
    }

    inline bool setText(std::string key)
    {
        if (key.length() >= 2)
        {
            this->key = key;
            return true;
        }
        return false;
    }

    void addValue(std::string word);
    // post: a new word is added to the correct key:
    //       - if the word fits in this key, a new value is added to the valuelist
    //       - if the word doesn't fit in this key, addValue is called on the next key
    //       - if no fitting key is found, a new key is made with this value in it

    inline Value* getValuePtr()
    {
        return valueTail;
    }

    inline void setValuePtr(Value* value)
    {
        valueTail = value;
    }

    inline void setPrev(Key* prev)
    {
        prevKey = prev;
    }

    inline Key* getPrev()
    {
        return prevKey;
    }

    inline void print() const
    {
        return;
    }


private:
    std::string key;
    Value* valueTail;
    Key* prevKey;

    // private copy constructor and assignment operator to prevent making copies
    Key(const Key&) { /* do nothing */ };
    Key& operator= (const Key&) { return *this; };
};

#endif
