//
//  ReadFile.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 21/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//
#include <fstream>
#include "ReadFile.hpp"
ReadFile::ReadFile(){
    
}
vector<string>ReadFile::readByLine(string fileToRead)
{
    vector<string> L;
    string line;
    ifstream myfile (fileToRead);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            L.push_back(line);
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    return L;
}
