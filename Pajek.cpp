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
            //file << i << " " <<"'" <<x.second<<"'"<<endl;
            file << i << " " <<x.second<<endl;
            i++;
        }
        file << "*Arcs" << endl;
        i = 1;
        for (auto x : adjVet) {
 
            file <<x.orig << " " << x.dest << " " << x.peso<<endl;

        }
    }
}
Grafo* Pajek::readPajek(){
    vector<string> L;
    string fileToRead("/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/pajekGrafo.txt");
    ReadFile rf;
    L = rf.readByLine(fileToRead);
    //char delimitadores[] = " <>[],;-\n\r    ";
    vector<pair<int,string>>verticesMap;
    vector<Adjacencias> adjVet;
    Organizer p;
    verticesMap = p.preparaVerticesFromPajek(L);
    adjVet = p.preparaAdjacenciasFromPajek(L);
    int size =0;
    for(auto itera : verticesMap){
        size++;
    }
    
    
    Grafo *g = new Grafo(size+1);
    
    for(auto it : adjVet){
        int origem = p.getOrigem(it.orig, verticesMap);
        int destino = p.getDestino(it.dest, verticesMap);
        g->criaAdjacenciaPeso(origem, destino, it.peso);
        
        
    }
    

    return g;
}
