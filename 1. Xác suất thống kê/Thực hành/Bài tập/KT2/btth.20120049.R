# Bai tap thuc hanh so 2
# Lop: C3 - Ca 1 - 20CTT1A
# Ho ten: Nguyen Hai Dang /MSSV: 20120049

p0 <- 0.6
alpha <- 0.05
# a/
#Em chon cap giai thuyet 2:
#Vi theo de bai neu ty le giang vien dong y tren 60% thi su thay doi xay ra
#Co nghia la H1: p > 0.6
#=> Chon gia thuyet 2


# b/
load('data04.rda')
summary(survey)
survey
y <- length(survey[survey==1])
n <- length(survey)
y
n
prop.test(y, n, p = p0, alternative = "greater", conf.level = 1-alpha)
#Ta thay p-value = 0.0262 < 5% = alpha
#Do do ta bac bo gia thuyet H0
#Ket luan: Hoi dong khoa hoc nen thay doi thang diem

# c/
#Vi p > p0 => ta can tinh z(1-a) va p-value = 1-p(x <= z)
proptest.xeq <- function(f,n,p0,alpha) {
  z0 = (f/n-p0)/(sqrt(p0*(1-p0)/n))
  cat('z0 = ', z0)
  p_value = 1-pnorm(z0, lower.tail=TRUE)
  cat('\np-value = ', p_value)
  if(p_value<alpha)
    cat('\nBac bo H0')
  else
    cat('\nChua du co so de bac bo H0')

}
proptest.xeq(y,n,p0,alpha)