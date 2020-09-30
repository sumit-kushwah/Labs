dd=imread("flower.png");
mm= rgb2gray(dd);


for i=1 : rows(mm)
  for j=1 : columns(mm)
      if(mm(i,j)>100 && mm(i,j) < 200 )
      mm(i,j)=100+1.55*(mm(i,j)-100);
      endif
  endfor
endfor
imwrite(mm,"flowercontrast.png");