/**
 * Stacks sind perfekt für die Bearbeitung von Daten in umgekehrter Reihenfolge
 * z.B "undo" bei Textverarbeitunfsprogrammen
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>

/// @brief Stack element type
typedef void stackElement_t;

/// @brief Stack type
typedef struct{
    //Speichert die Addresse des höchst möglichen Elements
    stackElement_t *top;
    // Speichert den Zeiger auf letzte Element
    stackElement_t *current;
    // Speichert die Addresse des untersten Elements
    stackElement_t *bottom;
    // Speichert die größe eines Elements
    size_t size;
    // Speichert die maximale Anzahl an Elementen
    size_t maxAmount;
}myStack_t;

/// Initialisiert ein neues Stack Element
/// \param size Beschreibt die größe eines einzelnen Elements (z.B sizeof(int32), sizeof(char))
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

/// Entfernt ein Element aus dem Stack und kopiert den Inhalt in
/// die addresse von io_pValue
/// \param io_pStack Stack Element
/// \param io_pValue Die Adresse zur Variable in die das
/// entnommene Element gespeichert werden soll
/// \return
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

/// Fügt ein Element in den Stack solange die
/// Stackgröße nicht überschritten wurden
/// \param io_pStack  Referenz zum Stack
/// \param io_pValue Addresse des Wert, die als Element kopiert
/// und in den Stack hinzugefügt werden soll
/// \return
int Push(myStack_t *io_pStack, stackElement_t *io_pValue){
    // Wenn der Stack initialisiert ist und
    if(
            (NULL != io_pStack) &&
            //z.B 0x5555555592e4
            (io_pStack->current >=
            //z.B 0x5555555592e4  -  int(4 bytes) * 5 Elemente = 0x5555555592d0
            ((io_pStack->bottom) - (io_pStack->size*io_pStack->maxAmount))))
    {
        // Geht ein Element zurück
        io_pStack->current -= io_pStack->size;

        // und kompiert den Inhalt von io_pValue in den Stack
        memcpy(io_pStack->current, io_pValue, io_pStack->size);

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void stack_random_number_demo();

void stack_linter();

int main() {
    printf("Zufällige Zahlen in den Stack rein und raustun:\n");
    stack_random_number_demo();

    printf("\nLinter Beispiel: \n");
    stack_linter();
    return 0;
}

/**
 * Beispiel:
 * Aus 4. Woche TI II Script Stacks Queues Rekursionen.pdf
 * Seite 15
 */
void stack_linter(){
    myStack_t *linter = StackNew(sizeof(char), 30);
    char* line = "(var x = {y: [1, 2, 3]})";
    for (int i = 0; i < 25; ++i) {
        char current_char = line[i];
        printf("%c", current_char );
        if(current_char == '{' || current_char == '[' || current_char == '(' ){

            Push(linter, &line[i]);
        }
        if(current_char == '}'){
            char o_value = 0;
            Pop(linter, &o_value);
            if(o_value == '{')
                printf("Korrospondenz %c", o_value);
        } else if(current_char==']'){
            char o_value = 0;
            Pop(linter, &o_value);
            if(o_value == '[')
                printf("Korrospondenz %c", o_value);
        }else if(current_char == ')'){
            char o_value = 0;
            Pop(linter, &o_value);
            if(o_value == '(')
                printf("Korrospondenz %c", o_value);
        }
    }
    char o_value = 0;
    printf("\nKeine Korrospondenz: ");
    while (Pop(linter, &o_value) == EXIT_SUCCESS) {
        printf("%c, ", o_value);
    }
    
}

/**
 * Zufällige Zahlen in den Stack schreiben und aus dem Stack entnehmen
 */
void stack_random_number_demo(){
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
}