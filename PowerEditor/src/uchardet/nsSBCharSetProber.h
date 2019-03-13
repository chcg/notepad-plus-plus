/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
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
 * The Original Code is Mozilla Universal charset detector code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *          Shy Shalom <shooshX@gmail.com>
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
#ifndef nsSingleByteCharSetProber_h__
#define nsSingleByteCharSetProber_h__

#include "nsCharSetProber.h"

#define SAMPLE_SIZE 64
#define SB_ENOUGH_REL_THRESHOLD  1024
#define POSITIVE_SHORTCUT_THRESHOLD  (float)0.95
#define NEGATIVE_SHORTCUT_THRESHOLD  (float)0.05
#define SYMBOL_CAT_ORDER  250
#define NUMBER_OF_SEQ_CAT 4
#define POSITIVE_CAT   (NUMBER_OF_SEQ_CAT-1)
#define NEGATIVE_CAT   0

struct SequenceModel
{
  const unsigned char* const charToOrderMap;    // [256] table use to find a char's order
  const PRUint8* const precedenceMatrix;  // [SAMPLE_SIZE][SAMPLE_SIZE]; table to find a 2-char sequence's frequency
  float  mTypicalPositiveRatio;     // = freqSeqs / totalSeqs 
  PRBool keepEnglishLetter;         // says if this script contains English characters (not implemented)
  const char* const charsetName;
  SequenceModel(void);
  SequenceModel(const unsigned char* const a, const PRUint8* const  b,float c,PRBool d,const char* const e) 
	  : charToOrderMap(a), precedenceMatrix(b), mTypicalPositiveRatio(c), keepEnglishLetter(d), charsetName(e){}
  SequenceModel& operator=(const SequenceModel&);
} ;


class nsSingleByteCharSetProber : public nsCharSetProber{
public:
  nsSingleByteCharSetProber(const SequenceModel *model) 
    :mModel(model), mReversed(PR_FALSE) { Reset(); }
  nsSingleByteCharSetProber(const SequenceModel *model, PRBool reversed, nsCharSetProber* nameProber)
    :mModel(model), mReversed(reversed), mNameProber(nameProber) { Reset(); }
  nsSingleByteCharSetProber(): mModel(0), mReversed(0){};
  virtual const char* GetCharSetName();
  virtual nsProbingState HandleData(const char* aBuf, PRUint32 aLen);
  virtual nsProbingState GetState(void) {return mState;}
  virtual void      Reset(void);
  virtual float     GetConfidence(void);
  virtual void      SetOpion() {}
  
  // This feature is not implemented yet. any current language model
  // contain this parameter as PR_FALSE. No one is looking at this
  // parameter or calling this method.
  // Moreover, the nsSBCSGroupProber which calls the HandleData of this
  // prober has a hard-coded call to FilterWithoutEnglishLetters which gets rid
  // of the English letters.
  PRBool KeepEnglishLetters() {return mModel->keepEnglishLetter;} // (not implemented)
  nsSingleByteCharSetProber operator=(const nsSingleByteCharSetProber&) = delete;

#ifdef DEBUG_chardet
  virtual void  DumpStatus();
#endif

protected:
  nsProbingState mState = eDetecting;
  const SequenceModel* const mModel = nullptr;
  const PRBool mReversed = PR_FALSE; // PR_TRUE if we need to reverse every pair in the model lookup

  //char order of last character
  unsigned char mLastOrder = 0;

  PRUint32 mTotalSeqs = 0;
  PRUint32 mSeqCounters[NUMBER_OF_SEQ_CAT] = { 0 };

  PRUint32 mTotalChar = 0;
  //characters that fall in our sampling range
  PRUint32 mFreqChar = 0;
  
  // Optional auxiliary prober for name decision. created and destroyed by the GroupProber
  nsCharSetProber* mNameProber = nullptr; 

};


extern const SequenceModel Koi8rModel;
extern const SequenceModel Win1251Model;
extern const SequenceModel Latin5Model;
extern const SequenceModel MacCyrillicModel;
extern const SequenceModel Ibm866Model;
extern const SequenceModel Ibm855Model;
extern const SequenceModel Latin7Model;
extern const SequenceModel Win1253Model;
extern const SequenceModel Latin5BulgarianModel;
extern const SequenceModel Win1251BulgarianModel;
extern const SequenceModel Latin2HungarianModel;
extern const SequenceModel Win1250HungarianModel;
extern const SequenceModel Win1255Model;
extern const SequenceModel TIS620ThaiModel;

extern const SequenceModel Iso_8859_13LithuanianModel;
extern const SequenceModel Iso_8859_10LithuanianModel;
extern const SequenceModel Iso_8859_4LithuanianModel;

extern const SequenceModel Iso_8859_13LatvianModel;
extern const SequenceModel Iso_8859_10LatvianModel;
extern const SequenceModel Iso_8859_4LatvianModel;

extern const SequenceModel Iso_8859_1PortugueseModel;
extern const SequenceModel Iso_8859_9PortugueseModel;
extern const SequenceModel Iso_8859_15PortugueseModel;
extern const SequenceModel Windows_1252PortugueseModel;

extern const SequenceModel Iso_8859_3MalteseModel;

extern const SequenceModel Windows_1250CzechModel;
extern const SequenceModel Iso_8859_2CzechModel;
extern const SequenceModel Ibm852CzechModel;
extern const SequenceModel Mac_CentraleuropeCzechModel;

extern const SequenceModel Windows_1250SlovakModel;
extern const SequenceModel Iso_8859_2SlovakModel;
extern const SequenceModel Ibm852SlovakModel;
extern const SequenceModel Mac_CentraleuropeSlovakModel;

extern const SequenceModel Windows_1250PolishModel;
extern const SequenceModel Iso_8859_2PolishModel;
extern const SequenceModel Iso_8859_13PolishModel;
extern const SequenceModel Iso_8859_16PolishModel;
extern const SequenceModel Ibm852PolishModel;
extern const SequenceModel Mac_CentraleuropePolishModel;

extern const SequenceModel Iso_8859_1FinnishModel;
extern const SequenceModel Iso_8859_4FinnishModel;
extern const SequenceModel Iso_8859_9FinnishModel;
extern const SequenceModel Iso_8859_13FinnishModel;
extern const SequenceModel Iso_8859_15FinnishModel;
extern const SequenceModel Windows_1252FinnishModel;

extern const SequenceModel Iso_8859_1ItalianModel;
extern const SequenceModel Iso_8859_3ItalianModel;
extern const SequenceModel Iso_8859_9ItalianModel;
extern const SequenceModel Iso_8859_15ItalianModel;
extern const SequenceModel Windows_1252ItalianModel;

extern const SequenceModel Windows_1250CroatianModel;
extern const SequenceModel Iso_8859_2CroatianModel;
extern const SequenceModel Iso_8859_13CroatianModel;
extern const SequenceModel Iso_8859_16CroatianModel;
extern const SequenceModel Ibm852CroatianModel;
extern const SequenceModel Mac_CentraleuropeCroatianModel;

extern const SequenceModel Windows_1252EstonianModel;
extern const SequenceModel Windows_1257EstonianModel;
extern const SequenceModel Iso_8859_4EstonianModel;
extern const SequenceModel Iso_8859_13EstonianModel;
extern const SequenceModel Iso_8859_15EstonianModel;

extern const SequenceModel Iso_8859_15IrishModel;
extern const SequenceModel Iso_8859_9IrishModel;
extern const SequenceModel Iso_8859_1IrishModel;
extern const SequenceModel Windows_1252IrishModel;

extern const SequenceModel Windows_1250RomanianModel;
extern const SequenceModel Iso_8859_2RomanianModel;
extern const SequenceModel Iso_8859_16RomanianModel;
extern const SequenceModel Ibm852RomanianModel;

extern const SequenceModel Windows_1250SloveneModel;
extern const SequenceModel Iso_8859_2SloveneModel;
extern const SequenceModel Iso_8859_16SloveneModel;
extern const SequenceModel Ibm852SloveneModel;
extern const SequenceModel Mac_CentraleuropeSloveneModel;

extern const SequenceModel Iso_8859_1SwedishModel;
extern const SequenceModel Iso_8859_4SwedishModel;
extern const SequenceModel Iso_8859_9SwedishModel;
extern const SequenceModel Iso_8859_15SwedishModel;
extern const SequenceModel Windows_1252SwedishModel;

#endif /* nsSingleByteCharSetProber_h__ */

