#include "PiranhaPlantFire.h"
#include "PlayScene.h"

PiranhaPlantFire::PiranhaPlantFire(int tag) {
	this->tagType = tag;
	SetState(PIRANHAPLANTFIRE_STATE_DARTING);
}

void PiranhaPlantFire::Render()
{
	int ani = PIRANHAPLANTFIRE_STATE_DARTING;
	animation_set->at(ani)->Render(x, y);
}

void PiranhaPlantFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	CGameObject::Update(dt);
	y += vy * dt;

	CMario* mario = ((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	/*DebugOut(L"Mario %d\n", mario);*/
	float marioLeft, marioTop, marioRight, marioBottom;
	mario->GetBoundingBox(marioLeft, marioTop, marioRight, marioBottom);
	DebugOut(L"Mario left %d\n", marioLeft, marioTop, marioRight, marioBottom);
	int marioLevel = mario->GetLevel();
	DebugOut(L"Mario level %d\n", marioLevel);

}


void PiranhaPlantFire::GetBoundingBox(float& left, float& top,
	float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + PIRANHAPLANTFIRE_BBOX_WIDTH;
	bottom = y + PIRANHAPLANTFIRE_BBOX_HEIGHT;
}

void PiranhaPlantFire::SetState(int state) {
	CGameObject::Update(state);
	switch (state)
	{
	case PIRANHAPLANTFIRE_STATE_DARTING:
		vy = 0;
		break;
	}
}
