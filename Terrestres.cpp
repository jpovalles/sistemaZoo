//
// Created by LENOVO on 03/04/2023.
//

#include "Terrestres.h"

int Terrestres::comer(string alimento, Zoo zoologico){
    unordered_map mapaDieta = zoologico.getComida();
    vector<string> vectorDieta = mapaDieta[this->dieta];

    vector<string>::iterator itVector;

    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        //string comida = *itVector;
        if(*itVector == alimento){
            cout << this->nombre << " fue alimentado con " << alimento << endl;
            return 1;
        }else if(itVector == vectorDieta.end()){
            cout << this->nombre << " no puede comer " << alimento << endl;
            return 0;
        }
    }
}

void Terrestres::juego() {
    if(this->jugar){
        cout << this->nombre << " esta cansado para jugar" << endl;
    }else{
        cout << this->nombre << " se divirtio jugando!" << endl;
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
            cout << this->nombre << " no puede dormir tanto!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Muy bien! " << this->nombre << " descanso lo suficiente.\n" << endl;
}
