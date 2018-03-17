//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef TRENDING_H
#define TRENDING_H

#include <string>
#include <vector>
#include "Hashtag.h"

class Trending{
private:
    std::string _startHashtagFilePath;
    std::string _endHashtagFilePath;
    std::string _outputHashtagFilePath;
    std::vector<Hashtag> start;
    std::vector<Hashtag> end;
    
    
public:
    Trending(std::string startHashtagFilePath, std::string endHashtagFilePath, std::string outputHashtagFilePath);
    void Run();
    void ReadStartfromFile();
    void ReadEndfromFile();
    void WriteToFile();
    void RankStart();
    void RankEnd();
    
};
#endif /* Trending_hpp */
