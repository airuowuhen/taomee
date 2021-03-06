/**
 *============================================================
 *  @file      mcast_proto.hpp
 *  @brief    multi-cast proto
 * 
 *  compiler   gcc4.1.2
 *  platform   Linux
 *
 *  copyright:  TaoMee, Inc. ShangHai CN. All rights reserved.
 *
 *============================================================
 */

#ifndef PAIPAI_MCAST_PROTO_HPP_
#define PAIPAI_MCAST_PROTO_HPP_

extern "C" {
#include <stdint.h>
#include <async_serv/dll.h>
}

/**
  * @brief multi-cast proto command type
  */
enum mcast_cmd_t {
	/*! reload config */
	mcast_reload_conf	= 60001,
    /*! for world notice */
	mcast_world_notice	= 60005
};

#pragma pack(1)

/**
  * @brief multi-cast package type
  */
struct mcast_pkg_t {
	uint32_t	server_id;
	uint32_t	main_cmd;
	uint32_t	minor_cmd;
	uint8_t		body[];	
};

#pragma pack()

inline void init_mcast_pkg_head(void* buf, uint32_t major_cmd, uint32_t minor_cmd)
{
    mcast_pkg_t* pkg = reinterpret_cast<mcast_pkg_t *>(buf);
    pkg->server_id = 0;//get_server_id(); /* mcast pkg_head id */
    pkg->main_cmd  = major_cmd;    
    pkg->minor_cmd = minor_cmd;
}

#endif // PAIPAI_MCAST_PROTO_HPP_

