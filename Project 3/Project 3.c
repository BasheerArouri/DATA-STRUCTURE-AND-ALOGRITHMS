#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMUM_LETTERS 500
#define MAXIMUM_WORDS 20
#define MAXIMUM_NUMBER_OF_COURSES 1000

/*Basheer Arouri
1201141
Dr. Ahmad Abu snina
section 1
*/



struct Course
{
    char course[MAXIMUM_LETTERS];  /// Course
    int credit_hours;                 /// Credit hours of this Course
    char course_code[MAXIMUM_LETTERS];  /// Course Code of this Course
    char department[MAXIMUM_LETTERS];  /// Department of this Course
    char topics[MAXIMUM_LETTERS];  /// Topics of this Course
    char status;   /// Status of the Course (E, O, D);
};

int first_prime_number;                          /// Table Size
int number_of_collisions_of_linear_hashing;         /// Calculate number of Collisions in the Linear Hashing
int number_of_collisions_of_double_hashing;         /// Calculate the number of Collisions in the Double Hashing


int get_number_of_courses()                      /// Function to get number of Courses
{
    FILE *courses_file = fopen("offered_courses.txt", "r");

    if(courses_file == NULL)          /// Empty File
    {
        printf("Empty File.\n");
        exit(0);
    }

    char line[MAXIMUM_LETTERS];
    char *last_line = fgets(line, 500, courses_file);  /// Count the number of lines in this File
    int number_of_lines = 0;

    while(last_line != NULL)
    {
        number_of_lines++;
        last_line = fgets(line, 500, courses_file);       /// Iterate on each line
    }
    return number_of_lines;      /// return number of Lines
}

int get_prime_number(int number)       /// Function to get the prime number that is the size of the Hash table
{
    int prime = number;

    if(prime %2 == 0)
    {
        prime = prime + 1;
    }


    while(prime != 0)                /// while not finding the prime number
    {
        int flag = 0;
        int temp_number = prime;

        for(int i = 2; i < temp_number/2; i++)    /// for loop from 2 to half the number
        {
            if(temp_number %i == 0)      /// if it is not prime
            {
                flag = 1;
                break;
            }
        }

        if(flag != 1)      /// if it is prime
        {
            return temp_number;    /// return the prime number
        }
        prime++;
    }

    return 0;        /// just to avoid the warning
}


void print_dashes()     ///Function to print dashes
{
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
}

void print_the_list()  /// print the available choices for the user
{
    printf("You have these Choices:");
    printf("\n");
    printf("1. Print hashed tables (including empty spots).\n");
    printf("2. Print out table size and the load factor.\n");
    printf("3. Print out the used hash functions.\n");
    printf("4. Insert a new record to hash table (insertion will be done on both hash tables).\n");
    printf("5. Search for a specific word (specify which table to search in).\n");
    printf("6. Delete a specific record (from both tables).\n");
    printf("7. Compare between the two methods in terms of number of collisions occurred.\n");
    printf("8. Save hash table back to a file named saved_courses.txt (of the double hashing) .\n");
}

int is_number(char choice[])   /// function to check weather the input from the user is valid
{
    for (int i = 0; choice[i]!= '\0'; i++)  /// iteration
    {
        if (!isdigit(choice[i]))  /// if we found at least one char
            return 0;   /// return 0 for finding at least one char
    }
    return 1;   /// return 1 for not finding any char

}



int get_choice()            /// function to return choice of the User
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

        if(correct_choice > 0 && correct_choice < 11)  /// if the number is between 1 and 10
        {
            return correct_choice;
        }

        else
        {
            printf("Please enter a valid number between 1-10: ");  /// if the number is not in the range 1-10
            scanf("%s", choice);
        }
    }

}

int hash(char* key, int TableSize)   /// Function to find the hash value of the string
{
    int hashValue = 0;
    while( *key != '\0' )      /// Iterate till the end
    {
        hashValue = ( hashValue << 5 ) + *key++;
    }
    return abs(hashValue % TableSize);     /// return the hash value of this string
}



void insert_for_linear_hashing(struct Course *courses[], int TableSize, char course[], int credit_hours, char course_code[], char department[], char topics[])
{
    /// Function to insert a course to the linear hashing
    int i = 0;
    int hash_idex = (hash(course, TableSize) + i)%TableSize;      /// Hash Function of the Linear Hashing


    while(1)                         /// To insert the Course
    {
        if(courses[hash_idex] ->status == 'O'  && courses[hash_idex] ->status != 'D')  /// If this site is not Occupied from another Course or Deleted
        {
            number_of_collisions_of_linear_hashing++;  /// Find number of Collisions
            i++;
            hash_idex = (hash(course, TableSize) + i)%TableSize;  /// Find the new value of the hash because the Collision
            continue;
        }

        else              /// Finding the Node where we want to add this Course
        {
            printf("Inner.\n");
            strcpy(courses[hash_idex] ->course, course);
            strcpy(courses[hash_idex] ->course_code, course_code);
            courses[hash_idex] ->credit_hours = credit_hours;
            strcpy(courses[hash_idex] ->department, department);
            strcpy(courses[hash_idex] ->topics, topics);
            courses[hash_idex] ->status = 'O';         /// let this Site Occupied with this Course
            break;               /// break the Loop

        }
    }
}

int get_second_prime(int prime)   /// Function to find second prime
{
    prime = prime -1;

    while(prime != 0)
    {
        int flag = 0;
        int temp_number = prime;

        for(int i = 2; i < temp_number/2; i++)
        {
            if(temp_number %i == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag != 1)
        {
            return temp_number;
        }
        prime--;
    }

    return 0;
}



void insert_for_double_hashing(struct Course* courses[],  int TableSize, char course[], int credit_hours, char course_code[], char department[], char topics[])
{

    /// Function that insert a Course to Double Hash

    int i = 0;
    int R = get_second_prime(TableSize);           /// Get the value of the smallest prime number after the Table Size
    int hash_value = hash(course, TableSize);       /// Finding the hash value of this String
    int hash_idex = abs(hash_value%TableSize + (i * (R - (hash_value%R))));  /// Hash Function for the Double Hashing

    if(hash_idex > TableSize)       /// if the Table size is smaller than the hash index of this Hash table
    {
        hash_idex = hash_idex %TableSize;
    }


    while(1)   /// Iterate till we found a node to insert this Course in the Double Hash Table
    {
        if(courses[hash_idex] ->status == 'O'  && courses[hash_idex] ->status != 'D')/// if this Node is Occupied , we cannot add this Course
        {
            number_of_collisions_of_double_hashing++; /// Increment the value of Collisions for this Double Hashing by 1
            i++;
            hash_idex = abs(hash_value%TableSize + (i *(R - (hash_value%R))));  /// Hash Function for Double Table

            if(hash_idex > TableSize)   /// if the Table size is smaller than the hash index of this Hash table
            {
                hash_idex = hash_idex %TableSize;
            }
            continue;
        }

        else   /// Finding the Node where we want to add this Course
        {
            strcpy(courses[hash_idex] ->course, course);
            strcpy(courses[hash_idex] ->course_code, course_code);
            courses[hash_idex] ->credit_hours = credit_hours;
            strcpy(courses[hash_idex] ->department, department);
            strcpy(courses[hash_idex] ->topics, topics);
            courses[hash_idex] ->status = 'O';
            break;
        }
    }
}


void rehash(struct Course* courses1[], struct Course* courses2[])
{
    int TableSize = first_prime_number;
    int index = 0;
    int counter = 0;

    while(index < TableSize)
    {

        if(courses1[index] ->status == 'O')
            counter++;

        index++;
    }

    int temp = ((float)(counter)/(first_prime_number)) *100;

    if(temp > 70)
    {

        int first_prime_before_update = first_prime_number;
        first_prime_number = get_prime_number(first_prime_number * 2);

        for(int i = 0; i < first_prime_number; i++)
        {
            courses1[i] = malloc(sizeof(struct Course));
            courses1[i] ->status = 'E';
        }

        for(int i = 0; i < first_prime_before_update; i++)
        {
            if(courses2[i] ->status == 'O')
            {
                insert_for_linear_hashing(courses1, first_prime_number, courses2[i] ->course, courses2[i] ->credit_hours,
                 courses2[i] ->course_code, courses2[i] ->department, courses2[i] ->topics);
            }
        }

         for(int i = 0; i < first_prime_number; i++)
        {
            courses2[i] = malloc(sizeof(struct Course));
            courses2[i] ->status = 'E';
        }

        for(int i = 0; i < first_prime_number; i++)
        {
            if(courses1[i] ->status == 'O')
            {
                insert_for_double_hashing(courses2, first_prime_number, courses1[i] ->course, courses1[i] ->credit_hours,
                 courses1[i] ->course_code, courses1[i] ->department, courses1[i] ->topics);
            }
        }
    }
}


    void save_file_info(struct Course *courses_with_linear_hashing[], struct Course *courses_with_double_hashing[])
    {
        /// Function to save loading the Info from the File and insert them into Linear Hash Table, Double Hash Table

        FILE *courses_file = fopen("offered_courses.txt", "r");   /// Open the file named courses.txt to read from it

        if(courses_file == NULL)                        /// If this file does not exist
        {
            printf("This File does not exist.\n");
            exit(0);                                   /// exit the Program
        }

        ///Some variables to use under
        char line[MAXIMUM_LETTERS] = "";
        char ending_line[MAXIMUM_LETTERS] = "";
        char words[MAXIMUM_WORDS][MAXIMUM_LETTERS];
        char course[MAXIMUM_LETTERS] = "";



        char *last_line = fgets(line, 500, courses_file);  /// Pointer for the current Line

        while(last_line != NULL)      /// Reading till the last Line
        {
            int i = 0;
            strcpy(course, strtok(last_line, ":"));     /// Strtok to cut the String(Line) depends on ":"
            strcpy(ending_line, strtok(NULL, ":"));      /// Strtok to cut the String(Line) depends on ":"

            char *word = strtok(ending_line, "#");       /// Strtok to cut the String(Line) depends on "#"

            while(word != NULL)                     /// Copying the content of the array (word) to another variables
            {
                strcpy(words[i], word);
                word = strtok(NULL, "#");
                i++;
            }


            int credit_hours = atoi(words[0]);

            char course_code[MAXIMUM_LETTERS] = "";
            strcpy(course_code, words[1]);

            char department[MAXIMUM_LETTERS] = "";
            strcpy(department, strtok(words[2], "/"));

            char topics[MAXIMUM_LETTERS] = "";
            strcpy(topics, strtok(NULL, "/"));


            insert_for_double_hashing(courses_with_double_hashing, first_prime_number, course, credit_hours, course_code, department, topics); /// insert this Course to Linear Hash Table

            insert_for_linear_hashing(courses_with_linear_hashing, first_prime_number, course, credit_hours, course_code, department, topics);  /// insert this Course to Double Hash Table

            last_line = fgets(line, 500, courses_file);  /// Read till the last Line
        }
    }



    void print_Hashing(struct Course *courses[], int TableSize)  /// Printing the values of each Table
    {
        int temp = TableSize;
        int hash_index = 0;
        while(temp > 0)
        {
            if(courses[hash_index] ->status == 'E')     /// if this site in the Table is Empty
            {
                printf("\n");
                printf("\t---> At index %d,  ", hash_index);
                printf("Empty Cell.\n\n");
            }

            else if(courses[hash_index] ->status == 'O')  /// if this site in the Table is Occupied
            {

                printf("\t---> At index %d,  ", hash_index); /// Print Some info
                printf("%s.....%s.....%d.....%s.....%s\n", courses[hash_index] ->course, courses[hash_index] ->course_code,
                       courses[hash_index] ->credit_hours, courses[hash_index] ->department,
                       courses[hash_index] ->topics);
            }
            hash_index++;
            temp --;
        }
    }


    void print_load_factor(struct Course* courses_with_linear_hashing[], struct Course* courses_with_double_hashing[])  /// Calculate the load Factor and print it's value
    {
        printf("Prime = %d\n", first_prime_number);
        printf("\t ---> The Table Size for the Linear and Double Hashing = %d\n", first_prime_number);

        int number_of_cells = 0;
        int i = 0;
        float temp = (float)(first_prime_number);

        while(i < first_prime_number) /// Counting the number of elements in this Table
        {
            if(courses_with_linear_hashing[i] ->status == 'O')  /// if this Node is Occupied, then counts it
            {
                number_of_cells++;
            }
            i++;
        }
        printf("\t ---> The Load Factor for the Linear and Double Hashing = %0.2f\n", (number_of_cells/temp));  /// Loading Factor
        return;
    }


    void print_hash_functions()  /// Function that print the Hashing Functions that we used in Linear, Double Hashing
    {
        printf("\t\tFor Open Addressing (Linear Hashing in my program) ---> h(x) = (hash(course, TableSize) + i)%%TableSize.\n");
        printf("\t\tFor Open Addressing (Double Hashing in my program) ---> h(x) = hash_value%%TableSize + (i *(R - (hash_value%%R))).\n");

        printf("\n");
        printf("\t\tPS : For Line 2, if the h(x) is greater than TableSize, then h(x) = h(x)%%TableSize.\n"); /// if the hash value greate
        ///r than the Table Size

        return;
    }



    void add_course_from_user(struct Course* courses_with_linear_hashing[], struct Course* courses_with_double_hashing[])     /// Function to add a Course from the User
    {
        char course[MAXIMUM_LETTERS];
        printf("Please enter the name of the course: ");
        gets(course);                       /// Read a course name from the user
        gets(course);

        int credit_hours;                     /// Read a course credit hours from the user
        printf("Please enter the credit hours of this Course: ");
        scanf("%d", &credit_hours);

        char course_code[MAXIMUM_LETTERS];
        printf("Please enter the course code: ");
        gets(course_code);                    /// Read a course code from the user
        gets(course_code);

        char department[MAXIMUM_LETTERS];
        printf("Please enter the course Department: ");
        gets(department);                             /// Read a course department from the user


        char course_topics[MAXIMUM_LETTERS];
        printf("Please enter the topics of this course, if you want to write more then 1 topic, separate them by , (Comma): ");
        gets(course_topics);           /// Read a course topics from the user

        insert_for_linear_hashing(courses_with_linear_hashing, first_prime_number, course, credit_hours, course_code, department
                                  , course_topics);  /// Insert this Node(Course) after get it from the user
        insert_for_double_hashing(courses_with_double_hashing, first_prime_number, course, credit_hours, course_code, department,
                                  course_topics);
        printf("\n");
        printf("\t---> Adding a Course with Course Code is %s\n", course_code);  /* Printing Statements*/
        printf("\t--->Thank you to add this course.\n\n");
        rehash(courses_with_linear_hashing, courses_with_double_hashing);
        return;
    }


    void Delete(struct Course* courses_for_linear_proping[], struct Course* courses_for_double_proping[]) /// Function that Delete a Course from Two Tables
    {

        char course[MAXIMUM_LETTERS];
        printf("\nPlease enter the Course you want to Delete it from the Two Hash Tables: ");
        gets(course); /// For Deleted Line
        gets(course);

        int i = 0;
        int flag = 0;
        int TableSize = first_prime_number;

        int hash_index = abs((hash(course, TableSize) + i)%TableSize); /// Hash Function for the Linear Hashing

        while(i < TableSize)
        {
            if(strcmp(courses_for_linear_proping[hash_index] ->course, course) == 0 && (courses_for_linear_proping[hash_index] ->status != 'D'))
            {
                /// if this Course is founding and the Course is exist(not Deleted)
                flag = 1;          /// Flag Value
                break;
            }
            i++;
            hash_index = abs((hash(course, TableSize) + i)%TableSize); /// Find the value of the string hash after update i
        }


        if(flag == 1)
        {
            courses_for_linear_proping[hash_index] ->status = 'D'; /// Set the Status for this node(D) Deleted node
            printf("Deleting a Course from the Double Hashing with Course name = %s.\n", course);
        }

        else
            printf("Sorry, but this Course does not exist in the Linear Hashing Table.\n");


        ///Deleted for the Double Hashing

        i = 0;
        flag = 0;
        TableSize = first_prime_number;
        int R = get_second_prime(TableSize);  /// finding the prime value smaller than the Table Size
        int hash_value = hash(course, TableSize);

        hash_index = abs((hash_value %TableSize) + i * (R -(hash_value%R)));  /// Hash Function of Double Hashing

        if(hash_index > TableSize)
        {
            hash_index = hash_index%TableSize;
        }

        while(i < TableSize)
        {
            if(strcmp(courses_for_double_proping[hash_index] ->course, course) == 0 && (courses_for_double_proping[hash_index] ->status != 'D'))
            {
                /// if finding this Node
                flag = 1;
                break;
            }
            i++;
            hash_index = abs((hash_value %TableSize) + i * (R -(hash_value%R))); /// new value of hash for Collision

            if(hash_index > TableSize)
            {
                hash_index = hash_index%TableSize; /// if the value of the hash is greater than the Table Size
            }
        }


        if(flag == 1)
        {
            courses_for_double_proping[hash_index] ->status = 'D'; /// if finding the node to Delete it
            printf("Deleting a Course from the linear Hashing with Course name = %s.\n", course);
        }

        else
            printf("Sorry, but this Course does not exist in The Double Hashing Table.\n");  /// not finding the value
    }

    void print_number_of_collisions()  /// Function to print the number of collisions
    {
        printf("\t ---> Number of Collisions in the Linear Hashing = %d\n", number_of_collisions_of_linear_hashing);
        printf("\t ---> Number of Collisions in the Double Hashing = %d\n", number_of_collisions_of_double_hashing);
        return;
    }


    void save_in_file(struct Course* courses[]) /// Function to save all the data after finishing the program in the file with Double Hashing
    {
        FILE* out = fopen("saved_courses.txt", "w");  /// open the file

        if(out == NULL)
        {
            printf("File does not Exist.\n");
            exit(0);
        }

        int temp = first_prime_number;
        int hash_index = 0;
        while(temp > 0)    /// iterate for all the Courses
        {
            if(courses[hash_index] ->status == 'E')  /// if this Node is Empty
            {
                fprintf(out, "\n");
                fprintf(out, "\t---> At index %d,  ", hash_index);
                fprintf(out, "Empty Cell.\n\n");
            }

            else if(courses[hash_index] ->status == 'O')  /// if this node is Occupied
            {

                fprintf(out, "\t---> At index %d,  ", hash_index);
                fprintf( out, "%s.....%s.....%d.....%s.....%s\n", courses[hash_index] ->course, courses[hash_index] ->course_code,
                         courses[hash_index] ->credit_hours, courses[hash_index] ->department,
                         courses[hash_index] ->topics);
            }
            hash_index++;
            temp --;
        }
        fclose(out);
        return;
    }



    int main()  /// main Function to test all the methods
    {
        number_of_collisions_of_linear_hashing = 0;  /// initially zero
        number_of_collisions_of_double_hashing = 0;  /// initially zero
        int choice;
        int number_of_courses = get_number_of_courses();  /// get the number of Courses
        first_prime_number = get_prime_number(number_of_courses/0.7);

        struct Course* courses_for_linear_proping[first_prime_number]; /// Define Array of Pointers to Course for Linear Hashing
        struct Course* courses_for_double_proping[first_prime_number];  /// Define Array of Pointers to Course for Double Hashing



        int temp_prime = first_prime_number - 1;

        while(temp_prime >= 0)  /// to set all of Pointers in Linear Hashing
        {
            courses_for_linear_proping[temp_prime] = (struct Course*)malloc(sizeof(struct Course));
            courses_for_linear_proping[temp_prime] ->status = 'E'; /// initially set Empty
            temp_prime--;
        }


        temp_prime = first_prime_number - 1;

        while(temp_prime >= 0)
        {
            /// to set all of Pointers in Linear Hashing
            courses_for_double_proping[temp_prime] = (struct Course*)malloc(sizeof(struct Course));
            courses_for_double_proping[temp_prime] ->status = 'E';  /// initially set Empty
            temp_prime--;
        }

        save_file_info(courses_for_linear_proping, courses_for_double_proping);
        while(1)
        {

            print_dashes();  /// Printing Dashes after each iteration
            print_the_list();   /// Printing The list after each iteration
            choice = get_choice();  /// get the choice from the user after each iteration

            switch(choice)
            {

            case 1:      /// Printing the Courses in the Linear Hashing and in the Double Hashing
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                printf("These Info About the Linear Hashing:\n\n");
                print_Hashing(courses_for_linear_proping, first_prime_number);
                printf("\n\n\nThese Info About the Double Hashing:\n\n");
                print_Hashing(courses_for_double_proping, first_prime_number);
                break;
            }

            case 2:          /// Printing The Load Factor
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                print_load_factor(courses_for_linear_proping, courses_for_double_proping);
                break;
            }

            case 3:      /// Printing the Hash Functions that we used in the Linear Hashing and the Double Hashing
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                print_hash_functions();
                break;
            }

            case 4:         /// Add a new Course from the User
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                add_course_from_user(courses_for_linear_proping, courses_for_double_proping);
                break;
            }

            case 5:    /// Making a Search for a specific Course
            {
                printf("Your choice is ---> <%d>\n\n", choice);

                int subchoice;
                printf("You have these 2 choices: \n");           /// tell the user witch Search
                printf("1- Apply Search on the Linear Hashing.\n");
                printf("2- Apply Search on the Double Hashing.\n");

                printf("\nPlease pick a number: ");
                scanf("%d", &subchoice);

                if(subchoice == 1)                 /// if Linear Probing
                {
                    char course[MAXIMUM_LETTERS];
                    printf("\n\nPlease enter the Course you want to find it's info: ");
                    gets(course);
                    gets(course);

                    int i = 0;
                    int flag = 0;
                    int TableSize = first_prime_number;

                    int hash_index = abs((hash(course, TableSize) + i)%TableSize);

                    while(i < TableSize)
                    {
                        /// if finding this Course and it is not Deleted
                        if((strcmp(courses_for_linear_proping[hash_index] ->course, course)  == 0) && (courses_for_linear_proping[hash_index] ->status != 'D'))
                        {
                            flag = 1;
                            break;
                        }
                        i++;
                        hash_index = abs((hash(course, TableSize) + i)%TableSize); /// update the value of the hash for Searching
                    }


                    if(flag == 1)  /// Finding the Course
                    {
                        printf("Some info about this Course: ");
                        printf("\n\n");
                        printf("\t ---> Course Name: %s\n", courses_for_linear_proping[hash_index] ->course);
                        printf("\t ---> Course Code: %s\n", courses_for_linear_proping[hash_index] ->course_code);
                        printf("\t ---> Course Credit Hours: %d\n", courses_for_linear_proping[hash_index] ->credit_hours);
                        printf("\t ---> Course Department: %s\n", courses_for_linear_proping[hash_index] ->department);
                        printf("\t ---> Course Topics: %s\n", courses_for_linear_proping[hash_index] ->topics);
                    }

                    else
                        printf("Sorry, but this Course does not exist.\n"); /// For not Finding the Course
                }

                else if(subchoice == 2)  /// for Double Hashing
                {
                    char course[MAXIMUM_LETTERS];
                    printf("\n\nPlease enter the Course you want to find it's info: ");
                    gets(course);
                    gets(course);

                    int i = 0;
                    int flag = 0;
                    int TableSize = first_prime_number;
                    int R = get_second_prime(TableSize);
                    int hash_value = hash(course, TableSize);

                    int hash_index = abs((hash_value %TableSize) + i * (R -(hash_value%R))); /// Double Hashing Function

                    if(hash_index > TableSize)
                    {
                        hash_index = hash_index%TableSize; /// set new Value of this hash value
                    }

                    while(i < TableSize)
                    {
                        /// if this Course is found
                        if(strcmp(courses_for_double_proping[hash_index] ->course, course) == 0 && (courses_for_double_proping[hash_index] ->status != 'D'))
                        {
                            flag = 1;
                            break;
                        }
                        i++;
                        hash_index = abs((hash_value %TableSize) + i * (R -(hash_value%R)));

                        if(hash_index > TableSize)
                        {
                            hash_index = hash_index%TableSize;
                        }
                    }


                    if(flag == 1)  /// finding this Course
                    {
                        printf("Some info about this Course: ");
                        printf("\n\n");
                        printf("\t ---> Course Name: %s\n", courses_for_double_proping[hash_index] ->course);
                        printf("\t ---> Course Code: %s\n", courses_for_double_proping[hash_index] ->course_code);
                        printf("\t ---> Course Credit Hours: %d\n", courses_for_double_proping[hash_index] ->credit_hours);
                        printf("\t ---> Course Department: %s\n", courses_for_double_proping[hash_index] ->department);
                        printf("\t ---> Course Topics: %s\n", courses_for_double_proping[hash_index] ->topics);
                    }

                    else
                        printf("Sorry, but this Course does not exist.\n"); ///not finding the Course

                }
                break;
            }

            case 6:  /// For Deleting the Course
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                Delete(courses_for_linear_proping, courses_for_double_proping);
                break;
            }

            case 7:   /// Printing number of Collisions
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                print_number_of_collisions();
                break;
            }

            case 8:  /// Save into file with Double Hashing
            {
                printf("Your choice is ---> <%d>\n\n", choice);
                save_in_file(courses_for_double_proping);
                printf("Thx for Using my program!\n");
                exit(0);
            }
            }
        }
        return 0;
    }
