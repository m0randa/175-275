//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Hashtag.h"
#include <algorithm>

using namespace std;

Hashtag::Hashtag(string word){
    SetWord(word);
    SetStartRank(0);
    SetEndRank(0);
    _startCount =0;
    _endCount = 0;
    
}
void Hashtag::Convert(){
    //unsigned int i;
    replace( _word.begin(), _word.end(), 'A', 'a' );
    replace( _word.begin(), _word.end(), 'B', 'b' );
    replace( _word.begin(), _word.end(), 'C', 'c' );
    replace( _word.begin(), _word.end(), 'D', 'd' );
    replace( _word.begin(), _word.end(), 'E', 'e' );
    replace( _word.begin(), _word.end(), 'F', 'f' );
    replace( _word.begin(), _word.end(), 'G', 'g' );
    replace( _word.begin(), _word.end(), 'H', 'h' );
    replace( _word.begin(), _word.end(), 'I', 'i' );
    replace( _word.begin(), _word.end(), 'J', 'j' );
    replace( _word.begin(), _word.end(), 'K', 'k' );
    replace( _word.begin(), _word.end(), 'L', 'l' );
    replace( _word.begin(), _word.end(), 'M', 'm' );
    replace( _word.begin(), _word.end(), 'N', 'n' );
    replace( _word.begin(), _word.end(), 'O', 'o' );
    replace( _word.begin(), _word.end(), 'P', 'p' );
    replace( _word.begin(), _word.end(), 'Q', 'q' );
    replace( _word.begin(), _word.end(), 'R', 'r' );
    replace( _word.begin(), _word.end(), 'S', 's' );
    replace( _word.begin(), _word.end(), 'T', 't' );
    replace( _word.begin(), _word.end(), 'U', 'u' );
    replace( _word.begin(), _word.end(), 'V', 'v' );
    replace( _word.begin(), _word.end(), 'W', 'w' );
    replace( _word.begin(), _word.end(), 'X', 'x' );
    replace( _word.begin(), _word.end(), 'Y', 'y' );
    replace( _word.begin(), _word.end(), 'Z', 'z' );
}

bool Hashtag::operator<(const Hashtag& rhs) const{
    if(rhs.GetEndCount() < this->GetEndCount()){
        return true;
    }
    else if(rhs.GetEndCount() == this->GetEndCount() && rhs.GetEndCount() != 0 && this->GetEndCount() != 0 && this->GetWord().compare(rhs.GetWord()) < 0)
        return true;
    else if(rhs.GetEndCount() == 0 && this->GetEndCount() == 0 && rhs.GetStartCount() < this->GetStartCount())
        return true;
    else if(rhs.GetEndCount() == 0 && this->GetEndCount() == 0 && rhs.GetStartCount() == this->GetStartCount() && this->GetWord().compare(rhs.GetWord()) < 0)
        return true;
    else
        return false;
}
