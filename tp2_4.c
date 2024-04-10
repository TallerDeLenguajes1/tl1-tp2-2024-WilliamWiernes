#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CANT_PC 5 // Se podría cambiar para preguntar al usuario cuántas PCs desea agregar, y hace un arreglo de PCs en tiempo de ejecución
#define MAX 20    // Cantidad de letras máximas para el tipo de cpu en el arreglo tipos[][].

typedef struct
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2024
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
} COMPU;

/* void cargaDeDatos(COMPU *PC); */
void listaPC(COMPU *PC);
void viejaPC(COMPU *PC);
void rapidaPC(COMPU *PC);

int main()
{
    // Semilla aleatorio
    srand(time(NULL));

    // Arreglo de 5 computadoras
    COMPU *PC = (COMPU *)malloc(CANT_PC * sizeof(COMPU)); // O se podría directamente usar COMPU PC[CANT_PC].

    // Carga de datos por parte del usuario
    // cargaDeDatos(PC);

    // Para evitar la carga manual de datos, los inicializo de forma automática y aleatoria
    char tipos[][MAX] = {
        "Intel",
        "AMD",
        "Celeron",
        "Athlon",
        "Core",
        "Pentium"};

    int eleccionTipo;

    for (int i = 0; i < CANT_PC; i++)
    {
        // rand() % (max - min + 1) + min;
        PC[i].velocidad = rand() % (3 - 1 + 1) + 1;
        PC[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        PC[i].cantidad = rand() % (8 - 1 + 1) + 1;
        PC[i].tipo_cpu = tipos[rand() % (5 - 0 + 1) + 0];
    }

    // Lista de PCs
    listaPC(PC);

    // PC más vieja
    viejaPC(PC);

    // PC más rápida
    rapidaPC(PC);

    // Liberando memoria asiganda dinámicamente
    /* for (int i = 0; i < CANT_PC; i++)
    {
        free(PC[i].tipo_cpu);
    } */

    free(PC); // No es necesario si se usa COMPU PC[CANT_PC].

    return 0;
}

/* void cargaDeDatos(COMPU *PC)
{
    for (int i = 0; i < CANT_PC; i++)
    {
        printf("\nPC %d:", i + 1);
        do
        {
            printf("\nIngrese la velocidad (1 - 3 GHz): ");
            scanf("%d", &PC[i].velocidad);
        } while (PC[i].velocidad < 1 || PC[i].velocidad > 3);

        do
        {
            printf("\nIngrese el anio de fabricacion (2015 - 2024): ");
            scanf("%d", &PC[i].anio);
        } while (PC[i].anio < 2015 || PC[i].anio > 2024);

        do
        {
            printf("\nIngrese la cantidad de nucleos (1 - 8): ");
            scanf("%d", &PC[i].cantidad);
        } while (PC[i].cantidad < 1 || PC[i].cantidad > 8);

        char tipos[][MAX] = {
            "Intel",
            "AMD",
            "Celeron",
            "Athlon",
            "Core",
            "Pentium"};

        int cantidadTipos = sizeof(tipos) / sizeof(tipos[0]); // sizeof(tipos) / sizeof(tipos[0]) nos permite saber cuantos elementos hay dentro del arreglo tipo[], por lo que si en un futuro se agregan más tipos de procesadores, el programa seguiría imprimiéndolos a todos.

        printf("\nIngrese el tipo de procesador ( ");
        for (int i = 0; i < cantidadTipos; i++)
        {
            printf("%d. %s ", i + 1, tipos[i]);
        }
        printf("): ");

        int eleccionTipo = 0;

        do
        {
            scanf("%d", &eleccionTipo);

            if (eleccionTipo <= 0 || eleccionTipo > cantidadTipos)
            {
                printf("\nTipo de cpu incorrecto, ingrese nuevamente: ");
            }

        } while (eleccionTipo <= 0 || eleccionTipo > cantidadTipos);

        PC[i].tipo_cpu = (char *)malloc(8 * sizeof(char)); // 7 por ser la cantidad de letras que contiene la palabra más larga dentro del arreglo tipos[], y 8 para el caracter nulo '\0'.

        strcpy(PC[i].tipo_cpu, tipos[eleccionTipo - 1]);
    }
} */

void listaPC(COMPU *PC)
{
    for (int i = 0; i < CANT_PC; i++)
    {
        printf("\n\n______________PC N.%d______________", i + 1);
        printf("\n\tVelocidad: %d", PC[i].velocidad);
        printf("\n\tAnio: %d", PC[i].anio);
        printf("\n\tCantidad de nucleos: %d", PC[i].cantidad);
        printf("\n\tTipo de procesador: %s", PC[i].tipo_cpu);
    }
}

void viejaPC(COMPU *PC)
{
    int masAntiguo = PC[0].anio, index = 0;

    for (int i = 0; i < CANT_PC; i++)
    {
        if (masAntiguo > PC[i].anio)
        {
            masAntiguo = PC[i].anio;
            index = i;
        }
    }

    printf("\n\n___________PC mas vieja___________");
    printf("\n\tPC N.%d creada en %d", index + 1, masAntiguo);
}

void rapidaPC(COMPU *PC)
{
    int masRapida = PC[0].velocidad, index = 0;

    for (int i = 0; i < CANT_PC; i++)
    {
        if (masRapida < PC[i].velocidad)
        {
            masRapida = PC[i].velocidad;
            index = i;
        }
    }

    printf("\n\n__________PC mas rapida__________");
    printf("\n\tPC N.%d con %d GHz", index + 1, masRapida);
}