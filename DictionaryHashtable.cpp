/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 12, 2016
 * Overview: this file is to implement the functionality of DictionaryHashtable
 * Assignment number: PA3
 */

#include "util.hpp"
#include "DictionaryHashtable.hpp"

/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 12, 2016
 * Overview: this file is to implement the functionality of DictionaryHashtable
 * Assignment number: PA3
 */

#include "util.hpp"
#include "DictionaryHashtable.hpp"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
    return (myDictionary.insert(word).second);
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
    return (myDictionary.find(word) != myDictionary.end());
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable()
{
    myDictionary.clear(); 
}
