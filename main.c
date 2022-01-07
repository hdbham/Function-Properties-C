#include <stdio.h>
//macro found on stack exchange allows forEach() not included in standard C
#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = numPairs; \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)
// source: https://stackoverflow.com/questions/34007634/macro-foreach-loop-in-c
int main(void) {
  
  int i, numPairs, found, elementOf, valid, oneToOne, onto;
  int arrY[5];
  int arrX[5];
 printf("CS 2130 - Computational Structures - Hunter Burningham\nThis program reads
in ordered pairs from the user \nthen determines if function is valid, onto, one-
to-one, bijective\n\n");
//edit domain here
int domain[5] = {1,2,3,4,5}; //domain elements
  int domainSize = sizeof(domain)/sizeof(domain[i]);
//displays domain
  printf("\nDomain = ");
  for (i = 0; i < domainSize; i++){
  printf("%d ", domain[i]);
  }
//edit range here
int range[5]  = {1,2,3,4,5}; //range elements
    int rangeSize = sizeof(range)/sizeof(range[i]);
//displays range
  printf("\nRange  = ");
  for (i = 0; i < rangeSize; i++){
  printf("%d ", range[i]);
  }
//begin user input
//get number of ordered pairs
 LOOP: printf("\n\nPlease enter the number of paired values as an integer: ");
  scanf("%i", &numPairs);
printf("\n");
//gets pairs, stores first number preceding space in ARR X
//subsequent in ARR Y
   for(i = 0; i < numPairs; i++){
    printf("Please enter ordered pair %d : ", i); 
    scanf("%d %d", &arrX[i], &arrY[i]);
  }
//displays arrays in function notation
  printf("\nFunction Described by:\n");
  for (i = 0; i < numPairs; i++){
  printf("f(%d) = %d\n", arrX[i], arrY[i]);
  }
printf("\n");
//end user input
//begin determinations
/*Determine if Valid Function:
ALL X within domain, ALL Y within range, No repeated Y values*/ 
//checks if all X in domain
  foreach(int *elementOf, arrX) {
found = 0;
     for(int j=0; j<domainSize; j++)
    {
        while(domain[j] == *elementOf)
        {
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        int valid = 1;
    }
    else {
       // printf("%d not in domain\n", *elementOf);
       valid = 0;}
}
//checks if all Y in range
foreach(int *elementOf, arrY) {
found = 0;
     for(int j=0; j<rangeSize; j++)
    {
        while(range[j] == *elementOf)
        {
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        int valid = 1;
    }
    else {
      //printf("%d not in range\n", *elementOf);
       valid = 0;}
} 
//checks duplicate Y values 
for(i=0;i<15;i++)
    {
        for(int j=i;j<numPairs;j++)
        {
            if(arrY[i]==arrY[j+1])
            {
              // printf("Y has duplicate value: %d\n",arrY[i]);
                valid = 0;
                ;
            }
        }
    }
if (valid == 0){
  printf("This function is not a valid function.\n");
  return 0;
}
else {
  printf("\nIs a valid function or a partial function\n");
  }
//check oneToOne
//No repeated X values;
oneToOne = 1; //assume one-to-one
for(i=0;i<15;i++)
    {
        for(int j=i;j<numPairs;j++)
        {
            if(arrX[i]==arrX[j+1])
            {
                //printf("Number %d has duplicate values, not oneToOne\n",arrX[i]);
                oneToOne = 0;
                ;
            }
        }
    }
//check onto
//see if all range values in Y, if so, then onto
onto = 1; //assume onto
foreach(int *elementOf, range) {
found = 0;
    
    for(i=0; i<numPairs; i++)
    {
        if(arrY[i] == *elementOf)
        {
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        onto = 0;
    }
}
//end determinations - bijective 
//output results
if (oneToOne == 1){
  printf("Is one-to-one\n");
}
else{
  printf("Is NOT one-to-one\n");
}
if (onto == 1){
  printf("Is Onto\n");
}
else {
  printf("Is NOT onto\n");
}
//determination for bijective (both onto and oneToOne) outputs "bijective" if true
if (onto == 1 && oneToOne == 1){
  printf("Bijective\n");
}
else {
  printf("Is NOT Bijective\n");
}
//end main()
}
