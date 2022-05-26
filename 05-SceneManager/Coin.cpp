#include "Coin.h"

void CCoin::Render()
{
	if (!isAppear || isDeleted) {
		return;
	}
	animation_set->at(0)->Render(x, y);

	//RenderBoundingBox();
}

CCoin::CCoin(int tag) : CGameObject() {
	if (tag == COIN_TYPE_QUESTION_BRICK)
		isAppear = false;
	else
		isAppear = true;
	state = COIN_STATE_IDLE;
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}

void CCoin::SetState(int state) {
	CGameObject::SetState(state);
	switch (state)
	{
	case COIN_STATE_IDLE:
		vx = vy = 0;
		break;
	}
}