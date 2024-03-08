# Bai tap thuc hanh so 3



# Bai 1:
# a/
setwd("D:/R/KT3")
data <- read.csv("Profit.csv", header = T)
attach(data);names(data)

x <- Dist.1;x
y <- Dist.3;y

alpha = 0.05

cat('KTC',100*(1-alpha),'% cho su sai khac ve doanh so ban hang trung binh cua 2 chi nhanh\n')
t.test(x,y)$conf.int

# b/

n1 = length(x)
n2 = length(y)

y1 = length(x[x>600])
y2 = length(y[y>600])

y = c(y1,y2)
n = c(n1,n2)

alpha = 0.05

p_value = prop.test(y,n,alternative = "less")$p.value
p_value

if(p_value < alpha)
	cat('Du co so bac bo H0 voi p-value =',p_value,'\n')
if(p_value > alpha)
	cat('Khong du co so bac bo H0 voi p-value =',p_value,'\n')


# c/
prop.test.leq <-function(x,y,alpha){
	n1 = length(x)
	n2 = length(y)
	y1 = length(x[x>600]); cat(y1)
	y2 = length(y[y>600]); cat(y2)

	p1 = y1/n1
	p2 = y2/n2
	
	p = (y1+y2)/(n1+n2)
	
	z_0 = (p1-p2)/sqrt(p*(1-p)*(1/n1 + 1/n2))

	p_value = qnorm(z_0)

	if (p_value < alpha)
		cat('Du co so bac bo H0 voi p-value=',p_value,'\n')
	else
		cat('Khong du co so bac bo H0 voi p-value=',p_value,'\n')
}

prop.test.leq(x,y,0.05)

# Bai 2:
# a/
height = c(600,1000,1250,1600,1800,2100,2500,2900)
temperature = c(56,54,56,50,47,49,47,45)

plot(height,temperature)

abline(lm(temperature~height))

# b/
lm(temperature~height)

# Dat nhiet do la bien t, do cao la bien h
# Dua vao ham hoi quy ta co cong thuc: t = 59.290662 - 0.005115*h
# Suy ra khi len cao them 1 ft thi nhiet do giam 0.005115 do F
# Theo kinh nghiem thi khi len cao them 1 km thi nhiet do giam 9.8 do C 
# tuong duong khi len cao them 1 ft thi nhiet do giam 0.01513 do F
# Vay kinh nghiem cua de bai khong dung khi 0.005115 < 0.01513



rm(list = ls())
ls()