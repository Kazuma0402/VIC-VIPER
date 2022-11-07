#include "Math.h"

float Math::Det(XMFLOAT3 a, XMFLOAT3  b, XMFLOAT3  c)
{
	return a.x * b.y * c.z +
		   a.z * b.x * c.y +
		   a.y * b.z * c.x -
		   a.z * b.y * c.x -
		   a.y * b.z * c.y -
		   a.x * b.z * c.y;
}

bool Math::Intersect(XMFLOAT3 start, XMFLOAT3 dir, XMFLOAT3 v0, XMFLOAT3 v1, XMFLOAT3 v2, float* length)
{
	XMFLOAT3 e01;
	e01.x = v1.x - v0.x;
	e01.y = v1.y - v0.y;
	e01.z = v1.z - v0.z;
	
	XMFLOAT3 e02;
	e02.x = v2.x - v0.x;
	e02.y = v2.y - v0.y;
	e02.z = v2.z - v0.z;

	float u, v, l;
	dir.x = -(dir.x);
	dir.y = -(dir.y);
	dir.z = -(dir.z);

	XMFLOAT3 w = XMFLOAT3(start.x - v0.x, start.y - v0.y, start.z - v0.z);

	u = Math::Det(w, e02, dir) / Math::Det(e01, e02, dir);
	v = Math::Det(e01, w, dir) / Math::Det(e01, e02, dir);
	l = Math::Det(e01, e02, w) / Math::Det(e01, e02, dir);

	*length = l;

	if (0 <= u && u <= 1 && 0 <= v && v <= 1 && u + v <= 1 && 0 <= l)
	{
		return true;
	}
	else
	{
		return false;
	}
}
