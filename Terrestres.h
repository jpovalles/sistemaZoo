//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_TERRESTRES_H
#define SISTEMAZOO_TERRESTRES_H

#include "Animal.h"
#include "Zoo.h"

class Terrestres : public Animal{
public:
    void juego();
    void comer(string alimento, bool dieta);
    void dormir();
};


#endif //SISTEMAZOO_TERRESTRES_H
