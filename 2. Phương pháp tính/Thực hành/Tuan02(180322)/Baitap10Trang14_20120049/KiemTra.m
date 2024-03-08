function KiemTra (p, pTB, d)
    pTBd = pTB - d;
    pTBt = pTB + d;
    if (p <= pTBt && p >= pTBd) disp('Dung')
    else disp('Sai')
    end
end