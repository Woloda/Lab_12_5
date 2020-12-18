#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.5/Lab_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab125
{
	TEST_CLASS(UnitTestLab125)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* top = NULL;
			Spusok* top1 = NULL;

			int x;
			x = 8;
			Creata(top, x);
			x = -1;
			Creata(top, x);
			x = 10;
			Creata(top, x);
			x = -2;
			Creata(top, x);

			Spusok* T = top;

			T = top;
			Copy(top, top1, T);

			T = top1;
			Spusok* G = top1;
			Process(top1, T, G, 4);

			T = top1;
			int l = T->inf;
			Assert::AreEqual(l, -2);
		}
	};
}
