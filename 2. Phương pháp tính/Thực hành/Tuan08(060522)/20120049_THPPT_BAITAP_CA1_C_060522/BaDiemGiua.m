function [] = SaiPhan(xx,yy,df)
    df_3DG=(-yy(1)+yy(3))/(xx(3)-xx(1))
    rEdf_3DG=((df-df_3DG)/df);
end