#pragma once
#include"Model.h"
#include"WorldTransform.h"
class PlayerBullet {
public:
	void Initialize(Model* model, Vector3 pos);
	void Update();
	void Draw(ViewProjection& view);

private:
	Model* model_ = nullptr; // メンバ変数
	WorldTransform worldTransform_;
	uint32_t textureHandle_ = 0u;
};

