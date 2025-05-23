/*
 * Copyright (c) 2013-2017 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * $Date:        2. Feb 2017
 * $Revision:    V2.0
 *
 * Project:      Common Driver definitions
 */

/* History:
 *  Version 2.0
 *    Changed prefix ARM_DRV -> ARM_DRIVER
 *    Added General return codes definitions
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.00
 *    Initial release
 */

#ifndef DRIVER_COMMON_H_
#define DRIVER_COMMON_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define ARM_DRIVER_VERSION_MAJOR_MINOR(major,minor) (((major) << 8) | (minor))

/**
\brief Driver Version
*/
typedef struct _ARM_DRIVER_VERSION {
  uint16_t api;                         ///< API version
  uint16_t drv;                         ///< Driver version
} ARM_DRIVER_VERSION;

/* General return codes */
#define ARM_DRIVER_OK                 0 ///< Operation succeeded
#define ARM_DRIVER_ERROR             -1 ///< Unspecified error
#define ARM_DRIVER_ERROR_BUSY        -2 ///< Driver is busy
#define ARM_DRIVER_ERROR_TIMEOUT     -3 ///< Timeout occurred
#define ARM_DRIVER_ERROR_UNSUPPORTED -4 ///< Operation not supported
#define ARM_DRIVER_ERROR_PARAMETER   -5 ///< Parameter error
#define ARM_DRIVER_ERROR_SPECIFIC    -6 ///< Start of driver specific errors

/**
\brief General power states
*/
typedef enum _ARM_POWER_STATE {
  ARM_POWER_OFF,                        ///< Power off: no operation possible
  ARM_POWER_LOW,                        ///< Low Power mode: retain state, detect and signal wake-up events
  ARM_POWER_FULL                        ///< Power on: full operation at maximum performance
} ARM_POWER_STATE;

typedef struct _PIN {
  uint8_t    pinNum;
  uint8_t    funcNum;
} PIN;

#ifndef ASSERT
#define ASSERT(X)   assert(X)
#endif

#ifndef BIT
#define BIT(n)      ((unsigned int) 1 << (n))
#define BITS2(m,n)  (BIT(m) | BIT(n))
#define BITS(m,n)   (~(BIT(m) - 1) & ((BIT(n) - 1) | BIT(n)))
#endif


#ifndef PLAT_CODE_IN_RAM_PRE1
//boost power up speed clk init code
#define PLAT_CODE_IN_RAM_PRE1        __attribute__((__section__(".pre1RamCode")))
#endif

#ifndef PLAT_CODE_IN_RAM_PRE2
//boost power up speed flash init code
#define PLAT_CODE_IN_RAM_PRE2        __attribute__((__section__(".pre2RamCode")))
#endif

#ifndef PLAT_CODE_IN_RAM
#define PLAT_CODE_IN_RAM             __attribute__((__section__(".ramCode")))
#endif

#ifndef RAM_CODE2_SECTION
#define RAM_CODE2_SECTION             __attribute__((__section__(".ramCode2")))
#endif


#ifndef MIN
#define MIN(a,b)  (((a)<(b) ? (a) : (b)))
#endif

#endif /* DRIVER_COMMON_H_ */
