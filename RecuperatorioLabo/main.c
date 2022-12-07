#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "LinkedList.h"
#include "Publicaciones.h"
#include "Validaciones.h"
#include "Informes.h"
#include "Parser.h"
int main()
{
    char seguir='s';
    char confirma;
    srand (time(NULL));

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listafiltrada=ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:

            loadFromText(lista);

        break;

        case 2:

            if(!ll_isEmpty(lista))
            {
                mostrarPosts(lista);
            }
            else
            {
                printf("primero debe cargar el archivo !!\n");
            }

        break;

        case 3:

            if(!ll_isEmpty(lista))
            {
               post_setCampos(lista);


            }
            else
            {
                printf("primero debe cargar el archivo !!\n");

            }
        break;

        case 4:
            if(!ll_isEmpty(lista))
            {
                listafiltrada = ll_filter(lista,filtrarMejoresPosteos);
                mostrarPosts(listafiltrada);
                guardarTexto("MejoresPosteos.csv",listafiltrada);

            }
            else
            {
                printf("primero debe cargar el archivo !!\n");

            }

        break;

        case 5:
            if(!ll_isEmpty(lista))
            {
                listafiltrada = ll_filter(lista,filtrarHeater);
                mostrarPosts(listafiltrada);
                guardarTexto("heaters.csv",listafiltrada);

            }
            else
            {
                printf("primero debe cargar el archivo !!\n");

            }

        break;

        case 6:
            if(!ll_isEmpty(lista))
            {
                ll_sort(lista,ordenarFollowers,1);

                mostrarPosts(lista);
                guardarTexto("followers.csv", lista);
            }
            else
            {
                printf("primero debe cargar el archivo !!\n");
            }


        break;

        case 7:
            if(!ll_isEmpty(lista))
            {
                mostrarMasPopular(lista);
            }
            else
            {
                printf("primero debe cargar el archivo !!\n");
            }



        break;

        case 8:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma =='s')
            {
                seguir='n';
            }

        break;
            }
                system("pause");

            }
            while(seguir=='s');



    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listafiltrada);

    return 0;
}




