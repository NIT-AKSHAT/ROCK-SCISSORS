#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define PRINT_SPACES(n) printf("   %*s  ", n, "")
#define print_spaces(n) printf("   -%*s   ", n, "")

int cmpchoice(void) {
    srand(time(NULL));
    return rand() % 3;
}

int fun(char rep)
{
    if (rep == 'y' || rep == 'Y')
    {
        return 1;
    }
    if (rep == 'n' || rep == 'N')
    {
        return 0;
    }
}
int fun1(char ans)
{
    if (ans == 'y' || ans == 'Y')
    {
        return 1;
    }
    if (ans == 'n' || ans == 'N')
    {
        return 0;
    }
}

int greater(char s1[], char s2[]) {
    int i;
    // Convert the choices to lowercase for case-insensitive comparison
    char choice1[10], choice2[10];
    strcpy(choice1, s1);
    strcpy(choice2, s2);
    for (i = 0; choice1[i]; i++) {
        choice1[i] = tolower(choice1[i]);
    }
    for (i = 0; choice2[i]; i++) {
        choice2[i] = tolower(choice2[i]);
    }

    if (strcmp(choice1, choice2) == 0) {
        // It's a draw
        return -1;
    } 
    else if ((strcmp(choice1, "rock") == 0 && strcmp(choice2, "scissors") == 0) ||
               (strcmp(choice1, "scissors") == 0 && strcmp(choice2, "paper") == 0) ||
               (strcmp(choice1, "paper") == 0 && strcmp(choice2, "rock") == 0)) 
               {
        // Player 1 wins
        return 1;
    } 
    else {
        // Player 2 wins
        return 0;
    }
}

void fun2(void) {
    char rep;
    int playerscore = 0, computerscore = 0;
    int n;
    char* ptr;

    PRINT_SPACES(10);
    print_spaces(10);
    fflush(stdin);

    printf("\n\n\n\n   Enter digits for user's name: ");
    scanf("%d", &n);
    ptr = (char *)malloc((n + 1) * sizeof(char));

    

    PRINT_SPACES(10);
    print_spaces(10);
    fflush(stdin);

    printf("Enter user's name: ");
    scanf(" %[^\n]s", ptr);

    system("cls");

    PRINT_SPACES(10);
    print_spaces(10);
    fflush(stdin);

    printf("Hi, %s! Do you want to play rock_scissors game? (y/n): ", ptr);
    scanf(" %c", &rep);


    int d = fun(rep);
    if (d==1)
     {
         int e = cmpchoice();
    char choices[][10] = {"ROCK", "PAPER", "SCISSORS"};

    char player_choice[10];
    printf("Enter your choice (rock/paper/scissors): ");
    scanf("%s", player_choice);

    system("cls");

    printf("Computer's turn is: %s\n", choices[e]);

    int g = greater(player_choice, choices[e]);

    if (g == 1) {
        playerscore += 1;
    } else if (g == 0) {
        computerscore += 1;
    } else if (g == -1) {
        computerscore += 1;
        playerscore += 1;
    }

    if (playerscore > computerscore)
	 {
	 	PRINT_SPACES(10);
        printf("You win!\n");
    } 
	else if (playerscore == computerscore) 
	{
		PRINT_SPACES(10);
        printf("Match is drawn\n");
    } else
	 {
	 	PRINT_SPACES(10);
        printf("Computer wins\n");
    }

	PRINT_SPACES(10);
	
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &rep);

    free(ptr);

    if (fun1(rep)) {
        fun2();
    } 

    }

     else if(d==0)
    {
        PRINT_SPACES(10);
        print_spaces(10);

    system("cls");

        printf("  \n\n   ---           YOU HAVE EXITED FROM THE GAME.               ---  \n\n  ");
    }
}

int main() {
    system("cls");

    printf("\n\n\n\n");
    fun2();

    return 0;
}
