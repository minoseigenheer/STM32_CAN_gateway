/*
 * cpp_link.cpp
 *
 *  Created on: Nov 22, 2022
 *      Author: minoseigenheer
 */

#include "cpp_link.hpp"

#include "project.hpp"

#ifdef __cplusplus
	extern "C"
	{
#endif

	void cpp_link (void)
		{
		    myCppProcessInit();
		    myCppProcess();

		}

#ifdef __cplusplus
	}
#endif

