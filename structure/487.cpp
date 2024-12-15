#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[21];
    int score;
};

void readStudents(struct Student students[], int n);
void countScores(struct Student students[], int n, int counts[]);
void printCounts(int counts[]);

int main() {
    int n, i;
    struct Student students[MAX_STUDENTS];
    int counts[3] = {0}; // 用于存储每个成绩段的学生人数

    scanf("%d", &n);
    readStudents(students, n);
    countScores(students, n, counts);
    printCounts(counts);

    return 0;
}

void readStudents(struct Student students[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
}

void countScores(struct Student students[], int n, int counts[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (students[i].score >= 80 && students[i].score <= 100) {
            counts[0]++;
        } else if (students[i].score >= 60 && students[i].score <= 79) {
            counts[1]++;
        } else {
            counts[2]++;
        }
    }
}

void printCounts(int counts[]) {
    printf("%d %d %d", counts[0], counts[1], counts[2]);
}
