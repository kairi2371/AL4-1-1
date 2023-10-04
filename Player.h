#include "Input.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"PlayerBullet.h"
#include<list>
#pragma once
class Player {
public:
	~Player();
	void Initialize(Model* model, uint32_t textureHandle);
	void Update();
	void Draw(ViewProjection& view);

private:
	void Rotate();
	void Attack();


private:
	Model* model_ = nullptr; // メンバ変数
	WorldTransform worldTransform_;
	Input* input_ = nullptr;
	uint32_t texHamdle_ = 0u;
	std::list<PlayerBullet*> bullets_;
	
};
