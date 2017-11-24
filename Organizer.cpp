//
//  Organizer.cpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 18/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Organizer.hpp"
Organizer::Organizer() {
    
}
int Organizer::getOrigem(string origem,vector<pair<int,string>>verticesMap){
    for(auto it : verticesMap){
        if(it.second == origem){
            return it.first;
        }
    }
    return -1;
}
int Organizer::getDestino(string destino,vector<pair<int,string>>verticesMap){
    for(auto it : verticesMap){
        if(it.second == destino){
            return it.first;
        }
    }
    return -1;
}
vector<int> Organizer::preparaVerticesAero(vector<string> linesOfTheFile){
    int j = 0;
    string aux = "";
    vector<int> vertices;
    char delimitadores[] = ",\n\r    ";
    vector<string> stringSplitada;
    for(auto itera : linesOfTheFile){
        if(j !=0){
            stringSplitada = splitT(itera, delimitadores);
            vertices.push_back(atoi(stringSplitada.at(0).c_str()));//arrumar conforme a base
            vertices.push_back(atoi(stringSplitada.at(1).c_str()));
        }
        j++;
//        for(auto itvet : stringSplitada){
//            cout<<itvet<<endl;
//        }
//        cout<<"--------"<<endl;

    }
    
    return vertices;
}
vector<pair<int,string>> Organizer::preparaVertices(vector<string> linesOfTheFile){
    
        int j = 0;
        string aux = "";
        int indexVertice = 0;
        vector<pair<int,string>> vertices;

        for(auto itera2 : linesOfTheFile){
            if(j != 0){
                aux = itera2.substr(0,5); 
                indexVertice = atoi(aux.c_str());;
                aux = itera2.substr(6, itera2.length());
                vertices.push_back(make_pair(indexVertice,aux));
            }
            j++;
                    if(indexVertice == 13356)
                        break;
        }
//            for (auto bla : vertices){
//                cout<<bla.first<<"---"<<bla.second<<endl;
//        
//            }
        return vertices;
}
vector<Adjacencias> Organizer::preparaAdjacencias(vector<string> linesOfTheFile){
    int j =0;
    char delimitadores[] = " <>[],;-\n\r    ";
    vector<string> stringSplitada;
    vector<Adjacencias> adjVet;
    for(auto itera : linesOfTheFile){
        if(j!=0){
            stringSplitada = splitT(itera, delimitadores);
            Adjacencias a;
            a.orig = stringSplitada.at(0);
            a.dest = stringSplitada.at(1);
            a.peso = atoi(stringSplitada.at(2).c_str());
            adjVet.push_back(a);
            
//            for(auto itvet : stringSplitada){
//                cout<<itvet<<endl;
//            }
        }
        j++;
    }
    return adjVet;
}


vector<string> Organizer::splitT1(char * str, char * delimiter){
    vector<string> * v = new vector<string>();
    
    char * pch;
    char *next_token = NULL;
    
    pch = strtok_r(str, delimiter, &next_token);
    
    while (pch != NULL)
    {
        v->push_back(pch);
        
        pch = strtok_r(NULL, delimiter, &next_token);
    }
    
    return *v;
}

vector<string> Organizer::splitT(const string str, const string delimiter){
    return splitT1((char *)str.c_str(), (char *)delimiter.c_str());
}

