//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "CarSimulator.h"

using namespace std;

void EndToEndTester::RunTests(){
    EndToEndTester test;
    for(int i = 1; i <= 10; i++)
        test.TestFile(i);
    // call TestFile for all inputFiles in the test_files folder
}


/*
 * @requirement pass if all lines output[testNum + 1] are the exact same (strcmp returns 0) as myOutput[testNum + 1] AND output files can be opened properly
 * @return pass: true, fail: false
 */
int EndToEndTester::TestFile(int testNum){
    // Create filepaths for the input, myOutput, and output text files.
    // input and output files are provided in the test_files folder.
    ostringstream inp;
    ostringstream outp;
    ostringstream moutp;
    string input;
    string myOutput;
    string output;
    string myline;
    string realline;
    ifstream myoutp;
    ifstream realOut;
    inp << TEST_FILE_RELATIVE_PATH << "/input" << testNum +1 << ".txt";
    input = inp.str();
    outp << TEST_FILE_RELATIVE_PATH << "/output" << testNum +1 << ".txt";
    output = outp.str();
    moutp << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum +1 << ".txt";
    myOutput = moutp.str();
    // myOutput is what is produced by the program being run
    // run the CarSimulator which involved 3 steps.
    CarSimulator fileTest(input, myOutput);
    // 1. read commands
    fileTest.ReadCommandsFromFile();
    // 2. run the commands
    fileTest.RunAllCommands();
    // 3. output state history
    fileTest.WriteStateHistoryToFile();
    // compare myOutput and corresponding output file line by line
    myoutp.open(myOutput);
    realOut.open(output);
    if(myoutp.is_open() &&realOut.is_open()){
    while(!myoutp.eof() && !realOut.eof()){
        getline(myoutp, myline);
        getline(realOut, realline);
    // if they differ on even one line, the test should fail
        if(myline.compare(realline) != 0){
            //myoutp.close();
            //realOut.close();
            return false;
        }}}
    myoutp.close();
    realOut.close();
    return true;
}
