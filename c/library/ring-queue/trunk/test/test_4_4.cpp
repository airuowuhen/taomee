/**
 * @file test_1.cpp
 * @author richard <richard@taomee.com>
 * @date 2010-09-20
 */

#include <stdio.h>
#include <string.h>

#include <boost/test/minimal.hpp>

#include "i_ring_queue.h"

/**
 * 原子地向waitable_queue中压入数据
 */
int test_main(int argc, char **argv)
{
	i_ring_queue *p_ring_queue = NULL;

	BOOST_REQUIRE(create_variable_queue_instance(&p_ring_queue, 2) == 0);
	BOOST_REQUIRE((p_ring_queue = create_waitable_queue_instance(p_ring_queue)) != NULL);
	BOOST_REQUIRE(p_ring_queue->init(9) == 0);
	BOOST_CHECK(p_ring_queue->push_data(NULL, strlen("abc"), 1) == -1);
	BOOST_CHECK(p_ring_queue->push_data("\003\0a", 0, 1) == -1);
	BOOST_CHECK(p_ring_queue->push_data("\003\0a", 3, 1) == 3);
	BOOST_CHECK(p_ring_queue->push_data("\003\0b", 3, 1) == 3);
	BOOST_CHECK(p_ring_queue->push_data("\003\0c", 3, 1) == 3);
	BOOST_CHECK(p_ring_queue->push_data("\003\0d", 3, 1) == -1);
	BOOST_CHECK(p_ring_queue->uninit() == 0);
	BOOST_CHECK(p_ring_queue->release() == 0);

	return 0;
}

