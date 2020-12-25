#define MAX_SIZE_STR 1000
#define MAX_SIZE_WORD 100
#define MAX_NUM_WORD 100

#include <string.h>
#include <stdio.h>

char text[MAX_NUM_WORD][MAX_SIZE_WORD];
int word_in_text;

struct int_pchar
{
    int size;
    char* word;
};

int input_str(char*);
void work(char* );
int arr_int(char*, int_pchar*);
int f_max_s(int , int_pchar*);
void delete_words(int, int, int_pchar*);
void str_to_text(int, int_pchar*);
void print_result();

int main()
{
    word_in_text = 0;
    char str_in[MAX_SIZE_STR];

    int ch;
    char c;
    int size;
    int i = 0;

    while(1)
    {

        str_in[0] = '\0';

        size = input_str(str_in);
        if( size  != 0)
        {
            work(str_in);
            word_in_text++;
        }
        else
            break;

    }

    print_result();

    return 0;
}

int input_str(char* str)
{
    char ch;
    scanf("%[^\n]",str);
    scanf("%c", &ch);
    for(int i=0; i<strlen(str); i++)
        if (str[i] == '\t')
            str[i] = ' ';

    int len = strlen(str);
    return len;
}

void work(char* str_in)
{
    int max_s;
    int arr_s;
    int_pchar arr[MAX_NUM_WORD];

    arr_s = arr_int(str_in, arr);
    max_s = f_max_s(arr_s, arr);
    delete_words( arr_s, max_s, arr);
    str_to_text(arr_s, arr);
}

int arr_int(char* str, int_pchar* arr)
{
    int len = strlen(str);
        
    int word_num = 1;

    for(int i=0; i<len ; i++)
        if (str[i] == ' ')
        {
            str[i] = '\0';
            word_num += 1;
        }

    arr[0].word = str;
    arr[0].size = strlen(arr[0].word);

    for(int i=1; i<word_num ; i++)
    {
        arr[i].word = arr[i-1].word + arr[i-1].size + 1;
        arr[i].size = strlen(arr[i].word);
    }

    return word_num;
}

int f_max_s(int arr_s, int_pchar* arr)
{
    int max_n;
    max_n = arr[0].size;

    for(int i=1; i<arr_s;i++)
        if(max_n < arr[i].size)
            max_n = arr[i].size;

    return max_n;
}

void delete_words(int arr_s, int max_num, int_pchar* arr)
{
    for(int i=0; i<arr_s;i++)
        if(arr[i].size == max_num)
            arr[i].size = 0;
}

void str_to_text(int size, int_pchar* arr)
{
    int pass = 0;

    for(int i=0; i<size;i++)
        if(arr[i].size != 0)
        {
            sprintf( &text[word_in_text][pass], "%s ", arr[i].word);
            pass += strlen(arr[i].word)+1; 
        }
}

void print_result()
{
    for(int i =0 ; i<= word_in_text; i++)
        printf("%s\n", text[i]);
}
