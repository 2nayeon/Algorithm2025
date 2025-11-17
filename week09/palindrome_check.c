#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int palindrome_check(char* cword);

main() {

	char wordset[][10] = { "nursesrun", "mom", "father", "rotator", "mother", "quit" };
	int k = 0, ans;

	while (strcmp(wordset[k], "quit")) {
		ans = palindrome_check(wordset[k]);
		if (ans == 1) printf("%s : True\n", wordset[k]);
		else printf("%s : False\n", wordset[k]);
		k++;
	}
}

int palindrome_check(char* cword) {
	int slen, k;

	slen = strlen(cword);
	for (k = 0; k < slen / 2; k++) {
		if (cword[k] != cword[slen - (k + 1)])
			return 0;
	}

	return 1;
}