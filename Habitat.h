//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_HABITAT_H
#define SISTEMAZOO_HABITAT_H

#include<string>
#include<iostream>
#include<vector>
#include"Animal.h"

using namespace std;

class Habitat {
private:
    string nombre;
    string tipo;
    vector<Animal> listaAnimales;
public:
    Habitat(string nombre, string tipo, vector<Animal> listaAnimales);
    string getNombre();
    string getTipo();
    vector<Animal> getLista();
    void agregarAnimal(Animal tempAnimal);
};


#endif //SISTEMAZOO_HABITAT_H
