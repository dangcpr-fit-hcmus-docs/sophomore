use QLTS
go
--Cau phu
ALTER TABLE THISINH
ADD TongDiem float
go

ALTER TABLE THISINH
ADD KetQua nvarchar(20)
go

--Cau 1
SELECT DDT.TenDDT, DDT.DiaChi
FROM DIADIEMTHI DDT
WHERE DDT.DiaChi LIKE '%TP Can Tho%'
AND NOT EXISTS (
	SELECT KM.MaMon
	FROM KHOI_MON KM
	WHERE KM.MaKhoi = 'A'
	EXCEPT
	SELECT BT.MaMon
	FROM DUTHI DT
	JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
	WHERE DDT.MaDDT = DT.DiaDiemThi
)
go
--Cau 2
SELECT BT.MaMon, BT.MaKhoi, TS.SBD, TS.HoTen, DT.Diem
FROM DUTHI DT
JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
JOIN THISINH TS ON DT.SBD = TS.SBD
WHERE DT.Diem >= ALL (
	SELECT DT2.Diem
	FROM DUTHI DT2
	JOIN BUOITHI BT2 ON DT2.MaBT = BT2.MaBT
	JOIN THISINH TS2 ON DT2.SBD = TS2.SBD
	WHERE BT2.MaKhoi = BT.MaKhoi AND BT2.MaMon = BT.MaMon)
go
--Cau 3
CREATE PROC usp_TinhTongDiem 
@sbd char(11), @tongdiem float out
AS
	IF NOT EXISTS (SELECT * FROM THISINH WHERE SBD = @sbd)
	BEGIN
		print 'Ko ton tai sbd'
		return 0
	END

	SELECT @tongdiem = sum(DT.DIEM *km.Tile)*10
	FROM DUTHI DT
	JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
	JOIN KHOI_MON KM ON BT.MaKhoi = KM.MaKhoi AND BT.MaMon = KM.MaMon
	WHERE DT.SBD = @sbd
	return 1
go

declare @tongdiem float
exec usp_TinhTongDiem 'QST.A.00075', @tongdiem out
print @tongdiem
go

--Cau 4
CREATE PROC usp_XetKetQuaThi
@SBD char(11)
AS
	IF NOT EXISTS (SELECT * FROM THISINH WHERE SBD = @sbd)
	BEGIN
		print 'Ko ton tai sbd'
		return 0
	END

	DECLARE @tongdiem float, @ketqua char(20), @diemchuan float
	IF ((SELECT COUNT(MaBT)
		FROM DUTHI DT
		WHERE DT.SBD = @SBD) < 2)
	BEGIN
		SET @tongdiem = NULL
		set @ketqua = 'Khong xet'
	END
	ELSE
	BEGIN
		EXEC usp_TinhTongDiem @sbd, @tongdiem out
		set @diemchuan = (SELECT DiemChuan	
						FROM THISINH TS
						JOIN NGANH_KHOI NK ON TS.Nganh = NK.MaNganh AND TS.Khoi = NK.MaKhoi
						WHERE TS.SBD = @SBD)
	END
	IF @tongdiem > @diemchuan
		SET @ketqua = 'Vuot chuan'
	ELSE
		SET @ketqua = 'Khong xet'
	UPDATE THISINH SET KetQua = @ketqua, TongDiem = @tongdiem WHERE SBD = @SBD
GO
EXEC usp_XetKetQuaThi 'QST.A.00779'
go

--Cau 5
CREATE PROC usp_XetKQThiALL
AS
	DECLARE cur cursor for select SBD from THISINH
	DECLARE @sbd char(11)

	open cur
	fetch next from cur into @sbd
	while (@@FETCH_STATUS = 0)
	begin
		exec usp_XetKetQuaThi @sbd
		fetch next from cur into @sbd
	end
	close cur
	deallocate cur
go
EXEC usp_XetKQThiALL