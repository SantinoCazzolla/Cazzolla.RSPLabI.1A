#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "publicaciones.h"

ePost* post_new()
{

    ePost* newPost = (ePost*) malloc(sizeof(ePost));

    if (newPost != NULL)
    {
        newPost->id = 0;
        strcpy(newPost->user," ");
        newPost->likes = 0;
        newPost->dislikes = 0;
        newPost->followers = 0;


    }

    return newPost;

}

ePost* post_newParametros(char* idStr,char* userStr,char* likesStr,char* dislikesStr,char* followersStr)
{


    ePost* nuevo = post_new();

    if (nuevo != NULL)
    {
        post_setId(nuevo, atoi(idStr));
        post_setUser(nuevo, userStr);
        post_setLikes(nuevo, atoi(likesStr));
        post_setDislikes(nuevo, atoi(dislikesStr));
        post_setFollowers(nuevo, atoi(followersStr));




    }

    return nuevo;
}

void post_delete(ePost* unPost)
{

    if(unPost!=NULL)
    {
        free(unPost);
        unPost=NULL;
    }

}

int menu()
{
    int opcion;
    system("cls");
    printf("\n-------------------------\n");
    printf("-------------------------\n");
    printf("1. Cargar archivo csv\n");
    printf("2. Mostrar Posts\n");
    printf("3. Asignar Estadisticas\n");
    printf("4. Mejores Posteos\n");
    printf("5. Mostrar heaters\n");
    printf("6. Ordenar Followers\n");
    printf("7. Mostrar mas popular\n");
    printf("8. Salir\n");
    printf("-------------------------\n");
    printf("-------------------------\n\n\n");


    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}

int post_getId(ePost* this, int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 0;
    }

    return todoOk;
}


int post_getUser(ePost* this, char* user)
{
    int todoOk = 1;

    if(this != NULL && user != NULL)
    {
        strcpy(user, this->user);
        todoOk = 0;
    }

    return todoOk;
}

int post_getLikes(ePost* this, int* likes)
{
    int todoOk = 1;

    if(this != NULL && likes != NULL)
    {
        *likes = this->likes;
        todoOk = 0;
    }

    return todoOk;
}

int post_getDislikes(ePost* this, int* dislikes)
{
    int todoOk = 1;

    if(this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;
        todoOk = 0;
    }

    return todoOk;
}

int post_getFollowers(ePost* this, int* followers)
{
    int todoOk = 1;

    if(this != NULL && followers != NULL)
    {
        *followers = this->followers;
        todoOk = 0;
    }

    return todoOk;
}

int post_setId(ePost* this,int id)
{
    int todoOk = 1;

    if (this != NULL && id>0)
    {
        this->id = id;
        todoOk = 0;
    }

    return todoOk;

}

int post_setUser(ePost* this,char* user)
{

    int todoOk = 1;

    if (this != NULL && user != NULL && strlen(user) <= 50)
    {
        strcpy(this->user, user);
        todoOk = 0;
    }

    return todoOk;

}

int post_setLikes(ePost* this,int likes)
{
    int todoOk = 1;

    if (this != NULL && likes>0)
    {
        this->likes = likes;
        todoOk = 0;
    }

    return todoOk;

}


int post_setDislikes(ePost* this,int dislikes)
{
    int todoOk = 1;

    if (this != NULL && dislikes>0)
    {
        this->dislikes = dislikes;
        todoOk = 0;
    }

    return todoOk;

}

int post_setFollowers(ePost* this,int followers)
{
    int todoOk = 1;

    if (this != NULL && followers>0)
    {
        this->followers = followers;
        todoOk = 0;
    }

    return todoOk;

}


void listarPost(LinkedList* lista, int index)
{
    ePost* auxPost = (ePost*) post_new();
    int id;
    char user[128];
    int likes;
    int dislikes;
    int followers;


    if(lista != NULL && index >=0)
    {
        auxPost = ll_get(lista, index);
        post_getId(auxPost,&id);
        post_getUser(auxPost,user);
        post_getLikes(auxPost,&likes);
        post_getDislikes(auxPost,&dislikes);
        post_getFollowers(auxPost,&followers);


        printf("%2d        %-16s        %d     %d       %d  \n", id, user, likes, dislikes,followers);

    }

}


int mostrarPosts(LinkedList* pArraylist)
{
    int todoOk = 1;

    ePost* pPost;


    if(pArraylist != NULL)
    {
        system("cls");
        printf("\n  ID      USER                 LIKES    DISLIKES  FOLLOWERS  \n\n");
        for(int i = 0; i < ll_len(pArraylist); i++)
        {
            pPost = ll_get(pArraylist, i);
            if(pPost != NULL)
            {
                listarPost(pArraylist, i);
                todoOk = 0;
            }
        }
    }
    else if(todoOk == 1)
    {
        printf("No hay Posts cargados en la lista\n");
    }

    return todoOk;
}

int generarRandomLikes()
{
    int likes;

    likes = rand()% (3000 - 234) + 2000;

    return likes;
}

int generarRandomDislikes()
{
    int dislikes;


    dislikes = rand()% (3000 - 234) + 2000;
    return dislikes;
}

int generarRandomFollowers()
{
    int followers;

    //followers = rand()% (20000) + 10001;
    followers = rand()% (20000 - 10001) + 10000;
    return followers;
}

void* asignarCamposPosts(void* pElement)
{
    ePost* auxPost;
    auxPost = (ePost*) pElement;

    settearLikes(auxPost);
    settearDislikes(auxPost);
    settearFollowers(auxPost);

    return auxPost;
}

int post_setCampos(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaAsignada;

    if(lista != NULL)
    {
        listaAsignada = ll_map(lista,asignarCamposPosts);
        if(listaAsignada != NULL)
        {
            todoOk = 0;
            printf("Se asignaron los campos\n");
        }
        else
        {
            printf("No se pudieron asignar\n");
        }
    }
    return todoOk;
}

void settearLikes(void* element)
{
    ePost* likes = NULL;

    if(element!=NULL)
    {
        likes = (ePost*) element;
        post_setLikes(likes, generarRandomLikes());

    }

}

void settearDislikes(void* element)
{
    ePost* dislikes = NULL;

    if(element!=NULL)
    {
        dislikes = (ePost*) element;
        post_setDislikes(dislikes, generarRandomDislikes());

    }

}

void settearFollowers(void* element)
{
    ePost* followers = NULL;

    if(element!=NULL)
    {
        followers = (ePost*) element;
        post_setFollowers(followers, generarRandomFollowers());

    }

}



