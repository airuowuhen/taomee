/** 
 * ========================================================================
 * @file arg.cpp
 * @brief 
 * @author smyang
 * @version 1.0
 * @date 2012-08-06
 * Modify $Date: $
 * Modify $Author: $
 * Copyright: TaoMee, Inc. ShangHai CN. All rights reserved.
 * ========================================================================
 */

#include <string.h>
#include <errno.h>


#include "arg.h"
#include "metric.h"



c_metric_arg * alloc_metric_arg(const char * p_arg, c_metric * p_metric)
{
    c_metric_arg * p = new (std::nothrow)c_metric_arg(p_metric->m_value_type);
    if (NULL == p)
    {
        ERROR_LOG("malloc node failed, %s", strerror(errno));
        return NULL;

    }

    STRNCPY(p->m_arg, p_arg, MAX_METRIC_ARG_LEN);
    p->m_metric = p_metric;

    g_hash_table_insert(p_metric->m_arg_map, p->m_arg, p);

    return p;
}

void free_metric_arg(void * p)
{
    c_metric_arg * p_arg = reinterpret_cast< c_metric_arg * >(p);
    delete p_arg;


}


c_metric_arg * find_metric_arg(GHashTable * p_table, char * p_arg)
{
    return reinterpret_cast< c_metric_arg * >(g_hash_table_lookup(p_table, p_arg));
}
