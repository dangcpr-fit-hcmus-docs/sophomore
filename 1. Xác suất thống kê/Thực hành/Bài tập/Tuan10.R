#Bai 1
setwd("D:/R")
dat1 <- read.csv("volume.csv", header = T)
attach(dat1); names(dat1)
dat1
x <- dat1[,2]
y <- dat1[,3]
x
y
#a.
#var.equal: kiem tra 2 phuong sai co bang nhau khong, bang thi TRUE, ko bang thi FALSE
t.test(x,y,alternative = "two.sided", var.equal = FALSE, conf.level=0.95)
#Chua du co so de bac bo H0
#The tich trung binh nhu nhau

#b. p-value = 0.1425

#c.Tim khoang tin cay 95%
#-0.0014 <= mux - muy <= 0.00021

#d.
test.leq.oneside <- function(x,y, mu0, sigma1, sigma2, alpha){
  m = length(x)
  n = length(y)
  x.bar = mean(x)
  y.bar = mean(y)
  z0 = (x.bar - y.bar - mu0) / (sqrt(sigma1^2/n+sigma2^2/m))
  p.value = pnorm(z0)
  cat('Voi muc y nghia alpha = ',alpha*100, '% :\n')
  if (p.value < alpha)
    cat('Bac bo Ho voi p-gia tri = ', p.value, '\n')
  else
    cat('Chua du co so  de bac bo H0 voi p-gia tri = ', p.value, '\n')
}
test.leq.oneside(x,y,0,0.002,0.0025,0.05)
t.test(x,y,alternative = "less", var.equal = FALSE, conf.level=0.95)

#e. 
test.geq.oneside <- function(x,y, mu0, sigma1, sigma2, alpha){
  m = length(x)
  n = length(y)
  x.bar = mean(x)
  y.bar = mean(y)
  z0 = (x.bar - y.bar - mu0) / (sqrt(sigma1^2/n+sigma2^2/m))
  p.value = 1-pnorm(z0)
  cat('Voi muc y nghia alpha = ',alpha*100, '% :\n')
  if (p.value < alpha)
    cat('Bac bo Ho voi p-gia tri = ', p.value, '\n')
  else
    cat('Chua du co so  de bac bo H0 voi p-gia tri = ', p.value, '\n')
}
test.geq.oneside(x,y,0,0.002,0.0025,0.05)
t.test(x,y,alternative = "greater", var.equal = FALSE, conf.level=0.95)

#Bai 2 (Vi du 2)

cholesterol = read.table('cholesterol.txt',header=TRUE)
cholesterol
attach(cholesterol)
var.test(Before,After)

#Lay ket qua tu kiem dinh phuong sai
v.equal <- ifelse(var.test(Before,After)$p.value < alpha, FALSE, TRUE); v.equal
t.test(Before,After,alternative = 'greater', var.equal = v.equal, conf.level = 0.95, paired = TRUE)
#Bac bo H0: mux - muy = 0
#Voi muc y nghia 5%, che do an kieng va tap the duc co hieu qua
#trong viec giam ham luong cholesterol trong mau nhung nguoi beo phi tham gia thu nghiem
