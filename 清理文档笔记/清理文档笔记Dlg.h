
// 清理文档笔记Dlg.h : 头文件
//

#pragma once
#include "MyListBox.h"
#include <vector>
using std::vector;

// C清理文档笔记Dlg 对话框
class C清理文档笔记Dlg : public CDialogEx
{
// 构造
public:
	C清理文档笔记Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void TraverseFile(TCHAR szPath[MAX_PATH], /* 要遍历的文件路径 */ const CString &strFilter,/* 过滤的文件后缀 */ vector<CString> &vecPath);// 保存遍历到的文件;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString m_Edit1;
	CString m_Edit2;
	CMyListBox m_ListBox1;
	CMyListBox m_ListBox2;
	// 保存要遍历的垃圾文件路径
	vector<CString> m_vecFileDelete;
};
