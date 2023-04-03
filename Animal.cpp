//
// Created by jpova on 3/04/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string tipoHabitat, string dieta, int id, int edad, int horasDormir,
               bool jugar):nombre(nombre), especie(especie), tipoHabitat(tipoHabitat), dieta(dieta), id(id), edad(edad), horasDormir(horasDormir), jugar(jugar) {}

void Animal::setNombre(string nombre){
    this->nombre = nombre;
}

string Animal::getNombre(){
    return this->nombre;
}

void Animal::setEspecie(string especie){
    this->especie = especie;
}

string Animal::getEspecie() {
    return this->especie;
}

void Animal::setTipoHabitat(string tipoHabitat) {
    this->tipoHabitat = tipoHabitat;
}

string Animal::getTipoHabitat() {
    return this->tipoHabitat;
}

void Animal::setDieta(string dieta) {
    this->dieta = dieta;
}

string Animal::getDieta() {
    return this->dieta;
}

void Animal::setId(int Id) {
    this->id = Id;
}

int Animal::getId() {
    return this->id;
}

void Animal::setEdad(int Edad) {
    this->edad = Edad;
}

int Animal::getEdad() {
    return this->edad;
}

void Animal::setHorasDormir(int horasDormir){
    this->horasDormir = horasDormir;
}

int Animal::getHorasDormir(){
    return this->horasDormir;
}

void Animal::setJugar(bool jugar) {
    this->jugar = jugar;
}

bool Animal::getJugar() {
    return this->jugar;
}