function [] = SaiPhan(xx,yy,df)   
    df_5DG=(yy(1)-8*yy(2)+8*yy(4)-yy(5))/((xx(2)-xx(1))*12)
    rEdf_5DG=((df-df_5DG)/df);
end