#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_LINE_LENGTH 256

enum PieceSource {
    Original,
    Add
};

struct Piece{
    int start;
    int length;
    enum PieceSource PIECE_SOURCE; 
};

struct PieceTable{
    char* original;
    char* add;
    struct Piece pieces[25];
    size_t pieces_length;
};

char* compute_piece_string(struct Piece source, struct PieceTable* table){
    char* result = (char*)malloc(source.length + 1);
    if(source.PIECE_SOURCE == Original){
        strncpy(result, table->original + source.start, source.length);
    }
    else if (source.PIECE_SOURCE == Add){
        strncpy(result, table->add + source.start, source.length);
    }
    result[source.length] = '\0';
    return result;
}

struct Piece make_piece(enum PieceSource source, int start, int length){
    struct Piece result;
    result.PIECE_SOURCE = source;
    result.start = start;
    result.length = length;
    return result;
}

int main(char argc, char* argv[]){
    struct PieceTable table;
    table.original = "Thebrown fox.";
    table.add =" quick  jumped over the white fence";

    table.pieces[0] = make_piece(Original, 0, 3);
    table.pieces[1] = make_piece(Add, 0, 7);
    table.pieces[2] = make_piece(Original, 3, 9);
    table.pieces[3] = make_piece(Add, 7, 28);
    table.pieces[4] = make_piece(Original, 12, 1);
    table.pieces_length = 5;

    char line[MAX_LINE_LENGTH] = "";

    for(size_t i = 0; i < table.pieces_length; ++i){
        strcat(line, compute_piece_string(table.pieces[i], &table));
    }

    printf("%s", line);
    return 0;
}
