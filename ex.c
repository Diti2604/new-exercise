//iferati22
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    char surname[20];
    int grade;
    float avg;
    struct Student* next;
};

void st(struct Student** head, struct Student** newStudent, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int cnt = 0;
        struct Student* temp;
        temp = (struct Student*)malloc(sizeof(struct Student));
        scanf("%s %s", temp->name, temp->surname);

        while (1)
        {
            scanf("%d", &temp->grade);
            if (temp->grade == -1)
            {
                break;
            }
            sum += temp->grade;
            cnt++;
        }

        if(cnt < 4)
        {
            temp->avg = (float) sum / 4;
        }
        else
        {
            temp->avg = (float)sum / cnt;
        }
        if (i == 0)
        {
            *newStudent = temp;
            *head = *newStudent;
        }
        else
        {
            (*newStudent)->next = temp;
            *newStudent = (*newStudent)->next;
        }
    }
    (*newStudent)->next = NULL;

    struct Student* curr = *head;
    float max = 0;
    struct Student* maximum = NULL;
    while (curr != NULL)
    {
        if (max < curr->avg)
        {
            max = curr->avg;
            maximum = curr;
        }
        curr = curr->next;
    }

    printf("%s %s %.2f\n", maximum->name, maximum->surname, max);
}

int main()
{
    int n;
    struct Student* head = NULL;
    struct Student* newStudent;
    scanf("%d", &n);
    st(&head, &newStudent, n);



    return 0;
}