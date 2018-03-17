//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "card.h"
#include <iostream>

using namespace std;

/**
 * Description: Parse a line from a file and create a card
 *
 * @param lineFromFile A string from a file
 *
 * @requirement carriage returns "\r" and newlines "\n" must be removed
 * @requirement a valid blank is at least three consecutive underscores
 * @requirement blankLength and blankIndex are zero if a valid blank is not found
 * @requirement blankIndex is the index that makes card->GetContent()[card->blankIndex] be the first underscore
 * @requirement blankLength is the number of underscores in the blank
 *
 */
Card::Card(string lineFromFile){

    int counter =0;
    unsigned int i =0;
    int one =0;
    SetBlankIndex(0);
    SetBlankLength(0);
    
    while(lineFromFile.back() == '\n' || lineFromFile.back() == '\r'){
        lineFromFile.pop_back();
    }
    SetContent(lineFromFile);
    while(i<lineFromFile.length()){
        if(lineFromFile[i] == '_'){
            if(i == 0){
                SetBlankIndex(0);
                one =1;
            }
            if(GetBlankIndex() ==0 && one == 0){
                SetBlankIndex(i);

            }
            
            if(counter >=0)
                counter++;
            else if(lineFromFile[i+1]!= '_' || lineFromFile[i+2] != '_'){
                SetBlankIndex(0);
                SetBlankLength(0);
                counter = -10;
                if(lineFromFile[i+1]!= '_')
                    lineFromFile.erase(i,1);
                else if(lineFromFile[i+2] != '_')
                    lineFromFile.erase(i,2);
            }
        }
        i++;
    }
    if(counter >2)
        SetBlankLength(counter);
}


/**
 * Description: Replace a blank in a card with content from a Word object
 *
 * @param word Word with which to replace the blank inside the card
 *
 * @requirement Card _content has its blank replaced with the _content of word
 *
 */
void Card::ReplaceBlanks(Word word){
    string test;
    int loc;
    int counter = GetBlankLength();
    loc = GetBlankIndex();
    test = GetContent();
    if(this->IsValid()){
    test.replace(loc, counter, word.GetContent());
    SetContent(test);
    }}

/**
 * Validate Card
 *
 * @requirement blankLength must be at least 3
 *
 */
bool Card::IsValid() {
    if(GetBlankLength() < 3)
        return false;
    else
        return true;
}

/**
 * Description: < operator overload
 *
 * @requirement return false if _content length of current Card is less than content of rhs
 *
 * @note This is necessary in order to use the .sort() function on a list properly
 */
bool Card::operator<(const Card& rhs) const{
    if(GetContent().length() < rhs.GetContent().length())
        return true;
    else
        return false;
    
}
