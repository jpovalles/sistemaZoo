//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_HABITAT_H
#define SISTEMAZOO_HABITAT_H

#include<string>
#include<iostream>
#include<unordered_map>
#include"Animal.h"

using namespace std;

class Habitat {
private:
    string nombre;
    string tipo;
    unordered_map<int, Animal*>* mapaAnimales;
public:
    Habitat(string nombre, string tipo, unordered_map<int, Animal*>* mapaAnimales);
    string getNombre();
    string getTipo();
    unordered_map<int, Animal*>* getMapa();
    void agregarAnimal(Animal *tempAnimal);
    void imprimirAnimales();
};


#endif //SISTEMAZOO_HABITAT_H
