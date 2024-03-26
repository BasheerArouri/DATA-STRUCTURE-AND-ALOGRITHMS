#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMUM_LETTERS 500
#define MAXIMUM_WORDS 20


typedef struct AVLnode* AVLNode;
struct AVLnode
{
    char course[MAXIMUM_LETTERS];
    char course_code[MAXIMUM_LETTERS];
    int credit_hours;
    char topics[MAXIMUM_LETTERS];

    struct AVLnode* Left;
    struct AVLnode *Right;
    int Height;

};

AVLNode MakeEmpty( AVLNode T );
int Height( AVLNode P );
int Max( int Lhs, int Rhs );
AVLNode SingleRotateWithLeft( AVLNode K2 );
AVLNode SingleRotateWithRight( AVLNode K1 );
AVLNode DoubleRotateWithLeft( AVLNode K3 );
AVLNode DoubleRotateWithRight( AVLNode K1 );
AVLNode Insert( char course[], int credit_hours, char course_code[], char topics[], AVLNode T );
int Max( int Lhs, int Rhs );
AVLNode get_file_info();
void print_dashes();
int get_choice();
int is_number(char choice[]);
void print_the_list();
void add_coure(AVLNode T);





int main()
{

    int choice;
    AVLNode T = NULL;
    int check_loading_is_done = 0;

    while(1)
    {
        print_dashes();
        print_the_list();
        choice = get_choice();


        switch(choice)
        {

        case 1:
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                T = get_file_info();
                printf("\t--->Reading courses.txt and Creation the tree is done!.\n");
                check_loading_is_done = 1;
                break;
            }


            case 2:
            {
                if(!check_loading_is_done)
                {
                    printf("Sorry, but you should loading the Tree Info first from the file.\n");
                    break;
                }
                printf("Your choice is ---> <%d>\n\n", choice);
                add_coure(T);
                break;
            }


















        case 10:
            {
                //save_to_file(T);
                exit(0);
            }

        }

    }

    //printf("T = %s\n", T  ->course);
    //printf("T ->Right = %s\n", T ->Right ->course);
    //printf("T ->Left = %s\n", T ->Left ->course);



    return 0;
}


AVLNode MakeEmpty( AVLNode T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}


AVLNode Insert( char course[], int credit_hours, char course_code[], char topics[], AVLNode T )
{
    if( T == NULL )
    {
        T = (AVLNode) malloc(sizeof(struct AVLnode ));

        if( T == NULL )
            printf( "Out of space!" );
        else
        {
            strcpy(T ->course, course);
            T ->credit_hours = credit_hours;
            strcpy(T ->course_code, course_code);
            strcpy(T ->topics, topics);
            T ->Height = 0;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if( strcmp(T ->course, course) > 0)
    {
        T->Left = Insert( course, credit_hours, course_code, topics, T ->Left);

        if( Height( T->Left ) - Height( T->Right ) == 2 )
        {
            if( strcmp(T ->course, course ))
                T = SingleRotateWithLeft( T );

            else
                T = DoubleRotateWithLeft( T );
        }
    }
    else if( strcmp(T ->course, course ) < 0)
    {
        T->Right = Insert( course, credit_hours, course_code, topics, T ->Right);

        if( Height( T->Right ) - Height( T->Left ) == 2 )
        {

            if( strcmp(course, T ->Right->course) > 0 )
                T = SingleRotateWithRight( T );
            else
                T = DoubleRotateWithRight( T );
        }
    }

    T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
    return T;
}

int Height( AVLNode P )
{
    if( P == NULL )
        return -1;
    else
        return P->Height;
}


AVLNode SingleRotateWithLeft( AVLNode K2 )
{

    AVLNode K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
    K1->Height = Max( Height( K1->Left ), K2->Height ) + 1;

    return K1;  /* New root */
}


AVLNode SingleRotateWithRight( AVLNode K1 )
{

    AVLNode K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max( Height( K1->Left ), Height( K1->Right ) ) + 1;
    K2->Height = Max( Height( K2->Right ), K1->Height ) + 1;

    return K2;
}


AVLNode DoubleRotateWithLeft( AVLNode K3 )
{
    K3->Left = SingleRotateWithRight( K3->Left );
    return SingleRotateWithLeft( K3 );
}


AVLNode DoubleRotateWithRight( AVLNode K1 )
{
    K1->Right = SingleRotateWithLeft( K1->Right );
    return SingleRotateWithRight( K1 );
}



int Max( int Lhs, int Rhs )
{
    return Lhs > Rhs ? Lhs : Rhs;
}

AVLNode get_file_info()
{
    AVLNode T = MakeEmpty(NULL);

    FILE *courses_file = fopen("courses.txt", "r");

    if(courses_file == NULL)
    {
        printf("This File does not exist.\n");
        exit(0);
    }

    char line[MAXIMUM_LETTERS] = "";
    char ending_line[MAXIMUM_LETTERS] = "";
    char words[MAXIMUM_WORDS][MAXIMUM_LETTERS];
    char course[MAXIMUM_LETTERS] = "";



    char *last_line = fgets(line, 500, courses_file);

    while(last_line != NULL)
    {
        int i = 0;
        strcpy(course, strtok(last_line, ":"));
        strcpy(ending_line, strtok(NULL, ":"));

        char *word = strtok(ending_line, "#");

        while(word != NULL)
        {
            strcpy(words[i], word);
            word = strtok(NULL, "#");
            i++;
        }


        int credit_hours = atoi(words[0]);

        char course_code[MAXIMUM_LETTERS] = "";
        strcpy(course_code, words[1]);

        char topics[MAXIMUM_LETTERS] = "";
        strcpy(topics, words[2]);


        T =  Insert(course, credit_hours, course_code, topics, T);

        last_line = fgets(line, 500, courses_file);
    }

    //T = Insert("Data Structures", 4, "COMP2421", "topic 1, topic 2", T);
    //T = Insert("Introduction to Franch", 5, "FRE111", "topic 1, topic 2", T);
    //T = Insert("Introduction to programming", 5, "COMP133", "topic 1, topic 2", T);
    fclose(courses_file);
    return T;

}

void print_dashes()
{
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
}


int get_choice()            /// function body
{
    char choice[MAXIMUM_LETTERS];       /// Define a string to get input from the user and if it's specified the conditions, we convert it to number by atoi function

    printf("\nPlease enter a number between 1-10: ");
    scanf("%s", choice);

    while(1)
    {
        if(!is_number(choice))      /// while the conditions do not specified
        {

            printf("Please enter a valid number between 1-9, Not a Letter: ");
            scanf("%s", choice);
            continue;
        }

        int correct_choice = atoi(choice);   /// if the condition  of being a number is specified

        if(correct_choice > 0 && correct_choice < 11)  /// if the number is between 1 and 9
        {
            return correct_choice;
        }

        else
        {
            printf("Please enter a valid number between 1-9: ");  /// if the number is not in the range 1-9
            scanf("%s", choice);
        }
    }

}


int is_number(char choice[])   /// function body
{
    for (int i = 0; choice[i]!= '\0'; i++)  /// iteration
    {
        if (!isdigit(choice[i]))  /// if we found at least one char
            return 0;   /// return 0 for finding at least one char
    }
    return 1;   /// return 1 for not finding any char

}

void print_the_list()  /// print the available choices for the user
{
    printf("You have these Choices:");
    printf("\n");
    printf("1. Read the file courses.txt file and create the tree.\n");
    printf("2. Insert a new course with all your associated data.\n");
    printf("3. Find a course and support updating of its information.\n");
    printf("4. List courses in lexicographic order with their associated information (credit hours, IDs, and topics).\n");
    printf("5. List all topics associated with a given course.\n");
    printf("6. List all courses in lexicographic order that belong to the same department.\n");
    printf("7. Delete a course.\n");
    printf("8. Delete all courses that start with a specific letter.\n");
    printf("9. Delete all courses belong to a given department.\n");
    printf("10. Save all words in file offered_courses.txt and exit the program.\n");
}


void add_coure(AVLNode T)
{
    if(T == NULL)
    {
        printf("Empty Tree.\n");
        return;
    }

    char course[MAXIMUM_LETTERS];
    printf("Please enter the name of the course: ");
    gets(course);

    int credit_hours;
    printf("Please enter the credit hours of this Course: ");
    scanf("%d", &credit_hours);

    char course_code[MAXIMUM_LETTERS];
    printf("Please enter the course code: ");
    scanf("%s", course_code);

    char course_topics[MAXIMUM_LETTERS];
    printf("Please enter the topics of this course, if you want to write more then 1 topic, separate them by , (Comma): ");
    gets(course_topics);


}
