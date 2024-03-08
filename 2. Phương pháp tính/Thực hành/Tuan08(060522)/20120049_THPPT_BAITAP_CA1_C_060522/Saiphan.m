function [] = Saiphan(xx,yy,df)
    df_SPT = (yy(3)-yy(2))/(xx(3)-xx(2))
    rEdf_SPT = abs((df-df_SPT)/df);
    
    df_SPL = (yy(2)-yy(1))/(xx(2)-xx(1))
    rEdf_SPL = abs((df-df_SPL)/df);
end