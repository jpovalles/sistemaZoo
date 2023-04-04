//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_AEREO_H
#define SISTEMAZOO_AEREO_H

#include "Animal.h"
#include "Zoo.h"

class Aereo : public Animal{
public:
    void juego();
    void comer(string alimento, bool dieta);
    void dormir();
};


#endif //SISTEMAZOO_AEREO_H
