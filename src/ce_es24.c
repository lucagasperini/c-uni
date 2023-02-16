/*
Esercizio 24 : Si scriva un programma in linguaggio C che, dato un percorso ad un file di testo passato come argomento
di programma, calcoli:
1. il numero totale di righe che compongono il file; *
2. il numero totale di caratteri che compongono il file (esclusi spazi);*
3. il numero totale di caratteri alfanumerici che compongono il file;*
4. il numero totale di parole che compongono il file; *
5. il numero massimo e medio di caratteri in una riga del file;
6. la lunghezza della riga più lunga incontrata nel file;
7. il contenuto della riga più lunga incontrata nel file.
*/

#define MAX_LINE_SIZE 1023

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct analysis_file_t {
        size_t row;
        size_t char_nospace;
        size_t char_alfanum;
        size_t word;
        size_t max_line;
        char max_line_str[MAX_LINE_SIZE + 1];
};

static inline void init_analysis_file(struct analysis_file_t* a)
{
        if(a == NULL) {
                return;
        }

        a->row = 0;
        a->char_nospace = 0;
        a->char_alfanum = 0;
        a->word = 0;
        a->max_line = 0;
        memset(a->max_line_str, 0, MAX_LINE_SIZE + 1);
}

static inline void do_read_line(const char* line, size_t len, struct analysis_file_t* a)
{
        a->row++;
        if(a->max_line < len) {
                a->max_line = len;
                strncpy(a->max_line_str, line, len);
        }
}

int analysis_file(const char* filename, struct analysis_file_t* a)
{
        FILE* fd = fopen(filename, "r");
        if(fd == NULL) {
                perror("ERRORE: Impossibile aprire il file");
                return 1;
        }

        char buffer[MAX_LINE_SIZE];
        size_t i = 0;

        while(feof(fd) == 0) {
                fread(buffer + i, 1,1, fd);
                if(buffer[i] == '\n') {
                        do_read_line(buffer, i, a);
                        i = 0; 
                        continue;
                }

                if(isalnum(buffer[i])) {
                        a->char_alfanum++;
                }

                if(buffer[i] != ' ') {
                        a->char_nospace++;
                }

                if(i > 0 && buffer[i] == ' ' && isalnum(buffer[i - 1])) {
                        a->word++;
                }

                if(i >= MAX_LINE_SIZE) {
                        do_read_line(buffer, i, a);
                        i = 0;
                        continue;
                }
                i++;
        }

        fclose(fd);
        return 0;
}

int main(int argc, char** argv)
{
        struct analysis_file_t af;
        init_analysis_file(&af);

        if(analysis_file("testfile", &af)) {
                return 1;
        } else {
                printf("Numero totale righe: %d\n", af.row);
                printf("Numero totale caratteri (esclusi spazi): %d\n", af.char_nospace);
                printf("Numero totale caratteri alfanumerici: %d\n", af.char_alfanum);
                printf("Numero totale parole: %d\n", af.word);
                printf("Lunghezza riga massima: %d\n", af.max_line);
                printf("Contenuto riga massima: %s\n", af.max_line_str);
        }
}