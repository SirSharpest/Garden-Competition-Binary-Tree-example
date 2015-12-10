/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Nathan Hughes (nah26)
 *
 * Created on 01 December 2015, 13:02
 */

#include <stdio.h>
#include <stdlib.h>
#include "competition.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char last_updated[MAX_INPUT_LENGTH]; 
    char name_of_competition[MAX_INPUT_LENGTH];
    char file_name[MAX_INPUT_LENGTH];
    
    printf("Please enter in the name of the file you wish to use for"
            " this program's data\n");
    scanf("%s", file_name);
    
    //Root node defined 
    competitor_node_ptr tree_top; 
    
    //Read in the data file
    tree_top = create_competitor_binary_tree(file_name, last_updated, name_of_competition);
    
 //   print_competitor_nodes(tree_top);
     print_competitor_table(tree_top, last_updated, name_of_competition);
    
    //print_competitor_table(tree_top, last_updated);
    
    return (EXIT_SUCCESS);
}
