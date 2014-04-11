// BattleUnitTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include "gtest\gtest.h"
#include "..\Assignment1\IBehaviour.h"

TEST(DamageBehaviour,DamageBehaviourTest)
{
	DamageBehaviour *damageBehaviour = new DamageBehaviour(100);
	ASSERT_TRUE(true,true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

