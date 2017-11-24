//
//  Pajek.cpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 24/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Pajek.hpp"
Pajek::Pajek(){
    
}

void Pajek::createPajek(Grafo *G,vector<pair<int,string>>verticesMap,vector<Adjacencias> adjVet) {
    ofstream file("/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/pajekGrafo.txt");
    int i = 1;

    if (file.is_open()) {
        file << "*Vertices " << G->getTamanho() << endl;
        for (auto x : verticesMap) {
            file << i << " " <<"'" <<x.second<<"'"<<endl;
            i++;
        }
        file << "*Arcs" << endl;
        i = 1;
        for (auto x : adjVet) {
 
            file <<x.orig << " " << x.dest << " " << x.peso<<endl;

        }
    }
}
