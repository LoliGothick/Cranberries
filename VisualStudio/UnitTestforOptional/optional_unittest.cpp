#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../cranberries/optional.hpp"
#include "../../cranberries/unit_test/unit_test.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforOptional
{		
	TEST_CLASS(OptionalUnitTest)
	{
	public:
		
		TEST_METHOD(OptionalTestMethod)
		{
			namespace unit = cranberries::unit_test_framework;
			using cranberries::optional;
			using cranberries::nullopt;

			auto fuck_ms = [](auto&& val) {
				std::ostringstream ss;
				ss << val;
				Logger::WriteMessage(ss.str().c_str());
			};

			try {
#pragma region create_tests
				unit::make_unit_test_container(unit::make_logger(fuck_ms), "create tests")
					% unit::assertion::are_equal(optional<int>{}.value_or_else([] { return 1; }), 1)
					% unit::assertion::are_equal(optional<int>{2}.value_or_else([] { return 1; }), 2)
					% unit::assertion::are_equal(optional<int>{2}.map([](auto a) { return a * 2; }), 4)
					% unit::assertion::are_equal(optional<int>{}.map([](auto a){ return a*2.; }), nullopt)
					| unit::collect;
#pragma endregion

			}
			catch (unit::detail_::assert_except const&) {
				Assert::Fail(L"Test Failed");
			}
			catch (...) {
				Assert::Fail(L"Unhandled exception throw");
			}


		}

	};
}