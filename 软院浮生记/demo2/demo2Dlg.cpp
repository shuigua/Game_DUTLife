// demo2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "demo2Dlg.h"
#include "hapwarn30.h"
#include "warn30result.h"
#include "hajime.h"
#include "gameover.h"
#include "gamepass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#define EVENT_COUNT 4

typedef struct Normal_event {
	char * name;
	int min_hap;
	int max_hap;
	int min_sco;
	int max_sco;
} Nor;

/*Nor normal[EVENT_COUNT] = {
	{"�Ͽ�",-3,2,-1,3},
	{"���",-2,2,-3,2},
	{"�",0,3,-2,2},
	{"��ϰ",-2,2,-1,4}
};*/

Nor normal[EVENT_COUNT] = {
	{"�Ͽ�",-3,3,-1,3},
	{"���",-2,3,-3,3},
	{"�",0,3,-2,3},
	{"��ϰ",-2,3,-1,3}
};

#define NORMAL_RANDOM_COUNT 48

typedef struct Normal_random {
	char * name;
	double hap_impact;
	double sco_impact;
} Nor_ipt;

Nor_ipt normal_impact[NORMAL_RANDOM_COUNT] = {
	{"�㿪���������֣�ֱ������ϰ���뿪\r\n�Ҹ���+ �ɼ�-", 2, 0.8},
	{"�����ܵؿ�����ģ���һ��ppt\r\n�Ҹ���- �ɼ�+", 0.8, 2},
	{"�ɹ�������Сʱ��������w\r\n�Ҹ���+ �ɼ�+", 2, 2},
	{"a��Բ�������˰��ϵĴ�����У��ַ��ӽ̻���\r\n�Ҹ���+ �ɼ�+", 2, 2},
	{"ˢ�������ӣ�����������������Сʱ���û�����ǶԵ�\r\n������֪���Լ��������\r\n�Ҹ���-", 0.9, 1.0},
	{"������������������е�̬�ȿ��˺ü����վ磨ѧϰ��ι����\r\n�Ҹ���+ �ɼ�-", 2, 0.9},
	{"�����﷨������������𰸸�������\r\n��������������ͷ��.jpg\r\n�Ҹ���- �ɼ�+", 0.8, 2},
	{"��������Сʱ����������һ�����⣬\r\n��������ȥ�ٳ���ʮȦ\r\n�Ҹ���+ �ɼ�+", 2, 2},
	{"��������ʼǣ��������ŵĺ���������Ŀ�ıʼǱ�\r\n��װ������.jpg\r\n�Ҹ���+ �ɼ�+", 2, 2},
	{"���ڻ��������������ˣ�\r\n�����ڲݸ�ֽ�ϻ���һ�����߰����С��\r\n�ɼ�-", 1.0, 0.8},
	{"���г�������һ��bug������һ�������У�\r\n�����200+��bug���Ĳ����\r\n�Ҹ���-", 0.8, 1.0},
	{"��С�ĵ㿪��֪�������ǲ�С�Ŀ���������Сʱ��\r\n��Ϊѧ���˺ܶ����������������߳��˽���\r\n�Ҹ���+ �ɼ�-", 2, 0.8},
	{"�����õ��������ΪĿ�꿪ʼѧϰ��\r\n�����������������ķϵļ��ڣ���ܾ�ѧϰ\r\n�Ҹ���- �ɼ�-", 0.8, 0.8},
	{"���ε��ֻ�����ͻȻ����ϰ�ҿ�����������\r\n�Ҹ���-", 0.7, 1},
	{"��ͬѧ�Ĺ�����ҵ\r\n����Ȼ��ƭ�Լ������˵ĳ���\r\n�Ҹ���+ �ɼ�-", 2, 0.9},
	{"����Сʱ��[����]���c++���ϰ��һ����\r\n�о��Լ����Ժ͵�����ս��\r\n�Ҹ���+ �ɼ�+", 2, 2},
	{"��ͬѧ��ȥ���ڣ����ݶ�ȥ\r\n�Ҹ���+ �ɼ�-", 2, 0.8},

	{"������ȣ���������ֵ��������������\r\n�������ʦ�������ص��������С���\r\n�Ҹ���- �ɼ�-", 0.8, 0.8},
	{"������ʦ̸�����Լ����ձ��������ͻȻ��ѧ������\r\n�Ҹ���+ �ɼ�+", 1.2, 1.2},
	{"������ѧ��ʦ�Ŀ�������ѧ���˼�����С�ж���\r\n�Ҹ���+ �ɼ�+", 1.2, 1.2},
	{"����ѧ��ʦ���˶�ʮ���ӽ��������������������ɽ\r\n�Ҹ���+ �ɼ�-", 1.3, 0.7},
	{"���յ��˽��Ҳŷ������Ǵ�����ҵ����\r\n�Ҹ���- �ɼ�-", 0.7, 0.7},
	{"ûд��������ҵ������Ч�ʼ���\r\n�Ҹ���- �ɼ�-", 0.7, 0.7},
	{"���տομ�����Լ������ĸ裬ѧϰ��������\r\n�Ҹ���+ �ɼ�+", 1.3, 1.3},
	{"���ϵ���ʵ���Ҵ���Ь�ĸ���ʦ��ʵ��Σ�\r\n��3��camera��С��������ͷ����\r\n��ǰ��ab�����ʱ�����ŵù����ǲ���.jpg\r\n�Ҹ���- �ɼ�-", 0.5, 0.5},
	{"�����ο���Ự�鵽�Լ��飬\r\n�ɥ��ɥ����������Υ��ɥХ��������ơ������ʤ�ޤ���\r\n�Ҹ���+ �ɼ�+", 1.3, 1.3},
	{"�������ź����ʦ���������Ľ��Σ����������������ⲻ�ܶ��е��Ա�\r\n�Ҹ���- �ɼ�+", 0.7, 1},
	{"�Ͽ������˺����ʦ���ĳ���Ա���ӣ�\r\n��Ц��ͬʱ���ܵ��Լ���ǰ;δ��\r\n�Ҹ���+ �ɼ�-", 1.2, 0.9},
	{"�˶�����ȥ�����ڰټҽ�̳��������\r\n�Ҹ���+ �ɼ�+", 1.3, 1.2},
	{"���Ŵ����������������ѧϰ������һ���½�\r\n�Ҹ���+ �ɼ�+", 1.3, 1.3},
	{"���������ppt����˯�������ԣ��Ҹ�����ûѧ��c++\r\n�Ҹ���- �ɼ�+", 0.8, 1.3},
	{"���ð��������ʦ��٣���������ʱ�ô��﷨���ò������Ͽ�\r\n�Ҹ���- �ɼ�+", 0.7, 1.3},
	{"�Ͽγٵ�����㱻һ��ʱ������ŵĺ����ʦ��֮����\r\n�Ҹ���- �ɼ�-", 0.7, 0.8},
	{"���տγٵ�����ʦ�ǵ�С������\r\n�Ҹ���- �ɼ�-", 0.7, 0.9},

	{"����Ϸ\r\n�Ҹ���+ �ɼ�-", 1.5, 0.8},
	{"����Ӱ\r\n�Ҹ���+ �ɼ�-", 1.3, 0.9},
	{"����\r\n�Ҹ���+ �ɼ�-", 1.3, 0.9},
	{"һ����ȥ����ɢ��\r\n�Ҹ���+ �ɼ�-", 1.3, 0.8},
	{"�ſա�������������������\r\n�Ҹ���+ �ɼ�-", 1.3, 0.9},
	{"�Ǻǣ���������Сʱ��ɨ���䣨�����ڵ�\r\n�Ҹ���++", 1.2, 1.0},
	{"��ͬѧ��绰��ɻ���\r\n�Ҹ���+ �ɼ�-", 1.5, 0.9},
	{"���飨����һ�����ȥˢ�ֻ�\r\n�Ҹ���+ �ɼ�-", 1.2, 0.8},

	{"�ǩ`��w\r\n�Ҹ���+ �ɼ�+", 3, 1.3},
	{"һ��ȥ�����\ɽ��\r\n�Ҹ���+ �ɼ�+", 2, 1.2},
	{"�Ž����ڵ���ΰ���쵼�£�����������â����ҫ�½��ܹ��������Ѭ��\r\n�Ҹ���- �ɼ�+", 0.5, 1.2},
	{"������ ͼ��� ־Ը�� �����֣�\r\n�Ҹ���+ �ɼ�+", 1.3, 1.2},
	{"�����ֻ棨ʳ�ä�\r\n�Ҹ���+ �ɼ�+", 1.5, 1.2},
	{"���質���賿������ͨ������ΪĳЩ��˵Ҫ���Լ����Գ����ڶ�������\r\n�Ҹ���+ �ɼ�-", 1.8, 0.9}
};

#define RANDOM_COUNT 22


typedef struct random {
	char * name;
	double hap_random_impact;
	double sco_random_impact;
} Ran_ipt;

Ran_ipt random_impact[RANDOM_COUNT] = {
	{"·��ż����ѧ����˳��Ҫ���˼����ʼǵ���\r\n�Ҹ���+ �ɼ�+", 1, 3},
	{"�������������������  ������������������������\r\n�Ҹ���+ �ɼ�-", 3, -1},
	{"�����ȥ�������ݶ������壬������ˮ������ʮ�㣨����Ҳ��ɼ���������\r\n�Ҹ���+ �ɼ�+", 2, 1},
	{"·�϶�����������ת���ڡ���Ժѧ��ѧ����æ��Ⱥ�ﱻ�˼�\r\n�Ҹ���+", 2.2, 0},
	{"��С�ļ���һ��Կ�� ���ԭ�� ����Ϊ�� \r\nʧ���Ǹ�����  �S����\r\n�Ҹ���+", 3, 0},
	{"��·�ϴ���������Ϸ��ʱ������������ʦ  \r\n����ʦ������һ������  (��o��)������\r\n�Ҹ���- �ɼ�-", -1.2, -1},
	{"����Ĵ��������ʮ�ֲ�� \r\n���һ��������ķ���\r\n�Ҹ���-", -1.4, 0},
	{"������С���ߵ���  û���õ��ҵĿ��  \r\n������/(��o��)/~~\r\n�Ҹ���-", -1, 0},
	{"�ҵĽ��п��ֱ��̵��� ɶʱ���еķ����ܺ�һ�㰡 \r\n�Ҹ���-", -0.8, 0},
	{"��ĳԷ�������˹��ڵ�***   ��Ϊ��ԺΨһһ������  \r\n���ֶ���������mmp\r\n�Ҹ���-", -1.7, 0},
	{"�̲����ĵĵ����Ͼ�Ȼ�в���  �ҵ�ѧϰ���ϱ��ɵ��� \r\n�ҵ�U��555~~  ����  ��Ҳ��ȥ��\r\n�Ҹ���- �ɼ�-", -1.2, -2},
	{"������ȥ�����ݶ������壬�������λ��ȫ����ʦռ��\r\n�Ҹ���- �ɼ�-", -1, -0.1},
	{"ϴ�����Ǵ����ѹ������ٴ���  ������\r\n�Ҹ���-", -1.9, 0},
	{"·�϶�����������������ֱ���ˢ100��Ǯ\r\n�Ҹ���-", -2, 0},
	{"·���������Լ�������/Ů�񣬼����˰���\r\n�Ҹ���-", 3, 0},
	{"��ð�ˣ�ҽ���ҵĴ�ү���ĵĸ��ҿ���һƿ����¶\r\n�Ҹ���+ �ɼ�+", 3, 2},
	{"С�����ѳ��ѣ����ޱ��������컨��\r\n�Ҹ���- �ɼ�-", -3, -1},
	{"��С�ĵ���ӿȪ����\r\n�Ҹ���-", -4, 0},
	{"����һ�����ӣ��ڶ�����ʩ���������Ϸ���ͬ�����һ��\r\n�Ҹ���-", -3, 0},
	{"·��Ұ��\r\n�Ҹ���-", -2, 0},
	{"��·ײǽ\r\n�Ҹ���-", -2, 0},
	{"��Ⱥ��ʱ��żȻ��ȡ�����������\r\n�Ҹ���+ �ɼ�+", 3, 3}
};


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo2Dlg dialog

CDemo2Dlg::CDemo2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemo2Dlg::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(CDemo2Dlg)
	m_out = _T("");
	m_remain = 0;
	m_hap = 0.0;
	m_sco = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	count = 45;
	m_remain = 15;
	m_hap = 80;
	m_sco = 20;
	happy30warn_count = 0;
	//SetDlgItemText(IDC_EDIT_change, "����");
}

void CDemo2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemo2Dlg)
	DDX_Text(pDX, IDC_EDIT_output, m_out);
	DDX_Text(pDX, IDC_EDIT_day, m_remain);
	DDX_Text(pDX, IDC_EDIT_happy, m_hap);
	DDX_Text(pDX, IDC_EDIT_score, m_sco);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemo2Dlg, CDialog)
	//{{AFX_MSG_MAP(CDemo2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_class, OnBUTTONclass)
	ON_BN_CLICKED(IDC_BUTTON_rest, OnBUTTONrest)
	ON_BN_CLICKED(IDC_BUTTON_outplay, OnBUTTONoutplay)
	ON_BN_CLICKED(IDC_BUTTON_selfstudy, OnBUTTONselfstudy)
	ON_BN_CLICKED(IDC_BUTTON4, OnButtonhajime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo2Dlg message handlers

BOOL CDemo2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CDemo2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemo2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemo2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemo2Dlg::OnBUTTONclass() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;
	
	//double m_hap_basic = normal[0].min_hap + rand() % ((normal[0].max_hap - normal[0].min_hap) + 1);
	//double m_sco_basic = normal[0].min_sco + rand() % ((normal[0].max_sco - normal[0].min_sco) + 1);
	
	

	int news_id = 0 * 3 + rand() % 17+17;
	
	double m_hap_basic;
	double m_sco_basic;
	
	if (normal_impact[news_id].hap_impact > 1)
	{
		//m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
		m_hap_basic = 0.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}
	else
	{
		//m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
		m_hap_basic = -1.4 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}

	if (normal_impact[news_id].sco_impact > 1)
	{
		//m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
		m_sco_basic = 1.5 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	else
	{
		//m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
		m_sco_basic = -0.5 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	
	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 2) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}

	UpdateData(false);
	
	if((count == 0)&&(m_sco < 60))
	{
		gameover dlg;
		dlg.DoModal();
		exit(0);
	} else if((count == 0)&&(m_sco >= 60))
	{
		gamepass dlg;
		dlg.DoModal();
		exit(0);
	}

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	SetDlgItemText(IDC_EDIT_output, normal_impact[news_id].name);

	int c = count % 3;
	if(c == 0) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	//SetDlgItemText(IDC_EDIT_output, "hi");
	

}

void CDemo2Dlg::OnBUTTONrest() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;

	//double m_hap_basic = normal[1].min_hap + rand() % ((normal[1].max_hap - normal[1].min_hap) + 1);
	//double m_sco_basic = normal[1].min_sco + rand() % ((normal[1].max_sco - normal[1].min_sco) + 1);
	
	int news_id = 0 * 3 + rand() % 8 + 34;
	
	

	
	/*if (m_hap_basic > 0)
	{
		m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
	}
	else
	{
		m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
	}

	if (m_sco_basic > 0)
	{
		m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
	}
	else
	{
		m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	m_hap *= 1.05;
	
	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 10) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}*/

	double m_hap_basic;
	double m_sco_basic;
	
	if (normal_impact[news_id].hap_impact > 1)
	{
		//m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
		m_hap_basic = 1.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}
	else
	{
		//m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
		m_hap_basic = 0.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}

	if (normal_impact[news_id].sco_impact > 1)
	{
		//m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
		m_sco_basic = 0.3 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	else
	{
		//m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
		m_sco_basic = -0.8 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	
	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 2) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}

	UpdateData(false);

	if((count == 0)&&(m_sco < 60))
	{
		gameover dlg;
		dlg.DoModal();
		exit(0);
	} else if((count == 0)&&(m_sco >= 60))
	{
		gamepass dlg;
		dlg.DoModal();
		exit(0);
	}

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	SetDlgItemText(IDC_EDIT_output, normal_impact[news_id].name);


	int c = count % 3;
	if(c == 0) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
}

void CDemo2Dlg::OnBUTTONoutplay()   //�
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;

	//double m_hap_basic = normal[2].min_hap + rand() % ((normal[2].max_hap - normal[2].min_hap) + 1);
	//double m_sco_basic = normal[2].min_sco + rand() % ((normal[2].max_sco - normal[2].min_sco) + 1);
	
	int news_id = 0 * 3 + rand() % 6 + 42;
	
	

	/*
	if (m_hap_basic > 0)
	{
		m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
	}
	else
	{
		m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
	}

	if (m_sco_basic > 0)
	{
		m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
	}
	else
	{
		m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 10) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}
	*/

	double m_hap_basic;
	double m_sco_basic;
	
	if (normal_impact[news_id].hap_impact > 1)
	{
		//m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
		m_hap_basic = 1.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}
	else
	{
		//m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
		m_hap_basic = -0.7 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}

	if (normal_impact[news_id].sco_impact > 1)
	{
		//m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
		m_sco_basic = 0.4 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	else
	{
		//m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
		m_sco_basic = -0.4 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	
	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 2) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}

	UpdateData(false);

	if((count == 0)&&(m_sco < 60))
	{
		gameover dlg;
		dlg.DoModal();
		exit(0);
	} else if((count == 0)&&(m_sco >= 60))
	{
		gamepass dlg;
		dlg.DoModal();
		exit(0);
	}

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	SetDlgItemText(IDC_EDIT_output, normal_impact[news_id].name);


	int c = count % 3;
	if(c == 0) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
}

/*void CDemo2Dlg::OnBUTTONmeal()							//���õ�����ģ�鹦��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;

	double m_hap_basic = normal[3].min_hap + rand() % ((normal[3].max_hap - normal[3].min_hap) + 1);
	double m_sco_basic = normal[3].min_sco + rand() % ((normal[3].max_sco - normal[3].min_sco) + 1);
	
	int news_id = 3 * 3 + rand() % 3+0;
	
	

	
	if (m_hap_basic > 0)
	{
		m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
	}
	else
	{
		m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
	}

	if (m_sco_basic > 0)
	{
		m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
	}
	else
	{
		m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 16;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	UpdateData(false);

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	if(news_id == 9) SetDlgItemText(IDC_EDIT_output, "ʳ�ô����ֶ�����");
	else if(news_id == 10) SetDlgItemText(IDC_EDIT_output, "�Ե���������");
	else if(news_id == 11) SetDlgItemText(IDC_EDIT_output, "ѧϰ���ڷ�æ��������");

	int c = count % 3;
	if(c == 2) SetDlgItemText(IDC_EDIT_change, "����");
	if(c == 1) SetDlgItemText(IDC_EDIT_change, "����");
	if(c == 0) SetDlgItemText(IDC_EDIT_change, "����");
}

void CDemo2Dlg::OnBUTTONactivity() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;

	double m_hap_basic = normal[4].min_hap + rand() % ((normal[4].max_hap - normal[4].min_hap) + 1);
	double m_sco_basic = normal[4].min_sco + rand() % ((normal[4].max_sco - normal[4].min_sco) + 1);
	
	int news_id = 4 * 3 + rand() % 3+0;
	
	

	
	if (m_hap_basic > 0)
	{
		m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
	}
	else
	{
		m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
	}

	if (m_sco_basic > 0)
	{
		m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
	}
	else
	{
		m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 16;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	UpdateData(false);

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	if(news_id == 12) SetDlgItemText(IDC_EDIT_output, "ʳ�ô����ֶ�����");
	else if(news_id == 13) SetDlgItemText(IDC_EDIT_output, "�Ե���������");
	else if(news_id == 14) SetDlgItemText(IDC_EDIT_output, "ѧϰ���ڷ�æ��������");

	int c = count % 3;
	if(c == 2) SetDlgItemText(IDC_EDIT_change, "����");
	if(c == 1) SetDlgItemText(IDC_EDIT_change, "����");
	if(c == 0) SetDlgItemText(IDC_EDIT_change, "����");
}*/

void CDemo2Dlg::OnBUTTONselfstudy() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	count--;
	m_remain = count / 3;

	//double m_hap_basic = normal[3].min_hap + rand() % ((normal[3].max_hap - normal[3].min_hap) + 1);
	//double m_sco_basic = normal[3].min_sco + rand() % ((normal[3].max_sco - normal[3].min_sco) + 1);
	
	int news_id = 0 * 3 + rand() % 17 + 0;
	
	

	/*
	if (m_hap_basic > 0)
	{
		m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
	}
	else
	{
		m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
	}

	if (m_sco_basic > 0)
	{
		m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
	}
	else
	{
		m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 16;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	m_hap *= 0.97;
	m_sco *= 0.97;

	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 10) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}

	*/

	double m_hap_basic;
	double m_sco_basic;
	
	if (normal_impact[news_id].hap_impact > 1)
	{
		//m_hap_basic = (m_hap_basic * normal_impact[news_id].hap_impact);
		m_hap_basic = 1.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}
	else
	{
		//m_hap_basic = (m_hap_basic / normal_impact[news_id].hap_impact);
		m_hap_basic = -1.3 * normal[0].max_hap * normal_impact[news_id].hap_impact;
	}

	if (normal_impact[news_id].sco_impact > 1)
	{
		//m_sco_basic = (m_sco_basic * normal_impact[news_id].sco_impact);
		m_sco_basic = 1.3 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	else
	{
		//m_sco_basic = (m_sco_basic / normal_impact[news_id].sco_impact);
		m_sco_basic = -1.3 * normal[0].max_sco * normal_impact[news_id].sco_impact;
	}
	
	m_sco += m_sco_basic;
	m_hap += m_hap_basic;

	int id = rand() % 22;

	m_hap += random_impact[id].hap_random_impact;
	m_sco += random_impact[id].sco_random_impact;

	
	
	if (m_hap > 100) m_hap = 100;
	if (m_hap < 0) m_hap = 0;
	if (m_sco > 100) m_sco = 100;
	if (m_sco < 0) m_sco = 0;

	if (m_hap < 30) 
	{
		happy30warn_count++;
		hapwarn30 dlg;
		dlg.DoModal();
	}

	if (happy30warn_count > 2) 
	{
		warn30result dlg;
		dlg.DoModal();
		m_sco -= 10;
		happy30warn_count = 1;
	}

	UpdateData(false);

	if((count == 0)&&(m_sco < 60))
	{
		gameover dlg;
		dlg.DoModal();
		exit(0);
	} else if((count == 0)&&(m_sco >= 60))
	{
		gamepass dlg;
		dlg.DoModal();
		exit(0);
	}

	SetDlgItemText(IDC_EDIT_random, random_impact[id].name);

	SetDlgItemText(IDC_EDIT_output, normal_impact[news_id].name);

	int c = count % 3;
	if(c == 0) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "����");
		SetDlgItemText(IDC_EDIT_alert, "��ô�������������ʲô��");
	}
}



void CDemo2Dlg::OnButtonhajime() 
{
	// TODO: Add your control notification handler code here
	hajime dlg;
	dlg.DoModal();
}
