
// MFC_max_word_chainDlg.h: 头文件
//

#pragma once
#include<string>

using namespace::std;
// CMFCmaxwordchainDlg 对话框
class CMFCmaxwordchainDlg : public CDialogEx
{
// 构造
public:
	CMFCmaxwordchainDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_MAX_WORD_CHAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();

	//data
	string file_path="";
	string head="";
	string tail="";
	afx_msg void OnBnClickedstart();
	afx_msg void OnBnClickedCheck1_w();
	afx_msg void OnBnClickedCheck2_r();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox comb_choose_input;
	afx_msg void OnBnClickedButton2();
};
