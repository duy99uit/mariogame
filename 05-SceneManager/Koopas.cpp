#include "Koopas.h"

CKoopas::CKoopas(int tag)
{
	this->start_x = x;
	this->start_y = y;
	this->nx = -1;
	this->SetState(KOOPAS_STATE_WALKING);
}

void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	vy += ay * dt;
	vx += ax * dt;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopas::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = KOOPAS_VY;
		ay = vy;
	}
	else
	{
		if (e->nx != 0 && e->obj->IsBlocking())
		{
			vx = -vx;
			nx = -nx;
		}
	}
}

void CKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + KOOPAS_BBOX_WIDTH;
	bottom = y + KOOPAS_BBOX_HEIGHT;
}

void CKoopas::Render()
{
	int ani = -1;
	if (state == KOOPAS_SHELL_IDLE)
		ani = KOOPAS_ANI_SHELL_UP;
	else if (state == KOOPAS_SHELL_MOVING)
		ani = KOOPAS_ANI_SHELL;
	else if (state == KOOPAS_SPIN)
	{
		if (vx < 0)
			ani = KOOPAS_ANI_SPIN_LEFT;
		else
			ani = KOOPAS_ANI_SPIN_RIGHT;
	}
	else {
		if (this->nx < 0)
			ani = KOOPAS_ANI_WALKING_LEFT;
		else
			ani = KOOPAS_ANI_WALKING_RIGHT;
	}

	animation_set->at(ani)->Render(x, y);
	RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_WALKING:
		vx = this->nx * KOOPAS_WALKING_SPEED;
		//drop out of block
		vy = KOOPAS_WALKING_SPEED;
		break;

	case KOOPAS_SPIN:
		vx = KOOPAS_WALKING_SPEED;
		break;
	case KOOPAS_SHELL_IDLE:
		// idle
		vx = 0;
		vy = 0;
		break;
	case KOOPAS_SHELL_MOVING:
		vy = -KOOPAS_SHELL_DEFLECT_SPEED;
		vx = KOOPAS_WALKING_SPEED;
		break;
	}
}