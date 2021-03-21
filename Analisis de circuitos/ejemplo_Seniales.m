FS=1000
x=0:1/FS:20;
%%plot(x,sierra2(x))
plot(x,cuad(x).*tri(x))

figure 2
plot(x,cuad(x),x,tri(x))


%0=4*2/pi(x+a)+1
%-1=8/pi(x+a)
%-pi/8=1+a
%-pi-8/8=+a