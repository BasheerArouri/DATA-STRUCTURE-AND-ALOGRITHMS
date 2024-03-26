///Name : Basheer Loay Arouri
/// ID : 1201141
/// Dr Ahmad Abusnina
/// Section 1
/// Project #1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMUM_LETTERS 500    /// Define A constant it's name is MAXIMUM_LETTERS and it's size is 500
#define MAXIMUM_WORDS 20       /// Define A constant it's name is MAXIMUM_WORDS and it's size is 20
#define MAXIMUM_CHARACTERS 20  /// Define A constant it's name is MAXIMUM_CHARACTERS and it's size is 20

///Comment


struct passenger_node      /// Define A passenger structcture (passenger node)
{
    long traveler_id;          /// Define A traveler id and it's type islong
    long travelling_date;      /// Define A traveling date and it's type is long
    char travelling_time[MAXIMUM_LETTERS];    /// Define A traveling time and it's type is String (Array of characters)
    char travelling_from[MAXIMUM_LETTERS];    /// Define A traveling from and it's type is String
    char travelling_to[MAXIMUM_LETTERS];      /// DEfine A traveling to and it's type is String
    struct passenger_node* Next;              /// Define A pointer to passenger node names's Next(Passengers in the same linked list)
    struct passenger_node* NextPassengerInBus;  /// Define A pointer to passenger node name's NextPassengerInBus (Passengers in the same bus)
};

struct bus_node            /// Define A bus structure (bus node)
{
    int bus_number;        /// Define A bus number and it's type is integer
    long bus_date;         /// Define A bus date and it's type is long
    char bus_departure_time[MAXIMUM_LETTERS];  /// Define a bus departure time and it's type is String
    char bus_from[MAXIMUM_LETTERS];            /// Define a bus from and it's type is String
    char bus_to[MAXIMUM_LETTERS];              /// Define a bus to and it's type is String
    double bus_price_of_ticket;                /// Define a bus price of ticket and it's type is double
    int bus_capacity;                          /// Define a bus capacity and it's type is integer
    struct bus_node* Next;                     /// Define a pointer to bus node and it's name is Next
    struct passenger_node* NextPassenger;      /// Define a pointer to passenger node to the passengers in this bus
};

struct bus_node* MakeEmptyBus(struct bus_node* buses_linked_list);  /// Function a pointer to bus node that makes the first node in the buses linked list(Header)

struct passenger_node* MakeEmptyPassenger(struct passenger_node* passengers_linked_list);  /// Function a pointer to passenger node that makes the first node in the passengers linked list(Header)

void insert_bus(struct bus_node* buses_linked_list, int bus_number_inserted, long bus_date_inserted, char bus_departure_time_inserted[], char bus_from_inserted[],
                char bus_to_inserted[], double bus_price_of_ticket_inserted, int bus_capacity_inserted);  /// Function to insert a bus to the buses linked list

void insert_passenger(struct passenger_node* passengers_linked_list, int passenger_number_inserted, long passenger_date_inserted, char passenger_departure_time_inserted[], char passenger_from_inserted[],
                      char passenger_to_inserted[]); /// Function to insert a passenger to the passengers linked list

void PrintPassengersList(struct passenger_node* passengers_linked_list); /// Function to print all the passengers in passengers linked list

void insert_passenger_to_bus(struct bus_node* bus, struct passenger_node* passenger); /// Function to insert passenger to a specific bus if the conditions are satisfied

int get_choice();       /// Function that get the user choice and make it valid if it is not

void print_the_list();  /// Function that print the available choices to the user

struct bus_node* load_bus_file_info(struct bus_node* buses_linked_list);  /// Function that load the bus file information and saves it in linked list(pointer)

struct passenger_node* load_passenger_file_info(struct passenger_node* passengers_linked_list);  /// Function that load the passenger file information and saves it in linked list(pointer)

void print_buses_info(struct bus_node* buses_linked_list);  /// Function that print all the buses info

void print_passengers_info(struct passenger_node* passengers_linked_list); /// Function that print all the passengers info

void print_dashes();  /// Function that print dashes(-----)

int check_bus_file_is_empty(struct bus_node* buses_linkd_list);  /// Function that check if the bus file is empty

int check_passenger_file_is_empty(struct passenger_node* passengers_linked_list);  /// Function that check if the passenger file is empty

void assign_passengers_to_the_buses(struct bus_node* buses_linked_list, struct passenger_node* passengers_linked_list);  /// Function that assign the passengers to buses

void print_assignment_passengers(struct bus_node* passengers_in_buses); /// Function that print all the buses info

int is_number(char choice[]);  /// Function that check if the given string is a number

void Delet(int X, struct passenger_node* L); /// Function that delete a passenger that satisfies the id from a passenger linked list

int get_user_bus_number();  /// Function that get the user info about the bus he wants to get it's info

struct bus_node* get_specific_bus(int bus_number, struct bus_node* buses_linked_list);  /// Function that return a pointer to a specific bus

void print_bus_info(struct bus_node* specific_bus);  /// Function that print info about a specific bus and it's passengers if exist

void print_unmatched_list(struct passenger_node* passengers_linked_list);  /// Function that print unmatched passengers

void add_user_passenger(struct passenger_node* passengers_linked_list);  /// Function that add a new passenger depend on the info that user inputed

long get_passenger_id();  /// Function that get the passenger id from the user

int check_in_unmatched_passengers(struct passenger_node* passengers_linked_list, long passenger_id);  /// Function that check if the passenger in the unmatched linked list

struct bus_node* check_in_assignment_buses(struct bus_node* buses, int passenger_id);  /// Function that check if the passenger in the assignment buses

void DeletPassengerFromBus(int passenger_id, struct passenger_node* passengers);  /// Function that delete a passenger from a specific bus

int IsLastInBus(struct passenger_node* this_passenger);  /// Function that check if the passenger is the last passenger in a specific bus

struct passenger_node* FindPreviousInBus(int X, struct passenger_node* L);  /// Function that find the previous passenger of a given linked list

int get_bus_number();  /// Function that get the bus number

int is_found_bus(struct bus_node* buses, int bus_number);  /// Function that check if the bus is exist or not

void DeletBus(int bus_number, struct bus_node* buses, struct passenger_node* unmatched_passengers);  /* Function that delete a specific bus and assign it's passengers (if exist) to unmatched
passengers linked list */

struct bus_node* FindPreviousBus(int X, struct bus_node* L);  /// Function that find the previous of a given bus

int IsLastBus(struct bus_node* bus);  /// Function that check if the bus is the last bus in the buses linked list


int main()    /// Driver code
{

    int choice;
    struct bus_node* buses_linked_list = MakeEmptyBus(NULL);  /// Make the header of the buses linked list
    struct passenger_node* passengers_linked_list = MakeEmptyPassenger(NULL);  /// Make the header of the passengers linked list

    int check_buses_load_is_done = 0;  /// Define a variable to check if the buses loading is done
    int check_passengers_load_is_done = 0;  /// Define a variable to check if the passengers loading is done
    int check_assignment_is_done = 0;  /// Define a variable to check if the assignment passengers in the buses is done

    while(1)
    {

        print_dashes();
        print_the_list();
        choice = get_choice();

        switch (choice)
        {

        case 1:
        {
            printf("Your choice is  ---> <%d>\n", choice);  /// Printing the choice of the user

            if(buses_linked_list ->Next != NULL)      /// check if the buses linked list is empty
            {
                printf("\nLoading the buses is already done.\n");

                break;                                /// if the buses linked list is empty, break
            }
            buses_linked_list = load_bus_file_info(buses_linked_list);   /// loading the buses linked list from a the file and save it


            if(buses_linked_list == NULL)             /// if the linked list is NULL
            {
                printf("This Buses File Does not exist.\n");
                break;                                /// break the case
            }

            if(!check_bus_file_is_empty(buses_linked_list))  /// if this file is not empty
            {
                print_buses_info(buses_linked_list);        /// printing the buses linked list
                printf("\nLoading These Buses is done!");
                check_buses_load_is_done = 1;             /// make loading buses is done
                break;
            }

            else
            {
                printf("This Buses File is empty, Please fill it and try again!\n");    /// if the buses file is empty
            }
            break;
        }

        case 2:
        {
            printf("Your choice is --->  <%d>\n", choice);

            if(passengers_linked_list ->Next != NULL)    /// if the passengers linked list is not empty
            {
                printf("\nLoading the passengers is already done.\n");
                break;
            }

            passengers_linked_list = load_passenger_file_info(passengers_linked_list);  /// loading these info in passenger linked list

            if(passengers_linked_list == NULL)           /// if the passengers linked list is not found
            {
                printf("This Passengers File Does not exist.\n");
                break;
            }

            if(!check_passenger_file_is_empty(passengers_linked_list))   /// if the passengers file is not empty
            {
                check_passengers_load_is_done = 1;               /// make passengers loading is done
                print_passengers_info(passengers_linked_list);   /// printing info about this passengers list
                printf("\nLoading These Passengers is done!");
                break;
            }

            else
            {
                printf("This Passengers File is empty, Please fill it and try again!\n");   /// if the passengers linked list is empty
            }
            break;
        }

        case 3:
        {
            printf("Your choice is ---> <%d>\n", choice);

            if(check_buses_load_is_done && check_passengers_load_is_done)    /// if the buses load and the passengers load are done
            {
                check_assignment_is_done = 1;                               /// make the assignment passengers to the buses is done
                assign_passengers_to_the_buses(buses_linked_list, passengers_linked_list);  /// assign the passengers to buses
                break;
            }
            else
            {
                printf("You should load buses file and passengers before you assign them.\n");  /* if the buses loading info and loading
            passengers info is not done*/
                break;
            }

        }

        case 4:
        {
            printf("Your choice is ---> <%d>\n", choice);
            if(!check_buses_load_is_done)                /// if the buses loading info from the file does not exist
            {
                printf("Sorry, But you must load the buses file to search for a bus.\n");
                break;
            }

            int bus_number = get_user_bus_number();    /// get user number to print info about this bus
            struct bus_node* specific_bus = get_specific_bus(bus_number, buses_linked_list);   /// get a bus that the user want to print info about

            if(specific_bus == NULL)    /// if the specific bus does not exist
            {
                printf("Sorry, but this bus does not exist.\n");
                break;
            }
            printf("Your Bus number is -->%d\n", bus_number);  /// print the user bus number
            print_bus_info(specific_bus);                      /// print the bus info
            break;
        }

        case 5:
        {
            printf("Your choice is ---> <%d>\n\n", choice);

            if(passengers_linked_list ->Next == NULL)   /// if the passengers linked list is empty
            {
                printf("Sorry, You should load the passengers file first to store data.\n\n");
                break;
            }
            if(!check_assignment_is_done)        /// if we did not assign the passengers to buses
            {
                printf("PS : All the passengers are unmatched passengers because you did not yet assign them to buses.\n\n");
            }
            print_unmatched_list(passengers_linked_list);   /// printing the unmatched passengers linked list
            break;
        }

        case 6:
        {
            if(!check_assignment_is_done)  /// if we did not do the assignment
            {
                printf("You Should Assign Passengers to the buses first.\n");
                break;                    /// out of case 6
            }

            printf("Your choice is ---> <%d>\n", choice);
            add_user_passenger(passengers_linked_list);       /// add a passenger to the passengers linked list(firstly unmatched passengers linked list)
            break;
        }

        case 7:
        {
            printf("Your choice is ---> <%d>\n", choice);
            int is_found = 0;                            /// flag to check if it is found

            long passenger_id = get_passenger_id();      /// get the passenger id from the user

            if(passengers_linked_list ->Next == NULL)    /// if the passengers is empty
            {
                is_found = 1;
                printf("\nSorry, This Passenger does not exist.\n");
                break;
            }

            int find_in_unmatched = 0;                   /// to check if the passenger in the unmatched passengers list
            if(!is_found)
            {
                if(passengers_linked_list ->Next != NULL)        /// if the passengers is empty
                {
                    if(check_in_unmatched_passengers(passengers_linked_list, passenger_id))      /// if this passenger is exist in unmatched passengers list
                    {
                        find_in_unmatched = 1;                   /// flag of finding this passenger in unmatched list is 1
                        Delet(passenger_id, passengers_linked_list); /// Delete this passenger from unmatched passengers list
                        printf("\n");

                        printf("\t\t---> Deleting A passenger with id = %ld form the passengers Unmatched linked list.\n", passenger_id);
                        break;
                    }

                }
            }

            if(!find_in_unmatched)   /// if it's not found in the passengers unmatched list and the list is not empty
            {
                struct bus_node* bus = check_in_assignment_buses(buses_linked_list, passenger_id);/// checking if this passenger in assignment buses
                if(bus != NULL)   /// if this bus exist
                {
                    DeletPassengerFromBus(passenger_id, bus ->NextPassenger);  /// Deleting this passenger from this bus by depending on id
                    printf("\n");
                    printf("\n\t\t---> Deleting A passenger with id = %ld from the Bus number %d.\n", passenger_id, bus ->bus_number);
                    break;
                }
            }
            printf("Sorry, but this passenger does not exist.\n");   /// if the passenger does not exist in any where
            break;
        }

        case 8:
        {
            printf("Your choice is ---> <%d>\n\n", choice);
            if(!check_buses_load_is_done)   /// if we want to delete an empty buses linked list, we cannot
            {
                printf("Sorry, you should load the buses file.\n");
                break;
            }

            int bus_number = get_bus_number();   /// get bus number to delete it and assign it's passengers to the unmatched passengers linked list

            if(check_buses_load_is_done)       /// if loading the buses is done
            {
                if(is_found_bus(buses_linked_list, bus_number))  /// if we found this bus
                {
                    DeletBus(bus_number, buses_linked_list, passengers_linked_list);  /// we should Delete this bus and assign it's passengers
                    printf("\n");
                    printf("\t\t--->Deleting a bus with number %d, and added it's passengers to the Unmatched passengers if there is.\n\n", bus_number);
                    break;
                }
                else
                {
                    printf("Sorry, This bus does not exist.\n");  /// if this bus does not exist
                }
            }

            break;
        }

        case 9:
        {
            exit(0);   /// exit the program
        }

        }
    }



    printf("Thanks For Using My Program!, See you on Other Programs.\n");  /// printing many thanks for visiting my program
    return 0;

}



struct bus_node* MakeEmptyBus(struct bus_node* buses_linked_list)  /// Function body
{
    if(buses_linked_list != NULL)   /// if this bus is already exist
    {
        printf("This Linked List is Already Exist!\n");
        return NULL;
    }
    buses_linked_list = (struct bus_node *)malloc(sizeof(struct bus_node));  /// otherwise, we will make a header for this buses linked list

    if(buses_linked_list == NULL)      /// if this location in memory is already full
    {
        printf("This Site of Memory is Full, Please try again.\n");
    }

    buses_linked_list ->Next = NULL;   /// Next to this head is null
    return buses_linked_list;     /// returning this head
}

void insert_bus(struct bus_node* buses_linked_list, int bus_number_inserted, long bus_date_inserted, char bus_departure_time_inserted[], char bus_from_inserted[],
                char bus_to_inserted[], double bus_price_of_ticket_inserted, int bus_capacity_inserted)  /// Function body
{

    if(buses_linked_list == NULL)    /// if this linked list does not exist
    {
        printf("This Linked List is Empty.\n");
        return;
    }
    struct bus_node* new_bus = (struct bus_node*)malloc(sizeof(struct bus_node));  /// make a pointer to first bus
    struct passenger_node* first_node = MakeEmptyPassenger(NULL);    /// make a header for the first passenger linked list


    while(1)
    {
        if(buses_linked_list ->Next == NULL)   /// if we reached the end of the buses linked list
        {
            new_bus ->bus_number = bus_number_inserted;                       /// Adding this bus (node) and it's components to the buses linked list
            new_bus ->bus_date = bus_date_inserted;
            strcpy(new_bus ->bus_departure_time, bus_departure_time_inserted);
            strcpy(new_bus ->bus_from, bus_from_inserted);
            strcpy(new_bus ->bus_to, bus_to_inserted);
            new_bus ->bus_price_of_ticket = bus_price_of_ticket_inserted;
            new_bus ->bus_capacity = bus_capacity_inserted;

            new_bus ->Next = buses_linked_list ->Next;
            buses_linked_list ->Next = new_bus;
            new_bus ->NextPassenger = first_node;       /// make a header of a passengers linked list for each bus added

            return;
        }
        buses_linked_list = buses_linked_list ->Next;     /// iterate for all buses until the end of the buses linked list
    }
}



void insert_passenger(struct passenger_node* passengers_linked_list, int passenger_number_inserted, long passenger_date_inserted, char passenger_departure_time_inserted[], char passenger_from_inserted[],
                      char passenger_to_inserted[])
{

    struct passenger_node* new_passenger = (struct passenger_node*)malloc(sizeof(struct passenger_node));  /// make a passenger node by malloc function

    while(1)
    {
        if(passengers_linked_list ->Next == NULL)   /// if we reach the end of the passengers list
        {
            new_passenger ->traveler_id = passenger_number_inserted;     /// Adding a passenger (node) and it's components
            new_passenger ->travelling_date = passenger_date_inserted;
            strcpy(new_passenger ->travelling_time, passenger_departure_time_inserted);
            strcpy(new_passenger ->travelling_from, passenger_from_inserted);
            strcpy(new_passenger ->travelling_to, passenger_to_inserted);

            new_passenger ->Next = passengers_linked_list ->Next;
            passengers_linked_list ->Next = new_passenger;
            passengers_linked_list ->NextPassengerInBus = NULL;     /// make the next for each passenger NULL(to add them into buses)
            return;
        }
        passengers_linked_list = passengers_linked_list ->Next;   /// iterate for all passengers until we reach the end of the passengers list
    }
}


struct passenger_node* MakeEmptyPassenger(struct passenger_node* passengers_linked_list)  /// function body
{
    if(passengers_linked_list != NULL)
    {
        printf("This Linked List is Already Exist!\n");
        return NULL;
    }
    passengers_linked_list = (struct passenger_node*)malloc(sizeof(struct passenger_node));  /// make a header (first node) of the passengers list

    if(passengers_linked_list == NULL)    /// if the memory is full at this site
    {
        printf("This Site of Memory is Full, Please try again.\n");
    }

    passengers_linked_list ->Next = NULL;       /// make a null for the Next of the header
    return passengers_linked_list;              /// return the head of passengers list
}


int get_choice()            /// function body
{
    char choice[MAXIMUM_CHARACTERS];       /// Define a string to get input from the user and if it's specified the conditions, we convert it to number by atoi function

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

        if(correct_choice > 0 && correct_choice < 10)  /// if the number is between 1 and 9
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

void print_the_list()  /// print the available choices for the user
{
    printf("You have these Choices:");
    printf("\n");
    printf("1. Load the bus information file.\n");
    printf("2. Load the passenger information file.\n");
    printf("3. Assign passengers and print assignment information of all buses.\n");
    printf("4. Print a specific bus information along with its passengers information (IDs).\n");
    printf("5. Print unmatched passengers.\n");
    printf("6. Add new passenger.\n");
    printf("7. Delete passenger.\n");
    printf("8. Delete bus number.\n");
    printf("9. Exit.\n");
}

struct bus_node* load_bus_file_info(struct bus_node* buses_linked_list)    /// processing of open a file and read it's contents
{

    FILE *bus_file = fopen("busses.txt", "r");      /// open a file it's name is busses,txt, for reading

    if(bus_file == NULL)       /// if the file does not exist
    {
        return NULL;
    }


    char line_bus[MAXIMUM_LETTERS];   /// define a array of char and it's size is 500 to put the line in
    char *last_line_bus = fgets(line_bus, MAXIMUM_LETTERS, bus_file);  /// check the nullity
    char words_bus[MAXIMUM_WORDS][MAXIMUM_LETTERS];  /// define an array of string to put data in while reading every line


    if(buses_linked_list == NULL)   /// if this buses list is not exist
    {
        printf("This Buses Linked List is Already Exist.\n");
    }

    while(last_line_bus != NULL)   /// iterate for the last line
    {
        int i = 0;
        char *last_word_bus = strtok(line_bus, "#");  /// take the first word of each line

        while(last_word_bus != NULL)  /// while there is a word in this line
        {
            strcpy(words_bus[i], last_word_bus);  /// copying the data to this array of strings
            last_word_bus = strtok(NULL, "#");   /// divide this line depends on #
            i++;
        }
        int bus_number_from_file = atoi(words_bus[0]); /// Reading data of this line and store it in each variable

        int bus_date_from_file = atoi(words_bus[1]);

        char bus_departure_time_from_file[MAXIMUM_LETTERS];
        strcpy(bus_departure_time_from_file, words_bus[2]);

        char bus_from_from_file[MAXIMUM_LETTERS];
        strcpy(bus_from_from_file, words_bus[3]);

        char bus_to_from_file[MAXIMUM_LETTERS];
        strcpy(bus_to_from_file, words_bus[4]);

        double bus_price_of_ticket_from_file = atoi(words_bus[5]);
        int bus_capacity_from_file = atoi(words_bus[6]);



        insert_bus(buses_linked_list, bus_number_from_file, bus_date_from_file, bus_departure_time_from_file, bus_from_from_file, bus_to_from_file, bus_price_of_ticket_from_file
                   , bus_capacity_from_file);  /// insert this bus and it's info

        last_line_bus = fgets(line_bus, MAXIMUM_LETTERS, bus_file);   /// reading until the last line
    }

    printf("\n");

    return buses_linked_list;   /// return the buses list after filling it
}

void print_buses_info(struct bus_node* buses_linked_list)  /// function body
{
    printf("These Information was found in the Buses File:\n\n");
    buses_linked_list = buses_linked_list ->Next;  /// pointer to the header

    while(buses_linked_list != NULL)  /// iterate of all buses to print it's info that we read from the file
    {
        printf("%d#%ld#%s#%s#%s#%0.0f#%d\n", buses_linked_list ->bus_number, buses_linked_list ->bus_date, buses_linked_list ->bus_departure_time
               , buses_linked_list ->bus_from, buses_linked_list ->bus_to, buses_linked_list ->bus_price_of_ticket, buses_linked_list ->bus_capacity);

        buses_linked_list = buses_linked_list ->Next;  /// pointer to next bus
    }
}


void print_dashes()  /// function body
{
    printf("\n\n-------------------------------------------------------------------------------------------------------------------\n\n");  /// printing dashes
}


struct passenger_node* load_passenger_file_info(struct passenger_node* passengers_linked_list)  /// function body
{
    if(passengers_linked_list ->Next != NULL)  /// if this passengers list is not empty
    {
        return passengers_linked_list;  /// return it as it self
    }

    FILE *passenger_file = fopen("passengers.txt", "r");  /// open a file and it's name is passengers for reading
    if(passenger_file == NULL)   /// if this file does not exist
    {
        printf("This File (passengers.txt) Does not exist.\n");
        return NULL;   /// return NULL for not existing
    }

    char line_passenger[MAXIMUM_LETTERS]; /// As Above
    char *last_line_passenger = fgets(line_passenger, MAXIMUM_LETTERS, passenger_file);
    char words_passenger[MAXIMUM_WORDS][MAXIMUM_LETTERS];


    if(passengers_linked_list == NULL)   /// if this passengers list does not exist
    {
        printf("This Passengers Linked List is Already Exist.\n");
    }


    while(last_line_passenger != NULL) /// As Above
    {
        int i = 0;
        char *last_word_passenger = strtok(line_passenger, "#");

        while(last_word_passenger != NULL)
        {
            strcpy(words_passenger[i], last_word_passenger);
            last_word_passenger = strtok(NULL, "#");
            i++;
        }


        int passenger_number_from_file = atoi(words_passenger[0]);

        int passenger_date_from_file = atoi(words_passenger[1]);

        char passenger_departure_time_from_file[MAXIMUM_LETTERS];
        strcpy(passenger_departure_time_from_file, words_passenger[2]);

        char passenger_from_from_file[MAXIMUM_LETTERS];
        strcpy(passenger_from_from_file, words_passenger[3]);

        char passenger_to_from_file[MAXIMUM_LETTERS] = "";

        int length = strlen(words_passenger[4]);
        int initial = 0;

        if(words_passenger[4][length -1] == '\n')  /// trim this string
        {
            while(initial < length -1)
            {
                passenger_to_from_file[initial] = words_passenger[4][initial];
                initial++;
            }

        }

        else
        {
            while(initial < length)  /// reading this string a char char
            {
                passenger_to_from_file[initial] = words_passenger[4][initial];
                initial++;
            }
        }


        insert_passenger(passengers_linked_list, passenger_number_from_file, passenger_date_from_file, passenger_departure_time_from_file,
                         passenger_from_from_file, passenger_to_from_file);
        /// insert this passenger

        last_line_passenger = fgets(line_passenger, MAXIMUM_LETTERS, passenger_file);

    }

    printf("\n");
    fclose(passenger_file);
    return passengers_linked_list;  /// return this passengers list after filling it
}


void print_passengers_info(struct passenger_node* passengers_linkd_list)  /// function body
{

    if(passengers_linkd_list == NULL)  /// if this passengers list does not exist
    {
        printf("This Passengers File is Empty, Please fill it and try again!\n");
        return;   /// get out the function
    }

    printf("\n\n");
    passengers_linkd_list = passengers_linkd_list ->Next;  /// pointer of the first passenger (header)

    while(passengers_linkd_list != NULL)  /// iterate until the last passenger
    {
        printf("%ld#%ld#%s#%s#%s\n", passengers_linkd_list ->traveler_id, passengers_linkd_list ->travelling_date, passengers_linkd_list ->travelling_time
               , passengers_linkd_list ->travelling_from, passengers_linkd_list ->travelling_to);  /// printing some info

        passengers_linkd_list = passengers_linkd_list ->Next;   /// pointer to next passenger
    }
}

int check_bus_file_is_empty(struct bus_node* buses_linkd_list)  /// function body
{
    return buses_linkd_list ->Next == NULL ? 1 : 0;  /// check if this file is empty after made the list
}

int check_passenger_file_is_empty(struct passenger_node* passengers_linked_list)  /// function body

{
    return passengers_linked_list ->Next == NULL ? 1 : 0;  /// check if the passengers file is empty
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

void assign_passengers_to_the_buses(struct bus_node* buses, struct passenger_node* passengers)  /// function body
{
    if(buses ->Next == NULL)   /// to check if this buses is empty
    {
        printf("Empty Buses Linked List.\n");
        return;   /// get out of this function
    }

    if(passengers ->Next == NULL)  /// to check if this passengers list is empty
    {
        printf("Empty Passengers Linked List.\n");
        return;
    }


    struct bus_node* current_bus = buses ->Next;  /// define a pointer of the first bus
    struct passenger_node* first_passenger = passengers;   /// define a pointer of the first passenger
    struct bus_node* first_bus = buses ->Next;            /// define a pointer of the first bus
    struct passenger_node* current_passenger = passengers ->Next;   /// define a pointer of the first passenger

    while(current_passenger != NULL)   /// iterate until the last passenger
    {

        int date = current_passenger ->travelling_date;  /// Assign data to variables

        char time[MAXIMUM_LETTERS];
        strcpy(time, current_passenger ->travelling_time);

        char from[MAXIMUM_LETTERS];
        strcpy(from, current_passenger ->travelling_from);

        char to[MAXIMUM_LETTERS];
        strcpy(to, current_passenger ->travelling_to);


        while(current_bus != NULL)  /// iterate until last bus
        {
            if(current_bus ->bus_capacity > 0)  /// if the capacity is larger than 0
            {
                if(current_bus ->bus_date == date && strcmp(current_bus ->bus_departure_time, time) == 0 &&
                        strcmp(current_bus ->bus_from, from) == 0 && strcmp(current_bus ->bus_to, to) == 0)  /// if these conditions are saticfied
                {
                    Delet(current_passenger ->traveler_id, first_passenger);  /// Delete this passenger from the unmatched passengers
                    insert_passenger_to_bus(current_bus, current_passenger);  /// insert him to the this bus
                    break;    /// break after insert this passenger in this bus
                }
            }
            current_bus = current_bus ->Next;  /// iterate of all buses
        }

        current_bus = first_bus;  /// pointing to the first bus
        current_passenger = current_passenger ->Next;   /// iterate of all passengers
    }
    print_assignment_passengers(first_bus);  /// printing all info about these buses after assigned passengers to them
}

void insert_passenger_to_bus(struct bus_node* bus, struct passenger_node* passenger)  /// function body
{

    struct passenger_node* first_passenger = bus ->NextPassenger;  /// pointer to the first passenger in this bus
    struct passenger_node *new_passenger = (struct passenger_node*)malloc(sizeof(struct passenger_node));  /// make a passenger

    while(1)
    {
        if(first_passenger ->NextPassengerInBus == NULL)  /// iterate until we reached the last passenger
        {
            new_passenger ->traveler_id = passenger ->traveler_id;  /// Assign these data to variables
            new_passenger ->travelling_date = passenger ->travelling_date;
            strcpy(new_passenger ->travelling_time, passenger ->travelling_time);
            strcpy(new_passenger ->travelling_from, passenger ->travelling_from);
            strcpy(new_passenger ->travelling_to, passenger ->travelling_to);

            new_passenger ->NextPassengerInBus = first_passenger ->NextPassengerInBus;  /// adding this passenger to this bus
            first_passenger ->NextPassengerInBus = new_passenger;


            return;
        }
        first_passenger = first_passenger ->NextPassengerInBus;  /// iterate of all passengers
    }
}

void print_assignment_passengers(struct bus_node* buses_with_passengers)  /// function body
{

    struct bus_node* another_buses = buses_with_passengers;  /// pointer of the first bus(head)

    printf("\n\nThese are Buses after assigned Passengers :\n\n");  /// printing some info
    printf("\t\tNumber               Date            Departure Time              Departure From                  Departure To               Price of Ticket            Capacity\n\n");


    while(buses_with_passengers != NULL)  /// iterate of all buses to print their info using tabs and spaces

    {
        printf("\t\t   %d\t\t   %ld               %s            \t   %s\t\t\t   %s\t\t\t %0.0f\t\t\t  %d", buses_with_passengers ->bus_number, buses_with_passengers ->bus_date, buses_with_passengers ->bus_departure_time,
               buses_with_passengers ->bus_from,buses_with_passengers ->bus_to, buses_with_passengers ->bus_price_of_ticket, buses_with_passengers ->bus_capacity);


        printf("\n");
        buses_with_passengers = buses_with_passengers ->Next;  /// next bus in this list
    }

    printf("\n\n\n");
    printf("Passengers of their Buses: \n\n");

    while(another_buses != NULL)  /// while this pointer does not NULL

    {
        int is_empty = 0;    /// if this flag become 1, then this bus does has any passenger
        printf("For the Bus #%d: \n\n", another_buses ->bus_number);

        struct passenger_node* current_passenger = another_buses ->NextPassenger ->NextPassengerInBus;

        while(current_passenger  != NULL)  /// if this bus has a passengers
        {
            printf("\t\t---> Passenger ID with this Bus = %ld\n", current_passenger ->traveler_id);
            current_passenger = current_passenger ->NextPassengerInBus;   /// iterate of all passengers in this bus (if exists)
            is_empty = 1;   /// flag become 1, this bus is not empty
        }

        if(!is_empty)   /// if this bus is empty
        {
            printf("\t\t--->Sorry, but this Bus is Empty from the Passengers.");
        }

        printf("\n\n");
        another_buses = another_buses ->Next;  /// iterate of all buses
    }
}

struct passenger_node* FindPrevious(int X, struct passenger_node* L)  /// function body
{
    struct passenger_node* P = L;
    while(P->Next != NULL && P->Next->traveler_id != X)  /// iterate until we find the previous of a given passenger and return it
        P = P->Next;
    return P;    /// return the previous of a given passenger
}

int IsLast(struct passenger_node* this_passenger)  /// function body
{
    return this_passenger ->Next == NULL ? 1 : 0; /// if this passenger is the last passenger
}

void Delet(int X, struct passenger_node* L)  /// function body
{
    struct passenger_node* P;
    struct  passenger_node* temp;
    P = FindPrevious(X, L);   /// finding the previous of the passenger we want to delete him

    if(!IsLast(P))         /// if this passenger is not the last one
    {
        temp = P->Next;
        P->Next = temp->Next;     /// next for previous pointing for the next of a deleted passenger
        free(temp);             /// free from memory
    }
}

int get_user_bus_number()  /// function body
{
    char bus_number[MAXIMUM_CHARACTERS];
    printf("\nPlease enter the number of the bus you want to get it's passengers info: ");
    scanf("%s", bus_number);  /// reading the input of the user as a string

    while(1)
    {
        if(!is_number(bus_number))  /// while this input is string
        {
            printf("Please enter a number not a string or a letter: ");
            scanf("%s", bus_number);  /// reading it from the user again
            continue;
        }
        break;    /// if the user input a number
    }

    int valid_number = atoi(bus_number);  /// convert it to number
    return valid_number;  /// return the number
}

struct bus_node* get_specific_bus(int bus_number, struct bus_node* buses_linked_list)  /// function body
{
    buses_linked_list = buses_linked_list ->Next;  /// pointer to the first bus after the header

    while(buses_linked_list != NULL)              /// iterate until the last bus
    {
        if(buses_linked_list ->bus_number == bus_number)   /// if we found the bus
        {
            return buses_linked_list;    /// return it
        }

        buses_linked_list = buses_linked_list ->Next;  /// otherwise, we iterate
    }
    return NULL;   /// if this bus does not exist
}


void print_bus_info(struct bus_node* bus)  /// function body
{
    if(bus == NULL)  /// if this bus does not exist
    {
        return;
    }

    printf("\nSome information about this bus:\n\n");
    printf("\t\tNumber\t\tDate\t\tDeparture Time\t\tDeparture From\t\tDeparture To\t\tPrice of Ticket\t\tCapacity\n\n");
    printf("\t\t  %d\t       %ld\t\t    %s\t\t    %s\t\t   %s\t\t      %0.0f\t\t   %d", bus ->bus_number, bus ->bus_date, bus ->bus_departure_time, bus ->bus_from
           ,bus ->bus_to, bus ->bus_price_of_ticket, bus ->bus_capacity);

    printf("\n\n");

    struct passenger_node* current_passenger = bus ->NextPassenger ->NextPassengerInBus;  /// A pointer to the first passenger in this bus

    if(current_passenger == NULL)  /// if the first passenger is already does not exist
    {
        printf("\nSorry, No Passengers in this bus.\n");
        return;
    }
    printf("\n\nThose Passengers in this bus: \n\n");

    while(current_passenger != NULL)   /// iterate of all passengers
    {
        printf("\t      --->Passenger with ID = %ld\n", current_passenger ->traveler_id);  /// printing his info
        current_passenger = current_passenger ->NextPassengerInBus;
    }
}

void print_unmatched_list(struct passenger_node* passengers_linked_list)  /// function body
{
    struct passenger_node* current_passenger = passengers_linked_list ->Next;  /// a pointer named current passenger that points to first passenger
    printf("\nSome information about those Unmatched Passengers:\n\n");
    printf("\t\tID\t\tDate\t\tDeparture Time\t\tDeparture From\t\t Departure To\n\n");  /// printing types for info

    while(current_passenger != NULL)  /// iterate of all passengers to print their info
    {
        printf("\t      %ld\t\t%ld\t\t   %s\t\t   %s\t\t   %s\n", current_passenger ->traveler_id, current_passenger ->travelling_date, current_passenger ->travelling_time,
               current_passenger ->travelling_from, current_passenger ->travelling_to);
        current_passenger = current_passenger ->Next;
    }
}


void add_user_passenger(struct passenger_node* passengers_linked_list) /// function body
{
    char semi_id[MAXIMUM_LETTERS];  /// reading the input id from the user as a string
    printf("Please enter an ID for this Passenger : ");
    scanf("%s", semi_id);

    while(1)
    {
        if(!is_number(semi_id))  /// while the conditions does not specified
        {
            printf("Please enter a number not a string : ");
            scanf("%s", semi_id);  /// reading id from the usr
            continue;
        }

        else
            break;
    }
    long id = atoi(semi_id);  /// if the conditions of this id are specified


    char semi_date[MAXIMUM_LETTERS];  /// Same Above but here for date
    printf("Please enter the departure date for this Passenger as follows --> DAY0MONTHYEAR : ");
    scanf("%s", semi_date);

    while(1)
    {
        if(!is_number(semi_date))
        {
            printf("Please enter a number not a string : ");
            scanf("%s", semi_date);
            continue;
        }
        else

            break;
    }

    long date = atoi(semi_date);  /// same above


    char time[MAXIMUM_LETTERS];  ///
    printf("Please enter the departure time for this Passenger as follows --> HOURS:MINUTES : ");
    scanf("%s", time);  /// reading the time from the user

    char from[MAXIMUM_LETTERS];
    printf("Please enter the country where this Passenger is travel from : ");
    scanf("%s", from);   /// reading the departure from from the user

    char to[MAXIMUM_LETTERS];
    printf("Please enter the destination for this Passenger :");
    scanf("%s", to);     /// reading the departure to from the user

    insert_passenger(passengers_linked_list, id, date, time, from, to);  /// insert this passenger to the passengers linked list
    printf("\n\n\t\t---> Adding a Passenger with ID = %ld to passengers linked list.\n", id);  /// printing sentence to understand the user
}


int check_in_unmatched_passengers(struct passenger_node* passengers_linked_list, long passenger_id)  /// function body
{
    struct passenger_node* first_node = passengers_linked_list;  /// first node that points to the head of this passengers list

    while(first_node != NULL)         /// iterate of the passengers until we find this passenger whose id is traveler id
    {
        if(first_node ->traveler_id == passenger_id)
        {
            return 1;          /// return 1 if we find him
        }
        first_node = first_node ->Next;
    }

    return 0;      /// return 0 if we did not find him
}

long get_passenger_id()  /// Function body
{
    char semi_passenger_id[MAXIMUM_LETTERS];
    printf("Please enter the id of the passenger you want to delete him: ");
    scanf("%s", semi_passenger_id);  /// reading the input from the user as a string and convert it if it's specified the conditions

    while(1)
    {
        if(!is_number(semi_passenger_id))  /// while the input is not a number
        {
            printf("Please enter the id  as a number not a string: ");
            scanf("%s", semi_passenger_id);
        }

        else
            break;
    }
    return atoi(semi_passenger_id);  /// if the conditions are specified about this number
}

struct bus_node* check_in_assignment_buses(struct bus_node* buses, int passenger_id)  ///Function body
{
    while(buses != NULL)
    {
        struct passenger_node* current_passenger = buses ->NextPassenger;
        while(current_passenger != NULL)    /// iterate of all passengers until we reach end
        {
            if(current_passenger ->traveler_id == passenger_id)
            {
                return buses;           /// if we found the passenger in this bus
            }

            current_passenger = current_passenger ->NextPassengerInBus;
        }

        buses = buses ->Next;
    }
    return NULL;   /// return null if this passenger does not in assignment buses
}

void DeletPassengerFromBus(int passenger_id, struct passenger_node* passengers) /// function body
{

    struct passenger_node* P;
    struct  passenger_node* temp;
    P = FindPreviousInBus(passenger_id, passengers);  /// P = previous for the given passenger

    if(!IsLastInBus(P))          /// if this passenger is not the last one in this bus
    {
        temp = P->NextPassengerInBus;
        P->NextPassengerInBus = temp->NextPassengerInBus;
        free(temp);
    }
}

int IsLastInBus(struct passenger_node* this_passenger)  /// function body
{
    return this_passenger ->NextPassengerInBus == NULL ? 1 : 0;  /// if this passenger is the last passenger in a specific bus
}


struct passenger_node* FindPreviousInBus(int X, struct passenger_node* L)   /// function body
{
    struct passenger_node* P = L;
    while(P ->NextPassengerInBus != NULL && P->NextPassengerInBus->traveler_id != X)  /// finding the previous passenger of a list in a bus
        P = P->NextPassengerInBus;
    return P;         /// return the pointer to previous
}

int get_bus_number()  /// function body
{
    char semi_bus_number[MAXIMUM_LETTERS];   /// reading the input as a string and convert it to number if the conditions are satecfied
    printf("Please enter the number of the bus you want to delete it: ");
    scanf("%s", semi_bus_number);

    while(1)
    {
        if(!is_number(semi_bus_number))  /// while the input is not a number
        {
            printf("Please enter the bus number as a number not a string: ");
            scanf("%s", semi_bus_number);
        }

        else
            break;
    }
    return atoi(semi_bus_number);          /// return the number after convert it from string
}


int is_found_bus(struct bus_node* buses, int bus_number)  /// Function body to check if the bus is exist or not
{
    while(buses != NULL)
    {
        if(buses ->bus_number == bus_number)
        {
            return 1;             /// return 1 if the bus is found
        }
        buses = buses ->Next;
    }
    return 0;                   /// return 0 if the bus is not found
}

void DeletBus(int bus_number, struct bus_node* buses, struct passenger_node* unmatched_passengers)  /// function body to delete a bus
{
    if(buses == NULL) /// if the bus does not exist
    {
        printf("This Bus does not exist.\n");
        return;
    }

    struct bus_node* P;
    struct  bus_node* temp;
    P = FindPreviousBus(bus_number, buses);   /// finding the previous of a given bus

    struct passenger_node* current_passenger = P ->Next ->NextPassenger ->NextPassengerInBus; /// current passenger  is a pointer to the first passenger in this bus(not the header)

    printf("\n");
    while(current_passenger != NULL)         /// while we did not reach the end of this list
    {
        insert_passenger(unmatched_passengers, current_passenger ->traveler_id, current_passenger ->travelling_date, current_passenger ->travelling_time
                         , current_passenger ->travelling_from, current_passenger ->travelling_to);

        printf("Adding a passenger with id = %ld to Unmatched passengers.\n", current_passenger ->traveler_id);

        current_passenger = current_passenger ->NextPassengerInBus;
    }
    if(!IsLastBus(P))    /// to check if this bus is not the last bus in the list
    {
        temp = P->Next;      /// temp is a pointer to the passenger you want to delete
        P->Next = temp->Next; /// the previous passenger is pointing to the next of passenger you want to delete it
        free(temp);  /// free this passenger from the memory
    }
}

struct bus_node* FindPreviousBus(int X, struct bus_node* L) /// function body to find the previous of the given bus
{
    struct bus_node* P = L;
    while(P->Next != NULL && P->Next->bus_number != X)
        P = P->Next;
    return P;   /// return a the previous bus
}

int IsLastBus(struct bus_node* bus)  /// function body to check if this bus is the last bus
{
    return bus ->Next == NULL ? 1 : 0; /// return 1 for NULL, 0 for not NULL
}






