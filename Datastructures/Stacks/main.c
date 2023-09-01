#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>

/// @brief Stack element type
typedef void stackElement_t;

/// @brief Stack type
typedef struct{
    stackElement_t *top;
    stackElement_t *current;
    stackElement_t *bottom;
    size_t size;
    size_t maxAmount;
}myStack_t;

/// Initialisiert ein neues Stack Element
/// \param size Beschreibt die größe eines einzelnen Elements (z.B int32, char)
/// \param maxAmount Breschreibt die Anzahl an Elementen, die im Stack vorhanden sein sollen
/// \return
myStack_t *StackNew(size_t size, size_t maxAmount){

    //Initialisiert ein leeres Stackelement
    myStack_t *p_Stack = malloc(sizeof(myStack_t));
    // Wenn keine Struktur angelegt werden konnte
    // Terminiert die Funktion
    if(p_Stack == NULL) return NULL;

    //Initialisiert die ein Array eines durch size definierten
    // Datentyps
    p_Stack->top = malloc(size * maxAmount);
    // Wenn kein Arrayangelegt werden konnte
    // gibt er den Speicher frei der allokiert wurde und
    // terminiert dann.
    if(NULL == p_Stack->top){
        free(p_Stack);
        return NULL;
    }
    // Bottom ist die Addresse des letzten Elements im Array
    p_Stack->bottom = p_Stack->top + (size * maxAmount);
    // Das aktuelle Element ist das Element von bottom
    p_Stack->current = p_Stack->bottom;
    // Size beschreibt die größe eines einzelnen Elements
    p_Stack->size = size;
    // Max Amount speichert wie viele Elemente maximal gespeichert
    // werden können.
    p_Stack->maxAmount = maxAmount;

    //Gibt den Stack zurück
    return p_Stack;
}

int Pop(myStack_t *io_pStack, stackElement_t *io_pValue){
    // Wenn der übergebende Stack nicht NULL ist und der
    if((NULL != io_pStack) && (io_pStack->current != io_pStack->bottom)){
        // Kopiert den Wert des Pointes von current mit der größe von Size
        // in die Adresse der Variable io_pValue
        memcpy(io_pValue, io_pStack->current, io_pStack->size);

        // addiert die Adresse von current mit der definierten Größe der Elemente
        io_pStack->current += io_pStack->size;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int Push(myStack_t *io_pStack, stackElement_t *io_pValue){
    if((NULL != io_pStack)&&(io_pStack->current >= ((io_pStack->bottom)-(io_pStack->size*io_pStack->maxAmount)))){
        io_pStack->current -= io_pStack->size;
        memcpy(io_pStack->current, io_pValue, io_pStack->size);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}


int main() {
    srand(time(NULL));
    myStack_t *test_stack = StackNew(sizeof(int), 5);
    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 20 + 1;
        Push(test_stack, &random_number);
        int element = *((int *) (test_stack->current));
        printf("%d\n", element);
    }
    printf("\n--\n");
    for (int i = 0; i < 5; ++i) {
        int o_value = 0;
        Pop(test_stack, &o_value);
        printf("%d\n", o_value);
    }
    return 0;
}
