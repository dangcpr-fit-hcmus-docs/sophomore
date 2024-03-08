#LT Bai 9 - Bai 4

#a.
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

#b.
test.leq.oneside <- function(x,y,mu0,alpha) {
  D = x-y
  n = length(D)
  D.bar = mean(D)
  D.sd = sd(D)
  t0 = (D.bar-mu0)*sqrt(n)/D.sd
  p.value = pt(t0,n-1)
  cat("Voi muc y nghia ",100*alpha, "% \n")
  if(p.value < alpha)
    cat("Bac bo H0 voi p-gia tri=", p.value, "\n")
  else
    cat("Chua du co so de bac bo H0 voi p-gia tri=",p.value,"\n")
}
x = Before; y = After
#Ap dung mu0=0
test.leq.oneside(x,y,mu0=0,alpha=0.05)

#Kiem tra lai bang t.test
t.test(x,y,alternative = "less",var.equal = v.equal, conf.level = 0.95, paired = TRUE)

#KIEM DINH TI LE
#Bai 7
y = c(15,8)
n = c(300,300)
prop.test(y,n,alternative = "two.sided", conf.level = 0.975)
#p-value = 0.202 > 0.025 = alpha
#=> Chua du co so bac bo H0

#HOI QUY TUYEN TINH

#Vi du 1
x <- c(18,23,25,35,65,54,34,56,72,19,23,42,18,39,37)
y <- c(202,186,187,180,156,169,174,172,153,199,193,174,198,183,178)
plot(x,y)
abline(lm(y~x))
result = lm(y~x)
summary(result)
#Thang du
coef(result) #Hoac result[['coefficients']]
res = resid(result) #Hoac result[['residual']]
summary(res)
