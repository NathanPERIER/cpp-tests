
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Casting integer signed unsigned") {
	const int16_t sig = 0xFFFA;
	const uint16_t usig = 0xFFFA;

	CHECK(int64_t(-6)     == sig);
	CHECK(uint64_t(65530) == usig);
	CHECK(sig  == static_cast<int16_t>(usig));
	CHECK(usig == static_cast<uint16_t>(sig));
	CHECK(sig  == (*reinterpret_cast<const int16_t*>(&usig)));
	CHECK(usig == (*reinterpret_cast<const uint16_t*>(&sig)));
}

TEST_CASE("Casting to bigger integer") {
	const int16_t sig16 = 0xFFFA;
	const uint16_t usig16 = 0xFFFA;

	// Cast to signed
	CHECK(int32_t(0xFFFFFFFA)  == static_cast<int32_t>(sig16));
	CHECK(int32_t(-6)          == static_cast<int32_t>(sig16));
	CHECK(int32_t(0x0000FFFA)  == static_cast<int32_t>(usig16));
	CHECK(int32_t(65530)       == static_cast<int32_t>(usig16));

	// Cast to unsigned
	CHECK(uint32_t(0xFFFFFFFA) == static_cast<uint32_t>(sig16));
	CHECK(uint32_t(4294967290) == static_cast<uint32_t>(sig16));
	CHECK(uint32_t(0x0000FFFA) == static_cast<uint32_t>(usig16));
	CHECK(uint32_t(65530)      == static_cast<uint32_t>(usig16));
}

TEST_CASE("Casting to smaller integer") {
	const int16_t sig16 = 0xFFFA;
	const uint16_t usig16 = 0xFFFA;

	// Cast to signed
	CHECK(int8_t(0xFA)  == static_cast<int8_t>(sig16));
	CHECK(int8_t(-6)    == static_cast<int8_t>(sig16));
	CHECK(int8_t(0xFA)  == static_cast<int8_t>(usig16));
	CHECK(int8_t(250)   == static_cast<int8_t>(usig16));

	// Cast to unsigned
	CHECK(uint8_t(0xFA) == static_cast<uint8_t>(sig16));
	CHECK(uint8_t(250)  == static_cast<uint8_t>(sig16));
	CHECK(uint8_t(0xFA) == static_cast<uint8_t>(usig16));
	CHECK(uint8_t(250)  == static_cast<uint8_t>(usig16));
}

TEST_CASE("Casting float to int") {
	const float f1 = 3.14;
	const float f2 = 6.9;

	CHECK(int16_t( 3) == static_cast<int16_t>(f1));
	CHECK(int16_t( 6) == static_cast<int16_t>(f2));
	CHECK(int16_t(-3) == static_cast<int16_t>(-f1));
	CHECK(int16_t(-6) == static_cast<int16_t>(-f2));
}

TEST_CASE("Casting double to int") {
	const double d1 = 3.14;
	const double d2 = 6.9;

	CHECK(int16_t( 3) == static_cast<int16_t>(d1));
	CHECK(int16_t( 6) == static_cast<int16_t>(d2));
	CHECK(int16_t(-3) == static_cast<int16_t>(-d1));
	CHECK(int16_t(-6) == static_cast<int16_t>(-d2));
}

