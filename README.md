# Wild McEliece（Maquarius）

sagemathを入れましょう。


# 20210308

まあー今年の山でしょう、リスト復号。
印刷した論文の中に多項式ラティスなんて謎が出てきて不安なんですが、もっとわかりやすいMcEliece直伝のリスト復号の解説書があるのでそれで勉強するつもり。
相変わらず理論には無関心で、雑多な計算ばかりに気が向いていしまうのは悲しい性。

ああでも、リスト復号が安全かどうかは電力解析攻撃の仕組みを理解しないとダメなのか。
よし、詳しくなろう。


# 20210226

Wild McElieceの必要性を感じています。

というのも、cado-nfsという因数分解ソフトを使っていて、２０年前に数ヶ月かかっていた計算がわずか２０分ぐらいで、
しかも１台のパソコンで解読できてしまうとわかったからです。

新型暗号は、発明されてから安全だと認識されるまでおよそ２０年から３０年かかるようなので、あと２０年で量子計算機ができるとすると
今から準備していないと間に合わないことになります。
こうして新型暗号の新陳代謝は今後も繰り返されていくのではないでしょうか？
量子暗号という手段もありますが、量子計算機が一般の家庭で使われるようになるのはさらに数十年先であることを考えると、
パソコンを使って計算できる暗号の必要性もまだなくなったわけでもないと感じます。

GoppaDecorderで設定したパラメータはn=8192,t=256というもので、すべての組み合わせnCtの数は10^493というくらいあるので
２０年くらいの間安全性は確保できるのではないかと思っています。（京で攻撃したときのことを考えています）
これは２０年後の計算機パワーを想定してのことですが、足りなければエラーの数を増やすなど対抗作を考えなけれればなりません。

そこでてきたのがWild McEkieceという選択肢です。


代数学の勉強を始めてから、パソコンに向かう時間が減ったんですが、そのせいで全く更新できてません。
事実あまり活動してないでしょう？
でもWildな方にも暗号として鍵を小さくすることができるというようなメリットもあるので実装してみたいです。
勉強に行き詰まったら開発を再開する予定です。

Wildな方は次世代規格外ですが、何事もワイルドに！をモットーにはみ出しを強化しますｗ


# 20210110

https://www.sciencedirect.com/science/article/pii/S0747717102001396

標数p=3,5のとき、n=GF(3^7),GF(5^5)、
n=2187,3125


# 20210109

コードが汚くてもとりあえず動いてくれればいいんだけど、だーれも動くの作ってない。

実装予定：標数p=11,13,17,19の3次拡大体。 n=GF(p^3) こんなもんかな。

n=1331,2197,4913,6859(6860-Extend)

https://arxiv.org/abs/1310.3202

https://tel.archives-ouvertes.fr/tel-01187916/document



# 20210108

https://eprint.iacr.org/2010/372.pdf

https://arxiv.org/pdf/1402.3264.pdf

https://tel.archives-ouvertes.fr/tel-01187916/document

https://www.iacr.org/archive/asiacrypt2014/88730287/88730287.pdf

# 20210104

大して効果がないようなので別の目的で再利用します。
攻撃アルゴリズムを実装するのは好きではないので、Wild McElieceのようなものをやってみたいです。

https://cr.yp.to/codes/wild-20100721.pdf

https://pqcrypto.org/wild-challenges.html

いろいろ専門家のアドバイスを聞いて参考にしています。

# 20210102

概要：例えば、符号の訂正能力をtとし、k=n/2とやると予め行に加えておくエラーeは対角線（あるいは置換行列をeにかけたもの）
になります。このとき、鍵に含まれるランダムエラーeの重みはwt(e)=kになります。

乱数パラメータとして、ランダムメッセージmを符号化する時、wt(m)=t/2とおきます。

この時、スクランブル行列をS、N×N置換行列をP、K×K置換行列をT、送信者が選んだ任意のエラーr（重みwt(r)=t/2）とします。暗号文をcとすると、

鍵生成：G'=SGP+eT

暗号化：c=mG'+r

という感じになります。つまり、wt(m)+wt(r)=tと置けば、送信者は任意のrをメッセージとして送ることができます。

受信者（鍵を公開した人）は最初にどの位置にエラーが入っているのか解っているので、暗号文cを復号した後で
メッセージからエラーeを除去することができます。

ここでは鍵の後半部分のK✕K行列の部分に公開者が意図的に入れたエラーeが入っているものとします。

つまり暗号文はメッセージの後半にあるため、前半部分のエラーだけをメッセージとすればいいことになります。（単純のため）

しかしこのような制約から構造を狙った攻撃だけでなく、既存のISDなどの攻撃に弱くなる可能性も指摘されています。

なのでまず攻撃法から考える必要がありそうです。

まだ調べてませんがこの辺はとても競争が激しいので、誰かがすでにアイデアを出している可能性があり、全容は把握してません。
（専門家も知らないようでした）

鍵にエラーを入れるのは、符号の構造を隠すためですがあまり効果がないだろうか？
復号はできるので、鍵から構造を取り除く意味で鍵にエラーを入れてみた。
こうして新年早々新型候補を公開してみましたが、ISDや構造攻撃に弱くなる可能性があるかどうかは早急に評価が必要になる。

もし鍵に含まれるエラーを特定する方法がなければ、安全だと言えるのだろうか？


例：

Goppa符号の組織符号を例にとって考えます。
バイナリGoppa符号の生成行列をG=[ I || A ]  ( || は連接)となるとき、

```math
   | 1 0 0 | * * *|
G= | 0 1 0 | * * *|
   | 0 0 1 | * * *|
```

とすると、エラーeを入れる位置は、例えば

```math
   |1   0   e|* * *|
G'=|0  1^e  0|* * *|
   |e   0   1|* * *|
```

です。ここでe=1です。


# 20201219

たった一ビットでも暗号化できるならやったほうがいいという攻めの姿勢で行くか、
一ビットしか暗号化できないのはつまらないからやめておこうという守りの姿勢で行くべきか迷う。

公開鍵にエラーを入れるなんてつまらないですかね。

# 20201109

GoppaDecorderのバグの修正に伴い、decode関数とpattarson関数で使うGCD関数を、それぞれogcdとzgcd関数に置き換えました。
この変更によりxgcdはなくなります。
omp指定を外して高速化ができました。

GoppaDecorderの更なるバグがないか調査のため、一時的にこのリポジトリの開発は遅延するかもしれません。

# 20201105

make dev が動きます。bibun関数で異様に遅い現象を改善しました。
逆行列の計算に失敗するバグを修正しました。

GoppaDecoderの方では正常に動くけど、こちらの方で正しいエラー修正ができないバグがまだあります。

バッファーオーバーフローが出る場合は、ulimit -s unlimitedを実行して動かしてください。

# 20201103

make devは正常に動きません。

開発用なのでいじらないように。
随時更新します。

# 20201102

開発と同時進行なので、共通ファイルを書き換えたりして動かなかった人もいるかもしれませんが、一応動作確認してあるので動くはずです。
コードを見やすくするつもりが、モジュール化させ過ぎて細かいところまで見えなくなってしまい逆効果な気が。

動かなかったらごめんなさい。

一応q-*.cみたいなのは全部動きます。

C言語で不便なのは、配列や行列を受け渡しできないこと。
私はいつも配列や行列をメンマに持つ構造体を使って受け渡ししてます。
皆さんは違いますか？ｗ

# 20201030

gf.hがなかったので、追加しました。
これで動きます。

defineがかなりバラバラの状態でどうにもならないので、もう一度全体を見直す必要があります。
というのも、ユークリッド法で訂正する方法と、パターソンで複合する方法を２通りに矛盾なくglobal.hに書かなければならず、
そのへんの定数周りがうまく使いこなせていないのが原因です。

バイナリバージョンは、できるだけ早く完成させたいです。

しかし、またしてもバグ。
教科書に乗っているような小さな例で失敗する。
この程度なら計算例があるからそのとおりになることを確認すればいいだけなので後日直せるからいいだろうけど、
どうしてこう動いていたはずのものがいつの間にか動かなくなるのだろう？

とりあえず動かないのはイカンという人がいたら、GoppaDecorderの方は無事動くのでそちらをクローンしてください。

バグのしっぽを掴んだようなのでまたあした。

# 20201029

kuboon氏のmtx.c行列ライブラリをコードに追加。
コードのスリム化を進めています。

# 20201028

McElieceがほぼ完成した。
位置が０の場合のバグも直した。
エラーの値をランダムにして確認した。

# 20201027

パリティチェック行列を対角化して生成行列を作る関数と、新しく定義した構造体を使って置換行列やスクランブル行列とその逆行列を同時に返すような関数を作ってみました。
C言語では配列渡しや行列渡しができないので、無理やり構造体というデータ型を使って行列型なるものを作って無理やり値渡しをしている。

サンプルでは、一応スクランブルがかかっている状態でも訂正できているのでいいのかなと。
でも本当は良くない。エラー位置が０の場合がうまく処理できていない；

実験的にエラー入りマクエリースは、ニーダーライターでは実現できそうにないので、仕方なくマクエリースの方で実装している。
何だかもうネットがマニュアル代わりになっています。
中途覚醒したときにプログラムなんか始めたりするので、結局朝まで眠れないｗ

ちょっと混乱して、パリティチェックの方にスクランブルとかかけてたんですが、なんとか生成行列にスクランブルをかけて復号することができた。
それにしても毎日プロ並みの長時間をプログラミングに費やしているわけですが、どうせやることもないし、やりたいことが暗号なのでそれで幸せｗ。
でもこれって納期とか成約がないからできるんであって、会社で仕事としてするんだったら苦痛だろうなー。

あー、私もNTTの研究者みたいにホモロジー代数使って暗号理論の一般化やってみたい！
いつになればそのレベルになれるのかわからないけど。

続きはまたあした！

# 20201026

今日はマクエリースの鍵をすべて揃えた状態での復号に成功しました。
鍵をバイナリとバイトに相互変換する関数を書いて、バイナリの状態でも動くようにする必要があります。
それからオリジナルの暗号機能の追加です。
日々進んでいます。
バイナリにしなくても、新型の機能の実験はできるので明日はそれを中心にやろうと思います。

間違っていたら消すつもりでしたが、これはこれでNiederreiter暗号として使えるので、そのまま公開しておきます。

いろいろ考えていますが、バイナリにする前に秘密のエラーを入れておけばそれでうまくいくのかも。
256エラー訂正符号を考えているので、２５６ビット秘密鍵は余裕で暗号化できます。
余った能力は、暗号文をランダム化するためのエラーに使えるだろうと思っています。

# 20201025

何とか今日はプログラミングできた。
昨日のことが思い出せない位眠い。
昨日は確か新しい暗号という目標ができたはずなのだが、それを具体的に書いてなかったので忘れそうである。
仮に暗号ができたとしても、一般代数曲線を使った符号の復号にはならないので必要性がなくなったわけではない。
目標を見逃したか？



ともかくも、バイナリバージョンのMcElieceは完成に近づいたので今日は安心して眠れそうだ。

# 20201024

あまりコーディングする気にならない。
あっという間に２週間近く経過。
このままではいけない。

# 20201011

連接符号や席符号を使えばもっとうまくいきそうだけど実際どうなのかわからない。
simple is best.


# 20201009:具体例を作るまでしばらくお待ちください

[n,k,d]=[24,12,8]-Binary-Golay-Codeを使った場合のメッセージ暗号化復号化のデモンストレーションを作っています。
もう数日かかるので、しばらくお待ちください。

何しろ脳内実験しかしてないので、とんでもない妄想かもしれないですｗ。

参考文献にあたるものがないのですが、基本的にGoppa符号を使っているので、McEliece暗号などの文献を探してみてください。

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


<img src="https://latex.codecogs.com/gif.latex?s=cH=S(GPH+ePH+(mP2)PH)=0+s1+s2">

<img src="https://latex.codecogs.com/gif.latex?s'=S^{-1}s">

2:

<img src="https://latex.codecogs.com/gif.latex?D(s')=eP+mP'P=(e+mP')P=e'">

<img src="https://latex.codecogs.com/gif.latex?e''=(e')P^{-1}">

e"を前半Kビットe、後半kビットm'に分ける。

すると、A,Bがそれぞれ線形なので、それぞれ独立したブロックである。

なので、後半kビットにかかるm'に注目し、

<img src="https://latex.codecogs.com/gif.latex?m=m'P'^{-1}">

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


