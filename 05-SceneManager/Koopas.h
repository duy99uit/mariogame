#pragma once
#include "GameObject.h"

#define KOOPAS_BBOX_WIDTH				16
#define KOOPAS_BBOX_HEIGHT				20

#define KOOPAS_STATE_WALKING	100
#define KOOPAS_SHELL_IDLE	200
#define KOOPAS_SPIN	300
#define KOOPAS_SHELL_MOVING	400

#define KOOPAS_WALKING_SPEED			0.03f

#define KOOPAS_ANI_WALKING_RIGHT	0
#define KOOPAS_ANI_SPIN_RIGHT		1
#define KOOPAS_ANI_WALKING_LEFT		2
#define KOOPAS_ANI_SPIN_LEFT		3
#define KOOPAS_ANI_SHELL			4
#define KOOPAS_ANI_SHELL_UP			5

#define KOOPAS_SHELL_DEFLECT_SPEED		0.4f
#define KOOPAS_GREEN		0
#define KOOPAS_RED			1

#define KOOPAS_VY  0.002f;

class CKoopas : public CGameObject
{
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	float ax;
	float ay;
public:

	CKoopas(int tagType);

	virtual void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

};