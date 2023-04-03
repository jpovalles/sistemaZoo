//
// Created by LENOVO on 03/04/2023.
//

#include "Zoo.h"

void Zoo::agregarHabitat(string nombre, string tipo, vector<Animal> listaAnimales){
    Habitat* pHabitatTemp = new Habitat(nombre, tipo, listaAnimales);
    this->listaHabitats.push_back(*pHabitatTemp);
}

vector<Habitat> Zoo::getHabitats(){
    return listaHabitats;
}

unordered_map<string, vector<string>> Zoo::getComida(){
    return comida;
}