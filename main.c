#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "Producto.h"


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

    if(listaDep0 == NULL || listaDep1 == NULL)
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
                eProducto_cargarArchivos(listaDep0, listaDep1);
                break;
            case 2:
                eProducto_listarDeposito(listaDep0, listaDep1);
                break;
            case 3:
                eProducto_moverProductos(listaDep0, listaDep1);
                eGestion_actualizarArchivos(listaDep0, listaDep1);
                break;
            case 4:
                eProducto_manejarStockProductos(listaDep0, listaDep1, -1);
                eGestion_actualizarArchivos(listaDep0, listaDep1);
                break;
            case 5:
                eProducto_manejarStockProductos(listaDep0, listaDep1, 1);
                eGestion_actualizarArchivos(listaDep0, listaDep1);
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
