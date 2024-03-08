# Mo phong 1: cho X1, ..., Xn ~ N(mu,sigma) khi
#do X.bar ~ N(mu,sigma^2/n)

#Gan cac gia tri
n = 10; mu = 2; sigma = 2

# Tao vecto X = (X1,...,Xn) ~ N(mu,sigma)
VecX <- function(n) rnorm(n,mu,sigma)

# Tinh gia tri trung binh sau:
MeanX <- function() mean(VecX(n))

# Lap lai qua trinh tren n lan
SampleMeanX <- function(m) replicate(m,MeanX())

# Ve bieu do tan so cho du lieu vua tao
hist(SampleMeanX(10000),freq=0,breaks=30)

#kiem tra lai bang cach ve ham do pp
#N(mu, sigma^2/n)
curve(dnorm(x,mu,sigma/sqrt(n)),col="blue",lty = 1, lwd =2, add = T)


#Mo phong 1.2: CHo X1,...,Xn ~ N(mu,sigma)
#Khi do (n-1)*S^2/sigma^2 ~ X^2(n-1)

#Tinh gia tri bien S = (n-1)*var(VecX(n))/sigma^2
S <- function() (n-1)*var(VecX(n))/sigma^2

#Lap lai qua trinh tren m lan
SampleS <- function(m) replicate(m,S())

#Ve bieu do tan so cho du lieu vua tao
hist(SampleS(100),freq=0,breaks=40)

#Ve ham mat do cua pp X^2(n-1)
curve(dchisq(x,n-1),col='red', lty=1, lwd=2,add=T)


#Bai1
#Viet ham tao MauY
m = 0
s = 1
MauY <- function() {
  X1 <- rnorm(1,m,s)
  X2 <- rnorm(1,m,s)
  Y = (X1)^2 + (X2)^2
}
Y <- function(n) replicate(n,MauY())
draw <- function(m) {
  #Ve bieu do tan suat
  hist(Y(m),freq=0,breaks=48)
  #Ve ham mat do cua phan pho Chi binh phuong 2
  # bac tu do
  # vao cung 1 bieu do (add=TRUE)
  curve(dchisq(x,2),col="blue",lty=1,lwd=2,add=TRUE)
}
par(mfrow=c(1,3))
draw(100)
draw(1000)
draw(10000)