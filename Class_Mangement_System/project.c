#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINE A STRUCTURE CALLED STUDENT
typedef struct Personne
{
    char *name;
    int cne;
    int grade;
}student;

// Functions Prtotypes
student* saisie(int taille);
void Afficher(student *LEtd, int taille);
void AfficheParCNE(student *LEtd, int taille);
void SupprimerEtdParCNE(student *LEtd, int taille);
void echange_Etd(student *LEtd);
void sort(student *LEtd, int taille);
int menu(void);


// Main function
int main(void)
{
    // Declaring the variables
    student *STUDENT;
    int taille, choice;
    char *string = (char *)malloc(20 * sizeof(char));

    printf("Enter the size of the class: ");
    scanf("%i",&taille);

// We can use switch case instead!
    do
    {
        choice = menu();
        if (choice == 1)
        {
            STUDENT = saisie(taille);
        }
        else if (choice == 2)
        {
            Afficher(STUDENT, taille);
        }
        else if (choice == 3)
        {
            AfficheParCNE(STUDENT,taille);
        }
        else if (choice == 4)
        {
            echange_Etd(STUDENT);
        }
        else if (choice == 5)
        {
            sort(STUDENT,taille);
        }
        else if (choice == 6)
        {
            SupprimerEtdParCNE(STUDENT,taille);
        }    
        printf("------------------------------------------------\n");
    } while (choice != 0);

    printf("Have a nice day!\n");

// Freeing memory
    free(string);
    free(STUDENT->name);
    free(STUDENT);
// Succesfull execution!
    return 0;
}


/* Functions that reads students' informations 
   and store them in an array of type student */
student* saisie(int taille)
{
    // File to save infos about students
    FILE *input;
    input = fopen("STUDENTS.txt","w");

    student *STUDENTS = (student *) malloc(taille * sizeof(student));

    for (int i = 0 ; i < taille ; i++)
    {
        // Allocate enough memory for the string!
        STUDENTS[i].name = (char *) calloc(20, sizeof(char));

        // Age of the student
        printf("ENTER CNE: ");
        scanf("%i",&STUDENTS[i].cne);

        // Name of the student
        printf("ENTER NAME: ");
        scanf("%s",STUDENTS[i].name);

        // Grade of the student
        printf("ENTER GRADE: ");
        scanf("%i",&STUDENTS[i].grade);


        // Save informations in the external file!
        fprintf(input,"%s's CNE is %i and his Grade %i\n",STUDENTS[i].name,STUDENTS[i].cne,STUDENTS[i].grade);
    }

    fclose(input);
    return STUDENTS;
}

// Function that writes to the stdout stream Students infos!
void Afficher(student *LEtd, int taille)
{
    for (int i = 0; i < taille;i++)
    {
        printf("%s's CNE is %i and his Grade %i\n",LEtd[i].name,LEtd[i].cne,LEtd[i].grade);
    }
}

// Function that search and element by its CNE and display its infos!
void AfficheParCNE(student *LEtd, int taille)
{
    int i = 0, CNE;
    printf("Enter the CNE : ");
    fscanf(stdin,"%i",&CNE);
    // here we can compare these two variables as they are integers!
    while(LEtd[i].cne != CNE)
    {
        i++;
    }
    fprintf(stdout,"%s's CNE is %i and his Grade %i\n",LEtd[i].name,LEtd[i].cne,LEtd[i].grade);
}

// Delete an element from the array by its CNE.
void SupprimerEtdParCNE(student *LEtd, int taille)
{
    int cne = 0;
    printf("Enter the CNE : ");
    fscanf(stdin,"%i",&cne);
    int k = 0;
    while (LEtd[k].cne != cne)
    {
        k++;
    }
    for (int z = k; z < taille ; z++)
    {
        LEtd[z] = LEtd[z+1];
    }
}

// Swap two elements from the array!
void echange_Etd(student *LEtd)
{
    int i , j;
    printf("Enter two indices i and j (separeted by space): ");
    fscanf(stdin,"%i %i",&i,&j);
    student temp = LEtd[i];
    LEtd[i] = LEtd[j];
    LEtd[j] = temp;
}

// Sort the array of students by Grade using BUBBLE SORT ALGO!
void sort(student *LEtd, int taille)
{
    int swap = 1;
    while(swap != 0)
    {
        swap = 0;
        for (int i = 0; i < taille - 1 ; i++)
        {
            if (LEtd[i].grade < LEtd[i+1].grade)
            {
                student temp = LEtd[i];
                LEtd[i] = LEtd[i+1];
                LEtd[i+1] = temp;
                swap++; 
            }
        }
    }
}

// Menu that displays the available operations!
int menu(void)
{
    int choice;
    printf("1/ ADD STUDENT\n");
    printf("2/ DISPLAY STUDENTS\n");
    printf("3/ DISPLAY A STUDENT BY CNE\n");
    printf("4/ SWAP TWO STUDENTS\n");
    printf("5/ SORT THE STUDENTS BY GRADE\n");
    printf("6/ DELETE A STUDENT BY CNE\n");
    printf("0/ QUIT\n");
    printf("Choose an operation: ");
    fscanf(stdin,"%i",&choice);
    return choice;
}

/*
Valgrind result:
==17993== 
==17993== HEAP SUMMARY:
==17993==     in use at exit: 0 bytes in 0 blocks
==17993==   total heap usage: 7 allocs, 7 frees, 6,672 bytes allocated
==17993== 
==17993== All heap blocks were freed -- no leaks are possible
==17993== 
==17993== For lists of detected and suppressed errors, rerun with: -s
==17993== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
