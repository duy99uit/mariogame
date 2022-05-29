#include "PiranhaPlant.h"

void PiranhaPlant::GetBoundingBox(float& left, float& top,
	float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + PIRANHAPLANT_BBOX_WIDTH;
	bottom = y + PIRANHAPLANT_BBOX_HEIGHT;
}

PiranhaPlant::PiranhaPlant()
{
	SetState(PIRANHAPLANT_ANI_IDLE);
}

void PiranhaPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	CGameObject::Update(dt, coObjects);

	x += vx * dt;
	y += vy * dt;
}

void PiranhaPlant::Render()
{
	int ani = PIRANHAPLANT_ANI_IDLE;

	animation_set->at(ani)->Render(x, y);
	RenderBoundingBox();
}

void PiranhaPlant::SetState(int _state)
{
	CGameObject::SetState(_state);
	switch (_state)
	{
	case PIRANHAPLANT_ANI_IDLE:
		vy = vx = 0;
		break;
	}
}