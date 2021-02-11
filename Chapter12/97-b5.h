#pragma once
#include<iostream>
#include<string>
#include <Windows.h>
#include <conio.h>
using namespace std;

class qrcode
{
protected:
	int version;
	int size;
	int** code;
	int nm;
	int am;
	int bm8;
	int km;
public:
	qrcode(int s);
	~qrcode();
	void show(HANDLE hout);
	void fill(string s);
	void mask();
};

void gotoxy(HANDLE hout, const int X, const int Y);
void setcolor(HANDLE hout, const int bg_color, const int fg_color);
string tobin(int,int);
int model(string);
string numcod(string);
string letnumcod(string);
int letnumtab(char);
string hanzicod(string);
string addcod(string);
string errcod(string);







/*ÆäËû*/


// QR_Encode.h : CQR_Encode ƒNƒ‰ƒXéŒ¾‚¨‚æ‚ÑƒCƒ“ƒ^[ƒtƒFƒCƒX’è‹`
// Date 2006/05/17	Ver. 1.22	Psytec Inc.

#if !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
#define AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// ’è”

// Œë‚è’ù³ƒŒƒxƒ‹
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

// ƒf[ƒ^ƒ‚[ƒh
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_KANJI		3

// ƒo[ƒWƒ‡ƒ“(Œ^”Ô)ƒOƒ‹[ƒv
#define QR_VRESION_S	0 // 1 ` 9
#define QR_VRESION_M	1 // 10 ` 26
#define QR_VRESION_L	2 // 27 ` 40

#define MAX_ALLCODEWORD	 3706 // ‘ƒR[ƒhƒ[ƒh”Å‘å’l
#define MAX_DATACODEWORD 2956 // ƒf[ƒ^ƒR[ƒhƒ[ƒhÅ‘å’l(ƒo[ƒWƒ‡ƒ“40-L)
#define MAX_CODEBLOCK	  153 // ƒuƒƒbƒNƒf[ƒ^ƒR[ƒhƒ[ƒh”Å‘å’l(‚q‚rƒR[ƒhƒ[ƒh‚ğŠÜ‚Ş)
#define MAX_MODULESIZE	  177 // ˆê•Óƒ‚ƒWƒ…[ƒ‹”Å‘å’l

// ƒrƒbƒgƒ}ƒbƒv•`‰æƒ}[ƒWƒ“
#define QR_MARGIN	4


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
	int ncRSBlock;		// ‚q‚rƒuƒƒbƒN”
	int ncAllCodeWord;	// ƒuƒƒbƒN“àƒR[ƒhƒ[ƒh”
	int ncDataCodeWord;	// ƒf[ƒ^ƒR[ƒhƒ[ƒh”(ƒR[ƒhƒ[ƒh” - ‚q‚rƒR[ƒhƒ[ƒh”)

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////
// QRƒR[ƒhƒo[ƒWƒ‡ƒ“(Œ^”Ô)ŠÖ˜Aî•ñ

typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	   // ƒo[ƒWƒ‡ƒ“(Œ^”Ô)”Ô†(1`40)
	int ncAllCodeWord; // ‘ƒR[ƒhƒ[ƒh”

					   // ˆÈ‰º”z—ñ“Yš‚ÍŒë‚è’ù³—¦(0 = L, 1 = M, 2 = Q, 3 = H) 
	int ncDataCodeWord[4];	// ƒf[ƒ^ƒR[ƒhƒ[ƒh”(‘ƒR[ƒhƒ[ƒh” - ‚q‚rƒR[ƒhƒ[ƒh”)

	int ncAlignPoint;	// ƒAƒ‰ƒCƒƒ“ƒgƒpƒ^[ƒ“À•W”
	int nAlignPoint[6];	// ƒAƒ‰ƒCƒƒ“ƒgƒpƒ^[ƒ“’†SÀ•W

	RS_BLOCKINFO RS_BlockInfo1[4]; // ‚q‚rƒuƒƒbƒNî•ñ(1)
	RS_BLOCKINFO RS_BlockInfo2[4]; // ‚q‚rƒuƒƒbƒNî•ñ(2)

} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/////////////////////////////////////////////////////////////////////////////
// CQR_Encode ƒNƒ‰ƒX

class CQR_Encode
{
	// \’z/Á–Å
public:
	CQR_Encode();
	~CQR_Encode();

public:
	int m_nLevel;		// Œë‚è’ù³ƒŒƒxƒ‹
	int m_nVersion;		// ƒo[ƒWƒ‡ƒ“(Œ^”Ô)
	BOOL m_bAutoExtent;	// ƒo[ƒWƒ‡ƒ“(Œ^”Ô)©“®Šg’£w’èƒtƒ‰ƒO
	int m_nMaskingNo;	// ƒ}ƒXƒLƒ“ƒOƒpƒ^[ƒ“”Ô†

public:
	int m_nSymbleSize;
	BYTE m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]
														 // bit5:‹@”\ƒ‚ƒWƒ…[ƒ‹iƒ}ƒXƒLƒ“ƒO‘ÎÛŠOjƒtƒ‰ƒO
														 // bit4:‹@”\ƒ‚ƒWƒ…[ƒ‹•`‰æƒf[ƒ^
														 // bit1:ƒGƒ“ƒR[ƒhƒf[ƒ^
														 // bit0:ƒ}ƒXƒNŒãƒGƒ“ƒR[ƒh•`‰æƒf[ƒ^
														 // 20h‚Æ‚Ì˜_—˜a‚É‚æ‚è‹@”\ƒ‚ƒWƒ…[ƒ‹”»’èA11h‚Æ‚Ì˜_—˜a‚É‚æ‚è•`‰æiÅI“I‚É‚ÍBOOL’l‰»j

private:
	int m_ncDataCodeWordBit; // ƒf[ƒ^ƒR[ƒhƒ[ƒhƒrƒbƒg’·
	BYTE m_byDataCodeWord[MAX_DATACODEWORD]; // “ü—Íƒf[ƒ^ƒGƒ“ƒR[ƒhƒGƒŠƒA

	int m_ncDataBlock;
	BYTE m_byBlockMode[MAX_DATACODEWORD];
	int m_nBlockLength[MAX_DATACODEWORD];

	int m_ncAllCodeWord; // ‘ƒR[ƒhƒ[ƒh”(‚q‚rŒë‚è’ù³ƒf[ƒ^‚ğŠÜ‚Ş)
	BYTE m_byAllCodeWord[MAX_ALLCODEWORD]; // ‘ƒR[ƒhƒ[ƒhZoƒGƒŠƒA
	BYTE m_byRSWork[MAX_CODEBLOCK]; // ‚q‚rƒR[ƒhƒ[ƒhZoƒ[ƒN

									// ƒf[ƒ^ƒGƒ“ƒR[ƒhŠÖ˜Aƒtƒ@ƒ“ƒNƒVƒ‡ƒ“
public:
	BOOL EncodeData(int nLevel, int nVersion, BOOL bAutoExtent, int nMaskingNo, LPCSTR lpsSource, int ncSource = 0);

private:
	int GetEncodeVersion(int nVersion, LPCSTR lpsSource, int ncLength);
	BOOL EncodeSourceData(LPCSTR lpsSource, int ncLength, int nVerGroup);

	int GetBitLength(BYTE nMode, int ncData, int nVerGroup);

	int SetBitStream(int nIndex, WORD wData, int ncData);

	BOOL IsNumeralData(unsigned char c);
	BOOL IsAlphabetData(unsigned char c);
	BOOL IsKanjiData(unsigned char c1, unsigned char c2);

	BYTE AlphabetToBinaly(unsigned char c);
	WORD KanjiToBinaly(WORD wc);

	void GetRSCodeWord(LPBYTE lpbyRSWork, int ncDataCodeWord, int ncRSCodeWord);

	// ƒ‚ƒWƒ…[ƒ‹”z’uŠÖ˜Aƒtƒ@ƒ“ƒNƒVƒ‡ƒ“
private:
	void FormatModule();

	void SetFunctionModule();
	void SetFinderPattern(int x, int y);
	void SetAlignmentPattern(int x, int y);
	void SetVersionPattern();
	void SetCodeWordPattern();
	void SetMaskingPattern(int nPatternNo);
	void SetFormatInfoPattern(int nPatternNo);
	int CountPenalty();
};

/////////////////////////////////////////////////////////////////////////////

#endif // !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
