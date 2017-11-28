//
//  GrafoAleatorio.hpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 28/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef GrafoAleatorio_hpp
#define GrafoAleatorio_hpp

#include <stdio.h>
#include "Grafo.hpp"
#include <iostream>
#include <string>
#include <list>
#include <time.h> 

using namespace std;
class GrafoAleatorio {
private:
    
public:
    GrafoAleatorio();
    void criaGrafoConexo(Grafo *g);
    void criaGrafoNaoConexo(Grafo *g);
};
#endif /* GrafoAleatorio_hpp */
