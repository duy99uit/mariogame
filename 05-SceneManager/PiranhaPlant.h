#pragma once
#include "GameObject.h"

#define PIRANHAPLANT_BBOX_WIDTH					20
#define PIRANHAPLANT_BBOX_HEIGHT				24

#define PIRANHAPLANT_ANI_IDLE	0

// x, y old value is 358	348

class PiranhaPlant :
	public CGameObject
{

public:

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	PiranhaPlant();
};