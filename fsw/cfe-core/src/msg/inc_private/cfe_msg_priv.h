/*
**  GSC-18128-1, "Core Flight Executive Version 6.7"
**
**  Copyright (c) 2006-2019 United States Government as represented by
**  the Administrator of the National Aeronautics and Space Administration.
**  All Rights Reserved.
**
**  Licensed under the Apache License, Version 2.0 (the "License");
**  you may not use this file except in compliance with the License.
**  You may obtain a copy of the License at
**
**    http://www.apache.org/licenses/LICENSE-2.0
**
**  Unless required by applicable law or agreed to in writing, software
**  distributed under the License is distributed on an "AS IS" BASIS,
**  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**  See the License for the specific language governing permissions and
**  limitations under the License.
*/

/******************************************************************************
 * Message private header
 *  - Avoid including outside this module
 */

#ifndef _cfe_msg_priv_
#define _cfe_msg_priv_

/*
 * Includes
 */
#include "common_types.h"
#include "cfe_error.h"

/*
 * Types
 */

/*
 * Defines
 */
/* TODO error bits won't fit a new module */
#define CFE_MSG_BAD_ARGUMENT    CFE_SB_BAD_ARGUMENT /**< \brief Error - bad argument */
#define CFE_MSG_NOT_IMPLEMENTED CFE_SB_NOT_IMPLEMENTED /**< \brief Error - not implemented */
#define CFE_MSG_WRONG_MSG_TYPE  CFE_SB_WRONG_MSG_TYPE /**< \brief Error - wrong type */

/*****************************************************************************/
/**
 * \brief get generic header field (uint8 array[2])
 *
 * \par DESCRIPTION
 *     Big endian get of header field given mask.  Only sets bits
 *     in value that are part of mask.
 *
 * \param[in]      Word Header value to set
 * \param[out]     Val  Value to set
 * \param[in]      Mask Mask used for set
 */
static inline void CFE_MSG_GetHeaderField(const uint8 *Word, uint16 *Val, uint16 Mask)
{
    *Val = (Word[0] << 8 | Word[1]) & Mask;
}

/*****************************************************************************/
/**
 * \brief Set generic header field (uint8 array[2])
 *
 * \par DESCRIPTION
 *     Big endian set of header field given value and mask.  Only sets bits
 *     from value that are part of mask.
 *
 * \param[in, out] Word Header value to set
 * \param[in]      Val  Value to set
 * \param[in]      Mask Mask used for set
 */
static inline void CFE_MSG_SetHeaderField(uint8 *Word, uint16 Val, uint16 Mask)
{
    Word[0] = (Word[0] & ~(Mask >> 8)) | ((Val & Mask) >> 8);
    Word[1] = ((Word[1] & ~Mask) | (Val & Mask)) & 0xFF;
}

#endif /* _cfe_msg_priv_ */