#include "Student.h"


 student* head =0;
 student* tail=0;

 extern Course Courses [3];

/**************************************Private Functions to File*************************************************/
static student* Create_Node (void);
static ValidType_t Check_Name (char* Name);
static ValidType_t Check_ID_7_digits (int id);
static ValidType_t Check_Gender (char gender);
static ValidType_t Check_Academic_Year (int year);
/*****************************************************************************************************************/


/******************************************Implementations*******************************************************/

static student* Create_Node (void)
{
    student* ptr =  (student*) (malloc(sizeof (student)));

    if (head == 0)
    {
        head =ptr;
    }
    else
    {
        tail->next = ptr;
    }
    tail =ptr;
    tail->next = 0;

    return ptr;
}

static ValidType_t Check_Name (char* Name)
{
    int count =0,i=0;

    while (Name[i] !=0)
    {
        if (Name[i] == ' ')
            count++;
        i++;
    }
    if (count ==1)
        return VALID;
    else
        return UNVALID;
}

static ValidType_t Check_ID_7_digits (int id)
{
    int count=0;

    while (id/10 !=0)
        {
            id/=10;
            count++;
        }
    if (count!=6)
        return UNVALID;
    else
        return VALID;

}

static ValidType_t Check_Gender (char gender)
{
    if (gender == 'M' || gender == 'F')
        return VALID;
    else
        return UNVALID;
}

static ValidType_t Check_Academic_Year (int year)
{
    if ((year>=1 && year <=MAX_ACADEMIC_YEAR))
        return VALID;
    else
        return UNVALID;
}

void Add_Student (void)
{
    student* New_Student =  Create_Node ();

    ValidType_t State= UNVALID;

    /*************************************Name************************************/

    while (State == UNVALID)
    {
        printf ("Enter First and Last Name Only of Student: ");
        fflush (stdin); fflush (stdout);
        gets (New_Student->Name);
        State = Check_Name (New_Student->Name);
    }

    State= UNVALID;

    /****************************************************************************/

    /************************************ID**************************************/
    student* curr=head;

    while (State != VALID)
    {
        printf ("Enter ID of Student (7 digits): ");
        fflush (stdin); fflush (stdout);
        scanf("%d",&New_Student->id);
        State = Check_ID_7_digits (New_Student->id);

        if (State == UNVALID)
            continue;
        else {}

        while (curr!=0)
        {
            while (curr->id == New_Student->id && curr != New_Student)
            {
                printf ("ID is already Exist, Enter another One: ");
                fflush (stdin); fflush (stdout);
                scanf("%d",&New_Student->id);
            }
            curr =curr->next;
        }
        State = Check_ID_7_digits (New_Student->id);
    }
    State = UNVALID;
    /*****************************************************************************/

    /********************************Gender**************************************/
    while (State == UNVALID)
    {
        printf ("Enter Gender 'M' for Males and 'F' for Females: ");
        fflush (stdin); fflush (stdout);
        scanf ("%c",&New_Student->gender);
        State = Check_Gender(New_Student->gender);
    }
    State = UNVALID;
    /****************************************************************************/

    /*******************************Academic Year********************************/
    while (State == UNVALID)
    {
        printf ("Enter Academic Year: ");
        fflush (stdin); fflush (stdout);
        scanf("%d",&New_Student->year);
        State = Check_Academic_Year(New_Student->year);
    }
    State = UNVALID;
    /*****************************************************************************/

    /*******************************GPA*******************************************/
        New_Student->GPA=0.0;
    /*****************************************************************************/
}

void Remove_Student (void)
{
    student* curr=head;
    student* prev=head;

    int id;
    printf ("Enter ID of Student whom you want to remove: ");
    scanf ("%d",&id);

    while (curr!=0)
    {
        if (curr->id == id)
        {
            if (curr ==head)
            {
               head = curr->next;
               free (curr);
            }
            else if (curr == tail)
            {
                prev =head;
                while (prev->next !=tail)
                {
                    prev=prev->next;
                }
                tail = prev;
                prev->next =0;
                free (prev);
            }
            else
            {
                prev->next = curr->next;
                free (curr);
            }
            return;
        }
        prev=curr;
        curr = curr->next;

    }

    printf ("Id Not Found\n");
}

void search_Student (void)
{
    unsigned int id;
     student* curr=head;

    printf ("Enter ID of Student whom want to his information: ");
    fflush (stdin); fflush (stdout);
    scanf ("%d",&id);

    while (curr!=0)
    {
        if (curr->id == id)
        {
            printf("======================================\n");
            printf ("Name: %s\n",curr->Name);
            printf ("ID: %d\n",curr->id);
            printf ("Gender: %c\n",curr->gender);
            printf ("Academic Year: %d\n",curr->year);
            printf ("GPA: %.2f\n",curr->GPA);
            printf("======================================\n");
            return;
        }
        curr = curr->next;
    }
    printf ("Id Not Found\n");
}

void Add_Courses (void)
{
    unsigned int id,i,temp=10;
    static int x=1;
    char id_Course[4];
    student* curr=head;

    printf ("Enter ID of Student: ");
    fflush (stdin); fflush (stdout);
    scanf ("%d",&id);

    printf ("Enter ID of Course: ");
    fflush (stdin); fflush (stdout);
    scanf ("%s",id_Course);

    for (i=0; i<3;i++)
    {
        if (strcmp (id_Course , Courses[i].id)==0)
        {
            temp=i;
            break;
        }
    }
     while (x)
    {
        while (curr!=0)
        {
            curr->Num_Courses=0;
            curr = curr->next;
        }
        x--;
    }
    curr =head;

    while (curr!=0)
    {

        if (curr->id == id && curr->Num_Courses <=2)
        {
            strcpy(curr->Courses[curr->Num_Courses].name , Courses[temp].name);
            strcpy(curr->Courses[curr->Num_Courses].id , Courses[temp].id);
            curr->Courses[curr->Num_Courses].Credit_Hours = Courses[temp].Credit_Hours;
            curr->Courses[curr->Num_Courses].grade = Courses[temp].grade;


            float gpa=0.0;
            float hrs=0.0;

            for (i=0;i<=curr->Num_Courses; i++)
            {
                gpa += (curr->Courses[i].grade*curr->Courses[i].Credit_Hours);
            }
            for (i=0;i<=curr->Num_Courses; i++)
            {
                hrs +=(curr->Courses[i].Credit_Hours);
            }
            curr->GPA =gpa/ hrs;
            curr->Num_Courses++;

            return;
        }

        curr=curr->next;
    }

    printf ("this id is not Exist\n");
}

void menu (void)
{
    int choice;

    printf ("=====================================================\n");
    printf ("Enter Choice:\n1> Add Student\n2> Remove Student\n3> Search on Student\n4> Add Courses to Student\n5> Exit..\n");
    printf ("=====================================================\n");
    printf ("your Choice is: ");
    scanf ("%d",&choice);
    printf ("=====================================================\n");

    switch (choice)
    {
    case 1:
        Add_Student();
        break;
    case 2:
        Remove_Student();
        break;
    case 3:
        search_Student();
        break;
    case 4:
        Add_Courses();
        break;
    case 5:
        exit (0);
        break;
    }
}

/*******************************************************************************************************************/

