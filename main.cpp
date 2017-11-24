//
//  main.cpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 14/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "ReadFile.hpp"
#include "Organizer.hpp"
#include "Grafo.hpp"
#include "Pajek.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
 
    ifstream file;
    string instructionsPath = "/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/bitcoinotc.csv";
    string instructionsPath2 = "/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/baseBigVoos.txt";
    
    vector<string> linesOfTheFile;
    ReadFile r;
    linesOfTheFile = r.readByLine(instructionsPath);
    //vector<pair<int,string>> vertices;
    vector<int> vertices;
    vector<pair<int,string>>verticesMap;
    vector<Adjacencias> adjVet;
    Organizer p;
    vertices = p.preparaVerticesAero(linesOfTheFile);
    adjVet = p.preparaAdjacencias(linesOfTheFile);
    sort(vertices.begin(), vertices.end());
    vertices.erase( unique( vertices.begin(), vertices.end() ), vertices.end() );
    int i =0;
    for(auto m :vertices){
        verticesMap.push_back(make_pair(i,to_string(m)));
        i++;
    }
    
    Grafo *g = new Grafo(vertices.size());
    
    for(auto it : adjVet){
        int origem = p.getOrigem(it.orig, verticesMap);
        int destino = p.getDestino(it.dest, verticesMap);
        g->criaAdjacenciaPeso(origem, destino, it.peso);
        
// como o peso nao vai ser o numero de vezes que ocorre o link e sim outro paramentro nao vai mais precisar disso
//        if(origem != -1 && destino != -1){
//            if(g->existeAdjascencia(origem, destino)==1){
//                //verificou a adjascencia e ja adicionou um peso a mais
//            }
//            else{ // aqui vai criar a adjascencia
//                g->criaAdjacencia(origem, destino);
//            }
//        }
    }
    Pajek pj;
    pj.createPajek(g, verticesMap, adjVet);
     //g->imprimeAdjacencia();

    
//    int i= 1;
//        for(auto itera : vertices){
//            cout<<i <<" - "<<itera<<endl;
//            i++;
//        }
//
//    int i= 1;
//    for(auto itera : adjVet){
//        cout<<i <<": "<<itera.orig<<" - "<<itera.dest<<endl;
//        i++;
//    }

//    for(auto itera : linesOfTheFile){
//        cout<<itera<<endl;
//    }


    return 0;
}
