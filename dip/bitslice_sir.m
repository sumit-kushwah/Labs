#because this is gray scale so 7 plates are there ;corresponding seven images are there
myimg=imread("catimgdir/catgrey.jpeg");
animg=imread("catimgdir_sir/catgreyside7.jpeg");
#m1=imread("catimgdir/catgrey1.jpeg");
#m2=imread("catimgdir_sir/catgrey1.jpeg");
for i=1 : rows(myimg)
for j=1 : columns(myimg)

if(animg(i,j)<1)
#animg(i,j)=animg(i,j)-1;
#myimg(i,j)=m1(i,j)+m2(i,j);
myimg(i,j)=0;
else
myimg(i,j)=1;
endif

endfor
endfor

imwrite(myimg,"catimgdir/catgrey8.jpeg");
#imwrite(animg,"catimgdir_sir/catgreyside8.jpeg");