#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYBOARD_BUFFER 70000000

enum PieceSource { Original, Add };

struct Piece;

typedef struct Piece{
    int start;
    size_t len;
    enum PieceSource PIECE_SOURCE;
    struct Piece *next;
    struct Piece *prev;
} Piece_t;

typedef struct {
    Piece_t *start;    
    Piece_t *end;
    size_t count;
    size_t length;
} PieceTable;

PieceTable *init_piece_table(size_t length) {
    Piece_t *start = (Piece_t *)malloc(sizeof(Piece_t));
    start->start = 0;
    start->len = length;
    start->PIECE_SOURCE = Original;
    start->next = NULL;
    start->prev = NULL;

    PieceTable *table = (PieceTable *)malloc(sizeof(PieceTable));
    table->start = start;
    table->end = NULL;
    table->count = 1;
    table->length = length;
}

char *print_table_contents(PieceTable *table, const char* original_sequence, const char* added_sequence) {
    char *result = (char *)malloc(table->length);
    int offset = 0;
    Piece_t current = *(table->start);

    for (size_t i = 0; i < table->count; ++i) {
        if(current.PIECE_SOURCE == Original){
            strncpy(result + offset, original_sequence + current.start, current.len);
        }
        else if(current.PIECE_SOURCE == Add){
            strncpy(result + offset, added_sequence + current.start, current.len);
        }

        if(current.next != NULL){
            current = *(current.next);
            offset += current.len;
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    const char *original = "The brownfox.";
    const char *added = "quick   jumped over the white fence";

    PieceTable *table = init_piece_table(13);
    // simulate adding text from keyboard buffer, one piece at a time
    // then print the result
    // each time a piece is added, the output is three pieces : the original one (right), the new text from the keyboard buffer (middle), amd the end of the original piece (left)
    

    char* output = print_table_contents(table, original, added);

    printf("%s", output);

    return 0;
}
