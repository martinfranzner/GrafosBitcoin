//
//  ReadFile.hpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 21/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef ReadFile_hpp
#define ReadFile_hpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <stdio.h>
using namespace std;
class ReadFile {
private:
    
public:
    ReadFile();
    vector<string> readByLine(string fileToRead);
};
#endif /* ReadFile_hpp */
