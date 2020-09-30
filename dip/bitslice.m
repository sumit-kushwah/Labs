#because this is gray scale so 7 plates are there ;corresponding seven images are there
myimg=imread("catgrey.jpeg");
for i=1 : rows(myimg)
for j=1 : columns(myimg)

if(myimg(i,j)>=128)
myimg(i,j)=128;
endif

endfor
endfor


imwrite(myimg,"catgrey1.jpeg");