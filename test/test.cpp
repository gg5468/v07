
#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;



namespace UnitTests
{
	TEST_CLASS(MoneyTests)
	{
	public:
		TEST_METHOD(zero)
		{
			money m1(0, 0);
			money m2(0, 0);
			m1 += m2;
			Assert::AreEqual(0, m1.get_eur());
			Assert::AreEqual(0, m1.get_ct());
		}

		TEST_METHOD(overflow)
		{
			money m1(9, 60);
			money m2(0, 60);
			m1 += m2;
			Assert::AreEqual(10, m1.get_eur());
			Assert::AreEqual(20, m1.get_ct());
		}

		TEST_METHOD(underflow)
		{
			money m1(0, 50);
			money m2(1, 0);
			m1 -= m2;
			Assert::AreEqual(-1, m1.get_eur());
			Assert::AreEqual(50, m1.get_ct());
		}
	};
}