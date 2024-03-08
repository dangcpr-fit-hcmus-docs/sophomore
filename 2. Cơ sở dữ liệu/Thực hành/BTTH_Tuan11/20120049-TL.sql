use QLDT
go

--Cau j: in danh sach gv
CREATE PROCEDURE DSGV
AS
	BEGIN
		SELECT *
		FROM dbo.GIAOVIEN
	END;
go
EXEC DSGV;
go

--Cau k: tinh so luong de tai
CREATE PROCEDURE SLDeTai (
	@MAGV char(5)
)
AS
	BEGIN
		SELECT GV.MAGV, GV.HOTEN, COUNT(DISTINCT TGDT.MADT) AS SLDT
		FROM dbo.THAMGIADT TGDT
		JOIN dbo.GIAOVIEN GV ON TGDT.MAGV = GV.MAGV
		WHERE GV.MAGV = @MAGV
		GROUP BY GV.MAGV, GV.HOTEN
	END;
go
EXEC SLDeTai '002';
go

--Cau l: In thong tin giao vien, lenh print
CREATE PROC PrintInfo (
	@MAGV char(5)
)
AS
BEGIN
	print N'MaGV:' + @MAGV
	DECLARE @TENGV nvarchar(40)
	SELECT @TENGV = GV.HOTEN FROM GIAOVIEN GV WHERE GV.MAGV = @MAGV
	print N'TenGV: '+ @TENGV
	DECLARE @SLDT int
	BEGIN
		SELECT @SLDT = COUNT(DISTINCT TGDT.MADT)
		FROM dbo.THAMGIADT TGDT
		JOIN dbo.GIAOVIEN GV ON TGDT.MAGV = GV.MAGV
		WHERE GV.MAGV = @MAGV
		GROUP BY GV.MAGV, GV.HOTEN
	END
	print N'SoLuongDeTai: ' + @SLDT
	DECLARE @SLNT char
	BEGIN
		SELECT @SLNT = COUNT(DISTINCT NT.TEN)
		FROM dbo.NGUOITHAN NT
		JOIN dbo.GIAOVIEN GV ON NT.MAGV = GV.MAGV
		WHERE GV.MAGV = @MAGV
		GROUP BY GV.MAGV, GV.HOTEN
	END
		print N'SoLuongNguoiThan: ' + @SLNT
END;
go
EXEC PrintInfo '003'
go

--Cau m: Kiem tra giao vien ton tai
CREATE PROC ExistGV(
	@MAGV char(5)
)
AS
BEGIN
	IF (@MAGV IN (SELECT MAGV FROM GIAOVIEN))
		print N'Tồn tại'
	ELSE
		print N'Không tồn tại'
END;
go
EXEC ExistGV '024'
GO

--Cau n: Kiem tra quy dinh
CREATE PROC CheckGV (
	@MAGV char(5)
)
AS
BEGIN
	DECLARE @BMGV char(5)
	SET @BMGV = (
		SELECT BM.MABM 
		FROM BOMON BM 
		JOIN GIAOVIEN GV ON GV.MABM = BM.MABM
		WHERE GV.MAGV = @MAGV
	)
	IF(NOT EXISTS (
			SELECT *
			FROM THAMGIADT TGDT
			JOIN DETAI DT ON TGDT.MADT = DT.MADT
			JOIN GIAOVIEN GV ON DT.GVCNDT = GV.MAGV
			JOIN BOMON BM ON GV.MABM = BM.MABM
			WHERE TGDT.MAGV = @MAGV AND BM.MABM <> @BMGV))
		BEGIN 
			print N'Hợp lệ'
			return 1
		END
	ELSE
		BEGIN
			print N'Không hợp lệ'
			return 0
		END
END;
go
EXEC CheckGV '006'
go

--Cau o: Phan cong cho giao vien
CREATE PROC PhanCong (
	@MAGV char(5),
	@MADT char(3),
	@STT char(1),
	@BD date,
	@KT date
)
AS
BEGIN
	DECLARE @CheckGV int
	IF (@MAGV IN (SELECT MAGV FROM GIAOVIEN)
			AND EXISTS (SELECT * FROM CONGVIEC CV WHERE CV.MADT = @MADT AND CV.SOTT = @STT)
			AND datediff (day, @BD, @KT) > 0)
		INSERT INTO THAMGIADT (MAGV, MADT, STT) VALUES (@MAGV, @MADT, @STT)
	ELSE
		print N'Không thêm được'
	EXEC @CheckGV = CheckGV @MAGV
	IF (@CheckGV = 1)
		print N'Thêm hợp lệ'
	ELSE
		BEGIN
			print N'Thêm không hợp lệ'
			DELETE FROM THAMGIADT WHERE MAGV = @MAGV AND MADT = @MADT AND STT = @STT
		END
END
go
EXEC PhanCong '002', '002', '2', '05/10/2019', '07/10/2019'
GO

--Cau p: Xoa giao vien
CREATE PROC DeleteGV(
	@MAGV char(5)
)
AS
BEGIN
	IF (NOT EXISTS (SELECT * FROM THAMGIADT TGDT WHERE TGDT.MAGV = @MAGV)
		AND NOT EXISTS (SELECT * FROM NGUOITHAN NT WHERE NT.MAGV = @MAGV)
		AND NOT EXISTS (SELECT * FROM GV_DT GVDT WHERE GVDT.MAGV = @MAGV)
	)
		DELETE FROM GIAOVIEN WHERE MAGV = @MAGV
	ELSE
		print N'Không xoá được'
END;
go
EXEC DeleteGV '015'
GO

--Cau q: In danh sach giao vien mot phong ban
CREATE PROC PhongBan (
	@MAPB char(5)
)
AS
BEGIN
	SELECT GV.MAGV, GV.HOTEN, COUNT(DISTINCT TGDT.MADT) AS SODETAI, COUNT(DISTINCT NT.TEN) SONGUOITHAN, COUNT(DISTINCT GV2.MAGV) SOGVDQL
	FROM GIAOVIEN GV
	LEFT JOIN BOMON BM ON GV.MABM = BM.MABM
	LEFT JOIN THAMGIADT TGDT ON GV.MAGV = TGDT.MAGV
	LEFT JOIN NGUOITHAN NT ON GV.MAGV = NT.MAGV
	LEFT JOIN DETAI DT ON DT.GVCNDT = GV.MAGV
	LEFT JOIN GIAOVIEN GV2 ON GV.MAGV = GV2.GVQLCM
	WHERE BM.MABM = @MAPB
	GROUP BY GV.MAGV, GV.HOTEN
END
go
EXEC PhongBan 'HTTT'
go

--Cau r: Kiem tra quy dinh 2 giao vien a, b
CREATE PROC CheckAB(
	@GV1 char(5),
	@GV2 char(5)
)
AS
BEGIN
	DECLARE @BM1 char(10) = (SELECT GV.MABM FROM GIAOVIEN GV WHERE GV.MAGV = @GV1)
	DECLARE @BM2 char(10) = (SELECT GV.MABM FROM GIAOVIEN GV WHERE GV.MAGV = @GV2)
	DECLARE @L1 int = (SELECT GV.LUONG FROM GIAOVIEN GV WHERE GV.MAGV = @GV1)
	DECLARE @L2 int = (SELECT GV.LUONG FROM GIAOVIEN GV WHERE GV.MAGV = @GV2)
	DECLARE @TBM char(10) = (SELECT BM.TRUONGBM FROM BOMON BM WHERE BM.MABM = @BM1)
	IF (@BM1 = @BM2 
		AND @TBM = @GV1)
		IF @L1 > @L2
			print N'Hợp lệ'
		ELSE
			print N'Không hợp lệ'
	ELSE
		print N'Hợp lệ'
END
GO
EXEC CheckAB '007', '008'
GO

--Cau s: Them giao vien
CREATE PROC AddGV(
	@MAGV char(5),
	@HoTen nvarchar(40),
	@Luong float,
	@Phai nchar(3),
	@NgSinh datetime,
	@DiaChi nvarchar(100),
	@GVQLCM char(5),
	@MaBM nchar(5)
)
AS
BEGIN
	IF (@MAGV NOT IN (SELECT MAGV FROM GIAOVIEN)
		AND DATEDIFF(year, @NgSinh, getdate()) > 18
		AND @Luong > 0)
	BEGIN 
		INSERT INTO GIAOVIEN VALUES (@MAGV, @HoTen, @Luong, @Phai, @NgSinh, @DiaChi, @GVQLCM, @MaBM)
		return 1
	END
	ELSE
	BEGIN
		print N'Thao tác thêm không hợp lệ'
		return 0
	END
END;
go
EXEC AddGV '015', N'Đặng An Nguyên', 2400, N'Nam', '10/31/2000', N'21A Bến Nghé', '003', 'HPT'
go

--Cau t: Ma giao vien duoc xac dinh tu dong theo quy tinh
CREATE PROC AddMaGVAuto(
 	@HoTen nvarchar(40),
	@Luong float,
	@Phai nchar(3),
	@NgSinh datetime,
	@DiaChi nvarchar(100),
	@GVQLCM char(5),
	@MaBM nchar(5)
)
AS
BEGIN
	DECLARE @Count int = 1
	DECLARE @MaGV char(5)
	WHILE (@count IN (SELECT MAGV FROM GIAOVIEN))
		SET @Count = @Count + 1

	IF (@Count < 10) SET @MaGV = '00' + cast(@Count AS char(3))
	ELSE IF (@Count < 100) SET @MaGV = '0' + cast(@Count AS char(4))
	ELSE SET @MaGV = cast(@Count as char(5))

	EXEC AddGV @MaGV, @HoTen, @Luong, @Phai, @NgSinh, @DiaChi, @GVQLCM, @MaBM
END
go
EXEC AddMaGVAuto N'Trần Thị Thanh Thanh', 1700, N'Nữ', '10/31/2002', N'21A Đồng Khởi', '002', 'HTTT'
go