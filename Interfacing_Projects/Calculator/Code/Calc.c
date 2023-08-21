/*
 * Calc.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mina Adel & Omar Ahmed
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_types.h"
#include <string.h>
#define MAX_INDEX 10
void calculate(void);
void sortNegatives(int arr[], int n);
void sortNegativesChar(sint8_t arr[], int n);
void Write_Num_LCD (uint8_t index);
void lcd_data(unsigned char data);
void Write_Operation_LCD (void);
uint8_t* Convert_Int_String (uint32_t Num);
void ALL_Operation ();
extern uint8_t index;
extern uint8_t PressedBTN;
extern uint8_t flag;
static sint32_t Num[MAX_INDEX]={0};//inputs up to five numbers (each number can have more than 1 digit)
static sint8_t operation[MAX_INDEX]={0};//inputs up to five operations (each number counts as a character)
void lcd_cmd(unsigned char cmd);
void lcd_string(unsigned char *str);
void lcd_moveCursor(uint8_t x,uint8_t y);
void lcd_printLong(long a);
unsigned char* integer_to_string(int a);
void Reset_Num_Operations (void);


uint32_t evaluateOneOperation(sint32_t a , sint32_t b , sint8_t op)
{
    uint32_t res;

    switch (op)
    {
    case '+':
        res= a+b;
        break;
    case '-':
        res= a-b;
        break;
    case '*':
        res= a*b;
        break;
    case '/':
        res= a/b;
        break;
    }
    return res;
}

void Write_Num_LCD (uint8_t index)
{

    lcd_data(PressedBTN);
    Num[index] += ((uint32_t)PressedBTN -48);
    Num[index]*=10;
    flag=0;
}

void Write_Operation_LCD (void)
{
    operation[index]= PressedBTN;
    lcd_data(PressedBTN);
    Num[index]/=10;
    index++;
}

void calculate(void){

    long result=0;
    sint32_t score[MAX_INDEX]={0};

    /*****ORGANIZING THE ARRAYS AND COUNTING THE SCORES*****/
    uint32_t myIndex,noPriority=0;
    Num[index]/=10;
    for(int i=0;i<=(index-1);i++){
        if(operation[i]=='+'||operation[i]=='-'){
            score[i]=1;
        }
        else if(operation[i]=='*'||operation[i]=='/'){
            score[i]=2;
        }
    }

    do{

        /*FIND THE FIRST HIGHEST SCORE AND USE ITS INDEX TO CALCULATE THE OPERATION*/
        for(int i=0;(score[i]!=-1)&&(score[i]!=0);i++){
            if(score[i]==2){
                noPriority=0;
                break;
            }
            else{
                noPriority=1;
            }
        }
        for(int j=0;j<=(index-1);j++){
            if(score[j]==2){
                myIndex=j;
                break;
            }
            else if(score[j]==1){
                myIndex=j;
                if(noPriority==1){
                    break;
                }
            }
        }
        score[myIndex]=-1;/*Remove the Score of the selected operation*/
        sortNegatives(score,index-1);/*Sort the scores to the new values.*/
        /*Store the result in the place of the first number.*/
        Num[myIndex]=evaluateOneOperation(Num[myIndex] ,Num[myIndex +1] , operation[myIndex]);
        /*Clear the place of the second number and the used operation.*/
        Num[myIndex+1]=-1;
        operation[myIndex]=-1;
        /*Sort the arrays such that the unwanted variables end up at the end of the array*/
        sortNegatives(Num,index);
        sortNegativesChar(operation,index-1);
        myIndex=0;

    }while(Num[1]!=-1);
    lcd_cmd(0x01);//clear the screen
    lcd_moveCursor(0,0); //Move Cursor to top left
    lcd_string("Result=");
    lcd_moveCursor(0,1); //Move Cursor to bottom left
    result=Num[0];
    /*PRINT THE RESULT AND RETURN ITS VALUE TO BE SAVED*/
    lcd_printLong(result);
    index=0; //Reset the index to overwrite the values in the next operation
    
    Reset_Num_Operations(); // Reset Numbers Array and Operation Array
   
}

void sortNegatives(int arr[], int n) {
    int i, j;
    for (i = 0; i <=n; i++) {
        for (j =0; j <=n-1; j++) {
            if (((int)arr[j])<0) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void sortNegativesChar(sint8_t arr[], int n) {
    int i, j;
    for (i = 0; i <=n; i++) {
        for (j =0; j <=n-1; j++) {
            if ((arr[j])<0) {
                // Swap arr[j] and arr[j+1]
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
unsigned char* integer_to_string(int a){
    static unsigned char myString[20];
    uint8_t i=0,temp=0;
    while(a!=0){
        myString[i]=(a%10)+48;
        a/=10;
        ++i;
    }
    unsigned char length=strlen(myString);//get the length of the string
    /*Reverse my string to the correct order*/
    for(int j=0;j<(length/2);j++){
        temp=myString[j];
        myString[j]=myString[length-j-1];
        myString[length-j-1]=temp;
    }
    return myString;
}

void lcd_printLong(long a){

    unsigned char* buffer=NULL;  // Buffer to store the string representation of the integer
    buffer=integer_to_string(a);  // Convert integer to string.
    lcd_string(buffer);  // Print the string representation on the LCD
}

void Reset_Num_Operations (void)
{
    uint8_t i;
	for (i=0; i<=index;i++)
	{
		Num[i]=0;
		if (i<=index-1)
			operation[i]=0;
	}
}
