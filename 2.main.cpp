#define MAX_SIZE_STR 1000
#define MAX_NUM_STR 1000
#define MAX_SIZE_WORD 100
#define MAX_NUM_WORD 100

#include <string.h>
#include <stdio.h>


struct
{
    char str[MAX_NUM_WORD][MAX_SIZE_WORD];
    int num;
} info[MAX_NUM_STR];

struct 
{
    int size;
    char* word;
} data[MAX_NUM_STR];

int input_str(char*);
void work(char*, char*, int );
int arr_int(char*, int_pchar*);
int f_max_s(int , int_pchar*);
void delete_words(int, int, int_pchar*);
void str_to_text(int, int_pchar*, char*);
//void print_result();
void get_info(int, int, int_pchar*, int);
void print_info(int);

int main()
{
    char text_out[MAX_NUM_WORD][MAX_SIZE_WORD];
    char text_in[MAX_NUM_WORD][MAX_SIZE_WORD];
    int word_in_text = 0;
    int num_str = 0;

    char str_in[MAX_SIZE_STR];

    int ch;
    char c;
    int size;
    int i = 0;

    while(1)
    {

        str_in[0] = '\0';

        size = input_str(text_in[num_str]);
        if( size  != 0)
            num_str++;
        else
            break;
    }

    for(int i=0; i<num_str; i++)
    {
            work(text_in[i],text_out[i], word_in_text);
            word_in_text++;
    }

    print_info(word_in_text);
    //print_result();

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

void work(char* str_in, char* text_out, int word_in_text)
{
    int max_s;
    int arr_s;
    //int_pchar arr[MAX_NUM_WORD];

    arr_s = arr_int(str_in, arr);
    max_s = f_max_s(arr_s, arr);

    get_info(max_s, arr_s, arr, word_in_text);

    delete_words( arr_s, max_s, arr);
    str_to_text(arr_s, arr, text_out);
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

void str_to_text(int size, int_pchar* arr, char* text)
{
    int pass = 0;

    for(int i=0; i<size;i++)
        if(arr[i].size != 0)
        {
            sprintf( &text[pass], "%s ", arr[i].word);
            pass += strlen(arr[i].word)+1; 
        }
}

/*
void print_result(text, num)
{
    for(int i =0 ; i<= word_in_text; i++)
        printf("%s\n", text_out[i]);
}
*/

void get_info(int maxs, int num, int_pchar* arr, int word_in_text)
{
    int count;
    int pass =0;
    int inf_num = 0;

    for(int i=1 ; i<=maxs; i++)
    {
        count = 0;

        for(int j=0 ; j<num; j++)
            if(arr[j].size == i)
                count++;

        if(count != 0)
        {
            sprintf(info[word_in_text].str[inf_num], "slov razmerom %d %d shtuk ; ", i, count);
            info[word_in_text].num++;
            inf_num++;
        }
    }
}

void print_info(int word_in_text)
{
    for(int i =0 ; i<= word_in_text; i++)
    {
        printf("\n");
        for(int j=0; j<info[i].num; j++)
            printf("%s ", info[i].str[j]);
    }
    
    printf("\n");
}
