#include "UMyQueryCallback.h"

UMyQueryCallback::UMyQueryCallback()
{
}

UMyQueryCallback::~UMyQueryCallback()
{
}

bool UMyQueryCallback::ReportFixture(b2Fixture* fixture)
{
	return true;
}
