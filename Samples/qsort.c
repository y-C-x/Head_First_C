#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_soures(const void *score_a, const void *score_b)
{
	int a = *(int *)score_a;
	int b = *(int *)score_b;
	return a - b;
}

int compare_soures_desc(const void *score_a, const void *score_b)
{
	int a = *(int *)score_a;
	int b = *(int *)score_b;
	return b - a;
}

typedef struct
{
	int width;
	int height;
} rectangle;

int compare_areas(const void *a, const void *b)
{
	rectangle *rect_A = (rectangle *)a;
	rectangle *rect_B = (rectangle *)b;
	int area_A = (rect_A->height) * (rect_A->width);
	int area_B = (rect_B->height) * (rect_B->width);
	return area_A - area_B;
}

int compare_names(const void *a, const void *b)
{
	char **strA = (char **)a;
	char **strB = (char **)b;
	return strcmp(*strA, *strB);
}

int compare_areas_desc(const void *a, const void *b)
{
	return compare_areas(b, a);
}

int compare_names_desc(const void *a, const void *b)
{
	return compare_names(b, a);
}

int main()
{
	int scores[] = {543, 323, 32, 554, 11, 3, 112}; // scores is a pointer
	int i;
	qsort(scores, 7, sizeof(int), compare_soures_desc);
	puts("These are the scores in order: ");
	for (i = 0; i < 7; i++)
	{
		printf("Score = %i\n", scores[i]);
	}

	char *names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort(names, 4, sizeof(char *), compare_names);
	puts("These are the names in order:");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", names[i]);
	}
	return 0;
}