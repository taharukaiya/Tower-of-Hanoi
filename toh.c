#include <stdio.h>
#include <stdlib.h>

struct pole
{
    int s[3];
};

struct pole p[3];
int top[3];

void fill_pole();
void display_level(int lev);
void display();
void push(int x);
int pop();
int is_winner();

int main()
{
    printf("*****TOWER OF HANOI*****\n");
    printf("Objective: Your goal is to insert the numbers into second or third pole within 7 moves such that from top to bottom, they are in ascending order.\n");
    printf("Rule: You cannot put an greater number above a smaller number at any point in the game\n");

    top[2] = top[1] = -1;
    int win = 0, moves = 0;
    int x;

    fill_pole();
    display();

    while (win != 1)
    {
        x = pop();
        push(x);
        win = is_winner();
        display();
        moves++;
    }

    if (moves > 7)
    {
        printf("Oops! You lost...\n");
    }
    else
    {
        printf("Congratulations! You win!\n");
    }

    return 0;
}

void fill_pole()
{
    p[0].s[0] = 3;
    p[0].s[1] = 2;
    p[0].s[2] = 1;
    top[0] = 2;
}

void push(int x)
{
    int pl;
push:
    printf("Choose pole to push to: ");
    scanf("%d", &pl);
    // printf("\n");
    if (p[pl].s[top[pl]] > x || p[pl].s[top[pl]] == 0)
    {
        top[pl]++;
        p[pl].s[top[pl]] = x;
    }
    else
    {
        printf("Cannot push here. Try again.\n");
        goto push;
    }
}

int pop()
{
    int pl, x;
pop:
    printf("Choose pole to pop from: ");
    scanf("%d", &pl);
    // printf("\n");

    if (top[pl] < 0)
    {
        printf("Pole empty, cannot pop. Try again.\n");
        goto pop;
    }

    x = p[pl].s[top[pl]];
    p[pl].s[top[pl]] = 99;
    top[pl]--;
    return x;
}

void display_level(int lev)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (p[i].s[lev] == 99 || p[i].s[lev] == 0)
        {
            printf("[ ]\t");
        }
        else
        {
            printf("[%d]\t", p[i].s[lev]);
        }
    }
    printf("\n");
}

void display()
{
    printf("\n");
    int i;
    for (i = 2; i >= 0; i--)
    {
        display_level(i);
    }
}

int is_winner()
{
    if ((p[2].s[0] == 3 && p[2].s[1] == 2 && p[2].s[2] == 1) ||
        (p[1].s[0] == 3 && p[1].s[1] == 2 && p[1].s[2] == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}