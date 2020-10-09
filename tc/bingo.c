/* ATTACKING PROGRAM of C */


#include <stdio.h>
#include "code.h" 

#define N 128 /* 頂点数 */
static unsigned int m[N]={
24949,15319,
28883,20250,
30505,22255,
24468,15102,
6651,22243,
15324,6359,
31303,32344,
25526,2136,
23648,27646,
15416,16347,
28362,29478,
19693,19216,
5261,11671,
30232,3154,
30874,12126,
305,30237,
22501,18628,
26500,22502,
26285,14266,
21505,18959,
15057,2385,
20499,9714,
31924,11841,
7950,18634,
15049,18000,
25482,15333,
4496,26903,
17254,22902,
17556,31581,
13383,9698,
2155,6915,
12157,23904,
26313,3080,
17170,5940,
30569,32575,
29274,7033,
7589,6744,
18180,30566,
942,24599,
28018,3078,
15482,5926,
6561,21620,
15021,17878,
24588,5647,
3390,12565,
29845,13577,
21627,28001,
3095,2343,
22437,19302,
4041,26565,
1365,17609,
28344,10456,
4865,23525,
4652,19011,
1936,19306,
24628,11470,
16911,27981,
23249,24270,
20333,5583,
29881,6315,
14691,12597,
28555,16307,
30108,23842,
2788,26585};

/* differential attacs for each vector of mm_k */
static unsigned int mm[8][128]={
{
7031,30138,
641,3019,
19013,32631,
28645,22617,
30102,3367,
23631,9421,
7713,5659,
19007,28567,
20796,4867,
21844,17963,
18917,30514,
12346,27726,
17851,7306,
5538,11448,
19017,30281,
16957,3453,
30,24251,
15050,23550,
12142,9437,
11858,24888,
19232,15313,
15701,26598,
15639,24545,
24867,17184,
5641,16969,
4654,6532,
21851,27741,
29180,27746,
15091,16028,
6648,20034,
6700,3814,
1727,4287,
3384,26680,
11745,18303,
19308,17657,
23565,18923,
30519,31157,
20021,2056,
13350,11889,
24666,26346,
6356,3369,
22154,6286,
25241,23887,
5920,13672,
29557,26358,
26498,27345,
22218,23242,
15096,1146,
15358,2423,
14412,15334,
16116,22464,
31592,22217,
15234,31346,
2174,10743,
24859,32272,
21806,30278,
25253,32155,
5344,22476,
13973,6742,
12314,2372,
29193,17894,
26283,19906,
30214,29875,
28324,305},
{
25306,
18574,
25604,
31319,
19927,
4321,
4957,
3050,
16117,
25281,
16811,
5696,
10047,
13272,
27610,
8040,
4083,
20000,
3781,
18203,
14364,
14618,
25876,
6682,
23555,
13687,
3332,
1020,
1944,
5314,
16055,
26931,
32242,
30123,
16578,
5890,
29909,
6293,
29163,
30180,
15278,
3787,
22198,
30296,
30545,
13304,
29214,
25864,
3802,
24955,
24237,
4556,
7619,
7020,
21864,
25337,
21803,
28823,
10773,
15742,
30858,
14340,
14276,
2972,
27974,
31120,
22556,
29904,
1373,
11779,
21550,
17865,
18626,
23483,
27655,
11404,
22220,
30116,
19872,
21214,
28544,
17924,
14387,
18909,
22824,
6966,
31893,
25929,
18855,
27765,
21800,
13962,
18859,
28588,
14432,
5625,
16863,
11696,
18951,
23897,
18009,
24559,
14632,
32377,
28607,
17565,
14609,
30324,
24493,
18953,
24903,
11667,
21538,
10031,
2709,
5611,
355,
12122,
15638,
25696,
25528,
3743,
6580,
2726,
6606,
6758,
2089,
305},
{
25618,
18296,
4243,
8684,
13579,
27913,
6587,
2336,
29058,
4561,
12377,
29559,
17178,
16974,
14436,
25563,
2124,
5682,
23248,
13220,
3031,
1327,
331,
4625,
28640,
32579,
25642,
21233,
21499,
25498,
3385,
15301,
31876,
11107,
26516,
26536,
27007,
14374,
29901,
2057,
8039,
910,
5919,
4906,
19985,
22844,
4920,
18188,
3407,
16522,
7615,
25963,
24271,
32345,
21435,
22654,
12567,
3189,
16087,
13611,
28839,
25543,
7750,
29560,
16599,
31521,
27541,
25303,
23434,
15277,
5518,
10448,
2072,
19315,
10633,
16322,
11462,
29187,
30890,
7653,
26963,
16079,
7369,
28811,
27302,
21496,
20238,
25609,
27348,
30276,
29190,
23912,
11072,
20511,
20581,
21245,
16379,
19674,
16051,
2070,
20344,
16329,
25267,
10847,
21517,
26988,
3142,
31302,
30520,
19204,
18675,
16096,
19668,
20061,
6928,
20340,
17937,
8700,
20586,
15741,
29495,
7349,
22910,
3834,
16840,
24571,
1968,
305},
{
31982,
1119,
21815,
11701,
5977,
8035,
17223,
26351,
22596,
8335,
12969,
14220,
32638,
13050,
4910,
15,
9369,
6779,
19651,
5618,
7386,
9664,
17201,
32561,
19269,
1029,
26588,
27613,
28410,
32203,
17594,
26715,
25513,
14690,
31938,
4039,
4948,
29923,
28558,
8049,
19249,
6998,
4348,
23587,
13195,
18253,
19032,
30223,
25893,
20307,
19614,
12958,
16531,
6599,
60,
15710,
3065,
262,
29200,
21126,
30568,
32574,
16984,
26688,
17213,
9750,
24498,
24896,
14658,
24497,
30852,
26269,
20769,
4623,
2406,
25910,
16916,
19841,
10026,
11685,
25882,
7576,
13234,
23596,
31601,
1385,
4224,
18234,
4524,
21426,
29450,
21877,
13184,
9993,
16541,
28877,
16365,
14308,
1105,
12934,
23638,
32330,
1088,
22467,
28318,
1950,
21559,
691,
27617,
31245,
13357,
12596,
24248,
28627,
24244,
7768,
32335,
13423,
19975,
15376,
368,
24562,
26723,
22169,
28562,
3330,
26914,
305},
{
28596,
26262,
16074,
17546,
9602,
5598,
906,
2140,
19691,
8002,
27711,
30479,
5915,
2416,
32198,
10842,
10818,
679,
6572,
12112,
26641,
10790,
13673,
14419,
11118,
19310,
6767,
24550,
2952,
28371,
25297,
25630,
6355,
21535,
3058,
12088,
25517,
7605,
25650,
7309,
18024,
23451,
32249,
22607,
28828,
22593,
23240,
29501,
30546,
1348,
8606,
30542,
7299,
23521,
30274,
26594,
22235,
11443,
6618,
16536,
11505,
23654,
3973,
2771,
26530,
11095,
21124,
4538,
2346,
20037,
15429,
28863,
26605,
10869,
11100,
21485,
32321,
18941,
32512,
31132,
15644,
18222,
4901,
1965,
24465,
13689,
22415,
1030,
17648,
30246,
21401,
29441,
17663,
21853,
16341,
8638,
10728,
27606,
27340,
25879,
20255,
283,
2080,
32234,
1668,
19881,
23533,
29182,
7324,
23172,
18020,
19034,
32307,
1983,
26259,
9420,
3374,
21570,
6368,
16374,
18285,
24664,
7385,
31605,
19947,
18286,
28807,
305},
{
6975,
26668,
27653,
10681,
25918,
6539,
14055,
6964,
28549,
14665,
17250,
16797,
31501,
10371,
5970,
11519,
17989,
12996,
29843,
26604,
26658,
31134,
22261,
4605,
19849,
25724,
15693,
13413,
3455,
27534,
22414,
25594,
11450,
20323,
15024,
21876,
14286,
6689,
28923,
1306,
3989,
16639,
27367,
32136,
16358,
3110,
7987,
22256,
14611,
18943,
15339,
22401,
5601,
25486,
13289,
14403,
29852,
27640,
20539,
19877,
8027,
21454,
32202,
15249,
11488,
16612,
18221,
21585,
12664,
26296,
23477,
32636,
10416,
24240,
14399,
30541,
30478,
9661,
7376,
24535,
21170,
11502,
30215,
30219,
30477,
19866,
29929,
18225,
1290,
3753,
32294,
20002,
17246,
31289,
5295,
19222,
14300,
16604,
7314,
10703,
27307,
31880,
20048,
23215,
4022,
8665,
11734,
25633,
13607,
6713,
25319,
27522,
10104,
21629,
4573,
12065,
23644,
9030,
17953,
18284,
28658,
6725,
22642,
22465,
6678,
6925,
10764,
305},
{
19030,
3032,
16106,
11896,
6596,
13323,
19642,
7634,
25936,
24508,
22406,
2978,
11786,
4257,
26730,
31308,
32617,
21150,
2168,
13999,
29095,
11731,
1062,
23831,
21567,
27941,
3028,
14292,
928,
19680,
12089,
9016,
9759,
7974,
31575,
6755,
12385,
11084,
29063,
28623,
8357,
2749,
22420,
980,
31882,
7804,
8382,
701,
11712,
1974,
1147,
21427,
22553,
5318,
31598,
4008,
20770,
11775,
32513,
13204,
15093,
4063,
23473,
17180,
20347,
18210,
28403,
5975,
10661,
19621,
27772,
1762,
5972,
13351,
1380,
7568,
23274,
9851,
13994,
31331,
18837,
28652,
8647,
14235,
10103,
22803,
8964,
15366,
7378,
22205,
22629,
10091,
18666,
22857,
17895,
8326,
29941,
31185,
25920,
2801,
16771,
30139,
15343,
31944,
21885,
16269,
18915,
5725,
13032,
13614,
14299,
5713,
14376,
30472,
31589,
5911,
5299,
2166,
19636,
5321,
19852,
31263,
23499,
10038,
3167,
18649,
31355,
305},
{
59309,
38738,
50400,
39468,
62689,
33754,
35472,
51998,
65068,
61118,
55554,
62669,
35964,
56596,
42390,
40826,
38720,
37464,
44842,
56662,
39311,
61132,
54287,
51056,
51390,
63081,
45409,
60693,
40401,
38137,
44515,
51986,
47383,
33093,
57312,
55186,
60729,
47805,
44597,
53351,
42374,
44809,
38523,
47754,
48142,
59069,
63250,
48204,
57018,
57443,
51835,
49938,
50365,
58306,
60678,
52068,
61607,
49787,
35155,
39075,
53017,
39799,
57601,
49095,
37348,
35939,
61998,
50724,
47781,
45377,
48040,
51767,
34788,
38331,
61439,
56340,
51376,
63726,
53102,
63325,
49071,
46461,
35878,
54272,
55973,
35954,
55249,
59313,
62290,
47833,
46131,
39693,
48035,
59097,
58366,
64704,
34081,
59376,
34860,
64051,
54935,
47054,
48017,
39135,
39381,
44218,
56209,
35109,
37749,
43180,
54939,
54389,
62952,
52377,
60298,
50022,
34847,
63261,
65355,
59747,
50594,
57464,
36797,
57408,
55185,
64297,
63084,
305}
};

/*
static char *Gp[8]={
"1000000001110100",
"0100000010110010",
"0010000011101000",
"0001000010001011",
"0000100001010111",
"0000010000011110",
"0000001011001101",
"0000000100101111"
};
*/

#define K 8
unsigned int c[8];

main(){
     int i,j,k;
     unsigned int h[N];
     
     
     for(i=0;i<8;i++){
       c[i]=Gp[i];
       printf("%u\n",c[i]);
     }
     
     
     for(j=0;j<8;j++){
       for(i=0;i<N;i++)
	 h[i]=mm[j][i];
       printf("k=%d\n",j);
       /* bingo(m,h); */
     }
for(i=0;i<8;i++)
 roop(i); 


}


void roop(int l)
{
int i,j,k;
unsigned int h[N];
char t[16];

/* 2次元配列として差分の暗号文をm_k=mm[k][i=N] とする。*/
/* 符号語 c[i] と一致するような差分の対応を表示 */
for(k=0;k<K;k++){
  for(i=0;i<N;i++)
    h[i]=mm[k][i];
  for(j=0;j<N;j++){
    for(i=0;i<N;i++){
      if(c[l]==(h[i]^m[j])){
	/* printf("(%d %d) %u =? %u %d\n",i,j,h[i]^m[j],c[l],k); */
	itob(h[i]^m[j],t);
      }
    }
  }
}

}


/* breaking if condition is [1] */
/* then print cyphertext and it's difference */
/* 符号語が未知状態で差分が定数となるような対応を表示 */
void bingo(unsigned int m[],unsigned int n[])
{
  int i,j,count=0,c;
  unsigned int d,e,f,em[N];
  

/* 差分の一致する要素が存在するか */
  q2(N,m);
  printf("\n");
  
  i=0;c=0;
  while(i<N){ 
    j=0;
    d=m[i]^n[0]; /* 最初を固定 */
    /* printf("%u\n",d); */

    for(j=0;j<N;j++){
      e=(m[i+1]^n[j]);
      if(e==d){
	printf("(%d,%d) = %u\n",i,j,d); /* 一致した頂点の出力 */
	c++;
	break;
      }
    }
    i++; /* なければ先に進む */
  }

}




/* 安定なソート */
void q2(int n,int a[])
{
  int i,j,l,r,p;
  int lstack[32],rstack[32];
  int x,t;
  
  l=0; r=n-1; p=0;
  for(;;){
    if(r-l<= 10){
      if(p==0) break;
      p--;
      l=lstack[p];
      r=rstack[p];
    }
    x=a[(l+r)/2];
    i=l; j=r;
    for(;;){
      while(a[i]<x) i++;
      while(x<a[j]) j--;
      if(i>=j) break;
      t=a[i]; a[i]=a[j]; a[j]=t;
      i++; j--;
    }
    if(i-l>r-j){
      if(i-l> 10){
	lstack[p]=l;
	rstack[p]=i-1;
	p++;
      }
      l=j+1;
    }else{
      if(r-j>10){
	lstack[p]=j+1;
	rstack[p]=r;
	p++;
      }
      r=i-1;
    }
  }
  inssort(n,a);
  
}


void inssort(int n,int a[])
{
  int i,j;
  int x;
  

  for(i=1;i<n;i++){
    x=a[i];
    for(j=i-1;j>=0 && a[j]>x;j--)
      a[j+1]=a[j];
    a[j+1]=x;
  }
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}


void itob(int n,char s[])
{
  int i,j,k=0;
  
  for(i=15,j=0;i>=0;i--,j++){
    s[j]=((n>>i) & 0x00001) + '0';
  }
  
  for(j=0;j<16;j++)
    printf("%d",s[j]-48);
printf("\n");

}
