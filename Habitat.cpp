//
// Created by LENOVO on 03/04/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, string tipo, unordered_map<int, Animal>* mapaAnimales): nombre(nombre), tipo(tipo), mapaAnimales(mapaAnimales){}

string Habitat::getNombre(){
    return nombre;
}

string Habitat::getTipo(){
    return tipo;
}

unordered_map<int, Animal>* Habitat::getMapa(){
    return mapaAnimales;
}

void Habitat::agregarAnimal(Animal tempAnimal){
    this->mapaAnimales->insert(make_pair(tempAnimal.getId(), tempAnimal));
    cout<<""<<"fue agregado al habitat"<<endl;
}

void Habitat::imprimirAnimales(){
    
}