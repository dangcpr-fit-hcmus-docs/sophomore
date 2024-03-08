﻿----QLDT----
use QLDT
go
--Q59
--EXCEPT
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV.MAGV
	FROM GIAOVIEN GV
	WHERE GV.MABM = 'HTTT'
	EXCEPT (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE DT.MADT = TGDT.MADT
	)
)
--NOT EXISTS
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV.MAGV
	FROM GIAOVIEN GV
	WHERE GV.MABM = 'HTTT'
	AND NOT EXISTS (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE DT.MADT = TGDT.MADT AND GV.MAGV = GV2.MAGV
	)
)
--COUNT
SELECT DT.TENDT
FROM DETAI DT
JOIN THAMGIADT TGDT ON DT.MADT = TGDT.MADT
JOIN GIAOVIEN GV ON TGDT.MAGV = GV.MAGV
WHERE GV.MABM = 'HTTT'
GROUP BY DT.MADT, DT.TENDT
HAVING COUNT(DISTINCT GV.MAGV) = (
	SELECT COUNT(*)
	FROM GIAOVIEN GV2
	WHERE GV2.MABM = 'HTTT'
)

--Q61
--EXCEPT
SELECT *
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	WHERE DT1.MACD = 'QLGD'
	EXCEPT (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE TGDT.MAGV = GV.MAGV
	)
)
--NOT EXISTS
SELECT *
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	WHERE DT1.MACD = 'QLGD'
	AND NOT EXISTS (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE TGDT.MAGV = GV.MAGV AND DT1.MADT = DT2.MADT
	)
)
--COUNT
SELECT GV.MAGV, GV.HOTEN, GV.LUONG, GV.PHAI, GV.NGSINH, GV.DIACHI, GV.GVQLCM, GV.MABM
FROM GIAOVIEN GV
JOIN THAMGIADT TGDT ON GV.MAGV = TGDT.MAGV
JOIN DETAI DT ON DT.MADT = TGDT.MADT
WHERE DT.MACD = 'QLGD'
GROUP BY GV.MAGV, GV.HOTEN, GV.LUONG, GV.PHAI, GV.NGSINH, GV.DIACHI, GV.GVQLCM, GV.MABM
HAVING COUNT(DISTINCT DT.MADT) = (
	SELECT COUNT(*)
	FROM DETAI
	WHERE MACD = 'QLGD'
)

--Q63
--EXCEPT
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV.MAGV
	FROM GIAOVIEN GV
	JOIN BOMON BM ON GV.MABM = BM.MABM
	WHERE BM.TENBM = N'Hóa hữu cơ'
	EXCEPT (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE DT.MADT = TGDT.MADT
	)
)
--NOT EXISTS
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV.MAGV
	FROM GIAOVIEN GV
	JOIN BOMON BM ON GV.MABM = BM.MABM
	WHERE BM.TENBM = N'Hóa hữu cơ'
	AND NOT EXISTS (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE DT.MADT = TGDT.MADT AND GV.MAGV = GV2.MAGV
	)
)
--COUNT
SELECT DT.TENDT
FROM DETAI DT
JOIN THAMGIADT TGDT ON DT.MADT = TGDT.MADT
JOIN GIAOVIEN GV ON TGDT.MAGV = GV.MAGV
JOIN BOMON BM ON GV.MABM = BM.MABM
WHERE BM.TENBM = N'Hóa hữu cơ'
GROUP BY DT.MADT, DT.TENDT
HAVING COUNT(DISTINCT GV.MAGV) = (
	SELECT COUNT(*)
	FROM GIAOVIEN GV2
	JOIN BOMON BM2 ON GV2.MABM = BM2.MABM
	WHERE BM2.TENBM = N'Hóa hữu cơ'
)

--Q65
--EXCEPT
SELECT *
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	JOIN CHUDE CD1 ON DT1.MACD = CD1.MACD
	WHERE CD1.TENCD = N'Ứng dụng công nghệ'
	EXCEPT (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE TGDT.MAGV = GV.MAGV
	)
)
--NOT EXISTS
SELECT *
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	JOIN CHUDE CD1 ON DT1.MACD = CD1.MACD
	WHERE CD1.TENCD = N'Ứng dụng công nghệ'
	AND NOT EXISTS (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE TGDT.MAGV = GV.MAGV AND DT1.MADT = DT2.MADT
	)
)
--COUNT
SELECT GV.MAGV, GV.HOTEN, GV.LUONG, GV.PHAI, GV.NGSINH, GV.DIACHI, GV.GVQLCM, GV.MABM
FROM GIAOVIEN GV
JOIN THAMGIADT TGDT ON GV.MAGV = TGDT.MAGV
JOIN DETAI DT ON DT.MADT = TGDT.MADT
JOIN CHUDE CD ON DT.MACD = CD.MACD
WHERE CD.TENCD = N'Ứng dụng công nghệ'
GROUP BY GV.MAGV, GV.HOTEN, GV.LUONG, GV.PHAI, GV.NGSINH, GV.DIACHI, GV.GVQLCM, GV.MABM
HAVING COUNT(DISTINCT DT.MADT) = (
	SELECT COUNT(*)
	FROM DETAI DT2
	JOIN CHUDE CD2 ON DT2.MACD = CD2.MACD
	WHERE CD2.TENCD = N'Ứng dụng công nghệ'
)

--Q67
--EXCEPT
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV1.MAGV
	FROM GIAOVIEN GV1
	JOIN BOMON BM1 ON GV1.MABM = BM1.MABM
	WHERE BM1.MAKHOA = 'CNTT'
	EXCEPT (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE TGDT.MADT = DT.MADT
	)
)
--NOT EXISTS
SELECT DT.TENDT
FROM DETAI DT
WHERE NOT EXISTS (
	SELECT GV1.MAGV
	FROM GIAOVIEN GV1
	JOIN BOMON BM1 ON GV1.MABM = BM1.MABM
	WHERE BM1.MAKHOA = 'CNTT'
	AND NOT EXISTS (
		SELECT GV2.MAGV
		FROM GIAOVIEN GV2
		JOIN THAMGIADT TGDT ON GV2.MAGV = TGDT.MAGV
		WHERE TGDT.MADT = DT.MADT AND GV1.MAGV = GV2.MAGV
	)
)
--COUNT
SELECT DT.TENDT
FROM DETAI DT
JOIN THAMGIADT TGDT ON DT.MADT = TGDT.MADT
JOIN GIAOVIEN GV ON TGDT.MAGV = GV.MAGV
JOIN BOMON BM ON GV.MABM = BM.MABM
WHERE BM.MAKHOA = 'CNTT'
GROUP BY DT.MADT, DT.TENDT
HAVING COUNT(DISTINCT GV.MAGV) = (
	SELECT COUNT(*)
	FROM GIAOVIEN GV2
	JOIN BOMON BM2 ON GV2.MABM = BM2.MABM
	WHERE BM2.MAKHOA = 'CNTT'
)

--Q69
--EXCEPT
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	WHERE DT1.KINHPHI > 100
	EXCEPT (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE GV.MAGV = TGDT.MAGV
	)
)
--NOT EXISTS
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT DT1.MADT
	FROM DETAI DT1
	WHERE DT1.KINHPHI > 100
	AND NOT EXISTS (
		SELECT DT2.MADT
		FROM DETAI DT2
		JOIN THAMGIADT TGDT ON DT2.MADT = TGDT.MADT
		WHERE GV.MAGV = TGDT.MAGV AND DT1.MADT = DT2.MADT
	)
)
--COUNT
SELECT GV.HOTEN
FROM GIAOVIEN GV
JOIN THAMGIADT TGDT ON GV.MAGV = TGDT.MAGV
JOIN DETAI DT ON TGDT.MADT = DT.MADT
WHERE DT.KINHPHI > 100
GROUP BY GV.MAGV, GV.HOTEN
HAVING COUNT(DISTINCT DT.MADT) = (
	SELECT COUNT(*)
	FROM DETAI DT2
	WHERE DT2.KINHPHI > 100
)

--Q71
--EXCEPT
SELECT GV.MAGV, GV.HOTEN, GV.NGSINH
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT CV.MADT, CV.SOTT
	FROM CONGVIEC CV
	JOIN DETAI DT ON CV.MADT = DT.MADT
	WHERE DT.TENDT = N'Ứng dụng hóa học xanh'
	EXCEPT (
		SELECT TGDT.MADT, TGDT.STT
		FROM THAMGIADT TGDT
		WHERE GV.MAGV = TGDT.MADT
	)
)
--NOT EXISTS
SELECT GV.MAGV, GV.HOTEN, GV.NGSINH
FROM GIAOVIEN GV
WHERE NOT EXISTS (
	SELECT CV.MADT, CV.SOTT
	FROM CONGVIEC CV
	JOIN DETAI DT ON CV.MADT = DT.MADT
	WHERE DT.TENDT = N'Ứng dụng hóa học xanh'
	AND NOT EXISTS (
		SELECT TGDT.MADT, TGDT.STT
		FROM THAMGIADT TGDT
		WHERE GV.MAGV = TGDT.MADT AND TGDT.MADT = CV.MADT AND TGDT.STT = CV.SOTT
	)
)
--COUNT
SELECT GV.MAGV, GV.HOTEN, GV.NGSINH
FROM GIAOVIEN GV
JOIN THAMGIADT TGDT ON GV.MAGV = TGDT.MADT
JOIN CONGVIEC CV ON TGDT.MADT = CV.MADT AND TGDT.STT = CV.SOTT
JOIN DETAI DT ON TGDT.MADT = DT.MADT
WHERE DT.TENDT = N'Ứng dụng hóa học xanh'
GROUP BY GV.MAGV, GV.HOTEN, GV.NGSINH
HAVING COUNT(CV.SOTT) = (
	SELECT COUNT(*)
	FROM DETAI DT2
	JOIN CONGVIEC CV2 ON DT2.MADT = CV2.MADT
	WHERE DT2.TENDT = N'Ứng dụng hóa học xanh'
)


----QLCB----
use QLCB
go
--Q51
--EXCEPT
SELECT DISTINCT LB.MACB
FROM LICHBAY LB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	EXCEPT (
		SELECT LMB2.MALOAI
		FROM LOAIMB LMB2
		JOIN MAYBAY MB2 ON LMB2.MALOAI = MB2.MALOAI
		JOIN LICHBAY LB2 ON MB2.SOHIEU = LB2.SOHIEU AND MB2.MALOAI = LB2.MALOAI
		WHERE LB.MACB = LB2.MACB
	)
)
--NOT EXISTS
SELECT DISTINCT LB.MACB
FROM LICHBAY LB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	AND NOT EXISTS (
		SELECT LMB2.MALOAI
		FROM LOAIMB LMB2
		JOIN MAYBAY MB2 ON LMB2.MALOAI = MB2.MALOAI
		JOIN LICHBAY LB2 ON MB2.SOHIEU = LB2.SOHIEU AND MB2.MALOAI = LB2.MALOAI
		WHERE LB.MACB = LB2.MACB AND LMB2.MALOAI = LMB.MALOAI
	)
)
--COUNT
SELECT LB.MACB
FROM LICHBAY LB
JOIN MAYBAY MB ON LB.SOHIEU = MB.SOHIEU AND LB.MALOAI = MB.MALOAI
JOIN LOAIMB LMB ON LMB.MALOAI = MB.MALOAI
WHERE LMB.HANGSX = 'Boeing'
GROUP BY LB.MACB
HAVING COUNT(DISTINCT LMB.MALOAI) = (
	SELECT COUNT(*)
	FROM LOAIMB LMB2
	WHERE LMB2.HANGSX = 'Boeing'
)

--Q52
--EXCEPT
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Airbus'
	EXCEPT (
		SELECT KN.MALOAI
		FROM KHANANG KN
		WHERE NV.MANV = KN.MANV
	)
)
--NOT EXISTS
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Airbus'
	AND NOT EXISTS (
		SELECT KN.MALOAI
		FROM KHANANG KN
		WHERE NV.MANV = KN.MANV AND LMB.MALOAI = KN.MALOAI
	)
)
--COUNT
SELECT NV.TEN
FROM NHANVIEN NV
JOIN KHANANG KN ON NV.MANV = KN.MANV
JOIN LOAIMB LMB ON KN.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Airbus'
GROUP BY NV.TEN, NV.MANV
HAVING COUNT(KN.MALOAI) = (
	SELECT COUNT(*)
	FROM LOAIMB LMB2
	WHERE LMB2.HANGSX = 'Airbus'
)

--Q53
--EXCEPT
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 0
AND NOT EXISTS (
	SELECT LB.MACB, LB.NGAYDI
	FROM LICHBAY LB
	WHERE LB.MACB = 100
	EXCEPT (
		SELECT PC.MACB, PC.NGAYDI
		FROM PHANCONG PC 
		WHERE PC.MANV = NV.MANV
	)
)
--NOT EXISTS
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 0
AND NOT EXISTS (
	SELECT LB.MACB, LB.NGAYDI
	FROM LICHBAY LB
	WHERE LB.MACB = 100
	AND NOT EXISTS (
		SELECT PC.MACB, PC.NGAYDI
		FROM PHANCONG PC 
		WHERE PC.MANV = NV.MANV AND PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI
	)
)
--COUNT
SELECT NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON NV.MANV = PC.MANV
WHERE PC.MACB = 100
GROUP BY NV.MANV, NV.TEN
HAVING COUNT(PC.NGAYDI) = (
	SELECT COUNT(*)
	FROM LICHBAY LB
	WHERE LB.MACB = 100
)

--Q54
--EXCEPT
SELECT DISTINCT LB.NGAYDI
FROM LICHBAY LB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	EXCEPT (
		SELECT LB2.MALOAI
		FROM LICHBAY LB2
		WHERE LB2.NGAYDI = LB.NGAYDI
	)
)
--NOT EXISTS
SELECT DISTINCT LB.NGAYDI
FROM LICHBAY LB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	AND NOT EXISTS (
		SELECT LB2.MALOAI
		FROM LICHBAY LB2
		WHERE LB2.NGAYDI = LB.NGAYDI AND LMB.MALOAI = LB2.MALOAI
	)
)
--COUNT
SELECT LB.NGAYDI
FROM LICHBAY LB
JOIN LOAIMB LMB ON LB.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Boeing'
GROUP BY LB.NGAYDI
HAVING COUNT(DISTINCT LMB.MALOAI) = (
	SELECT COUNT(*)
	FROM LOAIMB LMB2
	WHERE LMB2.HANGSX = 'Boeing'
)

--Q55
--EXCEPT
SELECT LMB.MALOAI
FROM LOAIMB LMB
WHERE LMB.HANGSX = 'Boeing'
AND NOT EXISTS (
	SELECT LB.NGAYDI
	FROM LICHBAY LB
	EXCEPT (
		SELECT LB2.NGAYDI
		FROM LICHBAY LB2
		WHERE LB2.MALOAI = LMB.MALOAI
	)
)
--NOT EXISTS
SELECT LMB.MALOAI
FROM LOAIMB LMB
WHERE LMB.HANGSX = 'Boeing'
AND NOT EXISTS (
	SELECT LB.NGAYDI
	FROM LICHBAY LB
	WHERE NOT EXISTS (
		SELECT LB2.NGAYDI
		FROM LICHBAY LB2
		WHERE LB2.MALOAI = LMB.MALOAI AND LB.NGAYDI = LB2.NGAYDI
	)
)
--COUNT
SELECT LMB.MALOAI
FROM LICHBAY LB
JOIN LOAIMB LMB ON LB.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Boeing'
GROUP BY LMB.MALOAI
HAVING COUNT(DISTINCT LB.NGAYDI) = (
	SELECT COUNT(DISTINCT LB2.NGAYDI)
	FROM LICHBAY LB2
)

--Q56
--EXCEPT
SELECT KH.MAKH, KH.TEN
FROM KHACHHANG KH
WHERE NOT EXISTS (
	SELECT DISTINCT DC.NGAYDI
	FROM DATCHO DC
	WHERE DC.NGAYDI >= '01/31/2000' AND DC.NGAYDI <= '11/01/2000'
	EXCEPT (
		SELECT DC2.NGAYDI
		FROM DATCHO DC2
		WHERE DC2.MAKH = KH.MAKH
	)
)
--NOT EXISTS
SELECT KH.MAKH, KH.TEN
FROM KHACHHANG KH
WHERE NOT EXISTS (
	SELECT DISTINCT DC.NGAYDI
	FROM DATCHO DC
	WHERE DC.NGAYDI >= '01/31/2000' AND DC.NGAYDI <= '11/01/2000'
	AND NOT EXISTS (
		SELECT DC2.NGAYDI
		FROM DATCHO DC2
		WHERE DC2.MAKH = KH.MAKH AND DC.NGAYDI = DC2.NGAYDI
	)
)
--COUNT
SELECT KH.MAKH, KH.TEN
FROM KHACHHANG KH
JOIN DATCHO DC ON KH.MAKH = DC.MAKH
WHERE DC.NGAYDI >= '01/31/2000' AND DC.NGAYDI <= '11/01/2000'
GROUP BY KH.MAKH, KH.TEN
HAVING COUNT(DISTINCT DC.NGAYDI) = (
	SELECT COUNT(DISTINCT DC2.NGAYDI)
	FROM DATCHO DC2
	WHERE DC2.NGAYDI >= '01/31/2000' AND DC2.NGAYDI <= '11/01/2000'
)

--Q57
--EXCEPT
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 1
EXCEPT
SELECT NV1.TEN
FROM NHANVIEN NV1
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Airbus'
	EXCEPT (
		SELECT KN.MALOAI
		FROM KHANANG KN
		WHERE NV1.MANV = KN.MANV
	)
)
--NOT EXISTS
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 1
AND NOT EXISTS (
	SELECT NV1.TEN
	FROM NHANVIEN NV1
	WHERE NOT EXISTS (
		SELECT LMB.MALOAI
		FROM LOAIMB LMB
		WHERE LMB.HANGSX = 'Airbus'
		AND NOT EXISTS (
			SELECT KN.MALOAI
			FROM KHANANG KN
			WHERE NV1.MANV = KN.MANV AND LMB.MALOAI = KN.MALOAI
		)
	)
	AND NV.MANV = NV1.MANV
)
--COUNT
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 1
EXCEPT
SELECT NV1.TEN
FROM NHANVIEN NV1
JOIN KHANANG KN ON NV1.MANV = KN.MANV
JOIN LOAIMB LMB ON KN.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Airbus'
GROUP BY NV1.TEN, NV1.MANV
HAVING COUNT(KN.MALOAI) = (
	SELECT COUNT(*)
	FROM LOAIMB LMB2
	WHERE LMB2.HANGSX = 'Airbus'
)

--Q58
--EXCEPT
SELECT DISTINCT CB.SBDI
FROM CHUYENBAY CB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	EXCEPT (
		SELECT LB2.MALOAI
		FROM CHUYENBAY CB2
		JOIN LICHBAY LB2 ON CB2.MACB = LB2.MACB
		JOIN LOAIMB LMB2 ON LB2.MALOAI = LMB2.MALOAI
		WHERE CB.SBDI = CB2.SBDI
	)
)
--NOT EXISTS
SELECT DISTINCT CB.SBDI
FROM CHUYENBAY CB
WHERE NOT EXISTS (
	SELECT LMB.MALOAI
	FROM LOAIMB LMB
	WHERE LMB.HANGSX = 'Boeing'
	AND NOT EXISTS (
		SELECT LB2.MALOAI
		FROM CHUYENBAY CB2
		JOIN LICHBAY LB2 ON CB2.MACB = LB2.MACB
		JOIN LOAIMB LMB2 ON LB2.MALOAI = LMB2.MALOAI
		WHERE CB.SBDI = CB2.SBDI AND LMB.MALOAI = LB2.MALOAI
	)
)
--COUNT
SELECT CB.SBDI
FROM CHUYENBAY CB
JOIN LICHBAY LB ON CB.MACB = LB.MACB
JOIN LOAIMB LMB ON LB.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Boeing'
GROUP BY CB.SBDI
HAVING COUNT(DISTINCT LB.MALOAI) = (
	SELECT COUNT(*)
	FROM LOAIMB LMB2
	WHERE LMB2.HANGSX = 'Boeing'
)