﻿--------QLDT--------
use QLDT
go

--Q36
SELECT *
FROM GIAOVIEN GV
WHERE GV.LUONG >= ALL(
	SELECT GV.LUONG
	FROM GIAOVIEN GV)

--Q38
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.NGSINH <= ALL (
	SELECT GV2.NGSINH
	FROM GIAOVIEN GV2
	WHERE GV2.MABM = 'HTTT')
AND GV.MABM = 'HTTT'

--Q40
SELECT GV.HOTEN, BM.MAKHOA
FROM GIAOVIEN GV 
join BOMON BM on GV.MABM = BM.MABM
WHERE GV.LUONG >= ALL (
	SELECT GV.LUONG
	FROM GIAOVIEN GV)

--Q42
SELECT DT.TENDT
FROM DETAI DT 
WHERE DT.MADT NOT IN (
	SELECT DISTINCT TGDT.MADT
	FROM GIAOVIEN GV1
	join THAMGIADT TGDT on GV1.MAGV = TGDT.MAGV
	WHERE GV1.HOTEN = N'Nguyễn Hoài An')

--Q44: Cho biết tên những giáo viên 
--khoa Công nghệ thông tin mà chưa tham gia đề tài nào.
SELECT GV.HOTEN
FROM GIAOVIEN GV
join BOMON BM on GV.MABM = BM.MABM
join KHOA K on BM.MAKHOA = K.MAKHOA AND K.TENKHOA = N'Công nghệ thông tin'
WHERE GV.MAGV NOT IN (
	SELECT TGDT.MAGV
	FROM THAMGIADT TGDT)

--Q46
SELECT *
FROM GIAOVIEN GV
WHERE GV.LUONG > ALL(
	SELECT GIAOVIEN.LUONG
	FROM GIAOVIEN
	WHERE GIAOVIEN.HOTEN = N'Nguyễn Hoài An')

--Q48
SELECT *
FROM GIAOVIEN GV
WHERE EXISTS (
	SELECT GV2.MAGV
	FROM GIAOVIEN GV2
	WHERE GV.HOTEN = GV2.HOTEN
	AND GV.PHAI = GV2.PHAI
	AND GV.MAGV <> GV2.MAGV)

--Q50
SELECT GV.HOTEN
FROM GIAOVIEN GV join BOMON BM on GV.MABM = BM.MABM
WHERE GV.LUONG > ALL (
	SELECT GV.LUONG
	FROM GIAOVIEN GV 
	join BOMON BM on GV.MABM = BM.MABM
	WHERE BM.TENBM = N'Hệ thống thông tin')

--Q52
SELECT GV.HOTEN
FROM DETAI DT 
join GIAOVIEN GV on DT.GVCNDT = GV.MAGV
GROUP BY DT.GVCNDT, GV.HOTEN
HAVING COUNT(*) >= ALL (
	SELECT COUNT(*)
	FROM DETAI DT 
	GROUP BY DT.GVCNDT)

--Q54
SELECT GV.HOTEN, BM.TENBM
FROM THAMGIADT TGDT 
join GIAOVIEN GV on TGDT.MAGV = GV.MAGV
join BOMON BM on GV.MABM = BM.MABM
GROUP BY TGDT.MAGV, GV.HOTEN, BM.TENBM
HAVING COUNT(DISTINCT TGDT.MADT) >= ALL(
	SELECT COUNT(DISTINCT TGDT.MADT)
	FROM THAMGIADT TGDT 
	GROUP BY TGDT.MAGV)

--Q56
SELECT GV.HOTEN, BM.TENBM
FROM NGUOITHAN NT
join GIAOVIEN GV on NT.MAGV = GV.MAGV
join BOMON BM on GV.MABM = BM.MABM
GROUP BY NT.MAGV, GV.HOTEN, BM.TENBM
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM NGUOITHAN NT
	GROUP BY NT.MAGV)

--------QLCB--------
use QLCB
go

--Q34
SELECT LMB.HANGSX, LB.SOHIEU, LB.MALOAI
FROM LOAIMB LMB 
join LICHBAY LB on LMB.MALOAI = LB.MALOAI
GROUP BY LMB.HANGSX, LB.SOHIEU, LB.MALOAI
HAVING COUNT(*) >= ALL (
	SELECT COUNT(*)
	FROM LOAIMB LMB 
	join LICHBAY LB on LMB.MALOAI = LB.MALOAI
	GROUP BY LMB.HANGSX, LB.SOHIEU, LB.MALOAI)

--Q35
SELECT NV.TEN
FROM PHANCONG PC 
join NHANVIEN NV on PC.MANV = NV.MANV 
GROUP BY PC.MANV, NV.TEN
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM PHANCONG PC 
	GROUP BY PC.MANV)

--Q36
SELECT NV.TEN, NV.DCHI, NV.DTHOAI
FROM PHANCONG PC 
join NHANVIEN NV on PC.MANV = NV.MANV 
WHERE NV.LOAINV = 1
GROUP BY PC.MANV, NV.TEN, NV.DCHI, NV.DTHOAI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM PHANCONG PC 
	join NHANVIEN NV on PC.MANV = NV.MANV 
	WHERE NV.LOAINV = 1
	GROUP BY PC.MANV)

--Q37
SELECT CB.SBDEN, COUNT(*) AS SOLUONG
FROM CHUYENBAY CB
GROUP BY CB.SBDEN
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM CHUYENBAY CB
	GROUP BY CB.SBDEN)

--Q38
SELECT CB.SBDI, COUNT(*) AS SOLUONG
FROM CHUYENBAY CB
GROUP BY CB.SBDI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM CHUYENBAY CB
	GROUP BY CB.SBDI)

--Q39
SELECT DC.MAKH, KH.DCHI, KH.DTHOAI
FROM DATCHO DC 
join KHACHHANG KH on DC.MAKH = KH.MAKH
GROUP BY DC.MAKH, KH.DCHI, KH.DTHOAI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM DATCHO DC 
	GROUP BY DC.MAKH)

--Q40
SELECT KN.MANV, NV.TEN, NV.LUONG
FROM KHANANG KN
join NHANVIEN NV on KN.MANV = NV.MANV
GROUP BY KN.MANV, NV.TEN, NV.LUONG
HAVING COUNT(*) >= ALL (
	SELECT COUNT(*)
	FROM KHANANG KN
	GROUP BY KN.MANV)

--Q41
SELECT NV.MANV, NV.TEN, NV.LUONG
FROM NHANVIEN NV
WHERE NV.LUONG >= ALL (
	SELECT NV.LUONG
	FROM NHANVIEN NV)

--Q42
SELECT PC1.MANV,PC1.NGAYDI,PC1.MACB, NV.TEN AS TENMAX, MAX(NV.LUONG) AS LUONGMAX
FROM PHANCONG PC1 
join PHANCONG PC2 on PC1.NGAYDI = PC2.NGAYDI AND PC1.MACB = PC2.MACB 
join NHANVIEN NV on PC2.MANV = NV.MANV
--ORDER BY PC1.MANV ASC, PC1.NGAYDI ASC
GROUP BY PC1.MANV, PC1.NGAYDI,PC1.MACB,NV.TEN, NV.LUONG, PC1.NGAYDI, PC1.MACB
HAVING MAX(NV.LUONG) >= ALL(
	SELECT NV.LUONG
	FROM PHANCONG PC3 
	join PHANCONG PC4 on PC4.NGAYDI = PC4.NGAYDI AND PC3.MACB = PC4.MACB 
	join NHANVIEN NV on PC4.MANV = NV.MANV
	WHERE PC3.MANV = PC1.MANV)

--Q43
SELECT CB.MACB, CB.GIODI, CB.GIODEN
FROM CHUYENBAY CB
WHERE CB.GIODI <= ALL (
	SELECT CB.GIODI
	FROM CHUYENBAY CB)

--Q44
SELECT CB.MACB, datediff(MINUTE, CB.GIODI, CB.GIODEN) AS THOIGIANBAY
FROM CHUYENBAY CB
WHERE datediff(MINUTE, CB.GIODI, CB.GIODEN) >= ALL (
	SELECT datediff(MINUTE, CB.GIODI, CB.GIODEN)
	FROM CHUYENBAY CB)

--Q45
SELECT CB.MACB, datediff(MINUTE, CB.GIODI, CB.GIODEN) AS THOIGIANBAY
FROM CHUYENBAY CB
WHERE datediff(MINUTE, CB.GIODI, CB.GIODEN) <= ALL (
	SELECT datediff(MINUTE, CB.GIODI, CB.GIODEN)
	FROM CHUYENBAY CB)

--Q46
SELECT LB.MACB, LB.NGAYDI
FROM LICHBAY LB
WHERE LB.MACB = (
	SELECT LB.MACB
	FROM LICHBAY LB
	WHERE LB.MALOAI = 'B747'
	GROUP BY LB.MACB
	HAVING COUNT(*) >= ALL (SELECT COUNT(*)
		FROM LICHBAY LB
		WHERE LB.MALOAI = 'B747'
		GROUP BY LB.MACB)
	)

--Q47
SELECT PC.MACB, COUNT(*)
FROM PHANCONG PC
GROUP BY PC.MACB
HAVING PC.MACB IN (
	SELECT DC.MACB
	FROM DATCHO DC
	GROUP BY DC.MACB
	HAVING COUNT(DISTINCT DC.MAKH) > 3)

--Q48
SELECT NV.LOAINV, COUNT(*)
FROM NHANVIEN NV
GROUP BY NV.LOAINV
HAVING NV.LOAINV IN (
	SELECT NV.LOAINV
	FROM NHANVIEN NV
	GROUP BY NV.LOAINV
	HAVING SUM(NV.LUONG) > 600000)

--Q49
SELECT DC.MACB, COUNT(*)
FROM DATCHO DC
GROUP BY DC.MACB
HAVING DC.MACB IN (
	SELECT PC.MACB
	FROM PHANCONG PC
	GROUP BY PC.MACB
	HAVING COUNT(DISTINCT PC.MANV) > 3)

--Q50
SELECT LB.MALOAI, COUNT(*)
FROM LICHBAY LB
GROUP BY LB.MALOAI
HAVING LB.MALOAI IN (
	SELECT MB.MALOAI
	FROM MAYBAY MB
	GROUP BY MB.MALOAI
	HAVING COUNT(*) > 1)