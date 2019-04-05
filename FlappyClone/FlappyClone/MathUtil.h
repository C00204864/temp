#ifndef MATHUTIL_H
#define MATHUTIL_H

static float randomBetweenTwoFloats(float a, float b)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

static int randomBetweenTwoInts(int a, int b)
{
	return std::rand() % (b + 1 - a) + a;
}

#endif // !MATHUTIL_H
