//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_ACUATICO_H
#define SISTEMAZOO_ACUATICO_H

#include "Animal.h"
#include "Zoo.h"

class Acuatico : public Animal{
public:
    void juego();
    void comer(string alimento, bool dieta);
    void dormir();
};


#endif //SISTEMAZOO_ACUATICO_H
