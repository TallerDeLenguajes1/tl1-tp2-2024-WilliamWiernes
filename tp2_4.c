#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2023
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
};

/* c.- Escribe una función que presente la lista de las PC,
cada una con sus características. */
void listaPC(struct compu *PC);

/* d.- Escribe una función que presente la PC más vieja. */
void viejaPC(struct compu *PC);

/* e.- Escribe una función que presente la PC que tiene mayor velocidad. */
void rapidaPC(struct compu *PC);

int main()
{
    // Semilla aleatoria
    srand(time(NULL));

    char tipos[6][10] =
        {"Intel",
         "AMD",
         "Celeron",
         "Athlon",
         "Core",
         "Pentium"};

    /* b.- Defina una variable de tipo arreglo de estructuras
    para guardar las características de 5 PC que cargará el usuario*/
    struct compu PC[5];

    // Evito la carga manual de datos
    int numAle;
    for (int i = 0; i < 5; i++)
    {
        PC[i].velocidad = 1 + rand() % 3; // 1 - 3
        PC[i].anio = 2015 + rand() % 10;  // 2015 - 2024
        PC[i].cantidad = 1 + rand() % 8;  // 1 - 8
        numAle = rand() % 6;              // 0 - 5, son 6 elementos en el arreglo tipos[6][10];
        PC[i].tipo_cpu = tipos[numAle];
    }

    // Muestro la lista de PCs
    listaPC(PC);

    // Muestro la PC más vieja
    viejaPC(PC);

    // Muestro la PC más rápida
    rapidaPC(PC);

    return 0;
}

void listaPC(struct compu *PC)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n\n______________PC N.%d______________", i);
        printf("\n\tVelocidad: %d", PC[i].velocidad);
        printf("\n\tAnio: %d", PC[i].anio);
        printf("\n\tCantidad de nucleos: %d", PC[i].cantidad);
        printf("\n\tTipo de procesador: %s", PC[i].tipo_cpu);
    }
}

void viejaPC(struct compu *PC)
{
    int masAntiguo = PC[0].anio, index = 0;

    for (int i = 0; i < 5; i++)
    {
        if (masAntiguo > PC[i].anio)
        {
            masAntiguo = PC[i].anio;
            index = i;
        }
    }

    printf("\n\n___________PC mas vieja___________");
    printf("\n\tPC N.%d creada en %d", index, masAntiguo);
}

void rapidaPC(struct compu *PC)
{
    int masRapida = PC[0].velocidad, index = 0;

    for (int i = 0; i < 5; i++)
    {
        if (masRapida < PC[i].velocidad)
        {
            masRapida = PC[i].velocidad;
            index = i;
        }
    }

    printf("\n\n__________PC mas rapida__________");
    printf("\n\tPC N.%d con %d GHz", index, masRapida);
}