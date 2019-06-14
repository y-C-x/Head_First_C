#include <stdio.h>

int main()
{
	float latitude;
	float longtitude;
	char info[80];
	int started = 0;

	puts("data=[");

	while (scanf("%f,%f,%79[^\n]", &latitude, &longtitude, info) == 3)
	{
		if (started)
			printf(",\n");
		else
			started = 1;

		if ((latitude < -90.0) || (latitude > 90.0))
		{
			fprintf(stderr, "Invalid latitude: %f\n", latitude);
			return 2;
		}
		if ((longtitude < -180.0) || (longtitude > 180.0))
		{
			fprintf(stderr, "Invalid longtitude: %f\n", longtitude);
			return 2;
		}
		printf("{latitude: %f, longtitude: %f, info: '%s'}", latitude, longtitude, info);
	}
	puts("\n]");
	return 0;
}