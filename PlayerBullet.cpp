#include "PlayerBullet.h"
#include<cassert>

void PlayerBullet::Initialize(Model* model, Vector3 pos) { 
	assert(model);
	model_ = model;

	textureHandle_ = TextureManager::Load("white1x1.png");
	worldTransform_.Initialize();
	worldTransform_.translation_ = pos;
}

void PlayerBullet::Update() { worldTransform_.UpdateMatrix(); }

void PlayerBullet::Draw(ViewProjection& view) {
	model_->Draw(worldTransform_, view, textureHandle_);
}
