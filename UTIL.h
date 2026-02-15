// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
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

/**
 *  @file
 *
 *  @brief Platform UTIL Library
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Library
 *
 *  @{
 */

/**
 *  @defgroup Platform_UTIL UTIL
 *
 *  @{
 */

#ifndef UTIL_H_
    #define UTIL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #define UTIL_UNUSED( Variable )                                                           ( ( void ) Variable )

    #define UTIL_BIT( Index )                                                                 ( ( uint32_t ) ( 1 ) << ( Index ) )

    #define UTIL_TokenStringfyEvaluate( Token )                                               #Token
    #define UTIL_TokenStringfy( Token )                                                       UTIL_TokenStringfyEvaluate( Token )

    #define UTIL_TokenConcatenateEvaluate( Token_Left, Token_Right )                          Token_Left##Token_Right
    #define UTIL_TokenConcatenate( Token_Left, Token_Right )                                  UTIL_TokenConcatenateEvaluate( Token_Left, Token_Right )

    #define UTIL_Ceil( Divisor, Dividend )                                                    ( ( uint32_t ) ( ( Divisor ) + ( Dividend ) - 1 ) / ( uint32_t ) ( Dividend ) )
    #define UTIL_Floor( Divisor, Dividend )                                                   ( ( uint32_t ) ( Divisor ) / ( uint32_t ) ( Dividend ) )
    #define UTIL_Modulus( Divisor, Dividend )                                                 ( ( uint32_t ) ( Divisor ) % ( uint32_t ) ( Dividend ) )
    #define UTIL_Max( Left, Right )                                                           ( ( Left ) < ( Right ) ? ( Right ) : ( Left ) )
    #define UTIL_Min( Left, Right )                                                           ( ( Left ) < ( Right ) ? ( Left ) : ( Right ) )
    #define UTIL_Absolute( Number )                                                           ( ( Number ) < 0 ? -( Number ) : ( Number ) )

    #define UTIL_YearToMonth( Year )                                                          ( ( double ) ( Year ) * 12.0l )
    #define UTIL_MonthToDay( Month )                                                          /* No Direct Mapping Exist */
    #define UTIL_DayToHour( Day )                                                             ( ( double ) ( Day ) * 24.0l )
    #define UTIL_HourToMinute( Hour )                                                         ( ( double ) ( Hour ) * 60.0l )
    #define UTIL_MinuteToSecond( Minute )                                                     ( ( double ) ( Minute ) * 60.0l )
    #define UTIL_SecondToMillisecond( Second )                                                ( ( double ) ( Second ) * 1000.0l )
    #define UTIL_MillisecondToMicrosecond( Millisecond )                                      ( ( double ) ( Millisecond ) * 1000.0l )
    #define UTIL_MicrosecondToNanosecond( Microsecond )                                       ( ( double ) ( Microsecond ) * 1000.0l )
    #define UTIL_NanosecondToPicosecond( Nanosecond )                                         ( ( double ) ( Nanosecond ) * 1000.0l )
    #define UTIL_PicosecondToNanosecond( Picosecond )                                         ( ( double ) ( Picosecond ) / 1000.0l )
    #define UTIL_NanosecondToMicrosecond( Nanosecond )                                        ( ( double ) ( Nanosecond ) / 1000.0l )
    #define UTIL_MicrosecondToMillisecond( Microsecond )                                      ( ( double ) ( Microsecond ) / 1000.0l )
    #define UTIL_MillisecondToSecond( Millisecond )                                           ( ( double ) ( Millisecond ) / 1000.0l )
    #define UTIL_SecondToMinute( Second )                                                     ( ( double ) ( Second ) / 60.0l )
    #define UTIL_MinuteToHour( Minute )                                                       ( ( double ) ( Minute ) / 60.0l )
    #define UTIL_HourToDay( Hour )                                                            ( ( double ) ( Hour ) / 24.0l )
    #define UTIL_DayToMonth( Day )                                                            /* No Direct Mapping Exist */
    #define UTIL_MonthToYear( Month )                                                         ( ( double ) ( Month ) / 12.0l )

    #define UTIL_FixedToDouble( FixedValue, FractionBits )                                    ( ( double ) ( FixedValue ) / ( 1 << ( FractionBits ) ) )
    #define UTIL_DoubleToFixed( DoubleValue, FractionBits )                                   ( ( uint32_t ) ( ( DoubleValue ) * ( 1 << ( FractionBits ) ) ) )

    #define UTIL_SizeOf( Type )                                                               ( sizeof( Type ) )
    #define UTIL_SizeOfWithoutNull( Type )                                                    ( UTIL_SizeOf( Type ) - 1 )

    #define UTIL_MemorySetZero( Destination, Length )                                         ( memset( ( void * ) ( Destination ), 0x00, ( size_t ) ( Length ) ) )
    #define UTIL_MemoryCopy( Destination, Source, Length )                                    ( memmove( ( void * ) ( Destination ), ( void * ) ( Source ), ( size_t ) ( Length ) ) )
    #define UTIL_MemoryAppend( Destination, Length_Occupied, Length_MAX, Source, Length )     ( memmove( ( void * ) ( Destination ) + ( Length_Occupied ), ( void * ) ( Source ), UTIL_Min( ( size_t ) ( Length ), ( ( size_t ) ( Length_MAX ) - ( Length_Occupied ) ) ) ) )

    #define UTIL_CharacterIsDigit( Character )                                                ( '0' <= ( Character ) && ( Character ) <= '9' )
    #define UTIL_CharacterIsAlpha( Character )                                                ( ( 'a' <= ( Character ) && ( Character ) <= 'z' ) || ( 'A' <= ( Character ) && ( Character ) <= 'Z' ) )

    #define UTIL_StringLength( String )                                                       ( strlen( ( char * ) ( String ) ) )
    #define UTIL_StringCopy( Destination, Source )                                            ( strcpy( ( char * ) ( Destination ), ( char * ) ( Source ) ) )
    #define UTIL_StringCompareStatusEqual                                                     0
    #define UTIL_StringCompare( String_Left, String_Right )                                   ( strcmp( ( char * ) ( String_Left ), ( char * ) ( String_Right ) ) ) // @UTIL_StringCompareStatus...
    #define UTIL_StringConcatenate( String_Left, String_Right )                               ( strcat( ( char * ) ( String_Left ), ( char * ) ( String_Right ) ) )
    #define UTIL_StringConcatenateConstant( String_Left, String_Right )                       String_Left String_Right
    #define UTIL_StringFindSeparator( String, Separators )                                    ( strpbrk( ( char * ) ( String ), ( char * ) ( Separators ) ) )
    #define UTIL_StringFormatLength( Format, ... )                                            ( snprintf( NULL, 0, ( char * ) ( Format ), ##__VA_ARGS__ ) )
    #define UTIL_StringFormatBufferAppend( Buffer, Length_Occupied, Length_MAX, Format, ... ) ( snprintf( ( char * ) ( Buffer ) + ( Length_Occupied ), ( uint32_t ) ( Length_MAX ) - ( Length_Occupied ), ( char * ) ( Format ), ##__VA_ARGS__ ) )

    // NOTE: Array MUST have at least ONE element
    #define UTIL_ArraySize( Array )                                                           ( UTIL_SizeOf( Array ) / UTIL_SizeOf( Array[ 0 ] ) )

    // TODO Rename to UTIL_PointerIncrementBytes( Pointer, N_Bytes )
    #define UTIL_ByteIncrement( Reference, N_Bytes )                                          ( ( uint8_t * ) ( Reference ) + ( N_Bytes ) )
    #define UTIL_ByteSwap( To, From ) \
        {                             \
            uint8_t Temp = ( To );    \
            ( To ) = ( From );        \
            ( From ) = Temp;          \
        }

    // Control Sequence Introducer ( CSI )
    #define UTIL_CSI_Prefix                                       "\e["
    #define UTIL_CSI_CursorUp( Rows )                             UTIL_CSI_Prefix UTIL_TokenStringfy( Rows ) "A"
    #define UTIL_CSI_CursorDown( Rows )                           UTIL_CSI_Prefix UTIL_TokenStringfy( Rows ) "B"
    #define UTIL_CSI_CursorForward( Columns )                     UTIL_CSI_Prefix UTIL_TokenStringfy( Columns ) "C"
    #define UTIL_CSI_CursorBack( Columns )                        UTIL_CSI_Prefix UTIL_TokenStringfy( Columns ) "D"
    #define UTIL_CSI_CursorNextLine( N_Lines )                    UTIL_CSI_Prefix UTIL_TokenStringfy( N_Lines ) "E"
    #define UTIL_CSI_CursorPreviousLine( N_Lines )                UTIL_CSI_Prefix UTIL_TokenStringfy( N_Lines ) "F"
    #define UTIL_CSI_CursorHorizontalAbsolute( Column )           UTIL_CSI_Prefix UTIL_TokenStringfy( Column ) "G"
    #define UTIL_CSI_CursorPosition( Row, Column )                UTIL_CSI_Prefix UTIL_TokenStringfy( Row ) ";" UTIL_TokenStringfy( Column ) "H"

    #define UTIL_CSI_EraseDisplayModeFromCursorToEnd              0
    #define UTIL_CSI_EraseDisplayModeFromCursorToBegin            1
    #define UTIL_CSI_EraseDisplayModeEntire                       2
    #define UTIL_CSI_EraseDisplayModeEntirePlusHistory            3
    #define UTIL_CSI_EraseDisplay( Mode )                         UTIL_CSI_Prefix UTIL_TokenStringfy( Mode ) "J" // @UTIL_CSI_EraseDisplayMode...

    #define UTIL_CSI_EraseLineModeFromCursorToEnd                 0
    #define UTIL_CSI_EraseLineModeFromCursorToBegin               1
    #define UTIL_CSI_EraseLineModeEntire                          2
    #define UTIL_CSI_EraseLine( Mode )                            UTIL_CSI_Prefix UTIL_TokenStringfy( Mode ) "K" // @UTIL_CSI_EraseLineMode...

    #define UTIL_CSI_ScrollUp( N_Lines )                          UTIL_CSI_Prefix UTIL_TokenStringfy( N_Lines ) "S"
    #define UTIL_CSI_ScrollDown( N_Lines )                        UTIL_CSI_Prefix UTIL_TokenStringfy( N_Lines ) "T"

    #define UTIL_CSI_HorizontalVerticalPosition( Row, Column )    UTIL_CSI_Prefix UTIL_TokenStringfy( Row ) ";" UTIL_TokenStringfy( Column ) "f"

    #define UTIL_CSI_SelectGraphicRenditionReset                  0
    #define UTIL_CSI_SelectGraphicRenditionIntensityBold          1
    #define UTIL_CSI_SelectGraphicRenditionIntensityFaint         2
    #define UTIL_CSI_SelectGraphicRenditionItalic                 3
    #define UTIL_CSI_SelectGraphicRenditionUnderline              4
    #define UTIL_CSI_SelectGraphicRenditionBlinkSlow              5
    #define UTIL_CSI_SelectGraphicRenditionBlinkRapid             6
    #define UTIL_CSI_SelectGraphicRenditionColorsInvert           7
    #define UTIL_CSI_SelectGraphicRenditionConceal                8
    #define UTIL_CSI_SelectGraphicRenditionCrossed                9
    #define UTIL_CSI_SelectGraphicRenditionFontDefault            10
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative1       11
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative2       12
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative3       13
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative4       14
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative5       15
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative6       16
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative7       17
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative8       18
    #define UTIL_CSI_SelectGraphicRenditionFontAlternative9       19
    #define UTIL_CSI_SelectGraphicRenditionGothic                 20
    #define UTIL_CSI_SelectGraphicRenditionIntensityBoldDisable   21
    #define UTIL_CSI_SelectGraphicRenditionIntensityDefault       22
    #define UTIL_CSI_SelectGraphicRenditionItalicDisable          23
    #define UTIL_CSI_SelectGraphicRenditionUnderlineDisable       24
    #define UTIL_CSI_SelectGraphicRenditionBlinkDisable           25
    #define UTIL_CSI_SelectGraphicRenditionSpaceProportional      26
    #define UTIL_CSI_SelectGraphicRenditionColorsInvertDisable    27
    #define UTIL_CSI_SelectGraphicRenditionReveal                 28
    #define UTIL_CSI_SelectGraphicRenditionCrossedDisable         29
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundBlack   30
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundRed     31
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundGreen   32
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundYellow  33
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundBlue    34
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundMagenta 35
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundCyan    36
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundWhite   37
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundSet8bit( Value ) \
        38;                                                                \
        5;                                                                 \
        Value
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundSet24bit( Red, Green, Blue ) \
        38;                                                                            \
        2;                                                                             \
        Red;                                                                           \
        Green;                                                                         \
        Blue
    #define UTIL_CSI_SelectGraphicRenditionColorForegroundDefault 39
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundBlack   40
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundRed     41
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundGreen   42
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundYellow  43
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundBlue    44
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundMagenta 45
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundCyan    46
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundWhite   47
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundSet8bit( Value ) \
        48;                                                                \
        5;                                                                 \
        Value
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundSet24bit( Red, Green, Blue ) \
        48;                                                                            \
        2;                                                                             \
        Red;                                                                           \
        Green;                                                                         \
        Blue
    #define UTIL_CSI_SelectGraphicRenditionColorBackgroundDefault    49
    #define UTIL_CSI_SelectGraphicRenditionSpacingPropotionalDisable 50
    #define UTIL_CSI_SelectGraphicRenditionFramed                    51
    #define UTIL_CSI_SelectGraphicRenditionEncircled                 52
    #define UTIL_CSI_SelectGraphicRenditionOverlined                 53
    #define UTIL_CSI_SelectGraphicRenditionFramedDisable             54
    #define UTIL_CSI_SelectGraphicRenditionEncircledDisable          54 // Same as Framed Disabled
    #define UTIL_CSI_SelectGraphicRenditionOverlinedDisable          55
    #define UTIL_CSI_SelectGraphicRenditionUnderlineColorSet8bit( Value ) \
        58;                                                               \
        5;                                                                \
        Value
    #define UTIL_CSI_SelectGraphicRenditionUnderlineColorSet24bit( Red, Green, Blue ) \
        58;                                                                           \
        2;                                                                            \
        Red;                                                                          \
        Green;                                                                        \
        Blue
    #define UTIL_CSI_SelectGraphicRenditionUnderlineColorDefault 59
    // TODO Add More CSI SGR Codes
    #define UTIL_CSI_SelectGraphicRendition( Code )              UTIL_CSI_Prefix UTIL_TokenStringfy( Code ) "m"

    #define UTIL_CSI_AUXPortOn( )                                UTIL_CSI_Prefix "5i"
    #define UTIL_CSI_AUXPortOff( )                               UTIL_CSI_Prefix "4i"

    #define UTIL_CSI_DeviceStatusReport( )                       UTIL_CSI_Prefix "6n"

    #define UTIL_CSI_SaveCurrentCursorPosition( )                UTIL_CSI_Prefix "s"
    #define UTIL_CSI_RestoreSavedCursorPosition( )               UTIL_CSI_Prefix "u"

    #define UTIL_CSI_CursorShow( )                               UTIL_CSI_Prefix "?25h"
    #define UTIL_CSI_CursorHide( )                               UTIL_CSI_Prefix "?25l"

    #define UTIL_CSI_FocusReportEnable( )                        UTIL_CSI_Prefix "?1004h"
    #define UTIL_CSI_FocusReportDisable( )                       UTIL_CSI_Prefix "?1004l"

    #define UTIL_CSI_AlternativeScreenBufferEnable( )            UTIL_CSI_Prefix "?1049h"
    #define UTIL_CSI_AlternativeScreenBufferDisable( )           UTIL_CSI_Prefix "?1049l"

    #define UTIL_CSI_BracketedPasteModeEnable( )                 UTIL_CSI_Prefix "?2004h"
    #define UTIL_CSI_BracketedPasteModeDisable( )                UTIL_CSI_Prefix "?2004l"

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief UTIL Operation Status
     *
     *  @enum UTIL_Status_t
     */
    typedef enum UTIL_Status
    {
        UTIL_Status_Success = 0,     ///< Success
        UTIL_Status_ArgumentInvalid, ///< Argument Invalid
        UTIL_Status_NotSupported,    ///< Not Supported
        UTIL_Status_Error,           ///< General Error
        UTIL_Status_Busy,            ///< Busy
        UTIL_Status_Timeout,         ///< Timeout
    } UTIL_Status_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Convert HEX string into BYTE string
     *
     *  @return UTIL_Status_t
     */
    UTIL_Status_t UTIL_HexStringToBytes( uint8_t * HexString, uint32_t HexStringLength, uint8_t * Bytes, uint32_t BytesLength );

    /**
     *  @brief Convert BYTE string into HEX string
     *
     *  @return UTIL_Status_t
     */
    UTIL_Status_t UTIL_BytesToHexString( uint8_t * Bytes, uint32_t BytesLength, uint8_t * HexString, uint32_t HexStringLength );

    /**
     *  @brief Reverse memory region content
     *
     *  @return UTIL_Status_t
     */
    UTIL_Status_t UTIL_MemoryReverse( uint8_t * Memory, uint32_t Length );

    /**
     *  @brief Sort Array Of Doubles
     *
     *  @return UTIL_Status_t
     */
    UTIL_Status_t UTIL_SortDouble( double * Array, uint32_t Length );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char UTIL_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* UTIL_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
