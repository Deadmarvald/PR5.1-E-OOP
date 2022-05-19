#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.1E/Money.cpp"
#include "../PR5.1E/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT51E
{
	TEST_CLASS(UT51E)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money t;

			int count = Object::Count();

			Assert::AreEqual(count, 1);
		}
	};
}