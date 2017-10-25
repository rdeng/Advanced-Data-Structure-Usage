#include "DictionaryTrie.hpp"
#include <string>
#include <iostream>
#include <vector>

int main()
{
    DictionaryTrie *mytrie = new DictionaryTrie();
    std::string s1("abc ");
    std::string s2("ab");
    std::string s3("aaa");
    
    bool state1 = mytrie->insert(s1,1);
    bool state2 = mytrie->insert(s2,1);
    bool state3 = mytrie->insert(s3,1);
    if( state1 == false)
    {
        std::cout<<"s1"<<std::endl;
    }
    if(state2 == false)
    {
        std::cout<<"s2"<<std::endl;
    }
    if( state3 == false)
    {
        std::cout<<"s3"<<std::endl;
    }
    bool state4 = mytrie->find(s1);
    bool state5 = mytrie->find(s2);
    bool state6 = mytrie->find(s3);

    if(state4 == false || state5 == false || state6 == false)
    {
         std::cout<<"2"<<std::endl;
    }
    bool state7 = mytrie->insert(s1,1);
    if(state7 == true)
    {
         std::cout<<"3"<<std::endl;
    }
    std::string s4 = "123";
    bool state8 = mytrie->find(s4);
    if(state8 == true)
    {
         std::cout<<"4"<<std::endl;
    }
    


    std::string s5 = "";    
    bool state9 = mytrie->insert(s5,1);  
    if(state9 == true)
    {
         std::cout<<"5"<<std::endl;
    }
    std::string s10("1242wasf12g");
    bool state10 = mytrie->insert(s10,1);
    bool state11 = mytrie->find(s10);
    if(state10 == false)
    {
          std::cout<<"10"<<std::endl;
    }
    if(state11 == false)
    {
         std::cout<<"11"<<std::endl;
    }
    std::string s100 = "a";
    std::vector<std::string> myV= mytrie->predictCompletions(s100,10);
    while( myV.size() != 0)
    {
        std::cout<<myV.back()<<std::endl;
        myV.pop_back();
    }



delete mytrie;
return 0;

}
