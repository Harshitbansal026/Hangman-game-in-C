#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define MaxWords 2048
#define MaxLen 64

void printBody(int mistakes, char *body)
{
	printf("\tMistakes :%d\n", mistakes);
	switch(mistakes)
	{

		case 6: body[6] = '\\'; break;
		case 5:
		    body[5] = '/';
		    body[6] = '\\';
		    break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[1] = ')', body[0] = '('; break;
		default: break;

	}

	printf("\t _________\n"
	       "\t|         |\n"
	       "\t|        %c %c\n"
	       "\t|        %c%c%c\n"
	       "\t|        %c %c\n"
	       "\t|             \n"
	       "\t|             \n", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6]);
}

int main()
{
    printf("Welcome to HANGMAN       \n");
    printf("\t _________\n"
	       "\t|         |\n"
	       "\t|        ( )\n"
	       "\t|        /|\\\n"
	       "\t|        / \\\n"
	       "\t|             \n"
	       "\t|             \n");
    printf("----------------------MAIN MENU----------------------\n");
    printf("The Rules of the game are as follows: \n1)Please enter all the alphabets in lower case.");
    printf("\n2)You can select difficulty as Easy(1),Medium(2) and Hard(3).\n");
    printf("If you want to leave you can by typing in quit \n ");
    printf("\nPlease Enjoy and DO NOT BE HANGED \n");
    srand(time(NULL));

    char guessWordsE[MaxWords][5];
    char guessWordsM[MaxWords][9];
    char guessWordsH[MaxWords][MaxLen];
    int WordsReadE=0;
    int WordsReadM=0;
    int WordsReadH=0;

    FILE *p = fopen("Words.txt","r");
    char input[64];


    if(p==NULL)
    {
        printf("Failed to open File \n");
        return 0;
    }

    while(fgets(input,63,p))
    {
        int l1=strlen(input);
        if(l1<5)
        {
            sscanf(input,"%s",guessWordsE[WordsReadE]); //in this statement input is taking words from file and those words are being stored in the array guessW
            WordsReadE++;
        }
        else if(l1>4 && l1<9)
        {
            sscanf(input,"%s",guessWordsM[WordsReadM]); //in this statement input is taking words from file and those words are being stored in the array guessW
            WordsReadM++;

        }
        else
        {
            sscanf(input,"%s",guessWordsH[WordsReadH]); //in this statement input is taking words from file and those words are being stored in the array guessW
            WordsReadH++;
        }

    }
    //printf("Total Words Read In: %d\n", WordsReadIn);
    fclose(p);

    char body[7];

    int lives=6;
    int correct=0;
    int oldcorrect=0;
    int mistakes=-1;

    int guessedL[12]={0,0,0,0,0,0,0,0,0,0,0,0};

    int quit=0;
    int i=0;

    char guess[16];
    char letterEntered;
    int c1=1;
    printf("Please Select the Difficulty :");
    scanf("%d", &c1);
    char diff="r";

     printf("Loading");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        putchar('.');
        fflush(stdout); //fflush empties whatever is in the buffer to the screen
        sleep(1); //sleep() function in C allows the users to wait for a current thread for a specific time
    }
    putchar('\n');

   if(diff=="E" || diff=="e")
    {
        c1=1;
    }
    else if(diff=="M" || diff=="m")
    {
        c1=2;
    }
    else if(diff=="H" || diff=="h")
    {
        c1=3;
    }

    if (c1==1)
    {
        system("cls");

        int randindx=rand()%WordsReadE;
        int len=strlen(guessWordsE[randindx]);


    while(correct<len)
    {

        for(i=0;i<len;i++)
        {
             if(guessedL[i]==1)
             {
                 printf("%c ", guessWordsE[randindx][i]);
             }
             else
             {
                 printf("_ ");
             }
         }

        printf("\n");

        printf("Guess a Letter :");
        fgets(guess,10,stdin);

        if(strncmp(guess, "quit", 4)== 0)
        {
            quit=1;
            break;
        }
         letterEntered=guess[0];

         oldcorrect=correct;
         for(i=0;i<len;i++)
         {
             if( guessedL[i]==1)
             {
                 continue;
             }
             if(letterEntered == guessWordsE[randindx][i])
             {
                 guessedL[i]=1;
                 correct++;

             }
         }
         if (oldcorrect==correct)
         {
             lives--;
             mistakes++;
             printf("OOPS!!  Incorrect guess \n");
             if(lives==0)
             {
                 printf("You were Hanged !!!\n");
                 break;
             }
         }
         else
         {
             printf("Correct Guess \n");
         }

         //printf("Correct Guesses Made : %d\n", correct);
         printBody(mistakes,body);
         printf("\n");
    }//while loop
    if(quit==1)
    {
        printf("The user Quit Early\n ");
    }

    else if(lives ==0)
    {
        printBody(mistakes,body);

        printf("YOU LOOSE ! The word was : %s\n",
               guessWordsE[randindx]);
    }
    else
    {
        printf("YOU WOOOOOON!!!!!!!! \n The Word is:  %s\n",
               guessWordsE[randindx]);
    }

    }


    else if(c1==2)
    {
        system("cls");

        int randindx=rand()%WordsReadM;
        int len=strlen(guessWordsM[randindx]);
        printf("Start : \n");
    while(correct<len)
    {

        for(i=0;i<len;i++)
         {
             if( guessedL[i]==1)
             {
                 printf("%c ", guessWordsM[randindx][i]);
             }
             else
             {
                 printf("_ ");
             }
         }
         printf("\n");

        printf("Guess a Letter :");
        gets(guess);


        if(strncmp(guess, "quit", 4)== 0)
        {
            quit=1;
            break;
        }
         letterEntered=guess[0];

         oldcorrect= correct;
         for(i=0;i<len;i++)
         {
             if( guessedL[i]==1)
             {
                 continue;
             }
             if(letterEntered == guessWordsM[randindx][i])
             {
                 guessedL[i]=1;
                 correct++;

             }
         }
         if ( oldcorrect==correct)
         {
             lives--;
             mistakes++;
             printf("OOPS!!  Incorrect guess \n");
             if(lives==0)
             {
                 printf("You were Hanged !!!\n");
                 break;
             }
         }
         else
         {
             printf("Correct Guess \n");
         }

         //printf("Correct Guesses Made : %d\n", correct);
         printBody(mistakes,body);
         printf("\n");
    }//while loop

    if(quit==1)
    {
        printf("The user Quit Early\n ");
    }

    else if(lives ==0)
    {
        printBody(mistakes,body);

        printf("YOU LOOSE ! The word was : %s\n",
               guessWordsM[randindx]);
    }
    else
    {
        printf("YOU WOOOOOON!!!!!!!! \n The Word is:  %s\n",
               guessWordsM[randindx]);
    }
    }


    else if (c1==3)
    {
        system("cls");

        int randindx=rand()%WordsReadH;
        int len=strlen(guessWordsH[randindx]);
        printf("Start : \n");
    while(correct<len)
    {

        for(i=0;i<len;i++)
         {
             if( guessedL[i]==1)
             {
                 printf("%c ", guessWordsH[randindx][i]);
             }
             else
             {
                 printf("_ ");
             }
         }
         printf("\n");

        printf("Guess a Letter :");
        gets(guess);


        if(strncmp(guess, "quit", 4)== 0)
        {
            quit=1;
            break;
        }
         letterEntered=guess[0];

         oldcorrect= correct;
         for(i=0;i<len;i++)
         {
             if( guessedL[i]==1)
             {
                 continue;
             }
             if(letterEntered == guessWordsH[randindx][i])
             {
                 guessedL[i]=1;
                 correct++;

             }
         }
         if ( oldcorrect==correct)
         {
             lives--;
             mistakes++;
             printf("OOPS!!  Incorrect guess \n");

             if(lives==0)
             {
                 printf("You were Hanged !!!\n");
                 break;
             }
         }
         else
         {
             printf("Correct Guess \n");

         }

         //printf("Correct Guesses Made : %d\n", correct);
         printBody(mistakes,body);
         printf("\n");

    }//while loop
    if(quit==1)
    {
        printf("The user Quit Early\n ");
    }

    else if(lives ==0)
    {
        printBody(mistakes,body);

        printf("YOU LOOSE !!!\nThe word was : %s\n",
               guessWordsH[randindx]);
    }
    else
    {
        printf("YOU WOOOOOON!!!!!!!! \n The Word is:  %s\n",
               guessWordsH[randindx]);
    }

    }

    else
    {
        printf("Invalid Choice entered :\n");
    }
    return 0;
}
