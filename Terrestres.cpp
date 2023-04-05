//
// Created by LENOVO on 03/04/2023.
//

#include "Terrestres.h"

void Terrestres::comer(string alimento, bool dieta){
    if(dieta){
        cout<<""<<this->nombre<<" se escondio rapidamente para disfrutar de su "<<alimento<<"\n"<<endl;
    }else{
        cout<<""<<alimento<<" no pertenece a la dieta de "<<this->nombre<<"\n"<<endl;
    }
}

void Terrestres::juego() {
    if(this->jugar){
        cout << this->nombre << " esta cansado para jugar" << endl;
    }else{
        cout << this->nombre << " esta corriendo alrededor del habitat para aumentar su diversion!" << endl;
    }

    this->jugar = not this->jugar;
}

void Terrestres::dormir(){
    int inHoras;

    do{
        cout << "Ingresa las horas a dormir: " << endl;
        cin >> inHoras;
        if(inHoras < this->horasDormir){
            cout << this->nombre << " necesita dormir mas!\n" << endl;
        }else if(inHoras > this->horasDormir){
            cout << this->nombre << " no debe dormir tanto!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Muy bien! " << this->nombre << " ahora esta corriendo hacia su lugar seguro para descansar.\n" << endl;
}
