//
// Created by LENOVO on 03/04/2023.
//

#include "Zoo.h"

void Zoo::agregarHabitat(Habitat habitatTemp){
    this->listaHabitats.push_back(habitatTemp);
}

vector<Habitat> Zoo::getHabitats(){
    return listaHabitats;
}

unordered_map<string, vector<string>> Zoo::getComida(){
    return comida;
}

bool Zoo::buscarComida(string tipoDieta, string alimento){
    vector<string> vectorDieta = this->comida[tipoDieta];
    vector<string>::iterator itVector;

    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        //string comida = *itVector;
        if(*itVector == alimento){
            return true;
        }
    }
    return false;
}