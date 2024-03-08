# Bai tap thuc hanh so 3
# Lop: C3 - Ca 1 - 20CTT1A
# Ho ten: Nguyen Hai Dang /MSSV: 20120049

#Bai 1
alpha = 0.05
setwd("D:/R/KT3")
pro <- read.csv("Profit.csv",header = T)
pro
attach(pro); names(pro)
a <- pro[,2]; a
b <- pro[,3]; b

#Cau a.
v.equal <- var.test(a,b,data=pro); v.equal
ans=t.test(a,b,alternative = "two.sided", var.equal = TRUE, conf.level=1-alpha)
ans
cat('Khoang tin cay',ans$conf[1],'<= mux - muy <=',ans$conf[2],'\n')
#Khoang tin cay ve sai khac doanh so ban hang trung binh la:
#7.459276 <=mux - muy <= 41.40653 

#Cau b
#H0: p1 <= p2
#H1: p1 > p2
an <- length(a[a>600])
bn <- length(b[b>600])
y <- c(an,bn)
n <- c(length(a),length(b))
ans2 = prop.test(y,n,alternative = 'greater', conf.level = 1-alpha)
ans2
cat('p-value =',ans2$p.value,'\n')
#p-gia tri = 0.1661
#p-gia tri > alpha = 0.05 => Sai
#Khong du co so de bac bo gia thuyet H0
#Chua du bang chung de ket luan doanh so quan 1 cao hon quan 3

#Cau c
prop.test.leq <- function(x,y,alpha) {
  x0 <- length(x[x>600])
  y0 <- length(y[y>600])
  p1 = x0/length(x)
  p2 = y0/length(y)
  p = (x0+y0)/(length(x) + length(y))
  z0 = (p1-p2)/sqrt(p*(1-p)*(1/length(x) + 1/length(y)))
  p.value = pnorm(z0)
  cat("p-value = ",p.value, '\n')
  cat('Voi muc y nghia alpha = ',alpha*100, '% :\n')
  if (p.value < alpha)
    cat('Bac bo Ho voi p-gia tri = ', p.value, '\n')
  else
    cat('Chua du co so  de bac bo H0 voi p-gia tri = ', p.value, '\n')
} 
prop.test.leq(a,b,alpha)

#Bai 2

#Cau 2: Do tin cay 5%
h <- c(600,1000,1250,1600,1800,2100,2500,2900)
f <- c(56,54,56,50,47,49,47,45)
n = length(h)
#Doi 9.8 do C/km = 0.0151 do F/ft
b0 = 0.0151
plot(h,f)
abline(lm(f~h))
result = lm(f~h)
summary(result)
res = resid(result) # cac thang du cua result
b1 = (coef(result))[['h']] # He so do doc cua duong thang hoi quy
b0 = mean(f) - b1*mean(h)
cat('Uoc luong duong thang hoi quy F=',b0,'+ (',b1,")*h\n")

#Cau b
#Ho: B1 = 0.0151
#H1: B1 != 0.0151
MSE = sum( res^2 ) / (n-2)
Sxx = sum((h-mean(h))^2)
t = (b1 - b0 ) / sqrt(MSE/Sxx)
ifelse(abs(t) > qt(1-alpha/2,n-2), 'Bac bo H0', 'Ko du co so bac bo H0')
#Ta thay ket qua Bac bo H0
#Vay kinh nghiem cua de bai khong dung
