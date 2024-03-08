#Vi du
setwd("D:/R")
load('heights.rda')
summary(heights)
hist(heights)
heights
t.test(heights, alternative = "two.sided", mu = 160, conf.level=0.95)

#Bai 1.
#Dua du lieu vao R:
data <- read.csv("profit.csv")
x <- data$profit
x

#Cau a: Ve do thi cua du lieu
hist(x)
#Nhan xet: Du lieu da cho co dang dieu xap xi chuan
hi.pro <- x[x>65]
hi.pro
#Cau b: Uoc luong khoang tin cay 99%
x.mean <- function(x,alpha) {
  x.bar <- mean(x)
  s <- sd(x)
  n <- length(x)
  ep = qnorm(1-alpha/2)*s/sqrt(n)
  mu.lower = x.bar - ep
  mu.upper = x.bar + ep
  cat('Khoang tin cay',100*(1-alpha),"% cho ky vong mu la:\n")
  cat('[',mu.lower,';',mu.upper,']\n')
}
x.mean(hi.pro,0.01)

#Cau c. Nhan xet phuong thuc ban hang moi voi muc y nghia 1%
#Ho: "mu <= 60"
#H1: "mu > 60"
t.test(x, alternative = "greater",mu=60,conf.level=0.99)
#Nhan xet: Ket qua cho ta p-value = 0.9699 > 0.01 = 1% = alpha
#Do do chua du co so de bac bo gia thuyet H0: "mu <= 60" voi muc y nghia 1%
#Khong mang lai hieu qua bang phuong thuc ban hang truoc do

#Cau 2
xi <- c(5,6,7,8,9,10)
ni <- c(5,10,15,20,12,8)
x <- rep(xi,ni)
x
#Ve bieu do stem&leaf cho du lieu x
stem(x)

#Cau b: Viet ham test.geq.oneside(x,mu0,alpha) d??? ki???m d???nh 
#gi??? thi???t H0: mu = mu0 và d???i thi???t H1: mu > m0. Ap dung H1: mu > 8
test.geq.oneside <- function(x, mu_0, alpha) {
  x.bar = mean(x)
  s = sd(x)
  n = length(x)
  # tinh gia tri thong ke kiem dinh
  t_0 = (x.bar - mu_0)*sqrt(n)/s
  # tinh p-value
  p.value = 1-pt(t_0,n-1)
  cat('Voi muc y nghia alpha=',alpha, ':\n')
  if (p.value <= alpha)
    cat('Bac bo H0 voi p-value = ',p.value)
  else
    cat('Chua du co so de bac bo H0 voi p-value=',p.value)
}
test.geq.oneside(x,8,0.05)
t.test(x,alternative = 'greater',mu=8,conf.level=0.95)

#Kiem dinh gia thuyet cho ti le
#Bai 6
dat <- read.csv()