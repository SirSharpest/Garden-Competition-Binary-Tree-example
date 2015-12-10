
/* 
 * File:   competition.h
 * Author: nathan
 *
 * Created on 01 December 2015, 13:17
 */


//define the max number of characters allowed
//in the name of the entrant 
#define MAX_INPUT_LENGTH 79
#define INCHES_IN_FOOT 12

/*
 * Structure for a competitor
 * and their entries for the competition 
 *
 */
typedef struct competitor_data{
    
    //Everything set to be max of the input lengths specified 
    //in design docs
    char name[MAX_INPUT_LENGTH];
    char postal_address[MAX_INPUT_LENGTH];
    char phone_number[MAX_INPUT_LENGTH];
    
    //use of unsigned short to save memory over use of int
    //and not signed as would never be < 0 
    unsigned short competitor_number; 
    
    //All lengths are as inches
    float cucumber_length; 
    float carrot_length; 
    float runnerbean_length; 

    //Pointers to children nodes
    struct competitor_data * left_child; 
    struct competitor_data * right_child; 
    
    
} competitor_node;

typedef competitor_node * competitor_node_ptr; 


/**
 * This function creates a BT using the information provided in the file given
 * @param competition_filename is the name of the file to read
 * @param last_update is the time the file was last updated, this is set in the function 
 * @param name_of_competition is the name of the competition and is set in the function 
 * @return A root node which contains all the nodes as children i.e. the entire tree can be found using it
 */
competitor_node_ptr create_competitor_binary_tree(char * competition_filename,
        char * last_update, char * name_of_competition);

/**
 * Prints the table to the terminal 
 * @param competitor_root_node
 * @param last_update
 * @param name_of_competition
 */
void print_competitor_table(competitor_node_ptr competitor_root_node, 
        char * last_update, char* name_of_competition); 

/**
 * Prints a single node's informaiton 
 * @param competitor_root_node
 */
void print_a_node(competitor_node_ptr competitor_root_node);

/**
 * Compare two nodes and return a value indicating which is larger of the two
 * @param node_1
 * @param node_2
 * @return 0 if nodes are equal, -number if node_2 is greater and +number if node_1 is greater
 */
int compare_entries(competitor_node_ptr node_1, competitor_node_ptr node_2);

/**
 * Calculates the total inches of fruit/veg 
 * @param node_to_calc
 * @return a float of the total size of all the competitors fruit/veg
 */
float calculate_total_inches(competitor_node_ptr node_to_calc);