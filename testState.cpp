//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testState.h"
#include "State.h"
#include <iostream>

using namespace std;

void StateTester::RunTests(){
    testSetTireAngleAboveMaximum();
    testSetTireAngleBelowMinimum();
    testSetHeadingAboveTwoPi();
    testSetHeadingBelowTwoPi();
}

/*
 * @requirement pass if _tire_angle returns is MAX_TIRE_ANGLE when SetTireAngle is provided an angle greater than MAX_TIRE_ANGLE
 * @return pass: true, fail: false
 */
bool StateTester::testSetTireAngleAboveMaximum(){
    State test;
    test.SetTireAngle(MAX_TIRE_ANGLE +10);
    
    if(test.GetTireAngle() == MAX_TIRE_ANGLE)
        return true;
    else
        return false;
}

/*
 * @requirement pass if _tire_angle returns is MIN_TIRE_ANGLE when SetTireAngle is provided an angle less than MIN_TIRE_ANGLE
 * @return pass: true, fail: false
 */
bool StateTester::testSetTireAngleBelowMinimum(){
    State test;
    test.SetTireAngle(MIN_TIRE_ANGLE-10);
    
    if(test.GetTireAngle() == MIN_TIRE_ANGLE)
        return true;
    else
        return false;
}

/*
 * @requirement pass if _heading returns an equivalent angle when SetHeading is provided an angle greater than than 2*pi
 * @return pass: true, fail: false
 */
bool StateTester::testSetHeadingAboveTwoPi(){
    State test;
    test.SetHeading(3*M_PI);
    
    if(test.GetHeading() == M_PI)
        return true;
    else
        return false;
}

/*
 * @requirement pass if _heading returns an equivalent angle when SetHeading is provided an angle less than than 2*pi
 * @return pass: true, fail: false
 */
bool StateTester::testSetHeadingBelowTwoPi(){
    State test;
    test.SetHeading(-3*M_PI);
    
    if(test.GetHeading() == M_PI)
        return true;
    else
        return false;
}
