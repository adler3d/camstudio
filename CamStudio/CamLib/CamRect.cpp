// recatangle.cpp	- CamStudio Library rectangle functions
/////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "CamRect.h"

BOOL isRectEqual(RECT a, RECT b)
{
	CRect rectA(a);
	return rectA == b;

	//if ((a.left == b.left)
	//	&& (a.right == b.right)
	//	&& (a.top == b.top)
	//	&& (a.bottom == b.bottom))
	//	return TRUE;
	//else
	//	return FALSE;
}

// The rectangle is normalized for fourth-quadrant positioning, which Windows typically uses for coordinates.
// this is dubious
void NormalizeRect(LPRECT prc)
{
	CRect rectSrc(*prc);
	rectSrc.NormalizeRect();
	::CopyRect(prc, rectSrc);
}

void FixRectSizePos(LPRECT prc, int maxxScreen, int maxyScreen, int minxScreen, int minyScreen)
{
	NormalizeRect(prc);

	int width = prc->right - prc->left + 1;
	int height = prc->bottom - prc->top + 1;

	//check that rectangle isn't too wide
	if (width > abs(maxxScreen-minxScreen)) {
		prc->left = minxScreen;
		prc->right = maxxScreen - 1;
	}
	else
	{
		//adjust left and right to make sure its on the screen
		if (prc->left < minxScreen) {
			prc->left = minxScreen;
		}
		if (prc->right > maxxScreen - 1) {
			prc->right = maxxScreen - 1;
		}
	}

	//check that rectangle isn't too tall
	if (height > abs(maxyScreen-minyScreen)) {
		prc->top = minyScreen;
		prc->bottom = maxyScreen - 1;
	}
	else
	{
		//adjust top and bottom to make sure its on the screen
		if (prc->top < minyScreen) {
			prc->top = minyScreen;
		}
		if (prc->bottom > maxyScreen - 1) {
			prc->bottom = maxyScreen - 1;
		}
	}
}
