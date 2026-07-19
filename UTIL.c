// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2025 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "UTIL.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static int UTIL_CompareDouble( const void * left, const void * right )
{
    int status = 0;
    double left_d = *( const double * ) left;
    double right_d = *( const double * ) right;

    if ( left_d < right_d )
    {
        status = -1;
    }
    else if ( left_d > right_d )
    {
        status = 1;
    }

    return status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

UTIL_Status_t UTIL_HexStringToBytes( uint8_t * HexString, uint32_t HexStringLength, uint8_t * Bytes, uint32_t BytesLength )
{
    UTIL_Status_t Status = UTIL_Status_Error;
    do
    {
        Status = UTIL_Status_Success;
        uint8_t CharacterValue = 0;
        uint8_t ByteValue = 0;
        uint32_t BytesLengthFilled = 0;
        for ( uint32_t index = 0; index < HexStringLength; ++index )
        {
            if ( BytesLengthFilled >= BytesLength )
            {
                Status = UTIL_Status_Error;
                break;
            }
            CharacterValue = tolower( HexString[ index ] );
            if ( '0' <= CharacterValue && CharacterValue <= '9' )
            {
                CharacterValue = CharacterValue - '0';
            }
            else if ( 'a' <= CharacterValue && CharacterValue <= 'f' )
            {
                CharacterValue = CharacterValue - 'a' + 10;
            }
            else
            {
                Status = UTIL_Status_Error;
                break;
            }
            if ( index % 2 == 0 )
            {
                ByteValue = CharacterValue << 4;
            }
            else
            {
                ByteValue += CharacterValue;
                Bytes[ BytesLengthFilled++ ] = ByteValue;
            }
        }
    }
    while ( 0 );
    return Status;
}

UTIL_Status_t UTIL_BytesToHexString( uint8_t * Bytes, uint32_t BytesLength, uint8_t * HexString, uint32_t HexStringLength )
{
    UTIL_Status_t Status = UTIL_Status_Error;
    do
    {
        Status = UTIL_Status_Success;
        uint32_t HexStringLengthFilled = 0;
        for ( uint32_t index = 0; index < BytesLength; ++index )
        {
            if ( HexStringLengthFilled >= HexStringLength )
            {
                Status = UTIL_Status_Error;
                break;
            }
            HexStringLengthFilled += UTIL_StringFormatBufferAppend( HexString, HexStringLengthFilled, HexStringLength, "%02X", Bytes[ index ] );
        }
    }
    while ( 0 );
    return Status;
}

UTIL_Status_t UTIL_MemoryReverse( uint8_t * Memory, uint32_t Length )
{
    UTIL_Status_t Status = UTIL_Status_Error;
    do
    {
        for ( uint8_t *start = Memory, *end = Memory + Length - 1; start < end; start++, end-- )
        {
            UTIL_ByteSwap( *start, *end );
        }
        Status = UTIL_Status_Success;
    }
    while ( 0 );
    return Status;
}

UTIL_Status_t UTIL_SortDouble( double * Array, uint32_t Length )
{
    UTIL_Status_t Status = UTIL_Status_Error;

    do
    {
        qsort( Array, Length, sizeof( double ), UTIL_CompareDouble );

        Status = UTIL_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char UTIL_VERSION[] = "0.0.0.v20260719-2341";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
