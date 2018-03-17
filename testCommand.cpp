//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testCommand.h"
#include "Command.h"
#include <iostream>

using namespace std;

void CommandTester::RunTests(){
    testNegativeVelocity();
    testVelocityTooHigh();
    testTireAngleTooLow();
    testTireAngleTooHigh();
    testNegativeTimeStamp();
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a negative velocity
 * @return pass: true, fail: false
 */
bool CommandTester::testNegativeVelocity(){
    Command ans;
    ans.SetVelocity(-1.0);
    ans.SetTireAngleRate(0.0);
    ans.SetTimeStamp(1);
    
    if(ans.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a velocity above 30.0
 * @return pass: true, fail: false
 */
bool CommandTester::testVelocityTooHigh(){
    Command ans;
    ans.SetVelocity(40.0);
    ans.SetTireAngleRate(0.0);
    ans.SetTimeStamp(1);
    
    if(ans.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a tire_angle_rate below the range MIN_TIRE_ANGLE_RATE
 * @return pass: true, fail: false
 */
bool CommandTester::testTireAngleTooLow(){
    Command ans;
    ans.SetVelocity(1.0);
    ans.SetTireAngleRate(MIN_TIRE_ANGLE_RATE -10);
    ans.SetTimeStamp(1);
    
    if(ans.IsValid() == false)
        return true;
    else
        return false;
}
/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a tire_angle_rate above the range MAX_TIRE_ANGLE_RATE
 * @return pass: true, fail: false
 */
bool CommandTester::testTireAngleTooHigh(){
    Command ans;
    ans.SetVelocity(1.0);
    ans.SetTireAngleRate(MAX_TIRE_ANGLE_RATE +10);
    ans.SetTimeStamp(1);
    
    if(ans.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a negative timestamp
 * @return pass: true, fail: false
 */
bool CommandTester::testNegativeTimeStamp(){
    Command ans;
    ans.SetVelocity(1.0);
    ans.SetTireAngleRate(0.0);
    ans.SetTimeStamp(-1.0);
    
    if(ans.IsValid() == false)
        return true;
    else
        return false;
}

