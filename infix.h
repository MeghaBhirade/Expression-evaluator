#ifndef INFIX_H
#define INFIX_H


int is_full(int top,int size);

int is_empty(int top);

void char_push_array(char *arr,int *top,int size, char ch);

char char_pop_array(char *arr, int *top);

char  char_peak_array(char *arr,int top);

int operator(char ch);

void infix_postfix_con(char *array , char *ch_array);

void push_array(int *arr,int size,int *top, int value);

int pop_array(int *arr, int *top);

void post_infix_eval(char *ch_array);

void iterative_reverse( char *str);

int infix_prefix_con(char *insert_array , char *ch_array);

void pre_infix_eval(char *ch_array);


#endif
