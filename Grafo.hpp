//
//  Grafo.hpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 22/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Grafo_hpp
#define Grafo_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>
#include "No.hpp"
#include "NoGrafo.hpp"

using namespace std;
class Grafo {
private:
    int tamanho;
    //list<int>* matrizAdj;
    list<No>* matrizAdj;
    NoGrafo *vertice;
    
public:
    Grafo(int tamanho);//ja cria a matriz
    int getTamanho(){return this->tamanho;};
    void criaAdjacencia(int lin, int adjasen);//bota valor na matriz
    void criaAdjacenciaPeso(int lin, int adjasen, int peso);
    void removeAdjacencia(int lin, int col);// bota valor como NULL
    int existeAdjascencia(int lin, int adj);
    void imprimeAdjacencia();//imprime a matriz
    int adjacentes(int linha, int v[]); //mostra o numero de adjacencias em cada linha
    void setaInformacao();
    void imprimeInformacao();
    void DFS(int origem, bool visitado[]);
    bool ciclo(int origem, bool visitado[]);
    bool conexo(int origem, bool visitado[]);
    void PRIM(int start);
};
#endif /* Grafo_hpp */
