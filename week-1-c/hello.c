#include <stdio.h>
#include <cs50.h>


//here, I ended up entering the space bar between main and (void. Deleted it
int main(void)

{
    // also forgot to use _ after get for get_string during the first try. Did it
    string name = get_string("What is your name?\n");

    printf("hello, %s\n", name);
}