//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "chars.h"

using namespace std;

/**
 * Description: constructor for Chars
 *
 * @param string wordsFilePath relative path of file to get Word information
 * @param string cardsFilePath relative path of file to get Card information
 * @param string outputFilePath relative path of file to write processed cards information
 *
 * @requirement assign parameters to Chars data members of similar name
 */
Chars::Chars(std::string wordsFilePath, std::string cardsFilePath, std::string outputFilePath){
    _wordFilePath = wordsFilePath;
    _cardFilePath = cardsFilePath;
    _outputFilePath = outputFilePath;

}

/**
* Description: Read Cards from a File
*
*
* @requirement output error if _cardsFilePath cannot be opened
* @requirement populate _cards list in the order they are found in the file
* @requirement Every line in the _cardsFilePath is used to create a new Card object using the Card constructor
* @requirement A Card is added to the _cards list only if the Card is valid
* @requirement close the file stream when you are done.
*
*/
void Chars::ReadCardsFromFile() {

    string ncard;
    ifstream inp;
    inp.open(_cardFilePath);
    if(!inp.is_open()){
        cout<<"NOT OPEN";
        inp.close();
        return;
    }
    else{
        while(!inp.eof()){
            getline(inp, ncard);
            Card test = Card(ncard);
            if(test.IsValid() == true){
                _cards.push_back(test);
            }
        }
    }
    inp.close();
}

/**
 * Description: Read Word from a File
 *
 *
 * @requirement output error if _wordsFilePath cannot be opened
 * @requirement populate _words list in the order they are found in the file
 * @requirement Every line in the _wordsFilePath is used to create a new Word object using the Word constructor
 * @requirement A Word is added to the _words list only if the Word is valid
 * @requirement close the file stream when you are done.
 *
 */
void Chars::ReadWordsFromFile() {

    string newword;
    ifstream inp;
    inp.open(_wordFilePath);
    if(!inp.is_open()){
        cout<<"NOT OPEN";
        inp.close();
        return;
    }
    else{
        while(!inp.eof()){
            getline(inp, newword);
            Word test = Word(newword);
            if(test.IsValid() == true){
                _words.push_back(test);
            }
        }
    }
    inp.close();
}

/**
 * Description: Uses _cards and _words lists to populate blanks inside of Card
 * objects in _cards with Word objects in _words
 *
 * @requirement attempt to fill all blanks in the Card objects in _cards with
 * the content of a Word object in _words with the same length as the blank
 * ReplaceBlanks should be used for replacing blanks
 *
 * @requirement If no Word object in _words is of the correct size for a Card object in _cards, then the Card object is removed from _cards using the erase function of the list<> type
 *
 * @requirement Once a Word in _words is used to replace a blank in a Card object in _cards, it is removed from _words using the erase function of the list<> type
 *
 */
void Chars::ProcessCards() {
    int lenc, lenw;
    int found=0;
    list<Card>::iterator cardIt = _cards.begin();
    list<Word>::iterator wordIt;
    
    while(cardIt != _cards.end()){
        found = 0;
        lenc = (*cardIt).GetBlankLength();
        wordIt = _words.begin();
        while(wordIt != _words.end() && (*cardIt).IsValid()){
            lenw = (*wordIt).GetContent().length();
            if(lenc == lenw && (*wordIt).IsValid()){
                cardIt->ReplaceBlanks((*wordIt));
                wordIt = _words.erase(wordIt);
                found = 1;
                break;
            }
            else{
                wordIt++;
            }
        }
        if(found == 0)
            cardIt = _cards.erase(cardIt);
        else
            cardIt++;
        
    }
}

/**
 * Description: Write Cards that have blanks filled with Words to _outputFilePath
 *
 * @requirement output error if _outputFilePath cannot be opened
 * @requirement The _cards list must be sorted according to the length of the card from shortest to longest.
 * if the < operator is properly overloaded, this can be done by calling .sort() on a list
 *
 * @requirement Each Card object in _cards must be output on a new line with a carriage return ("\r\n") at the end
 * @requirement close the file stream when you are done.
 *
 */
void Chars::WriteCardsToFile() {
    ofstream outp;
    outp.open(_outputFilePath);
    if(!outp.is_open()){
        cout<<"NOT OPEN";
        outp.close();
        return;
    }
    else{
        _cards.sort();
        list<Card>::iterator cardIt = _cards.begin();
        while(cardIt != _cards.end()){
            outp<<cardIt->GetContent()<<"\r\n";
            cardIt++;
        }

    }
    outp.close();
}
