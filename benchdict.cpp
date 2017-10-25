/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Feb 18, 2016
 * Overview: implement a program that times our implementation of find
 * methods in our dictionary classes
 * Assignment number: PA3
 */

#include "util.hpp"
#include "DictionaryTrie.hpp"
#include "DictionaryBST.hpp"
#include "DictionaryHashtable.hpp"
#include <fstream>
#include <sstream>

/**
 * time test on find method in trie
 */
void testFindTrie(unsigned int min_size,unsigned int min_step_size,
                       int numofIteration, std::string dict_filename)

{
    //initalize the input stream
    std::ifstream in;
        
    //indicate the dictionary we are testing
    std::cout<<"DictionaryTrie"<<std::endl;

    //initialize timer and variables to store time
    Timer T;
    long long time_duration = 0;
    long long total_time = 0;
    long long average_time = 0;

    //for loop go through number of iteration times
    for(int i = 0; i < numofIteration; i++)
    {
        //open stream, create new trie and load
        total_time = 0;
        in.open(dict_filename,std::ios::binary);
        DictionaryTrie* dictionary_trie = new DictionaryTrie();
        Utils::load_dict(*dictionary_trie,in,min_size+i*min_step_size);

        //give warning if reach the end but still do the finding
        if(in.eof())
        {
            std::cout<<"Warning: words is not enough in file"<<std::endl;
        }

        //while loop finding 10 words 1000 times
        int j = 0;
        while( j < 1000)
        {
            T.begin_timer();
            dictionary_trie->find("fweijgowjgieojgi");
            dictionary_trie->find("pgiwjegiwobniioa");
            dictionary_trie->find("agiwnbionieowigj");
            dictionary_trie->find("fwjionbnwianbwoa");
            dictionary_trie->find("wobiwnbwonblddvi");
            dictionary_trie->find("cngiwbonabnlnvva");
            dictionary_trie->find("idnaboakmacnrbni");
            dictionary_trie->find("ljbiaonbnrnoenbr");
            dictionary_trie->find("wbirobncknvbonbr");
            dictionary_trie->find("ibonanblkxbnaeon");

            time_duration = T.end_timer();
            total_time = total_time + time_duration;
            j++;
        }

        //get the average time and print out 
        average_time = total_time/1000;
        std::cout<<min_size+i*min_step_size<<"\t"<<average_time<<std::endl;
        
        //clean up
        delete dictionary_trie;
        in.close();
    }

    std::cout<<""<<std::endl;
}

/**
 * time test on find method in BST
 */
void testFindBST(unsigned int min_size,unsigned int min_step_size,
                       int numofIteration, std::string dict_filename)

{
    //initialize the input stream
    std::ifstream in;
       
    //indicate the dictionary we are testing
    std::cout<<"DictionaryBST"<<std::endl;

    //initialize timer and variables to store time
    Timer T;
    long long time_duration = 0;
    long long total_time = 0;
    long long average_time = 0;

    //for loop go through number of iteration times
    for(int i = 0; i < numofIteration; i++)
    {
        //open stream, create new BST and load
        total_time = 0;
        in.open(dict_filename,std::ios::binary);
        DictionaryBST* dictionary_bst = new DictionaryBST();
        Utils::load_dict(*dictionary_bst,in,min_size+i*min_step_size);

        //give warning if reach the end but still do the finding
        if(in.eof())
        {
            std::cout<<"Warning: words is not enough in file"<<std::endl;
        }

        //while loop finding 10 words 1000 times
        int j = 0;
        while( j < 1000)
        {
            T.begin_timer();
            dictionary_bst->find("fweijgowjgieojgi");
            dictionary_bst->find("pgiwjegiwobniioa");
            dictionary_bst->find("agiwnbionieowigj");
            dictionary_bst->find("fwjionbnwianbwoa");
            dictionary_bst->find("wobiwnbwonblddvi");
            dictionary_bst->find("cngiwbonabnlnvva");
            dictionary_bst->find("idnaboakmacnrbni");
            dictionary_bst->find("ljbiaonbnrnoenbr");
            dictionary_bst->find("wbirobncknvbonbr");
            dictionary_bst->find("ibonanblkxbnaeon");

            time_duration = T.end_timer();
            total_time = total_time + time_duration;
            j++;
        }

        //get the average time and print out
        average_time = total_time/1000;
        std::cout<<min_size+i*min_step_size<<"\t"<<average_time<<std::endl;

        //clean up
        delete dictionary_bst;
        in.close();
    }

    std::cout<<""<<std::endl;
}

/**
 * time test on find method in HashTable
 */
void testFindHashtable(unsigned int min_size,unsigned int min_step_size,
                       int numofIteration, std::string dict_filename)
{
    //initialize the input stream
    std::ifstream in;

    //indicate the dictionary we are testing
    std::cout<<"DictionaryHashtable"<<std::endl;

    //initialize timer and variables to store time
    Timer T;
    long long time_duration = 0;
    long long total_time = 0;
    long long average_time = 0;

    //for loop go through number of iteration times
    for(int i = 0; i < numofIteration; i++)
    {
        //open stream, create new HashTable and load
        total_time = 0;
        in.open(dict_filename,std::ios::binary);
        DictionaryHashtable* dictionary_hashtable = new DictionaryHashtable();
        Utils::load_dict(*dictionary_hashtable,in,min_size+i*min_step_size);

        //give warning if reach the end but still do the finding
        if(in.eof())
        {
            std::cout<<"Warning: words is not enough in file"<<std::endl;
        }

        //while loop finding 10 words 1000 times
        int j = 0;
        while( j < 1000)
        {
            T.begin_timer();
            dictionary_hashtable->find("fweijgowjgieojgi");
            dictionary_hashtable->find("pgiwjegiwobniioa");
            dictionary_hashtable->find("agiwnbionieowigj");
            dictionary_hashtable->find("fwjionbnwianbwoa");
            dictionary_hashtable->find("wobiwnbwonblddvi");
            dictionary_hashtable->find("cngiwbonabnlnvva");
            dictionary_hashtable->find("idnaboakmacnrbni");
            dictionary_hashtable->find("ljbiaonbnrnoenbr");
            dictionary_hashtable->find("wbirobncknvbonbr");
            dictionary_hashtable->find("ibonanblkxbnaeon");

            time_duration = T.end_timer();
            total_time = total_time + time_duration;
            j++;
        }

        //get the average time and print out
        average_time = total_time/1000;
        std::cout<<min_size+i*min_step_size<<"\t"<<average_time<<std::endl;

        //clean up
        delete dictionary_hashtable;
        in.close();
    }
}

/**
 * main method to run the whole program, calling three methods above
 */
int main(int argc, char* argv[])
{
    //check number of arguments and prompt user if wrong
    if(argc < 5)
    {
        std::cout << "Incorrect number of arguments." << std::endl;
        std::cout << "\t First argument: name of dictionary file." << std::endl;
        std::cout << std::endl;
        exit(-1);
    }

    //get min_size, min_step_size and number of iterations from arguments
    unsigned int min_size = (unsigned int) std::stoi(argv[1]);
    unsigned int min_step_size = (unsigned int) std::stoi(argv[2]);
    int numofIteration = std::stoi(argv[3]);

    //call all three test methods 
    testFindTrie(min_size,min_step_size,numofIteration,argv[4]);
    testFindBST(min_size,min_step_size,numofIteration,argv[4]);
    testFindHashtable(min_size,min_step_size,numofIteration,argv[4]);
    return 0;
}
    

