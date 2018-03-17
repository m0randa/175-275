#include "Velociplotter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Velociplotter::Velociplotter(string inputFilePath, string outputFilePath){
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
}

void Velociplotter::Run(){
    ReadInputsFromFile();
    CalculateAverageVelocities();
    WriteOutputsToFile();
}

void Velociplotter::ReadInputsFromFile(){
    ifstream inp;
    string loc;
    string gps;
    
    inp.open(_inputFilePath);
    if(!inp.is_open()){
        cout << "INP NOT OPEN";
        inp.close();
    }
    else{
        while(!inp.eof()){
            getline(inp,loc);
            
            //Change commas to spaces
            for(unsigned int i =0; i< loc.length(); i++){
                if(loc[i] == ',')
                    loc[i] = ' ';
            }
            
            istringstream getit(loc);
            string GGA, N, W, M, M2, rest;
            double time, latitude, longitude, temp, temp2, temp3, temp4, temp5;
            
            getit >> GGA >> time >> latitude >> N >> longitude >> W >> temp >> temp2 >> temp3 >> temp4 >> M >> temp5 >> M2 >> rest;
            
            //Check if it's an appropriate line
            if(GGA == "$GPGGA" && time != 0){
                GPSPosition okay(latitude,longitude,time);
                
                //Place into vector
                int i = pos.size();
                if(i != 0){
                    if(pos[i-1].GetTime() == okay.GetTime()){
                    pos.pop_back();
                    pos.push_back(okay);
                    }
                    else
                        pos.push_back(okay);
                }
                else
                    pos.push_back(okay);
                
                }
        }
    }
    inp.close();
}

void Velociplotter::CalculateAverageVelocities(){
    double time;
    double dist;
    double velocity;
    for(unsigned int i =1; i<pos.size(); i++){
        if(pos[i-1].GetTime() < pos[i].GetTime()){
            time = pos[i].GetTime() - pos[i-1].GetTime();
            dist = pos[i-1].CalcDistanceKmTo(pos[i]);
            velocity = (dist/time);
            velocity = velocity*3600;
            
            pos[i].SetVel(velocity);
        }
        else{
            pos[i].SetVel(-1);
        }
    }
}


void Velociplotter::WriteOutputsToFile(){
    ofstream outp;
    int change;
    outp.open(_outputFilePath);
    if(!outp.is_open()){
        cout << "OUTP NOT OPEN";
        outp.close();
    }
    else{
        for(unsigned int i =1; i<pos.size(); i++){
            
            //If velocity is less than zero at any time the program quits
            if(pos[i].GetVel() < 0)
                outp.close();
            
            //If one line's time equals the one before it's time, it should print the same location as the previous one
            else if(pos[i-1].GetTime() == pos[i].GetTime())
                i++;
            else{
                if(pos[i].GetTime()-pos[i-1].GetTime()>1){
                    change = pos[i].GetTime() - pos[i-1].GetTime();
                    int j =1;
                    while(j < change){
                        outp << pos[i-1].GetTime()+j << " " << pos[i].GetVel() << endl;
                        j = j+1;
                    }
                }
                
                outp << pos[i].GetTime() << " " << pos[i].GetVel() << endl;
            }}
        
    }
    outp.close();
}
