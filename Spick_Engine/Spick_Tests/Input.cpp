#include "pch.h"
#include "CppUnitTest.h"
#include "API_Headers/Importation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpickTests
{
	TEST_CLASS(InputTests)
	{
	public:

		TEST_METHOD(Check_If_The_Given_Mouse_Button_Is_Held_Down)
		{
			auto anyKey = 0;
			// Randomise a key from a enum
			spic::Importation inputManager;

			Assert::AreEqual(anyKey, 0);

		}
	};
}