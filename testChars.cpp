//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <iostream>
#include "testChars.h"
#include "word.h"
#include "card.h"

using namespace std;

void CharsTester::RunTests() {
    testConstructWordWithCarriageReturn();
    testConstructWordWithNewLine();
    testIsWordValidWithSpace();
    testIsWordValidPercentSign();
    testIsWordValidShortWord();
    testConstructCardWithCarriageReturn();
    testConstructCardWithNewLine();
    testIsCardValidNoBlank();
    testIsCardValidShortBlank();
    testCorrectBlankLengthAndIndex();
    testCardIsLessThan();
}

/*
 * @requirement pass if "\r\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithCarriageReturn() {
    string sent = "This is_____ test\r\n";
    Word test = Word(sent);
    
    if(test.GetContent() == "This is_____ test")
        return true;
    else
        return false;
}

/*
 * @requirement pass if "\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithNewLine() {
    string sent = "This is_____ test\n";
    Word test = Word(sent);
    
    if(test.GetContent() == "This is_____ test")
        return true;
    else
        return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a space is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidWithSpace() {
    string sent = "This is_____ test";
    Word test = Word(sent);
    
    if(test.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a percent sign is considered valid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidPercentSign() {
    string sent = "This%";
    Word test = Word(sent);
    
    if(test.IsValid() == true)
        return true;
    else
        return false;
}

/*
 * @requirement pass if Word created using constructor with string that is less than 3 characters is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidShortWord() {
    string sent = "Y";
    Word test = Word(sent);
    
    if(test.IsValid() == false )
        return true;
    else
        return false;
}

/*
 * @requirement pass if "\r\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithCarriageReturn() {
    string sent = "This is_____ test\r\n";
    Card test = Card(sent);
    
    if(test.GetContent() == "This is_____ test")
        return true;
    else
        return false;
}

/*
 * @requirement pass if "\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithNewLine() {
    string sent = "This is_____ test\n";
    Card test = Card(sent);
    
    if(test.GetContent() == "This is_____ test")
        return true;
    else
        return false;
}

/*
 * @requirement pass if Card created using constructor with string that has no underscores is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidNoBlank() {
    string sent = "Thisisatest";
    Card test = Card(sent);
    
    if(test.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass if Card created using constructor with string that has a blank that is only two characters long is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidShortBlank() {
    string sent = "Y";
    Card test = Card(sent);
    
    if(test.IsValid() == false)
        return true;
    else
        return false;
}

/*
 * @requirement pass if blankLength and blankIndex is correct in properly formatted Card object with a blank yet to be filled.
 * @return pass: true, fail: false
 */
bool CharsTester::testCorrectBlankLengthAndIndex() {
    string sent = "This____test";
    Card test = Card(sent);
    
    if(test.GetBlankLength() == 4 && test.GetBlankIndex() == 4)
        return true;
    else
        return false;
}

/*
 * @requirement pass if Card with contents that have fewer characters than another Card is considered "less than"
 * @return pass: true, fail: false
 */
bool CharsTester::testCardIsLessThan() {
    string one = "Thisisatest";
    string two = "nope";
    Card on1 = Card(one);
    Card tw2 = Card(two);
    if(tw2 < on1)
        return true;
    else
    return false;
}

