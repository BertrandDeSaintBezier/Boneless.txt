#include<stdio.h>
#include<windows.h>

#define MAX_LINE_LENGTH 256 

void set_win_console_mode(){
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT) & (~ENABLE_LINE_INPUT));
}

void clear_screen(){
    printf("\033[2J\033[H");
}

int delete(char* line, int pos){
if(pos >  0){
        line[pos] = '.';
        line[pos - 1] = '_';
        return --pos;
    }
    else{
        return pos;
    }
}

int append(char* line, int pos, char newchar){
    if(pos < MAX_LINE_LENGTH - 1){
        line[pos] = newchar;
        line[pos + 1] = '_';
        return ++pos;
    }
    else{
        return pos;
    }
}

int main(int argc, char* argv[]){	
    set_win_console_mode();
    clear_screen();

    char line[MAX_LINE_LENGTH];
    line[MAX_LINE_LENGTH - 1] = '\0';

    for(size_t i = 0; i < MAX_LINE_LENGTH - 1; ++i){
        line[i] = '.';
    }

    char curr = '_';
    line[0] = curr;

    int curr_pos = 0;

    while(1){
        curr = getchar();
        clear_screen();

        switch(curr){
            case '\b':
                // decrement current
                curr_pos = delete(line, curr_pos);
                break;
            case '\r' : 
                // stop running
                printf("user typed : %s\n", line);
                return 0;
            default:
                // add letter to line
                curr_pos = append(line, curr_pos,curr);
                break;
        }
        printf("%s\n", line);
    }

    return 0;
}
