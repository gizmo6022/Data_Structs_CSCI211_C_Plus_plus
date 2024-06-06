//John Marshall Assignment 2

#include "Card.h"
#include <vector> 


void mergesort(Card[], int, int);
void merge(Card[], int, int, int);
void quicksortValue(Card , int, int);
void quicksort(Card , int, int);

//MERGE/MERGESORT ALOGRITHMS TAKEN AND MODIFIED FROM CLASS SOURCE CODE

void mergesort(Card stack[], int left, int right){
	
	int middle = (left + right)/2;
	
	if(left<right){
		int middle = (left + right)/2;
		
		mergesort(stack, left, middle);
		mergesort(stack, middle+1, right);
	
		merge(stack, left, middle, right);
	};
}

void merge(Card stack[], int left, int middle, int right){
    //VARAIBLES: Lower Partion Index, Upper Partion Index, Entire Partion Index 
	int lowerCounter = 0;
    int upperCounter = 0;
    int mergeCounter = left;
    
    int lowerSize = middle - left + 1;
    int upperSize = right - middle;

    //create New arrays to at the proper size
    std::vector<Card> tempLower(lowerSize);
	std::vector<Card> tempUpper(upperSize);

  
    //Populate temp arrays
    for(int i = 0; i < lowerSize; i++) {
        tempLower[i] = stack[left + i]; 
    };
	for(int i = 0; i < upperSize; i++) {
        tempUpper[i] = stack[middle + 1 + i]; 
    };
  
    //MERGE: repopulate main array with new temp array values.
    while(lowerCounter < lowerSize && upperCounter < upperSize) { 
        //This is where the comparison takes place
        if(tempLower[lowerCounter].valRefNum <= tempUpper[upperCounter].valRefNum) { 
            stack[mergeCounter] = tempLower[lowerCounter];
            lowerCounter++;
        } 
        else { 
            stack[mergeCounter] = tempUpper[upperCounter];
            upperCounter++;
        } 
        
        //Increment index to place the next value from the two partitions
        mergeCounter++;
    };
    
    while(lowerCounter < lowerSize) { 
        stack[mergeCounter] = tempLower[lowerCounter]; 
        lowerCounter++; 
        mergeCounter++; 
    }; 
  
    //Copy the remaining elements of tempUpper, if there are any
    while(upperCounter < upperSize) { 
        stack[mergeCounter] = tempUpper[upperCounter]; 
        upperCounter++; 
        mergeCounter++; 
    }; 
}


//QUICK SORT ALOGRITHMS TAKEN AND MODIFIED FROM CLASS SOURCE CODE

//Variables: the lower partition Index, upper partition Index, swapping Temp, middle element pivot
void quicksortValue(Card stack[], int start, int end) {
    int lower = start;
    int upper = end;
    Card temp;
    Card pivot = stack[(lower + upper) / 2];

    //Partitioning
    //Compare numbers to pivot and sort them into into Less then pivot and greater then pivot, Increment/decrement index tracker
    while(lower <= upper) {
        while(stack[lower].valRefNum < pivot.valRefNum) {
            lower++;
        };
        while(stack[upper].valRefNum > pivot.valRefNum) {
            upper--;
        };
        if(lower <= upper) {
            //Swap elements at indexs and increment/decrement                              
            temp = stack[lower];
            stack[lower] = stack[upper];
            stack[upper] = temp;
            lower++;
            upper--;
        };
    };

    //call quicksort again on new partitions
    if(start < upper) {
        quicksortValue(stack, start, upper);
    };
    if(lower < end) {
        quicksortValue(stack, lower, end);
    };
}

//QUICK SORT BY SUIT
void quicksortSuit(Card stack[], int start, int end) {
    int lower = start;
    int upper = end;
    Card temp;
    Card pivot = stack[(lower + upper) / 2];

    //Partitioning
    //Compare numbers to pivot and sort them into into Less then pivot and greater then pivot, Increment/decrement index tracker
    while(lower <= upper) {
        while(stack[lower].suitRefNum < pivot.suitRefNum) {
            lower++;
        };
        while(stack[upper].suitRefNum > pivot.suitRefNum) {
            upper--;
        };
        if(lower <= upper) {
            //Swap elements at indexs and increment/decrement                                       
            temp = stack[lower];
            stack[lower] = stack[upper];
            stack[upper] = temp;
            lower++;
            upper--;
        };
    };

    //call quicksort again on new partitions
    if(start < upper) {
        quicksortSuit(stack, start, upper);
    };
    if(lower < end) {
        quicksortSuit(stack, lower, end);
    };
}

