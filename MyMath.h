#include "Vector3.h"
#include "Matrix4x4.h"
#pragma once

////ノルム(長さ)を求める
//float Length(const Vector3& v);
////正規化する
//Vector3 Normalize(const Vector3 & v);
////逆行列を求める
//Matrix4x4 Inverse(const Matrix4x4& m);
//
////ビューポート行列の作成
//Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float nearZ, float farZ);
//
////座標変換(w除算あり)
//Vector3 Transform(const Vector3& v, const Matrix4x4& m);
////ベクトル変換
//Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

//アフィン変換行列の作成
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);
Matrix4x4 Multipy(const Matrix4x4& m1, const Matrix4x4& m2);
