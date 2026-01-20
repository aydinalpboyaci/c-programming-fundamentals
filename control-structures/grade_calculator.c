#include <stdio.h>

int main(){
    int mt,final;
    printf("Enter midterm exam score: ");
    scanf("%d", &mt);
    printf("Enter final exam score: ");
    scanf("%d", &final);
    printf("You %s the course", ((mt+final) /2 >= 50) ? "pass" : "fail");

    return 0;
}