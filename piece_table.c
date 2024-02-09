#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_LINE_LENGTH 256

struct Piece{
    int start;
    int length;
    bool original;
};

struct PieceTable{
    char* original;
    char* add;

};

int main(char argc, char* argv[]){
    char line[MAX_LINE_LENGTH] = "The quick brown fox.";

    struct PieceTable* table = (struct PieceTable*)malloc(sizeof(struct PieceTable));
    table->original = line;
    table->add = "jumped over the white fence";

    printf("%s", line);
    return 0;
}
