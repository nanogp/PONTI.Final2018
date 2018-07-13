#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Gestion.h"
#include "Menu.h"


int main()
{
    int returnAux;
    eMenu menuPrincipal = {/*titulo del menu*/{"FINAL 2018 PONTI"},
                           /*cantidad de opciones*/6,
                           /*codigos*/{1,2,3,4,5,
                           0},
                           /*descripciones*/{"\n 1. CARGAR DEPOSITOS"
                                             "\n 2. LISTAR PRODUCTOS DE DEPOSITO"
                                             "\n 3. MOVER PRODUCTOS A DEPOSITO"
                                             "\n 4. DESCONTAR PRODUCTOS DE DEPOSITO"
                                             "\n 5. AGREGAR PRODUCTOS A DEPOSITO"
                                             "\n 0. SALIR DEL PROGRAMA"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ArrayList* listaDep0 = al_newArrayList();
    ArrayList* listaDep1 = al_newArrayList();

    if(listadoService == NULL || listadoEntry == NULL)
    {
        returnAux = CHECK_POINTER;
    }

    while(salirDelPrograma == 'N')
    {
        limpiarPantalla();
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                eService_cargarTxt(listadoService);
                eEntry_cargarTxt(listadoEntry);
                break;
            case 2:
                eEntry_procesar(listadoEntry, listadoService);
                break;
            case 3:
                break;
            case 4:
                eGestion_listado(listadoEntry,
                                 eEntry_mostrarUno,
                                 ENTRY_LISTADO_TITULO,
                                 ENTRY_MOSTRAR_UNO_CABECERA,
                                 ENTRY_MSJ_LISTA_VACIA,
                                 ENTRY_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 5:
                eGestion_listado(listadoService,
                                 eService_mostrarUno,
                                 SERVICE_LISTADO_TITULO,
                                 SERVICE_MOSTRAR_UNO_CABECERA,
                                 SERVICE_MSJ_LISTA_VACIA,
                                 SERVICE_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
