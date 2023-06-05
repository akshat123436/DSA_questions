#include <stdio.h>

struct student{
    char name[30];
    int class;
    int rollno;
    int physics,chemistry,maths;
};

int main(int argc, char const *argv[])
{
    struct student stu_list[2];

    for(int i = 0;i<2;i++){
        printf("Enter name, class, rollno, marks of physics,chemistry and maths\n");
        scanf("%[^\n]%*c",&stu_list[i].name);
        scanf("%d%d%d%d%d",&stu_list[i].class,&stu_list[i].rollno,&stu_list[i].physics,&stu_list[i].chemistry,&stu_list[i].maths);
        getchar();
    }
    for(int i = 0;i<2;i++){
        printf("Name of %d student is - %s, class - %d, rollno - %d\nphysics marks - %d, chemistry marks - %d, maths marks - %d\n----------Total Marks = %d ----------\n\n",i+1,stu_list[i].name,stu_list[i].class,stu_list[i].rollno,stu_list[i].physics,stu_list[i].chemistry,stu_list[i].maths,stu_list[i].physics+stu_list[i].chemistry+stu_list[i].maths);
    }

    return 0;
}
