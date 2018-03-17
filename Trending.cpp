//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Trending.h"
#include "Hashtag.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Trending::Trending(string startHashtagFilePath, string endHashtagFilePath, string outputHashtagFilePath){
    _startHashtagFilePath = startHashtagFilePath;
    _endHashtagFilePath = endHashtagFilePath;
    _outputHashtagFilePath = outputHashtagFilePath;
}

void Trending::Run(){
    ReadStartfromFile();
    ReadEndfromFile();
    RankStart();
    RankEnd();
    WriteToFile();

}

void Trending::ReadStartfromFile(){
    string word;
    ifstream inp;
    inp.open(_startHashtagFilePath);
    if(!inp.is_open()){
        cout<<"NOT OPEN\n";
        inp.close();
        return;
    }
    else{
        while(!inp.eof()){
            inp >> word;
            if(inp.good()){
                Hashtag test = Hashtag(word);
                test.Convert();
                word = test.GetWord();
                if(start.size() == 0){
                    start.push_back(test);
                    start.at(0).IncrementStartCount();
                }
                else{
                    for(unsigned int i =0; i<start.size(); i++){
                        if(word == start.at(i).GetWord()){
                            start.at(i).IncrementStartCount();
                            break;
                        }
                        else if(i == start.size()-1){
                            start.push_back(test);
                            int j = start.size();
                            start.at(j-1).IncrementStartCount();
                            break;
                        }
                        
                    }}
            }
            else{
                inp.ignore(numeric_limits<streamsize>::max(), '\n');
            }}}
    sort(start.begin(),start.end());
    inp.close();
}

void Trending::ReadEndfromFile(){
    string word;
    ifstream inp;
    inp.open(_endHashtagFilePath);
    if(!inp.is_open()){
        cout<<"NOT OPEN\n";
        inp.close();
        return;
    }
    else{
        while(!inp.eof()){
            inp >> word;
            if(inp.good()){
                Hashtag test = Hashtag(word);
                test.Convert();
                word = test.GetWord();
                if(end.size() == 0){
                    end.push_back(test);
                    end.at(0).IncrementEndCount();
                }
                else{
                    for(unsigned int i =0; i<end.size(); i++){
                        if(word == end.at(i).GetWord()){
                            end.at(i).IncrementEndCount();
                            break;
                        }
                        else if(i == (end.size()-1)){
                            end.push_back(test);
                            int j = end.size();
                            end.at(j-1).IncrementEndCount();
                            break;
                        }
                        
                    }}}
                else
                inp.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }}
//            inp >> word;
//            Hashtag test = Hashtag(word);
//            test.Convert();
//            end.push_back(test);
//            for(unsigned int i =0; i<end.size(); i++){
//                if(test.GetWord() == end.at(i).GetWord() && end.size() > 1){
//                    end.at(i).IncrementEndCount();
//                    end.pop_back();
//                    break;
//                }
//            }
//            
//        }
//    }
    sort(end.begin(),end.end());
    inp.close();
}

void Trending::RankStart(){
    unsigned int i;
    for(i =0; i<start.size(); i++){
        if(i==0){
            start.at(i).SetStartRank(1);
        }
        else if(start.at(i).GetStartCount() == start.at(i-1).GetStartCount()){
            int j = start.at(i-1).GetStartRank();
            start.at(i).SetStartRank(j);
        }
        else if(i == start.size() -1){
            int j = start.at(i-1).GetStartRank();
            start.at(i).SetStartRank(j+1);
        }
        else if(start.at(i+1).GetStartRank() == 0 ){
            int j = start.at(i-1).GetStartRank();
            start.at(i).SetStartRank(j+1);
        }
    }
}

void Trending::RankEnd(){
    unsigned int i;
    for(i =0; i<end.size(); i++){
        if(i==0){
            end.at(i).SetEndRank(1);
        }
        else if(end.at(i).GetEndCount() == end.at(i-1).GetEndCount()){
            int j = end.at(i-1).GetEndRank();
            end.at(i).SetEndRank(j);
        }
        else if(i == end.size() -1){
            int j = end.at(i-1).GetEndRank();
            end.at(i).SetEndRank(j+1);
        }
        else if(end.at(i+1).GetEndRank() == 0 ){
            int j = end.at(i-1).GetEndRank();
            end.at(i).SetEndRank(j+1);
        }
    }
}


void Trending::WriteToFile() {
    ofstream outp;
    string tempWord;
    signed int startRank =0;
    outp.open(_outputHashtagFilePath);
    if(!outp.is_open()){
        cout<<"NOT OPEN\n";
        outp.close();
        return;
    }
    else{
        for(unsigned int i =0; i< end.size(); i++){
            Hashtag temp = end.at(i);
            tempWord = temp.GetWord();
            
            for(unsigned int j = 0; j < start.size(); j++){
                if(start.at(j).GetWord() == tempWord){
                    startRank = start.at(j).GetStartRank();
                    break;
                }
                else if(j == start.size()-1){
                    startRank = 1000;
                }
            }
            
            signed int rank = startRank -temp.GetEndRank();
            if(startRank == 0){
                outp<< "1: " << temp.GetWord() << " (new)\n";
            }
            else if(i==0){
                if(start.size() == 1){
                    outp<< temp.GetEndRank() << ": " << temp.GetWord() << " (+" << rank << ")\n";
                    
                }
              else if(temp.GetEndRank() == end.at(i+1).GetEndRank()){
                outp<< "T" << temp.GetEndRank() << ": " << temp.GetWord();
                if(rank > 100)
                      outp << " (new)\n";
                else if(rank >= 0)
                    outp << " (+" << rank << ")\n";
                else
                    outp << " (" << rank << ")\n";
              }
              else{
                  outp<< temp.GetEndRank() << ": " << temp.GetWord();
                  
                  if(rank > 100)
                      outp << " (new)\n";
                  else if(rank >= 0)
                      outp << " (+" << rank << ")\n";
                  else
                      outp << " (" << rank << ")\n";
              }
            }
            else if(i == end.size() -1){
                if(temp.GetEndRank() == end.at(i-1).GetEndRank()){
                    outp<< "T" << temp.GetEndRank() << ": " << temp.GetWord();
                    if(rank > 100)
                        outp << " (new)\n";
                    else if(rank >= 0)
                        outp << " (+" << rank << ")\n";
                    else
                        outp << " (" << rank << ")\n";
                }
                else{
                    outp<< temp.GetEndRank() << ": " << temp.GetWord();
                    if(rank > 100)
                        outp << " (new)\n";
                    else if(rank >= 0)
                        outp << " (+" << rank << ")\n";
                    else
                        outp << " (" << rank << ")\n";
                }}
            else{
                if((temp.GetEndRank() == end.at(i+1).GetEndRank() || temp.GetEndRank() == end.at(i-1).GetEndRank())){
                outp<< "T" << temp.GetEndRank() << ": " << temp.GetWord();
                    if(rank > 100)
                        outp << " (new)\n";
                    else if(rank >= 0)
                    outp << " (+" << rank << ")\n";
                else
                    outp << " (" << rank << ")\n";
            }
            else{
                outp<< temp.GetEndRank() << ": " << temp.GetWord();
                if(rank > 100)
                    outp << " (new)\n";
                else if(rank >= 0)
                    outp << " (+" << rank << ")\n";
                else
                    outp << " (" << rank << ")\n";
            }}
        }
    }
    outp.close();
}






