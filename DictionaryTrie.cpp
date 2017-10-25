/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 18, 2016
 * Overview: this file is to implement the functionality of DictionaryTrie
 * Assignment number: PA3
 */

#include "util.hpp"
#include "DictionaryTrie.hpp"
#include <string>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie()
{
    //initialize a root
    root = new TrieNode();
}

/**
 * Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) 
 */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    //if empty string, invalid so return false
    if(word.length() == 0)
    {
        return false;
    }

    //if the word is already in dictionary, return false
    if(this->find(word) == true)
    {
        return false;
    }

    //get the root and initialize an iterator to go through each character
    TrieNode *curr = root;
    std::string::iterator track = word.begin();

    //while loop to go through the word passed in
    while(track != word.end())
    {
        //get the single character and get the index of it to insert
        char singleW = *track;
        int index = (int)singleW - (int)'a';

        //if the char is a space, make it to be the last child
        if(index < 0)
        {
            index = 26;
        }

        //create a new node if there's no node existed in the child place
        if(curr->child[index] == 0)
        {
            TrieNode *newNode = new TrieNode();
            //link the parent with its child and link child with parent
            newNode->parent = curr;
            curr->child[index] = newNode;
        }

        //go down the trie and to the next character
        curr = curr->child[index];
        track++;
    }

    //store the frequency to the node
    curr->freq = freq;

    //update the maxCount for the trie
    std::string::iterator track1 = word.begin();
    while(track1 != word.end())
    {
        curr = curr->parent;
        if(freq > curr->maxCount)
        {
            curr->maxCount = freq;
        }
        track1++;
    }
    
    //return true after insertion
    return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    //if the word is empty, return false
    if(word.length() == 0)
    {
        return false;
    }

    //get the root and initialize an iterator to go through each character
    TrieNode *curr = root;
    std::string::iterator track = word.begin();

    //while loop to go through the word passed in
    while(track != word.end())
    {
        //get the single character and get the index of it to find
        char singleW = *track;
        int index = (int)singleW - (int)'a';

        //if the char is a space, it shoudld be the last child
        if(index < 0)
        {
            index = 26;
        }

        //if cannot find the child in that specific index, return false
        if(curr->child[index] == 0)
        {
            return false;
        }

        //go down the trie and to the next character
        curr = curr->child[index];
        track++;
    }

    //if the frequency of the word is not 0, return true
    if(curr->freq != 0)
    {
        return true;
    }

    //otherwise return false
    return false;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix,
unsigned int num_completions)
{
    std::vector<std::string> words;
    //create a priority queue in which smaller freq pair in at front
    std::priority_queue<std::pair<std::string,unsigned int>, 
                             std::vector<std::pair<std::string,unsigned int> >,
                             pairCmp> pq;
    //create a empty pair
    std::pair<std::string,unsigned int> empty(prefix,0);

    //push the empty pair into the pq for num_completions times,
    //so that there is something in the pq for comparison in searchHelper
    //method
    for(unsigned int j = 0; j < num_completions; j++)
    {
        pq.push(empty);
    }

    //if the prefix is empty or num_completions is negative or zero,
    //return
    if(prefix.length() == 0 || num_completions <= 0)
    {
        return words;
    }

    //create a TrieNode object
    TrieNode *curr = root;
    std::string::iterator track = prefix.begin();
    //loop through the end of the prefix string
    while(track != prefix.end())
    {
        char singleW = *track;
        int index = (int)singleW - (int)'a';
        if(index < 0)
        {
            index = 26;
        }
        if(curr->child[index] == 0)
        {
            return words;
        }
        curr = curr->child[index];
        track++;
    }
    //call searchHelper method 
    searchHelper(curr,pq,prefix);
   
    //pop the pq for num_completions times
    for(unsigned int i = 0; i < num_completions; i++)
    {
        //only push to the vector if it has positive frequency
        if(!pq.empty())
        {
            if(pq.top().second != 0)
            {
                words.push_back(pq.top().first);
                pq.pop();
            }
            else
            {
                pq.pop();
            }
        }
    }
    //call reverse method to get the right ordering(max--min)
    words = reverse(words);
    return words;
}
/* searchHelper method that insert the correct element into the pq */
void DictionaryTrie::searchHelper(TrieNode *curr, 
                        std::priority_queue<std::pair<std::string,unsigned int>, 
                        std::vector<std::pair<std::string,unsigned int> >,
                        pairCmp>& pq, std::string prefix)
{
     //if the curr TrieNode's frequency is greater than zero
     if(curr->freq > 0)
     {
        //compare with the first element's freq in the pq
        if(curr->freq > pq.top().second)
        {
            //pop the first pair
            pq.pop();
            //create a new pair and push back to the pq
            std::pair<std::string,unsigned int> newPair(prefix, curr->freq);
            pq.push(newPair);
        }
     }   
     //check if the maxCount of the TrieNode is greater than the top
     //pair frequency
     if(curr->maxCount > pq.top().second)
     {
         //loop through all the child
         for(int i = 0; i < 27; i++)
         {
             //if the child is not null
             if(curr->child[i] != 0)
             {
                 //update the prefix
                 std::string newPrefix(prefix);
 
                 if(i == 26)
                 {
                     newPrefix += " ";
                 }
                 else
                 {
                     char toAdd = (char)('a' + i);
                     std::string addString(1, toAdd);
                     newPrefix.append(addString);
                 }
                 //recursivly call the searchHelper method
                 searchHelper(curr->child[i],pq,newPrefix);
            }
         }
     }
    return;
}

/* reverse method to get the right ording in the vector */
std::vector<std::string>DictionaryTrie::reverse(std::vector<std::string> in)
{
    //create a new vector for return purpose
    std::vector<std::string> returnV;
    //loop from the back of the input vector
    for(int i = (int)in.size() - 1; i >= 0; i--)
    {
        //get the string and push back to the return vector
        std::string T = in[i];
        returnV.push_back(T);
    }
    return returnV;
}
/* Destructor */
DictionaryTrie::~DictionaryTrie()
{
    //calling the helper method using postorder to delete all the nodes
    deleteAll(root);
}

/**
 * a helper method using postorder to delete nodes
 */
void DictionaryTrie::deleteAll(TrieNode *n)
{
    //if the node passed in is null, return
    if(n == 0)
    {
        return;
    }

    //for each child in the node's children array, recursively call
    for(int i = 0; i < 27; i++)
    {
        deleteAll(n->child[i]);
    }

    //delete the node itself
    delete n;
}

