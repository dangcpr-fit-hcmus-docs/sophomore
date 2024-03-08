# TH XSTK Bai 3: Bien ngau nhien (Tuan 3-4)

# Vi du 1 a
# Tao vec to k có gia tri tu 0 den 8
k = 0:8
# Viet ham xac suat
p <- function(k) choose(8,k) * 0.3^k * 0.7^(8-k)
dbinom(k,8,0.3)
# Tinh gia tri xac suat P(X = k), k = 0,1,...,8
p(k)



# Vi du 1 b
# Viet ham mat do cua bien ngau nhien X ~ N(mu = 0,sigma^2 = 1)
f <- function(x, mu=0, sigma=1){
  1/sqrt(2*pi*sigma^2) * exp(-(x-mu)^2/(2*sigma^2))
}

# Tinh f(0)
dnorm(0,0,1)
f(0)

par(mfrow = c(2,1))

# Vi du 2 a
# Ve ham xac suat o vi du 1a
plot(0:8, dbinom(0:8,8,0.3), type = "h", xlab = "k", ylab = "P(X = k)", main = "Ham xac suat cua bnn X")

plot(k, p(k), type = "h", xlab = "k", ylab = "P(X = k)", main = "Ham xac suat cua bnn X")



# Vi du 2 b
# Ve ham mat do xac suat o vi du 1b
curve(f(x,0,1),from=-3,to=3, xlab = "x", ylab = "fX(x)", main = "Ham mat do cua bnn X")
curve(dnorm(x,0,1),from=-3,to=3, xlab = "x", ylab = "fX(x)", main = "Ham mat do cua bnn X")


# Vi du 3 a
# Viet ham pp xac suat FX
F <- function(k) sum(p(0:k))
# Vecto hoa ham FX
F <- Vectorize(F)
# Tinh F(4)
F(4)

pbinom(4,8,0.3)
pbinom(0:8,8,0.3)

# Vi du 3 b
# Viet ham pp xac suat
F2 <- function(a,mu = 0, sigma = 1){
  integrate(function(x) f(x,mu,sigma), lower = -Inf, upper =a)$value
}
# Vecto hoa ham 
F2 = Vectorize(F2)
F2(1.96)

pnorm(1.96,0,1)

# Vi du 4 a
plot(stepfun(k, c(0, F(k))), ylab = "FX(x)", main = "cdf of X")
plot(stepfun(0:8, c(0, pbinom(0:8,8,0.3))), ylab = "FX(x)", main = "cdf of X")


# Vi du 4 b
curve(F2(x), from = -3, to = 3, ylab = "FX(x)", main = "cdf of X")


# Vi du 5 a
K = k[F(k) >= 0.25]
K[1]

# kiem tra lai
F(0)
F(1)


# Vi du 5 b
uniroot(function(x) F2(x)-0.975, c(-3,3))$root

# kiem tra lai
F2(1.96)

#Bai 1

#Nhap gia tri cho cac tham so:
x <- 0:15
m = 25; n=100-25;k=15
dhyper(x,m,n,k)

# Ve bieu do cot ham xac suat cua X~H(100,25,15)

barplot(dhyper(x,m,n,k))

#Bai 2

#Cach 1: tinh tong xac suat: P(5<=X<=12)
sum(dhyper(5:12,m,n,k))

#Cach 2
phyper(12,m,n,k)-phyper(4,m,n,k)

#Bai 3
#Cau a: Ve ham mat do cua X~exp(lamba = 0.6):
curve(dexp(x,0.6),from=0,to=10, col="blue")
curve(dexp(x,0.3),from=0,to=10, add=T)
#Cau b:
curve(dexp(x,0.3),from=0,to=10,col="red",add=T)
#Cau c:
x=0:10
k=uniroot(function(x) dexp(x,0.6)-dexp(x,0.3),lower = 0, upper = 10)$root
s = pexp(10,0.6)-pexp(k,0.6)+pexp(k,0.3)
s