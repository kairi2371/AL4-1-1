#include "MyMath.h"
#include <math.h>

//float Length(const Vector3& v) { return 0.0f; }
//
//Vector3 Normalize(const Vector3& v) { return Vector3(); }
//
//Matrix4x4 Inverse(const Matrix4x4& m) { return Matrix4x4(); }
//
//Matrix4x4
//    MakeViewportMatrix(float left, float top, float width, float height, float nearZ, float farZ) {
//	return Matrix4x4();
//}
//
//Vector3 Transform(const Vector3& v, const Matrix4x4& m) { return Vector3(); }
//
//Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m) { return Vector3(); }



Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {
	Matrix4x4 matScale = {
	    {
			scale.x, 0, 0, 0,
			0, scale.y, 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		},
	};
	Matrix4x4 matRotX = {
	    {
			1, 0, 0, 0, 
			0, cosf(rot.x), sinf(rot.x), 0, 
			0, -sinf(rot.x), cosf(rot.x), 0,
			0, 0, 0, 1
		},
	};
	Matrix4x4 matRotY = {
	    {
			cosf(rot.y), 0, -sinf(rot.y), 0,
			0, 1, 0, 0,
			sinf(rot.y),0, -cosf(rot.y),0,
			0, 0, 0, 1
		},
	};
	Matrix4x4 matRotZ = {
	    {
			cosf(rot.z), sinf(rot.z), 0, 0, 
			-sinf(rot.z), cosf(rot.z), 0,0,
			0, 0, 1, 0, 
			0, 0, 0, 1
		},
	};
	Matrix4x4 matTrans = {
	    { 
			1, 0, 0, 0,
			0,1, 0, 0,
			0, 0, 1, 0,
			translate.x, translate.y, translate.z, 1,
		},
	};
	Matrix4x4 matRot = Multipy(Multipy(matRotZ, matRotX), matRotY);
	
	return Multipy(Multipy(matScale,matRot),matTrans);
}

Matrix4x4 Multipy(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}

	return result;
}
