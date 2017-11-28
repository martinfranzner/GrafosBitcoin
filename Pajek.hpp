//
//  Pajek.hpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 24/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Pajek_hpp
#define Pajek_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Grafo.hpp"
#include "Organizer.hpp"
#include "ReadFile.hpp"

using namespace std;
class Pajek {
private:
    
public:
    Pajek();
    void createPajek(Grafo *G,vector<pair<int,string>>verticesMap,vector<Adjacencias> adjVet);
    Grafo* readPajek();
};
#endif /* Pajek_hpp */
