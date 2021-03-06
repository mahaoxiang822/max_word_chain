
// MFC_max_word_chainDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_max_word_chain.h"
#include "MFC_max_word_chainDlg.h"
#include "afxdialogex.h"
#include "../Core/Core.h"
#include "../Core/Solve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

vector<string> word_list;
string readin = "";
bool enable_loop = false;
char head_ch = 0;
char tail_ch = 0;
string inputfile_path = "";

vector<string> array2string(char *words[], int len) {
	vector<string> res;
	string s;
	for (int i = 0; i < len; i++) {
		s = words[i];
		res.push_back(s);
	}
	return res;
}
int string2array(vector<string> string_list, char *words[]) {//返回长度
	int size = (int)string_list.size();
	for (int i = 0; i < size; i++) {
		int len = string_list[i].length();
		words[i] = new char[len + 3];
		strcpy_s(words[i], len + 3, string_list[i].c_str());
	}
	return size;
}
bool console_read() {
	return true;
}

bool file_read() {

	ifstream wordlist;
	ostringstream content;
	try {
		wordlist.open(inputfile_path, ios::in);
		content << wordlist.rdbuf();
		readin = content.str();
	}
	catch (...) {
		throw("file read exception");
	}
	return true;
}

void string_read(string input) {
	try {
		readin = input;
	}
	catch (...) {
		throw("gui input exception");
	}
}

void handle_readin() {

	string word = "";
	try {
		for (int i = 0; i < (int)readin.size(); i++) {
			if (('a' <= readin[i] && 'z' >= readin[i]) ||
				('A' <= readin[i] && 'Z' >= readin[i])) {
				char temp = readin[i];
				if ('A' <= temp && 'Z' >= temp) {
					temp = temp - ('A' - 'a');
				}
				word += temp;
			}
			else {
				if (word.size() == 0) {
					continue;
				}
				else
				{
					word_list.push_back(word);
					word = "";
				}
			}
		}
		if (word.size() != 0) {
			word_list.push_back(word);
			word = "";
		}
	}
	catch (...) {
		throw("handle readin exception");
	}
}


void clear_duplicate() {
	try {
		sort(word_list.begin(), word_list.end());
		word_list.erase(unique(word_list.begin(), word_list.end()), word_list.end());
	}
	catch (...) {
		throw("clear duplicate word exception");
	}

}

void handle_parameters(int para_num, vector<string> para) {
	try {
		for (int i = 0; i < para_num; i++) {
			if (para[i] == "-w" && i < para_num - 1) {
				inputfile_path = para[i + 1];
			}
			if (para[i] == "-c" && i < para_num - 1) {
				inputfile_path = para[i + 1];
			}
			if (para[i] == "-h" && i < para_num - 1) {
				head_ch = para[i + 1][0];
			}
			if (para[i] == "-t" && i < para_num - 1) {
				tail_ch = para[i + 1][0];
			}
			if (para[i] == "-r") {
				enable_loop = true;
			}
		}
	}
	catch (...) {
		throw("handle parameters error");
	}
}
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
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMFCmaxwordchainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, comb_choose_input);
}

BEGIN_MESSAGE_MAP(CMFCmaxwordchainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCmaxwordchainDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCmaxwordchainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCmaxwordchainDlg::OnBnClickedstart)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCmaxwordchainDlg::OnBnClickedCheck2_r)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCmaxwordchainDlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCmaxwordchainDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCmaxwordchainDlg::OnEnChangeEdit3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCmaxwordchainDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCmaxwordchainDlg::OnBnClickedButton2)
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
	comb_choose_input.AddString(_T("选择文件输入(默认)"));
	comb_choose_input.AddString(_T("直接输入"));
	comb_choose_input.SetCurSel(0);


	CButton* radio = (CButton*)GetDlgItem(IDC_max_word);
	radio->SetCheck(1);

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

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files All Files (*.*)|*.*||"), NULL);
	try {
		if (dlgFile.DoModal())
		{
			strFile = dlgFile.GetPathName();
			file_path = CT2A(strFile.GetBuffer());

		}
	}
	catch (...) {
		MessageBox(_T("GUI_EXCEPTION:choose file exception"));
	}
}


void CMFCmaxwordchainDlg::OnBnClickedstart()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Chead, Ctail, Cinput;
	CString result;
	vector<string> para;
	int para_num = 0;
	int mode = comb_choose_input.GetCurSel();
	bool max_word = true;
	//-------------
	word_list.clear();
	readin = "";
	enable_loop = false;
	head_ch = 0;
	tail_ch = 0;
	inputfile_path = "";
	//-------------
	try {
		GetDlgItem(IDC_EDIT2)->GetWindowText(Chead);
		GetDlgItem(IDC_EDIT3)->GetWindowText(Ctail);
		GetDlgItem(IDC_EDIT4)->GetWindowText(Cinput);
		head = CT2A(Chead.GetBuffer());
		tail = CT2A(Ctail.GetBuffer());
		int state = GetCheckedRadioButton(IDC_max_word, IDC_max_length);

		if (state == IDC_max_word) {
			para.push_back("-w");
			max_word = true;
		}
		else {
			para.push_back("-c");
			max_word = false;
		}
		para.push_back(file_path);
		para_num = para_num + 2;
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
		state = pBtn->GetCheck();
		if (state == 1) {
			para.push_back("-r");
			para_num = para_num + 1;
		}
		if (head != "") {
			para.push_back("-h");
			para.push_back(head);
			para_num = para_num + 2;
		}
		if (tail != "") {
			para.push_back("-t");
			para.push_back(tail);
			para_num = para_num + 2;
		}
	}
	catch (...) {
		MessageBox(_T("GUI_EXCEPTION:gui elements have something wrong"));
	}
	try {
		handle_parameters(para_num, para);
		if (mode == 1) {
			string input = CT2A(Cinput.GetBuffer());
			string_read(input);
		}
		else {
			file_read();
		}
		handle_readin();
		clear_duplicate();
		vector<string> ret_res;
		string str_res = "";
		int wsize = (int)word_list.size();
		char **in = new char *[wsize + 5];
		char **res = new char*[wsize + 5];
		string2array(word_list, in);
		int res_len ;
		if (max_word) {
			res_len = Core::gen_chain_word(in, wsize, res, head_ch, tail_ch, enable_loop);
		}
		else {
			res_len = Core::gen_chain_char(in, wsize, res, head_ch, tail_ch, enable_loop);
		}

		ret_res = array2string(res, res_len);
		for (int i = 0; i < (int) ret_res.size(); i++) {
			str_res += ret_res[i] + " ";
		}
		result = str_res.c_str();
		SetDlgItemText(IDC_EDIT1, result);
	}
	catch (const char *error_message) {
		string x(error_message);
		CString message(x.c_str());
		MessageBox(message);
	}


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



void CMFCmaxwordchainDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCmaxwordchainDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString gReadFilePathName1;
	CFileDialog fileDlg(false, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt Files (*.txt)|*.txt|All File (*.*)|*.*||"), NULL);
	try {
		if (fileDlg.DoModal() == IDOK)    //弹出对话框
		{
			char* pOldLocale = _strdup(setlocale(LC_CTYPE, NULL));
			setlocale(LC_CTYPE, "chs");
			gReadFilePathName1 = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名
		}
		CStdioFile file;
		CString strText;
		GetDlgItem(IDC_EDIT1)->GetWindowText(strText);

		file.Open(gReadFilePathName1, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		GetDlgItemText(IDC_EDIT1, strText); //获取edit box中的数据
		file.WriteString(strText);  //写入edit box中的数据
		file.Close();
		MessageBox(_T("save success"));
	}
	catch (...) {
		MessageBox(_T("GUI_EXCEPTION:save data exception"));
	}
	//如果是多个编辑框，添加多条语句，此处省略
	
}
