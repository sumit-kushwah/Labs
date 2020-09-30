aa=imread("image2.png");
count=0;
for i= 1: rows(aa) 
  for j=1 : columns(aa)
   if(aa(i,j)==0 && (aa(i-1,j)==1 && aa(i,j-1)==1) )
      count++;
    endif 
  endfor
endfor
count


