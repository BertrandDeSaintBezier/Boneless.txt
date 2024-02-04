#include<stdio.h>
#include<windows.h>

#define MAX_LINE_LENGTH 256

void clear_screen(){
	printf("\033[2J\033[H");
}

int main(int argc, char* argv[]){	
	char line[MAX_LINE_LENGTH];
	char curr = '_';

	int curr_pos = 0;

	for(size_t i = 0; i < MAX_LINE_LENGTH; ++i){
		line[i] = '.';
	}
	line[MAX_LINE_LENGTH - 1] = '\0';

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT) & (~ENABLE_LINE_INPUT));

	line[0] = curr;

	clear_screen();

	while(1){
		curr = getchar();
		clear_screen();
		line[curr_pos] = curr;
		line[curr_pos + 1] = '_';
		++curr_pos;
		printf("user typed : %s\n", line);
	}

	return 0;
}
