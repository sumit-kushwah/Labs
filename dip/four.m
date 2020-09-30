#finding connected component using 4-connected algo
img= imread("dip4.jpg");
label=0;
intstart=0;
count=1;
for i=2 : rows(img)
    for j=1 : columns(img)-1
        if(img(i,j)==0 && (img(i,j+1)==0 || img(i-1,j)==0))
            label

        
