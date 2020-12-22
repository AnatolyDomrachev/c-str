#define MAX_SIZE_STR 1000
#define MAX_SIZE_WORD 100

#include <string.h>
#include <stdio.h>

struct int_pchar
{
    int size;
    char word[MAX_SIZE_WORD];
};

void input_str(char*);
void work(char*, char* );
void arr_int(char*, int_pchar*);
int f_max_s(int_pchar*);
void delete_words(int, int_pchar*);

int main()
{
    char str_in[MAX_SIZE_STR];
    char str_out[MAX_SIZE_STR];

    input_str(str_in);
    work(str_in, str_out);

    printf("%s\n", str_out);

    return 0;
}

void input_str(char* str)
{
    //TODO Ввод пока не будет введена пустая стpока
    scanf("%[^\n]",str);
    for(int i=0; i<strlen(str); i++)
        if (str[i] == '\t')
            str[i] = ' ';
}

void work(char* str_in, char* str_out)
{
    int max_s;
    int_pchar arr[MAX_SIZE_STR];

    arr_int(str_in, arr);
    max_s = f_max_s(arr);
    delete_words(max_s, arr);
}

void arr_int(char* str, int_pchar* arr)
{
    sscanf(str, "%s", arr[0].word);
    arr[0].size = strlen(arr[0].word);
}

int f_max_s(int_pchar* arr)
{
    return 123;
}

void delete_words(int num, int_pchar* str)
{}
