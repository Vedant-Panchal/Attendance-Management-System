#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct subject  // structure for storing attendance of specific subject
{
    char subjectname[30];
    char attendance[2];  // (P/A)
} Subject;

typedef struct node   // structure for storing students basic details
{
    char studentname[100];
    int rollno;
    int enroll;
    char courseandclass[50];  //for storing branch and programme
    Subject subjects[6];    // Array of subjects for attendance
    time_t currentTime;
    struct node *next;
} studentinfo;

studentinfo *head = NULL;

void insertAttendance()
{

    printf("\nEnter the subject for which you want to mark attendance for whole class:\n");
    printf("\t\t1. Mathematics-II\n");
    printf("\t\t2. Data Structures\n");
    printf("\t\t3. Basic Electronics\n");
    printf("\t\t4. Applied Physics\n");
    printf("\t\t5. Human Values\n");
    printf("\t\t6. EGD\n");
    int choice;
    printf("Enter : ");
    scanf("%d", &choice);

    char subjectName[20];
    switch (choice)
    {
    case 1:
        strcpy(subjectName, "Mathematics-II");
        break;
    case 2:
        strcpy(subjectName, "Data Structures");
        break;
    case 3:
        strcpy(subjectName, "Basic Electronics");
        break;
    case 4:
        strcpy(subjectName, "Applied Physics");
        break;
    case 5:
        strcpy(subjectName, "Human Values");
        break;
    case 6:
        strcpy(subjectName, "EGD");
        break;
    default:
        printf("Invalid choice!\n");
        return;
    }

    printf("\t\t+-------------------------------------------------------------------------------------------------+\n");
    printf("\t\t                       Marking Attendance For %-20s \n", subjectName);
    printf("\t\t+-------------------------------------------------------------------------------------------------+\n");
    printf("\n\t\t+-------------------------------------------------------------------------------------------------+\n");
    printf("\t\t                                PLEASE TURN CAPSLOCK ON\n");
    printf("\t\t+-------------------------------------------------------------------------------------------------+\n");
    
    studentinfo *temp = head; //for traversal
    while (temp != NULL)
    {
        // Access the student's information
        char *studentName = temp->studentname;
        int rollNo = temp->rollno;
        int enrollNo = temp->enroll;
        strcpy(temp->subjects[choice - 1].subjectname, subjectName); // copying subject names for switch 
        printf("\tStudent Name  : %s\n", temp->studentname);        //case to the subject name in subject structure
        printf("\tRoll no       : %d\n", temp->rollno);
        printf("\tEnrollment no : %d\n", temp->enroll);
        temp->currentTime = time(NULL);
        printf("\tDate and Time : %s", ctime(&temp->currentTime));
        printf("\tEnter Attendance (P/A): ");
        scanf("%s", &temp->subjects[choice - 1].attendance);
        strupr(temp->subjects[choice - 1].attendance);
        printf("\n");
        // Move to the next student
        temp = temp->next;
    }
}

void displayRecords()
{
    studentinfo *temp = head;
    printf("\nEnter the subject to display record : \n");
    printf("\t\t1. Mathematics-II\n");
    printf("\t\t2. Data Structures\n");
    printf("\t\t3. Basic Electronics\n");
    printf("\t\t4. Applied Physics\n");
    printf("\t\t5. Human Values\n");
    printf("\t\t6. EGD\n");
    int choice;
    printf("Enter : ");
    scanf("%d", &choice);

    char subjectName[20];
    switch (choice)
    {
    case 1:
        strcpy(subjectName, "Mathematics-II");
        break;
    case 2:
        strcpy(subjectName, "Data Structures");
        break;
    case 3:
        strcpy(subjectName, "Basic Electronics");
        break;
    case 4:
        strcpy(subjectName, "Applied Physics");
        break;
    case 5:
        strcpy(subjectName, "Human Values");
        break;
    case 6:
        strcpy(subjectName, "EGD");
        break;
    default:
        printf("Invalid choice!\n");
        return;
    }
    printf("\t+----------------------------------------------------------------------------------------------------+\n");
    printf("\t                              %s ATTENDANCE RECORD                                          \n", subjectName);
    printf("\t+----------------------------------------------------------------------------------------------------+\n");
    if (head == NULL)
    {
        printf("No data available\n");
    }
    else
    {
        printf("\t+---------+---------------------------+----------------------------------+\n");
        printf("\t| Roll No |        Student Name       |      Attendance                  |\n");
        printf("\t+---------+---------------------------+----------------------------------+\n");
        while (temp->next != NULL)
        {
            printf("\t| %-7d | %25s   %10s \n", temp->rollno, temp->studentname, temp->subjects[choice - 1].attendance);
            temp = temp->next;
        }
        printf("\t| %-7d | %25s   %10s \n", temp->rollno, temp->studentname, temp->subjects[choice - 1].attendance);
        printf("\t+---------+---------------------------+----------------------------------+\n");
    }
}

void editAttendance()
{
    studentinfo *search = head;
    int rollno;
    int no;
    printf("\nEnter the subject for which you want to change attendance :\n");
    printf("\t\t1. Mathematics-II\n");
    printf("\t\t2. Data Structures\n");
    printf("\t\t3. Basic Electronics\n");
    printf("\t\t4. Applied Physics\n");
    printf("\t\t5. Human Values\n");
    printf("\t\t6. EGD\n");
    int choice;
    printf("Enter : ");
    scanf("%d", &choice);

    char subjectName[20];
    switch (choice)
    {
    case 1:
        strcpy(subjectName, "Mathematics-II");
        break;
    case 2:
        strcpy(subjectName, "Data Structures");
        break;
    case 3:
        strcpy(subjectName, "Basic Electronics");
        break;
    case 4:
        strcpy(subjectName, "Applied Physics");
        break;
    case 5:
        strcpy(subjectName, "Human Values");
        break;
    case 6:
        strcpy(subjectName, "EGD");
        break;
    default:
        printf("Invalid choice!\n");
        return;
    }
    printf("\nEnter the number of students to change attendance to present : ");
    scanf("%d", &no);
    int correctionlist[no];
    for (int i = 0; i < no; i++)
    {
        printf("\nEnter the roll number of Student (%d) :", i + 1);
        scanf("%d", &correctionlist[i]);
        for (search = head; search != NULL; search = search->next)
        {
            if (correctionlist[i] == search->rollno)
            {
                printf("\n\tStudent Name  : %s\n", search->studentname);
                printf("\tRoll no       : %d\n", search->rollno);
                printf("\tEnrollment no : %d\n", search->enroll);
                printf("\tCourse and Class : %s\n", search->courseandclass);
                printf("\tEnter New Attendance (P/A): ");
                scanf("%s", &search->subjects[choice - 1].attendance);
                strupr(search->subjects[choice - 1].attendance);
            }
        }
        printf("\n");
    }
}

void loadStudentList()
{
    FILE *nameFile, *enrollFile, *rollNoFile;
    nameFile = fopen("name.txt", "r");
    enrollFile = fopen("enrollno.txt", "r");
    rollNoFile = fopen("roll-no.txt", "r");

    if (nameFile == NULL || enrollFile == NULL || rollNoFile == NULL)
    {
        printf("Unable to open file(s).\n");
        return;
    }

    char name[100];
    int enroll;
    int rollNo;
    char courseandclass[20] = "B.Tech ICT-A";
    while (fgets(name, sizeof(name), nameFile) != NULL && fscanf(enrollFile, "%d", &enroll) != EOF && fscanf(rollNoFile, "%d", &rollNo) != EOF)
    {
        name[strcspn(name, "\n")] = '\0'; // Remove the newline character from the name
        studentinfo *info = (struct node *)malloc(sizeof(struct node));
        strcpy(info->studentname, name);
        info->enroll = enroll;
        info->rollno = rollNo;
        strcpy(info->courseandclass, courseandclass);
        if (head == NULL)
        {
            head = info;
            info->next = NULL;
        }
        else
        {
            studentinfo *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            info->next = NULL;
            temp->next = info;
        }
    }
    fclose(nameFile);
    fclose(enrollFile);
    fclose(rollNoFile);
}

void printStudentList()
{
    printf("\t+----------------------------------------------------------------------------------------------------+\n");
    printf("\t|                                            Student List                                            |\n");
    printf("\t+----------------------------------------------------------------------------------------------------+\n");
    printf("\t+---------+---------------------------+----------------------------------+\n");
    printf("\t| Roll No |        Student Name       |      Enrollment No               |\n");
    printf("\t+---------+---------------------------+----------------------------------+\n");

    studentinfo *temp = head;

    while (temp->next != NULL)
    {
        printf("\t| %-7d | %25s   %10d \n", temp->rollno, temp->studentname, temp->enroll);
        temp = temp->next;
    }
    printf("\t| %-7d | %25s   %10d \n", temp->rollno, temp->studentname, temp->enroll);

    printf("\t+---------+---------------------------+----------------------------------+\n");
}
void studentSearch()
{
    studentinfo *search = head;
    int rollno;
    printf("Enter the roll no to get student details : ");
    scanf("%d", &rollno);

    while (search!= NULL)
    {
        if (rollno == search->rollno)
        {
            printf("\n\tStudent Name  : %s\n", search->studentname);
            printf("\tRoll no       : %d\n", search->rollno);
            printf("\tEnrollment no : %d\n", search->enroll);
            printf("\tCourse and Class : %s\n", search->courseandclass);
        }
        search = search->next;
    }
    printf("\n");
}

void exportAttendanceToTxtFile()
{
    char subjectFiles[6][30] = {   //storing the file names in an array
        "maths-attendance.txt",
        "ds-attendance.txt",
        "be-attendance.txt",
        "ap-attendance.txt",
        "egd-attendance.txt",
        "hv-attendance.txt"};

    printf("\tEnter the subject for which you want to export attendance:\n");
    printf("\t\t1. Mathematics-II\n");
    printf("\t\t2. Data Structures\n");
    printf("\t\t3. Basic Electronics\n");
    printf("\t\t4. Applied Physics\n");
    printf("\t\t5. Human Values\n");
    printf("\t\t6. EGD\n");

    int choice;
    printf("Enter: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6)
    {
        printf("Invalid choice!\n");
        return;
    }

    // Open the file for writing
    FILE *file = fopen(subjectFiles[choice - 1], "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    studentinfo *temp = head;
    fprintf(file, "\tCURRENT TIME : %s\n", ctime(&temp->currentTime));
    fprintf(file, "\t+---------+---------------------------+----------------------------------+\n");
    fprintf(file, "\t| Roll No |        Student Name       |      Attendance                  |\n");
    fprintf(file, "\t+---------+---------------------------+----------------------------------+\n");

    // Traverse the student list and write attendance data to the file
    while (temp != NULL)
    {
        fprintf(file, "\t| %-7d | %25s   %10s \n", temp->rollno, temp->studentname, temp->subjects[choice - 1].attendance);
        temp = temp->next;
    }

    fprintf(file, "+-------+--------------------------------+-------------------+-------------+\n");
    fclose(file);
    printf("Attendance exported to '%s' file successfully.\n", subjectFiles[choice - 1]);
}

int main()
{
    int choice;
    loadStudentList(); // to load the data from 3 txt files into the linked list
    do
    {
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                              ATTENDANCE MANAGEMENT SYSTEM                                          |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <1> INSERT ATTENDANCE                                                              |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <2> DISPLAY RECORDS                                                                |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <3> EDIT ATTENDANCE                                                                |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <4> DISPLAY STUDENT DATA                                                           |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <5> SEARCH FOR STUDENT INFORMATION                                                 |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <6> EXPORT ATTENDANCE TO TXT FILE                                                  |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("\t|                 <7> EXIT                                                                           |\n");
        printf("\t+----------------------------------------------------------------------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAttendance(); 
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            editAttendance();
            break;
        case 4:
            printStudentList();
            break;
        case 5:
            studentSearch();
            break;
        case 6:
            exportAttendanceToTxtFile();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    printf("THANK YOU :)");
    return 0;
}