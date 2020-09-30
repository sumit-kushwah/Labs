aa=imread("imagesample.jpg");
cc=aa;
for i=2 :  rows(aa)-1
for j=2 : columns(aa)-1
#vertical masking
#v1=aa(i+1,j+1)+2*aa(i,j+1)+aa(i-1,j+1)-(aa(i-1,j-1)+2*aa(i,j-1)+aa(i+1,j-1));
v2=aa(i+1,j-1)+2*aa(i-1,j)+aa(i+1,j+1)-(aa(i-1,j-1)+2*aa(i-1,j)+aa(i-1,j+1));

cc(i,j)=v2;
endfor
endfor
imwrite(cc,"hmaskedsobel.jpg");
