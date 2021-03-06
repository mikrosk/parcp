/*
 * DO NOT EDIT THIS FILE BY HAND!  It is generated by MKfallback.sh.
 */

#include <curses.priv.h>
#include <term.h>

#include <tic.h>

/* fallback entries for: vt52 */

static const TERMTYPE fallbacks[1] =
{
 /* vt52 */
	{
		"vt52|dec vt52",
		(char *)0,
		{ /* BOOLEANS */
		/* bw */	FALSE,
		/* am */	TRUE,
		/* xsb */	FALSE,
		/* xhp */	FALSE,
		/* xenl */	FALSE,
		/* eo */	FALSE,
		/* gn */	FALSE,
		/* hc */	FALSE,
		/* km */	FALSE,
		/* hs */	FALSE,
		/* in */	FALSE,
		/* da */	FALSE,
		/* db */	FALSE,
		/* mir */	FALSE,
		/* msgr */	FALSE,
		/* os */	FALSE,
		/* eslok */	FALSE,
		/* xt */	FALSE,
		/* hz */	FALSE,
		/* ul */	FALSE,
		/* xon */	FALSE,
		/* nxon */	FALSE,
		/* mc5i */	FALSE,
		/* chts */	FALSE,
		/* nrrmc */	FALSE,
		/* npc */	FALSE,
		/* ndscr */	FALSE,
		/* ccc */	FALSE,
		/* bce */	TRUE,
		/* hls */	FALSE,
		/* xhpa */	FALSE,
		/* crxm */	FALSE,
		/* daisy */	FALSE,
		/* xvpa */	FALSE,
		/* sam */	FALSE,
		/* cpix */	FALSE,
		/* lpix */	FALSE,
		/* OTbs */	FALSE,
		/* OTns */	FALSE,
		/* OTnc */	FALSE,
		/* OTMT */	FALSE,
		/* OTNL */	FALSE,
		/* OTpt */	FALSE,
		/* OTxr */	FALSE},
		{ /* NUMERICS */
		/* cols */	80,
		/* it */	8,
		/* lines */	25,
		/* lm */	ABSENT_NUMERIC,
		/* xmc */	ABSENT_NUMERIC,
		/* pb */	ABSENT_NUMERIC,
		/* vt */	ABSENT_NUMERIC,
		/* wsl */	ABSENT_NUMERIC,
		/* nlab */	ABSENT_NUMERIC,
		/* lh */	ABSENT_NUMERIC,
		/* lw */	ABSENT_NUMERIC,
		/* ma */	ABSENT_NUMERIC,
		/* wnum */	ABSENT_NUMERIC,
		/* colors */	16,
		/* pairs */	256,
		/* ncv */	ABSENT_NUMERIC,
		/* bufsz */	ABSENT_NUMERIC,
		/* spinv */	ABSENT_NUMERIC,
		/* spinh */	ABSENT_NUMERIC,
		/* maddr */	ABSENT_NUMERIC,
		/* mjump */	ABSENT_NUMERIC,
		/* mcs */	ABSENT_NUMERIC,
		/* mls */	ABSENT_NUMERIC,
		/* npins */	ABSENT_NUMERIC,
		/* orc */	ABSENT_NUMERIC,
		/* orl */	ABSENT_NUMERIC,
		/* orhi */	ABSENT_NUMERIC,
		/* orvi */	ABSENT_NUMERIC,
		/* cps */	ABSENT_NUMERIC,
		/* widcs */	ABSENT_NUMERIC,
		/* btns */	ABSENT_NUMERIC,
		/* bitwin */	ABSENT_NUMERIC,
		/* bitype */	ABSENT_NUMERIC,
		/* OTug */	ABSENT_NUMERIC,
		/* OTdC */	ABSENT_NUMERIC,
		/* OTdN */	ABSENT_NUMERIC,
		/* OTdB */	ABSENT_NUMERIC,
		/* OTdT */	ABSENT_NUMERIC,
		/* OTkn */	ABSENT_NUMERIC},
		{ /* STRINGS */
		/* cbt */	ABSENT_STRING,
		/* bel */	"\007",
		/* cr */	"\015",
		/* csr */	ABSENT_STRING,
		/* tbc */	ABSENT_STRING,
		/* clear */	"\033E",
		/* el */	"\033K",
		/* ed */	"\033J",
		/* hpa */	ABSENT_STRING,
		/* cmdch */	ABSENT_STRING,
		/* cup */	"\033Y%p1%' '%+%c%p2%' '%+%c",
		/* cud1 */	"\033B",
		/* home */	"\033H",
		/* civis */	"\033f",
		/* cub1 */	"\033D",
		/* mrcup */	ABSENT_STRING,
		/* cnorm */	"\033e",
		/* cuf1 */	"\033C",
		/* ll */	ABSENT_STRING,
		/* cuu1 */	"\033A",
		/* cvvis */	ABSENT_STRING,
		/* dch1 */	ABSENT_STRING,
		/* dl1 */	"\033M",
		/* dsl */	ABSENT_STRING,
		/* hd */	ABSENT_STRING,
		/* smacs */	ABSENT_STRING,
		/* blink */	ABSENT_STRING,
		/* bold */	ABSENT_STRING,
		/* smcup */	ABSENT_STRING,
		/* smdc */	ABSENT_STRING,
		/* dim */	ABSENT_STRING,
		/* smir */	ABSENT_STRING,
		/* invis */	ABSENT_STRING,
		/* prot */	ABSENT_STRING,
		/* rev */	"\033p",
		/* smso */	"\033p",
		/* smul */	ABSENT_STRING,
		/* ech */	ABSENT_STRING,
		/* rmacs */	ABSENT_STRING,
		/* sgr0 */	"\033q",
		/* rmcup */	ABSENT_STRING,
		/* rmdc */	ABSENT_STRING,
		/* rmir */	ABSENT_STRING,
		/* rmso */	"\033q",
		/* rmul */	ABSENT_STRING,
		/* flash */	ABSENT_STRING,
		/* ff */	ABSENT_STRING,
		/* fsl */	ABSENT_STRING,
		/* is1 */	"\033q\033e",
		/* is2 */	ABSENT_STRING,
		/* is3 */	ABSENT_STRING,
		/* if */	ABSENT_STRING,
		/* ich1 */	ABSENT_STRING,
		/* il1 */	ABSENT_STRING,
		/* ip */	ABSENT_STRING,
		/* kbs */	"\010",
		/* ktbc */	ABSENT_STRING,
		/* kclr */	ABSENT_STRING,
		/* kctab */	ABSENT_STRING,
		/* kdch1 */	ABSENT_STRING,
		/* kdl1 */	ABSENT_STRING,
		/* kcud1 */	"\034P",
		/* krmir */	ABSENT_STRING,
		/* kel */	ABSENT_STRING,
		/* ked */	ABSENT_STRING,
		/* kf0 */	ABSENT_STRING,
		/* kf1 */	"\034;",
		/* kf10 */	"\034D",
		/* kf2 */	"\034<",
		/* kf3 */	"\034=",
		/* kf4 */	"\034>",
		/* kf5 */	"\034?",
		/* kf6 */	"\034@",
		/* kf7 */	"\034A",
		/* kf8 */	"\034B",
		/* kf9 */	"\034C",
		/* khome */	"\034G",
		/* kich1 */	"\034R",
		/* kil1 */	ABSENT_STRING,
		/* kcub1 */	"\034K",
		/* kll */	ABSENT_STRING,
		/* knp */	ABSENT_STRING,
		/* kpp */	ABSENT_STRING,
		/* kcuf1 */	"\034M",
		/* kind */	ABSENT_STRING,
		/* kri */	ABSENT_STRING,
		/* khts */	ABSENT_STRING,
		/* kcuu1 */	"\034H",
		/* rmkx */	ABSENT_STRING,
		/* smkx */	ABSENT_STRING,
		/* lf0 */	ABSENT_STRING,
		/* lf1 */	ABSENT_STRING,
		/* lf10 */	ABSENT_STRING,
		/* lf2 */	ABSENT_STRING,
		/* lf3 */	ABSENT_STRING,
		/* lf4 */	ABSENT_STRING,
		/* lf5 */	ABSENT_STRING,
		/* lf6 */	ABSENT_STRING,
		/* lf7 */	ABSENT_STRING,
		/* lf8 */	ABSENT_STRING,
		/* lf9 */	ABSENT_STRING,
		/* rmm */	ABSENT_STRING,
		/* smm */	ABSENT_STRING,
		/* nel */	"\015\012",
		/* pad */	ABSENT_STRING,
		/* dch */	ABSENT_STRING,
		/* dl */	ABSENT_STRING,
		/* cud */	ABSENT_STRING,
		/* ich */	ABSENT_STRING,
		/* indn */	ABSENT_STRING,
		/* il */	ABSENT_STRING,
		/* cub */	ABSENT_STRING,
		/* cuf */	ABSENT_STRING,
		/* rin */	ABSENT_STRING,
		/* cuu */	ABSENT_STRING,
		/* pfkey */	ABSENT_STRING,
		/* pfloc */	ABSENT_STRING,
		/* pfx */	ABSENT_STRING,
		/* mc0 */	ABSENT_STRING,
		/* mc4 */	ABSENT_STRING,
		/* mc5 */	ABSENT_STRING,
		/* rep */	ABSENT_STRING,
		/* rs1 */	ABSENT_STRING,
		/* rs2 */	ABSENT_STRING,
		/* rs3 */	ABSENT_STRING,
		/* rf */	ABSENT_STRING,
		/* rc */	ABSENT_STRING,
		/* vpa */	ABSENT_STRING,
		/* sc */	ABSENT_STRING,
		/* ind */	"\012",
		/* ri */	"\033I",
		/* sgr */	ABSENT_STRING,
		/* hts */	ABSENT_STRING,
		/* wind */	ABSENT_STRING,
		/* ht */	"\011",
		/* tsl */	ABSENT_STRING,
		/* uc */	ABSENT_STRING,
		/* hu */	ABSENT_STRING,
		/* iprog */	ABSENT_STRING,
		/* ka1 */	ABSENT_STRING,
		/* ka3 */	ABSENT_STRING,
		/* kb2 */	ABSENT_STRING,
		/* kc1 */	ABSENT_STRING,
		/* kc3 */	ABSENT_STRING,
		/* mc5p */	ABSENT_STRING,
		/* rmp */	ABSENT_STRING,
		/* acsc */	ABSENT_STRING,
		/* pln */	ABSENT_STRING,
		/* kcbt */	ABSENT_STRING,
		/* smxon */	ABSENT_STRING,
		/* rmxon */	ABSENT_STRING,
		/* smam */	ABSENT_STRING,
		/* rmam */	ABSENT_STRING,
		/* xonc */	ABSENT_STRING,
		/* xoffc */	ABSENT_STRING,
		/* enacs */	ABSENT_STRING,
		/* smln */	ABSENT_STRING,
		/* rmln */	ABSENT_STRING,
		/* kbeg */	ABSENT_STRING,
		/* kcan */	ABSENT_STRING,
		/* kclo */	ABSENT_STRING,
		/* kcmd */	ABSENT_STRING,
		/* kcpy */	ABSENT_STRING,
		/* kcrt */	ABSENT_STRING,
		/* kend */	ABSENT_STRING,
		/* kent */	ABSENT_STRING,
		/* kext */	ABSENT_STRING,
		/* kfnd */	ABSENT_STRING,
		/* khlp */	"\034b",
		/* kmrk */	ABSENT_STRING,
		/* kmsg */	ABSENT_STRING,
		/* kmov */	ABSENT_STRING,
		/* knxt */	ABSENT_STRING,
		/* kopn */	ABSENT_STRING,
		/* kopt */	ABSENT_STRING,
		/* kprv */	ABSENT_STRING,
		/* kprt */	ABSENT_STRING,
		/* krdo */	ABSENT_STRING,
		/* kref */	ABSENT_STRING,
		/* krfr */	ABSENT_STRING,
		/* krpl */	ABSENT_STRING,
		/* krst */	ABSENT_STRING,
		/* kres */	ABSENT_STRING,
		/* ksav */	ABSENT_STRING,
		/* kspd */	ABSENT_STRING,
		/* kund */	"\034a",
		/* kBEG */	ABSENT_STRING,
		/* kCAN */	ABSENT_STRING,
		/* kCMD */	ABSENT_STRING,
		/* kCPY */	ABSENT_STRING,
		/* kCRT */	ABSENT_STRING,
		/* kDC */	ABSENT_STRING,
		/* kDL */	ABSENT_STRING,
		/* kslt */	ABSENT_STRING,
		/* kEND */	ABSENT_STRING,
		/* kEOL */	ABSENT_STRING,
		/* kEXT */	ABSENT_STRING,
		/* kFND */	ABSENT_STRING,
		/* kHLP */	ABSENT_STRING,
		/* kHOM */	ABSENT_STRING,
		/* kIC */	ABSENT_STRING,
		/* kLFT */	ABSENT_STRING,
		/* kMSG */	ABSENT_STRING,
		/* kMOV */	ABSENT_STRING,
		/* kNXT */	ABSENT_STRING,
		/* kOPT */	ABSENT_STRING,
		/* kPRV */	ABSENT_STRING,
		/* kPRT */	ABSENT_STRING,
		/* kRDO */	ABSENT_STRING,
		/* kRPL */	ABSENT_STRING,
		/* kRIT */	ABSENT_STRING,
		/* kRES */	ABSENT_STRING,
		/* kSAV */	ABSENT_STRING,
		/* kSPD */	ABSENT_STRING,
		/* kUND */	ABSENT_STRING,
		/* rfi */	ABSENT_STRING,
		/* kf11 */	"\034T",
		/* kf12 */	"\034U",
		/* kf13 */	"\034V",
		/* kf14 */	"\034W",
		/* kf15 */	"\034X",
		/* kf16 */	"\034Y",
		/* kf17 */	"\034Z",
		/* kf18 */	"\034[",
		/* kf19 */	"\034\\",
		/* kf20 */	"\034]",
		/* kf21 */	ABSENT_STRING,
		/* kf22 */	ABSENT_STRING,
		/* kf23 */	ABSENT_STRING,
		/* kf24 */	ABSENT_STRING,
		/* kf25 */	ABSENT_STRING,
		/* kf26 */	ABSENT_STRING,
		/* kf27 */	ABSENT_STRING,
		/* kf28 */	ABSENT_STRING,
		/* kf29 */	ABSENT_STRING,
		/* kf30 */	ABSENT_STRING,
		/* kf31 */	ABSENT_STRING,
		/* kf32 */	ABSENT_STRING,
		/* kf33 */	ABSENT_STRING,
		/* kf34 */	ABSENT_STRING,
		/* kf35 */	ABSENT_STRING,
		/* kf36 */	ABSENT_STRING,
		/* kf37 */	ABSENT_STRING,
		/* kf38 */	ABSENT_STRING,
		/* kf39 */	ABSENT_STRING,
		/* kf40 */	ABSENT_STRING,
		/* kf41 */	ABSENT_STRING,
		/* kf42 */	ABSENT_STRING,
		/* kf43 */	ABSENT_STRING,
		/* kf44 */	ABSENT_STRING,
		/* kf45 */	ABSENT_STRING,
		/* kf46 */	ABSENT_STRING,
		/* kf47 */	ABSENT_STRING,
		/* kf48 */	ABSENT_STRING,
		/* kf49 */	ABSENT_STRING,
		/* kf50 */	ABSENT_STRING,
		/* kf51 */	ABSENT_STRING,
		/* kf52 */	ABSENT_STRING,
		/* kf53 */	ABSENT_STRING,
		/* kf54 */	ABSENT_STRING,
		/* kf55 */	ABSENT_STRING,
		/* kf56 */	ABSENT_STRING,
		/* kf57 */	ABSENT_STRING,
		/* kf58 */	ABSENT_STRING,
		/* kf59 */	ABSENT_STRING,
		/* kf60 */	ABSENT_STRING,
		/* kf61 */	ABSENT_STRING,
		/* kf62 */	ABSENT_STRING,
		/* kf63 */	ABSENT_STRING,
		/* el1 */	ABSENT_STRING,
		/* mgc */	ABSENT_STRING,
		/* smgl */	ABSENT_STRING,
		/* smgr */	ABSENT_STRING,
		/* fln */	ABSENT_STRING,
		/* sclk */	ABSENT_STRING,
		/* dclk */	ABSENT_STRING,
		/* rmclk */	ABSENT_STRING,
		/* cwin */	ABSENT_STRING,
		/* wingo */	ABSENT_STRING,
		/* hup */	ABSENT_STRING,
		/* dial */	ABSENT_STRING,
		/* qdial */	ABSENT_STRING,
		/* tone */	ABSENT_STRING,
		/* pulse */	ABSENT_STRING,
		/* hook */	ABSENT_STRING,
		/* pause */	ABSENT_STRING,
		/* wait */	ABSENT_STRING,
		/* u0 */	ABSENT_STRING,
		/* u1 */	ABSENT_STRING,
		/* u2 */	ABSENT_STRING,
		/* u3 */	ABSENT_STRING,
		/* u4 */	ABSENT_STRING,
		/* u5 */	ABSENT_STRING,
		/* u6 */	ABSENT_STRING,
		/* u7 */	ABSENT_STRING,
		/* u8 */	ABSENT_STRING,
		/* u9 */	ABSENT_STRING,
		/* op */	"\033bO\033c@",
		/* oc */	"\033bO\033c@",
		/* initc */	ABSENT_STRING,
		/* initp */	ABSENT_STRING,
		/* scp */	ABSENT_STRING,
		/* setf */	"\033b%p1%'@'%+%Pa%?%ga%'@'%=%tO%e%?%ga%'G'%=%t@%e%ga%c%;",
		/* setb */	"\033c%p1%'@'%+%Pa%?%ga%'@'%=%tO%e%?%ga%'G'%=%t@%e%ga%c%;",
		/* cpi */	ABSENT_STRING,
		/* lpi */	ABSENT_STRING,
		/* chr */	ABSENT_STRING,
		/* cvr */	ABSENT_STRING,
		/* defc */	ABSENT_STRING,
		/* swidm */	ABSENT_STRING,
		/* sdrfq */	ABSENT_STRING,
		/* sitm */	ABSENT_STRING,
		/* slm */	ABSENT_STRING,
		/* smicm */	ABSENT_STRING,
		/* snlq */	ABSENT_STRING,
		/* snrmq */	ABSENT_STRING,
		/* sshm */	ABSENT_STRING,
		/* ssubm */	ABSENT_STRING,
		/* ssupm */	ABSENT_STRING,
		/* sum */	ABSENT_STRING,
		/* rwidm */	ABSENT_STRING,
		/* ritm */	ABSENT_STRING,
		/* rlm */	ABSENT_STRING,
		/* rmicm */	ABSENT_STRING,
		/* rshm */	ABSENT_STRING,
		/* rsubm */	ABSENT_STRING,
		/* rsupm */	ABSENT_STRING,
		/* rum */	ABSENT_STRING,
		/* mhpa */	ABSENT_STRING,
		/* mcud1 */	ABSENT_STRING,
		/* mcub1 */	ABSENT_STRING,
		/* mcuf1 */	ABSENT_STRING,
		/* mvpa */	ABSENT_STRING,
		/* mcuu1 */	ABSENT_STRING,
		/* porder */	ABSENT_STRING,
		/* mcud */	ABSENT_STRING,
		/* mcub */	ABSENT_STRING,
		/* mcuf */	ABSENT_STRING,
		/* mcuu */	ABSENT_STRING,
		/* scs */	ABSENT_STRING,
		/* smgb */	ABSENT_STRING,
		/* smgbp */	ABSENT_STRING,
		/* smglp */	ABSENT_STRING,
		/* smgrp */	ABSENT_STRING,
		/* smgt */	ABSENT_STRING,
		/* smgtp */	ABSENT_STRING,
		/* sbim */	ABSENT_STRING,
		/* scsd */	ABSENT_STRING,
		/* rbim */	ABSENT_STRING,
		/* rcsd */	ABSENT_STRING,
		/* subcs */	ABSENT_STRING,
		/* supcs */	ABSENT_STRING,
		/* docr */	ABSENT_STRING,
		/* zerom */	ABSENT_STRING,
		/* csnm */	ABSENT_STRING,
		/* kmous */	ABSENT_STRING,
		/* minfo */	ABSENT_STRING,
		/* reqmp */	ABSENT_STRING,
		/* getm */	ABSENT_STRING,
		/* setaf */	ABSENT_STRING,
		/* setab */	ABSENT_STRING,
		/* pfxl */	ABSENT_STRING,
		/* devt */	ABSENT_STRING,
		/* csin */	ABSENT_STRING,
		/* s0ds */	ABSENT_STRING,
		/* s1ds */	ABSENT_STRING,
		/* s2ds */	ABSENT_STRING,
		/* s3ds */	ABSENT_STRING,
		/* smglr */	ABSENT_STRING,
		/* smgtb */	ABSENT_STRING,
		/* birep */	ABSENT_STRING,
		/* binel */	ABSENT_STRING,
		/* bicr */	ABSENT_STRING,
		/* colornm */	ABSENT_STRING,
		/* defbi */	ABSENT_STRING,
		/* endbi */	ABSENT_STRING,
		/* setcolor */	ABSENT_STRING,
		/* slines */	ABSENT_STRING,
		/* dispc */	ABSENT_STRING,
		/* smpch */	ABSENT_STRING,
		/* rmpch */	ABSENT_STRING,
		/* smsc */	ABSENT_STRING,
		/* rmsc */	ABSENT_STRING,
		/* pctrm */	ABSENT_STRING,
		/* scesc */	ABSENT_STRING,
		/* scesa */	ABSENT_STRING,
		/* ehhlm */	ABSENT_STRING,
		/* elhlm */	ABSENT_STRING,
		/* elohlm */	ABSENT_STRING,
		/* erhlm */	ABSENT_STRING,
		/* ethlm */	ABSENT_STRING,
		/* evhlm */	ABSENT_STRING,
		/* OTi2 */	ABSENT_STRING,
		/* OTrs */	ABSENT_STRING,
		/* OTnl */	ABSENT_STRING,
		/* OTbc */	ABSENT_STRING,
		/* OTko */	ABSENT_STRING,
		/* OTma */	ABSENT_STRING,
		/* OTG2 */	ABSENT_STRING,
		/* OTG3 */	ABSENT_STRING,
		/* OTG1 */	ABSENT_STRING,
		/* OTG4 */	ABSENT_STRING,
		/* OTGR */	ABSENT_STRING,
		/* OTGL */	ABSENT_STRING,
		/* OTGU */	ABSENT_STRING,
		/* OTGD */	ABSENT_STRING,
		/* OTGH */	ABSENT_STRING,
		/* OTGV */	ABSENT_STRING,
		/* OTGC */	ABSENT_STRING,
		/* meml */	ABSENT_STRING,
		/* memu */	ABSENT_STRING,
		/* box1 */	ABSENT_STRING}
	} /* size = 1977 */
};

const TERMTYPE *_nc_fallback(const char *name GCC_UNUSED)
{
    const TERMTYPE	*tp;

    for (tp = fallbacks;
	 	tp < fallbacks + sizeof(fallbacks)/sizeof(TERMTYPE);
	 	tp++)
	if (_nc_name_match(tp->term_names, name, "|"))
	    return(tp);
	return((TERMTYPE *)0);
}
