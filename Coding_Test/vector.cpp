#if 0
#include <stdio.h>

double vector_dotp(double x[], double y[]);

int main(void) {

	double x[3] = {

		1.0, 2.0, 3.0

	}

	;

	double y[3] = {

		1.0, 2.0, 3.0

	}

	;

	double value;

	value = vector_dotp(x, y);

	printf("%f\n", value);

	v = sqrt(Vector1.x * Vector1.x + Vector1.y * Vector1.y + Vector1.z * Vector1.z);
	Vector1.x /= v;
	Vector1.y /= v;
	Vector1.z /= v;

	v = sqrt(Vector2.x * Vector2.x + Vector2.y * Vector2.y + Vector2.z * Vector2.z);
	Vector2.x /= v;
	Vector2.y /= v;
	Vector2.z /= v;

	///< 내적하기
	float theta;
	float degree;

	theta = Vector1.x * Vector2.x + Vector1.y * Vector2.y + Vector1.z * Vector2.z;

	theta = acos(theta);

	degree = theta * (180 / 3.141592);

	float n_x, n_y, n_z;

	n_x = Vector1.y * Vector2.z - Vector1.z * Vector2.y;
	n_y = Vector1.z * Vector2.x - Vector1.x * Vector2.z;
	n_z = Vector1.x * Vector2.y - Vector1.y * Vector2.x;


	return 0;

}

double vector_dotp(double x[], double y[]) {

	int i;

	double result;

	result = 0.0;

	for (i = 0;i < 3;i++)

		result += x[i] * y[i];

	return result;

}
#endif