/****************************************************************************
 *
 *   Copyright (C) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <gtest/gtest.h>
#include <CollisionPrevention/CollisionPrevention.hpp>

// to run: make tests TESTFILTER=CollisionPrevention

class CollisionPreventionTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		uORB::Manager::initialize();
		param_init();
	}

	void TearDown() override
	{
		param_reset_all();
		uORB::Manager::terminate();
	}
};

TEST_F(CollisionPreventionTest, testInstantiation)
{
	CollisionPrevention cp(nullptr);
}

TEST_F(CollisionPreventionTest, testReadWriteParam)
{
	// GIVEN a parameter handle
	param_t param = param_handle(px4::params::MPC_COL_PREV_D);

	// WHEN: we get the parameter
	float value = -999;
	int status = param_get(param, &value);

	// THEN it should be successful and have the default value
	EXPECT_EQ(0, status);
	EXPECT_EQ(-1, value);

	// WHEN: we set the parameter
	value = 42;
	status = param_set(param, &value);

	// THEN: it should be successful
	EXPECT_EQ(0, status);

	// WHEN: we get the parameter again
	float value2 = -1999;
	status = param_get(param, &value2);

	// THEN: it should be the value we set
	EXPECT_EQ(0, status);
	EXPECT_EQ(42, value2);
}
