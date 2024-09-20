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
	{"上课",-3,2,-1,3},
	{"休憩",-2,2,-3,2},
	{"活动",0,3,-2,2},
	{"自习",-2,2,-1,4}
};*/

Nor normal[EVENT_COUNT] = {
	{"上课",-3,3,-1,3},
	{"休憩",-2,3,-3,3},
	{"活动",0,3,-2,3},
	{"自习",-2,3,-1,3}
};

#define NORMAL_RANDOM_COUNT 48

typedef struct Normal_random {
	char * name;
	double hap_impact;
	double sco_impact;
} Nor_ipt;

Nor_ipt normal_impact[NORMAL_RANDOM_COUNT] = {
	{"点开网易云音乐，直到从自习室离开\r\n幸福感+ 成绩-", 2, 0.8},
	{"很难受地看完了模电的一章ppt\r\n幸福感- 成绩+", 0.8, 2},
	{"成功种树两小时整，开心w\r\n幸福感+ 成绩+", 2, 2},
	{"a区圆桌碰到了班上的代码大佬，分分钟教会我\r\n幸福感+ 成绩+", 2, 2},
	{"刷工数卷子，信心满满做了两个小时结果没几道是对的\r\n（并不知道自己哪里错了\r\n幸福感-", 0.9, 1.0},
	{"抱着认真培养日语语感的态度看了好几集日剧（学习啊喂……\r\n幸福感+ 成绩-", 2, 0.9},
	{"日语语法题错到哭泣，看答案更不懂了\r\n（真让人摸不着头脑.jpg\r\n幸福感- 成绩+", 0.8, 2},
	{"将近两个小时认真做出来一道难题，\r\n激动的想去操场跑十圈\r\n幸福感+ 成绩+", 2, 2},
	{"整理整理笔记，临走优雅的合上赏心悦目的笔记本\r\n（装逼三连.jpg\r\n幸福感+ 成绩+", 2, 2},
	{"终于还是做不出来题了，\r\n于是在草稿纸上画了一堆乱七八糟的小人\r\n成绩-", 1.0, 0.8},
	{"运行程序发现有一个bug，改了一行再运行，\r\n变成了200+个bug（改不完的\r\n幸福感-", 0.8, 1.0},
	{"不小心点开了知乎，于是不小心看了三个多小时，\r\n以为学到了很多姿势自信满满地走出了教室\r\n幸福感+ 成绩-", 2, 0.8},
	{"以美好的暑假生活为目标开始学习，\r\n但回想起了无数个荒废的假期，遂拒绝学习\r\n幸福感- 成绩-", 0.8, 0.8},
	{"尴尬的手机铃声突然在自习室快活地响了起来\r\n幸福感-", 0.7, 1},
	{"抄同学的工数作业\r\n（当然是骗自己看懂了的抄的\r\n幸福感+ 成绩-", 2, 0.9},
	{"三个小时，[完美]解决c++编程习题一道，\r\n感觉自己可以和地球作战了\r\n幸福感+ 成绩+", 2, 2},
	{"被同学叫去开黑，从容而去\r\n幸福感+ 成绩-", 2, 0.8},

	{"矩阵的秩，基，特征值和特征向量……\r\n代万基老师的声音回荡在我梦中……\r\n幸福感- 成绩-", 0.8, 0.8},
	{"日听老师谈起了自己的日本生活经历，突然想学好日语\r\n幸福感+ 成绩+", 1.2, 1.2},
	{"在李正学老师的课堂上又学到了几个“小招儿”\r\n幸福感+ 成绩+", 1.2, 1.2},
	{"李正学老师花了二十分钟教我们四上四下攀爬大黑山\r\n幸福感+ 成绩-", 1.3, 0.7},
	{"综日到了教室才发现忘记带《大家的日语》\r\n幸福感- 成绩-", 0.7, 0.7},
	{"没写完日语作业，听课效率减半\r\n幸福感- 成绩-", 0.7, 0.7},
	{"综日课课间放了自己爱豆的歌，学习动力爆棚\r\n幸福感+ 成绩+", 1.3, 1.3},
	{"又上到了实验室穿拖鞋的高老师的实验课，\r\n被3个camera和小车车，矿工头盔，\r\n课前分ab卷的限时测验吓得跪下惹不起.jpg\r\n幸福感- 成绩-", 0.5, 0.5},
	{"日听课口语会话抽到自己组，\r\nドキドキして先生のアドバイスを聞いて、良くなりました\r\n幸福感+ 成绩+", 1.3, 1.3},
	{"课上听着侯刚老师条理清晰的讲课，因跟不上听不懂理解不能而感到自卑\r\n幸福感- 成绩+", 0.7, 1},
	{"上课听到了侯刚老师讲的程序员段子，\r\n蠢笑的同时感受到自己的前途未卜\r\n幸福感+ 成绩-", 1.2, 0.9},
	{"运动完再去听两节百家讲坛，美滋滋\r\n幸福感+ 成绩+", 1.3, 1.2},
	{"跟着代万基牌有声书认真学习完了下一个章节\r\n幸福感+ 成绩+", 1.3, 1.3},
	{"听着刘斌读ppt听到睡……不对，我根本就没学过c++\r\n幸福感- 成绩+", 0.8, 1.3},
	{"因感冒向日语老师请假，结果因请假时用错语法不得不赶来上课\r\n幸福感- 成绩+", 0.7, 1.3},
	{"上课迟到，差点被一到时间就锁门的侯刚老师拒之门外\r\n幸福感- 成绩-", 0.7, 0.8},
	{"综日课迟到被老师记到小本本上\r\n幸福感- 成绩-", 0.7, 0.9},

	{"玩游戏\r\n幸福感+ 成绩-", 1.5, 0.8},
	{"看电影\r\n幸福感+ 成绩-", 1.3, 0.9},
	{"听歌\r\n幸福感+ 成绩-", 1.3, 0.9},
	{"一个人去外面散心\r\n幸福感+ 成绩-", 1.3, 0.8},
	{"放空————发呆————\r\n幸福感+ 成绩-", 1.3, 0.9},
	{"呵呵，花两三个小时打扫房间（不存在的\r\n幸福感++", 1.2, 1.0},
	{"和同学打电话叙旧怀念\r\n幸福感+ 成绩-", 1.5, 0.9},
	{"看书（看到一半放弃去刷手机\r\n幸福感+ 成绩-", 1.2, 0.8},

	{"デートw\r\n幸福感+ 成绩+", 3, 1.3},
	{"一起去爬大黒山！\r\n幸福感+ 成绩+", 2, 1.2},
	{"团建，在党的伟大领导下，在社会主义光芒的照耀下接受共产主义的熏陶\r\n幸福感- 成绩+", 0.5, 1.2},
	{"开发区 图书馆 志愿者 （举手！\r\n幸福感+ 成绩+", 1.3, 1.2},
	{"创意手绘（食堂へ\r\n幸福感+ 成绩+", 1.5, 1.2},
	{"唱歌唱到凌晨，甚至通宵，因为某些人说要唱自己可以唱到第二天早上\r\n幸福感+ 成绩-", 1.8, 0.9}
};

#define RANDOM_COUNT 22


typedef struct random {
	char * name;
	double hap_random_impact;
	double sco_random_impact;
} Ran_ipt;

Ran_ipt random_impact[RANDOM_COUNT] = {
	{"路上偶遇了学长，顺便要到了记满笔记的书\r\n幸福感+ 成绩+", 1, 3},
	{"我朋友送我尼尔激活码  哈哈哈哈哈哈哈哈哈哈哈哈\r\n幸福感+ 成绩-", 3, -1},
	{"过会儿去了体育馆锻炼身体，挥洒汗水，畅快十足（体育也算成绩啊。。）\r\n幸福感+ 成绩+", 2, 1},
	{"路上丢了玉兰卡，转眼在“软院学长学姐帮帮忙”群里被人捡到\r\n幸福感+", 2.2, 0},
	{"不小心捡到了一串钥匙 物归原主 助人为乐 \r\n失主是个妹子  楽しみ\r\n幸福感+", 3, 0},
	{"在路上大声讨论游戏的时候碰到了齐老师  \r\n齐老师给了我一个白眼  (⊙o⊙)。。。\r\n幸福感- 成绩-", -1.2, -1},
	{"今天的大黑上妖风十分猖獗 \r\n给我换了无数的发型\r\n幸福感-", -1.4, 0},
	{"今天快递小哥走的早  没有拿到我的快递  \r\n哭唧唧/(ㄒoㄒ)/~~\r\n幸福感-", -1, 0},
	{"我的建行卡又被吞掉了 啥时候建行的服务能好一点啊 \r\n幸福感-", -0.8, 0},
	{"在某苑超市买到了过期的***   作为软院唯一一个超市  \r\n这种都能做出来mmp\r\n幸福感-", -1.7, 0},
	{"教材中心的电脑上竟然有病毒  我的学习资料被干掉了 \r\n我的U盘555~~  辣鸡  再也不去了\r\n幸福感- 成绩-", -1.2, -2},
	{"本来想去体育馆锻炼身体，结果发现位置全被老师占了\r\n幸福感- 成绩-", -1, -0.1},
	{"洗澡忘记带卡脱光了又再穿上  倍尴尬\r\n幸福感-", -1.9, 0},
	{"路上丢了玉兰卡，结果发现被盗刷100块钱\r\n幸福感-", -2, 0},
	{"路上遇到了自己的男神/女神，激动了半天\r\n幸福感-", 3, 0},
	{"感冒了，医务室的大爷好心的给我开了一瓶开塞露\r\n幸福感+ 成绩+", 3, 2},
	{"小憩被舍友吵醒，面无表情望着天花板\r\n幸福感- 成绩-", -3, -1},
	{"不小心掉进涌泉湖里\r\n幸福感-", -4, 0},
	{"丢了一条裤子，第二天在施工工人身上发现同款裤子一条\r\n幸福感-", -3, 0},
	{"路遇野狗\r\n幸福感-", -2, 0},
	{"走路撞墙\r\n幸福感-", -2, 0},
	{"逛群的时候偶然获取到了真题题库\r\n幸福感+ 成绩+", 3, 3}
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
	//SetDlgItemText(IDC_EDIT_change, "上午");
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
		SetDlgItemText(IDC_EDIT_change, "上午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天上午想干什么？");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "下午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天下午想干什么？");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "晚上");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天晚上想干什么？");
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
		SetDlgItemText(IDC_EDIT_change, "上午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天上午想干什么？");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "下午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天下午想干什么？");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "晚上");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天晚上想干什么？");
	}
}

void CDemo2Dlg::OnBUTTONoutplay()   //活动
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
		SetDlgItemText(IDC_EDIT_change, "上午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天上午想干什么？");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "下午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天下午想干什么？");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "晚上");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天晚上想干什么？");
	}
}

/*void CDemo2Dlg::OnBUTTONmeal()							//弃用的两个模块功能
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

	if(news_id == 9) SetDlgItemText(IDC_EDIT_output, "食堂大妈又抖手了");
	else if(news_id == 10) SetDlgItemText(IDC_EDIT_output, "吃到不明物体");
	else if(news_id == 11) SetDlgItemText(IDC_EDIT_output, "学习过于繁忙叫了外卖");

	int c = count % 3;
	if(c == 2) SetDlgItemText(IDC_EDIT_change, "上午");
	if(c == 1) SetDlgItemText(IDC_EDIT_change, "下午");
	if(c == 0) SetDlgItemText(IDC_EDIT_change, "晚上");
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

	if(news_id == 12) SetDlgItemText(IDC_EDIT_output, "食堂大妈又抖手了");
	else if(news_id == 13) SetDlgItemText(IDC_EDIT_output, "吃到不明物体");
	else if(news_id == 14) SetDlgItemText(IDC_EDIT_output, "学习过于繁忙叫了外卖");

	int c = count % 3;
	if(c == 2) SetDlgItemText(IDC_EDIT_change, "上午");
	if(c == 1) SetDlgItemText(IDC_EDIT_change, "下午");
	if(c == 0) SetDlgItemText(IDC_EDIT_change, "晚上");
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
		SetDlgItemText(IDC_EDIT_change, "上午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天上午想干什么？");
	}
	if(c == 2) 
	{
		SetDlgItemText(IDC_EDIT_change, "下午");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天下午想干什么？");
	}
	if(c == 1) 
	{
		SetDlgItemText(IDC_EDIT_change, "晚上");
		SetDlgItemText(IDC_EDIT_alert, "那么，今天晚上想干什么？");
	}
}



void CDemo2Dlg::OnButtonhajime() 
{
	// TODO: Add your control notification handler code here
	hajime dlg;
	dlg.DoModal();
}
