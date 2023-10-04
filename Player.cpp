#include "Player.h"
#include <cassert>
Player::~Player() {}
void Player::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);
	model_ = model;
	texHamdle_ = textureHandle;
	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	worldTransform_.Initialize();
}

void Player::Update() {
	Vector3 move = {0, 0, 0};

	const float kCharacterSpeed = 0.2f;

	if (input_->PushKey(DIK_LEFT)) {
		move.x -= kCharacterSpeed;
	} if (input_->PushKey(DIK_RIGHT)) {
		move.x += kCharacterSpeed;
	}

	if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;
	} if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}
	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z += move.z;
	Rotate();
	worldTransform_.UpdateMatrix();

	Attack();
	for (PlayerBullet*bullet : bullets_){
		bullet->Update();
	}
}

void Player::Draw(ViewProjection& view) {
	model_->Draw(worldTransform_,view,texHamdle_); 
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw(view);
	}

}

void Player::Rotate() 
{ 
	const float kRotSpeed = 0.02f; 
	if (input_->PushKey(DIK_A)) {
		worldTransform_.rotation_.y -= kRotSpeed;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.rotation_.y += kRotSpeed;
	}
}

void Player::Attack() { 
	if (input_->PushKey(DIK_SPACE)){
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(model_,worldTransform_.translation_);
		bullets_.push_back(newBullet);

	}

}

