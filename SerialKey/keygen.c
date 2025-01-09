#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Input  */
/* char* seed: seed given as command line argument #1 (argv[1])*/
/* int key: key given as command line argument #2 (argv[2])*/

/* Output  */
/* char* serial: empty array to be filled with generated serial key */
void generate_serial(char *serial, char *seed, int key) {
  int key = key>>4;
  int kpart2 = 0xf & key;
  char character; 
  //looped and checks 10 characters at beginning of serial
  for(int i = 0; i<10; i++)
  {
  	//saves each character received 
  	character = *((seed+i));
  	// checks character if number from dec 58 and 65
  	if(character >=58 && c< 65)
  	{
  	   //checks if range is from numbers
  	   if(47 < character && character < 58)
  	   {
  	   	if(57 < character(key%10))
  	   	{
  			c= c-10;
  	    	}
  	    }
  	    //adds remainder to the key to find key
  	    c+= key%10;
  	}
  	
  	//check if character is mayuscular by dec 64 & 91
  	else if(64 < character && character < 91)
  	{  
  	  if( 90 < (character(kpart2 %26)) )
  	  {
  		character= character - 26;
  	  }
  	  //adds the value to the key
  	  character += key %10;
  	}
  	
  	//goes check if character is minuscular by dec 96 & 123
  	else if(96 < character && character < 123) 
  	{
  	  //checks if character is out of range from minusculars
  	  if((character+(key%26)) > 122){	
 	    //locates to miniscular by subtracting 26
             character= character - 26;
  	  }
  	  //adds to key from remainders to find key
  	  character+= kpart2 %26;
  	}
  	
  	//saves the characters to part of serials
  	character = *(serial+10+i); 
  }
}

int main(int argc, char **argv) {
  char serial[32] = {0};
  char *seed;
  int key;

  if (argc < 3) {
    printf("Seed and Key not provided\n");
    return 1;
  }

  seed = argv[1];
  key = atoi(argv[2]);

  if (strlen(argv[1]) != 20) {
    printf("Incorrect seed format\n");
    return 1;
  }

  if (key < 17 || key > 255) {
    printf("Incorrect key format\n");
    return 1;
  }

  generate_serial(serial, argv[1], atoi(argv[2]));
  printf("%s\n", serial);
  return 0;
}

