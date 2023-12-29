/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "nsSBCharSetProber.h"

/********* Language model for: Danish *********/

/**
 * Generated by BuildLangModel.py
 * On: 2022-11-30 19:41:17.519380
 **/

/* Character Mapping Table:
 * ILL: illegal character.
 * CTR: control character specific to the charset.
 * RET: carriage/return.
 * SYM: symbol (punctuation) that does not belong to word.
 * NUM: 0 - 9.
 *
 * Other characters are ordered by probabilities
 * (0 is the most common character in the language).
 *
 * Orders are generic to a language. So the codepoint with order X in
 * CHARSET1 maps to the same character as the codepoint with the same
 * order X in CHARSET2 for the same language.
 * As such, it is possible to get missing order. For instance the
 * ligature of 'o' and 'e' exists in ISO-8859-15 but not in ISO-8859-1
 * even though they are both used for French. Same for the euro sign.
 */
static const unsigned char Iso_8859_15_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 4X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 6X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,CTR, /* 7X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 8X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 9X */
  SYM,SYM,SYM,SYM,SYM,SYM, 50,SYM, 50,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* AX */
  SYM,SYM,SYM,SYM, 60, 57,SYM,SYM, 61,SYM,SYM,SYM, 43, 43, 62,SYM, /* BX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 63, 46, 64, 35, 47, 52, /* CX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 65, 37, 66, 33, 40, 55, 41, /* DX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 67, 46, 68, 35, 47, 52, /* EX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 69, 37, 70, 33, 40, 55, 71, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const unsigned char Iso_8859_1_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 4X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 6X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,CTR, /* 7X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 8X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 9X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* AX */
  SYM,SYM,SYM,SYM,SYM, 57,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* BX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 72, 46, 73, 35, 47, 52, /* CX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 74, 37, 75, 33, 40, 55, 41, /* DX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 76, 46, 77, 35, 47, 52, /* EX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 78, 37, 79, 33, 40, 55, 80, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const unsigned char Windows_1252_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 4X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 6X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,CTR, /* 7X */
  SYM,ILL,SYM, 81,SYM,SYM,SYM,SYM,SYM,SYM, 50,SYM, 43,ILL, 82,ILL, /* 8X */
  ILL,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, 50,SYM, 43,ILL, 83, 84, /* 9X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* AX */
  SYM,SYM,SYM,SYM,SYM, 57,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* BX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 85, 46, 86, 35, 47, 52, /* CX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 87, 37, 88, 33, 40, 55, 41, /* DX */
   39, 32, 44, 53, 36, 21, 20, 42, 38, 28, 89, 46, 90, 35, 47, 52, /* EX */
   31, 48, 58, 29, 49, 59, 34,SYM, 19, 91, 37, 92, 33, 40, 55, 93, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const unsigned char Ibm865_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 4X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM,  4, 16, 24,  7,  0, 13, 10, 18,  5, 23, 11,  8, 12,  2,  9, /* 6X */
   17, 30,  1,  6,  3, 15, 14, 25, 27, 22, 26,SYM,SYM,SYM,SYM,CTR, /* 7X */
   42, 33, 28, 44, 36, 39, 21, 42, 94, 46, 38, 52, 47, 95, 36, 21, /* 8X */
   28, 20, 20, 49, 34, 58, 96, 97, 98, 34, 33, 19,SYM, 19,SYM,SYM, /* 9X */
   32, 35, 29, 37, 48, 48,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* AX */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* BX */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* CX */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* DX */
   45, 41, 99, 56,100,101, 57, 54,102,103,104,105,106,107, 51,SYM, /* EX */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */


/* Model Table:
 * Total sequences: 1065
 * First 512 sequences: 0.9958348814328518
 * Next 512 sequences (512-1024): 0.0041324290837536455
 * Rest: 3.268948339453948e-05
 * Negative sequences: TODO
 */
static const PRUint8 DanishLangModel[] =
{
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,3,3,3,3,2,3,0,0,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,2,2,2,2,2,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,2,2,2,2,
  3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,1,2,2,1,
  3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,0,2,2,3,3,3,3,3,3,2,0,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,3,3,2,3,3,2,0,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,0,2,2,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,0,2,2,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,0,2,2,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,1,2,3,3,3,3,2,2,2,0,2,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,2,2,0,0,2,0,0,
  3,3,3,3,3,3,3,2,3,3,2,3,3,3,3,3,2,2,3,3,3,3,3,3,1,2,2,1,2,0,0,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,2,2,2,2,2,2,
  3,3,3,3,3,3,3,3,3,3,3,2,2,3,3,3,3,2,3,3,3,3,3,3,2,0,2,2,2,2,2,
  3,3,3,3,3,3,3,3,3,3,2,2,3,2,2,3,2,2,2,3,3,3,2,3,2,0,0,0,1,1,0,
  3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,2,2,0,2,2,3,2,2,3,0,0,2,
  3,3,3,3,3,3,3,2,3,3,2,2,2,2,2,3,3,2,2,3,3,3,3,3,2,0,2,0,2,2,0,
  3,3,3,3,3,3,3,3,3,3,3,2,2,3,2,3,3,3,3,3,3,3,3,2,2,0,1,0,2,2,0,
  3,3,3,3,3,3,3,2,3,3,1,2,3,2,3,3,2,2,2,3,3,3,3,3,2,3,0,0,2,2,1,
  3,3,3,3,0,2,3,3,3,2,3,3,3,2,3,2,3,2,2,0,0,0,2,3,0,2,1,0,0,0,0,
  2,3,3,3,2,3,3,3,3,3,3,3,3,3,3,2,3,2,2,0,0,0,0,0,2,0,0,0,0,0,0,
  3,3,3,3,0,0,3,3,3,2,2,3,2,2,3,0,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,2,3,3,3,2,0,0,2,2,2,2,2,0,0,0,0,
  3,3,3,2,3,3,3,3,3,3,2,2,2,2,2,3,2,2,2,3,3,2,3,0,2,0,0,0,0,2,0,
  3,3,2,3,3,3,2,2,3,3,2,3,2,2,2,3,2,2,3,0,2,0,3,2,3,0,2,2,2,2,2,
  3,2,2,2,3,3,2,2,2,3,0,2,2,2,0,2,2,0,2,0,2,0,2,2,2,2,2,0,0,0,2,
  3,2,2,2,3,3,2,2,2,3,2,2,2,2,0,2,2,2,2,0,0,0,2,2,0,2,3,0,0,0,0,
  3,2,1,2,2,2,2,2,2,2,0,2,1,2,2,0,0,2,0,0,0,0,2,0,2,2,0,2,0,0,0,
  2,2,3,2,2,0,2,2,2,2,2,0,2,2,2,2,2,1,2,0,0,0,0,0,1,0,2,0,0,0,0,
  0,3,2,2,2,0,2,0,2,0,2,2,0,2,2,0,0,2,2,0,0,0,0,0,0,2,0,0,0,0,0,
  0,0,0,0,2,1,0,0,0,0,0,0,0,0,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};


const SequenceModel Iso_8859_15DanishModel =
{
  Iso_8859_15_CharToOrderMap,
  DanishLangModel,
  31,
  (float)0.9958348814328518,
  PR_TRUE,
  "ISO-8859-15"
};

const SequenceModel Iso_8859_1DanishModel =
{
  Iso_8859_1_CharToOrderMap,
  DanishLangModel,
  31,
  (float)0.9958348814328518,
  PR_TRUE,
  "ISO-8859-1"
};

const SequenceModel Windows_1252DanishModel =
{
  Windows_1252_CharToOrderMap,
  DanishLangModel,
  31,
  (float)0.9958348814328518,
  PR_TRUE,
  "WINDOWS-1252"
};

const SequenceModel Ibm865DanishModel =
{
  Ibm865_CharToOrderMap,
  DanishLangModel,
  31,
  (float)0.9958348814328518,
  PR_TRUE,
  "IBM865"
};
