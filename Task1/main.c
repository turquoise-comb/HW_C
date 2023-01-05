#include<stdio.h>//includes standard input and output
#include<string.h>

#define NUMBER_OF_FLOORS 9
#define MAX_PASSENGERS 10

int lift_floor;



int press_button() {//press button function which takes no argument and returns 
	printf("\nPlease press a button by entering its corresponding name.\n");
	printf("\nFloor names are B3, B2, B1, G, 1, 2, 3, 4, 5\n");
  	char input[30];// we assume possible incorrect input will not exceed length of 31 characters
  	scanf("%s", input);

  	if (strcmp(input, "B3") == 0) {
      return 0;
  	} else if(strcmp(input, "B2") == 0) {
      return 1;
  	} else if(strcmp(input, "B1") == 0) {
      return 2;
  	} else if(strcmp(input, "G") == 0) {
      return 3;
  	} else if(strcmp(input, "1") == 0) {
    	return 4;
  	} else if(strcmp(input, "2") == 0) {
    	return 5;
  	} else if(strcmp(input, "3") == 0) {
    	return 6;
  	} else if(strcmp(input, "4") == 0) {
    	return 7;
  	} else if(strcmp(input, "5") == 0) {
    	return 8;
  	} else {
    // Return -1 if the input is not recognized
    	return -1;
  }
}


char* floor_to_string(int floor_index){// while operating with arrays in functions, only the pointer to the first element of the array is copied
	//so we need to use a pointer * to access return value of string type later on in the code
  switch (floor_index){
    case 0:
      return "B3";
    case 1:
      return "B2";
    case 2:
      return "B1";
    case 3:
      return "G";
    case 4:
      return "1";
    case 5:
      return "2";
    case 6:
      return "3";
    case 7:
      return "4";
    case 8:
      return "5";
    default:
      // Return "wrong floor" if the input is not recognized
      return "elevator is on invalid floor";
  }
}


void floor_to_floor(int start, int end) {
  if (start > end) {
    for (int i = start; i >= end; i--) {
    	if (i==start){
      printf("\nThe elevator is going down from the %s floor\n", floor_to_string(i));
    	}else if(i==end){
    	    printf("\nThe elevator has stopped on the %s floor\n", floor_to_string(i));
    	}else {
    		printf("\nThe elevator is on the %s floor\n", floor_to_string(i));
    	}

      lift_floor=i;
    }
  } else {
    for (int i = start; i <= end; i++) {
	if (i==start){
      printf("\nThe elevator is going up from the %s floor\n", floor_to_string(i));
    	}else if(i==end){
    	    printf("\nThe elevator has stopped on the %s floor\n", floor_to_string(i));
    	}else {
    		printf("\nThe elevator is on the %s floor\n", floor_to_string(i));
    	}
      lift_floor=i;
    }
  }
}


int main(){

	char going='y';
	//initially lift is at the ground floor:
	lift_floor=6;
	 printf("\n\n");


	 while(going!='n'){//while loop makes the game playable as long as the user wishes to keep on playing. It will execute (run the game) at least once


		//user initial floor: 
		printf("\nYou are at the ground floor\n");
		printf("\nThe elevator is on the %d floor\n", lift_floor);
		if(lift_floor!=3){
			printf("\nyup,this is working\n");
			floor_to_floor(lift_floor, 3);
		}
		
		floor_to_floor(lift_floor, press_button());


		printf("\nDo you wish to continue? y/n: \n");
		scanf(" %c", &going);

	}

return 0;// returns 0 if the program compiled correctly
}
