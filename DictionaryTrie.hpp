/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 18, 2016
 * Overview: the header file of DictionaryTrie
 * Assignment number: PA3
 */

/**
 * CSE 100 PA3 C++ Autocomplete
 * Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <vector>
#include <string>
#include <utility>
#include <queue>

/**
 * class used for comparing two pairs
 */
class pairCmp
{
  public:
    /*
     * overwrite the comparing method. When comparing two pairs with
     * string and int, only compare their ints.
     */
    bool operator()(std::pair<std::string,unsigned int> firstPair,
                    std::pair<std::string,unsigned int> secondPair)
    {
      //access the ints
      unsigned int firstInt = firstPair.second;
      unsigned int secondInt = secondPair.second;

      //compare the ints
      return firstInt > secondInt;
    }
};

/**
 * The class for a dictionary ADT, implemented as a trie
 * You may implement this class as either a mulit-way trie
 * or a ternary search trie, but you must use one or the other.
 */
class DictionaryTrie
{
private:
  // Add your own data members and methods here
  
  /**
   * inner class TrieNode to help building the Trie
   */ 
  class TrieNode
  {
    public:
      //a node has a frequency and 27 children as an array
      unsigned int freq;
      TrieNode *child[27];
      //maxCount field to account for the maxFreq in the subtree
      unsigned int maxCount;
      TrieNode *parent;

      //constructor fof a TrideNode, initialize the freq and children array
      TrieNode()
      {
        freq = 0;
        maxCount = 0;
        parent = 0;
        for(int i = 0; i < 27; i++)
        {
          child[i] = 0;
        }
      }
  };
private:
  //root node
  TrieNode *root;

public:
  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /**
   * Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) 
   */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /** 
   * Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

  /* Helper method for destructor */
  void deleteAll(TrieNode *n);
  /** searchHelper method to search for the top frequency words for predict 
   *  completion method.
   */
  void searchHelper(TrieNode *curr, 
                          std::priority_queue<std::pair<std::string,unsigned int>, 
                          std::vector<std::pair<std::string,unsigned int> >,
                          pairCmp>& pq, std::string prefix);
  /** reverse method to get the right order for the return vector words.( from 
   *  larger freq to smaller freq
   */
  std::vector<std::string> reverse(std::vector<std::string> in);
};
#endif // DICTIONARY_TRIE_HPP
