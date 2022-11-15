#pragma once
#ifndef VECTOR_H
#define VECTOR_H

class vec3
{
public:
	float x, y, z;

public:
	vec3();
	vec3(float x, float y, float z);
	vec3(float vec[]);

	vec3 operator+(const vec3& operand);
	vec3 operator-(const vec3& operand);
	vec3 operator*(const float& operand); // Scalar multiply
	vec3 operator/(const float& operand); // Scalar devide

	float GetLength();

public:
	static vec3 Normalize(vec3 vec);
	static float Dot(vec3 a, vec3 b);
	static vec3 Cross(vec3 a, vec3 b);
	static vec3 ProjectionAB(vec3 a, vec3 b);
	static vec3 VerticalAB(vec3 a, vec3 b);
	static float GetAngleAB(vec3 a, vec3 b);
};

#endif