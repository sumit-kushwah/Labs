aa=imread("imagesample.jpg");
cc=aa;
for i=2 :  rows(aa)-1
for j=2 : columns(aa)-1
#vertical masking
#v1=aa(i+1,j)+aa(i-1,j)+aa(i,j+1)+aa(i,j-1)-4*aa(i,j);
v2=4*aa(i,j)-(aa(i+1,j)+aa(i-1,j)+aa(i,j+1)+aa(i,j-1));

cc(i,j)=v2;
endfor
endfor
imwrite(cc,"negative_lap.jpg");
