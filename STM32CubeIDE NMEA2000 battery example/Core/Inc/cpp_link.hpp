/*
 * cpp_link.hpp
 *
 *  Created on: Nov 22, 2022
 *      Author: minoseigenheer
 */

#ifndef CORE_INC_CPP_LINK_HPP_
#define CORE_INC_CPP_LINK_HPP_

#include "main.h"
#include "stm32f1xx_hal.h"

#ifndef CPP_LINK_HPP_
#define CPP_LINK_HPP_

	#ifdef __cplusplus
		extern "C"
		{
	#endif

		void cpp_link (void);

	#ifdef __cplusplus
		}
	#endif
#endif /* CPP_LINK_HPP_ */

#endif /* CORE_INC_CPP_LINK_HPP_ */
