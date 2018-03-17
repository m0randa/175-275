//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "word.h"

using namespace std;

/**
 * Parse a line from a file and create a word
 *
 * @param lineFromFile A string from a file
 *
 * @requirement carriage returns "\r" and newlines "\n" must be removed
 * @requirement after removal of carriage returns and newline, content of line are assigned to _content
 *
 */
Word::Word(string lineFromFile){
    while(lineFromFile.back() == '\n' || lineFromFile.back() == '\r'){
        lineFromFile.pop_back();
    }
    SetContent(lineFromFile);
    

}

/**
 * Validate Word
 *
 * @param Pointer to Word to validate
 *
 * @requirement every character in _content must pass the condition:
 * ispunct(character) || isalnum(character)
 * @requirement The Word length must be greater than 2
 *
 * @return 1 if valid, 0 otherwise
 */
bool Word::IsValid(){
    unsigned int len = GetContent().length();
    if( len < 2)
        return 0;
    unsigned int i =0;
    while(i < len){
        if(ispunct(GetContent()[i]) == 0 && isalnum(GetContent()[i]) == 0){
                return 0;
        }
        i++;
    }

    return 1;
}
