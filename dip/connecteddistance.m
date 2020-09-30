matrix_img=[0     0     0     0     0     0     0     0     0     0     0     0     0     0     0  0;
 0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0;
 0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0;
 0     0     0     0     0     0     0     0     0     0     1     1     1     1     0     0;
 2     2     2     2     0     0     0     0     0     1     1     1     1     1     1     0;
 2     2     2     2     0     0     0     0     1     1     1     1     1     1     1     1;
 2     2     2     2     0     0     0     0     1     1     1     1     1     1     1     1;
 2     2     2     2     0     0     0     0     1     1     1     1     1     1     1     1;
 2     2     2     2     0     0     0     0     0     1     1     1     1     1     1     0;
 2     2     2     2     0     0     0     0     0     0     1     1     1     1     0     0;
 2     2     2     2     0     0     0     0     0     0     0     0     0     0     0     0;
 2     2     2     2     0     0     0     0     0     0     0     0     0     0     0     0;
 2     2     2     2     0     0     5     5     5     0     0     0     0     0     0     0;
 2     2     2     2     0     0     5     5     5     0     0     0     0     0     0     0;
 2     2     2     2     0     0     5     5     5     0     0     0     0     0     0     0;
 2     2     2     2     0     0     0     0     0     0     0     0     0     0     0     0];

[y x]=ndgrid(1:size(matrix_img,1),1:size(matrix_img,2));
c=1;
n=max(matrix_img(:));
for k=1:n
  cy=mean(y(matrix_img==k));
  cx=mean(x(matrix_img==k));
  #fprintf('Centroid of Object %d is %2.2g and %2.2g \n', k, cx, cy);
  arrx(c)=cx;
  arry(c)=cy;
  c=c+1;

endfor

distancebw=sqrt((arrx(1)-arrx(2))^2+(arry(1)-arry(2))^2);