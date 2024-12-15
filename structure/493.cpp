#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    char id[6]; // 学号
    char name[11]; // 姓名
    int scores[3]; // 三门课程的成绩
    int total; // 总分
};

void readStudents(struct Student students[], int n);
void calculateTotals(struct Student students[], int n);
struct Student findHighestTotal(struct Student students[], int n);

int main() {
    int n;
    struct Student students[MAX_STUDENTS];
    struct Student highest;

    scanf("%d", &n);
    readStudents(students, n);
    calculateTotals(students, n);
    highest = findHighestTotal(students, n);

    printf("%s %s %d", highest.name, highest.id, highest.total);

    return 0;
}

void readStudents(struct Student students[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", students[i].id, students[i].name, &students[i].scores[0], &students[i].scores[1], &students[i].scores[2]);
    }
}

void calculateTotals(struct Student students[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        students[i].total = 0;
        for (j = 0; j < 3; j++) {
            students[i].total += students[i].scores[j];
        }
    }
}

struct Student findHighestTotal(struct Student students[], int n) {
    int i, maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (students[i].total > students[maxIndex].total) {
            maxIndex = i;
        }
    }
    return students[maxIndex];
}
