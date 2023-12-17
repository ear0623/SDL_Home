#pragma once

#include "Box2D.h"

class b2World;

class AGravityComponent
{
public:

	AGravityComponent();
	virtual ~AGravityComponent();


	//Geter
	inline b2Vec2 GetGravity() const { return Gravity2d; }
	inline b2World* GetGravityWorld() const { return GravityWorld;}
	inline b2PolygonShape* GetShape() const { return Shape; }
	inline b2Body* GetBody()const { return Body; }
	inline b2BodyDef GetBodyDef() const { return BodyDef; }
	//Seter
	void SetGravity(const b2Vec2& NewGravity);
	void SetShpae(const b2PolygonShape& shape);
	//
	void CreateBox(float32 SetX, float32 SetY, float32 Size_Wide, float32 Size_Height,float32 Friction_Force,b2BodyType BodyType);
	void CreateShape(float32 SetX, float32 SetY, float32 Size_Wide, float32 Size_Height, float32 Friction_Force);
	void SettingGravity(float32 Index_X, float32 Index_Y) { Gravity2d = { Index_X, Index_Y };}

protected:
	b2BodyDef BodyDef;
	b2Body* Body;
	b2PolygonShape* Shape;
	b2Vec2 Gravity2d;
	b2World* GravityWorld;

};

