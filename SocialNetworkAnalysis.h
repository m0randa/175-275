//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef SOCIALNETWORKANALYSIS_H
#define SOCIALNETWORKANALYSIS_H

#include <string>

class SocialNetworkAnalysis{
private:
    std::string _inputFilePath;
    std::string _outputFilePath;
public:
    SocialNetworkAnalysis(std::string inputFilePath, std::string ouputFilePath);
    void Run();
};
#endif /* SocialNetworkAnalysis_hpp */
