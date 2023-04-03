//
// Created by LENOVO on 03/04/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, string tipo, vector<Animal> listaAnimales):nombre(nombre), tipo(tipo), listaAnimales(listaAnimales){}

string Habitat::getNombre(){
    return nombre;
}

string Habitat::getTipo(){
    return tipo;
}

vector<Animal> Habitat::getLista(){
    return listaAnimales;
}

void agregarAnimal(Animal tempAnimal){
    this->listaAnimales.push_back(tempAnimal);
    cout<<""<<"fue agregado al habitat"<<endl;
}