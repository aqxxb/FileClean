
// �����ĵ��ʼ�Dlg.h : ͷ�ļ�
//

#pragma once
#include "MyListBox.h"
#include <vector>
using std::vector;

// C�����ĵ��ʼ�Dlg �Ի���
class C�����ĵ��ʼ�Dlg : public CDialogEx
{
// ����
public:
	C�����ĵ��ʼ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void TraverseFile(TCHAR szPath[MAX_PATH], /* Ҫ�������ļ�·�� */ const CString &strFilter,/* ���˵��ļ���׺ */ vector<CString> &vecPath);// ������������ļ�;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString m_Edit1;
	CString m_Edit2;
	CMyListBox m_ListBox1;
	CMyListBox m_ListBox2;
	// ����Ҫ�����������ļ�·��
	vector<CString> m_vecFileDelete;
};
