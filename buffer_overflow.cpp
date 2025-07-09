#include <cstdio>

int read_from(const char s[], int pos, int size);
int write_to(char c, char s[], int pos, int size);

int main() {
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	int lower_len = sizeof(lower) / sizeof(char);
	int upper_len = sizeof(upper) / sizeof(char);

	write_to('d', lower, 3, lower_len);
	write_to('D', upper, 3, upper_len);

	printf("lower = %s\n", lower);
	printf("upper = %s\n", upper);

	char letter_d = lower[3];
	char letter_D = upper[3];

	printf("Caractère modifié dans lower[3] = %c\n", letter_d);
	printf("Caractère modifié dans upper[3] = %c\n", letter_D);

	read_from(lower, 7, lower_len); // volontairement hors-limite

	write_to('g', lower, 1, lower_len);
	printf("lower après écriture = %s\n", lower);

	return 0;
}

int read_from(const char s[], int pos, int size) {
	if (pos < size) {
		for (int i = 0; i < pos; i++)
			printf("%c", s[i]);
		printf("\n");
		return 0;
	} else {
		printf("Erreur : tentative de lecture hors limites à l'indice %d (max autorisé : %d)\n", pos, size - 1);
		return -1;
	}
}

int write_to(char c, char s[], int pos, int size) {
	if (pos >= 0 && pos < size - 1) { // éviter d’écraser le caractère '\0'
		s[pos] = c;
		return 0;
	} else {
		printf("Erreur : écriture hors limites à l'indice %d (max autorisé : %d)\n", pos, size - 2);
		return -1;
	}
}