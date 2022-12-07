/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

/////////////////////////////////////////////////////////////////////ESTRUCTURA////////////////////////////////////////////////////////////////////

typedef struct{
int id;
char nombre[20];
char sexo;
float sueldo;
}eEmpleado;

//////////////////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES//////////////////////////////////////////////////////////////

int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados(LinkedList* lista);

int compararLegajo(void*a, void* b);
int compararNombre(void*a, void* b);
///////////////////////////////CONSTRUCTOR

eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo);

///////////////////////////////DESTRUCTOR

void empleadoDestroy(eEmpleado* pEmpleado);

///////////////////////////////SETTERS

int empleadoSetId(eEmpleado* pEmpleado, int id);
int empleadoSetNombre(eEmpleado* pEmpleado, char* nombre);
int empleadoSetSexo(eEmpleado* pEmpleado, char sexo);
int empleadoSetSueldo(eEmpleado* pEmpleado, float sueldo);

///////////////////////////////GETTERS

int empleadoGetId(eEmpleado* pEmpleado, int* pId);
int empleadoGetNombre(eEmpleado* pEmpleado, char* pNombre);
int empleadoGetSexo(eEmpleado* pEmpleado, char* pSexo);
int empleadoGetSueldo(eEmpleado* pEmpleado, float* pSueldo);

////////////////////////////////////////////////////////////////////////MAIN///////////////////////////////////////////////////////////////////////
int main(void){
/*
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
*/

	eEmpleado* auxEmpleado;

	printf("------Creo el LinkedList (ll_newLinkedList)------\n");
	LinkedList* listaEmpleados = ll_newLinkedList();

	if(listaEmpleados == NULL)
	{
		printf("No se pudo crear la linkedlist\n");
		exit(1);
	}
	printf("------Muestro el tamanio de la LinkedList (ll_len)------\n");
	printf("Tam:%d\n", ll_len(listaEmpleados));

	auxEmpleado = new_EmpleadoParam(1234, "Santino", 'm', 15000);

	ll_add(listaEmpleados, auxEmpleado);

	mostrarEmpleado(auxEmpleado);

	printf("Tam:%d\n", ll_len(listaEmpleados));


	auxEmpleado = new_EmpleadoParam(4231, "Eluney", 'f', 20000);

	ll_add(listaEmpleados, auxEmpleado);
	auxEmpleado = new_EmpleadoParam(2421, "Tomi", 'm', 18000);

	ll_add(listaEmpleados, auxEmpleado);

	printf("------Antes del (ll_push)------\n");
	mostrarEmpleados(listaEmpleados);

	auxEmpleado = new_EmpleadoParam(7341, "Olivia", 'f', 500);
	ll_push(listaEmpleados, 1, auxEmpleado);

	printf("------Despues del push (ll_push)------\n");

	mostrarEmpleados(listaEmpleados);

	printf("------Piso a Tomi con Gustavo (ll_set)------\n");
	auxEmpleado = new_EmpleadoParam(7822, "Gustavo", 'm', 60000);
	ll_set(listaEmpleados, 3, auxEmpleado);
	mostrarEmpleados(listaEmpleados);

	printf("------Elimino a Olivia (ll_remove)------\n");
	ll_remove(listaEmpleados, 1);
	mostrarEmpleados(listaEmpleados);

	printf("------Extraigo a Santino y lo elimino (ll_pop)------\n");
	auxEmpleado = (eEmpleado*) ll_pop(listaEmpleados, 0);

	mostrarEmpleado(auxEmpleado);
	mostrarEmpleados(listaEmpleados);

	printf("******Agrego mas empleados (ll_add)******\n");
	auxEmpleado = new_EmpleadoParam(7211, "Nadia", 'f', 100);
	ll_add(listaEmpleados, auxEmpleado);
	auxEmpleado = new_EmpleadoParam(3621, "Joaco", 'm', 12000);
	ll_add(listaEmpleados, auxEmpleado);
	auxEmpleado = new_EmpleadoParam(9134, "Naomi", 'f', 19600);
	ll_add(listaEmpleados, auxEmpleado);
	mostrarEmpleados(listaEmpleados);

	printf("------Mustra el indice en el que se encuentra la persona indicada, es este caso Naomi (ll_indexOf)------\n\n");
	printf("%d\n", ll_indexOf(listaEmpleados, auxEmpleado));

	printf("------Mustra si el indice esta lleno(1) o vacio(0) (ll_contains)------\n\n");
	printf("%d\n", ll_contains(listaEmpleados, auxEmpleado));

	printf("******Agrego mas empleados (ll_add)******\n");
	auxEmpleado = new_EmpleadoParam(6123, "Pedro", 'm', 12335);
	ll_add(listaEmpleados, auxEmpleado);
	auxEmpleado = new_EmpleadoParam(3621, "Maria", 'f', 12546);
	ll_add(listaEmpleados, auxEmpleado);
	auxEmpleado = new_EmpleadoParam(9134, "Florencia", 'f', 47211);
	ll_add(listaEmpleados, auxEmpleado);
	mostrarEmpleados(listaEmpleados);

	printf("------Creo SubLista (ll_subList)------\n\n");
	LinkedList* lista2 = ll_subList(listaEmpleados, 4, 8);

	printf("******Lista 2****** \n\n");
	mostrarEmpleados(lista2);

	printf("------Ordeno la lista de forma creciente por legajo(ll_sort)------\n\n");
	ll_sort(listaEmpleados, compararLegajo, 1);
	mostrarEmpleados(listaEmpleados);

	printf("------Ordeno la lista de forma decreciente por legajo(ll_sort)------\n\n");
	ll_sort(listaEmpleados, compararLegajo, 0);
	mostrarEmpleados(listaEmpleados);

	printf("------Ordeno la lista de forma creciente por nombre(ll_sort)------\n\n");
	ll_sort(listaEmpleados, compararNombre, 1);
	mostrarEmpleados(listaEmpleados);

	printf("------Ordeno la lista de forma decreciente por nombre(ll_sort)------\n\n");
	ll_sort(listaEmpleados, compararNombre, 0);
	mostrarEmpleados(listaEmpleados);

	printf("------Elimino a TODOS(ll_clear)------\n\n");
	ll_clear(listaEmpleados);
	mostrarEmpleados(listaEmpleados);

	printf("------Elimino la LinkedList(ll_deleteLinkedList)------\n");
	printf("Chauchau :D\n\n");
	ll_deleteLinkedList(listaEmpleados);
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int compararLegajo(void*a, void* b)
{
	int retorno = 0;
	eEmpleado* emp1 = NULL;
	eEmpleado* emp2 = NULL;

	if(a != NULL && b != NULL)
	{
		emp1 = (eEmpleado*) a;
		emp2 = (eEmpleado*) b;
		if(emp1->id > emp2->id)
		{
			retorno = 1;
		}else if(emp1->id < emp2->id)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int compararNombre(void*a, void* b)
{
	int retorno = 0;
	eEmpleado* emp1 = NULL;
	eEmpleado* emp2 = NULL;

	if(a != NULL && b != NULL)
	{
		emp1 = (eEmpleado*) a;
		emp2 = (eEmpleado*) b;
		retorno = strcmp(emp1->nombre, emp2->nombre);


	}
	return retorno;
}

int mostrarEmpleados(LinkedList* lista)
{
	int retorno = 0;
	if(lista != NULL)
	{
		printf("Legajo    Nombre   Sexo   Sueldo\n");
		for(int i = 0; i < ll_len(lista); i++)
		{
			mostrarEmpleado((eEmpleado*) ll_get(lista, i));
		}

		printf("\n\n");
		retorno = 1;
	}

	return retorno;
}

int mostrarEmpleado(eEmpleado* empleado)
{
    int retorno = 0;
    int id;
    char nombre[20];
    char sexo;
    float sueldo;

    if(empleado != NULL)
    {
        if(empleadoGetId(empleado, &id) &&
           empleadoGetNombre(empleado, nombre) &&
           empleadoGetSexo(empleado, &sexo) &&
           empleadoGetSueldo(empleado, &sueldo))
           {
            printf("%d %s %c %.2f\n", id, nombre, sexo, sueldo);
            retorno = 1;
           }

    }
    return retorno;
}

eEmpleado* new_Empleado()
{
    eEmpleado* nuevoEmpleado;
    nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

     if(nuevoEmpleado != NULL)
        {
            nuevoEmpleado->id = 0;
            strcpy(nuevoEmpleado->nombre, "xx");
            nuevoEmpleado->sexo = 'x';
            nuevoEmpleado->sueldo = 0;
        }
    return nuevoEmpleado;
}

eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = new_Empleado();

         if(nuevoEmpleado != NULL)
        {
            if(!(empleadoSetId(nuevoEmpleado, id) &&
                 empleadoSetNombre(nuevoEmpleado, nombre) &&
                 empleadoSetSexo(nuevoEmpleado, sexo) &&
                 empleadoSetSueldo(nuevoEmpleado, sueldo) ))
            {
                free(nuevoEmpleado);
                nuevoEmpleado = NULL;
            }
        }
    return nuevoEmpleado;
}

///////////////////////////////DESTRUCTOR

void empleadoDestroy(eEmpleado* pEmpleado)
{
    free(pEmpleado);
}

///////////////////////////////SETTERS

int empleadoSetId(eEmpleado* pEmpleado, int id)
{
    int retorno = 0;

    if(pEmpleado != NULL && id >= 1000 && id <= 9999)
        {
            pEmpleado->id = id;
            retorno = 1;
        }else
        {
            printf("ID invalido");
        }

    return retorno;
}

int empleadoSetNombre(eEmpleado* pEmpleado, char* nombre)
{
    int retorno = 0;

    char auxCadena[20];

    if(pEmpleado != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 20)
        {
            strcpy(auxCadena, nombre);
            strlwr(auxCadena);
            auxCadena[0] = toupper(auxCadena[0]);
            strcpy(pEmpleado->nombre, auxCadena);
            retorno = 1;
        }else
        {
            printf("Nombre invalido");
        }
    return retorno;
}

int empleadoSetSexo(eEmpleado* pEmpleado, char sexo)
{
    int retorno = 0;

    sexo = tolower(sexo);

    if(pEmpleado != NULL && (sexo == 'm' || sexo == 'f'))
        {
            pEmpleado->sexo = sexo;
            retorno = 1;
        }else
        {
            printf("Sexo invalido");
        }
    return retorno;
}

int empleadoSetSueldo(eEmpleado* pEmpleado, float sueldo)
{
    int retorno = 0;

    if(pEmpleado != NULL && sueldo > 0 && sueldo < 9999999999)
        {
            pEmpleado->sueldo = sueldo;
            retorno = 1;
        }else
        {
            printf("Sueldo invalido");
        }
    return retorno;
}

///////////////////////////////GETTERS

int empleadoGetId(eEmpleado* pEmpleado, int* pId)
{
    int retorno = 0;

    if(pEmpleado != NULL && pId != NULL)
        {
            *pId = pEmpleado->id;
            retorno = 1;
        }
    return retorno;
}

int empleadoGetNombre(eEmpleado* pEmpleado, char* pNombre)
{
    int retorno = 0;

    if(pEmpleado != NULL && pNombre != NULL)
        {
            strcpy(pNombre, pEmpleado->nombre);
            retorno = 1;
        }
    return retorno;
}

int empleadoGetSexo(eEmpleado* pEmpleado, char* pSexo)
{
    int retorno = 0;

    if(pEmpleado != NULL && pSexo != NULL)
        {
            *pSexo = pEmpleado->sexo;
            retorno = 1;
        }
    return retorno;
}

int empleadoGetSueldo(eEmpleado* pEmpleado, float* pSueldo)
{
    int retorno = 0;

    if(pEmpleado != NULL && pSueldo != NULL)
        {
            *pSueldo = pEmpleado->sueldo;
            retorno = 1;
        }
    return retorno;
}


























