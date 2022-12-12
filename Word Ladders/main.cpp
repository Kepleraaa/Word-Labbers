/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "map.h"
using namespace std;

void WordLadders_Helper(string currentstr,const Lexicon &english,Vector<string> &strings,string &destinationstr,Vector<string> &Beststrings,int &BestValue,Map<string,int> &theShortestSteps)
{
    if (strings.size()>=BestValue)
    {
        return;
    }
    else if (currentstr==destinationstr)
    {
        BestValue=strings.size();
        Beststrings=strings;
        return;
    }
    else
    {
        for (int i=0;i<currentstr.size();i++)
        {
            for (char ch='a';ch<='z';ch++)
            {
                if (ch!=currentstr[i])
                {
                    string possiblestr=currentstr;
                    possiblestr[i]=ch;
                    if (english.contains(possiblestr))
                    {
                        if (!theShortestSteps.containsKey(possiblestr) || theShortestSteps[possiblestr]>strings.size())
                        {
                            strings.add(possiblestr);
                            theShortestSteps[possiblestr]=strings.size();
                            WordLadders_Helper(possiblestr,english,strings,destinationstr,Beststrings,BestValue,theShortestSteps);
                            strings=strings.subList(0,strings.size()-1);
                        }
                    }
                }
            }
        }
    }
}

Vector<string> WordLadders(const Lexicon &english,string startstr,string destinationstr)
{
    Map<string,int> theShortestSteps;
    int BestValue=20;
    Vector<string> BestLadder;
    Vector<string> temp_Ladder={startstr};
    theShortestSteps[startstr]=temp_Ladder.size();
    WordLadders_Helper(startstr,english,temp_Ladder,destinationstr,BestLadder,BestValue,theShortestSteps);
    if (BestLadder.isEmpty())
        cout<<"No labber found."<<endl;
    return BestLadder;
}

int main()
{
    const Lexicon english("EnglishWords.txt");
    int signal=1;
    while (signal)
    {
        string startstr=getLine("enter the start string:");
        string destinationstr=getLine("enter the destination string:");
        cout<<WordLadders(english,startstr,destinationstr)<<endl;
        signal=getInteger("是否继续？ 1.继续；0.结束");
    }
    return 0;
}
