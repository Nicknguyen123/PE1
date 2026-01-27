#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
	char str[1000];
	printf("Type string: ");
	fgets(str, sizeof(str), stdin);
	puts(str);
	int count = 0;
	for (int i = 0; str[i] != '\n'; i ++) {
		char c = str[i];
		if (c >= 'a' && c <= 'z') {
			count ++;
		}
	}
	printf("%d", count);
	return 0;
}