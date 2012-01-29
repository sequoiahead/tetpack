#include "input/InputConfiguration.h"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

#include <iostream>

class TestInputConfiguration : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( TestInputConfiguration );
		CPPUNIT_TEST( testSettersGetters );
		CPPUNIT_TEST( testDoubleSet );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() {
		config = new InputConfiguration;
	}

	void tearDown() {
		delete config;
	}

	void testSettersGetters() {
		config->set(ACT_TEST1, CMD_TEST1);
		config->set(ACT_TEST2, CMD_TEST2);

		CPPUNIT_ASSERT(CMD_TEST1 == config->get(ACT_TEST1));
		CPPUNIT_ASSERT(CMD_TEST2 == config->get(ACT_TEST2));
		CPPUNIT_ASSERT(*CMD_NONE == config->get(ACT_TEST3)); //CommandNone
		CPPUNIT_ASSERT(*CMD_NONE == config->get(ACT_TEST4)); //CommandNone
	}

	void testDoubleSet() {
		config->set(ACT_TEST1, CMD_TEST1);
		config->set(ACT_TEST1, CMD_TEST2);
		config->get(ACT_TEST2);

		CPPUNIT_ASSERT(CMD_TEST2 == config->get(ACT_TEST1));
		CPPUNIT_ASSERT(CMD_TEST1 != config->get(ACT_TEST1));
	}

	TestInputConfiguration() {
		CMD_NONE = new CommandNone;
	}

	~TestInputConfiguration() {
		delete CMD_NONE;
	}

private:
	InputConfiguration* config;
	const Command* CMD_NONE;

	static const InputAction ACT_TEST1;
	static const InputAction ACT_TEST2;
	static const InputAction ACT_TEST3;
	static const InputAction ACT_TEST4;

	static const Command CMD_TEST1;
	static const Command CMD_TEST2;

	static const int CMD_ID1;
	static const int CMD_ID2;
};

const InputAction TestInputConfiguration::ACT_TEST1 = 1;
const InputAction TestInputConfiguration::ACT_TEST2 = 2;
const InputAction TestInputConfiguration::ACT_TEST3 = 3;
const InputAction TestInputConfiguration::ACT_TEST4 = 4;

const int TestInputConfiguration::CMD_ID1 = 98;
const int TestInputConfiguration::CMD_ID2 = 165;

const Command TestInputConfiguration::CMD_TEST1(CMD_ID1);
const Command TestInputConfiguration::CMD_TEST2(CMD_ID2);

CPPUNIT_TEST_SUITE_REGISTRATION( TestInputConfiguration );
