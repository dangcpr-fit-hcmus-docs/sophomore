#VD:
m=50;n=3;p=.5;alpha=0.05 #Tung 30 dong xu can doi 50 lan
y = rbinom(m,n,p)
p.hat = y/n

epsilon = qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n) #Dung sai

matplot(rbind(p.hat-epsilon, p.hat+epsilon),rbind(1:m,1:m),type='l',lty=1,xlab="Vi tri cac khoang tin cay",ylab="50 khoang tin cay")

#Ve 50 khoang tin cay
abline(v=p) #Ve duong thang p=0.5

#Bai 1
#Tao mau 35 gia tri cua bien ngau nhien X~(10;5^2)
n=35
x <- rnorm(n,10,5);x
#Tim KTC 95% cho ky vong, alpha=5%
x.bar = mean(x)
alpha = 0.05
s = 5
epsilon = qnorm(1-alpha/2)*s/sqrt(n)
cat('KTC',100*(1-alpha),'% cho ky vong mu la:\n')
cat('[',x.bar-epsilon,';',x.bar+epsilon,']\n')

#Xoa du lieu duoc gan
rm(list=ls(all=T))

#Bai 2
setwd("D:/R")
#a. Nhap du lieu tu file data31.xls vao R
dat31 <- read.csv("data31.csv",header = T)
dat31
attach(dat31); names(dat31)
#b. Viet ham ci.mean
ci.mean <- function(x,alpha) {
  n = length(x) #Co mau
  x.bar = mean(x) #Trung binh mau
  s = sd(x) #Do lech tieu chuan mau
  t = qt(1-alpha/2,n-1) #Phan vi muc (1-alpha/2) cua T-t(n-1)
  ep = t*s/sqrt(n) #Sai so uoc luong
  cat('KTC',100*(1-alpha),'% cho ky vong mu la:\n')
  cat('[',x.bar-ep,';',x.bar+ep,']\n')
}
ci.mean(profit, 0.05)
ci.mean(profit, 0.01)

#Bai 3
#a.
dat32 <- read.csv("data32.csv",header = T)
dat32
attach(dat32); names(dat32)
ci.mean <- function(x,alpha) {
  n = length(x) #Co mau
  x.bar = mean(x) #Trung binh mau
  s = sd(x) #Do lech tieu chuan mau
  t = qt(1-alpha/2,n-1) #Phan vi muc (1-alpha/2) cua T-t(n-1)
  ep = t*s/sqrt(n) #Sai so uoc luong
  cat('KTC',100*(1-alpha),'% cho ky vong mu la:\n')
  cat('[',x.bar-ep,';',x.bar+ep,']\n')
}
ci.mean(KHTN, 0.05)
ci.mean(KT, 0.01)
#b.
f = length(KHTN[KHTN>5])
ci.prop <- function(f,n,alpha) {
  p.hat = f/n
  ep = qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n)
  cat('KTC',100*(1-alpha),'% cho ky vong mu la:\n')
  cat('[',p.hat-ep,';',p.hat+ep,']\n')
}
ci.prop(f,length(KHTN),0.1)
ci.prop(f,length(KHTN),0.05)
ci.prop(f,length(KHTN),0.01)

#Bai 4
#a. Dua du lieu bang ve dang vecto
a <- seq(1.2,2.0,by=0.2)
b <- seq(1.4,2.2,by=0.2)
m <- (a+b)/2
N <- c(6,34,31,42,12)
x <- rep(m,N);x
#Ap dung ci.mean de tim KTC 95% cho chieu cao trung binh cua thanh nien o trong khu vuc
ci.mean(x,0.05)