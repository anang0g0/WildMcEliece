# Private-key-Cryptosystem-using-Subfield-Subcode

部分体部分符号を用いた秘密鍵暗号とその実装（修論補完計画）
20201006（今の所、設計段階）

単にニーダーライター暗号を秘密鍵にしただけ。（でも安全）

暗号化鍵が見えなければいいので、鍵サイズも公開鍵バージョンよりずっと小さくなる。

その代わりRao-Nam暗号より鍵がでかい。

そしてシンドロームエラーテーブルも使わない。

この場合、選択平分攻撃は、暗号化鍵をブラックボックスとして、ひたすら平文とそれに対応する暗号文を集める差分攻撃になる。

この時、暗号解読に必要となる平文と暗号文のデータを、すべて集めるのが物理的に不可能な時間とサイズを見積もることで、 この手の秘密鍵暗号の様々なバリエーションに、秘密鍵サイズに応じた、安全性に対する一つの下界を算出することができるだろう。

ここでちょっとはみ出してみると、ハミング重み＝最小距離d-1のエラーを混ぜた時、２つの過剰なd-1重みのエラーベクトルの シンドローム衝突を見つける難しさに基づいてハッシュ関数も作れそうなお感がする。

ハッシュ関数の設計に符号理論の結果を使うほうが、無理に死にかけた秘密鍵暗号を組成するよりまともかもしれないが、 それはまた別の研究テーマになる。

ある秘密鍵暗号の試論

公開パラメータ：n=1024,k=32＊10=320,secret key size 320bit(必要なら+320＊320+10＊1024=112960bit),wt(r)=32(r is random error)

暗号化：

1.input m;

2.output randomization c=(H(r)^m,rH);wt(r)=32

PACEではシンドロームエラーテーブルと暗号化行列の両方が秘密鍵であり、暗号化するときも復号するときも同じ鍵を使う。（多分これは普通）

秘密鍵マックリース暗号では、暗号化にゴッパ多項式から生成されるパリティ検査行列を使い、 秘密鍵にゴッパ多項式と復号アルゴリズムにパターソンアルゴリズムを使う。

エラーテーブルは使わない。

ということは毎回秘密鍵から暗号化行列を生成することになり、カギ生成のオーバーヘッドが問題になる。

なんでこんなことをするかというと、単純に、ナードっぽく1つの平文に対して集めきれないほど大きな暗号文が生成されることを狙っているからだ。

参考文献によると、PACE解読にかかる計算量はO(k^2nN^2)であるが、実はこのN(１つの選択平文に対する、可能な全ての暗号文の数)というのは指数的である。

なのでこのNが途轍もなく大きければ計算できないことになる、というのが私の論文の趣旨であった。 実際エラーテーブルを使ってこのＮを大きくしようとすると、秘密鍵サイズも膨大に増えてしまって改良にならない。

そこで、エラーテーブルを使わないで普通に訂正できる範囲内で暗号化復号化できるようにしようという感じで、秘密鍵マクリースは生まれた。 そしてそのようなパラメータとしてn=8192、k=3328を選んだ。（でかすぎｗ）

このパラメータは正しくないと思うのだが、折角だから修論補完計画としてやってみよう。（予定）

そしてＰＡＣＥっぽく、エラーテーブルの代わりに、最初から暗号化鍵にエラーを混入させておくタイプの暗号方式が可能かどうかやってみよう。 これは例えば、ニーダーライターではなくマックリースだけに言えるのだが、暗号化行列は符号の生成行列であると同時に、 カギ自体が符号語であるということを利用する。

＊　PACE：Rao-Nam Scheme　＊

１．秘密鍵：ハミング距離=3であるような簡単な符号、ハミング重みｔ=n/2である幾つかの過剰なエラーとそのシンドロームの対応表。

２．暗号化：

G'=SG

c=(mSG+e)P

３．復号：

c=(mSG+e)P=mSGP+eP

c'=cP=mSG+e

c'H=s

Z(s)=e

a=c'^e=c=mSG

a(SG)^{-1}=m


# 20201007（改良型Rao-Nam秘密鍵暗号）

設定：

１，[n,k,d]=[256,128,33]-バイナリGoppa Codeを考える。
ここで、訂正可能なエラーベクトルwt(t)=16とする。

２．暗号化鍵をE=SGPとして、S,G,Pは秘密鍵である。

３．Eの前半ｋビットをＡ、後半n-kビットをＢとする。Ｂの異なる全ての列iに重み1のエラーe_iが１か所づつ、混入されているものとする。 
エラーe_iが入った暗号化鍵をE'とする。

つまり、乱数ｒをwt(r)=tとすると、c=rE'には必ず重みtのダミーエラーパターンe'=Σe_i,k<i<nが入っていることになる。

４．暗号化鍵E'の各行の後半のどの位置にダミーのエラーeが入っているか、暗号文作成者は知っている。
wt(e)=tとして、eは毎回ランダムに変えても構わない。

暗号化：

１．乱数rをwt(r)=t,|r|=kとする。暗号文をc=rE'+mとする。

２．（暗号化フォーマット）平文ｍはwt(m)=t、|m|=k-tだが、mは左詰めとし、ｍの最後の１が立っている位置で平文ブロックを切ることとする。

もしwt(m)<tの場合は、暗号文フォーマットとして、平文の右側最後のk-tビットに対して、ハミング重みがt-wt(m)=xビットの１を連続してパディングする。
ここで、wt(m+e)=2tである。

復号化：

1.wt(r)=tより、暗号文ｃの後半kビットをbとするとs=bHである。

2.D_k(s)=e

3.c^e=c'

4.c'H=s2

5.D_k(s2)=m

ゆえに、平文ｍはm'の前半に含まれる。 ここでeは鍵の後半に入っているwt(r)=wt(e)となるランダムエラーであり、mは重みwt(m)+wt(r)=tなる平文ｍである。

その２：

設定：その1と同じとする。

暗号化：

１平文mを|m|=kとなるようにとり、ランダムエラーベクトルrをwt(m)+wt(r)=tとなるようにとる。
また、|m|<kのばあい、mの最後の1以降を０でパディングする。

２．暗号文c=mE'+rとする。
エラーベクトルrは、E'の前半kビットに入れる。

３.暗号化鍵E'のmに対するダミーエラーからできたエラーパターンをe'とすると、cに含まれるエラーはr+e'。
ここで、wt(r+e')=t。


復号：

1．cH=s

2.D(s)=r^e'。

3.m'=c^(r^e')とし、m=m"A^{-1}。

ここで、E'の次元をｋとすると、ｍ’の前半ｋビットをm",Eの前半ｋ＊ｋ行列をＡとする。

参考文献：THE RAO-NAM SCHEME IS INSECURE AGAINST A CHOSEN-PLAINTEXT ATTACK

https://link.springer.com/chapter/10.1007/3-540-48184-2_40

