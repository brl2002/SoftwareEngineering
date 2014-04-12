// BattleUnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest\gtest.h"
#include "BehaviourTest.h"
#include "AttributeHandlerTest.h"
#include "CharacterTest.h"

TEST(BehaviourTest, BehaviourTesting)
{
	BehaviourTest behaviour = BehaviourTest(100);
	ASSERT_TRUE(true, behaviour.GetName() == "damage");
}

TEST(PlayerTest,MyFirstPlayerTest)
{
	BehaviourTest behaviour = BehaviourTest(100);
	CharacterTest player = CharacterTest();
	CharacterTest enemy = CharacterTest();
	behaviour.TakeActionTest(&player, &enemy);
	ASSERT_TRUE(true, behaviour.GetResult());
}

TEST(AttributeHandlerTest,HandlerTest)
{
	AttributeHandlerTest handler = AttributeHandlerTest();
	handler.AddAttribute(new HealthTest());
	HealthTest *health = handler.GetAttribute<HealthTest*>();
	ASSERT_TRUE(true, health != NULL);
}

TEST(CharacterTest,CharacterHeavyAttackDamageTest)
{
	CharacterTest player = CharacterTest();
	player.AddPart(new PartTest(100, "player"));
	player.AddBehaviour(new HeavyAttackTest(10));
	player.AddBehaviour(new LightAttackTest(10, 6));
	player.AddBehaviour(new BlockTest(5, 5));

	CharacterTest enemy = CharacterTest();
	enemy.AddPart(new PartTest(20, "head"));
	enemy.AddPart(new PartTest(100, "body"));
	enemy.AddBehaviour(new HeavyAttackTest(10));

	player.SelectCurrentEnemyPart(&enemy);
	player.SwitchBehaviour(0);
	player.TakeAction(&enemy);

	ASSERT_TRUE(true, enemy.GetCurrentPart(0)->GetBehaviour()->GetAttributeHandler()->GetAttribute<HealthTest*>()->GetValue() == 75);
}

TEST(CharacterTest,CharacterLightAttackDamageTest)
{
	CharacterTest player = CharacterTest();
	player.AddPart(new PartTest(100, "player"));
	player.AddBehaviour(new HeavyAttackTest(10));
	player.AddBehaviour(new LightAttackTest(10, 6));
	player.AddBehaviour(new BlockTest(5, 5));

	CharacterTest enemy = CharacterTest();
	enemy.AddPart(new PartTest(20, "head"));
	enemy.AddPart(new PartTest(100, "body"));
	enemy.AddBehaviour(new HeavyAttackTest(10));

	player.SelectCurrentEnemyPart(&enemy);
	player.SwitchBehaviour(1);
	player.TakeAction(&enemy);

	ASSERT_TRUE(true, enemy.GetCurrentPart(0)->GetBehaviour()->GetAttributeHandler()->GetAttribute<HealthTest*>()->GetValue() == 13);
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

