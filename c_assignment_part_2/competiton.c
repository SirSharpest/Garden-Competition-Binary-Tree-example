#include <stdio.h>
#include <stdlib.h>
#include "competition.h"


/**
 * Using the file given, this will read all of the information for one of the competitors 
 * @param competitor_table_file
 * @return a node struct with all member variables filled in
 */
competitor_node_ptr read_team_node(FILE * competitor_table_file) {

    int scan_status;
    competitor_node *temp_competitor_node;

    float temp_inches;
    int temp_feet;

    static int competitor_number = 1;

    //Request more memory for new node
    temp_competitor_node = calloc(1, sizeof (competitor_node));
    
    fscanf(competitor_table_file,"%[^\n]\n",temp_competitor_node->name);

    //get postal address
    fscanf(competitor_table_file,"%[^\n]\n",temp_competitor_node->postal_address);



    //get phone number
    fscanf(competitor_table_file,"%[^\n]\n",temp_competitor_node->phone_number);

    //Grab the inches and feet from the text file and 
    //Store locally so that they can be converted into inches 
    fscanf(competitor_table_file, "%d%f%*[\n]", &temp_feet, &temp_inches);
    //Storing feet as inches in the Struct 
    temp_competitor_node->cucumber_length = ((temp_feet * INCHES_IN_FOOT) + temp_inches);


    //Grab the inches and feet from the text file and 
    //Store locally so that they can be converted into inches 
    fscanf(competitor_table_file, "%d%f%*[\n]", &temp_feet, &temp_inches);
    //Storing feet as inches in the Struct 
    temp_competitor_node->carrot_length = ((temp_feet * INCHES_IN_FOOT) + temp_inches);



    //Grab the inches and feet from the text file and 
    //Store locally so that they can be converted into inches 
    fscanf(competitor_table_file, "%d%f%*[\n]", &temp_feet, &temp_inches);
    
    //Storing feet as inches in the Struct 
    temp_competitor_node->runnerbean_length = ((temp_feet * INCHES_IN_FOOT) + temp_inches);


    //set competitor number
    temp_competitor_node->competitor_number = competitor_number;


    //Debug output to check reading has happened correctly
#ifdef DEBUG
    printf("***** \n");
    printf("%s", temp_competitor_node->name);
    printf("%s", temp_competitor_node->postal_address);
    printf("%s", temp_competitor_node->phone_number);
    printf("%f\n%f\n%f\n", temp_competitor_node->cucumber_length,
            temp_competitor_node->carrot_length,
            temp_competitor_node->runnerbean_length);

    printf("***** \n \n");
#endif 


    //check for errors
    if (scan_status == EOF) {
        printf("Problems have happened while reading from file\n");
        return NULL;
    } else {
        competitor_number++;
        return temp_competitor_node;
    }

}




/**
 * Finds the location of where a node should go in the tree and then places it there 
 * @param current
 * @param new
 */
void add_competitor_node(competitor_node_ptr current, competitor_node_ptr new) {

    //If new node is greater than or equal to current 
    if (compare_entries(new, current) >= 0) {
        if (current->right_child == NULL) {
            current->right_child = new;
        } else {
            add_competitor_node(current->right_child, new);
        }
    } else {

        if (current->left_child == NULL) {
            current->left_child = new;
        } else {
            add_competitor_node(current->left_child, new);
        }

    }



}

/**
 * Compares two nodes and decides which is larger
 * @param node_1
 * @param node_2
 * @return 
 */
int compare_entries(competitor_node_ptr node_1, competitor_node_ptr node_2) {

    float total_1, total_2;

    total_1 = calculate_total_inches(node_1);

    total_2 = calculate_total_inches(node_2);
    //if node_1 is larger then it will be > 0
    //if node_1 is less than it i will be < 0
    return total_1 - total_2;


}

float calculate_total_inches(competitor_node_ptr node_to_calc){
    
    return node_to_calc->cucumber_length + node_to_calc->carrot_length +
            node_to_calc->runnerbean_length;

}


/**
 * Creates a binary tree by using a data file and scanning the contents 
 * @param competition_filename
 * @param last_update
 * @param name_of_competition
 * @return 
 */
competitor_node_ptr create_competitor_binary_tree(char * competition_filename,
        char * last_update, char* name_of_competition) {


    FILE * competition_table_file;

    competitor_node_ptr tree_top_ptr;
    competitor_node_ptr temp_top_ptr;

    //char temp[20];

    competition_table_file = fopen(competition_filename, "r");

    if (competition_table_file != NULL) {

        int ch = 0;
        int lines = 0;
        while (!feof(competition_table_file)) {
            ch = fgetc(competition_table_file);
            if (ch == '\n') {
                lines++;
            }
        }

#ifdef DEBUG
        printf("There are %d lines in this file \n", lines);
#endif
        rewind(competition_table_file);

        fgets(name_of_competition, MAX_INPUT_LENGTH, competition_table_file);
   
        fgets(last_update, MAX_INPUT_LENGTH, competition_table_file);
      


        tree_top_ptr = read_team_node(competition_table_file);

        for (int i = 0; i < ((lines - 3) / 6); i++) {
            add_competitor_node(tree_top_ptr, read_team_node(
                    competition_table_file));
        }

    } else {
        printf("Couldn't find the file");
        return NULL;
    }

    fclose(competition_table_file);
    return tree_top_ptr;

}