#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	char id[10];
	char fullName[50];
	float salary1; // Basic salary
	float salary2; // Overtime pay
	float salary3; // Bonus
} Employee;

int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	getchar();
	Employee nv[1000];
	for (int i = 0; i < n; i ++) {
		printf("nv%d:\n", i + 1);
		printf("Enter id: ");
		fgets(nv[i].id, sizeof(nv[i].id), stdin);
		nv[i].id[strcspn(nv[i].id, "\n")] = '\0';
		printf("Fullname: ");
		fgets(nv[i].fullName, sizeof(nv[i].fullName), stdin);
		nv[i].fullName[strcspn(nv[i].fullName, "\n")] = '\0';
		printf("Salary1: ");
		scanf("%f", &nv[i].salary1);
		printf("Salary2: ");
		scanf("%f", &nv[i].salary2);
		printf("Salary3: ");
		scanf("%f", &nv[i].salary3);
		getchar();
	}
	float total = 0;
	for (int i = 0; i < n; i ++) {
		printf("\nnv%d: %s; %s; %f; %f; %f =>", i + 1, nv[i].id, nv[i].fullName, 
		nv[i].salary1, nv[i].salary2, nv[i].salary3);
		total = nv[i].salary1 + nv[i].salary2 + nv[i].salary3;
		if (total >= 10000000) {
			printf(" High");
		} else {
			printf(" Low");
		}
	}
	return 0;
}