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
void Shift_array (uint8_t Shifted_Index , uint8_t Last_index , sint32_t* Num);


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

    sint32_t result=0;
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
        //Num[myIndex+1]=-1;
        operation[myIndex]=-1;
        /*Sort the arrays such that the unwanted variables end up at the end of the array*/
        //sortNegatives(Num,index);
        if (score[0] != 0)
            Shift_array(myIndex+1 , index , Num);
        else
        {
            // do Nothing
        }

        sortNegativesChar(operation,index-1);
        myIndex=0;

    }while(operation[0]!=-1);
    lcd_cmd(0x01);//clear the screen
    lcd_moveCursor(0,0); //Move Cursor to top left
    lcd_string("Result=");
    lcd_moveCursor(0,1); //Move Cursor to bottom left
    result=Num[0];
    /*PRINT THE RESULT AND RETURN ITS VALUE TO BE SAVED*/
    if (0 == result){
        lcd_data ('0');
    }
    else{
        lcd_printLong(result);
    }
    
    Reset_Num_Operations(); // Reset Numbers Array and Operation Array

    index=0; //Reset the index to overwrite the values in the next operation
   
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
    uint8_t parameter=0;
    static unsigned char myString[20];
    uint8_t i=0,j=0,temp=0;
    unsigned char length;
    uint8_t indexx =0;

    if (a<0)
    {
         myString[i] = '-';
         i++;
         j++;
         a*=-1;
    }
    else
    {
        // Do Nothing
    }

    while(a!=0){
        myString[i]=(a%10)+48;
        a/=10;
        ++i;
    }
    myString[i]=0;

    length=strlen(myString); //get the length of the string

    /*Reverse my string to the correct order*/
    if (j){
        parameter=((length-1)/2)+1;
    }
    else
        parameter=(length/2);

    for(;j<parameter;j++){
        temp=myString[j];
        indexx=(myString[0]=='-'?length-j:length-j-1);
        myString[j]=myString[indexx];
        myString[indexx]=temp;
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
    int i;
    for (i=0; i<=index;i++)
    {
        Num[i]=0;
        if (i<=index-1)
            operation[i]=0;
    }
}

void Shift_array (uint8_t Shifted_Index , uint8_t Last_index , sint32_t* Num)
{
    sint32_t temp;
    uint8_t i;

    for (i=Shifted_Index; i<Last_index; i++)
    {
        temp = Num[i];
        Num[i]=Num [i+1];
        Num[i+1]=temp;
    }
}
