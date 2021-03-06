
// Shablon Enc-DecDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Shablon Enc-Dec.h"
#include "Shablon Enc-DecDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CShablonEncDecDlg dialog



CShablonEncDecDlg::CShablonEncDecDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHABLONENCDEC_DIALOG, pParent)
	, Source_Data(_T(""))
	, Encrypted_Data(_T(""))
	, Decrypted_String(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShablonEncDecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Source_Data);
	DDX_Text(pDX, IDC_EDIT2, Encrypted_Data);
	DDX_Text(pDX, IDC_EDIT3, Decrypted_String);
}

BEGIN_MESSAGE_MAP(CShablonEncDecDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CShablonEncDecDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShablonEncDecDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CShablonEncDecDlg message handlers

BOOL CShablonEncDecDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShablonEncDecDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShablonEncDecDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShablonEncDecDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShablonEncDecDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString input_Pattern("abcjh48w");
	CString output_Pattern("4w8bachj");

	Encrypted_Data = _T("");
	CString pattern;
	int y = 0, length = 0;

	UpdateData(true);

	length = Source_Data.GetLength();

	for (int i = 0; i < length; i++) {
		pattern = Source_Data.GetAt(i);
		y = input_Pattern.Find(pattern);
		if (y > -1) {
			Encrypted_Data = Encrypted_Data + output_Pattern.GetAt(y);
		}
		else {
			Encrypted_Data = Encrypted_Data + pattern;
		}
	}

	UpdateData(false);
}




void CShablonEncDecDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString input_Pattern("abcjh48w");
	CString output_Pattern("4w8bachj");

	Decrypted_String = _T("");
	CString pattern;

	int y = 0, length = 0;

	UpdateData(true);

	length = Encrypted_Data.GetLength();

	for (int i = 0; i < length; i++) {
		pattern = Encrypted_Data.GetAt(i);
		y = output_Pattern.Find(pattern);
		if (y > -1) {
			Decrypted_String = Decrypted_String + input_Pattern.GetAt(y);
		}
		else {
			Decrypted_String = Decrypted_String + pattern;
		}
	}
	UpdateData(false);
}
