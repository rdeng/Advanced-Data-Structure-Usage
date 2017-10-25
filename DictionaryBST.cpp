/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 12, 2016
 * Overview: this file is to implement the functionality of DictionaryBST
 * Assignment number: PA3
 */

#include "util.hpp"
#include "DictionaryBST.hpp"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
    return (myDictionaryBST.insert(word).second);
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
    return (myDictionaryBST.find(word) != myDictionaryBST.end());
}

/* Destructor */
DictionaryBST::~DictionaryBST()
{
    myDictionaryBST.clear();
}


