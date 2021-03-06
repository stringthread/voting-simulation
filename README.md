# voting-simulation
2020年度モデリングとシミュレーション基礎Ⅰの課題として作成した投票行動シミュレーションです。
# シミュレーション内容
- 100人の有権者を用意し、A,Bの2つにグルーピングします。
- A,Bのうち投票した人数が多かった側のグループに属する有権者に、定額Mを均等に配分します。
- 各有権者はパラメータとして機会費用のデータ(o_cost)を持ち、投票の影響力(influence(type))の値が機会費用パラメータ以上であるとき投票します。
- 機会費用(o_cost)は、A,Bそれぞれについて一定の平均値を定めたうえで、標準偏差を平均値の半分とした正規分布に従う乱数によって、各有権者ごとに決定されます。
- 投票の影響力は、分配される総額M、グループAに属する有権者の数をN<sub>A</sub>、前回に投票した有権者の数をN<sub>V</sub>、前回に投票した中でグループAに属する有権者の数をN<sub>V A</sub>としたとき、N<sub>V A</sub>＞N<sub>V B</sub>ならば(M/N<sub>A</sub>)*{1-(N<sub>V A</sub>/N<sub>V</sub> - 0.5)<sup>2</sup>}、そうでなければ(M/N<sub>A</sub>)*{1-(N<sub>V A</sub>/N<sub>V</sub> - 0.5)<sup>4</sup>}として表します。これは厳密な根拠がある訳ではありませんが、投票する人数が拮抗しているときほど自分が投票することが結果に影響を与える可能性が高まるという性質、投票している人数の偏りが同じであればマイノリティの方が自己の利益のために投票に行きやすいという性質には合致しており、簡便なモデルとしては一定の妥当性があると考えられます。
- この投票ゲーム100回を1セットとして、Aの機会費用平均値とAの人数を変えながらセットを繰り返し、各投票ゲームについて最後の回でのAとBの投票率をCSVファイルに出力します。