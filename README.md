# Pubric-key-Cryptosystem-with-Hidden-error-bit
# （間違えたら消します）

# 20201009:エラー入りMcEliece暗号のつづき


どの位置にエラーが入っているかを知っているのは公開鍵作成者だけである。

つまり、そのエラー位置の記録は秘密鍵だ。

逆にこう言える。
好きな場所にエラーが入れられるということは、一見乱数を暗号化しているように見えて、符号に含まれるエラーを用いて任意のメッセージを復号時に再現できるということを意味している。

もしそうなら、後半部分に暗号化鍵に含まれるエラーを使って真のメッセージを構成するのと同時に、
前半部分のwt(m)+wt(e)=tのeをランダムにすることで、あたかも乱数をやり取りしているように見せることができる。

この暗号が成功するためには、鍵のどこにエラーが隠されているかが識別不可能であることにかかっている。

あとは先日考えた方法と、どちらがメッセージを効率的かつ安全にに暗号化できるかどうかで決まる。

これを公開鍵に使うことで、送信者は公開鍵に含まれるエラーを知る必要がない。

公開鍵の作り方、暗号化、復号化について説明する。

１，公開鍵Ｆエラー訂正数ｔを次のように作る。

秘密鍵は、S,G,P,P2である。

D=GP

Dの前半ｋ＊ｋ行列部分をA、Dの後半ｋ＊ｋ行列をBとし、Iにｋ＊ｋ置換行列 P2 をかけてＩをランダム化し、それを新しくBにXORする。

ここで、I　はｋ＊ｋビットの単位行列である。

つまり、IP2=m"とおくと、

E=S(A|B)=S(GP+IP2)=SGP+S(IP2)P=SGP+Sm"P

IP2は置換P2で単位行列をランダム化したものである。
ここで、公開鍵にはm"というエラーが入ることになる。

Eと、訂正可能なエラーの数　ｔ　を公開鍵として公開する。

２，暗号化

c=mE+e（eは　wt(e)>0,mは　0=<wt(m)<t、eは　cの前半ｋビットに入れる。）

ここで、wt(e)+wt(m)=t　である。


３．復号化

1.暗号文cに対して、

s=cH=S(GPH+ePH+(mP2)PH)=0+s1+s2

s'=(S^{-1})s

2:
D(s')=eP+mP2P=(e+mP2)P=e'

e"=(e')P^{-1}

e"を前半Kビットe、後半kビットm'に分ける。

すると、A,Bがそれぞれ線形なので、それぞれ独立したブロックである。

なので、後半kビットにかかるm'に注目し、

m=m'P2^{-1}


# 20201007　エラー入りMcEliece公開鍵暗号

最初から公開鍵にエラーを混入させておくタイプのMcEliece暗号方式の変種が可能かどうかやってみよう。

これは例えば、ニーダーライターではなくマックリースだけに言えるのだが、暗号化行列は符号の生成行列であると同時に、 カギ自体が符号語であるということを利用する。

隠れエラービットマックリース暗号では、暗号化にゴッパ多項式から生成されるパリティ検査行列を使い、 秘密鍵にゴッパ多項式と復号アルゴリズムにパターソンアルゴリズムを使う。


20201007：

・課題その２　エラー入りMcEliece暗号（設計中）

設定：[n,k,d]=[640,320,65]-binary Goppa Code。

ここで、t=32とする。

1.E=SGPとする。

２，Eの後半n-k個の異なる列に重み１のエラーを加える。Eの次元は320なのでその組み合わせは320C32になる。
E'=Σ(e_i^E_i)(0<i<k)とする。

3．暗号化鍵E'の各行のどの位置にエラーe_iが入っているか、暗号文作成者は知っている。
暗号文作成者は、この隠されたエラーeを情報シンボルとして利用することで、任意のメッセージを受信者が復元できるようにする。
ある意味、公開鍵暗号をエラーでマスクすると言ってもいい。


目的としているセキュリティパラメータは１２８ビットである。（目標）

２５６ビット以上のセキュリティを実現したい場合は、符号長を１０２４にしなければならないだろう。（予想）


その１

暗号化：（ISDを理解してない）

１．乱数rをwt(r)+wt(m)=t,|r|=kとする。暗号文をc=rE'+mとする。

ここで、wt(m)<t,0<wt(r)=<tである。wt(r)>0なのは符号語が消えないため。

２．（暗号化フォーマット）平文ｍはwt(m)<t,|m|=kだが、mは左詰めとし、ｍの最後の１が立っている位置で平文ブロックを切ることとする。(残りは０で埋める)


復号化：

1.wt(r)+wt(m)=tより、暗号文ｃに対してシンドロームs=cHを計算する。

2.D_k(s)=e

3.wt(e)=tなので、前半ｋビットが平文である。



その２：(１とほぼ同じ)

設定：

１，[n,k,d]=[640,320,65]-バイナリGoppa Codeを考える。
ここで、訂正可能なエラーベクトルwt(t)=32とする。
更にパリティ検査行列のパラメータは[n,k]=[640,320]である。

２．暗号化鍵をE=SGPとして、S,G,Pは秘密鍵である。

３．Eの前半ｋビットをＡ、後半n-kビットをＢとする。Ｂの異なる全ての列iに重み1のエラーe_iが１か所づつ、ランダムに混入されているものとする。 
エラーe_iが入った暗号化鍵をE'とする。

つまり、乱数ｒをwt(r)=tとすると、c=rE'には必ず重みtのダミーエラーパターンe'=Σe_(i,j),k<i<n,0<j<kが入っていることになる。


暗号化：

１平文mを|m|=k、wt(m)=<tとなるようにとり、ランダムエラーベクトルrをwt(m)+wt(r)=tとなるようにとる。(mは０でもいい)
また、|m|<kのばあい、mの最後の1以降を０でパディングする。

２．暗号文c=mE'+rとする。
エラーベクトルrは、E'の前半kビットに入れる。

３.暗号化鍵E'のmに対するダミーエラーからできたエラーパターンをe'とすると、cに含まれるエラーはr+e'。
ここで、wt(r+e')=t.


復号：

1．cH=s

2.D(s)=r^e'

3.m'=c^(r^e')とし、m=m"A^{-1}。

ここで、E'の次元をｋとすると、ｍ’の前半ｋビットをm",E'の前半ｋ＊ｋ行列をＡとする。

