#include "MushRoom.h"
#include "debug.h"


CMushroom::CMushroom(int type) {
	SetAppear(false);
	typeMushroom = type;
}

void CMushroom::Render() {
	if (isAppear && !isDeleted) {
		animation_set->at(0)->Render(x, y);
	}
	RenderBoundingBox();
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isDeleted) return;

	if (state == MUSHROOM_STATE_UP)
	{
		y += vy * dt;
		if (start_y - y >= MUSHROOM_BBOX_HEIGHT)
		{
			vy = 0;
			y = start_y - MUSHROOM_BBOX_HEIGHT - 0.1f;

			//mushroom move right 
			SetState(MUSHROOM_STATE_RIGHT);
			/*DebugOut(L"Mushroom state right running!\n");*/
			
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::SetState(int state) {
	CGameObject::SetState(state);
	switch (state)
	{
	case MUSHROOM_STATE_IDLE:
		vy = vx = 0;
		break;
	case MUSHROOM_STATE_UP:
		vy = -0.05f;
		start_y = y;
		break;
	case MUSHROOM_STATE_RIGHT:
		vy = MUSHROOM_GRAVITY;
		vx = MUSHROOM_SPEED;
		DebugOut(L"Vao day \n", vy, vx);
		break;
	}
}
