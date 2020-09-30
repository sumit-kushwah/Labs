f=zeros(101,101);
f(1,1)=1;
f(101,1)=1;
f(1,101)=1;
f(101,101)=1;
f(51,51)=1;

theta = 0 : pi / 100 : 2 * pi;

for i = 1 : rows(f)
for j = 1 : columns(f)
    if (f(i, j) == 1)
        rho = i * cos(theta) + j * sin(theta);
        plot(rho);
        hold on ;
    endif
endfor
endfor
