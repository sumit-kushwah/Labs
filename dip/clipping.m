dd=imread("flower.png");
mm= rgb2gray(dd);

for i=1 : rows(mm)
  for j=1 : columns(mm)
      if(mm(i,j)>102 && mm(i,j) < 200 )
      mm(i,j)=0;
    else
      mm(i,j)=255;
      endif
  endfor
endfor
imwrite(mm,"flowerclip.png");