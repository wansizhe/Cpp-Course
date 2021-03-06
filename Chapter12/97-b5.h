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


// QR_Encode.h : CQR_Encode NXé¾¨æÑC^[tFCXè`
// Date 2006/05/17	Ver. 1.22	Psytec Inc.

#if !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
#define AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// è

// ëèù³x
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

// f[^[h
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_KANJI		3

// o[W(^Ô)O[v
#define QR_VRESION_S	0 // 1 ` 9
#define QR_VRESION_M	1 // 10 ` 26
#define QR_VRESION_L	2 // 27 ` 40

#define MAX_ALLCODEWORD	 3706 // R[h[hÅål
#define MAX_DATACODEWORD 2956 // f[^R[h[hÅål(o[W40-L)
#define MAX_CODEBLOCK	  153 // ubNf[^R[h[hÅål(qrR[h[hðÜÞ)
#define MAX_MODULESIZE	  177 // êÓW[Åål

// rbg}bv`æ}[W
#define QR_MARGIN	4


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
	int ncRSBlock;		// qrubN
	int ncAllCodeWord;	// ubNàR[h[h
	int ncDataCodeWord;	// f[^R[h[h(R[h[h - qrR[h[h)

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////
// QRR[ho[W(^Ô)ÖAîñ

typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	   // o[W(^Ô)Ô(1`40)
	int ncAllCodeWord; // R[h[h

					   // ÈºzñYÍëèù³¦(0 = L, 1 = M, 2 = Q, 3 = H) 
	int ncDataCodeWord[4];	// f[^R[h[h(R[h[h - qrR[h[h)

	int ncAlignPoint;	// ACgp^[ÀW
	int nAlignPoint[6];	// ACgp^[SÀW

	RS_BLOCKINFO RS_BlockInfo1[4]; // qrubNîñ(1)
	RS_BLOCKINFO RS_BlockInfo2[4]; // qrubNîñ(2)

} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/////////////////////////////////////////////////////////////////////////////
// CQR_Encode NX

class CQR_Encode
{
	// \z/ÁÅ
public:
	CQR_Encode();
	~CQR_Encode();

public:
	int m_nLevel;		// ëèù³x
	int m_nVersion;		// o[W(^Ô)
	BOOL m_bAutoExtent;	// o[W(^Ô)©®g£wètO
	int m_nMaskingNo;	// }XLOp^[Ô

public:
	int m_nSymbleSize;
	BYTE m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]
														 // bit5:@\W[i}XLOÎÛOjtO
														 // bit4:@\W[`æf[^
														 // bit1:GR[hf[^
														 // bit0:}XNãGR[h`æf[^
														 // 20hÆÌ_aÉæè@\W[»èA11hÆÌ_aÉæè`æiÅIIÉÍBOOLl»j

private:
	int m_ncDataCodeWordBit; // f[^R[h[hrbg·
	BYTE m_byDataCodeWord[MAX_DATACODEWORD]; // üÍf[^GR[hGA

	int m_ncDataBlock;
	BYTE m_byBlockMode[MAX_DATACODEWORD];
	int m_nBlockLength[MAX_DATACODEWORD];

	int m_ncAllCodeWord; // R[h[h(qrëèù³f[^ðÜÞ)
	BYTE m_byAllCodeWord[MAX_ALLCODEWORD]; // R[h[hZoGA
	BYTE m_byRSWork[MAX_CODEBLOCK]; // qrR[h[hZo[N

									// f[^GR[hÖAt@NV
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

	// W[zuÖAt@NV
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
