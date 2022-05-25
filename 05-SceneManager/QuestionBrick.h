#pragma once
#include "GameObject.h"

#define QUESTION_BRICK_NORMAL	0
#define QUESTION_BRICK_ANI_NORMAL	0

#define QUESTION_BRICK_HIT	1
#define QUESTION_BRICK_ANI_HIT	1

#define QUESTIONBRICK_SPEED		0.05f
#define QUESTIONBRICK_PUSH_MAX_HEIGHT 8



class QuestionBrick :public CGameObject
{
	int tagType;

public:
	CGameObject* obj = NULL;
	QuestionBrick(int tagType);

	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsAllowCollision() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetState(int state);

	void startPushedUp();
	void stopPushedUp();


};