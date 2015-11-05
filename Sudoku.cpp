// sudoku Solver 
//
// The program, first gets the 2d array from Reading_file, using I/O. Then appends it to sudoku array
// It then uses array and array algorithum to find all possible solution at empty space and if solution is valid, it appends 
// to the sudoku array. When all the slots are filled it then creates a file named writing_file and appendes
// the sudoku problem and solution. 
// 
//
// Parameters  - Main               
// ==========                
//    * fp     		sudoku file writer opening pointer.  
//    sudoku   		Array to append sudoku problem from the file 
//    p,z,w			Iterative value 
//
// Parameters  - zeros             
// ==========     
//    app_arr     	Array to append solution to empty slot 
//    count   		variable that increases in magnetude when new variable is appended in app_arr
//    a,b,d			Iterative value 
//
// Parameters  - array_printer             
// ==========     
//    p,z			Iterative value 
//

#include <stdio.h>
#include <stdlib.h> 

int array_printer(int sudoku[9][9]);
int zeros (int sudoku[9][9], int p, int z);

int main()
{
	//initializing the file pointer
	FILE * fp;
	FILE * fpr;
	
	// opens Reading file and creates the writing_file
	fp = fopen("writing_file.txt", "w");
	fpr = fopen("Reading_file.txt", "r");
	
	//prints out to the writing file
	fprintf(fp, "The following is a sudoku to solve:\n\n");
	printf("The following is a sudoku to solve:\n\n");
	
	//initializing empty sudoku file 
   int sudoku[9][9];
   
   //iterative variables 
   int p = 0;
   int z = 0;
   int w = 0;
   int i = 0;
   
   //empty array to append the array from Read_file
   char ignore[200];
   
   //Gets the data from as char from Reading file and changes it to int value and appends it to sudoku file
   while(fgets(ignore,200,fpr)!=NULL){
   		i=0;
		while(ignore[i]!='\0'){
			if(ignore[i]!=' '){
				sudoku[p][z] = atoi(&ignore[i]);
				z++;
				if( z == 8 & p ==8){
					break;
				}
			}
			i++;
		}
		p++;
		z=0;
   }
   
   // closes the reading file 
   fclose(fpr);
   
   //reinitalizing iterative variables 
   p=0;
   i=0;
   z=0;
   w=0;
   
   //Prints unsolved sudoku file to writing file
   for(p;p<9;p++){
   		for(z;z<9;z++){
   			fprintf(fp,"%d  ",sudoku[p][z]);
		}
		z=0;
		fprintf(fp,"\n");
   }
   //reinitalizing iterative variables 
   p=0;
   z=0;
   
   //prints unsolved sudoku to user 
   array_printer(sudoku);
   
   //finds zeros within unsolved sudoku and sends it to zero function 
   while(w <=81){
   	p=0;
   	z=0;
	   for(p;p<9;p++){
			for (z;z<9;z++){
				if(sudoku[p][z]==0){
					sudoku[p][z] = zeros(sudoku, p ,z);	
					w=0;
				}
				else {
					w = w +1;
				}
			}
			z=0;
		}
    }
	printf("\n");
	printf("\n");	
	printf("\n\n\nThe following is the solved sudoku puzzle:\n\n");
	//prints the solved sudoku array to user
	array_printer(sudoku);
	
	fprintf(fp,"\n\n\nThe following is the solved sudoku puzzle:\n\n");
	p=0;
    z=0;
    //writes the solved sudoku into the writing file 
	for(p;p<9;p++){
   		for(z;z<9;z++){
   			fprintf(fp,"%d  ",sudoku[p][z]);
		}
		z=0;
		fprintf(fp,"\n");
   }
   fclose(fp);
   return 0;
};

//sudoku solving algorithum.
int zeros (int sudoku[9][9], int p, int z){
	int count = 0;
	int a = 0;
	int b = 0;
	int d = 0;
	int c[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	if(p<3 && z<3){
		for(a;a<3;a++){
			for(b;b<3;b++){
				if(sudoku[a][b] != 0){				
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=0;
		}
	}
	if((3<=p & p<6) && (z<3)){
		a = 3;
		for(a;a<6;a++){
			for(b;b<3;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=0;
		}
	}
	if((p>=6) && (z<3)){
		a=6;
		for(a;a<9;a++){
			for(b;b<3;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=0;
		}
	}
	if((p<3) && (3<=z & z<6)){
		for(a;a<3;a++){
			b=3;
			for(b;b<6;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=3;
		}
	}
	if((3<=p & p<6) && (3<=z & z<6)){
		a=3;
		for(a;a<6;a++){
			b=3;
			for(b;b<6;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=3;
		}
	}
	if((p>=6) && (3<=z & z<6)){
		a=6;
		for(a;a<9;a++){
			b=3;
			for(b;b<6;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=3;
		}
	}
	if((p<3) && (z>=6)){
		for(a;a<3;a++){
			b=6;
			for(b;b<9;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=6;
		}
	}
	if((3<=p & p<6) && (z>=6)){
		a=3;
		for(a;a<6;a++){
			b=6;
			for(b;b<9;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=6;
		}
	}
	if((p>=6) && (z>=6)){
		a=6;
		for(a;a<9;a++){
			b=6;
			for(b;b<9;b++){
				if(sudoku[a][b] != 0){
					c[count] = sudoku[a][b];
					count = count+1;
				}
			}
			b=6;
		}
	}
	a=0;
	for (a;a<9;a++){
		if(sudoku[p][a]!=0){
			c[count] = sudoku[p][a];
			count = count+1;
		}
		if(sudoku[a][z]!=0){
			c[count] = sudoku[a][z];
			count = count + 1;
		}
	}
	a = 1;
	b = 0;
	count=0;
	for(b;b<24;b++){
		if(c[b]==a){
			a=a+1;
			b=0;
		}
	}
	d=a;
	a=a+1;
	b=0;
	for(b;b<24;b++){
		if(c[b]==a){
			a=a+1;
			b=0;
		}
	}
	if(a!=10){
		d=0;
		a=0;
	}
	return d;
}


//user_printing algorithum 
int array_printer(int sudoku[9][9]){
	int p=0;
	int z=0;
  for(p;p<9;p++){
		for (z;z<9;z++){
			printf("%d  ", sudoku[p][z]);
	   };
	   z = 0; 
	   printf("\n");
   };
   	return 0;
}

