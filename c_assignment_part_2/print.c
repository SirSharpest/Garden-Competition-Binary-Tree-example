#include <stdio.h>
#include "competition.h"


void print_competitor_nodes(competitor_node_ptr competitor_root_node, 
        void (* action)(competitor_node_ptr)){
    
    
    if(competitor_root_node->left_child  != NULL){
        print_competitor_nodes(competitor_root_node->left_child, 
                action);
    }
    
    action(competitor_root_node);
     
    if(competitor_root_node->right_child != NULL){
        print_competitor_nodes(competitor_root_node->right_child,
                action);
    }

}

void print_a_nodes_competition_stats(competitor_node_ptr competitor_root_node){
    
    
    int cucumber_feet = (int)competitor_root_node->cucumber_length / INCHES_IN_FOOT; 
    int carrot_feet = (int)competitor_root_node->carrot_length / INCHES_IN_FOOT; 
    int runnerbean_feet = (int)competitor_root_node->runnerbean_length / INCHES_IN_FOOT; 
    
    
    float cucumber_inches =  (competitor_root_node->cucumber_length - (cucumber_feet *INCHES_IN_FOOT ) );  
    float carrot_inches =  (competitor_root_node->carrot_length - (carrot_feet *INCHES_IN_FOOT ) ); 
    float runnerbean_inches = (competitor_root_node->runnerbean_length - (runnerbean_feet *INCHES_IN_FOOT ) ) ; 
   
    int total_feet = cucumber_feet + carrot_feet + runnerbean_feet;
    float total_inches = cucumber_inches + carrot_inches + runnerbean_inches;
    
    if(total_inches > INCHES_IN_FOOT){
        total_feet += total_inches/INCHES_IN_FOOT; 
        total_inches -= (int)(total_inches/INCHES_IN_FOOT) * INCHES_IN_FOOT;
    }
    
    printf("%-23s %-4u  %4dft  %-4.1fin %4dft  %4.1fin  %4dft "
            " %-4.1fin %4dft  %-4.1fin \n",
            competitor_root_node->name,
            competitor_root_node->competitor_number,
            cucumber_feet,
            cucumber_inches,
            carrot_feet, 
            carrot_inches,
            runnerbean_feet, 
            runnerbean_inches,
            total_feet,
            total_inches
    );
    
}


void print_competiton_table(competitor_node_ptr competitor_root_node, 
        char * last_update, char* name_of_competition){

    char name_header[] = "NAME";
    char comp_num_header[] = "competitor number";
    char cucumber_header[] = "Cucumber";
    char carrot_header[] = "Carrot";
    char runnerbean_header[] = "Runner Bean"; 
    char total_header[]  = "Totals";
    
    
    
    printf("Competition: %sDate: %s", 
            name_of_competition, last_update); 
   
   
    printf("%-14s %-19s %-15s %-12s %-15s  %-15s \n", 
            name_header, 
            comp_num_header,
            cucumber_header,
            carrot_header,
            runnerbean_header,
            total_header);
    
    printf("================================================================================="
            "============\n");
        
    print_competitor_nodes(competitor_root_node,print_a_nodes_competition_stats);
    
}

/**
 * Takes the same information as required for print functions, but also takes 
 * a function pointer which will decide how information is traversed 
 * @param root_node
 * @param last_update
 * @param name_of_competition
 * @param action
 */
void traverse_information(competitor_node_ptr root_node, char* last_update, char* name_of_competition,
        void(*action)(competitor_node_ptr, char*, char*)){
    
    action(root_node, last_update, name_of_competition);
    
}

void print_a_nodes_contact_information(competitor_node_ptr competitor_root_node){
    
    //print out information in specified format
    printf("\nCompetitor Name: %s \n"
            "Postal Address: %s \n"
            "Telephone: %s \n", 
            competitor_root_node->name,
            competitor_root_node->postal_address,
            competitor_root_node->phone_number);
    
}



void print_competiton_information_table(competitor_node_ptr competitor_root_node, 
        char * last_update, char* name_of_competition){
    
     printf("Competition: %sDate: %s", 
            name_of_competition, last_update); 
     
     print_competitor_nodes(competitor_root_node, print_a_nodes_contact_information);
    
    
}