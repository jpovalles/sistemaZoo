//
// Created by jpova on 3/04/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string tipoHabitat, string dieta, string estadoSalud, int id, int edad, int horasDormir, bool jugar):nombre(std::move(nombre)), especie(std::move(especie)), tipoHabitat(std::move(tipoHabitat)), dieta(std::move(dieta)), estadoSalud(estadoSalud), id(id), edad(edad), horasDormir(horasDormir), jugar(jugar) {}

void Animal::juego() {
    if(this->jugar){
        cout << this->nombre << " esta cansado para jugar" << endl;
    }else{
        cout << this->nombre << " se divirtio jugando!" << endl;
    }

    this->jugar = not this->jugar;  // El cansancio del animal va a hacer intermitente entre instancias de ejecucion del codigo
}

void Animal::dormir(){
    int inHoras;

    do{
        cout << "Ingresa las horas a dormir: " << endl;
        cin >> inHoras;
        if(inHoras < this->horasDormir){
            cout << this->nombre << " necesita dormir mas!\n" << endl;
        }else if(inHoras > this->horasDormir){
            cout << this->nombre << " no puede dormir tanto!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Muy bien! " << this->nombre << " descanso lo suficiente.\n" << endl;
}

void Animal::comer(string alimento, bool dieta) {
    if (dieta) {
        cout << "" << this->nombre << " esta comiendo " << alimento << "\n" << endl;
    } else {
        cout << "" << alimento << " no pertenece a la dieta de " << this->especie << " " << this->nombre << "\n" << endl;
    }
}


string Animal::getNombre(){
    return this->nombre;
}


string Animal::getEspecie() {
    return this->especie;
}

string Animal::getTipoHabitat() {
    return this->tipoHabitat;
}


string Animal::getDieta() {
    return this->dieta;
}

int Animal::getId() {
    return this->id;
}


int Animal::getEdad() {
    return this->edad;
}



string Animal::getSalud() {
    return this->estadoSalud;
}