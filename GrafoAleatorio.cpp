//
//  GrafoAleatorio.cpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 28/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "GrafoAleatorio.hpp"
GrafoAleatorio::GrafoAleatorio(){
    
}

void GrafoAleatorio::criaGrafoConexo(Grafo *g){
    //Grafo *g = new Grafo(size);
    int size = g->getTamanho();
    int arestas = 0;
    while(arestas < (size-1)){
    cout<<"Digite numero de arestas(no minino igual o numero de (vertices-1)): "<<endl;
    cin>>arestas;
    }
    int i;
    int arestasRestantes = arestas - size;
    if(arestasRestantes == 0){
        for(i=0; i <(size-1); i++){
            g->criaAdjacencia(i, (i+1));
        }
        g->criaAdjacencia(i, 0);
    }
    else if(arestasRestantes == -1){
        for(i=0; i <(size-1); i++){
            g->criaAdjacencia(i, (i+1));
        }
    }
    else {
        
        for(i=0; i <(size-1); i++){
            g->criaAdjacencia(i, (i+1));
        }
        g->criaAdjacencia(i, 0);
        for(i=0; i < arestasRestantes; i++){
            g->criaAdjacencia(i, (rand()%size));
        }
    }

}

void GrafoAleatorio::criaGrafoNaoConexo(Grafo *g){
    int size = g->getTamanho();
    int arestas = -1;
    int i;
    while(arestas < 0){
        cout<<"Digite numero de arestas: "<<endl;
        cin>>arestas;
    }
    if(arestas < (size-1)){
        for(i=0; i < arestas; i++){
            g->criaAdjacencia(i, (i+1));
        }
    }
    else {
        int contAresta = 0,aux = 0;
        int sizeHalf = size/2;
        int i=0,j=1;
        while(contAresta < arestas){
            
            if(contAresta < arestas){
              
            g->criaAdjacencia(i, rand()%(sizeHalf+1));
                contAresta++;
            }
            if(contAresta < arestas){
            g->criaAdjacencia(sizeHalf+j, rand()% (size-sizeHalf)+(sizeHalf+1));
                contAresta++;
            }
            j++;
            i++;
            cout<<j<<endl;
            if(sizeHalf+j >= size)
                j=1;
        }
    }
 
}




