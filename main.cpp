#include <iostream>
#include <exception>
#include "Zoo.h"
#include "Animal.h"
#include "Habitat.h"

int encontrarAnimal(int id, Zoo* pZoo){ //Metodo que busca el animal en los habitats, si lo encuentra retorna el indice del habitat y si no retorna un -1

    for(int i = 0; i < pZoo->getHabitats().size(); i++){
        unordered_map<int, Animal*> mapaAnimales = pZoo->getHabitats()[i].getMapa();

        if(mapaAnimales.count(id) == 1){
            cout << "Animal encontrado!\n" << endl;
            return i;
        }
    }
    cout << "El id ingresado no corresponde a ningun animal\n" << endl;
    return -1;
}



void editarDieta(Zoo* pZoo){
    //Permite limitar las entradas del usuario para evitar entradas no deseadas
    string opcionEditar[3] = {"Salir","Agregar alimento", "Eliminar alimento"};
    string opcionDieta[4] = {"Salir", "Carnivoro", "Herbivoro", "Omnivoro"};
    string alimento = "";
    int opcEditar = 0, opcDieta = 0;

    do{
        cout << "\nQue deseas hacer?" << endl;
        for(int i = 0; i != 3; i++){
            cout << i << ") " << opcionEditar[i] << endl;
        }

        cin >> opcEditar;

        if(opcEditar == 1 || opcEditar == 2){
            do{
                cout << "\nQue dieta quieres editar?" << endl;
                for(int i = 0; i != 4; i++){
                    cout << i << ") " << opcionDieta[i] << endl;
                }
                cin >> opcDieta;
            }while(opcDieta < 0 || opcDieta > 3);
        }

        switch(opcEditar){
            case 0:
                break;
            case 1:
                if(opcDieta != 0){
                    cout << "\nIngrese el nombre del alimento a ingresar:" << endl;
                    cin >> alimento;
                    pZoo->agregarAlimento(opcionDieta[opcDieta], alimento);
                }
                break;
            case 2:
                if(opcDieta != 0) {
                    if(pZoo->getComida()[opcionDieta[opcDieta]].empty()){   // accedo al mapa de comida, busco la clave del tipo de dieta y ejecuto la funcion empty al vector de alimentos
                        cout << "\n# La dieta " << opcionDieta[opcDieta] << " no tiene alimentos!" << endl;
                    }else{
                        pZoo->imprimirDieta(opcionDieta[opcDieta]);
                        cout << "\nIngresa el alimento a eliminar:" << endl;
                        cin >> alimento;
                        pZoo->eliminarAlimento(opcionDieta[opcDieta], alimento);
                    }
                }
                break;
            default:
                cout << "\n# Ingresa una opcion valida" << endl;
        }
    }while(opcEditar != 0 && opcDieta != 0);
}

void listarAnimales(Zoo* pZoo){
    vector<Habitat>::iterator itVector;
    int num = 1;
    vector<Habitat> vectorHabitats = (pZoo->getHabitats());
    for (itVector = vectorHabitats.begin(); itVector != vectorHabitats.end(); ++itVector, num++){
        Habitat habitatTemp = *itVector;
        cout <<"\n"<<num << ") ";
        if(itVector->getMapa().empty()){
            cout<<"En "<<itVector->getNombre()<<" de tipo "<<itVector->getTipo()<< " se encuentran:"<<endl;
            cout<<"\tEste habitat esta vacio"<<endl;
        }else{itVector->imprimirAnimales();}
    }
}

int validarAnimal(Zoo* pZoo){  // ingreso del id y validacion de que el animal exista
    int id;

    do{
        listarAnimales(pZoo);
        cout << "Ingrese el id del animal:" << endl;
        cin >> id;

    }while(encontrarAnimal(id, pZoo) == -1);

    return id;
}



int seleccionador(int x, string cadena[]){ //Se asegura de que el usuario no ingrese entradas no deseadas
    int opcTipo;
    do{
        for(int i = 0; i <= x-1; i++){
            cout << i+1 << ") " << cadena[i] << endl;
        }
        try{
            cin >> opcTipo;
            if(cin.fail()){
                throw runtime_error("Entrada invalida: no es un numero entero");
            }
        }catch(runtime_error& e){
            cout<<e.what()<<endl;
        }
    }while(opcTipo < 1 || opcTipo > x);
    return opcTipo;
}

string escogerAccion(){ //Imprime las ordenes que se le pueden dar al animal y la retorna
    string acciones[4] = {"Salir", "Comer", "Jugar", "Dormir"};

    int seleccion = seleccionador(4, acciones);

    return acciones[seleccion-1];
}

void accion(int id, string accion, Zoo* pZoo){ //id: identificador del animal. Acción: orden que se le da al animal. Funciona a modo de menú
    string alimento;
    bool estaComida;
    int estaAnimal = encontrarAnimal(id, pZoo);
    Animal* animTemp = pZoo->getHabitats()[estaAnimal].getMapa()[id];

    if(accion == "Comer"){
        if(pZoo->getComida()[animTemp->getDieta()].empty()){
            cout << "\n# No puede ejecutarse la accion comer, no hay alimentos en la dieta " << animTemp->getDieta() << endl;
        }else{
            do{
                cout << "Ingrese el alimento:" << endl;
                cin >> alimento;
                estaComida = pZoo->buscarComida(animTemp->getDieta(), alimento);
            }while(not estaComida); //Se verifica que el alimento sí pertenezca a la dieta
            animTemp->comer(alimento, true); //El booleano indica si el alimento pertenece a la dieta del animal.
        }

    }else if(accion == "Jugar"){
        pZoo->getHabitats()[estaAnimal].getMapa()[id]->juego();  // No se puede usar animTemp porque no cambiaria el valor bool juego del animal, el cambio no perduraria
    }else if(accion == "Dormir"){
        animTemp->dormir();
    }
}

void nuevoAnimal(Zoo* pZoo){
    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    string tiposDietas[3]={"Carnivoro", "Herbivoro","Omnivoro"};
    //Permiten limitar los tipos de habitats y de dietas que se quieran ingresar
    string especie, nombre, tipoHabitat, tipoDieta, estadoSalud;
    int edad, horasDormir, opcDieta, opcTipo, opcHabitat;
    int id = pZoo->getId(); //Identificador automático para evitar id`s repetidos
    cout<<"Cual es la especie del animal?: "<<endl;
    cin>>especie;
    cout<<"Como se llama?: "<<endl;
    cin>>nombre;
    do{
        cout<<"Cual es su edad?: "<<endl;
        cin>>edad;
    }while(edad<0 || edad>15);
    do{
        cout<<"Cuantas horas necesita dormir?: "<<endl;
        cin>>horasDormir;
    }while(horasDormir<1 || horasDormir>24);
    cout<<"Cual es el estado de salud del animal:"<<endl;
    cin>>estadoSalud;
    cout << "Selecciona el tipo de habitat del animal:" << endl;
    opcTipo = seleccionador(4, tipoHabitats);
    cout << "Selecciona el tipo de dieta:" << endl;
    opcDieta = seleccionador(3, tiposDietas);
    cout<<"Seleccione el habitat para el nuevo animal: "<<endl;
    pZoo->imprimirHabitats();
    vector<Habitat> habitatTemp = (pZoo->getHabitats());
    do{
        cin>>opcHabitat;
        //Se resta 1 porque se imprimen los habitats a partir de esta posición, pero para acceder a ellos con índice la primera posición es 0 (una menos)
        if(habitatTemp[opcHabitat-1].getTipo()!=tipoHabitats[opcTipo-1]){
            cout<<nombre<<" no pertenece a un habitat de tipo "<<habitatTemp[opcHabitat-1].getTipo()<<endl;
        }
    }while(habitatTemp[opcHabitat-1].getTipo()!=tipoHabitats[opcTipo-1]); //Verifica que el animal si pueda pertenecer al habitat que se quiere agregar
    Animal* temp = new Animal(nombre, especie, tipoHabitats[opcTipo-1], tiposDietas[opcDieta-1], estadoSalud, id, edad, horasDormir, false);
    habitatTemp[opcHabitat-1].agregarAnimal(temp); //Agrega los animales a un vector temporal para asignarlo completo al Zoo
    pZoo->setVector(habitatTemp);
    pZoo->setId(id + 1);
}

void anadirHabitat(Zoo* pZoo){

    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    int opcTipo = 0;
    string nombreHabitat;

    cout << "Ingrese el nombre del nuevo habitat:" << endl;
    cin >> nombreHabitat;
    cout << "Selecciona el tipo de habitat:" << endl;
    opcTipo = seleccionador(4, tipoHabitats);

    unordered_map<int, Animal*> mapaAnimales;

    Habitat habTemp(nombreHabitat, tipoHabitats[opcTipo-1], mapaAnimales);  //opcTipo-1 porque recibe el numeral de seleccion y se lo necesita como indice del arreglo tipoHabitats
    pZoo->agregarHabitat(habTemp);
}

void menu(Zoo* pZoo){
    int opcion = 0;
    int id;
    string accionSel;

    cout << "########################\nBienvenido al SendoZoo!\n########################" << endl;
    int flag = 0;
    do{
        cout << "\nQue deseas hacer?" << endl;
        string opcionesMenu[6] = {"Salir","Anadir habitat", "Anadir animal", "Listar habitats y animales", "Realizar accion", "Editar dietas"};
        for(int i = 0; i != 6; i++){
            cout << i << ") " << opcionesMenu[i] << endl;
        }
        cin>>opcion;

        switch(opcion){
            case 0:
                break;
            case 1:
                anadirHabitat(pZoo);
                break;
            case 2:
                if(pZoo->getHabitats().empty()){
                    cout << "\n# No hay habitats para recibir animales!" << endl;
                }else{
                    nuevoAnimal(pZoo);
                    flag = 1; //Permite conocer si ya se han agregado animales al Zoo para no tener problemas con otras funciones
                }
                break;
            case 3:
                listarAnimales(pZoo);
                break;
            case 4:
                if(flag==0){
                    cout<<"Aun no hay animales en el SendoZoo\n"<<endl;
                }else {
                    accionSel = escogerAccion();
                    if (accionSel != "Salir") {
                        id = validarAnimal(pZoo);
                        accion(id, accionSel, pZoo);
                    }
                }
                break;
            case 5:
                editarDieta(pZoo); //Permite agregar y eliminar alimentos
                break;
            default:
                cout << "\n# Ingresa una opcion valida!" << endl;
        }
    }while(opcion != 0);

}


int main(){
    Zoo *pZoo = new Zoo;

    pZoo->setId(1);
    menu(pZoo);
    /*anadirHabitat(pZoo);
    anadirHabitat(pZoo);
    nuevoAnimal(pZoo);
    enlistarAnimales(pZoo);*/
    return 0;
}