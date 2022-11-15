#if 0
#include <stdio.h>
#include <math.h>
#include "Vector.h"

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}
vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
vec3::vec3(float vec[])
{
	this->x = vec[0];
	this->y = vec[1];
	this->z = vec[2];
}

vec3 vec3::operator+(const vec3& operand)
{
	vec3 result;
	result.x = x + operand.x;
	result.y = y + operand.y;
	result.z = z + operand.z;

	return result;
}
vec3 vec3::operator-(const vec3& operand)
{
	vec3 result;
	result.x = x - operand.x;
	result.y = y - operand.y;
	result.z = z - operand.z;

	return result;
}
vec3 vec3::operator*(const float& operand)
{
	vec3 result;
	result.x = x * operand;
	result.y = y * operand;
	result.z = z * operand;

	return result;
}
vec3 vec3::operator/(const float& operand)
{
	vec3 result;
	result.x = x / operand;
	result.y = y / operand;
	result.z = z / operand;

	return result;
}

float vec3::GetLength()
{
	return sqrt((x * x) + (y * y) + (z * z));
}



vec3 vec3::Normalize(vec3 vec)
{
	float length = vec.GetLength();
	if (length == 0)
	{
		return vec;
	}
	return (vec / length);
}
float vec3::Dot(vec3 a, vec3 b)
{
	float result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return result;
}
vec3 vec3::Cross(vec3 a, vec3 b)
{
	vec3 result = vec3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x));
	return result;
}
vec3 vec3::ProjectionAB(vec3 a, vec3 b)
{
	if (b.GetLength() == 0)
	{
		return vec3(0, 0, 0);
	}
	vec3 result = b * (Dot(a, b) / (b.GetLength() * b.GetLength()));
	return result;
}
vec3 vec3::VerticalAB(vec3 a, vec3 b)
{
	vec3 result = a - ProjectionAB(a, b);
	return result;
}
float vec3::GetAngleAB(vec3 a, vec3 b)
{
	float result = radToDeg(acosf(Dot(a, b) / (a.GetLength() * b.GetLength())));
	return result;
}

double vector_dotp(double x[], double y[]);

struct vector2 {
	double x, y;
	//생성자
	vector2(double _x, double _y) {
		x = _x, y = _y;
	}
	//외적
	double cross(const vector2& other) const {
		return x * other.y - y * other.x;
	}
};

// 두 선분의 교차 여부를 판별과 볼록 껍질 찾기(convex hull)
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

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