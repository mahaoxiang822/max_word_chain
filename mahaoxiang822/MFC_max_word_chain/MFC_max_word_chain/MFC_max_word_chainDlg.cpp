
// MFC_max_word_chainDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_max_word_chain.h"
#include "MFC_max_word_chainDlg.h"
#include "afxdialogex.h"
#include "dll_inputhandler.h"
#include "Core.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCmaxwordchainDlg 对话框



CMFCmaxwordchainDlg::CMFCmaxwordchainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_MAX_WORD_CHAIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCmaxwordchainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCmaxwordchainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCmaxwordchainDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCmaxwordchainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCmaxwordchainDlg::OnBnClickedstart)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCmaxwordchainDlg::OnBnClickedCheck1_w)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCmaxwordchainDlg::OnBnClickedCheck2_r)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCmaxwordchainDlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCmaxwordchainDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCmaxwordchainDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CMFCmaxwordchainDlg 消息处理程序

BOOL CMFCmaxwordchainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCmaxwordchainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCmaxwordchainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCmaxwordchainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCmaxwordchainDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCmaxwordchainDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFile = _T("");

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.txt)|*.jpg|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetPathName();
		file_path = CT2A(strFile.GetBuffer());
		
	}
}


void CMFCmaxwordchainDlg::OnBnClickedstart()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Chead,Ctail;
	CString result;
	vector<string> para;
	InputHandler inputhandler;
	int para_num = 0;
	GetDlgItem(IDC_EDIT2)->GetWindowText(Chead);
	GetDlgItem(IDC_EDIT2)->GetWindowText(Ctail);
	head = CT2A(Chead.GetBuffer());
	tail = CT2A(Ctail.GetBuffer());
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	int state = pBtn->GetCheck();
	if (state == 1) {
		para.push_back("-w");
	}
	else {
		para.push_back("-c");
	}
	para.push_back(file_path);
	para_num = para_num + 2;
	pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
	state = pBtn->GetCheck();
	if (state == 1) {
		para.push_back("-r");
		para_num = para_num + 1;
	}
	if (head != "") {
		para.push_back("-h");
		para.push_back(head);
		para_num = para_num + 1;
	}
	if (tail != "") {
		para.push_back("-t");
		para.push_back(tail);
		para_num = para_num + 1;
	}

	inputhandler.handle_parameters(para_num, para);
	inputhandler.file_read();
	inputhandler.handle_readin();
	inputhandler.clear_duplicate();
	Core core;
	vector<string> ret_res;
	string str_res = "";
	core.max_chain_word(inputhandler.word_list, ret_res, inputhandler.head_ch, inputhandler.tail_ch, inputhandler.enable_loop);
	for (int i = 0; i < ret_res.size(); i++) {
		str_res += ret_res[i] + " ";
	}
	result = str_res.c_str();
	SetDlgItemText(IDC_EDIT1, result);


}


void CMFCmaxwordchainDlg::OnBnClickedCheck1_w()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCmaxwordchainDlg::OnBnClickedCheck2_r()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCmaxwordchainDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCmaxwordchainDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCmaxwordchainDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
