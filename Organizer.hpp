//
//  Organizer.hpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 18/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Organizer_hpp
#define Organizer_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Adjacencias {
    string orig;
    string dest;
    int peso;
};

using namespace std;
class Organizer {
    
    
public:
    Organizer();
    int getOrigem(string origem,vector<pair<int,string>>verticesMap);
    int getDestino(string destino,vector<pair<int,string>>verticesMap);
    
    vector<int> preparaVerticesAero(vector<string> linesOfTheFile);
    
    vector<pair<int,string>> preparaVertices(vector<string> linesOfTheFile);
    vector<Adjacencias> preparaAdjacencias(vector<string> linesOfTheFile);
    
    vector<string> splitT(const string str, const string delimiter);
    vector<string> splitT1(char * str, char * delimiter);
};
#endif /* Organizer_hpp */
