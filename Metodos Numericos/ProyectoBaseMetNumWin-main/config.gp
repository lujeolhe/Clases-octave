set zeroaxis
set style line 1 lc rgb '#E41A1C' pt 1 ps 1 lt 1 lw 2
set style line 2 lc rgb '#377EB8' pt 6 ps 1 lt 1 lw 2
set style line 3 lc rgb '#4DAF4A' pt 2 ps 1 lt 1 lw 2
set style line 4 lc rgb '#984EA3' pt 3 ps 1 lt 1 lw 2
set style line 5 lc rgb '#FF7F00' pt 4 ps 1 lt 1 lw 2
set style line 6 lc rgb '#FFFF33' pt 5 ps 1 lt 1 lw 2
set style line 7 lc rgb '#A65628' pt 7 ps 1 lt 1 lw 2
set style line 8 lc rgb '#F781BF' pt 8 ps 1 lt 1 lw 2
set style line 9 lc rgb '#9b9b9b' pt 9 ps 1 lt 1 lw 2
set palette maxcolors 8
set style line 11 lc rgb '#808080' lt 1 lw 3
set border 0 back ls 11
set tics out nomirror
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
unset grid
set font ",12"
set grid
set style arrow 5 heads filled size screen 0.02,5,30 ls 9

set arrow from 0, graph 0 to 0, graph 1 nohead as 5
#set term pdfcairo font "./SF_Cartoonist_Hand.ttf"
#set output 'biseccion.pdf'
#set key right top
unset key
#set xlabel "x"
#set ylabel "f(x)"
