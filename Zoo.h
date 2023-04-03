//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_ZOO_H
#define SISTEMAZOO_ZOO_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include"Habitat.h"
#include"Animal.h"

using namespace std;

class Zoo {
private:
    unordered_map<string, vector<string>> comida;
    vector<Habitat> listaHabitats;
public:
    Zoo() = default;
    void agregarHabitat(string nombre, string tipo, vector<Animal> listaAnimales);
    vector<Habitat> getHabitats();
    unordered_map<string, vector<string>> getComida();
};


#endif //SISTEMAZOO_ZOO_H
