//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "SocialNetworkAnalysis.h"
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

SocialNetworkAnalysis::SocialNetworkAnalysis(string inputFilePath, string outputFilePath){
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
}

void SocialNetworkAnalysis::Run(){
    ifstream inp;
    inp.open(_inputFilePath);
    if(!inp.is_open()){
        cout<<"NOT OPEN\n";
        inp.close();
        return;
    }
    else{
        inp.close();
    }
    
    ofstream outp;
    outp.open(_outputFilePath);
    if(!outp.is_open()){
        cout<<"NOT OPEN\n";
        outp.close();
        return;
    }
    else{
        outp.close();
    }

}
