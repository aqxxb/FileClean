// MyListBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ĵ��ʼ�.h"
#include "MyListBox.h"


// CMyListBox

IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox()
{

}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_WM_PAINT()
	ON_WM_DROPFILES()
END_MESSAGE_MAP()



// CMyListBox ��Ϣ�������




void CMyListBox::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	Scroll();				   // TODO: �ڴ˴������Ϣ����������
	CListBox::OnPaint();	   // ��Ϊ��ͼ��Ϣ���� CListBox::OnPaint()
}


void CMyListBox::OnDropFiles(HDROP hDropInfo)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TCHAR szPath[MAX_PATH] = {};
	// ͳ����ק���ļ��е���Ŀ
	int nCount = DragQueryFile(hDropInfo, -1, szPath, MAX_PATH);
	// �ֱ��ȡÿ���ļ��е�·��
	for (int i = 0; i < nCount; i++)
	{
		DragQueryFile(hDropInfo, i, szPath, MAX_PATH);
		if (LB_ERR == FindString(0, szPath))
		{// ���m_ListBox����û������µ��ļ���·��������ӽ�m_ListBox
			AddString(szPath);
		}
	}
	CListBox::OnDropFiles(hDropInfo);
}

void CMyListBox::Scroll()
{
	CString    str;
	CSize      sz;
	int        dx = 0;
	TEXTMETRIC tm;
	CDC*       pDC = GetDC();
	CFont*     pFont = GetFont();

	// Select the listbox font, save the old font
	CFont* pOldFont = pDC->SelectObject(pFont);
	// Get the text metrics for avg char width
	pDC->GetTextMetrics(&tm);

	for (int i = 0; i < GetCount(); i++)
	{
		GetText(i, str);
		sz = pDC->GetTextExtent(str);

		// Add the avg width to prevent clipping
		sz.cx += tm.tmAveCharWidth;

		if (sz.cx > dx)
			dx = sz.cx;
	}
	// Select the old font back into the DC
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// Set the horizontal extent so every character of all strings 
	// can be scrolled to.
	SetHorizontalExtent(dx);
}
