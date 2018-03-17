//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "CarSimulator.h"
#include <limits>

using namespace std;

/**
 * Creates CarSimulator object
 *
 * @requirement assigns _inputFileName to object data members _inputFileName
 * @requirement assigns _outputFileName to object data members _outputFileName
 */
CarSimulator::CarSimulator(std::string _inputFileName, std::string _outputFileName){
    this->_inputFileName =_inputFileName;
    this->_outputFileName = _outputFileName;
}

/**
 * Populates object _commands data member from _inputFileName
 *
 * @requirement if the Command IsValid() returns false for any Command, the input file is invalidated. An output file still needs to be generated
 * @requirement if a line is not formatted correctly, the file is not invalidated. It is just discarded.
 * @requirement close the file at the end of the function
 */
void CarSimulator::ReadCommandsFromFile(){
    Command test;
    ifstream inp;
    double vel;
    double tire;
    double time;
    inp.open(_inputFileName);
    if(!inp.is_open()){
        cout<<"NOT OPEN";
        return;
    }
    else{
    while(!inp.eof()){
        inp >> time >> vel >> tire;
        test= Command(vel,tire,time);
        if(!inp.good()){
            inp.clear();
            inp.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(!test.IsValid()){
            _commands.clear();
            inp.close();
        }
        else{
            _commands.push_back(test);
        }
    }}
    inp.close();
}

/**
 * Populates _stateHistory data member from already populated _commands by calling RunCommand on each command
 *
 * @requirement the last Command in _commands has a duration of .2 seconds
 * @requirement the calculated duration between each Command must be >= .005 seconds and <= .2 seconds otherwise, the whole set of _commands is invalidated. An output file should still be generated.
 */
void CarSimulator::RunAllCommands(){
    int sizeC;
    int i;
    double duration;
    Command temp;
    Command temp2;
    if(_commands.empty())
        return;
    else
        sizeC = _commands.size();
    for(i=0; i<sizeC; i++){
        if(i == sizeC-1)
            duration = 0.2;
        else{
            temp = _commands.at(i+1);
            temp2 = _commands.at(i);
            duration = temp.GetTimeStamp()-temp2.GetTimeStamp();
        }
        if(duration < 0.005 || duration > 0.2){
            _commands.clear();
            _stateHistory.clear();
        }
        
        else
            RunCommand(_commands.at(i), duration);
    }
}

/**
 * Adds a new State to _stateHistory given a Command and duration
 *
 * @requirement A new state is updated according to the following equations/pseudocode:
 *
 * x_pos = x_prev + duration*velocity*cos(tire_angle)*cos(heading)
 * y_pos = y_prev + duration*velocity*cos(tire_angle)*sin(heading)
 * tire_angle = tire_angle_prev + duration*tire_angle_rate
 * heading = heading_prev + duration*velocity*(1.0/L)*sin(tire_angle)
 * time_stamp = time_stamp_prev + duration
 *
 * @requirement all data members of the new State must be set with setters. Otherwise, bad things will happen.
 */
void CarSimulator::RunCommand(Command command, double duration){
    State prev;
    State newS;
    double vel = command.GetVelocity();
    prev = GetCurrentState();
    newS.SetTimeStamp(prev.GetTimeStamp() +duration);
    newS.SetTireAngle(prev.GetTireAngle() +(duration*command.GetTireAngleRate()));
    newS.SetHeading(prev.GetHeading() +(duration*vel*(1.0/L)*sin(prev.GetTireAngle())));
    newS.SetXPos(prev.GetXPos() +(duration*vel*cos(prev.GetTireAngle())*cos(prev.GetHeading())));
    newS.SetYPos(prev.GetYPos() +(duration*vel*cos(prev.GetTireAngle())*sin(prev.GetHeading())));
    if(prev.GetHeading() == 0.0 && prev.GetTireAngle() == 0.0 && prev.GetXPos() == 0.0 && prev.GetYPos() ==0.0 && prev.GetTimeStamp() == 0.0)
        _stateHistory.clear();
    _stateHistory.push_back(newS);
}

/**
 * Populates output file called _outputFileName with _stateHistory
 *
 * @requirement Each line in the output file should be formatted as follows:
 *
 * timestamp,x_pos,y_pos,tire_angle,heading
 *
 * All numbers are of type double.
 *
 * @requirement close the file when you are done.
 */
void CarSimulator::WriteStateHistoryToFile(){
    ofstream outp;
    State temp;
    int size;
    int i;
    double time;
    double x;
    double y;
    double tire;
    double head;
    outp.open(_outputFileName);
    if(outp.is_open()){
        if(!_stateHistory.empty()){
            size = _stateHistory.size();
            for(i =0; i<size; i++){
                temp = _stateHistory.at(i);
                time = temp. GetTimeStamp();
                x = temp.GetXPos();
                y = temp.GetYPos();
                tire = temp.GetTireAngle();
                head = temp.GetHeading();
                outp << time <<","<< x <<","<< y <<","<< tire <<","<< head << endl;
            }
        }
    }
    outp.close();
}

/**
 * Returns the most recent state to be used in RunCommand()
 *
 * @requirement if _stateHistory is empty, return default state (all data members are 0.0), otherwise return the last state in _stateHistory
 */
State CarSimulator::GetCurrentState(){
    int size;
    if(_stateHistory.empty())
        return State();
    else{
        size =_stateHistory.size();
        return _stateHistory.at(size-1);
    }
}

