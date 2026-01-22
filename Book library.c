#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	char id[10];
	char title[50];
	char author[30];
	int year;
} Information;

void input(int n, Information *p) {
	for (int i = 0; i < n; i ++) {
		printf("BOOK %d: ", i + 1);
		printf("\nID: ");
		fgets(p[i].id, sizeof(p[i].id), stdin);
		p[i].id[strcspn(p[i].id, "\n")] = '\0';
		printf("TITLE: ");
		fgets(p[i].title, sizeof(p[i].title), stdin);
		p[i].title[strcspn(p[i].title, "\n")] = '\0';
		printf("AUTHOR: ");
		fgets(p[i].author, sizeof(p[i].author), stdin);
		p[i].author[strcspn(p[i].author, "\n")] = '\0';
		printf("YEAR: ");
		scanf("%d", &p[i].year);
		getchar();
	}
}

void display(int n, Information *p) {
	for (int i = 0; i < n; i ++) {
		printf("\n%s; %s; %s; %d", p[i].id, p[i].title, p[i].author, p[i].year);
	}
}

void average(int n, Information *p) {
	double average = 0;
	for (int i = 0; i < n; i ++) {
		average += p[i].year;
	}
	printf("\nAverage year: %.2lf", average / n);
}

void findLatestYear(int n, Information *p) {
	int max = p[0].year;
	for (int i = 1; i < n; i ++) {
		if (p[i].year > max) {
			max = p[i].year;
		}
	}
	for (int i = 0; i < n; i ++) {
		if (p[i].year == max) {
			printf("%s; %s; %s; %d", p[i].id, p[i].title, p[i].author, p[i].year);
		}
	}
}

int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	getchar();
	Information book[1000];
	input(n, book);
	int opt;
	printf("Opt: ");
	scanf("%d", &opt);
	switch (opt) {
		case 1:
			printf("List of books: ");
			display(n, book);
			break;
		case 2:
			display(n, book);
			average(n, book);
			break;
		case 3:
			findLatestYear(n, book);
			break;
		default:
			printf("Options is not valid");
	}
}