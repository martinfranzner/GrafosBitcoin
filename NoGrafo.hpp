//
//  NoGrafo.hpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 23/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef NoGrafo_hpp
#define NoGrafo_hpp

#include <string>
#include <stdio.h>
using namespace std;

class NoGrafo {
    string nome = "";
    
public:
    NoGrafo();
    void addAdjNome(string nm){this->nome = nm;};
    string getAdjNome(){return this->nome;};
};

#endif /* NoGrafo_hpp */
